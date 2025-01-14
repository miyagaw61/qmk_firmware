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
    WIN_FN,
};

enum custom_keycodes {
    CK_MOD1 = SAFE_RANGE,
    CK_MOD2,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define QK_DELAY 0x2000
#define DELAY(kc) (QK_DELAY | (kc))

#define REPEAT_TH 50
#define REPEAT_START_TH 300

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
         KC_ESC,              KC_F1,    KC_F2,                   KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,       KC_F8,     KC_F9,         KC_F10,      KC_F11,         KC_F12,    KC_DEL,    LSFT(LCTL(KC_K)),
         KC_GRV,    KC_1,     KC_2,     KC_3,                    KC_4,     KC_5,     KC_6,     KC_7,     KC_8,        KC_9,      KC_0,          KC_MINS,     LSFT(KC_MINS),  KC_INT3,   KC_BSPC,   KC_PGUP,
         KC_TAB,    KC_Q,     KC_W,     KC_E,                    KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,        KC_O,      KC_P,          KC_RBRC,     KC_NUHS,                              KC_PGDN,
         KC_LCTL,   KC_A,     KC_S,     KC_D,                    KC_F,     KC_G,     KC_H,     KC_J,     KC_K,        KC_L,      KC_SCLN,       LSFT(KC_7),  KC_NUHS,        KC_ENT,               KC_HOME,
         KC_LSFT,   KC_Z,     KC_X,     KC_C,                    KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,     KC_DOT,    KC_SLSH,       KC_INT1,     KC_RSFT,                   KC_UP,
         KC_CAPS,   KC_LWIN,  KC_LALT,  CK_MOD1,                 KC_SPC,                       CK_MOD2,               KC_RALT,   MO(WIN_FN),    KC_RCTL,                     KC_LEFT,   KC_DOWN,   KC_RGHT),

    [WIN_FN] = LAYOUT_jis_86(
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
    [WIN_BASE] = { ENCODER_CCW_CW(LSFT(LALT(KC_F5)), LALT(KC_F5))},
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
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

uint32_t is_lctl(void) {
    return (get_mods() & MOD_BIT(KC_LCTL));
}

uint32_t is_rctl(void) {
    return (get_mods() & MOD_BIT(KC_RCTL));
}

uint32_t is_ctl(void) {
    return get_mods() & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL));
}

void register_lctl(void) {
    register_mods(MOD_BIT(KC_LCTL));
}

void register_rctl(void) {
    register_mods(MOD_BIT(KC_RCTL));
}

void unregister_lctl(void) {
    unregister_mods(MOD_BIT(KC_LCTL));
}

void unregister_rctl(void) {
    unregister_mods(MOD_BIT(KC_RCTL));
}

uint32_t is_lalt(void) {
    return (get_mods() & MOD_BIT(KC_LALT));
}

uint32_t is_ralt(void) {
    return (get_mods() & MOD_BIT(KC_RALT));
}

uint32_t is_alt(void) {
    return get_mods() & (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT));
}

void register_lalt(void) {
    register_mods(MOD_BIT(KC_LALT));
}

void register_ralt(void) {
    register_mods(MOD_BIT(KC_RALT));
}

void unregister_lalt(void) {
    unregister_mods(MOD_BIT(KC_LALT));
}

void unregister_ralt(void) {
    unregister_mods(MOD_BIT(KC_RALT));
}

uint32_t is_lwin(void) {
    return (get_mods() & MOD_BIT(KC_LGUI));
}

uint32_t is_rwin(void) {
    return (get_mods() & MOD_BIT(KC_RGUI));
}

uint32_t is_win(void) {
    return get_mods() & (MOD_BIT(KC_LGUI) | MOD_BIT(KC_RGUI));
}

void register_lwin(void) {
    register_mods(MOD_BIT(KC_LGUI));
}

void register_rwin(void) {
    register_mods(MOD_BIT(KC_RGUI));
}

void unregister_lwin(void) {
    unregister_mods(MOD_BIT(KC_LGUI));
}

void unregister_rwin(void) {
    unregister_mods(MOD_BIT(KC_RGUI));
}

