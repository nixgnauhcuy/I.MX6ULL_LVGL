#include "../examples.h"

static uint32_t active_index = 0;

static void checkbox_event_handler(lv_event_t * e)
{
    uint32_t * active_id = lv_event_get_user_data(e);
    lv_obj_t * cont = lv_event_get_current_target(e);
    lv_obj_t * act_cb = lv_event_get_target(e);
    lv_obj_t * old_cb = lv_obj_get_child(cont, *active_id);

    if(act_cb == cont) return;

    lv_obj_clear_state(old_cb, LV_STATE_CHECKED);
    lv_obj_add_state(act_cb, LV_STATE_CHECKED);

    *active_id = lv_obj_get_index(act_cb);
}

void example_demo(void)
{
    lv_obj_set_flex_flow(lv_scr_act(), LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(lv_scr_act(), LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);

    lv_obj_t * cb;
    cb = lv_checkbox_create(lv_scr_act());
    lv_checkbox_set_text(cb, "Default");

    cb = lv_checkbox_create(lv_scr_act());
    lv_checkbox_set_text(cb, "Default Check");
    lv_obj_add_state(cb, LV_STATE_CHECKED);

    cb = lv_checkbox_create(lv_scr_act());
    lv_checkbox_set_text(cb, "Disable");
    lv_obj_add_state(cb, LV_STATE_DISABLED);

    cb = lv_checkbox_create(lv_scr_act());
    lv_obj_add_state(cb, LV_STATE_CHECKED | LV_STATE_DISABLED);
    lv_checkbox_set_text(cb, "Check and Disable");

    lv_obj_t * obj = lv_obj_create(lv_scr_act());
    lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_size(obj, lv_pct(30), lv_pct(50));
    lv_obj_add_event_cb(obj, checkbox_event_handler, LV_EVENT_CLICKED, &active_index);

    lv_obj_t * obj_c1 = lv_checkbox_create(obj);
    lv_checkbox_set_text(obj_c1, "checkbox1");
    lv_obj_add_flag(obj_c1, LV_OBJ_FLAG_EVENT_BUBBLE);

    lv_obj_t * obj_c2 = lv_checkbox_create(obj);
    lv_checkbox_set_text(obj_c2, "checkbox2");
    lv_obj_add_flag(obj_c2, LV_OBJ_FLAG_EVENT_BUBBLE);

    lv_obj_t * obj_c3 = lv_checkbox_create(obj);
    lv_checkbox_set_text(obj_c3, "checkbox3");
    lv_obj_add_flag(obj_c3, LV_OBJ_FLAG_EVENT_BUBBLE);

    lv_obj_t * obj_c4 = lv_checkbox_create(obj);
    lv_checkbox_set_text(obj_c4, "checkbox4");
    lv_obj_add_flag(obj_c4, LV_OBJ_FLAG_EVENT_BUBBLE);

}

