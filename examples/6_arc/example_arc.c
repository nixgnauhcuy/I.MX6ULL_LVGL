#include "../examples.h"

static void set_angle(void * obj, int32_t v)
{
    lv_arc_set_value(obj, v);
}

void example_demo(void)
{
    lv_obj_set_flex_flow(lv_scr_act(), LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(lv_scr_act(), LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    lv_obj_t * arc_1 = lv_arc_create(lv_scr_act());
    lv_arc_set_mode(arc_1, LV_ARC_MODE_NORMAL);
    lv_obj_set_size(arc_1, 150, 150);
    lv_arc_set_rotation(arc_1, 90);
    lv_arc_set_bg_angles(arc_1, 0, 360);
    lv_arc_set_value(arc_1, 0);

    lv_obj_t * arc_2 = lv_arc_create(lv_scr_act());
    lv_arc_set_mode(arc_2, LV_ARC_MODE_SYMMETRICAL);
    lv_obj_set_size(arc_2, 150, 150);
    lv_arc_set_rotation(arc_2, 0);
    lv_arc_set_bg_angles(arc_2, 0, 360);
    lv_arc_set_value(arc_2, 30);

    lv_obj_t * arc_3 = lv_arc_create(lv_scr_act());
    lv_obj_set_size(arc_3, 150, 150);
    lv_arc_set_rotation(arc_3, 270);
    lv_arc_set_bg_angles(arc_3, 0, 360);
    lv_obj_remove_style(arc_3, NULL, LV_PART_KNOB);
    lv_obj_clear_flag(arc_3, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_t * arc_4 = lv_arc_create(lv_scr_act());
    lv_arc_set_mode(arc_4, LV_ARC_MODE_REVERSE);
    lv_obj_set_size(arc_4, 150, 150);
    lv_arc_set_rotation(arc_4, 270);
    lv_arc_set_bg_angles(arc_4, 0, 360);
    lv_obj_remove_style(arc_4, NULL, LV_PART_KNOB);
    lv_obj_clear_flag(arc_4, LV_OBJ_FLAG_CLICKABLE);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, arc_3);
    lv_anim_set_exec_cb(&a, set_angle);
    lv_anim_set_time(&a, 1000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&a, 500);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_start(&a);

    lv_anim_t a1;
    lv_anim_init(&a1);
    lv_anim_set_var(&a1, arc_4);
    lv_anim_set_exec_cb(&a1, set_angle);
    lv_anim_set_time(&a1, 1000);
    lv_anim_set_repeat_count(&a1, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&a1, 1000);
    lv_anim_set_values(&a1, 0, 100);
    lv_anim_start(&a1);
}

