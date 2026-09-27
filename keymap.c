#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _SYM,
  _NAV,
  _NUMPAD
};

/// TODO:
// - tap hold umlauts? https://docs.qmk.fm/tap_hold
//   -> https://docs.qmk.fm/features/tap_dance#example-3
//   or double tap is easier? https://docs.qmk.fm/features/tap_dance#simple-example

// workaround for dead keys, see:
// https://github.com/davidramiro/km96-usintl-de/blob/master/keymap.c
// Keycodes for dead keys
enum custom_keycodes {
    MC_QUOT = SAFE_RANGE,
    MC_GRV,
    MC_6CIRC
};


// https://github.com/qmk/qmk_firmware/blob/master/docs/features/key_overrides.md
//const key_override_t circum_override = ko_make_basic(MOD_MASK_SHIFT, KC_6, MC_CIRCUM);
//
//// This globally defines all key overrides to be used
//const key_override_t *key_overrides[] = {
//	&circum_override
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                   MC_6CIRC,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                   KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
  MO(_NAV), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                                   KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN, MC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,       MO(_NUMPAD),  XXXXXXX,      KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL,                   KC_LGUI, KC_LALT, MO(_SYM),   KC_SPC,       KC_SPC,       MO(_NAV),   KC_RALT, KC_RGUI
),

[_SYM] = LAYOUT(
  XXXXXXX, KC_F1,      KC_F2,      KC_F3,      KC_F4,   XXXXXXX,                         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,
  _______, KC_F5,      KC_F6,      KC_F7,      KC_F8,   XXXXXXX,                         KC_MINS,    S(KC_9),    S(KC_0),    S(KC_BSLS), XXXXXXX, XXXXXXX,
  _______, KC_F9,      KC_F10,     KC_F11,     KC_F12,  XXXXXXX,                         KC_EQL,     KC_LBRC,    KC_RBRC,    KC_BSLS,    XXXXXXX, XXXXXXX,
  _______, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,     MC_QUOT,    S(KC_LBRC), S(KC_RBRC), MC_GRV,     XXXXXXX, _______,
  _______,                         _______,    _______, _______, _______,   _______,     _______, _______, _______
),

[_NAV] = LAYOUT(
  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,   XXXXXXX, KC_PSCR,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    RALT(KC_S), 
  _______, XXXXXXX,    KC_LGUI, RALT(KC_5),XXXXXXX, XXXXXXX,                     KC_BSPC, KC_ENT,  XXXXXXX, KC_DEL,  XXXXXXX,    RALT(KC_Y), 
  _______, XXXXXXX,    KC_LALT, KC_LSFT,   KC_LCTL, XXXXXXX,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, RALT(KC_P), RALT(KC_Q), 
  _______, KC_MUTE,    KC_MPLY, KC_VOLU,   XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,    _______,
  _______,                      _______,   _______, _______, _______,   _______, _______, _______, _______
),

[_NUMPAD] = LAYOUT(
  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,                     XXXXXXX, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, 
  _______, XXXXXXX,    XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,                     XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, XXXXXXX, 
  _______, XXXXXXX,    XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,                     XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX, 
  _______, XXXXXXX,    XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, _______,   XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, XXXXXXX,
  _______,                      _______,   _______, _______, _______,   _______, _______, KC_KP_0, KC_PDOT
),

};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

// workaround for dead keys, see:
// https://github.com/davidramiro/km96-usintl-de/blob/master/keymap.c
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MC_QUOT:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_SPC));
        }
        break;
    case MC_GRV:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_GRV) SS_TAP(X_SPC));
        }
        break;    
    case MC_6CIRC:
        if(record->event.pressed){
            SEND_STRING(SS_TAP(X_6));

            if((get_mods() & MOD_MASK_SHIFT) != 0)
            {
              SEND_STRING(SS_TAP(X_SPC));
            }
        }
        break;
    }
    return true;
};