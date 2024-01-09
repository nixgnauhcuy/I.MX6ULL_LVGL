#include "../examples.h"

static lv_obj_t * slider_label, * slider2_label;

static void slider_event_handler(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    char buf[8];
    lv_snprintf(buf, sizeof(buf), "%d%%", (int)lv_slider_get_value(slider));
    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_label_set_text(slider_label, buf);
    
}

static void slider1_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);

    /*Provide some extra space for the value*/
    if(code == LV_EVENT_REFR_EXT_DRAW_SIZE) {
        lv_coord_t * size = lv_event_get_param(e);
        *size = LV_MAX(*size, 50);
    }
    else if(code == LV_EVENT_DRAW_PART_END) {
        lv_obj_draw_part_dsc_t * dsc = lv_event_get_param(e);
        if(dsc->part == LV_PART_INDICATOR) {
            char buf[16];
            lv_snprintf(buf, sizeof(buf), "%d - %d", (int)lv_slider_get_left_value(obj), (int)lv_slider_get_value(obj));

            lv_point_t label_size;
            lv_txt_get_size(&label_size, buf, LV_FONT_DEFAULT, 0, 0, LV_COORD_MAX, 0);
            lv_area_t label_area;
            label_area.x1 = dsc->draw_area->x1 + lv_area_get_width(dsc->draw_area) / 2 - label_size.x / 2;
            label_area.x2 = label_area.x1 + label_size.x;
            label_area.y2 = dsc->draw_area->y1 - 10;
            label_area.y1 = label_area.y2 - label_size.y;

            lv_draw_label_dsc_t label_draw_dsc;
            lv_draw_label_dsc_init(&label_draw_dsc);
            lv_draw_label(dsc->draw_ctx, &label_draw_dsc, &label_area, buf, NULL);
        }
    }
}

static void slider2_event_handler(lv_event_t * e)
{
    lv_obj_t * slider = lv_event_get_target(e);
    char buf[8];
    lv_snprintf(buf, sizeof(buf), "%d%%", (int)lv_slider_get_value(slider));
    lv_obj_align_to(slider2_label, slider, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_label_set_text(slider2_label, buf);
    
}

void example_demo(void)
{
    lv_obj_t * slider = lv_slider_create(lv_scr_act());
    lv_obj_align(slider, LV_ALIGN_TOP_MID, 0, 100);
    lv_obj_add_event_cb(slider, slider_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    slider_label = lv_label_create(lv_scr_act());
    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    lv_label_set_text(slider_label, "0%");

    lv_obj_t * slider1 = lv_slider_create(lv_scr_act());
    lv_obj_align(slider1, LV_ALIGN_TOP_MID, 0, 200);
    lv_slider_set_mode(slider1, LV_SLIDER_MODE_RANGE);
    lv_slider_set_value(slider1, 90, LV_ANIM_OFF);
    lv_slider_set_left_value(slider1, 10, LV_ANIM_OFF);
    lv_obj_add_event_cb(slider1, slider1_event_cb, LV_EVENT_ALL, NULL);

    lv_obj_t * slider2 = lv_slider_create(lv_scr_act());
    lv_obj_align(slider2, LV_ALIGN_TOP_MID, 0, 300);
    lv_slider_set_mode(slider2, LV_SLIDER_MODE_SYMMETRICAL);
    lv_slider_set_range(slider2, -50, 50);
    lv_obj_add_event_cb(slider2, slider2_event_handler, LV_EVENT_ALL, NULL);
    slider2_label = lv_label_create(lv_scr_act());
    lv_obj_align_to(slider2_label, slider2, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    lv_label_set_text(slider2_label, "0%");
}

