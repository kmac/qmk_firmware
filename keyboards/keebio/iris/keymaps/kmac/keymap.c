#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

/* My defines for fitting longer keycodes into the ascii art: */
#define CTLESC LCTL_T(KC_ESC)
#define ADJEQU LT(ADJUST,KC_EQL)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};


//````
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   * Ideas:
   * Possibly change the KC_EQL on the right thumb to LT(ADJUST,KC_EQL)
   * */

  // QWERTY
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //│  ~ `   │   1    │   2    │   3    │    4   │    5   │                          │    6   │   7    │   8    │   9    │   0    │   BS   │
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //│  TAB   │   Q    │   W    │   E    │    R   │    T   │                          │    Y   │   U    │   I    │   O    │   P    │  | \   |
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //│ESC/CTRL│   A    │   S    │   D    │    F   │    G   │                          │    H   │   J    │   K    │   L    │  : ;   │  " '   │
     CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //│ SHIFT  │   Z    │   X    │   C    │    V   │    B   │  + =   │        │  _ -   │    N   │   M    │   < ,  │  > .   │  ? /   │ENT/SHFT│
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_EQL,           KC_MINS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                               │ SUPER   │ LOWER │ ENTER  │                 │ SPACE  │  RAISE │  ALT   │
                                    KC_LGUI, LOWER,   KC_ENT,                    KC_SPC,  RAISE,   KC_RALT
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  //

  // LOWER - Symbols
  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //│        │    !   │    @   │   #    │   $    │    %   │                          │   ^    │   &    │   *    │   (    │   )    │  _ -   │
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //│        │        │   {    │    }   │    [   │   ]    │                          │   [    │   ]    │   {    │   }    │   |    │   _    │
     _______, _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC,                            KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PIPE, KC_UNDS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //│        │        │        │        │    (   │   )    │                          │  + =   │   _    │        │        │        │        │
     _______, _______, _______, _______, KC_LPRN, KC_RPRN,                            KC_EQL,  KC_UNDS, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //│        │ Reset  │        │        │        │        │                          │   +    │  _ -   │        │        │ Reset  │        │
     _______, RESET,   _______, _______, _______, _______, _______,          _______, KC_PLUS, KC_MINS, _______, _______, RESET,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                               │        │        │        │                 │        │        │        │
                                    _______, _______, _______,                   _______, _______, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  //

  // RAISE - Navigation
  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //│        │   F1   │   F2   │   F3   │    F4  │   F5   │                          │   F6   │   F7   │   F8   │   F9   │   F10  │   F11  │
     _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //│        │  HOME  │   UP   │  END   │  PGUP  │        │                          │  HOME  │  PGUP  │  PGDN  │  END   │        │   F12  │
     _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,                            KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //│        │  LEFT  │  DOWN  │  RIGHT │  PGDN  │        │                          │  LEFT  │  DOWN  │   UP   │  RIGHT │        │  PGUP  │
     _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,                            KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT, _______, KC_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //│        │ Reset  │        │        │        │  INS   │  DEL                DEL  │   INS  │        │        │        │        │  PGDN  │
     _______, RESET,   _______, _______, _______, KC_INS,  KC_DEL,           KC_DEL,  KC_INS,  _______, _______, _______, _______, KC_PGDN,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                               │        │        │        │                 │        │        │        │
                                    _______, _______, _______,                   _______,  _______, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  //

  // ADJUST - Keyboard
  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //│        │        │        │        │        │        │                          │        │        │        │        │        │        │
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //│ Toggle │        │ Hue +  │ Sat +  │ Vib +  │        │                          │        │        │        │        │        │        │
     RGB_TOG, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //│ Toggle │        │ Hue -  │ Sat +  │ Vib +  │        │                          │        │        │        │        │        │        │
     RGB_MOD, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //│        │ Reset  │        │        │        │        │                          │        │        │        │        │ Reset  │        │
     _______, RESET,   _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, RESET,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                               │        │        │        │                 │        │        │        │
                                    _______, _______, _______,                   _______, _______, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};
//````

/*
See https://docs.qmk.fm/#/custom_quantum_functions?id=programming-the-behavior-of-any-keycode

When you want to override the behavior of an existing key, or define the
behavior for a new key, you should use the process_record_kb() and
process_record_user() functions.

Called by QMK during key processing before the actual key event is handled. If
these functions return true QMK will process the keycodes as usual.  If these
functions return false QMK will skip the normal key handling, and it will be up
to you to send any key up or down events that are required.

These function are called every time a key is pressed or released.
*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
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

