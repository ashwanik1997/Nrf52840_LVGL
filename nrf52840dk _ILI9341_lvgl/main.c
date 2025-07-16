#include "main.h"

static lv_disp_drv_t disp_drv;                         /*Descriptor of a display driver*/

const nrf_drv_timer_t timer = NRF_DRV_TIMER_INSTANCE(0);

static const nrfx_spim_t spi = NRFX_SPIM_INSTANCE(3);  /**< SPI instance. */
static volatile bool spi_xfer_done = 1;
static volatile int color_ptr = 0;

static nrfx_spim_xfer_desc_t xfer_desc = NRFX_SPIM_XFER_TX(NULL, 0);

static volatile u32 counter = 0;

static volatile u32 bufferSizeRemaining = 0;

//MG_init((uint8_t**) buffers);

static inline void spi_write(const void * data, size_t size) {

    spi_xfer_done = 0;
    xfer_desc.p_tx_buffer = data;
    xfer_desc.tx_length = size;
    APP_ERROR_CHECK(nrfx_spim_xfer(&spi, &xfer_desc, 0));
    while(!spi_xfer_done);
}

static inline void write_command(uint8_t c) {

    nrf_gpio_pin_clear(ILI9341_DC_PIN);
    spi_write(&c, sizeof(c));
}

static inline void write_data(uint8_t c) {

    nrf_gpio_pin_set(ILI9341_DC_PIN);
    spi_write(&c, sizeof(c));
}

static void set_addr_window(uint16_t x_0, uint16_t y_0, uint16_t x_1, uint16_t y_1)
{
    ASSERT(x_0 <= x_1);
    ASSERT(y_0 <= y_1);

    write_command(ILI9341_CASET);
    write_data(x_0 >> 8);
    write_data(x_0);
    write_data(x_1 >> 8);
    write_data(x_1);
    write_command(ILI9341_PASET);
    write_data(y_0 >> 8);
    write_data(y_0);
    write_data(y_1 >> 8);
    write_data(y_1);
    write_command(ILI9341_RAMWR);
}

static void command_list(void)
{
    write_command(ILI9341_SWRESET);
    nrf_delay_ms(120);
    write_command(ILI9341_DISPOFF);
    nrf_delay_ms(120);
    write_command(ILI9341_PWCTRB);
    write_data(0x00);
    write_data(0XC1);
    write_data(0X30);

    write_command(ILI9341_TIMCTRA);
    write_data(0x85);
    write_data(0x00);
    write_data(0x78);

    write_command(ILI9341_PWCTRSEQ);
    write_data(0x39);
    write_data(0x2C);
    write_data(0x00);
    write_data(0x34);
    write_data(0x02);

    write_command(ILI9341_PUMP);
    write_data(0x20);

    write_command(ILI9341_TIMCTRB);
    write_data(0x00);
    write_data(0x00);

    write_command(ILI9341_PWCTR1);
    write_data(0x23);

    write_command(ILI9341_PWCTR2);
    write_data(0x10);

    write_command(ILI9341_VMCTR1);
    write_data(0x3e);
    write_data(0x28);

    write_command(ILI9341_VMCTR2);
    write_data(0x86);

    write_command(ILI9341_MADCTL);
    write_data(0x48);

    write_command(ILI9341_PIXFMT);
    write_data(0x55);

    write_command(ILI9341_FRMCTR1);
    write_data(0x00);
    write_data(0x18);

    write_command(ILI9341_DFUNCTR);
    write_data(0x08);
    write_data(0x82);
    write_data(0x27);

    write_command(ILI9341_ENGMCTR);
    write_data(0x00);

    write_command(ILI9341_GAMMASET);
    write_data(0x01);

    write_command(ILI9341_GMCTRP1);
    write_data(0x0F);
    write_data(0x31);
    write_data(0x2B);
    write_data(0x0C);
    write_data(0x0E);
    write_data(0x08);
    write_data(0x4E);
    write_data(0xF1);
    write_data(0x37);
    write_data(0x07);
    write_data(0x10);
    write_data(0x03);
    write_data(0x0E);
    write_data(0x09);
    write_data(0x00);

    write_command(ILI9341_GMCTRN1);
    write_data(0x00);
    write_data(0x0E);
    write_data(0x14);
    write_data(0x03);
    write_data(0x11);
    write_data(0x07);
    write_data(0x31);
    write_data(0xC1);
    write_data(0x48);
    write_data(0x08);
    write_data(0x0F);
    write_data(0x0C);
    write_data(0x31);
    write_data(0x36);
    write_data(0x0F);

    write_command(ILI9341_SLPOUT);
    nrf_delay_ms(120);
    write_command(ILI9341_DISPON);
}
static void ili9341_pixel_draw(uint16_t x, uint16_t y, uint32_t color)
{
    set_addr_window(x, y, x, y);

    const uint8_t data[2] = {color >> 8, color};

    nrf_gpio_pin_set(ILI9341_DC_PIN);

    spi_write(data, sizeof(data));

    nrf_gpio_pin_clear(ILI9341_DC_PIN);
}

