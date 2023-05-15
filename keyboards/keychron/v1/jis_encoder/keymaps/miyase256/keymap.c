/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN_1,
    WIN_FN_2,
    WIN_FN_3,
};

enum custom_keycodes {
    CK_WIN_FN_1 = SAFE_RANGE,
    CK_WIN_FN_2,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_jis_86(
         KC_ESC,             KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,    KC_VOLD,  KC_VOLU,  KC_DEL,   KC_MUTE,
         KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_INT3,  KC_BSPC,  KC_PGUP,
         KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
         KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
         KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,    KC_INT1,  KC_RSFT,  KC_UP,
         KC_LCTL,  KC_LOPT,  KC_LCMD,  KC_LNG2,                      KC_SPC,                       KC_LNG1,  KC_RCMD,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_jis_86(
         _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,   _______,  RGB_TOG,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
         RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
         _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,    _______,  _______,  _______,
         _______,  _______,  _______,  _______,                      _______,                      _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_jis_86(
         KC_ESC,              KC_F1,    KC_F2,                   KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,       KC_F8,                  KC_F9,    KC_F10,     KC_F11,   KC_F12,   KC_DEL,   KC_MUTE,
         KC_GRV,    KC_1,     KC_2,     KC_3,                    KC_4,     KC_5,     KC_6,     KC_7,     KC_8,        KC_9,                   KC_0,     KC_MINS,    KC_EQL,   KC_INT3,  KC_BSPC,  KC_PGUP,
         KC_TAB,    KC_Q,     KC_W,     KC_E,                    KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,        KC_O,                   KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
         KC_LCTL,   KC_A,     KC_S,     KC_D,                    KC_F,     KC_G,     KC_H,     KC_J,     KC_K,        KC_L,                   KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
         KC_LSFT,   KC_Z,     KC_X,     KC_C,                    KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,     KC_DOT,                 KC_SLSH,  KC_INT1,    KC_RSFT,  KC_UP,
         KC_CAPS,   KC_LWIN,  KC_LALT,  CK_WIN_FN_1,                       KC_SPC,                       CK_WIN_FN_2, KC_RALT,  MO(WIN_FN_3), KC_RCTL,  KC_LEFT,    KC_DOWN,  KC_RGHT),

    [WIN_FN_1] = LAYOUT_jis_86(
         KC_ESC,              KC_F1,    KC_F2,                   KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,       KC_F8,                  KC_F9,    KC_F10,     KC_F11,   KC_F12,   KC_DEL,   KC_MUTE,
         KC_GRV,    KC_1,     KC_2,     KC_3,                    KC_4,     KC_5,     KC_6,     KC_7,     KC_8,        KC_9,                   KC_0,     KC_MINS,    KC_EQL,   KC_INT3,  KC_BSPC,  KC_PGUP,
         KC_TAB,    KC_Q,     KC_W,     KC_E,                    KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,        KC_O,                   KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
         KC_LCTL,   KC_A,     KC_S,     KC_D,                    KC_F,     KC_G,     KC_H,     KC_J,     KC_K,        KC_L,                   KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
         KC_LSFT,   KC_Z,     KC_X,     KC_C,                    KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,     KC_DOT,                 KC_SLSH,  KC_INT1,    KC_RSFT,  KC_UP,
         KC_CAPS,   KC_LWIN,  KC_LALT,  _______,                           KC_SPC,                       _______,     KC_RALT,    _______,    KC_RCTL,    KC_LEFT,  KC_DOWN,    KC_RGHT),

    [WIN_FN_2] = LAYOUT_jis_86(
         KC_ESC,              KC_F1,    KC_F2,                   KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,       KC_F8,                  KC_F9,    KC_F10,     KC_F11,   KC_F12,   KC_DEL,   KC_MUTE,
         KC_GRV,    KC_1,     KC_2,     KC_3,                    KC_4,     KC_5,     KC_6,     KC_7,     KC_8,        KC_9,                   KC_0,     KC_MINS,    KC_EQL,   KC_INT3,  KC_BSPC,  KC_PGUP,
         KC_TAB,    KC_Q,     KC_W,     KC_E,                    KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,        KC_O,                   KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
         KC_LCTL,   KC_A,     KC_S,     KC_D,                    KC_F,     KC_G,     KC_H,     KC_J,     KC_K,        KC_L,                   KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
         KC_LSFT,   KC_Z,     KC_X,     KC_C,                    KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,     KC_DOT,                 KC_SLSH,  KC_INT1,    KC_RSFT,  KC_UP,
         KC_CAPS,   KC_LWIN,  KC_LALT,  _______,                           KC_SPC,                       _______,     KC_RALT,    _______,    KC_RCTL,    KC_LEFT,  KC_DOWN,    KC_RGHT),

    [WIN_FN_3] = LAYOUT_jis_86(
         _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,    KC_VOLD,  KC_VOLU,  _______,  RGB_TOG,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
         RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
         _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
         _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,    _______,  _______,  _______,
         QK_BOOT,  _______,  _______,  _______,                      _______,                      _______,  _______,  _______,    _______,  _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN_1] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_FN_2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_FN_3] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

uint32_t is_lsft(void) {
    return (get_mods() & MOD_BIT(KC_LSFT));
}

uint32_t is_rsft(void) {
    return (get_mods() & MOD_BIT(KC_RSFT));
}

uint32_t is_sft(void) {
    return get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
}

void register_lsft(void) {
    register_mods(MOD_BIT(KC_LSFT));
}

void register_rsft(void) {
    register_mods(MOD_BIT(KC_RSFT));
}

void unregister_lsft(void) {
    unregister_mods(MOD_BIT(KC_LSFT));
}

void unregister_rsft(void) {
    unregister_mods(MOD_BIT(KC_RSFT));
}

bool tap_with_sft(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_sft()) {
            tap_code(keycode);
            return false;
        }
    }
    return true;
}

