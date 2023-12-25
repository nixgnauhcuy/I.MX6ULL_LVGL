#include "../examples_all.h"

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
    lv_obj_t* obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj, 800, 480);
    lv_obj_align(obj, LV_ALIGN_TOP_LEFT, 0, 0);

    /********** Recolor Start **********/ 
    lv_obj_t* recolor_label = lv_label_create(obj);
    lv_label_set_recolor(recolor_label, true);
    lv_label_set_text(recolor_label, "#ff0000 Recolor# #00ff00 Test#!!!");
    lv_obj_align(recolor_label, LV_ALIGN_TOP_LEFT, 0, 0);
    /********** Recolor End **********/ 

    /********** Insert Start **********/ 
    lv_obj_t* insert_label = lv_label_create(obj);
    lv_label_set_text(insert_label, "Test!!!");
    lv_label_ins_text(insert_label, 0, "Insert ");
    lv_obj_align(insert_label, LV_ALIGN_TOP_LEFT, 0, 50);
    /********** Insert End **********/ 

    /********** Formatted Start **********/ 
    lv_obj_t* formatted_label = lv_label_create(obj);
    lv_label_set_text_fmt(formatted_label, "%s Test!!!", "Formatted");
    lv_obj_align(formatted_label, LV_ALIGN_TOP_LEFT, 0, 100);
    /********** Formatted End **********/ 

     /********** Static Start **********/ 
    lv_obj_t* statitc_label = lv_label_create(obj);
    static char _text[] = " tatic  est!!!";
    lv_label_set_text_static(statitc_label, _text);
    lv_obj_align(statitc_label, LV_ALIGN_TOP_LEFT, 0, 150);
    _text[0] = 'S';
    _text[7] = 'T';
    /********** Static End **********/ 

    /********** Label Long Mode Start **********/ 
    lv_obj_t* label = lv_label_create(obj);
    lv_label_set_text(label, "Label Long Mode");
    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 0);

    lv_obj_t* long_label_wrap = lv_label_create(obj);
    lv_label_set_long_mode(long_label_wrap, LV_LABEL_LONG_WRAP);
    lv_obj_set_height(long_label_wrap, 30);
    lv_obj_set_width(long_label_wrap, 120);
    lv_label_set_text(long_label_wrap, "Label Long Wrap Test!!!");
    lv_obj_align(long_label_wrap, LV_ALIGN_TOP_MID, 0, 50);

    lv_obj_t* long_label_dot = lv_label_create(obj);
    lv_label_set_long_mode(long_label_dot, LV_LABEL_LONG_DOT);
    lv_obj_set_height(long_label_dot, 30);
    lv_obj_set_width(long_label_dot, 120);
    lv_label_set_text(long_label_dot, "Label Long Dot Test!!!");
    lv_obj_align(long_label_dot, LV_ALIGN_TOP_MID, 0, 100);

    lv_obj_t* long_label_scroll = lv_label_create(obj);
    lv_label_set_long_mode(long_label_scroll, LV_LABEL_LONG_SCROLL);
    lv_obj_set_height(long_label_scroll, 30);
    lv_obj_set_width(long_label_scroll, 120);
    lv_label_set_text(long_label_scroll, "Label Long Scroll Test!!!");
    lv_obj_align(long_label_scroll, LV_ALIGN_TOP_MID, 0, 150);

    lv_obj_t* long_label_scroll_circular = lv_label_create(obj);
    lv_label_set_long_mode(long_label_scroll_circular, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_height(long_label_scroll_circular, 30);
    lv_obj_set_width(long_label_scroll_circular, 120);
    lv_label_set_text(long_label_scroll_circular, "Label Long Scroll Circular Test!!!");
    lv_obj_align(long_label_scroll_circular, LV_ALIGN_TOP_MID, 0, 200);

    lv_obj_t* long_label_clip = lv_label_create(obj);
    lv_label_set_long_mode(long_label_clip, LV_LABEL_LONG_CLIP);
    lv_obj_set_height(long_label_clip, 30);
    lv_obj_set_width(long_label_clip, 120);
    lv_label_set_text(long_label_clip, "Label Long Clip Test!!!");
    lv_obj_align(long_label_clip, LV_ALIGN_TOP_MID, 0, 250);
    /********** Label Long Mode End **********/ 
}

