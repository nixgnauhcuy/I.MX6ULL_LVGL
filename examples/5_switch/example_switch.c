#include "../examples.h"

static void switch_event_handler(lv_event_t* e)
{
    static lv_obj_t* obj;
    
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        if (lv_obj_has_state(target, LV_STATE_CHECKED)) {
            if (!lv_obj_is_valid(obj)) {
                obj = lv_obj_create(lv_scr_act());
                lv_obj_set_size(obj, 200, 100);
            }
        } else {
            if (lv_obj_is_valid(obj)) {
                lv_obj_del(obj);
            }
        }
    }

}

void example_demo(void)
{
    lv_obj_set_flex_flow(lv_scr_act(), LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(lv_scr_act(), LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    lv_obj_t * sw;

    sw = lv_switch_create(lv_scr_act());
    lv_obj_add_event_cb(sw, switch_event_handler, LV_EVENT_ALL, NULL);

    sw = lv_switch_create(lv_scr_act());
    lv_obj_add_state(sw, LV_STATE_CHECKED);
    lv_obj_add_event_cb(sw, switch_event_handler, LV_EVENT_ALL, NULL);

    sw = lv_switch_create(lv_scr_act());
    lv_obj_add_state(sw, LV_STATE_DISABLED);
    lv_obj_add_event_cb(sw, switch_event_handler, LV_EVENT_ALL, NULL);

    sw = lv_switch_create(lv_scr_act());
    lv_obj_add_state(sw, LV_STATE_CHECKED | LV_STATE_DISABLED);
    lv_obj_add_event_cb(sw, switch_event_handler, LV_EVENT_ALL, NULL);
}

