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
 * | LCTRL|   A  | S/Alt|D/Shft|F/Ctrl|   G  |-------.    ,-------|   H  |J/Ctrl|K/Shft|L/Alt |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |BackSP |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP|      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                            MC_6CIRC,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
  KC_LCTL,  KC_A,   ALT_S,   SFT_D,   CTL_F,   KC_G,                            KC_H,       CTL_J,   SFT_K,   ALT_L,   KC_SCLN, MC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,       XXXXXXX,   KC_BSPC,  KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                             KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,    KC_ENT,   MO(_RAISE), KC_BSPC, XXXXXXX
),
/* LOWER - special characters and navigation with mouse
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |      |      |  €   |      |      |                    |      |  Ü   |      |  Ö   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL|  Ä   |  ß   |LShift| Ctrl |      |-------.    ,-------|      |  [   |  ]   |  \   |      |      |
 * |------+------+------+------+------+------|       |    |TG GAME|------+------+------+------+------+------|
 * |LShift|      |  F5  |  F6  |  F7  | F8   |-------|    |-------|      |  {   |  }   | ` ~  |      |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP|      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,
  _______, XXXXXXX,    XXXXXXX,    RALT(KC_5), XXXXXXX, XXXXXXX,                        XXXXXXX, RALT(KC_Y), XXXXXXX,    RALT(KC_P), XXXXXXX, XXXXXXX,
  _______, RALT(KC_Q), RALT(KC_S), KC_LSFT,    KC_LCTL, XXXXXXX,                        XXXXXXX, KC_LBRC,    KC_RBRC,    KC_BSLS,    XXXXXXX, XXXXXXX,
  _______, XXXXXXX,    KC_F5,      KC_F6,      KC_F7,   KC_F8,   XXXXXXX,   TG(_GAMING),XXXXXXX, S(KC_LBRC), S(KC_RBRC), MC_GRV,     XXXXXXX, _______,
                                   _______,    _______, _______, _______,   _______,    _______, _______, _______
),
/* RAISE - navigation
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |  F6  |  F7  |  F8  |  F9  | F10  |                    |      |      |      | Del  |VolDow|VolUp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL|      | LAlt |LShift| Ctrl | F11  |-------.    ,-------| Left | Down |  Up  |Right |Pause |Next  |
 * |------+------+------+------+------+------| PrntSc|    |       |------+------+------+------+------+------|
 * |LShift|      |      |      |      | F12  |-------|    |-------|      | Home |      | End  |      |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP|      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  KC_VOLD, KC_VOLU,
  _______, XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, KC_F11,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY, KC_MNXT,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,  KC_PSCR,   XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, _______,
                             _______, _______, _______, _______,   _______,  _______, _______, _______
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
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            _______, _______, _______, _______,   _______,  _______, _______, _______
),




/* Gaming - standard base layer without home row mods, comfortable space from WASD and arrow keys
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  UP  |  '   |
 * |------+------+------+------+------+------| Del   |    |TG GAME|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  | Left | Down | Right|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |Space | /Space  /       \Enter \  |      |BackSP|      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_GAMING] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,  KC_3,    KC_4,    KC_5,                            MC_6CIRC,KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,  KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
  KC_LCTL,  KC_A,   KC_S,  KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_UP,   MC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,  KC_C,    KC_V,    KC_B,   KC_DEL,    TG(_GAMING),  KC_N,    KC_M,    KC_COMM, KC_LEFT, KC_DOWN, KC_RGHT,
                           KC_LGUI, KC_LALT, KC_SPC, KC_SPC,    KC_ENT,       XXXXXXX, KC_BSPC, XXXXXXX
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