static void ili9341_rect_draw(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color)
{
    set_addr_window(x, y, x + width - 1, y + height - 1);

    const uint8_t data[2] = {color >> 8, color};

    nrf_gpio_pin_set(ILI9341_DC_PIN);

    // Duff's device algorithm for optimizing loop.
    uint32_t i = (height * width + 7) / 8;

/*lint -save -e525 -e616 -e646 */
    switch ((height * width) % 8) {
        case 0:
            do {
                spi_write(data, sizeof(data));
        case 7:
                spi_write(data, sizeof(data));
        case 6:
                spi_write(data, sizeof(data));
        case 5:
                spi_write(data, sizeof(data));
        case 4:
                spi_write(data, sizeof(data));
        case 3:
                spi_write(data, sizeof(data));
        case 2:
                spi_write(data, sizeof(data));
        case 1:
                spi_write(data, sizeof(data));
            } while (--i > 0);
        default:
            break;
    }
/*lint -restore */

    nrf_gpio_pin_clear(ILI9341_DC_PIN);
}
static void ili9341_rotation_set(nrf_lcd_rotation_t rotation)
{
    write_command(ILI9341_MADCTL);
    switch (rotation) {
        case NRF_LCD_ROTATE_0:
            write_data(ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR);
            break;
        case NRF_LCD_ROTATE_90:
            write_data(ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR);
            break;
        case NRF_LCD_ROTATE_180:
            write_data(ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR);
            break;
        case NRF_LCD_ROTATE_270:
            write_data(ILI9341_MADCTL_MX | ILI9341_MADCTL_MY | ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR);
            break;
        default:
            break;
    }
}

static void ili9341_display_invert(bool invert)
{
    write_command(invert ? ILI9341_INVON : ILI9341_INVOFF);
}
void ili9341_setWindow(uint16_t color)
{
  ili9341_rect_draw(0, 0, WIDTH, HEIGHT, color);
}
void ili9341_DrawBitmap(int16_t x, int16_t y, const uint16_t *image, int16_t w, int16_t h){
  int16_t skipC = 0;                      // non-zero if columns need to be skipped due to clipping
  int16_t originalWidth = w;              // save this value; even if not all columns fit on the screen, the image is still this width in ROM
  int i = w*(h - 1);

  if((x >= WIDTH) || ((y - h + 1) >= HEIGHT) || ((x + w) <= 0) || (y < 0)){
    return;                             // image is totally off the screen, do nothing
  }
  if((w > WIDTH) || (h > HEIGHT)){    // image is too wide for the screen, do nothing
    //***This isn't necessarily a fatal error, but it makes the
    //following logic much more complicated, since you can have
    //an image that exceeds multiple boundaries and needs to be
    //clipped on more than one side.
    return;
  }
  if((x + w - 1) >= WIDTH){            // image exceeds right of screen
    skipC = (x + w) - WIDTH;           // skip cut off columns
    w = WIDTH - x;
  }
  if((y - h + 1) < 0){                  // image exceeds top of screen
    i = i - (h - y - 1)*originalWidth;  // skip the last cut off rows
    h = y + 1;
  }
  if(x < 0){                            // image exceeds left of screen
    w = w + x;
    skipC = -1*x;                       // skip cut off columns
    i = i - x;                          // skip the first cut off columns
    x = 0;
  }
  if(y >= HEIGHT){                     // image exceeds bottom of screen
    h = h - (y - HEIGHT + 1);
    y = HEIGHT - 1;
  }

  set_addr_window(x, y-h+1, x+w-1, y);

  for(y=0; y<h; y=y+1){
    for(x=0; x<w; x=x+1){
                                        // send the top 8 bits
      write_data((uint8_t)(image[i] >> 8));
                                        // send the bottom 8 bits
      write_data((uint8_t)image[i] << 8);
      i = i + 1;                        // go to the next pixel
    }
    i = i + skipC;
    i = i - 2*originalWidth;
  }
}
void drawRGBBitmap(int16_t x, int16_t y, const uint16_t *bitmap, int16_t w, int16_t h) {
    for(int16_t j=0; j<h; j++, y++) {
        for(int16_t i=0; i<w; i++ ) {
            ili9341_pixel_draw(x+i, y, bitmap[j * w + i]);
        }
    }
}

