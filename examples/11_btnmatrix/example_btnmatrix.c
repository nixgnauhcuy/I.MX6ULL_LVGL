#include "../examples.h"

static const char * btnm1_map[] = {"1", "2", "3", "4", "5", "\n",
                                  "6", "7", "8", "9", "0", "\n",
                                  "Action1", "Action2", ""};

static const char * btnm2_map[] = {LV_SYMBOL_LEFT, "1", "2", "3", "4", "5", LV_SYMBOL_RIGHT, ""};

static void btnmatrix1_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        uint32_t id = lv_btnmatrix_get_selected_btn(obj);
        const char * txt = lv_btnmatrix_get_btn_text(obj, id);

        LV_LOG_USER("%s was pressed\n", txt);
    }
}

static void btnmatrix2_event_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    uint32_t id = lv_btnmatrix_get_selected_btn(obj);
    bool prev = id == 0 ? true : false;
    bool next = id == 6 ? true : false;
    if(prev || next) {
        uint32_t i;
        for(i = 1; i < 7; i++) {
            if(lv_btnmatrix_has_btn_ctrl(obj, i, LV_BTNMATRIX_CTRL_CHECKED)) break;
        }

        if(prev && i > 1) i--;
        else if(next && i < 5) i++;

        lv_btnmatrix_set_btn_ctrl(obj, i, LV_BTNMATRIX_CTRL_CHECKED);
    }
}

void example_demo(void)
{
    lv_obj_t * btnm1 = lv_btnmatrix_create(lv_scr_act());
    lv_btnmatrix_set_map(btnm1, btnm1_map);
    lv_btnmatrix_set_btn_width(btnm1, 10, 2);
    lv_btnmatrix_set_btn_ctrl(btnm1, 10, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_btnmatrix_set_btn_ctrl(btnm1, 11, LV_BTNMATRIX_CTRL_CHECKED);
    //lv_obj_set_size(btnm1, 400, 200);
    lv_obj_align(btnm1, LV_ALIGN_TOP_MID, 0, 50);
    lv_obj_add_event_cb(btnm1, btnmatrix1_event_handler, LV_EVENT_ALL, NULL);

    static lv_style_t style_bg;
    lv_style_init(&style_bg);
    lv_style_set_pad_all(&style_bg, 0);
    lv_style_set_pad_gap(&style_bg, 0);
    lv_style_set_clip_corner(&style_bg, true);
    lv_style_set_border_width(&style_bg, 0);

    static lv_style_t style_btn;
    lv_style_init(&style_btn);
    lv_style_set_border_width(&style_btn, 1);
    lv_style_set_border_opa(&style_btn, LV_OPA_50);
    lv_style_set_border_color(&style_btn, lv_palette_main(LV_PALETTE_GREY));
    lv_style_set_border_side(&style_btn, LV_BORDER_SIDE_INTERNAL);
    lv_style_set_radius(&style_btn, 0);

    lv_obj_t * btnm2 = lv_btnmatrix_create(lv_scr_act());
    lv_btnmatrix_set_map(btnm2, btnm2_map);
    lv_obj_add_style(btnm2, &style_bg, 0);
    lv_obj_add_style(btnm2, &style_btn, LV_PART_ITEMS);
    lv_obj_add_event_cb(btnm2, btnmatrix2_event_handler, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_set_size(btnm2, 400, 50);

    lv_btnmatrix_set_btn_ctrl_all(btnm2, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_btnmatrix_clear_btn_ctrl(btnm2, 0, LV_BTNMATRIX_CTRL_CHECKABLE);
    lv_btnmatrix_clear_btn_ctrl(btnm2, 6, LV_BTNMATRIX_CTRL_CHECKABLE);

    lv_btnmatrix_set_one_checked(btnm2, true);
    lv_btnmatrix_set_btn_ctrl(btnm2, 1, LV_BTNMATRIX_CTRL_CHECKED);
    lv_obj_align(btnm2, LV_ALIGN_BOTTOM_MID, 0, -100);
}

