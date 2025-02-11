#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAMING,
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

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP|      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     MC_6CIRC,KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,  XXXXXXX,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                        KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, XXXXXXX
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |  KP/ | KP7  | KP8  | KP9  |  €   |  ß   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |  KP* | KP4  | KP5  | KP6  |      |  Ü   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL|      |  F5  |  F6  |  F7  | F8   |-------.    ,-------|  KP- | KP1  | KP2  | KP3  |  Ö   |  Ä   |
 * |------+------+------+------+------+------|       |    |TG GAME|------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|  KP+ | KP0  |      | KP.  |      |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP|      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PSLS, KC_P7,   KC_P8,   KC_P9,   RALT(KC_5),RALT(KC_S),
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PAST, KC_P4,   KC_P5,   KC_P6,   XXXXXXX,   RALT(KC_Y),
  _______, XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,                     KC_PMNS, KC_P1,   KC_P2,   KC_P3,   RALT(KC_P),RALT(KC_Q),
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,TG(_GAMING),KC_PPLS,KC_P0,  XXXXXXX, KC_PDOT, XXXXXXX,   _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |PrntSc|      |  \   |  (   |  )   |      |                    |      |      |      | Del  |VolDow|VolUp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL|      | ` ~  |  [   |  ]   |      |-------.    ,-------| Left | Down |  Up  |Right |Pause |Next  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|      |  -   |  {   |  }   |      |-------|    |-------|      | Home |      | End  |      |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP|      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  KC_F12,  KC_F1,   KC_F2,   KC_F3,     KC_F4,     KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_PSCR, XXXXXXX, KC_BSLS, S(KC_9),   S(KC_0),   XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  KC_VOLD, KC_VOLU,
  _______, XXXXXXX, MC_GRV,  KC_LBRC,   KC_RBRC,   XXXXXXX,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY, KC_MNXT,
  _______, XXXXXXX, KC_MINS, S(KC_LBRC),S(KC_RBRC),XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, _______,
                             _______,   _______,   _______, _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP|      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                              _______, _______, _______, _______, _______,  _______, _______, _______
),




/* Gaming
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   5  | ESC  |   1  |   2  |   3  |   4  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------|------+------+------+------+------+                    |------+------+------+------+------+------|
 * |   T  | Tab  |   Q  |   W  |   E  |   R  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------|------+------+------+------+------+                    |------+------+------+------+------+------|
 * |   G  |LShift|   A  |   S  |   D  |   F  |-------.    ,-------|   H  |   J  |  Up  |   L  |   ;  |  '   |
 * |------|------+------+------+------+------+       |    |TG QWRT|------+------+------+------+------+------|
 * |   B  |LCTRL |   Z  |   X  |   C  |   V  |-------|    |-------|   N  | Left | Down | Right|   M  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP|      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_GAMING] = LAYOUT(
  KC_5,  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,                         MC_6CIRC,KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_T,  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
  KC_G,  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,                         KC_H,    KC_J,    KC_UP,   KC_L,    KC_SCLN, MC_QUOT,
  KC_B,  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,   XXXXXXX, TG(_GAMING), KC_N,   KC_LEFT, KC_DOWN, KC_RGHT, KC_M   , KC_RSFT,
                        KC_LGUI, KC_LALT,   XXXXXXX, KC_SPC, KC_ENT, XXXXXXX, KC_BSPC, XXXXXXX
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

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