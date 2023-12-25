#include "../examples.h"

static int _tick = 0;
static lv_obj_t *tick_label;
static lv_obj_t *btn_obj;
static lv_obj_t *text_label;
static lv_obj_t *btn1_obj;

static void btn_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);

    if(code == LV_EVENT_CLICKED) {
        if (target == btn_obj) {
            _tick++;
            lv_label_set_text_fmt(tick_label, "%d", _tick);
        }
    }
    else if (code == LV_EVENT_VALUE_CHANGED) {
        if (target == btn1_obj) {
            if (lv_obj_has_state(btn1_obj, LV_STATE_CHECKED)) {
                lv_label_set_text(text_label, "Toggled");
            }
            else {
                lv_label_set_text(text_label, "Toggle");
            }
        }
    }
}

void example_demo(void)
{

    static lv_style_t style, style_pr;
    lv_style_init(&style);

    lv_style_set_radius(&style, 3);

    lv_style_set_bg_opa(&style, LV_OPA_100);
    lv_style_set_bg_color(&style, lv_palette_main(LV_PALETTE_GREEN));
    lv_style_set_bg_grad_color(&style, lv_palette_darken(LV_PALETTE_GREEN, 2));
    lv_style_set_bg_grad_dir(&style, LV_GRAD_DIR_VER);

    lv_style_set_border_opa(&style, LV_OPA_40);
    lv_style_set_border_width(&style, 2);
    lv_style_set_border_color(&style, lv_palette_main(LV_PALETTE_GREY));

    lv_style_set_shadow_width(&style, 8);
    lv_style_set_shadow_color(&style, lv_palette_main(LV_PALETTE_GREY));
    lv_style_set_shadow_ofs_y(&style, 8);

    lv_style_set_outline_opa(&style, LV_OPA_COVER);
    lv_style_set_outline_color(&style, lv_palette_main(LV_PALETTE_BLUE));

    lv_style_set_text_color(&style, lv_color_black());
    lv_style_set_pad_all(&style, 10);


    lv_style_init(&style_pr);
    
    lv_style_set_outline_width(&style_pr, 30);
    lv_style_set_outline_opa(&style_pr, LV_OPA_TRANSP);

    lv_style_set_translate_y(&style_pr, 5);
    lv_style_set_shadow_ofs_y(&style_pr, 3);
    lv_style_set_bg_color(&style_pr, lv_palette_darken(LV_PALETTE_GREEN, 2));
    lv_style_set_bg_grad_color(&style_pr, lv_palette_darken(LV_PALETTE_GREEN, 4));

    static lv_style_transition_dsc_t trans;
    static lv_style_prop_t props[] = {LV_STYLE_OUTLINE_WIDTH, LV_STYLE_OUTLINE_OPA, 0};
    lv_style_transition_dsc_init(&trans, props, lv_anim_path_linear, 300, 0, NULL);
    lv_style_set_transition(&style_pr, &trans);


    btn_obj = lv_btn_create(lv_scr_act());
    lv_obj_remove_style_all(btn_obj);
    lv_obj_add_style(btn_obj, &style, 0);
    lv_obj_add_style(btn_obj, &style_pr, LV_STATE_PRESSED);
    lv_obj_add_event_cb(btn_obj, btn_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_size(btn_obj, 120, 120);
    lv_obj_align(btn_obj, LV_ALIGN_TOP_MID, 0, 60);

    tick_label = lv_label_create(btn_obj);
    lv_label_set_text_fmt(tick_label, "%d", _tick);
    lv_obj_center(tick_label);

    btn1_obj = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn1_obj, btn_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_size(btn1_obj, 120, 120);
    lv_obj_add_flag(btn1_obj, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_align(btn1_obj, LV_ALIGN_BOTTOM_MID, 0, -60);

    text_label = lv_label_create(btn1_obj);
    lv_label_set_text(text_label, "Toggle");
    lv_obj_center(text_label);
}

