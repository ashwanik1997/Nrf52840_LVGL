
#include "app_util_platform.h"
#include "nrfx_gpiote.h"
#include "nrfx_spim.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "app_error.h"
#include "nrf_drv_timer.h"
#include "nrf_drv_twi.h"
#include "nrfx_twim.h"
#include "nrfx_twi.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "math.h"
#include "lvgl/lvgl.h"
#include "lv_conf.h"
#include "ui/ui.h"
#include "ui/ui_helpers.h"
#include "XPT2046_touch.h"
#include "string.h"
#include "stdint.h"
#include "stdarg.h"
#include "bitmapsLarge.h"
#include "cm_backtrace.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/examples/widgets/lv_example_widgets.h"
typedef uint32_t u32;

#undef BSP_BUTTON_0
#define BSP_BUTTON_0 NRF_GPIO_PIN_MAP(0, 11)

#undef ILI9341_DC_PIN
#define ILI9341_DC_PIN NRF_GPIO_PIN_MAP(0, 27)

#undef ILI9341_SS_PIN
#define ILI9341_SS_PIN NRF_GPIO_PIN_MAP(0, 26)

#undef ILI9341_MISO_PIN
#define ILI9341_MISO_PIN NRFX_SPIM_PIN_NOT_USED

#undef ILI9341_SCK_PIN
#define ILI9341_SCK_PIN NRF_GPIO_PIN_MAP(0, 02)

#undef ILI9341_MOSI_PIN
#define ILI9341_MOSI_PIN NRF_GPIO_PIN_MAP(1, 15)

// Set of commands described in ILI9341 datasheet.
#define ILI9341_NOP         0x00
#define ILI9341_SWRESET     0x01
#define ILI9341_RDDID       0x04
#define ILI9341_RDDST       0x09

#define ILI9341_SLPIN       0x10
#define ILI9341_SLPOUT      0x11
#define ILI9341_PTLON       0x12
#define ILI9341_NORON       0x13

#define ILI9341_RDMODE      0x0A
#define ILI9341_RDMADCTL    0x0B
#define ILI9341_RDPIXFMT    0x0C
#define ILI9341_RDIMGFMT    0x0D
#define ILI9341_RDSELFDIAG  0x0F

#define ILI9341_INVOFF      0x20
#define ILI9341_INVON       0x21
#define ILI9341_GAMMASET    0x26
#define ILI9341_DISPOFF     0x28
#define ILI9341_DISPON      0x29

#define ILI9341_CASET       0x2A
#define ILI9341_PASET       0x2B
#define ILI9341_RAMWR       0x2C
#define ILI9341_RAMRD       0x2E

#define ILI9341_PTLAR       0x30
#define ILI9341_MADCTL      0x36
#define ILI9341_PIXFMT      0x3A

#define ILI9341_FRMCTR1     0xB1
#define ILI9341_FRMCTR2     0xB2
#define ILI9341_FRMCTR3     0xB3
#define ILI9341_INVCTR      0xB4
#define ILI9341_DFUNCTR     0xB6

#define ILI9341_PWCTR1      0xC0
#define ILI9341_PWCTR2      0xC1
#define ILI9341_PWCTR3      0xC2
#define ILI9341_PWCTR4      0xC3
#define ILI9341_PWCTR5      0xC4
#define ILI9341_VMCTR1      0xC5
#define ILI9341_VMCTR2      0xC7
#define ILI9341_PWCTRSEQ    0xCB
#define ILI9341_PWCTRA      0xCD
#define ILI9341_PWCTRB      0xCF

#define ILI9341_RDID1       0xDA
#define ILI9341_RDID2       0xDB
#define ILI9341_RDID3       0xDC
#define ILI9341_RDID4       0xDD

#define ILI9341_GMCTRP1     0xE0
#define ILI9341_GMCTRN1     0xE1
#define ILI9341_DGMCTR1     0xE2
#define ILI9341_DGMCTR2     0xE3
#define ILI9341_TIMCTRA     0xE8
#define ILI9341_TIMCTRB     0xEA

#define ILI9341_ENGMCTR     0xF2
#define ILI9341_INCTR       0xF6
#define ILI9341_PUMP        0xF7

#define ILI9341_MADCTL_MY  0x80
#define ILI9341_MADCTL_MX  0x40
#define ILI9341_MADCTL_MV  0x20
#define ILI9341_MADCTL_ML  0x10
#define ILI9341_MADCTL_RGB 0x00
#define ILI9341_MADCTL_BGR 0x08
#define ILI9341_MADCTL_MH  0x04

#define ILI9341_XSTART 2
#define ILI9341_YSTART 1

enum ILI9341_tab_t {
    INITR_GREENTAB = 0,     /**< Green tab. */
    INITR_REDTAB,           /**< Red tab. */
    INITR_BLACKTAB,         /**< Black tab. */
    INITR_144GREENTAB,
};
enum ILI9341_tab_t tab_color = INITR_GREENTAB;

#ifndef ILI9341_TAB_COLOR  
#define ILI9341_TAB_COLOR  0
#endif

// Color definitions
#define	ILI9341_BLACK      0x0000
#define	ILI9341_BLUE       0x001F
#define	ILI9341_RED        0xF800
#define	ILI9341_GREEN      0x07E0
#define ILI9341_CYAN       0x07FF
#define ILI9341_MAGENTA    0xF81F
#define ILI9341_YELLOW     0xFFE0
#define ILI9341_WHITE      0xFFFF
#define ILI9341_ORANGE     0xFD60
#define ILI9341_LIGHTGREEN 0x07EF

#define WIDTH   128
#define HEIGHT  160
#define RGB2BGR(x)      (x << 11) | (x & 0x07E0) | (x >> 11)

typedef enum{
    NRF_LCD_ROTATE_0 = 0,       /**< Rotate 0 degrees, clockwise. */
    NRF_LCD_ROTATE_90,          /**< Rotate 90 degrees, clockwise. */
    NRF_LCD_ROTATE_180,         /**< Rotate 180 degrees, clockwise. */
    NRF_LCD_ROTATE_270          /**< Rotate 270 degrees, clockwise. */
}nrf_lcd_rotation_t;

void spi_init(void);
static void ili9341_pixel_draw(uint16_t x, uint16_t y, uint32_t color);
static void ili9341_rect_draw(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);
void ili9341_setWindow(uint16_t color);
static void ili9341_rotation_set(nrf_lcd_rotation_t rotation);
void ili9341_push_colors(uint8_t *p_colors, int32_t size);
void ili9341_DrawBitmap(int16_t x, int16_t y, const uint16_t *image, int16_t w, int16_t h);
void gfx_draw_raw(int16_t x, int16_t y, uint16_t w, uint16_t h,const uint16_t *p_raw);
void MG_flush(uint8_t* buffer, u32 bufferSize);
void drawRGBBitmap(int16_t x, int16_t y,const uint16_t *bitmap, int16_t w, int16_t h);
