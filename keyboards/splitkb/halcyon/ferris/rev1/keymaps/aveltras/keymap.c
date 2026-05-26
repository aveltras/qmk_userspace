#include QMK_KEYBOARD_H

#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#include "keymap_french.h"

#undef PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

enum aveltras_layers {
    _base,
    _shifted,
    _symbols,
    _num_nav,
    _functions,
    _accents,
};

enum custom_keycodes {
    FR_UCIRC = SAFE_RANGE, // û
    FR_ECIRC, // ê
    FR_ACIRC, // â
    FR_OCIRC, // ô
    FR_ICIRC, // î
    FR_IDIAE, // ï
};

// https://docs.qmk.fm/keycodes_basic
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_base] = LAYOUT_ferris_hlc(
                              FR_Q, FR_C, FR_O, FR_P, FR_W,                             FR_J, FR_M, FR_D, MO(_accents), FR_Y,
                              FR_A, LGUI_T(FR_S), LCTL_T(FR_E), LALT_T(FR_N), FR_F,     FR_L, LALT_T(FR_R), RCTL_T(FR_T), RGUI_T(FR_I), FR_U,
                              FR_Z, FR_X, FR_MINS, FR_V, FR_B,                          FR_DOT, FR_H, FR_G, FR_COMM, FR_K,
                              LT(_shifted, KC_ESCAPE), LT(_num_nav, KC_BSPC),           LT(_functions, KC_SPC), LT(_symbols, KC_ENTER),
                              KC_MUTE , KC_NO, KC_NO, KC_NO, KC_NO,                     KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO
                              ),
  [_shifted] = LAYOUT_ferris_hlc(
                                 S(FR_Q), S(FR_C), S(FR_O), S(FR_P), S(FR_W),        S(FR_J), S(FR_M), S(FR_D), FR_EXLM, S(FR_Y),
                                 S(FR_A), S(FR_S), S(FR_E), S(FR_N), S(FR_F),        S(FR_L), S(FR_R), S(FR_T), S(FR_I), S(FR_U),
                                 S(FR_Z), S(FR_X), FR_QUES, S(FR_V), S(FR_B),        FR_COLN, S(FR_H), S(FR_G), FR_SCLN, S(FR_K),
                                 _______, _______,                                   _______, _______,
                                 _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
                                 ),
  [_symbols] = LAYOUT_ferris_hlc(
                                 S(KC_6), FR_LABK, FR_RABK, FR_DLR, FR_PERC,         FR_AT, FR_AMPR, FR_ASTR, FR_QUOT, KC_GRAVE,
                                 FR_LCBR, FR_LPRN, FR_RPRN, FR_RCBR, FR_EQL,         FR_BSLS, FR_PLUS, FR_MINS, FR_SLSH, FR_DQUO,
                                 S(KC_GRAVE), FR_LBRC, FR_RBRC, FR_UNDS, FR_HASH,    FR_PIPE, FR_EXLM, FR_SCLN, FR_COLN, FR_QUES,
                                 _______, _______,                                   _______, _______,
                                 _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
                                 ),
  [_num_nav] = LAYOUT_ferris_hlc(
                                 KC_TAB, KC_HOME, KC_UP, KC_END, KC_PAGE_UP,                           FR_SLSH, FR_7, FR_8, FR_9, KC_NO,
                                 KC_LEFT_SHIFT, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PAGE_DOWN,              FR_MINS, FR_4, FR_5, FR_6, FR_0,
                                 KC_NO, KC_KB_VOLUME_DOWN, KC_MUTE, KC_KB_VOLUME_UP, S(KC_TAB),        FR_COMM, FR_1, FR_2, FR_3, FR_DOT,
                                 _______, _______,                                                     _______, _______,
                                 _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______
                                 ),
  [_functions] = LAYOUT_ferris_hlc(
                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_PRINT_SCREEN, KC_F1, KC_F2, KC_F3, KC_F4,
                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_F5, KC_F6, KC_F7, KC_F8,
                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_F9, KC_F10, KC_F11, KC_F12,
                                 _______, _______,                               _______, _______,
                                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
                                   ),
  [_accents] = LAYOUT_ferris_hlc(
                                 FR_ACIRC, FR_CCED, RALT(FR_O), FR_OCIRC, KC_NO,      KC_NO, KC_NO, KC_NO, KC_TRNS, FR_UCIRC,
                                 FR_AGRV, FR_EACU, FR_EGRV, FR_ECIRC, KC_NO,          FR_LPRN, FR_RPRN, FR_ICIRC, FR_IDIAE, FR_UGRV,
                                 RALT(FR_A), KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                 _______, _______,                                    _______, _______,
                                 _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______
                                 )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FR_UCIRC:
            if (record->event.pressed) {
                tap_code16(FR_CIRC);
                tap_code16(FR_U);
            }
            return false;
        case FR_ECIRC:
            if (record->event.pressed) {
                tap_code16(FR_CIRC);
                tap_code16(FR_E);
            }
            return false;
        case FR_ACIRC:
            if (record->event.pressed) {
                tap_code16(FR_CIRC);
                tap_code16(FR_A);
            }
            return false;
        case FR_OCIRC:
            if (record->event.pressed) {
                tap_code16(FR_CIRC);
                tap_code16(FR_O);
            }
            return false;
        case FR_ICIRC:
            if (record->event.pressed) {
                tap_code16(FR_CIRC);
                tap_code16(FR_I);
            }
            return false;
        case FR_IDIAE:
            if (record->event.pressed) {
                tap_code16(FR_DIAE);
                tap_code16(FR_I);
            }
            return false;

        default:
            return true;
    }
}