uint32_t MG_getElapsedTimeMs(void) {

	return counter;
}

volatile u32 timestamp0 = 0;
volatile u32 timestamp1 = 0;
volatile u32 xfer_bufferSize = 0;
static void spim_evt_handler(nrfx_spim_evt_t const *p_event, void *p_context) {

    if (p_event->type == NRFX_SPIM_EVENT_DONE) {
        spi_xfer_done = 1;
        if (xfer_bufferSize > 0) {
            u32 bufferSize = xfer_bufferSize;
            if (bufferSize > 255) {
                bufferSize = 255;
            }
            xfer_bufferSize -= bufferSize;
            xfer_desc.p_tx_buffer += 255;
            xfer_desc.tx_length = bufferSize;
            APP_ERROR_CHECK(nrfx_spim_xfer(&spi, &xfer_desc, 0));
        } else {
            timestamp1 = MG_getElapsedTimeMs();
            // NRF_LOG_INFO("Flushed\n");
        } 
    }
}

int del = 0;
static void gpiote_event_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t action) {

}

void timer_event_handler(nrf_timer_event_t event_type, void* p_context) {

    switch (event_type) {
        case NRF_TIMER_EVENT_COMPARE0:
           // counter += 4;
            lv_tick_inc(1);
            break;

        default:
            //Do nothing.
            break;
    }
}

void spi_init(void){
    
    nrf_gpio_cfg_output(ILI9341_DC_PIN);

    nrfx_spim_config_t spi_config = NRFX_SPIM_DEFAULT_CONFIG;
    // spi_config.frequency = NRF_SPIM_FREQ_16M;
    spi_config.frequency = NRF_SPIM_FREQ_16M;
    spi_config.ss_pin = ILI9341_SS_PIN;
    spi_config.miso_pin = ILI9341_MISO_PIN;
    spi_config.mosi_pin = ILI9341_MOSI_PIN;
    spi_config.sck_pin = ILI9341_SCK_PIN;
    ret_code_t err_code = nrfx_spim_init(&spi, &spi_config, spim_evt_handler, NULL);
    if (err_code) {
        NRF_LOG_INFO("SPIM failed, %d", err_code);
        NRF_LOG_FLUSH();
    }
}


void MG_flush(uint8_t* buffer, u32 bufferSize) {

    spi_xfer_done = 0;
    xfer_bufferSize = bufferSize;
    if (bufferSize > 255) {
        bufferSize = 255;
    }
    xfer_bufferSize -= bufferSize;
    xfer_desc.p_tx_buffer = buffer;
    xfer_desc.tx_length = bufferSize;
    timestamp0 = MG_getElapsedTimeMs();
    APP_ERROR_CHECK(nrfx_spim_xfer(&spi, &xfer_desc, 0));
}

void MG_complete() {

    nrf_gpio_pin_clear(ILI9341_DC_PIN);
}

void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p)
{
    set_addr_window(area->x1, area->y1, area->x2, area->y2);
    size_t buf_len = (area->y2+1 - area->y1) * (area->x2+1 - area->x1) * 2;
    uint8_t buffer[buf_len];
    int32_t x, y, i = 0;
    for(y = area->y1; y <= area->y2; y++) {
        for(x = area->x1; x <= area->x2; x++) {
            int t = color_p->ch.red;
            color_p->ch.red = color_p->ch.blue;
            color_p->ch.blue = t;
            buffer[i++] = color_p->full >> 8;
            buffer[i++] = color_p->full;
            color_p++;
        }
    }
    nrf_gpio_pin_set(ILI9341_DC_PIN);
    for (int i = 0; i < buf_len; i += 255) {
        int len = 255;
        if (buf_len - i < 255) {
            len = buf_len - i;
        }
        MG_flush(buffer + i, len);
        while (!spi_xfer_done);
    }
    lv_disp_flush_ready(&disp_drv);
}
void lvgl_display_driver_init(void)
{
    static lv_disp_draw_buf_t draw_buf_dsc_1;
    static lv_color_t buf_1[LV_HOR_RES_MAX * 10];                          /*A buffer for 10 rows*/
    NRF_LOG_INFO("%x\n", buf_1);
    lv_disp_draw_buf_init(&draw_buf_dsc_1, buf_1, NULL, LV_HOR_RES_MAX * 10);   /*Initialize the display buffer*/

    
    lv_disp_drv_init(&disp_drv);                    /*Basic initialization*/

    disp_drv.hor_res = LV_HOR_RES_MAX;
    disp_drv.ver_res = LV_VER_RES_MAX;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf_dsc_1;

    lv_disp_drv_register(&disp_drv);

    NRF_LOG_INFO("DISP %x", lv_disp_get_default());
    NRF_LOG_INFO("SCR %x", lv_scr_act());
}
extern volatile int touch_x;
extern volatile int touch_y;
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static lv_coord_t last_x = 0;
    static lv_coord_t last_y = 0;
    uint8_t touch_buff;
    uint8_t irq = XPT2046_TouchPressed();
    if(irq == 0)
    {
        data->point.x = touch_x;
        data->point.y = touch_y;

        data->state = LV_INDEV_STATE_PRESSED;  
    }
    else{
        data->state = LV_INDEV_STATE_RELEASED;
    }

}    
void lvgl_touch_driver_init(void)
{

    
    static lv_indev_drv_t indev_touchpad;
    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_touchpad);
    indev_touchpad.type = LV_INDEV_TYPE_POINTER;
    indev_touchpad.read_cb = touchpad_read;
    lv_indev_t * my_indev = lv_indev_drv_register(&indev_touchpad);

}

