// Compile and with
// make splitkb/kyria:zazze_bling
// being in the QMK root directory
// Flash
// make splitkb/kyria:zazze_bling:flash
//
// alternative make splitkb/kyria
//
// Commented out the function encoder_update_kb
// in the rev1.c file in the folder
// ~/qmk_firmware/keyboards/splitkb/kyria/rev1
// 
/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

/* uint16_t copy_paste_timer; */

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // can always be here
    // Macros, where | is the cursor
    M_LRBRC,  // [|]
    M_LRCBR,  // {|}
    M_LRPRN,  // (|)
    M_LRABR,  // <|>
    M_DQUOT,  // '|'
    M_DDQUOT, // "|"
    M_DPIPE,  // |||
    // New keys
    /* DBL_TAP,  // Repeat next key */
};


/* enum layers { */
/*     _QWERTY = 0, */
/*     _LOWER, */
/*     _RAISE, */
/*     _ENC1, */
/*     _ENC2, */
/*     _ENC3, */
/*     _ENC4, */
/*     _MACROS */
/* }; */

enum layers {
    _QWERTY = 0,
    _NUM,
    _NAV,
    _NUMPAD,
    _MACROS
};

/* enum custom_keycodes { */
/*     KC_CCCV = SAFE_RANGE */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * _QWERTY
,-----------------------.                  ,-----------------------.
|Tab| Q | W | E | R | T |                  | Y | U | I | O | P | {[|
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|LSh| A | S | D | F | G |                  | H | J | K | L | ;:| '"|
|---+---+---+---+---+---+-------.  ,---+---+---+---+---+---+---+---|
|LCl| Z | X | C | V | B |RAl|App|  |RGU|Del| N | M | ,<| .>|Bsp|RSh|
`-----------+---+---+---+---+---|  |---+---+---+---+---+-----------'
            |Rsh|LAl|LGU|NUM|Esc|  |Ent|NAV|Spc|RAl|Bsp|
            `-------------------'  `-------------------'

,-----------------------.                  ,-----------------------.
|Tab| Q | W | E | R | T |                  | Y | U | I | O | P | Å |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|LSh| A | S | D | F | G |                  | H | J | K | L | Ö | Ä |
|---+---+---+---+---+---+-------.  ,---+---+---+---+---+---+---+---|
|LCl| Z | X | C | V | B |RAl|App|  |RGU|Del| N | M | ,;| .:|Bsp|RSh|
`-----------+---+---+---+---+---|  |---+---+---+---+---+-----------'
            |Rsh|LAl|LGU|NUM|Esc|  |Ent|NAV|Spc|RAl|Bsp|
            `-------------------'  `-------------------'
 */
[_QWERTY] = LAYOUT( 
//,--------+-----+-----+------+-----+------.                                  ,-------+-------+--------+-------+--------+--------.  
     KC_TAB, KC_Q, KC_W,  KC_E, KC_R,  KC_T,                                      KC_Y,   KC_U,    KC_I,   KC_O,    KC_P, KC_LBRC,
//,--------|-----|-----|------|-----|------|                                  |-------|-------|--------|-------|--------|--------|  
    KC_LSFT, KC_A, KC_S,  KC_D, KC_F,  KC_G,                                      KC_H,   KC_J,    KC_K,   KC_L, KC_SCLN, KC_QUOT,
//,--------|-----|-----|------|-----|------|--------+------. ,-------+--------|-------|-------|--------|-------|--------|--------|   
    KC_LCTL, KC_Z, KC_X,  KC_C, KC_V,  KC_B, KC_RALT,KC_APP,  KC_RGUI,  KC_DEL,   KC_N,   KC_M, KC_COMM, KC_DOT, KC_BSPC, KC_RSFT,
//,-------------------------------------------------|------| |-------|--------|-------|-------|--------|-------+--------+--------,  
                    KC_RSFT,KC_LALT,KC_LGUI,MO(_NUM),KC_ESC,   KC_ENT,MO(_NAV), KC_SPC,KC_RALT, KC_BSPC
//                 |-------+-------+-------+--------+------, `-------+--------|-------|-------|--------|
		    ),

/* 
* _NUM: Function keys, Symbols, Numbers
,-----------------------.                  ,-----------------------.
|   | ! | `~| { | } | & |                  | =+| 7&| 8*| 9(| 0)| `~|
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   | # | $ | ( |RAl| | |                  | -_| 4$| 5%| 6^| ]}| \||
|---+---+---+---+---+---|-------.  ,-------|---+---+---+---+---+---|
|   | % | ^ | [ | ] | _ |NUP|   |  |   |Del| \|| 1!| 2@| 3#| /?|RCl|
`-------------------------------|  |---+---+---+---+---+-----------'
   (PgU|PgD)|   |   |   |   |   |  |PEn|   |   |   |   |(Ctl-Z|Ctl-Y)
            `-------------------'  `-------------------'
,-----------------------.                  ,-----------------------.
|   | ! | §±| Å | ^ | & |                  |´` |7/{|8([|9)]|0=}| " |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   | # | € |LSh|RAl| | |                  | +?|4¤$|5%€|6& |¨^~| '*|
|---+---+---+---+---+---|-------.  ,-------|---+---+---+---+---+---|
|   | % | & | å |¨^~| _ |NUP|   |  |   |Del|<>||1! |2"@|3#£| -_|RCL|
`-------------------------------|  |---+---+---+---+---+-----------'
   (PgU|PgD)|   |   |   |   |   |  |PEn|   |   |   |   |(Ctl-Z|Ctl-Y)
            `-------------------'  `-------------------'
*/


[_NUM] = LAYOUT(
//|-------+-------+-------+-------+-------+-------|                                      |--------+-----+-----+-----+-------+-------|
   _______,KC_EXLM, KC_GRV,KC_LCBR,KC_RCBR,KC_AMPR,                                         KC_EQL, KC_7, KC_8, KC_9,   KC_0,  KC_AT,
//,-------|-------|-------|-------|-------|-------|                                      |--------+-----+-----+-----+-------+-------|
   _______,KC_HASH, KC_DLR,KC_LSFT,KC_RALT,KC_PIPE,                                        KC_MINS, KC_4, KC_5, KC_6,KC_RBRC,KC_BSLS,
//,-------|-------|-------|-------|-------|-------|-----------|-------|  |-------|-------|--------+-----+-----+-----+-------+-------|
   _______,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_UNDS,MO(_NUMPAD),_______,   _______, KC_DEL, KC_NUBS,KC_1, KC_2, KC_3,KC_SLSH,KC_RCTL,
//,-------+-------+-------|-------|-------|-------|-----------|-------|  |-------|-------|--------|-----|-----|-----|-------|-------|
                           _______,_______,_______,    _______,_______,   KC_PENT,_______, _______,_______,_______
//                        |-------+-------+-------+-----------+-------|  |-------+-------+--------+-------+-------|
		       ),

/*
* _NAV: Function keys, navigation
,-----------------------.                  ,-----------------------.
|   |F1 |F2 |F3 |F4 |F5 |                  |Hme|PgD|PgU|End|Ins|PSc|
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   |F6 |F7 |F8 |F9 |F10|                  |Lft|Dwn| Up|Rgt|ScL|Pse|
|---+---+---+---+---+---+-------.  ,-------+---+---+---+---+---+---|
|   |F11|F12|Vdn|Vup|CsL|   |   |  |   |   |MLt|Md |MUp|MRt|MB1|MB2|
`-----------+---+---+---+---+---|  |---+---+---+---+---+-----------'
   (PgU|PgD)|   |   |   |   |   |  |   |   |   |   |   |(Bsp|Del)
            `-------------------'  `-------------------'
*/

[_NAV] = LAYOUT(
//|-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+---------+---------|
   _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                                   KC_HOME,KC_PGDN,KC_PGUP, KC_END,   KC_INS,  KC_PSCR,
//,-------|-------|-------|-------|-------|-------|                                  |-------+-------+-------+-------+---------+---------|
   _______,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,                                   KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,  KC_SLCK,  KC_PAUS,
//,-------|-------|-------|-------|-------|-------|-------|-------|  |-------|-------|-------+-------+-------+-------+---------+---------|
   _______, KC_F11, KC_F12,KC_VOLD,KC_VOLU,KC_CAPS,_______,_______,   _______,_______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,  KC_BTN1,  KC_BTN2,
//,-------+-------+-------|-------|-------|-------|-------|-------|  |-------|-------|-------|-------|-------|-------+---------+---------|
                           _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
//                        |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
		       ),

/*
* _NUMPAD: Numpad keys
,-----------------------.                  ,-----------------------.
|   |   |   |   |   |   |                  | = | 7 | 8 | 9 | 0 |   |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   |   |   |   |   |   |                  | - | 4 | 5 | 6 | * |   | 
|---+---+---+---+---+---+-------.  ,-------+---+---+---+---+---+---|
|   |   | . | , |PEN|NLK|   |   |  |   |   | + | 1 | 2 | 3 | / |   |
`-----------+---+---+---+---|---|  |---+---+---+---+---+-----------'
 (VolU|VolD)|   |   |   |   |   |  |   |   |   |   |   |(Bsp|Del)
            `-------------------'  `-------------------'
*/

[_NUMPAD] = LAYOUT(
//|-------+-------+-------+-------+-------+-------|                                  |-------+-----+-----+-----+-------+-------|
   _______,_______,_______,_______,_______,_______,                                   KC_PEQL,KC_P7,KC_P8,KC_P9,  KC_P0,_______,
//,-------|-------|-------|-------|-------|-------|                                  |-------+-----+-----+-----+-------+-------|
   _______,_______,_______,_______,_______,_______,                                   KC_PMNS,KC_P4,KC_P5,KC_P6,KC_PAST,_______,
//,-------|-------|-------|-------|-------|-------|-------|-------|  |-------|-------|-------+-----+-----+-----+-------+-------|
   _______,_______,KC_PDOT,KC_COMM,KC_PENT,KC_NLCK,_______,_______,   _______,_______,KC_PPLS,KC_P1,KC_P2,KC_P3,KC_PSLS,_______,
//,-------+-------+-------|-------|-------|-------|-------|-------|  |-------|-------|-------|-----------------+-------+-------|
                           _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
//                        |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
		   ),

/*
* _MACROS: Macros, RGB Underglow
,-----------------------.                  ,-----------------------.
|   |   |   | {}| <>|   |                  |EXE|HLP|MEN|SEL|STP|AGN|
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   |   |   | ()| ''| |||                  |TOG|SAI|HUI|VAI|MOD|   |
|---+---+---+---+---+---+-------.  ,-------+---+---+---+---+---+---|
|   |   |   | []| ""|   |   |   |  |   |   |   |SAD|HUD|VAD|RMD|   |
`-----------+---+---+---+---|---|  |---+---+---+---+---+-----------'
 (VolU|VolD)|   |   |   |   |   |  |   |   |   |   |   |(Bsp|Del)
            `-------------------'  `-------------------'
*/
[_MACROS] = LAYOUT(
//|-------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+----------+--------+---------|
   _______, _______, _______, M_LRCBR, M_LRABR, _______,                                        KC_EXEC, KC_HELP, KC_MENU, KC_SELECT, KC_STOP, KC_AGAIN,
//|-------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+----------+--------+---------|
   _______, _______, _______, M_LRPRN, M_DQUOT, M_DPIPE,                                        RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,   RGB_MOD,  _______,
//|-------+--------+--------+--------+--------+--------|---------|--------|  |-------+--------+--------+--------+--------+----------+--------+---------|
   _______, _______, _______, M_LRBRC,M_DDQUOT, _______, _______, _______,    _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD,  RGB_RMOD,  _______,
//|-------+--------+--------+--------+--------+--------|---------|--------|  |-------+--------+--------+--------+--------+----------+--------+---------|
                              _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
//                          |--------+--------+--------+--------+---------|  |-------+--------+--------+--------+--------|
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case M_LRPRN:
                SEND_STRING("()" SS_TAP(X_LEFT));
                return false;
            case M_LRCBR:
                SEND_STRING("{}" SS_TAP(X_LEFT));
                return false;
            case M_LRBRC:
                SEND_STRING("[]" SS_TAP(X_LEFT));
                return false;
            case M_LRABR:
                SEND_STRING("<>" SS_TAP(X_LEFT));
                return false;
            case M_DQUOT:
                SEND_STRING("''" SS_TAP(X_LEFT));
                return false;
            case M_DDQUOT:
                SEND_STRING("\"\"" SS_TAP(X_LEFT));
                return false;
            case M_DPIPE:
                SEND_STRING("||" SS_TAP(X_LEFT));
                return false;
        }

    }
    
    return true;
}

