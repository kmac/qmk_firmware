#include QMK_KEYBOARD_H

/*
 * Note: double-slash comments are assumed to be markdown-formatted text
 *       (filtered by print-map.sh)
 */

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

/* My defines for fitting longer keycodes into the ascii art: */
#define CTLESC LCTL_T(KC_ESC)
#define ADJEQL LT(_ADJUST,KC_EQL)
#define ADJMINS LT(_ADJUST,KC_MINS)

/*
#define USE_RGB_LAYERS
*/


//````
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   * Ideas:
   * Possibly change the KC_EQL on the right thumb to LT(ADJUST,KC_EQL)
   */

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
  //│ SHIFT  │   Z    │   X    │   C    │    V   │    B   │ADJUST/=│        │  _ -   │    N   │   M    │   < ,  │  > .   │  ? /   │ENT/SHFT│
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ADJEQL,           KC_MINS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, /*KC_RSFT*/ KC_SFTENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                               │ SUPER  │ LOWER  │ ENTER  │                 │ SPACE  │  RAISE │  ALT   │
                                    KC_LGUI,MO(_LOWER),KC_ENT,                   KC_SPC, TT(_RAISE),KC_RALT
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
  //│        │        │        │        │    (   │   )    │                          │   +    │   =    │        │        │        │        │
     _______, _______, _______, _______, KC_LPRN, KC_RPRN,                            KC_PLUS,  KC_EQL, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //│        │ Reset  │        │        │        │        │        │        │  DEL   │   -    │   _    │        │        │ Reset  │        │
     _______, RESET,   _______, _______, _______, _______, _______,          KC_DEL,  KC_MINS,  KC_UNDS, _______, _______, RESET,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                               │        │        │        │                 │        │        │        │
                                    _______, _______, _______,                   _______, _______, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  //

  // RAISE - Navigation
  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //│        │   F1   │   F2   │   F3   │    F4  │   F5   │                          │   F6   │   F7   │   F8   │   F9   │   F10  │   F12  │
     _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //│        │        │  HOME  │   UP   │  END   │  PGUP  │                          │  HOME  │  PGUP  │  PGDN  │  END   │   F11  │  PGUP  │
     _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                            KC_HOME, KC_PGUP, KC_PGDN, KC_END,   KC_F11,  KC_PGUP,
  //├────────┼────────┤────────┼────────┼────────┼────────┼                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //│        │        │  LEFT  │  DOWN  │  RIGHT │  PGDN  │                          │  LEFT  │  DOWN  │   UP   │  RIGHT │        │  PGDN  │
     _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                            KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT, _______, KC_PGDN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //│        │ Reset  │        │        │        │        │        │        │  DEL   │  INS   │        │        │        │ Reset  │        │
     _______, RESET,   _______, _______, _______, _______, _______,          KC_DEL,  KC_INS,  _______, _______, _______,  RESET,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                               │        │        │        │                 │        │        │        │
                                    _______, _______, _______,                   _______,  _______, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  //

  // ADJUST - Keyboard
  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //│ Plain  │Breathe │Rainbow │ Swirl  │ Snake  │ Knight │                          │ Xmas   │Gradient│  Test  │        │        │        │
     RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SW,RGB_M_K,                            RGB_M_X, RGB_M_G, RGB_M_T, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //│ Toggle │        │ Hue +  │ Sat +  │Bright +│        │                          │        │        │        │        │        │        │
     RGB_TOG, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //│  Mode  │        │ Hue -  │ Sat -  │Bright -│        │                          │        │        │        │        │        │        │
     RGB_MOD, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //│        │ Reset  │        │        │        │        │        │        │        │        │        │        │        │ Reset  │        │
     _______, RESET,   _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, RESET,   _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //                               │        │        │        │                 │        │        │        │
                                    _______, _______, _______,                   _______, _______, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};
//````

#ifdef USE_RGB_LAYERS

void keyboard_post_init_user(void) {
	rgblight_enable_noeeprom();
	rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
	rgblight_disable_noeeprom();
};


/* The current problem with this is that it breaks the TT functionality: */
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _RAISE:
      rgblight_enable_noeeprom();
      rgblight_sethsv_noeeprom(HSV_PURPLE);
      break;
    default:
      rgblight_disable_noeeprom();
      break;
    }
  return state;
}
#endif

