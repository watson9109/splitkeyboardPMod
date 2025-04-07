// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_japanese.h"
//#include "../../config.h"
#define DIODE_DIRECTION COL2ROW 

enum layer_name {
    _ABC,
    _NUMBER,     
    _SYMBOL,
    _MIDI,
};
   
#define LT_NUM  LT(_SYMBOL, KC_SPC) 
#define LT_SYM  LT(_NUMBER, JP_ZKHK)      
//#define TG_MIDI TG(_MIDI)
#define TG_MIDI TG(_MIDI)
#define TG_ABC  TG(_ABC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ABC] = LAYOUT(  // ABC
        KC_ESC,             KC_Q,           KC_W,           KC_E,               KC_R,           KC_T,           KC_NO,          KC_NO,          KC_NO,          KC_NO,        
        KC_LCTL,            KC_A,           KC_S,           KC_D,               KC_F,           KC_G,           KC_NO,          KC_NO,          KC_NO,          KC_NO,   
        KC_LSFT,            KC_Z,           KC_X,           KC_C,               KC_V,           KC_B,           KC_NO,          KC_NO,          KC_NO,          KC_NO,   
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_NO,          KC_NO,          KC_LGUI,        LALT_T(KC_TAB), LT_SYM,         LT_NUM, 
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPC,   
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_H,           KC_J,           KC_K,           KC_L,           KC_LEFT_BRACKET,KC_RIGHT_BRACKET,
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_N,           KC_M,           JP_COMM,       JP_DOT,         JP_SLSH,        TG_MIDI, 
        MS_BTN1,            MS_BTN2,        KC_ENT,         KC_BSPC,            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO          
    ),
    [_NUMBER] = LAYOUT(   // MIDI
        KC_ESC,             _______,        KC_UP,        KC_KP_8,            KC_KP_9,        _______,        KC_NO,          KC_NO,          KC_NO,          KC_NO,        
        KC_LCTL,            KC_LEFT,        KC_DOWN,        KC_RIGHT,            KC_KP_6,        _______,        KC_NO,          KC_NO,          KC_NO,          KC_NO,   
        KC_LSFT,            _______,        KC_KP_1,        KC_KP_2,            KC_KP_3,        _______,        KC_NO,          KC_NO,          KC_NO,          KC_NO,   
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_NO,          KC_NO,          KC_LGUI,        LALT_T(KC_TAB), LT_SYM,         LT_NUM, 
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_PSCR,        KC_BSPC,   
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_LEFT_BRACKET,_______,
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_F1,          KC_F2,          KC_F3,          KC_F4,          _______,        JP_BSLS, 
        MS_BTN1,            MS_BTN2,        KC_ENT,         KC_BSPC,            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO          
    ),
    [_SYMBOL] = LAYOUT(  // NUMBER
        KC_ESC,             JP_1,           JP_2,           JP_3,               JP_4,           JP_5,           KC_NO,          KC_NO,          KC_NO,          KC_NO,        
        KC_LCTL,            JP_MINS,        JP_PLUS,        KC_LCBR,            KC_RCBR,        JP_YEN,         KC_NO,          KC_NO,          KC_NO,          KC_NO,   
        KC_LSFT,            JP_ASTR,        JP_UNDS,        JP_LPRN,            JP_RPRN,        JP_CIRC,        KC_NO,          KC_NO,          KC_NO,          KC_NO,   
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_NO,          KC_NO,          KC_LGUI,        LALT_T(KC_TAB), LT_SYM,         LT_NUM, 
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              JP_6,           JP_7,           JP_8,           JP_9,           JP_0,           KC_0,   
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              JP_SCLN,        JP_COLN,        JP_QUOT,        JP_AT,          KC_COMM,        KC_DOT,
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              _______,        _______,        _______,        _______,        _______,       _______, 
        MS_BTN1,            MS_BTN2,        KC_ENTER,       KC_BACKSPACE,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO          
    ),
    [_MIDI] = LAYOUT(  // MIDI
        KC_ESC,             KC_Q,           KC_W,           KC_E,               KC_R,           KC_T,           KC_NO,          KC_NO,          KC_NO,          KC_NO,        
        KC_LCTL,            KC_A,           KC_S,           KC_D,               KC_F,           KC_G,           KC_NO,          KC_NO,          KC_NO,          KC_NO,   
        KC_LSFT,            KC_Z,           KC_X,           KC_C,               KC_V,           KC_B,           KC_NO,          KC_NO,          KC_NO,          KC_NO,   
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_NO,          KC_NO,          KC_LGUI,        LALT_T(KC_TAB), KC_SPC,         KC_SPC,
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LEFT_SHIFT,   
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_H,           KC_J,           KC_K,           KC_L,           KC_LEFT_BRACKET,KC_RIGHT_BRACKET,
        KC_NO,              KC_NO,          KC_NO,          KC_NO,              KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       TG_MIDI, 
        MS_BTN1,            MS_BTN2,        KC_ENTER,       KC_BACKSPACE,       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO          
    ) 
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_ABC] = { 
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD)
    },
    [_NUMBER] = { 
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD)
    },
    [_SYMBOL] = { 
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD)
    },
    [_MIDI] = { 
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD)
    }
};
#endif


// #if defined(JOYSTICK_ENABLE)

// char arrow_keys[4] = {KC_UP, KC_LEFT, KC_DOWN, KC_RIGHT};

// joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
//     [0] = JOYSTICK_AXIS_VIRTUAL,
//     [1] = JOYSTICK_AXIS_VIRTUAL
// };


// static int actuation = 255; // actuation point for arrows (0-511)

// bool arrows[4];

// void joystick_task_user() { 
//     if (!arrows[0] && analogReadPin(GP26) - 512 > actuation){
//         arrows[0] = true;
//         register_code16(arrow_keys[2]);
//     }
//     else if (arrows[0] &&  analogReadPin(GP26) - 512 < actuation){
//         arrows[0] = false;
//         unregister_code16(arrow_keys[2]);
//     }
//     if (!arrows[1] && analogReadPin(GP26) - 512 < -actuation){
//         arrows[1] = true;
//         register_code16(arrow_keys[0]);
//     }
//     else if (arrows[1] && analogReadPin(GP26) - 512 > -actuation){
//         arrows[1] = false;
//         unregister_code16(arrow_keys[0]);
//     }
//     if (!arrows[2] && analogReadPin(GP27) - 512 > actuation){
//         arrows[2] = true;
//         register_code16(arrow_keys[1]);
//     }
//     else if (arrows[2] &&  analogReadPin(GP27) - 512 < actuation){
//         arrows[2] = false;
//         unregister_code16(arrow_keys[1]);
//     }
//     if (!arrows[3] && analogReadPin(GP27) - 512 < -actuation){
//         arrows[3] = true;
//         register_code16(arrow_keys[3]);
//     }
//     else if (arrows[3] && analogReadPin(GP27) - 512 > -actuation){
//         arrows[3] = false;
//         unregister_code16(arrow_keys[3]);
//     }
// }
//#endif

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     // コンソールが有効化されている場合、マトリックス上の位置とキー押下状態を出力します
//   #ifdef CONSOLE_ENABLE
//       uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
//   #endif 
//     return true;
// }

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