bool tap_with_sft(uint16_t keycode) {
    if (is_sft()) {
        tap_code(keycode);
        return false;
    }
    return true;
}

bool tap_without_sft(uint16_t keycode) {
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
    return true;
}

void send(uint16_t keycode) {
    uint16_t keycode_without_QK = (keycode & ~QK_LSFT);
    keycode_without_QK = (keycode_without_QK & ~QK_LCTL);
    keycode_without_QK = (keycode_without_QK & ~QK_LALT);
    keycode_without_QK = (keycode_without_QK & ~QK_LGUI);
    if (keycode & QK_LSFT) {
        register_lsft();
    }
    if (keycode & QK_LCTL) {
        register_lctl();
    }
    if (keycode & QK_LALT) {
        register_lalt();
    }
    if (keycode & QK_LGUI) {
        register_lwin();
    }
    tap_code(keycode_without_QK);
    if (keycode & QK_LSFT) {
        unregister_lsft();
    }
    if (keycode & QK_LCTL) {
        unregister_lctl();
    }
    if (keycode & QK_LALT) {
        unregister_lalt();
    }
    if (keycode & QK_LGUI) {
        unregister_lwin();
    }
}

static uint16_t delay_keycode = 0;

uint32_t send_delay(uint32_t trigger_time, void *cb_arg) {
    send(delay_keycode);
    return 0;
}

static bool mod1_oneshot = false;
static bool mod2_oneshot = false;
static bool mod1_enabled = false;
static bool mod2_enabled = false;

void oneshot_to_enabled(void) {
    if (mod1_oneshot) {
        mod1_oneshot = false;
        mod1_enabled = true;
    }
    if (mod2_oneshot) {
        mod2_oneshot = false;
        mod2_enabled = true;
    }
}

static bool mod2_f_repeat = false;
static int  mod2_f_delay = 0;
static bool mod2_b_repeat = false;
static int  mod2_b_delay = 0;

#define PROC_SFT(keycode1, keycode2) \
case keycode1: \
    if (!record->event.pressed) { \
        break; \
    } \
    if (mod1_oneshot | mod1_enabled) { \
        mod1_oneshot = false; \
        mod1_enabled = true; \
        break; \
    } \
    if (mod2_oneshot | mod2_enabled) { \
        mod2_oneshot = false; \
        mod2_enabled = true; \
        break; \
    } \
    if (keycode2 & QK_LSFT) { \
        uint16_t keycode2_new = (keycode2 & ~QK_LSFT); \
        return tap_with_sft(keycode2_new); \
    } else { \
        return tap_without_sft(keycode2); \
    } \
    break;