void lv_example_style_13(void)
{
    static lv_style_t style_indic;
    lv_style_init(&style_indic);
    lv_style_set_bg_color(&style_indic, lv_palette_lighten(LV_PALETTE_RED, 3));
    lv_style_set_bg_grad_color(&style_indic, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_bg_grad_dir(&style_indic, LV_GRAD_DIR_HOR);

    static lv_style_t style_indic_pr;
    lv_style_init(&style_indic_pr);
    lv_style_set_shadow_color(&style_indic_pr, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_shadow_width(&style_indic_pr, 10);
    lv_style_set_shadow_spread(&style_indic_pr, 3);

    /*Create an object with the new style_pr*/
    lv_obj_t * obj = lv_slider_create(lv_scr_act());
    lv_obj_add_style(obj, &style_indic, LV_PART_INDICATOR);
    lv_obj_add_style(obj, &style_indic_pr, LV_PART_INDICATOR | LV_STATE_PRESSED);
    lv_slider_set_value(obj, 70, LV_ANIM_OFF);
    lv_obj_center(obj);
}

// Define display dimensions
#define DISPLAY_WIDTH 320
#define DISPLAY_HEIGHT 240

// Define arc progress bar dimensions and position
#define ARC_PROGRESS_BAR_X 30
#define ARC_PROGRESS_BAR_Y 20
#define ARC_PROGRESS_BAR_RADIUS 20
#define ARC_PROGRESS_BAR_THICKNESS 10

// Define arc progress bar color
#define ARC_PROGRESS_BAR_COLOR 0x00FF00 // Green

// Define knob dimensions and position
#define KNOB_X 0
#define KNOB_Y 0
#define KNOB_RADIUS 10
#define M_PI 3.14159265358979323846
// Define knob color
#define KNOB_COLOR 0xFF0000 // Red

// Define current progress percentage
int current_progress = 0;

// Draw the arc progress bar with a specified progress percentage
void draw_arc_progress_bar(int progress_percentage) {
  // Clear the previous progress bar
  for (int x = ARC_PROGRESS_BAR_X - ARC_PROGRESS_BAR_RADIUS - ARC_PROGRESS_BAR_THICKNESS; 
       x <= ARC_PROGRESS_BAR_X + ARC_PROGRESS_BAR_RADIUS + ARC_PROGRESS_BAR_THICKNESS; x++) {
    for (int y = ARC_PROGRESS_BAR_Y - ARC_PROGRESS_BAR_RADIUS - ARC_PROGRESS_BAR_THICKNESS; 
         y <= ARC_PROGRESS_BAR_Y + ARC_PROGRESS_BAR_RADIUS + ARC_PROGRESS_BAR_THICKNESS; y++) {
      int distance = sqrt(pow(x - ARC_PROGRESS_BAR_X, 2) + pow(y - ARC_PROGRESS_BAR_Y, 2));
      if (distance >= ARC_PROGRESS_BAR_RADIUS - ARC_PROGRESS_BAR_THICKNESS && distance <= ARC_PROGRESS_BAR_RADIUS + ARC_PROGRESS_BAR_THICKNESS) {
        ili9341_pixel_draw(x, y, 0x000000); // Black
      }
    }
  }

  // Calculate the angle of the knob based on the progress percentage
  int knob_angle = (progress_percentage * 180) / 100;

  // Draw the arc progress bar foreground
  for (int angle = -90; angle <= knob_angle - 90; angle++) {
    double radians = angle * M_PI / 180.0;
    for (int r = ARC_PROGRESS_BAR_RADIUS - ARC_PROGRESS_BAR_THICKNESS; r <= ARC_PROGRESS_BAR_RADIUS; r++) {
      int x = (int)(ARC_PROGRESS_BAR_X + r * cos(radians));
      int y = (int)(ARC_PROGRESS_BAR_Y + r * sin(radians));
      ili9341_pixel_draw(x, y, ARC_PROGRESS_BAR_COLOR);
    }
  }

  // Draw the knob
  for (int x = KNOB_X - KNOB_RADIUS; x <= KNOB_X + KNOB_RADIUS; x++) {
    for (int y = KNOB_Y - KNOB_RADIUS; y <= KNOB_Y + KNOB_RADIUS; y++) {
      int distance = sqrt(pow(x - KNOB_X, 2) + pow(y - KNOB_Y, 2));
      if (distance <= KNOB_RADIUS) {
        ili9341_pixel_draw(x + ARC_PROGRESS_BAR_X + ARC_PROGRESS_BAR_RADIUS - KNOB_RADIUS, y + ARC_PROGRESS_BAR_Y - KNOB_RADIUS, KNOB_COLOR);
      }
    }
  }
}

#ifdef MG_DEBUG
	void MG_log(const char *format, ...) {

        va_list args;
        char buffer[1024];
		va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
		va_end(args);
        NRF_LOG_INFO("%s", buffer);
        NRF_LOG_FLUSH();
	}

    void MG_assert(const int expression) {

        ASSERT(expression);
    }
#endif



int main(void) {

    nrfx_err_t err_code;

    APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
    NRF_LOG_DEFAULT_BACKENDS_INIT();

    // cm_backtrace_init("v1.0", "v1.1", "v1.2");

    // NRF_LOG_INFO("libming demo 4");
    // NRF_LOG_FLUSH();

    err_code = nrfx_gpiote_init();
    if (err_code) {
        // NRF_LOG_INFO("GPIOTE init failed, %d", err_code);
        // NRF_LOG_FLUSH();
        return 0;
    }

    nrf_drv_timer_config_t timer_cfg = NRF_DRV_TIMER_DEFAULT_CONFIG;
    // 31.25 kHz == 32 us
    timer_cfg.frequency = 9;
    err_code = nrf_drv_timer_init(&timer, &timer_cfg, timer_event_handler);
    if (err_code) {
        // NRF_LOG_INFO("Timer init failed, %d", err_code);
        // NRF_LOG_FLUSH();
        return 0;
    }
    // 125 * 32 us = 4 ms
    nrf_drv_timer_extended_compare(&timer, NRF_TIMER_CC_CHANNEL0, 125, NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK, true);
    nrf_drv_timer_enable(&timer);

    // Button with interrupt
    nrfx_gpiote_in_config_t config = NRFX_GPIOTE_CONFIG_IN_SENSE_HITOLO(false);
    config.pull = NRF_GPIO_PIN_PULLUP;
    err_code = nrfx_gpiote_in_init(BSP_BUTTON_0, &config, gpiote_event_handler);
    if (err_code) {
        // NRF_LOG_INFO("GPIOTE input init failed, %d", err_code);
        // NRF_LOG_FLUSH();
        return 0;
    }
    nrfx_gpiote_in_event_enable(BSP_BUTTON_0, true);
    spi_init();
    command_list();
    xpt2046_init();
    // NRF_LOG_INFO("init complete");
    // NRF_LOG_FLUSH();

    lv_init();

    lvgl_display_driver_init();
    //touchpad_init();
    lvgl_touch_driver_init();

//draw_arc_progress_bar(80);
    while(1) {
ui_init();
//lv_example_style_13();
//st7735_setWindow(ST7735_BLUE);
//lv_example_img_1();

        lv_task_handler();
        // NRF_LOG_INFO("> asd");
       // NRF_LOG_FLUSH();
       // MG_run();
    //    drawRGBBitmap(0, 0, lvgl_img, WIDTH, HEIGHT);

       //drawRGBBitmap(0,0, my_pic,128,160);

      //ST7735_DrawBitmap(int1, int16_t y, const uint16_t *image, int16_t w, int16_t h)
        // if (timestamp1 >= timestamp0) {
        //     NRF_LOG_INFO("> %u", timestamp1 - timestamp0);
        //     NRF_LOG_FLUSH();
        // }
    }
}
