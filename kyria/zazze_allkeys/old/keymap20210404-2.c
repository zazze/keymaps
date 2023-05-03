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
    _NAV,
    _NUM,
    _MACROS
};

/* enum custom_keycodes { */
/*     KC_CCCV = SAFE_RANGE */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /*
 * _QWERTY

,-----------------------.                  ,-----------------------.
|Tab| Q | W | E | R | T |                  | Y | U | I | O | P | [{|
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|LSh| A | S | D | F | G |                  | H | J | K | L | ;:| '"|
|---+---+---+---+---+---+-------.  ,---+---+---+---+---+---+---+---|
|LCl| Z | X | C | V | B |Esc|App|  |RAl|Bsp| N | M | ,<| .>| /?|RCl|
`-----------+---+---+---+---+---|  |---+---+---+---+---+-----------'
    (Up|Dwn)|Rsh|GUI|LAl|NUM|Ent|  |Ent|NAV|Spc|RSh|Bsp|(Bsp|Del)
            `-------------------'  `-------------------'
 */
[_QWERTY] = LAYOUT( 
//,- ------+-----+-----+------+-----+------.                                  ,-------+-------+--------+-------+--------+--------.  
    KC_TAB,  KC_Q, KC_W,  KC_E, KC_R,  KC_T,                                      KC_Y,   KC_U,    KC_I,   KC_O,    KC_P, KC_LBRC,
//,--------|-----|-----|------|-----|------|                                  |-------|-------|--------|-------|--------|--------|  
    KC_LSFT, KC_A, KC_S,  KC_D, KC_F,  KC_G,                                      KC_H,   KC_J,    KC_K,   KC_L, KC_SCLN, KC_QUOT,
//,--------|-----|-----|------|-----|------|--------+------. ,-------+--------|-------|-------|--------|-------|--------|--------|   
    KC_LCTL, KC_Z, KC_X,  KC_C, KC_V,  KC_B,  KC_ESC,KC_APP,  KC_RALT, KC_BSPC,   KC_N,   KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RCTL,
//,-------------------------------------------------|------| |-------|--------|-------|-------|--------|-------+--------+--------,  
                    KC_RSFT,KC_LGUI,KC_LALT,MO(_NUM),KC_ENT,   KC_ENT,MO(_NAV), KC_SPC,KC_RSFT, KC_BSPC
//                 |-------+-------+-------+--------+------, `-------+--------|-------|-------|--------|
		    ),

/*
* _NAV: Function keys, navigation
,-----------------------.                  ,-------------------------.
|F1 |F2 |F3 |F4 |F5 |F6 |                  |Hme|PgD|PgU|End| Ins| PSc|
|---+---+---+---+---+---|                  |---+---+---+---+----+----|
|F7 |F8 |F9 |F10|F11|F12|                  |Lft|Dwn| Up|Rgt| ScL| Pse|
|---+---+---+---+---+---+-------.  ,-------+---+---+---+---+----+----|
|Pre|Ply|Nxt|Mut|Vdn|Vup|CsL|   |  |   |   |MLt|Md |MUp|MRt| MB1| MB2|
`-----------+---+---+---+---+---|  |---+---+---+---+---+-------------'
   (PgU|PgD)|   |   |   |   |   |  |   |   |   |   |   |(Bsp|Del)
            `-------------------'  `-------------------'
*/
[_NAV] = LAYOUT(
//|-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+---------+---------|
     KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5, KC_F6,                                    KC_HOME,KC_PGDN,KC_PGUP, KC_END,   KC_INS,  KC_PSCR,
//,-------|-------|-------|-------|-------|-------|                                  |-------+-------+-------+-------+---------+---------|
     KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,                                   KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,  KC_SLCK,  KC_PAUS,
//,-------|-------|-------|-------|-------|-------|-------|-------|  |-------|-------|-------+-------+-------+-------+---------+---------|
   KC_MPRV,KC_MPLY,KC_MNXT,KC_MUTE,KC_VOLD,KC_VOLU,KC_CAPS,_______,   _______,_______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,  KC_BTN1,  KC_BTN2,
//,-------+-------+-------|-------|-------|-------|-------|-------|  |-------|-------|-------|-------|-------|-------+---------+---------|
                           _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
//                        |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
		       ),

/* 
* _NUM: Function keys, Symbols, Numbers
,-----------------------.                  ,-----------------------.
| `~| ! | @ | { | } | & |                  | =+| 7&| 8*| 9(| 0)| ]}|
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   | # | $ | ( | ) | | |                  | * | 4$| 5%| 6^| + | \||
|---+---+---+---+---+---|-------.  ,-------|---+---+---+---+---+---|
|RAl| % | ^ | [ | ] | _ | \||   |  |RGU|Del| ~ | 1!| 2@| 3#| -_|RCl|
`-------------------------------|  |---+---+---+---+---+-----------'
   (PgU|PgD)|   |   |   |   |   |  |PEn|   |   |   |   |(Ctl-Z|Ctl-Y)
            `-------------------'  `-------------------'
*/

[_NUM] = LAYOUT(
//|-------+-------+-------+-------+-------+-------|                                  |--------+-----+-----+-----+-------+-------|
    KC_GRV,KC_EXLM,  KC_AT,KC_LCBR,KC_RCBR,KC_AMPR,                                     KC_EQL, KC_7, KC_8, KC_9,   KC_0,KC_RBRC,
//,-------|-------|-------|-------|-------|-------|                                  |--------+-----+-----+-----+-------+-------|
   _______,KC_HASH, KC_DLR,KC_LPRN,KC_RPRN,KC_PIPE,                                    KC_PAST, KC_4, KC_5, KC_6,KC_PPLS,KC_BSLS,
//,-------|-------|-------|-------|-------|-------|-------|-------|  |-------|-------|--------+-----+-----+-----+-------+-------|
   KC_RALT,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_UNDS,KC_NUBS,_______,   KC_RGUI, KC_DEL,KC_TILDE, KC_1, KC_2, KC_3,KC_MINS,KC_RCTL,
//,-------+-------+-------|-------|-------|-------|-------|-------|  |-------|-------|--------|-----------------+-------+-------|
                           _______,_______,_______,_______,_______,   KC_PENT,_______, _______,_______,_______
//                        |-------+-------+-------+-------+-------|  |-------+-------+--------+-------+-------|
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
    ),


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
void encoder_update_user(uint8_t index, bool clockwise) {
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
	tap_code(KC_PGUP);
      } else {
	tap_code(KC_PGDN);
      }
      break;
    case _NUM:
      // Volume control.
      if (clockwise) {
	tap_code(KC_VOLU);
      } else {
	tap_code(KC_VOLD);
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
    case _MACROS:
      // Volume control.
      if (clockwise) {
	tap_code(KC_VOLU);
      } else {
	tap_code(KC_VOLD);
      }
      break;
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
	tap_code(KC_BSPC);
     } else {
	tap_code(KC_DEL);
      }
      break;
    case _NUM:
      if (clockwise) {
	tap_code16(C(KC_Z));
      } else {
	tap_code16(C(KC_Y));	
      }
      break;
    default:
      if (clockwise) {
	tap_code(KC_BSPC);
      } else {
	tap_code(KC_DEL);
      }
      break;
    }
  }
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

