#include "../examples.h"

void example_demo(void)
{
    static lv_point_t line_points_0[] = { {0, 0}, {300, 0}, {150, 260}, {0, 0} };
    static lv_point_t line_points_1[] = { {0, 80}, {300, 80}, {150, 340}, {0, 80} };

    static lv_style_t style_line;
    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, 5);
    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_line_rounded(&style_line, true);

    lv_obj_t * line0;
    line0 = lv_line_create(lv_scr_act());
    lv_line_set_points(line0, line_points_0, 4);     /*Set the points*/
    lv_obj_add_style(line0, &style_line, 0);
    lv_obj_center(line0);

    lv_obj_t * line1;
    line1 = lv_line_create(lv_scr_act());
    lv_line_set_y_invert(line1, true);
    lv_line_set_points(line1, line_points_1, 4);     /*Set the points*/
    lv_obj_add_style(line1, &style_line, 0);
    lv_obj_center(line1);
}

