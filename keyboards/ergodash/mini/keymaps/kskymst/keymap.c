#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |  ⌘   |                    |   ⌘  |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      | Ctrl |  ALt |  ⌘   |||||||| LOWER | LOWER | Space |||| Enter | Raise| Raise||||||||   ⌘  |  ALt | Ctrl |      |
   * ,---------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT(
    KC_GRV, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LCMD,                        KC_RCMD, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    XXXXXXX,  KC_LCTL,  KC_LALT,  KC_LCMD,           LOWER, LOWER,  KC_SPC,      KC_ENT,   RAISE,  RAISE,          KC_RCMD, KC_LALT, KC_LCTL, XXXXXXX  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |   !  |   @  |   #  |   $  |   %  |      |                    |      |   ^  |   &  |   *  |   (  |   )  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  Tab |   1  |   2  |   3  |   4  |   5  |   (  |                    |   )  |      | Left |  Up  | Right|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  |  ⌘   |                    |   ⌘  |     |      | Down |     |        | Shift|
   * |-------------+------+-----+------+------+------+------+------+------+------+------+------+------+------+--------------|
   * |      | Ctrl |  ALt |  ⌘   |||||||| LOWER | LOWER | Space |||| Enter | Raise| Raise||||||||   ⌘  |  ALt | Ctrl |      |
   * ,----------------------```------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX,                        XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
    KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LPRN,                        KC_RPRN, XXXXXXX, KC_LEFT, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX , \
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LCMD,                        KC_RCMD , XXXXXXX,    XXXXXXX,   KC_DOWN,   XXXXXXX,   XXXXXXX, KC_RSFT, \
    XXXXXXX,  KC_LCTL,  KC_LALT,  KC_LCMD,           LOWER, LOWER,  KC_SPC,      KC_ENT,   RAISE,  RAISE,          KC_RCMD, KC_LALT, KC_LCTL, XXXXXXX  \
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * |  Esc |   !  |   @  |   #  |   $  |   %  |      |                    |      |   ^  |   &  |   *  |   (  |   )  |  \   |
  * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
  * |  Tab |   F1 |   F2 |   F3 |   F4 |   F5 |   (  |                    |   )  |      | Left |  Up  | Right|      |      |
  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
  * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 |   ⌘  |                    |   ⌘  |      |      | Down |      |      | Shift|
  * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
  * |      | Ctrl |  ALt |  ⌘   |||||||| LOWER | LOWER | Space |||| Enter | Raise| Raise||||||||   ⌘  |  ALt | Ctrl |      |
  * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    KC_ESC , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX,                        XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
    KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LPRN,                        KC_RPRN, XXXXXXX, KC_LEFT, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX , \
    KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_LCMD,                         KC_RCMD, XXXXXXX,    XXXXXXX,    KC_DOWN,   XXXXXXX,   XXXXXXX, KC_RSFT, \
    XXXXXXX,  KC_LCTL,  KC_LALT,  KC_LCMD,           LOWER, LOWER,  KC_SPC,      KC_ENT,   RAISE,  RAISE,          KC_RCMD, KC_LALT, KC_LCTL, XXXXXXX  \
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
