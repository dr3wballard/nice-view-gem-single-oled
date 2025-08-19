#include <stdlib.h>
#include <zephyr/kernel.h>
#include "draw_power.h"

LV_IMG_DECLARE(power_01);
LV_IMG_DECLARE(power_02);
LV_IMG_DECLARE(power_03);
LV_IMG_DECLARE(power_04);
LV_IMG_DECLARE(power_05);
LV_IMG_DECLARE(power_06);
LV_IMG_DECLARE(power_07);
LV_IMG_DECLARE(power_08);
LV_IMG_DECLARE(power_09);
LV_IMG_DECLARE(power_10);
LV_IMG_DECLARE(power_11);
LV_IMG_DECLARE(power_12);
LV_IMG_DECLARE(power_13);
LV_IMG_DECLARE(power_14);
LV_IMG_DECLARE(power_15);
LV_IMG_DECLARE(power_16);
LV_IMG_DECLARE(power_17);
LV_IMG_DECLARE(power_18);
LV_IMG_DECLARE(power_19);
LV_IMG_DECLARE(power_20);
LV_IMG_DECLARE(power_21);
LV_IMG_DECLARE(power_22);
LV_IMG_DECLARE(power_23);
LV_IMG_DECLARE(power_24);
LV_IMG_DECLARE(power_25);
LV_IMG_DECLARE(power_26);
LV_IMG_DECLARE(power_27);
LV_IMG_DECLARE(power_28);
LV_IMG_DECLARE(power_29);
LV_IMG_DECLARE(power_30);

const lv_img_dsc_t *anim_imgs[] = {
    &power_01, &power_02, &power_03, &power_04, &power_05, &power_06,
    &power_07, &power_08, &power_09, &power_10, &power_11, &power_12,
    &power_13, &power_14, &power_15, &power_16, &power_17, &power_18,
    &power_19, &power_20, &power_21, &power_22, &power_23, &power_24,
    &power_25, &power_26, &power_27, &power_28, &power_29, &power_30,
};

void draw_animation(lv_obj_t *canvas) {
#if IS_ENABLED(CONFIG_NICE_VIEW_GEM_ANIMATION)
    lv_obj_t *art = lv_animimg_create(canvas);
    lv_obj_center(art);

    lv_animimg_set_src(art, (const void **)anim_imgs, 16);
    lv_animimg_set_duration(art, CONFIG_NICE_VIEW_GEM_ANIMATION_MS);
    lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(art);
#else
    lv_obj_t *art = lv_img_create(canvas);

    int length = sizeof(anim_imgs) / sizeof(anim_imgs[0]);
    srand(k_uptime_get_32());
    int random_index = rand() % length;

    lv_img_set_src(art, anim_imgs[random_index]);
#endif

    lv_obj_align(art, LV_ALIGN_TOP_LEFT, 36, 0);
}