/* #ifdef ENCODER_ENABLE */
/* void encoder_update_user(uint8_t index, bool clockwise) { */
/*   // Left encoder */
/*   if (index == 0) { */
/*     switch (biton32(layer_state)) { */
/*     case _QWERTY: */
/*       if (clockwise) { */
/* 	tap_code(KC_PGUP); */
/*       } else { */
/* 	tap_code(KC_PGDN); */
/*       } */
/*       break; */
/*     case _NAV: */
/*       // Up and down arrows */
/*       if (clockwise) { */
/* 	tap_code(KC_UP); */
/*       } else { */
/* 	tap_code(KC_DOWN); */
/*       } */
/*       break; */
/*     case _ENC1: */
/*       // Up and down arrows */
/*       if (clockwise) { */
/* 	tap_code(KC_UP); */
/* 	tap_code(KC_UP); */
/* 	// untap_code(KC_UP); */
/*       } else { */
/* 	tap_code(KC_DOWN); */
/* 	tap_code(KC_DOWN); */
/* 	// untap_code(KC_DOWN); */
/*       } */
/*       break; */
/*     case _ENC2: */
/*       // Up and down arrows */
/*       if (clockwise) { */
/* 	tap_code(KC_UP); */
/* 	tap_code(KC_UP); */
/* 	tap_code(KC_UP); */
/* 	// untap_code(KC_UP); */
/*       } else { */
/* 	tap_code(KC_DOWN); */
/* 	tap_code(KC_DOWN); */
/* 	tap_code(KC_DOWN); */
/* 	// untap_code(KC_DOWN); */
/*       } */
/*       break; */
/*     case _ENC3: */
/*       // Up and down arrows */
/*       if (clockwise) { */
/* 	tap_code(KC_UP); */
/* 	tap_code(KC_UP); */
/* 	tap_code(KC_UP); */
/* 	tap_code(KC_UP); */
/* 	// untap_code(KC_UP); */
/*       } else { */
/* 	tap_code(KC_DOWN); */
/* 	tap_code(KC_DOWN); */
/* 	tap_code(KC_DOWN); */
/* 	tap_code(KC_DOWN); */
/* 	// untap_code(KC_DOWN); */
/*       } */
/*       break; */
/*     case _ENC4: */
/*       // Up and down arrows */
/*       if (clockwise) { */
/* 	tap_code(KC_UP); */
/* 	tap_code(KC_UP); */
/* 	tap_code(KC_UP); */
/* 	tap_code(KC_UP); */
/* 	tap_code(KC_UP); */
/* 	// untap_code(KC_UP); */
/*       } else { */
/* 	tap_code(KC_DOWN); */
/* 	tap_code(KC_DOWN); */
/* 	tap_code(KC_DOWN); */
/* 	tap_code(KC_DOWN); */
/* 	tap_code(KC_DOWN); */
/* 	// untap_code(KC_DOWN); */
/*       } */
/*       break; */
/*     case _MACROS: */
/*       // Volume control. */
/*       if (clockwise) { */
/* 	tap_code(KC_VOLU); */
/*       } else { */
/* 	tap_code(KC_VOLD); */
/*       } */
/*       break; */
/*     default: */
/*       if (clockwise) { */
/* 	tap_code(KC_PGUP); */
/*       } else { */
/* 	tap_code(KC_PGDN); */
/*       } */
/*       break; */
/*     } */
/*     // Right encoder */
/*   } else if (index == 1) { */
/*     switch (biton32(layer_state)) { */
/*     case _NUM: */
/*       if (clockwise) { */
/* 	tap_code16(C(KC_Z)); */
/*       } else { */
/* 	tap_code16(C(KC_Y));	 */
/*       } */
/*       break; */
/*     case _QWERTY: */
/*       if (clockwise) { */
/* 	tap_code(KC_BSPC); */
/*      } else { */
/* 	tap_code(KC_DEL); */
/*       } */
/*       break; */
/*     default: */
/*       if (clockwise) { */
/* 	tap_code(KC_BSPC); */
/*       } else { */
/* 	tap_code(KC_DEL); */
/*       } */
/*       break; */
/*     } */
/*   } */
/* } */
/* #endif */

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  // Left encoder
  if (index == 0) {
    switch (biton32(layer_state)) {
    case _QWERTY:
      // Up and down arrows
      if (clockwise) {
	tap_code(KC_UP);
      } else {
	tap_code(KC_DOWN);
      }
      break;
    case _NAV:
      if (clockwise) {
	tap_code(KC_LEFT);
      } else {
	tap_code(KC_RIGHT);
      }
      break;
    case _NUM:
      // Volume control.
      if (clockwise) {
	tap_code(KC_PGUP);
      } else {
	tap_code(KC_PGDOWN);
      }
      break;
    /* case _ENC1: */
    /*   // Up and down arrows */
    /*   if (clockwise) { */
    /* 	tap_code(KC_UP); */
    /* 	/\* tap_code(KC_UP); *\/ */
    /* 	// untap_code(KC_UP); */
    /*   } else { */
    /* 	tap_code(KC_DOWN); */
    /* 	/\* tap_code(KC_DOWN); *\/ */
    /* 	// untap_code(KC_DOWN); */
    /*   } */
    /*   break; */
    /* case _ENC2: */
    /*   // Up and down arrows */
    /*   if (clockwise) { */
    /* 	tap_code(KC_UP); */
    /* 	/\* tap_code(KC_UP); *\/ */
    /* 	/\* tap_code(KC_UP); *\/ */
    /* 	// untap_code(KC_UP); */
    /*   } else { */
    /* 	tap_code(KC_DOWN); */
    /* 	tap_code(KC_DOWN); */
    /* 	tap_code(KC_DOWN); */
    /* 	// untap_code(KC_DOWN); */
    /*   } */
    /*   break; */
    /* case _ENC3: */
    /*   // Up and down arrows */
    /*   if (clockwise) { */
    /* 	tap_code(KC_UP); */
    /* 	/\* tap_code(KC_UP); *\/ */
    /* 	/\* tap_code(KC_UP); *\/ */
    /* 	/\* tap_code(KC_UP); *\/ */
    /* 	// untap_code(KC_UP); */
    /*   } else { */
    /* 	tap_code(KC_DOWN); */
    /* 	/\* tap_code(KC_DOWN); *\/ */
    /* 	/\* tap_code(KC_DOWN); *\/ */
    /* 	/\* tap_code(KC_DOWN); *\/ */
    /* 	// untap_code(KC_DOWN); */
    /*   } */
    /*   break; */
    /* case _ENC4: */
    /*   // Up and down arrows */
    /*   if (clockwise) { */
    /* 	tap_code(KC_UP); */
    /* 	/\* tap_code(KC_UP); *\/ */
    /* 	/\* tap_code(KC_UP); *\/ */
    /* 	/\* tap_code(KC_UP); *\/ */
    /* 	/\* tap_code(KC_UP); *\/ */
    /* 	// untap_code(KC_UP); */
    /*   } else { */
    /* 	tap_code(KC_DOWN); */
    /* 	/\* tap_code(KC_DOWN); *\/ */
    /* 	/\* tap_code(KC_DOWN); *\/ */
    /* 	/\* tap_code(KC_DOWN); *\/ */
    /* 	/\* tap_code(KC_DOWN); *\/ */
    /* 	// untap_code(KC_DOWN); */
    /*   } */
    /*   break; */
    /* case _MACROS: */
    /*   // Volume control. */
    /*   if (clockwise) { */
    /* 	tap_code(KC_VOLU); */
    /*   } else { */
    /* 	tap_code(KC_VOLD); */
    /*   } */
    /*   break; */
    default:
      if (clockwise) {
	tap_code(KC_PGUP);
      } else {
	tap_code(KC_PGDN);
      }
      break;
    }
    // Right encoder
  } else if (index == 1) {
    switch (biton32(layer_state)) {
    case _QWERTY:
      if (clockwise) {
	tap_code(KC_WH_D);
     } else {
	tap_code(KC_WH_U);
      }
      break;
    case _NUM:
      if (clockwise) {
	tap_code(KC_BSPC);
      } else {
	tap_code(KC_DEL);
      }
      break;
    case _NAV:
      if (clockwise) {
	tap_code(KC_VOLD);
      } else {
	tap_code(KC_VOLU);
      }
      break;
    default:
      if (clockwise) {
	tap_code(KC_WH_D);
     } else {
	tap_code(KC_WH_U);
      }
      break;
    }
  }
  return true;
}
#endif

/* // Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore! */
/* const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*     {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6 */
/*     {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12 */
/* ); */
/* // Light LEDs 9 & 10 in cyan when keyboard layer 1 is active */
/* const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*     {9, 2, HSV_CYAN} */
/* ); */
/* // Light LEDs 11 & 12 in purple when keyboard layer 2 is active */
/* const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*     {11, 2, HSV_PURPLE} */
/* ); */
/* // Light LEDs 13 & 14 in green when keyboard layer 3 is active */
/* const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*     {13, 2, HSV_GREEN} */
/* ); */

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUM, _NAV, _MACROS);
}

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     switch (get_highest_layer(state)) { */
/*     case _NUM: */
/*         rgblight_setrgb (0x00,  0x00, 0xF0); */
/*         break; */
/*     case _NAV: */
/*         rgblight_setrgb (0xF0,  0x00, 0x00); */
/*         break; */
/*     case _MACROS: */
/*         rgblight_setrgb (0x00,  0x00, 0x00); */
/*         break; */
/*     case _ENC1: */
/*         rgblight_setrgb (0xF0,  0x40, 0x40); */
/*         break; */
/*     case _ENC2: */
/*         rgblight_setrgb (0xF0,  0x80, 0x80); */
/*         break; */
/*     case _ENC3: */
/*         rgblight_setrgb (0xF0,  0xC0, 0xC0); */
/*         break; */
/*     case _ENC4: */
/*         rgblight_setrgb (0xF0,  0xF0, 0x00); */
/*         break; */
/*     default: //  for any other layers, or the default layer */
/*         rgblight_setrgb (0xC0,  0xC0, 0xC0); */
/*         break; */
/*     } */
/*   return state; */
/* } */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

/* static void render_kyria_logo(void) { */
/*     static const char PROGMEM kyria_logo[] = { */
/*         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*         0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*         0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*         0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0, */
/*         0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0, */
/*         0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*         0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, */
/*         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 */
/*     }; */
/*     oled_write_raw_P(kyria_logo, sizeof(kyria_logo)); */
/* } */

/* static void render_qmk_logo(void) { */
/*   static const char PROGMEM qmk_logo[] = { */
/*     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94, */
/*     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4, */
/*     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0}; */

/*   oled_write_P(qmk_logo, false); */
/* } */

static void render_status(void) {
    // QMK Logo and version information
    /* render_qmk_logo(); */
    oled_write_P(PSTR("       Kyria rev1.3\n\n"), false);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NUMERIC\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAVIGATION\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("NUMPAD\n"), false);
            break;
        case _MACROS:
            oled_write_P(PSTR("MACROS"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined!!!\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        /* render_kyria_logo(); */
          /* render_qmk_logo(); */
	  oled_write_P(PSTR("       QMK Firmware\n\n"), false);

  /* render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc) */
    }
}
#endif