bool tap_without_sft(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_lsft()) {
            unregister_lsft();
            tap_code(keycode);
            register_lsft();
            return false;
        }
        if (is_rsft()) {
            unregister_rsft();
            tap_code(keycode);
            register_rsft();
            return false;
        }
    }
    return true;
}

bool tap_with_sft_or(uint16_t keycode1, uint16_t keycode2, keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_sft()) {
            tap_code(keycode1);
            return false;
        } else {
            tap_code(keycode2);
            return false;
        }
    }
    return true;
}

bool tap_without_sft_or(uint16_t keycode1, uint16_t keycode2, keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_lsft()) {
            unregister_lsft();
            tap_code(keycode1);
            register_lsft();
            return false;
        } else if (is_rsft()) {
            unregister_rsft();
            tap_code(keycode1);
            register_rsft();
            return false;
        } else {
            tap_code(keycode2);
            return false;
        }
    }
    return true;
}

bool tap_with_sft_or_plus_sft(uint16_t keycode1, uint16_t keycode2, keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_sft()) {
            tap_code(keycode1);
            return false;
        } else {
            register_lsft();
            tap_code(keycode2);
            unregister_lsft();
            return false;
        }
    }
    return true;
}

bool tap_without_sft_or_plus_sft(uint16_t keycode1, uint16_t keycode2, keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_lsft()) {
            unregister_lsft();
            tap_code(keycode1);
            register_lsft();
            return false;
        } else if (is_rsft()) {
            unregister_rsft();
            tap_code(keycode1);
            register_rsft();
            return false;
        } else {
            register_lsft();
            tap_code(keycode2);
            unregister_lsft();
            return false;
        }
    }
    return true;
}

static bool win_fn_1_oneshot = false;
static bool win_fn_2_oneshot = false;
static bool win_fn_1_enabled = false;
static bool win_fn_2_enabled = false;

