/* Copyright 2021 Stian Meyer
 * Modified from layout provided by Alex Daigre
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
#include "muse.h"
#include "keymap_norwegian.h"
#define USB_POLLING_INTERVAL_MS 4
#define QMK_KEYS_PER_SCAN 4

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
  ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | s-Esc|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  Bksp|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ø  |  Æ   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |   ?  |  Alt | Lower|    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    NO_ARNG,  \
  KC_CAPS_LOCK,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NO_OSTR,  NO_AE, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  NO_MINS, KC_ENT,  \
  KC_LCTL, KC_LGUI, NO_QUES, KC_LALT,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   |  |   F1 |   F2 |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9 |  F10  |  '   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   Å  |  up  |  Æ   |  -   |  +   |      |      |      |   -  |  /   |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps | Left | down | Right|  *   |  \   |      |      |      |   [  |   ]  |Prints|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |rshift|  <   |   >  |  ,   |  .   |  /   |  =   |      | Play | Stop | Mute | File |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Sysreq|Enter |Lower |      |    space    |Raise | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  NO_PIPE,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  NO_QUOT,  \
  KC_TAB, NO_ARNG, KC_UP, NO_AE, NO_MINS, NO_PLUS, _______, _______, _______, NO_MINS, NO_SLSH, NO_BSLS, \
  KC_CAPS_LOCK, KC_LEFT, KC_DOWN, KC_RGHT, NO_ASTR, NO_BSLS, _______, _______, _______, NO_LCBR, NO_RBRC, KC_PSCR, \
  KC_LSFT, NO_LABK, NO_RABK, KC_COMM, KC_DOT, NO_SLSH, NO_EQL, _______, KC_MPLY, KC_MSTP, KC_MUTE, KC_MYCM, \
  KC_LCTL, KC_SYRQ, KC_ENT, _______, _______, _______, KC_SPC, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  @   |  %   |   $  |   (  |   )  |   [  |   ]  |  {   |   }  |  ~   |  &   | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | tab  |  7   |  8   |  9   |      |      |      |      |      |   +  |  -   | Ins  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |  4   |  5   |  6   |      |      |      |      |      |   *  |  =   |Prints|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Rshift|  1   |  2   |  3   |      |      |      |      |      |   ^  |  |   | Menu |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RCtrl | RAlt | RGui |      |      |             |      | Home | pgdwn| pgup |  end |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  NO_AT, NO_PERC, NO_DLR, NO_LPRN, NO_RPRN, NO_LBRC, NO_RBRC, NO_LCBR, NO_RCBR, NO_TILD, NO_AMPR, KC_DELETE, \
  KC_TAB, KC_7, KC_8, KC_9, _______, _______, _______, _______, _______, NO_PLUS, NO_MINS, KC_INS, \
  KC_CAPS_LOCK, KC_4, KC_5, KC_6, _______, _______, _______, _______, _______, NO_ASTR, NO_EQL, KC_PSCR, \
  KC_RSFT, KC_1, KC_2, KC_3, _______, _______, _______, _______, _______, NO_CIRC, NO_PIPE, KC_MENU, \
  KC_RCTL, KC_RALT, KC_RGUI, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN,  KC_PGUP,  KC_END  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      | Play | Stop |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Light|      |      |      |      |             |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   _______,   _______, _______, _______, _______, _______, _______,_______, _______, _______,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  BACKLIT, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
)



};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
       case ADJUST:
          if (record->event.pressed) {
            layer_on(_RAISE);
            layer_on(_LOWER);
            layer_on(_ADJUST);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_ADJUST);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
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
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

/*bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}
*/

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
