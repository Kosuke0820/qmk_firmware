/* Copyright 2019 zk-phi
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

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum custom_keycodes {
  DOG = SAFE_RANGE,
  DOG_2,
  DOGE,
  DOG_BROWN,
  DOG_HOUSE,
  DOG_BOWL,
  DOG_BLACK,
  POODLE,
  HOWDY,
  HOTDOG,
  DATADOG,
  GENBA_HOWDY,
  GENBA_CAT,
  UI,
  KAIZEN,
  DOUBUTSUEN
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DOG:
      if (record->event.pressed) {
        SEND_STRING(":dog:");
      }
      break;
    case DOG_2:
      if (record->event.pressed) {
        SEND_STRING(":dog2:");
      }
      break;
    case DOGE:
      if (record->event.pressed) {
        SEND_STRING(":doge:");
      }
      break;
    case DOG_BROWN:
      if (record->event.pressed) {
        SEND_STRING(":dog_brown:");
      }
      break;
    case DOG_HOUSE:
      if (record->event.pressed) {
        SEND_STRING(":dog_house:");
      }
      break;
    case DOG_BOWL:
      if (record->event.pressed) {
        SEND_STRING(":dog_bowl:");
      }
      break;
    case DOG_BLACK:
      if (record->event.pressed) {
        SEND_STRING(":dog_black:");
      }
      break;
    case POODLE:
      if (record->event.pressed) {
        SEND_STRING(":poodle:");
      }
      break;
    case HOWDY:
      if (record->event.pressed) {
        SEND_STRING(":howdy:");
      }
      break;
    case HOTDOG:
      if (record->event.pressed) {
        SEND_STRING(":hotdog:");
      }
      break;
    case DATADOG:
      if (record->event.pressed) {
        SEND_STRING(":datadog:");
      }
      break;
    case GENBA_HOWDY:
      if (record->event.pressed) {
        SEND_STRING(":genba_howdy:");
      }
      break;
    case GENBA_CAT:
      if (record->event.pressed) {
        SEND_STRING(":genba_cat:");
      }
      break;
    case UI:
      if (record->event.pressed) {
        SEND_STRING(":word_ui:");
      }
      break;
    case KAIZEN:
      if (record->event.pressed) {
        SEND_STRING(":kaizen:");
      }
      break;
    case DOUBUTSUEN:
      if (record->event.pressed) {
        SEND_STRING(":doubutsuen:");
      }
      break;
  }
  return true;
};

enum layers {
    DEFAULT,
    RAISE,
    LOWER,
    ADJUST
};

// キー配置変える時は以下いじってください
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT] = LAYOUT(
        UI, KAIZEN, DOUBUTSUEN,
        DOG, DOG_BROWN, GENBA_HOWDY
    ),
    [RAISE] = LAYOUT(
        _______, KC_PGUP, MO(ADJUST),
        KC_HOME, KC_PGDN, KC_END
    ),
    [LOWER] = LAYOUT(
        MO(ADJUST), _______, _______,
        _______,    _______, _______
    ),
    [ADJUST] = LAYOUT(
        _______,        RGB_TOG,        _______,
        RGB_MODE_SNAKE, RGB_MODE_PLAIN, RGB_HUI
    )
};