void oneshot_to_enabled(keyrecord_t *record) {
    if (record->event.pressed) {
        if (win_fn_1_oneshot) {
            win_fn_1_oneshot = false;
            win_fn_1_enabled = true;
        }
        if (win_fn_2_oneshot) {
            win_fn_2_oneshot = false;
            win_fn_2_enabled = true;
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSFT:
            oneshot_to_enabled(record);
            break;
        case KC_RSFT:
            oneshot_to_enabled(record);
            break;
        case KC_2:
            oneshot_to_enabled(record);
            return tap_without_sft(KC_LBRC, record);
        case KC_6:
            oneshot_to_enabled(record);
            return tap_without_sft(KC_EQL, record);
        case KC_7:
            oneshot_to_enabled(record);
            return tap_with_sft(KC_6, record);
        case KC_8:
            oneshot_to_enabled(record);
            return tap_with_sft(KC_QUOT, record);
        case KC_9:
            oneshot_to_enabled(record);
            return tap_with_sft(KC_8, record);
        case KC_0:
            oneshot_to_enabled(record);
            return tap_with_sft(KC_9, record);
        case KC_MINS: // -,= (-,_)
            oneshot_to_enabled(record);
            return tap_with_sft(KC_INT1, record);
        case KC_EQL: // ^, ~ (=, +)
            oneshot_to_enabled(record);
            return tap_with_sft_or_plus_sft(KC_SCLN, KC_MINS, record);
        case KC_E:
            if (!record->event.pressed) {
                break;
            }
            if (win_fn_1_oneshot) {
                win_fn_1_oneshot = false;
                win_fn_1_enabled = true;
            }
            if (win_fn_2_oneshot) {
                win_fn_2_oneshot = false;
                win_fn_2_enabled = true;
                tap_code(KC_END);
                return false;
            }
        case KC_I:
            if (!record->event.pressed) {
                break;
            }
            if (win_fn_2_oneshot) {
                win_fn_2_oneshot = false;
                win_fn_2_enabled = true;
            }
            if (win_fn_1_oneshot) {
                win_fn_1_oneshot = false;
                win_fn_1_enabled = true;
                tap_code(KC_INT5);
                if (is_lsft()) {
                    register_lsft();
                    tap_code(KC_I);
                    unregister_lsft();
                } else if (is_rsft()) {
                    register_rsft();
                    tap_code(KC_I);
                    unregister_rsft();
                } else {
                    tap_code(KC_I);
                }
                tap_code(KC_INT4);
                return false;
            }
            break;
        case KC_O:
            if (!record->event.pressed) {
                break;
            }
            if (win_fn_2_oneshot) {
                win_fn_2_oneshot = false;
                win_fn_2_enabled = true;
            }
            if (win_fn_1_oneshot) {
                win_fn_1_oneshot = false;
                win_fn_1_enabled = true;
                tap_code(KC_INT5);
                if (is_lsft()) {
                    register_lsft();
                    tap_code(KC_O);
                    unregister_lsft();
                } else if (is_rsft()) {
                    register_rsft();
                    tap_code(KC_O);
                    unregister_rsft();
                } else {
                    tap_code(KC_O);
                }
                tap_code(KC_INT4);
                return false;
            }
            break;
        case KC_LBRC: // ([, {)
            oneshot_to_enabled(record);
            return tap_with_sft_or(KC_RBRC, KC_RBRC, record);
        case KC_RBRC: // (], })
            oneshot_to_enabled(record);
            return tap_with_sft_or(KC_NUHS, KC_NUHS, record);
        case KC_A:
            if (!record->event.pressed) {
                break;
            }
            if (win_fn_1_oneshot) {
                win_fn_1_oneshot = false;
                win_fn_1_enabled = true;
                tap_code(KC_INT5);
                if (is_lsft()) {
                    register_lsft();
                    tap_code(KC_A);
                    unregister_lsft();
                } else if (is_rsft()) {
                    register_rsft();
                    tap_code(KC_A);
                    unregister_rsft();
                } else {
                    tap_code(KC_A);
                }
                tap_code(KC_INT4);
                return false;
            }
            if (win_fn_2_oneshot) {
                win_fn_2_oneshot = false;
                win_fn_2_enabled = true;
                tap_code(KC_HOME);
                return false;
            }
            break;
        case KC_J:
            if (!record->event.pressed) {
                break;
            }
            if (win_fn_2_oneshot) {
                win_fn_2_oneshot = false;
                win_fn_2_enabled = true;
            }
            if (win_fn_1_oneshot) {
                win_fn_1_oneshot = false;
                win_fn_1_enabled = true;
                tap_code(KC_INT5);
                tap_code(KC_ESC);
                win_fn_1_oneshot = false;
                return false;
            }
            break;
        case KC_SCLN: // ;, + (;, :)
            oneshot_to_enabled(record);
            return tap_without_sft(KC_QUOT, record);
        case KC_QUOT: // :, * (', ", `)
            if (!record->event.pressed) {
                break;
            }
            if (win_fn_2_oneshot) {
                win_fn_2_oneshot = false;
                win_fn_2_enabled = true;
            }
            if (win_fn_1_oneshot | win_fn_1_enabled) {
                win_fn_1_oneshot = false;
                win_fn_1_enabled = true;
                register_lsft();
                tap_code(KC_LBRC);
                unregister_lsft();
                return false;
            }
            return tap_with_sft_or_plus_sft(KC_2, KC_7, record);
        case KC_SLSH: // /, ?, ~
            if (!record->event.pressed) {
                break;
            }
            if (win_fn_2_oneshot) {
                win_fn_2_oneshot = false;
                win_fn_2_enabled = true;
            }
            if (win_fn_1_oneshot | win_fn_1_enabled) {
                win_fn_1_oneshot = false;
                win_fn_1_enabled = true;
                register_lsft();
                tap_code(KC_EQL);
                unregister_lsft();
                return false;
            }
            break;
        case KC_INT1: // \, _ (\, |)
            oneshot_to_enabled(record);
            return tap_with_sft(KC_INT3, record);
        case CK_WIN_FN_1:
            if (record->event.pressed) {
                win_fn_1_oneshot = true;
                layer_on(WIN_FN_1);
            } else {
                layer_off(WIN_FN_1);
                if (win_fn_1_oneshot) {
                    tap_code(KC_INT5);
                }
                win_fn_1_oneshot = false;
                win_fn_1_enabled = false;
            }
            return false;
        case CK_WIN_FN_2:
            if (record->event.pressed) {
                win_fn_2_oneshot = true;
                layer_on(WIN_FN_2);
            } else {
                layer_off(WIN_FN_2);
                if (win_fn_2_oneshot) {
                    tap_code(KC_INT4);
                }
                win_fn_2_oneshot = false;
                win_fn_2_enabled = false;
            }
            return false;
        default:
            oneshot_to_enabled(record);
            break;
    }
    return true;
}