#define PROC_MOD1_TEMPLATE(keycode1) \
case keycode1: \
    if (!record->event.pressed) { \
        break; \
    } \
    if (is_sft()) { \
        break; \
    } \
    if (is_ctl()) { \
        break; \
    } \
    if (is_win()) { \
        break; \
    } \
    if (mod2_oneshot) { \
        mod2_oneshot = false; \
        mod2_enabled = true; \
    } \
    if (mod1_oneshot | mod1_enabled) { \
        mod1_oneshot = false; \
        mod1_enabled = true;

#define PROC_MOD1(keycode1, keycode2) \
case keycode1: \
    if (!record->event.pressed) { \
        break; \
    } \
    if (is_sft()) { \
        break; \
    } \
    if (mod2_oneshot) { \
        mod2_oneshot = false; \
        mod2_enabled = true; \
    } \
    if (mod1_oneshot | mod1_enabled) { \
        mod1_oneshot = false; \
        mod1_enabled = true; \
        send(keycode2); \
        return false; \
    } \
    break;

#define PROC_MOD1_2(keycode1, keycode2, keycode3) \
case keycode1: \
    if (!record->event.pressed) { \
        break; \
    } \
    if (is_sft()) { \
        break; \
    } \
    if (is_ctl()) { \
        break; \
    } \
    if (is_win()) { \
        break; \
    } \
    if (mod2_oneshot) { \
        mod2_oneshot = false; \
        mod2_enabled = true; \
    } \
    if (mod1_oneshot | mod1_enabled) { \
        mod1_oneshot = false; \
        mod1_enabled = true; \
        send(keycode2); \
        if (keycode3 & QK_DELAY) { \
            delay_keycode = (keycode3 & ~QK_DELAY); \
            defer_exec(300, send_delay, NULL); \
            return false; \
        } \
        send(keycode3); \
        return false; \
    } \
    break;

#define PROC_MOD2(keycode1, keycode2) \
case keycode1: \
    if (!record->event.pressed) { \
        break; \
    } \
    if (is_sft()) { \
        break; \
    } \
    if (mod1_oneshot) { \
        mod1_oneshot = false; \
        mod1_enabled = true; \
    } \
    if (mod2_oneshot | mod2_enabled) { \
        mod2_oneshot = false; \
        mod2_enabled = true; \
        send(keycode2); \
        return false; \
    } \
    break;

#define PROC_MOD2_2(keycode1, keycode2, keycode3) \
case keycode1: \
    if (!record->event.pressed) { \
        break; \
    } \
    if (is_sft()) { \
        break; \
    } \
    if (is_ctl()) { \
        break; \
    } \
    if (is_win()) { \
        break; \
    } \
    if (mod1_oneshot) { \
        mod1_oneshot = false; \
        mod1_enabled = true; \
    } \
    if (mod2_oneshot | mod2_enabled) { \
        mod2_oneshot = false; \
        mod2_enabled = true; \
        send(keycode2); \
        if (keycode3 & QK_DELAY) { \
            delay_keycode = (keycode3 & ~QK_DELAY); \
            defer_exec(300, send_delay, NULL); \
            return false; \
        } \
        send(keycode3); \
        return false; \
    } \
    break;

#define PROC_MOD1_SFT(keycode1, keycode2) \
case keycode1: \
    if (!record->event.pressed) { \
        break; \
    } \
    if (mod2_oneshot) { \
        mod2_oneshot = false; \
        mod2_enabled = true; \
    } \
    if (mod1_oneshot | mod1_enabled) { \
        mod1_oneshot = false; \
        mod1_enabled = true; \
        if (is_lsft()) { \
            unregister_lsft(); \
        } else if (is_rsft()) { \
            unregister_rsft(); \
        } else { \
            break; \
        } \
        send(keycode2); \
        return false; \
    } \
    break;

#define PROC_MOD2_SFT(keycode1, keycode2) \
case keycode1: \
    if (!record->event.pressed) { \
        break; \
    } \
    if (mod1_oneshot) { \
        mod1_oneshot = false; \
        mod1_enabled = true; \
    } \
    if (mod2_oneshot | mod2_enabled) { \
        mod2_oneshot = false; \
        mod2_enabled = true; \
        if (is_lsft()) { \
            unregister_lsft(); \
        } else if (is_rsft()) { \
            unregister_rsft(); \
        } else { \
            break; \
        } \
        send(keycode2); \
        return false; \
    } \
    break;

#define PROC_MOD1_SFT_2(keycode1, keycode2, keycode3) \
case keycode1: \
    if (!record->event.pressed) { \
        break; \
    } \
    if (mod2_oneshot) { \
        mod2_oneshot = false; \
        mod2_enabled = true; \
    } \
    if (mod1_oneshot | mod1_enabled) { \
        mod1_oneshot = false; \
        mod1_enabled = true; \
        if (is_lsft()) { \
            unregister_lsft(); \
        } else if (is_rsft()) { \
            unregister_rsft(); \
        } else { \
            break; \
        } \
        send(keycode2); \
        if (keycode3 & QK_DELAY) { \
            delay_keycode = (keycode3 & ~QK_DELAY); \
            defer_exec(300, send_delay, NULL); \
            return false; \
        } \
        send(keycode3); \
        return false; \
    } \
    break;

#define PROC_MOD2_SFT_2(keycode1, keycode2, keycode3) \
case keycode1: \
    if (!record->event.pressed) { \
        break; \
    } \
    if (mod1_oneshot) { \
        mod1_oneshot = false; \
        mod1_enabled = true; \
    } \
    if (mod2_oneshot | mod2_enabled) { \
        mod2_oneshot = false; \
        mod2_enabled = true; \
        if (is_lsft()) { \
            unregister_lsft(); \
        } else if (is_rsft()) { \
            unregister_rsft(); \
        } else { \
            break; \
        } \
        send(keycode2); \
        if (keycode3 & QK_DELAY) { \
            delay_keycode = (keycode3 & ~QK_DELAY); \
            defer_exec(300, send_delay, NULL); \
            return false; \
        } \
        send(keycode3); \
        return false; \
    } \
    break;

bool process_custom_sft_keys(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        PROC_SFT(KC_2,          KC_LBRC);
        PROC_SFT(KC_6,          KC_EQL);
        PROC_SFT(KC_7,          LSFT(KC_6));
        PROC_SFT(KC_8,          LSFT(KC_QUOT));
        PROC_SFT(KC_9,          LSFT(KC_8));
        PROC_SFT(KC_0,          LSFT(KC_9));
        PROC_SFT(KC_MINS,       LSFT(KC_INT1)); // -=  ->  -_
        PROC_SFT(LSFT(KC_MINS), LSFT(KC_SCLN)); // ^~  ->  =+
        PROC_SFT(KC_RBRC,       LSFT(KC_RBRC)); // @`  ->  [{
        PROC_SFT(KC_NUHS,       LSFT(KC_NUHS)); // [{  ->  ]}
        PROC_SFT(KC_SCLN,       KC_QUOT);       // ;+  ->  ;:
        PROC_SFT(LSFT(KC_7),    LSFT(KC_2));    // :*  ->  '"
        PROC_SFT(KC_INT1,       LSFT(KC_INT3)); // \_  ->  \|
    }
    return true;
}

