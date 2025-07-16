// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: widgets

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Screen1_Colorwheel1;
lv_obj_t * ui_Screen1_Image2;
lv_obj_t * ui_Screen1_Panel1;
lv_obj_t * ui_Screen1_Label1;
lv_obj_t * ui_Screen1_Image3;
lv_obj_t * ui_Screen1_Panel2;
lv_obj_t * ui_Screen1_Label2;
lv_obj_t * ui_Screen1_Image6;
lv_obj_t * ui_Screen1_Panel3;
lv_obj_t * ui_celcius;
lv_obj_t * ui_Screen1_Image9;
lv_obj_t * ui_Screen1_Label4;
lv_obj_t * ui_Screen1_Label5;
lv_obj_t * ui_Screen1_Label3;
lv_obj_t * ui_Screen1_Image1;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_width(ui_Screen1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Screen1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_Screen1, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_Screen1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_Screen1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Screen1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Screen1, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_Screen1, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Colorwheel1 = lv_colorwheel_create(ui_Screen1, true);
    lv_obj_set_width(ui_Screen1_Colorwheel1, 240);
    lv_obj_set_height(ui_Screen1_Colorwheel1, 240);
    lv_obj_set_align(ui_Screen1_Colorwheel1, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_Screen1_Colorwheel1, LV_STATE_CHECKED);       /// States
    lv_obj_set_style_radius(ui_Screen1_Colorwheel1, 240, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Colorwheel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Colorwheel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Screen1_Colorwheel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Screen1_Colorwheel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Screen1_Colorwheel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Screen1_Colorwheel1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Screen1_Colorwheel1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Screen1_Colorwheel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Screen1_Colorwheel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_Screen1_Colorwheel1, LV_BLEND_MODE_ADDITIVE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_Screen1_Colorwheel1, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Screen1_Colorwheel1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_Screen1_Colorwheel1, true, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Screen1_Colorwheel1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Colorwheel1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Screen1_Colorwheel1, lv_color_hex(0x0000E9), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Screen1_Colorwheel1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Screen1_Colorwheel1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Screen1_Colorwheel1, LV_GRAD_DIR_NONE, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Colorwheel1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Colorwheel1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Screen1_Image2 = lv_img_create(ui_Screen1_Colorwheel1);
    lv_img_set_src(ui_Screen1_Image2, &ui_img_face_png);
    lv_obj_set_width(ui_Screen1_Image2, LV_SIZE_CONTENT);   /// 128
    lv_obj_set_height(ui_Screen1_Image2, LV_SIZE_CONTENT);    /// 128
    lv_obj_set_align(ui_Screen1_Image2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Screen1_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_Screen1_Image2, 440);
    lv_obj_set_style_opa(ui_Screen1_Image2, 150, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Panel1 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Panel1, 60);
    lv_obj_set_height(ui_Screen1_Panel1, 60);
    lv_obj_set_x(ui_Screen1_Panel1, -19);
    lv_obj_set_y(ui_Screen1_Panel1, -69);
    lv_obj_set_align(ui_Screen1_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen1_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Panel1, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Panel1, lv_color_hex(0x545454), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Screen1_Panel1, lv_color_hex(0x070007), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Panel1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Screen1_Panel1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Label1 = lv_label_create(ui_Screen1_Panel1);
    lv_obj_set_width(ui_Screen1_Label1, 20);
    lv_obj_set_height(ui_Screen1_Label1, 20);
    lv_obj_set_x(ui_Screen1_Label1, -2);
    lv_obj_set_y(ui_Screen1_Label1, 15);
    lv_obj_set_align(ui_Screen1_Label1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_Screen1_Label1, LV_LABEL_LONG_CLIP);
    lv_label_set_text(ui_Screen1_Label1, "98");
    lv_obj_set_style_text_color(ui_Screen1_Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Screen1_Label1, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_Screen1_Label1, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label1, &ui_font_Medium, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Label1, lv_color_hex(0x00EFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Label1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Label1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Screen1_Label1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Screen1_Label1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_Screen1_Label1, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_Screen1_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Image3 = lv_img_create(ui_Screen1_Panel1);
    lv_img_set_src(ui_Screen1_Image3, &ui_img_icons8_favorite_32_png);
    lv_obj_set_width(ui_Screen1_Image3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Image3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Image3, 0);
    lv_obj_set_y(ui_Screen1_Image3, -7);
    lv_obj_set_align(ui_Screen1_Image3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Screen1_Image3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen1_Panel2 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Panel2, 60);
    lv_obj_set_height(ui_Screen1_Panel2, 60);
    lv_obj_set_x(ui_Screen1_Panel2, 74);
    lv_obj_set_y(ui_Screen1_Panel2, 2);
    lv_obj_set_align(ui_Screen1_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen1_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Panel2, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Panel2, lv_color_hex(0x545454), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Screen1_Panel2, lv_color_hex(0x070007), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Panel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Panel2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Screen1_Panel2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Label2 = lv_label_create(ui_Screen1_Panel2);
    lv_obj_set_width(ui_Screen1_Label2, LV_SIZE_CONTENT);   /// 20
    lv_obj_set_height(ui_Screen1_Label2, LV_SIZE_CONTENT);    /// 20
    lv_obj_set_x(ui_Screen1_Label2, 0);
    lv_obj_set_y(ui_Screen1_Label2, 14);
    lv_obj_set_align(ui_Screen1_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label2, "64");
    lv_obj_set_style_text_color(ui_Screen1_Label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Screen1_Label2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label2, &ui_font_Medium, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Screen1_Label2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Screen1_Label2, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Screen1_Label2, lv_color_hex(0x00EFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Screen1_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Screen1_Label2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Screen1_Label2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_Screen1_Label2, LV_BLEND_MODE_ADDITIVE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_Screen1_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Image6 = lv_img_create(ui_Screen1_Panel2);
    lv_img_set_src(ui_Screen1_Image6, &ui_img_2dd_drop_png);
    lv_obj_set_width(ui_Screen1_Image6, LV_SIZE_CONTENT);   /// 17
    lv_obj_set_height(ui_Screen1_Image6, LV_SIZE_CONTENT);    /// 16
    lv_obj_set_x(ui_Screen1_Image6, -1);
    lv_obj_set_y(ui_Screen1_Image6, -10);
    lv_obj_set_align(ui_Screen1_Image6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Screen1_Image6, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_Screen1_Image6, 400);
    lv_obj_set_style_outline_color(ui_Screen1_Image6, lv_color_hex(0x00EAFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Image6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Image6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Image6, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Screen1_Image6, lv_color_hex(0x00EAFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Screen1_Image6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Screen1_Image6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Screen1_Image6, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Screen1_Image6, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Screen1_Image6, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_Screen1_Image6, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_Screen1_Image6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Panel3 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Panel3, 60);
    lv_obj_set_height(ui_Screen1_Panel3, 60);
    lv_obj_set_x(ui_Screen1_Panel3, -30);
    lv_obj_set_y(ui_Screen1_Panel3, 67);
    lv_obj_set_align(ui_Screen1_Panel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen1_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Panel3, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Panel3, lv_color_hex(0x545454), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Screen1_Panel3, lv_color_hex(0x070007), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Panel3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Panel3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Screen1_Panel3, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_celcius = lv_label_create(ui_Screen1_Panel3);
    lv_obj_set_width(ui_celcius, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_celcius, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_celcius, 1);
    lv_obj_set_y(ui_celcius, 10);
    lv_obj_set_align(ui_celcius, LV_ALIGN_CENTER);
    lv_label_set_text(ui_celcius, "24°c");
    lv_obj_set_style_text_color(ui_celcius, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_celcius, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_celcius, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_celcius, &ui_font_Medium, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Image9 = lv_img_create(ui_Screen1_Panel3);
    lv_img_set_src(ui_Screen1_Image9, &ui_img_2d_temp_png);
    lv_obj_set_width(ui_Screen1_Image9, LV_SIZE_CONTENT);   /// 17
    lv_obj_set_height(ui_Screen1_Image9, LV_SIZE_CONTENT);    /// 16
    lv_obj_set_x(ui_Screen1_Image9, 0);
    lv_obj_set_y(ui_Screen1_Image9, -15);
    lv_obj_set_align(ui_Screen1_Image9, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Screen1_Image9, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_Screen1_Image9, 400);

    ui_Screen1_Label4 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Label4, 65);
    lv_obj_set_height(ui_Screen1_Label4, 20);
    lv_obj_set_x(ui_Screen1_Label4, 15);
    lv_obj_set_y(ui_Screen1_Label4, -3);
    lv_obj_set_align(ui_Screen1_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label4, "12:56");
    lv_obj_set_style_text_color(ui_Screen1_Label4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_Screen1_Label4, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Screen1_Label4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Screen1_Label4, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_Screen1_Label4, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label4, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Label5 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Label5, 45);
    lv_obj_set_height(ui_Screen1_Label5, 15);
    lv_obj_set_x(ui_Screen1_Label5, 24);
    lv_obj_set_y(ui_Screen1_Label5, -27);
    lv_obj_set_align(ui_Screen1_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label5, "23 TUE");
    lv_obj_set_style_text_color(ui_Screen1_Label5, lv_color_hex(0xB3FFFB), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label5, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Label3 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Label3, 45);
    lv_obj_set_height(ui_Screen1_Label3, 15);
    lv_obj_set_x(ui_Screen1_Label3, 24);
    lv_obj_set_y(ui_Screen1_Label3, 20);
    lv_obj_set_align(ui_Screen1_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label3, "OCT 22");
    lv_obj_set_style_text_color(ui_Screen1_Label3, lv_color_hex(0xFBFFC0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen1_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_Screen1_Label3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_Screen1_Label3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label3, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Image1 = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_Screen1_Image1, &ui_img_icons8_favorite_32_png);
    lv_obj_set_width(ui_Screen1_Image1, LV_SIZE_CONTENT);   /// 32
    lv_obj_set_height(ui_Screen1_Image1, LV_SIZE_CONTENT);    /// 32
    lv_obj_set_x(ui_Screen1_Image1, -819);
    lv_obj_set_y(ui_Screen1_Image1, -90);
    lv_obj_set_align(ui_Screen1_Image1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Screen1_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
}
