PROJECT_NAME     := gfx_nrf52840
TARGETS          := nrf52840_xxaa
OUTPUT_DIRECTORY := _build

include sdk.mk
PROJ_DIR := .

$(OUTPUT_DIRECTORY)/nrf52840_xxaa.out: \
  LINKER_SCRIPT  := nrf52.ld

# Source files common to all targets
SRC_FILES += \
  $(PROJ_DIR)/main.c \
   $(PROJ_DIR)/xpt2046_touch.c \
  $(SDK_ROOT)/modules/nrfx/mdk/gcc_startup_nrf52840.S \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_rtt.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_serial.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_backend_uart.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_default_backends.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_frontend.c \
  $(SDK_ROOT)/components/libraries/log/src/nrf_log_str_formatter.c \
  $(SDK_ROOT)/components/libraries/util/app_error.c \
  $(SDK_ROOT)/components/libraries/util/app_error_handler_gcc.c \
  $(SDK_ROOT)/components/libraries/util/app_error_weak.c \
  $(SDK_ROOT)/components/libraries/util/app_util_platform.c \
  $(SDK_ROOT)/components/libraries/util/nrf_assert.c \
  $(SDK_ROOT)/components/libraries/atomic/nrf_atomic.c \
  $(SDK_ROOT)/components/libraries/balloc/nrf_balloc.c \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf.c \
  $(SDK_ROOT)/external/fprintf/nrf_fprintf_format.c \
  $(SDK_ROOT)/components/libraries/memobj/nrf_memobj.c \
  $(SDK_ROOT)/components/libraries/ringbuf/nrf_ringbuf.c \
  $(SDK_ROOT)/components/libraries/strerror/nrf_strerror.c \
  $(SDK_ROOT)/components/libraries/gfx/nrf_gfx.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_clock.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_spi.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_uart.c \
  $(SDK_ROOT)/components/drivers_nrf/nrf_soc_nosd/nrf_nvic.c \
  $(SDK_ROOT)/components/drivers_nrf/nrf_soc_nosd/nrf_soc.c \
  $(SDK_ROOT)/modules/nrfx/soc/nrfx_atomic.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_clock.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/prs/nrfx_prs.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_spi.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_spim.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_uart.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_uarte.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_gpiote.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_timer.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT_Syscalls_GCC.c \
  $(SDK_ROOT)/external/segger_rtt/SEGGER_RTT_printf.c \
  $(SDK_ROOT)/external/thedotfactory_fonts/orkney24pts.c \
  $(SDK_ROOT)/modules/nrfx/mdk/system_nrf52.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_twi.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/nrfx_twim.c \
  $(SDK_ROOT)/integration/nrfx/legacy/nrf_drv_twi.c \
  $(SDK_ROOT)/modules/nrfx/soc/nrfx_atomic.c \
  $(SDK_ROOT)/modules/nrfx/drivers/src/prs/nrfx_prs.c \
  $(SDK_ROOT)/components/libraries/hardfault/nrf52/handler/hardfault_handler_gcc.c \
  $(SDK_ROOT)/components/libraries/hardfault/hardfault_implementation.c \
  $(PROJ_DIR)/lvgl/src/core/lv_disp.c  \
  $(PROJ_DIR)/lvgl/src/core/lv_event.c \
  $(PROJ_DIR)/lvgl/src/core/lv_group.c \
  $(PROJ_DIR)/lvgl/src/core/lv_indev.c \
  $(PROJ_DIR)/lvgl/src/core/lv_indev_scroll.c \
  $(PROJ_DIR)/lvgl/src/core/lv_obj.c \
  $(PROJ_DIR)/lvgl/src/core/lv_obj_class.c \
  $(PROJ_DIR)/lvgl/src/core/lv_obj_draw.c \
  $(PROJ_DIR)/lvgl/src/core/lv_obj_pos.c \
  $(PROJ_DIR)/lvgl/src/core/lv_obj_scroll.c \
  $(PROJ_DIR)/lvgl/src/core/lv_obj_style.c \
  $(PROJ_DIR)/lvgl/src/core/lv_obj_style_gen.c \
  $(PROJ_DIR)/lvgl/src/core/lv_obj_tree.c \
  $(PROJ_DIR)/lvgl/src/core/lv_refr.c \
  $(PROJ_DIR)/lvgl/src/core/lv_theme.c \
  $(PROJ_DIR)/lvgl/src/draw/lv_draw.c \
  $(PROJ_DIR)/lvgl/src/draw/lv_draw_arc.c \
  $(PROJ_DIR)/lvgl/src/draw/lv_draw_img.c \
  $(PROJ_DIR)/lvgl/src/draw/lv_draw_label.c \
  $(PROJ_DIR)/lvgl/src/draw/lv_draw_layer.c \
  $(PROJ_DIR)/lvgl/src/draw/lv_draw_line.c \
  $(PROJ_DIR)/lvgl/src/draw/lv_draw_mask.c \
  $(PROJ_DIR)/lvgl/src/draw/lv_draw_rect.c \
  $(PROJ_DIR)/lvgl/src/draw/lv_draw_transform.c \
  $(PROJ_DIR)/lvgl/src/draw/lv_draw_triangle.c \
  $(PROJ_DIR)/lvgl/src/draw/lv_img_buf.c \
  $(PROJ_DIR)/lvgl/src/draw/lv_img_cache.c \
  $(PROJ_DIR)/lvgl/src/draw/lv_img_decoder.c \
  $(PROJ_DIR)/lvgl/src/draw/sdl/lv_draw_sdl.c \
  $(PROJ_DIR)/lvgl/src/draw/sdl/lv_draw_sdl_arc.c \
  $(PROJ_DIR)/lvgl/src/draw/sdl/lv_draw_sdl_bg.c \
  $(PROJ_DIR)/lvgl/src/draw/sdl/lv_draw_sdl_composite.c \
  $(PROJ_DIR)/lvgl/src/draw/sdl/lv_draw_sdl_img.c \
  $(PROJ_DIR)/lvgl/src/draw/sdl/lv_draw_sdl_label.c \
  $(PROJ_DIR)/lvgl/src/draw/sdl/lv_draw_sdl_layer.c \
  $(PROJ_DIR)/lvgl/src/draw/sdl/lv_draw_sdl_line.c \
  $(PROJ_DIR)/lvgl/src/draw/sdl/lv_draw_sdl_mask.c \
  $(PROJ_DIR)/lvgl/src/draw/sdl/lv_draw_sdl_polygon.c \
  $(PROJ_DIR)/lvgl/src/draw/sdl/lv_draw_sdl_rect.c \
  $(PROJ_DIR)/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c \
  $(PROJ_DIR)/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c \
  $(PROJ_DIR)/lvgl/src/draw/sdl/lv_draw_sdl_utils.c \
  $(PROJ_DIR)/lvgl/src/draw/sw/lv_draw_sw.c \
  $(PROJ_DIR)/lvgl/src/draw/sw/lv_draw_sw_arc.c \
  $(PROJ_DIR)/lvgl/src/draw/sw/lv_draw_sw_blend.c \
  $(PROJ_DIR)/lvgl/src/draw/sw/lv_draw_sw_dither.c \
  $(PROJ_DIR)/lvgl/src/draw/sw/lv_draw_sw_gradient.c \
  $(PROJ_DIR)/lvgl/src/draw/sw/lv_draw_sw_img.c \
  $(PROJ_DIR)/lvgl/src/draw/sw/lv_draw_sw_layer.c \
  $(PROJ_DIR)/lvgl/src/draw/sw/lv_draw_sw_letter.c \
  $(PROJ_DIR)/lvgl/src/draw/sw/lv_draw_sw_line.c \
  $(PROJ_DIR)/lvgl/src/draw/sw/lv_draw_sw_polygon.c \
  $(PROJ_DIR)/lvgl/src/draw/sw/lv_draw_sw_rect.c \
  $(PROJ_DIR)/lvgl/src/draw/sw/lv_draw_sw_transform.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_dejavu_16_persian_hebrew.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_fmt_txt.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_loader.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_10.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_12.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_12_subpx.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_14.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_16.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_18.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_20.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_22.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_24.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_26.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_28.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_28_compressed.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_30.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_32.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_34.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_36.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_38.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_40.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_42.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_44.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_46.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_48.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_montserrat_8.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_simsun_16_cjk.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_unscii_16.c \
  $(PROJ_DIR)/lvgl/src/font/lv_font_unscii_8.c \
  $(PROJ_DIR)/lvgl/src/hal/lv_hal_disp.c \
  $(PROJ_DIR)/lvgl/src/hal/lv_hal_indev.c \
  $(PROJ_DIR)/lvgl/src/hal/lv_hal_tick.c \
  $(PROJ_DIR)/lvgl/src/layouts/flex/lv_flex.c \
  $(PROJ_DIR)/lvgl/src/layouts/grid/lv_grid.c \
  $(PROJ_DIR)/lvgl/src/libs/bmp/lv_bmp.c \
  $(PROJ_DIR)/lvgl/src/libs/ffmpeg/lv_ffmpeg.c \
  $(PROJ_DIR)/lvgl/src/libs/freetype/lv_freetype.c \
  $(PROJ_DIR)/lvgl/src/libs/fsdrv/lv_fs_cbfs.c \
  $(PROJ_DIR)/lvgl/src/libs/fsdrv/lv_fs_fatfs.c \
  $(PROJ_DIR)/lvgl/src/libs/fsdrv/lv_fs_posix.c \
  $(PROJ_DIR)/lvgl/src/libs/fsdrv/lv_fs_stdio.c \
  $(PROJ_DIR)/lvgl/src/libs/fsdrv/lv_fs_win32.c \
  $(PROJ_DIR)/lvgl/src/libs/gif/gifdec.c \
  $(PROJ_DIR)/lvgl/src/libs/gif/lv_gif.c \
  $(PROJ_DIR)/lvgl/src/libs/png/lodepng.c \
  $(PROJ_DIR)/lvgl/src/libs/png/lv_png.c \
  $(PROJ_DIR)/lvgl/src/libs/qrcode/lv_qrcode.c \
  $(PROJ_DIR)/lvgl/src/libs/qrcode/qrcodegen.c \
  $(PROJ_DIR)/lvgl/src/libs/rlottie/lv_rlottie.c \
  $(PROJ_DIR)/lvgl/src/libs/sjpg/lv_sjpg.c \
  $(PROJ_DIR)/lvgl/src/libs/sjpg/tjpgd.c \
  $(PROJ_DIR)/lvgl/src/libs/tiny_ttf/lv_tiny_ttf.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_anim.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_anim_timeline.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_area.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_async.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_bidi.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_color.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_fs.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_gc.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_ll.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_log.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_lru.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_malloc_builtin.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_math.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_mem.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_memcpy_builtin.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_printf.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_style.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_style_gen.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_templ.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_timer.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_tlsf.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_txt.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_txt_ap.c \
  $(PROJ_DIR)/lvgl/src/misc/lv_utils.c \
  $(PROJ_DIR)/lvgl/src/others/file_explorer/lv_file_explorer.c \
  $(PROJ_DIR)/lvgl/src/others/fragment/lv_fragment.c \
  $(PROJ_DIR)/lvgl/src/others/fragment/lv_fragment_manager.c \
  $(PROJ_DIR)/lvgl/src/others/gridnav/lv_gridnav.c \
  $(PROJ_DIR)/lvgl/src/others/ime/lv_ime_pinyin.c \
  $(PROJ_DIR)/lvgl/src/others/imgfont/lv_imgfont.c \
  $(PROJ_DIR)/lvgl/src/others/monkey/lv_monkey.c \
  $(PROJ_DIR)/lvgl/src/others/msg/lv_msg.c \
  $(PROJ_DIR)/lvgl/src/others/snapshot/lv_snapshot.c \
  $(PROJ_DIR)/lvgl/src/themes/basic/lv_theme_basic.c \
  $(PROJ_DIR)/lvgl/src/themes/default/lv_theme_default.c \
  $(PROJ_DIR)/lvgl/src/themes/mono/lv_theme_mono.c \
  $(PROJ_DIR)/lvgl/src/widgets/animimg/lv_animimg.c \
  $(PROJ_DIR)/lvgl/src/widgets/arc/lv_arc.c \
  $(PROJ_DIR)/lvgl/src/widgets/bar/lv_bar.c \
  $(PROJ_DIR)/lvgl/src/widgets/btn/lv_btn.c \
  $(PROJ_DIR)/lvgl/src/widgets/btnmatrix/lv_btnmatrix.c \
  $(PROJ_DIR)/lvgl/src/widgets/calendar/lv_calendar.c \
  $(PROJ_DIR)/lvgl/src/widgets/calendar/lv_calendar_header_arrow.c \
  $(PROJ_DIR)/lvgl/src/widgets/calendar/lv_calendar_header_dropdown.c \
  $(PROJ_DIR)/lvgl/src/widgets/canvas/lv_canvas.c \
  $(PROJ_DIR)/lvgl/src/widgets/chart/lv_chart.c \
  $(PROJ_DIR)/lvgl/src/widgets/checkbox/lv_checkbox.c \
  $(PROJ_DIR)/lvgl/src/widgets/colorwheel/lv_colorwheel.c \
  $(PROJ_DIR)/lvgl/src/widgets/dropdown/lv_dropdown.c \
  $(PROJ_DIR)/lvgl/src/widgets/img/lv_img.c \
  $(PROJ_DIR)/lvgl/src/widgets/imgbtn/lv_imgbtn.c \
  $(PROJ_DIR)/lvgl/src/widgets/keyboard/lv_keyboard.c \
  $(PROJ_DIR)/lvgl/src/widgets/label/lv_label.c \
  $(PROJ_DIR)/lvgl/src/widgets/led/lv_led.c \
  $(PROJ_DIR)/lvgl/src/widgets/line/lv_line.c \
  $(PROJ_DIR)/lvgl/src/widgets/list/lv_list.c \
  $(PROJ_DIR)/lvgl/src/widgets/menu/lv_menu.c \
  $(PROJ_DIR)/lvgl/src/widgets/meter/lv_meter.c \
  $(PROJ_DIR)/lvgl/src/widgets/msgbox/lv_msgbox.c \
  $(PROJ_DIR)/lvgl/src/widgets/objx_templ/lv_objx_templ.c \
  $(PROJ_DIR)/lvgl/src/widgets/roller/lv_roller.c \
  $(PROJ_DIR)/lvgl/src/widgets/slider/lv_slider.c \
  $(PROJ_DIR)/lvgl/src/widgets/span/lv_span.c \
  $(PROJ_DIR)/lvgl/src/widgets/spinbox/lv_spinbox.c \
  $(PROJ_DIR)/lvgl/src/widgets/spinner/lv_spinner.c \
  $(PROJ_DIR)/lvgl/src/widgets/switch/lv_switch.c \
  $(PROJ_DIR)/lvgl/src/widgets/table/lv_table.c \
  $(PROJ_DIR)/lvgl/src/widgets/tabview/lv_tabview.c \
  $(PROJ_DIR)/lvgl/src/widgets/textarea/lv_textarea.c \
  $(PROJ_DIR)/lvgl/src/widgets/tileview/lv_tileview.c \
  $(PROJ_DIR)/lvgl/src/widgets/win/lv_win.c \
  $(PROJ_DIR)/ui/ui_helpers.c \
  $(PROJ_DIR)/ui/ui_img_2d_heart_png.c \
  $(PROJ_DIR)/ui/ui_img_2d_temp_png.c \
  $(PROJ_DIR)/ui/ui_img_2dd_drop_png.c \
  $(PROJ_DIR)/ui/ui.c \
  $(PROJ_DIR)/ui/ui_img_face_png.c \
  $(PROJ_DIR)/ui/ui_font_Big.c \
  $(PROJ_DIR)/ui/ui_font_Medium.c \
  $(PROJ_DIR)/ui/ui_img_icons8_favorite_32_png.c \
  
  # $(PROJ_DIR)/cm_backtrace/fault_handler/gcc/cmb_fault.S \
  # $(PROJ_DIR)/cm_backtrace/cm_backtrace.c \