bool process_mod1_keys(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        PROC_MOD1(LSFT(KC_7), LSFT(KC_LBRC));  // MOD1+'  ->  `
        PROC_MOD1(KC_SLSH,    LSFT(KC_EQL));   // MOD1+/  ->  ~
        PROC_MOD1(KC_D,       LCTL(KC_F1));    // MOD1+D  ->  CTL+F1
        PROC_MOD1(KC_X,       LSFT(LCTL(KC_K)));    // MOD1+X  ->  SFT+CTL+K
        PROC_MOD1(KC_SPC,     LSFT(LCTL(KC_SPC)));  // MOD1+SPC  ->  SFT+CTL+SPC
        PROC_MOD1_2(KC_I,    KC_I, KC_INT5);   // MOD1+I  ->  I, MOD1-ONESHOT
        PROC_MOD1_2(KC_O,    KC_O, KC_INT5);   // MOD1+O  ->  O, MOD1-ONESHOT
        PROC_MOD1_2(KC_A,    KC_A, KC_INT5);   // MOD1+A  ->  A, MOD1-ONESHOT
        PROC_MOD1_2(KC_J,    KC_INT4, KC_ESC); // MOD1+J  ->  MOD2-ONESHOT, ESC
        PROC_MOD1_2(KC_DOWN, LCTL(LALT(KC_PAUS)), DELAY(LALT(KC_TAB))); // MOD1+DOWN  ->  CTL+ALT+PAUSE, ALT+TAB
        PROC_MOD1_2(KC_UP,   LWIN(KC_3),          DELAY(LWIN(KC_UP)));  // MOD1+UP    ->  WIN+3, WIN+UP
        PROC_MOD1_TEMPLATE(KC_M) // MOD1+M  ->  ESC, SPC, W, CTL+S, H, CTL+C, CTL+C, M, A, K, E, ENTER, CTL+S, L
            send(KC_ESC);
            send(KC_SPC);
            send(KC_W);
            send(LCTL(KC_S));
            send(KC_H);
            send(LCTL(KC_C));
            send(LCTL(KC_C));
            send(KC_M);
            send(KC_A);
            send(KC_K);
            send(KC_E);
            send(KC_ENT);
            send(LCTL(KC_S));
            send(KC_L);
            return false;
        }
        break;
    }
    return true;
}

