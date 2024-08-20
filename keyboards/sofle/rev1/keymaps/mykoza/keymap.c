#include <stdio.h>
#include QMK_KEYBOARD_H

enum sofle_layers { _COLEMAK, _GAMING, _NAV, _MOUSE, _MEDIA, _NUM, _SYM, _FUN };

enum custom_keycodes { COLEMAK = SAFE_RANGE, GAMING, NAV, MOUSE, MEDIA, NUM, SYM, FUN };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // COLEMAK
    // ┌-----------------------------------┐                 ┌-----------------------------------┐
    // | ESC |  1  |  2  |  3  |  4  |  5  |                 |  6  |  7  |  8  |  9  |  0  |  -  |
    // |-----------------------------------|                 |-----------------------------------|
    // | TAB |  Q  |  W  |  F  |  P  |  B  |                 |  J  |  L  |  U  |  Y  |  ;  |  [  |
    // |-----------------------------------|                 |-----------------------------------|
    // |  `  |  A  |  R  |  S  |  T  |  G  |                 |  M  |  N  |  E  |  I  |  O  |  '  |
    // |-----------------------------------|-----┐     ┌-----|-----------------------------------|
    // | CTL |  Z  |  X  |  C  |  D  |  V  |     |     |     |  K  |  H |  ,  |  .  |  /  | SFT |
    // └-----------------------------------------|     |-----------------------------------------┘
    //             | SUP | ALT | SFT | SPC | LOW |     | xxx | ENT | BSP | DEL | APP |
    //             |     |     |     | nav | mou |     | num | sym |     | fun | med |
    //             └-----------------------------┘     └-----------------------------┘
    [_COLEMAK] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC,
        KC_GRV, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT,
        KC_LCTL, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_NO, KC_NO, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LGUI, KC_LALT, KC_LSFT, LT(_NAV, KC_SPC), LT(_MOUSE, KC_TAB), LT(_NUM, KC_EQL), LT(_SYM, KC_ENT), RALT_T(KC_BSPC), LT(_FUN, KC_DEL), LT(_MEDIA, KC_APP)
    ),
    [_GAMING] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LGUI, KC_LALT, KC_LSFT, KC_SPC, KC_NO, DF(_COLEMAK), KC_ENT, KC_BSPC, KC_DEL, KC_APP
    ),
    [_NAV] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_AGIN, KC_PSTE, KC_COPY, KC_CUT, KC_UNDO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS, KC_RSFT,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT, KC_BSPC, KC_DEL, KC_APP
    ),
    [_MOUSE] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_AGIN, KC_PSTE, KC_COPY, KC_CUT, KC_UNDO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DF(_GAMING), KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN4, KC_BTN1, KC_BTN3, KC_BTN2, KC_BTN5
    ),
    [_MEDIA] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MSTP, KC_MPLY, KC_MUTE, KC_NO
    ),
    [_NUM] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_NO, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL, KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
        KC_NO, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ALGR, KC_NO, KC_NO,
        KC_DOT, KC_0, KC_MINS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [_SYM] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
        KC_NO, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_COLN, KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,
        KC_NO, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_PIPE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ALGR, KC_NO, KC_NO,
        KC_NO, KC_LPRN, KC_RPRN, KC_UNDS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [_FUN] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F12,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SCRL, KC_NO, KC_LSFT, KC_LCTL, KC_LALT, KC_CAPS, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PAUS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ALGR, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_APP, KC_SPC, KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(default_layer_state)) {
        case _COLEMAK:
            autoshift_enable();
            break;
        case _GAMING:
            autoshift_disable();
            break;
    }
    return state;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RALT_T(KC_BSPC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);

    switch (get_highest_layer(default_layer_state)) {
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n\n"), false);

    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navi\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mous\n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Medi\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Nums\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symb\n"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("Func\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}
#endif

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case GAMING:
//             if (record -> event.pressed) {
//                 set_single_persistent_default_layer(_GAMING);
//                 autoshift_disable();
//             }
//             return false;
//         case COLEMAK:
//             if (record -> event.pressed) {
//                 set_single_persistent_default_layer(_COLEMAK);
//                 autoshift_enable();
//             }
//             return false;
//     }
//     return true;
// }

#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}

#endif