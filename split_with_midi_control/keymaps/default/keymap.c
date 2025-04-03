// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
//#include "../../config.h"
#define DIODE_DIRECTION COL2ROW 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
      
        KC_TAB,             KC_Q,           KC_W,           KC_E,               KC_R,           KC_T,           KC_NO,          KC_NO,          KC_NO,          KC_NO,        
        KC_LEFT_CTRL,       KC_A,           KC_S,           KC_D,               KC_F,           KC_G,           KC_NO,          KC_NO,          KC_NO,          KC_NO,   
        KC_LEFT_SHIFT,      KC_Z,           KC_X,           KC_C,               KC_V,           KC_B,           KC_NO,          KC_NO,          KC_NO,          KC_NO,   
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_NO,          KC_NO,          KC_Q,           KC_W,           KC_E,           KC_R, 
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LEFT_SHIFT,   
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_H,           KC_J,           KC_K,           KC_L,           KC_LEFT_BRACKET,KC_RIGHT_BRACKET,
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_BACKSLASH, 
        KC_A,               KC_S,           KC_D,           KC_F,               KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO          

    )
      
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // コンソールが有効化されている場合、マトリックス上の位置とキー押下状態を出力します
  #ifdef CONSOLE_ENABLE
      uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
  #endif 
    return true;
}

// void keyboard_post_init_user(void) {
//     pointing_device_set_cpi_on_side(true, 1000);
//     pointing_device_set_cpi_on_side(false,8000);
// }

// report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
//     left_report.h = left_report.x;
//     left_report.v = left_report.y;
//     left_report.x = 0;
//     left_report.y = 0;
//     return pointing_device_combine_reports(left_report, right_report);
// }