bool process_mod2_keys(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        PROC_MOD2(KC_E, KC_END);  // MOD2+E  ->  END
        PROC_MOD2(KC_A, KC_HOME); // MOD2+A  ->  HOME
        PROC_MOD2_2(KC_U, LSFT(KC_HOME), LCTL(KC_X)); // MOD2+U  ->  SFT+HOME, CTL+X
        case KC_F: // MOD2+F  ->  RIGHT (repeatable)
            if (record->event.pressed) {
                if (mod1_oneshot) {
                    mod1_oneshot = false;
                    mod1_enabled = true;
                }
                if (mod2_oneshot | mod2_enabled) {
                    mod2_oneshot = false;
                    mod2_enabled = true;
                    mod2_f_repeat = true;
                    return false;
                }
            } else {
                if (mod2_f_repeat) {
                    mod2_f_repeat = false;
                    mod2_f_delay = 0;
                    return false;
                }
            }
            break;
        case KC_B: // MOD2+B  ->  LEFT (repeatable)
            if (record->event.pressed) {
                if (mod1_oneshot) {
                    mod1_oneshot = false;
                    mod1_enabled = true;
                }
                if (mod2_oneshot | mod2_enabled) {
                    mod2_oneshot = false;
                    mod2_enabled = true;
                    mod2_b_repeat = true;
                    return false;
                }
            } else {
                if (mod2_b_repeat) {
                    mod2_b_repeat = false;
                    mod2_b_delay = 0;
                    return false;
                }
            }
            break;
    }
    return true;
}

bool process_mod1_sft_keys(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        PROC_MOD1_SFT_2(KC_I, LSFT(KC_I), KC_INT5); // MOD1+SFT+I  ->  SFT+I, MOD1-ONESHOT
        PROC_MOD1_SFT_2(KC_O, LSFT(KC_O), KC_INT5); // MOD1+SFT+O  ->  SFT+O, MOD1-ONESHOT
        PROC_MOD1_SFT_2(KC_A, LSFT(KC_A), KC_INT5); // MOD1+SFT+A  ->  SFT+A, MOD1-ONESHOT
    }
    return true;
}

bool process_mod2_sft_keys(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        PROC_MOD2_SFT(KC_E, LSFT(KC_END));  // MOD2+SFT+E  ->  SFT+END
        PROC_MOD2_SFT(KC_A, LSFT(KC_HOME)); // MOD2+SFT+A  ->  SFT+HOME
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool result;
    result = process_custom_sft_keys(keycode, record);
    if (!result) {
        return result;
    }
    result = process_mod1_keys(keycode, record);
    if (!result) {
        return result;
    }
    result = process_mod2_keys(keycode, record);
    if (!result) {
        return result;
    }
    result = process_mod1_sft_keys(keycode, record);
    if (!result) {
        return result;
    }
    result = process_mod2_sft_keys(keycode, record);
    if (!result) {
        return result;
    }
    switch (keycode) {
        case CK_MOD1:
            if (record->event.pressed) {
                mod1_oneshot = true;
            } else {
                if (mod1_oneshot) {
                    tap_code(KC_INT5);
                }
                mod1_oneshot = false;
                mod1_enabled = false;
            }
            return false;
        case CK_MOD2:
            if (record->event.pressed) {
                mod2_oneshot = true;
            } else {
                if (mod2_oneshot) {
                    tap_code(KC_INT4);
                }
                mod2_oneshot = false;
                mod2_enabled = false;
            }
            return false;
        default:
            if (record->event.pressed) {
                oneshot_to_enabled();
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (mod2_f_repeat) {
        if (mod2_f_delay == 0 || mod2_f_delay > (REPEAT_TH + REPEAT_START_TH)) {
            tap_code(KC_RGHT);
            if (mod2_f_delay != 0) {
                mod2_f_delay = REPEAT_START_TH;
            }
        }
        mod2_f_delay++;
    }

    if (mod2_b_repeat) {
        if (mod2_b_delay == 0 || mod2_b_delay > (REPEAT_TH + REPEAT_START_TH)) {
            tap_code(KC_LEFT);
            if (mod2_b_delay != 0) {
                mod2_b_delay = REPEAT_START_TH;
            }
        }
        mod2_b_delay++;
    }
}
