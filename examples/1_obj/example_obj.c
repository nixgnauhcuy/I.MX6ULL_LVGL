#include "../examples.h"

static void btn_event_handler(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    static bool _flag = true;
    static lv_obj_t* obj4;
    static lv_obj_t* obj4_label;
    
    if (code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
        
        if (_flag) {
            obj4 = lv_obj_create(lv_scr_act());
            lv_obj_set_size(obj4, 380, 220);
            lv_obj_align(obj4, LV_ALIGN_BOTTOM_RIGHT, -10, -10);
            obj4_label = lv_label_create(obj4);
            lv_label_set_text(obj4_label, "obj4");
        } 
        else {
            lv_obj_del(obj4);
        }
        _flag = !_flag;
    }
}

void example_demo(void)
{
    lv_obj_t* obj1 = lv_obj_create(lv_scr_act());
    lv_obj_t* label = lv_label_create(obj1);
    lv_label_set_text(label, "obj1");
    lv_obj_center(label);
    lv_obj_set_size(obj1, 380, 220);
    lv_obj_align(obj1, LV_ALIGN_TOP_LEFT, 10, 10);

    static lv_style_t style_shadow;
    lv_style_init(&style_shadow);
    lv_style_set_shadow_width(&style_shadow, 10);
    lv_style_set_shadow_spread(&style_shadow, 5);
    lv_style_set_shadow_color(&style_shadow, lv_palette_main(LV_PALETTE_BLUE));

    lv_obj_t* obj2 = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj2, &style_shadow, 0);
    lv_obj_set_size(obj2, 380, 220);
    lv_obj_align(obj2, LV_ALIGN_TOP_RIGHT, -10, 10);

    lv_obj_t* obj3 = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(obj3, btn_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_size(obj3, 380, 220);
    lv_obj_align(obj3, LV_ALIGN_BOTTOM_LEFT, 10, -10);
}

