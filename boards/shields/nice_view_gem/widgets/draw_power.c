#include <stdlib.h>
#include <zephyr/kernel.h>
#include "draw_power.h"

LV_IMG_DECLARE(power);
// LV_IMG_DECLARE(nervous_finn);

void draw_power(lv_obj_t *canvas) {
    lv_obj_t *art = lv_img_create(canvas);

    lv_img_set_src(art, &power);

    lv_obj_align(art, LV_ALIGN_TOP_LEFT, 36, 0);
}
