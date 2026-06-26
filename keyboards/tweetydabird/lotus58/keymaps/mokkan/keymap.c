#include QMK_KEYBOARD_H

enum lotus_layers {
    _GALLIUM = 0,
    _NAV_NUM,
    _SYMBOLS,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_GALLIUM] = LAYOUT(
        KC_F1,    KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_KB_MUTE,     XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TAB,   KC_B,   KC_L,    KC_D,    KC_C,    KC_V,                             KC_J,    KC_Y,    KC_O,    KC_U,    KC_COMM, KC_DEL,
        KC_LCTL,  KC_N,   KC_R,    KC_T,    KC_S,    KC_G,                             KC_P,    KC_H,    KC_A,    KC_E,    KC_I,    KC_RCTL,
        KC_LSFT,  KC_X,   KC_Q,    KC_M,    KC_W,    KC_Z,    KC_ESC,         KC_BSPC, KC_K,    KC_F,    KC_QUOT, KC_SCLN, KC_DOT,  KC_RSFT,
                                   KC_LALT, KC_LGUI, TL_LOWR, KC_SPC,         KC_ENT,  TL_UPPR, KC_RGUI, KC_RALT
    ),

    [_NAV_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,        _______, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
        _______, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                          XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
        _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                          KC_SLSH, KC_1,    KC_2,    KC_3,    KC_MINS, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,        _______, KC_ASTR, KC_0,    KC_DOT,  KC_COLN, KC_PLUS, _______,
                                   _______, _______, _______, _______,        _______, _______, _______, _______ 
    ),

    [_SYMBOLS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, KC_GRV,  KC_TILD, KC_LCBR, KC_RCBR, KC_AMPR,                          KC_PIPE, KC_LBRC, KC_RBRC, KC_UNDS, XXXXXXX, _______,
        _______, KC_EXLM, KC_QUES, KC_LPRN, KC_RPRN, KC_BSLS,                          KC_SLSH, KC_LABK, KC_RABK, KC_EQL,  KC_MINS, _______,
        _______, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, _______,        _______, KC_ASTR, XXXXXXX, XXXXXXX, _______, KC_PLUS, _______,
                                   _______, _______, _______, _______,        _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,        QK_RBT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                   _______, _______, _______, _______,        _______, _______, _______, _______ 
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_GALLIUM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV_NUM] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_SYMBOLS] = { ENCODER_CCW_CW(MS_WHLD, MS_WHLU) },
    [_ADJUST]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};

const uint16_t PROGMEM lh_reboot_combo[] = { KC_F6, KC_ESC, COMBO_END };
const uint16_t PROGMEM rh_reboot_combo[] = { KC_F7, KC_BSPC, COMBO_END };

combo_t key_combos[] = {
    COMBO(lh_reboot_combo, QK_RBT),
    COMBO(rh_reboot_combo, QK_RBT),
};

bool oled_task_user(void) {
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case _GALLIUM:
            oled_write_P(PSTR("  Gal"), false);
            break;
        case _NAV_NUM:
            oled_write_P(PSTR(" Nav#"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("  Sym"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("  Adj"), false);
            break;
    }
    oled_write_P(PSTR("\n"), false);

    char wpm[6];
    snprintf(wpm, sizeof(wpm), " %03d ", get_current_wpm());

    oled_write_P(PSTR("-WPM-"), false);
    oled_write(wpm, false);

    return false;
}