# Include folders common to all targets
INC_FOLDERS += \
  $(SDK_ROOT)/modules/nrfx/mdk \
  $(PROJ_DIR) \
  $(PROJ_DIR)/ui \
  $(SDK_ROOT)/components/libraries/strerror \
  $(SDK_ROOT)/components/toolchain/cmsis/include \
  $(SDK_ROOT)/components/libraries/util \
  $(SDK_ROOT)/components/libraries/balloc \
  $(SDK_ROOT)/components/libraries/ringbuf \
  $(SDK_ROOT)/modules/nrfx/hal \
  $(SDK_ROOT)/components/libraries/log \
  $(SDK_ROOT)/modules/nrfx \
  $(SDK_ROOT)/modules/nrfx/drivers/include \
  $(SDK_ROOT)/components/libraries/experimental_section_vars \
  $(SDK_ROOT)/integration/nrfx/legacy \
  $(SDK_ROOT)/components/libraries/delay \
  $(SDK_ROOT)/integration/nrfx \
  $(SDK_ROOT)/components/drivers_nrf/nrf_soc_nosd \
  $(SDK_ROOT)/external/segger_rtt \
  $(SDK_ROOT)/components/libraries/button \
  $(SDK_ROOT)/components/libraries/memobj \
  $(SDK_ROOT)/external/fprintf \
  $(SDK_ROOT)/modules/nrfx/drivers/include \
  $(SDK_ROOT)/components/libraries/log/src \
  $(SDK_ROOT)/components/libraries/atomic \
  $(PROJ_DIR)/cm_backtrace \
  $(SDK_ROOT)/components/libraries/gfx \
  $(SDK_ROOT)/modules/nrfx/soc \
  $(SDK_ROOT)/modules/nrfx/drivers/src/prs \
  $(SDK_ROOT)/external/thedotfactory_fonts \
  $(PROJ_DIR)/cm_backtrace \
  $(PROJ_DIR)/lvgl/src/core \
  $(PROJ_DIR)/lvgl/src/draw \
  $(PROJ_DIR)/lvgl/src/font \
  $(PROJ_DIR)/lvgl/src/hal \
  $(PROJ_DIR)/lvgl/src/layouts \
  $(PROJ_DIR)/lvgl/src/layouts/flex \
  $(PROJ_DIR)/lvgl/src/layouts/grid \
  $(PROJ_DIR)/lvgl/src/libs \
  $(PROJ_DIR)/lvgl/src/libs/bmp \
  $(PROJ_DIR)/lvgl/src/libs/ffmpeg \
  $(PROJ_DIR)/lvgl/src/libs/freetype \
  $(PROJ_DIR)/lvgl/src/libs/fsdrv \
  $(PROJ_DIR)/lvgl/src/libs/gif \
  $(PROJ_DIR)/lvgl/src/libs/png \
  $(PROJ_DIR)/lvgl/src/libs/qrcode \
  $(PROJ_DIR)/lvgl/src/libs/rlottie \
  $(PROJ_DIR)/lvgl/src/libs/sjpg \
  $(PROJ_DIR)/lvgl/src/libs/tiny_ttf \
  $(PROJ_DIR)/lvgl/src/misc \
  $(PROJ_DIR)/lvgl/src/others \
  $(PROJ_DIR)/lvgl/src/others/file_explorer \
  $(PROJ_DIR)/lvgl/src/others/fragment \
  $(PROJ_DIR)/lvgl/src/others/gridnav \
  $(PROJ_DIR)/lvgl/src/others/ime \
  $(PROJ_DIR)/lvgl/src/others/imgfont \
  $(PROJ_DIR)/lvgl/src/others/monkey \
  $(PROJ_DIR)/lvgl/src/others/msg \
  $(PROJ_DIR)/lvgl/src/others/snapshot \
  $(PROJ_DIR)/lvgl/src/themes \
  $(PROJ_DIR)/lvgl/src/themes/basic \
  $(PROJ_DIR)/lvgl/src/themes/default \
  $(PROJ_DIR)/lvgl/src/themes/mono \
  $(PROJ_DIR)/lvgl/src/widgets \
  $(PROJ_DIR)/lvgl/src/widgets/animimg \
  $(PROJ_DIR)/lvgl/src/widgets/arc \
  $(PROJ_DIR)/lvgl/src/widgets/bar \
  $(PROJ_DIR)/lvgl/src/widgets/btn \
  $(PROJ_DIR)/lvgl/src/widgets/btnmatrix \
  $(PROJ_DIR)/lvgl/src/widgets/calendar \
  $(PROJ_DIR)/lvgl/src/widgets/canvas \
  $(PROJ_DIR)/lvgl/src/widgets/chart \
  $(PROJ_DIR)/lvgl/src/widgets/checkbox \
  $(PROJ_DIR)/lvgl/src/widgets/colorwheel \
  $(PROJ_DIR)/lvgl/src/widgets/dropdown \
  $(PROJ_DIR)/lvgl/src/widgets/img \
  $(PROJ_DIR)/lvgl/src/widgets/imgbtn \
  $(PROJ_DIR)/lvgl/src/widgets/keyboard \
  $(PROJ_DIR)/lvgl/src/widgets/label \
  $(PROJ_DIR)/lvgl/src/widgets/led \
  $(PROJ_DIR)/lvgl/src/widgets/line \
  $(PROJ_DIR)/lvgl/src/widgets/list \
  $(PROJ_DIR)/lvgl/src/widgets/menu \
  $(PROJ_DIR)/lvgl/src/widgets/meter \
  $(PROJ_DIR)/lvgl/src/widgets/msgbox \
  $(PROJ_DIR)/lvgl/src/widgets/objx_templ \
  $(PROJ_DIR)/lvgl/src/widgets/roller \
  $(PROJ_DIR)/lvgl/src/widgets/slider \
  $(PROJ_DIR)/lvgl/src/widgets/span \
  $(PROJ_DIR)/lvgl/src/widgets/spinbox \
  $(PROJ_DIR)/lvgl/src/widgets/spinner \
  $(PROJ_DIR)/lvgl/src/widgets/switch \
  $(PROJ_DIR)/lvgl/src/widgets/table \
  $(PROJ_DIR)/lvgl/src/widgets/tabview \
  $(PROJ_DIR)/lvgl/src/widgets/textarea \
  $(PROJ_DIR)/lvgl/src/widgets/tileview \
  $(PROJ_DIR)/lvgl/src/widgets/win \
