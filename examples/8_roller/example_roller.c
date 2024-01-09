#include "../examples.h"

static uint32_t active_index = 0;

static void roller_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        char buf[32];
        lv_roller_get_selected_str(obj, buf, sizeof(buf));
        LV_LOG_USER("Selected Value: %s\n", buf);
    }
}

void example_demo(void)
{
    const char * value = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12";

    lv_obj_set_flex_flow(lv_scr_act(), LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(lv_scr_act(), LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    lv_obj_t *roller1 = lv_roller_create(lv_scr_act());
    lv_roller_set_options(roller1, value, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller1, 5);
    lv_obj_add_event_cb(roller1, roller_event_handler, LV_EVENT_ALL, NULL);

    lv_obj_t *roller2 = lv_roller_create(lv_scr_act());
    lv_roller_set_options(roller2, value, LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(roller2, 5);
    lv_obj_add_event_cb(roller2, roller_event_handler, LV_EVENT_ALL, NULL);

}