# Libraries common to all targets
LIB_FILES += \

# Optimization flags
OPT = -O3 -g3
# Uncomment the line below to enable link time optimization
#OPT += -flto

# C flags common to all targets
CFLAGS += $(OPT)
CFLAGS += -DDEBUG
CFLAGS += -DCONFIG_GPIO_AS_PINRESET
CFLAGS += -DFLOAT_ABI_HARD
CFLAGS += -DNRF52840_XXAA
CFLAGS += -mcpu=cortex-m4
CFLAGS += -mthumb -mabi=aapcs
CFLAGS += -Wall
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# keep every function in a separate section, this allows linker to discard unused ones
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-builtin -fshort-enums

# C++ flags common to all targets
CXXFLAGS += $(OPT)
# Assembler flags common to all targets
ASMFLAGS += -DDEBUG
ASMFLAGS += -mcpu=cortex-m4
ASMFLAGS += -mthumb -mabi=aapcs
ASMFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
ASMFLAGS += -DCONFIG_GPIO_AS_PINRESET
ASMFLAGS += -DFLOAT_ABI_HARD
ASMFLAGS += -DNRF52840_XXAA

# Linker flags
LDFLAGS += $(OPT)
LDFLAGS += -mthumb -mabi=aapcs -L$(SDK_ROOT)/modules/nrfx/mdk -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# let linker dump unused sections
LDFLAGS += -Wl,--gc-sections
# use newlib in nano version
LDFLAGS += --specs=nano.specs

nrf52840_xxaa: CFLAGS += -D__HEAP_SIZE=8192
nrf52840_xxaa: CFLAGS += -D__STACK_SIZE=8192
nrf52840_xxaa: ASMFLAGS += -D__HEAP_SIZE=8192
nrf52840_xxaa: ASMFLAGS += -D__STACK_SIZE=8192

# Add standard libraries at the very end of the linker input, after all objects
# that may need symbols provided by these libraries.
LIB_FILES += -lc -lnosys -lm


.PHONY: default help

# Default target - first one defined
default: nrf52840_xxaa

# Print all targets that can be built
help:
	@echo following targets are available:
	@echo		nrf52840_xxaa
	@echo		sdk_config - starting external tool for editing sdk_config.h
	@echo		flash      - flashing binary

TEMPLATE_PATH := $(SDK_ROOT)/components/toolchain/gcc


include $(TEMPLATE_PATH)/Makefile.common

$(foreach target, $(TARGETS), $(call define_target, $(target)))

.PHONY: flash erase

# Flash the program
flash: default
	@echo Flashing: $(OUTPUT_DIRECTORY)/nrf52840_xxaa.hex
	nrfjprog -f nrf52 --recover
	nrfjprog -f nrf52 --program $(OUTPUT_DIRECTORY)/nrf52840_xxaa.hex --sectorerase
	nrfjprog -f nrf52 --reset

erase:
	nrfjprog -f nrf52 --eraseall

SDK_CONFIG_FILE := sdk_config.h
CMSIS_CONFIG_TOOL := $(SDK_ROOT)/external_tools/cmsisconfig/CMSIS_Configuration_Wizard.jar
sdk_config:
	java -jar $(CMSIS_CONFIG_TOOL) $(SDK_CONFIG_FILE)
