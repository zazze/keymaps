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


enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _MACROS,
    _ADJUST
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
|LCl| Z | X | C | V | B |GUI|Esc|  |RAl|Bsp| N | M | ,<| .>| /?|RCl|
`-----------+---+---+---+---+---|  |---+---+---+---+---+-----------'
            |Lsh|LAl|Spc|LOW|Ent|  |Ent|RSE|RSh|MAC|App|
            `-------------------'  `-------------------'
 */
   [_QWERTY] = LAYOUT( 
//,- ------+-----+-----+------+-----+------.                                     ,-------+-----------+--------+--------+--------+--------.  
    KC_TAB,  KC_Q, KC_W,  KC_E, KC_R,  KC_T,                                         KC_Y,       KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
//,--------|-----|-----|------|-----|------|                                     |-------|-----------|--------|--------|--------|--------|  
    KC_LSFT, KC_A, KC_S,  KC_D, KC_F,  KC_G,                                         KC_H,       KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
//,--------|-----|-----|------|-----|------|--------+-------. ,-------|----------|-------|-----------|--------|--------|--------|--------|   
    KC_LCTL, KC_Z, KC_X,  KC_C, KC_V,  KC_B, KC_LGUI, KC_ESC,  KC_RALT,   KC_BSPC,   KC_N,       KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,
//,-------------------------------------------------|-------| |-------|----------|-------|-----------|--------|--------+--------+--------,  
                    KC_LSFT,KC_LALT,KC_SPC,MO(_LOWER),KC_ENT,   KC_ENT,MO(_RAISE),KC_RSFT,MO(_MACROS), KC_APP
//                 |-------+-------+------+---------+-------, `-------+----------|-------|-----------|--------|
		    ),

/* 
* _LOWER: Function keys, Symbols, Numbers
,-----------------------.                  ,-----------------------.
| ~ | ! | @ | { | } | & |                  | / | 7 | 8 | 9 | - | = |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
| ` | # | $ | ( | ) | | |                  | * | 4 | 5 | 6 | + | . |
|---+---+---+---+---+---|-------.  ,-------|---+---+---+---+---+---|
| \ | % | ^ | [ | ] | _ |   |   |  |   |Del| 0 | 1 | 2 | 3 | = |   |
`-------------------------------|  |---+---+---+---+---+-----------'
            |   |   |   |   |   |  |PEn|   |   |   |   |
            `-------------------'  `-------------------'
*/

[_LOWER] = LAYOUT(
//|-------+-------+-------+-------+-------+-------|                                  |-------+-----+-----+-----+-------+-------|
   KC_TILD,KC_EXLM,  KC_AT,KC_LCBR,KC_RCBR,KC_AMPR,                                   KC_PSLS,KC_P7,KC_P8,KC_P9,KC_PMNS, KC_EQL,
//,-------|-------|-------|-------|-------|-------|                                  |-------+-----+-----+-----+-------+-------|
    KC_GRV,KC_HASH, KC_DLR,KC_LPRN,KC_RPRN,KC_PIPE,                                   KC_PAST,KC_P4,KC_P5,KC_P6,KC_PPLS,KC_PDOT,
//,-------|-------|-------|-------|-------|-------|-------|-------|  |-------|-------|-------+-----+-----+-----+-------+-------|
   KC_BSLS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_UNDS,_______,_______,   _______, KC_DEL,  KC_P0,KC_P1,KC_P2,KC_P3,KC_PEQL,_______,
//,-------+-------+-------|-------|-------|-------|-------|-------|  |-------|-------|-------|-----------------+-------+-------|
                           _______,_______,_______,_______,_______,   KC_PENT,_______,_______,_______,_______
//                        |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
		       ),

/*
* _RAISE: Function keys, navigation
,-----------------------.                  ,-----------------------.
|F1 |F2 |F3 |F4 |F5 |F6 |                  |Hme|PgD|PgU|End|Ins|PSc|
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|F7 |F8 |F9 |F10|F11|F12|                  |Lft|Dwn| Up|Rgt|ScL|Pse|
|---+---+---+---+---+---+-------.  ,-------+---+---+---+---+---+---|
|Pre|Ply|Nxt|Mut|Vdn|Vup|CsL|   |  |   |   |MLt|Md |MUp|MRt|MB1|MB2|
`-----------+---+---+---+---+---|  |---+---+---+---+---+-----------'
            |   |   |   |   |   |  |   |   |   |   |   |
            `-------------------'  `-------------------'
*/
[_RAISE] = LAYOUT(
//|-------+-------+-------+-------+-------+-------|                                  |-------+-------+-------+-------+-------+-------|
     KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5, KC_F6,                                    KC_HOME,KC_PGDN,KC_PGUP, KC_END, KC_INS,KC_PSCR,
//,-------|-------|-------|-------|-------|-------|                                  |-------+-------+-------+-------+-------+-------|
     KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,                                   KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,KC_SLCK,KC_PAUS,
//,-------|-------|-------|-------|-------|-------|-------|-------|  |-------|-------|-------+-------+-------+-------+-------+-------|
   KC_MPRV,KC_MPLY,KC_MNXT,KC_MUTE,KC_VOLD,KC_VOLU,KC_CAPS,_______,   _______,_______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,KC_BTN1,KC_BTN2,
//,-------+-------+-------|-------|-------|-------|-------|-------|  |-------|-------|-------|-------|-------|-------+-------+-------|
                           _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
//                        |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
		       ),

/*
* _MACROS
,-----------------------.                  ,-----------------------.
|   |   |   | {}| <>|   |                  |   |   |   |   |   |   |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   |   |   | ()| ''| |||                  |   |   |   |   |   |   |
|---+---+---+---+---+---+-------.  ,-------+---+---+---+---+---+---|
|   |   |   | []| ""|   |   |   |  |   |   |   |   |   |   |   |   |
`-----------+---+---+---+---|---|  |---+---+---+---+---+-----------'
            |   |   |   |   |   |  |   |   |   |   |   |
            `-------------------'  `-------------------'
*/
    [_MACROS] = LAYOUT(
      _______, _______, _______, M_LRCBR, M_LRABR, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, M_LRPRN, M_DQUOT, M_DPIPE,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, M_LRBRC, M_DDQUOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
* _ADJUST: Underglow
,-----------------------.                  ,-----------------------.
|EXE|HLP|MEN|SEL|STP|AGN|                  |F13|F14|F15|F16|F17|F18|
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   |TOG|SAI|HUI|VAI|MOD|                  |F19|F20|F21|F22|F23|F24|
|---+---+---+---+---+---+-------.  ,-------+---+---+---+---+---+---|
|   |   |SAD|HUD|VAD|RMD|   |   |  |   |   |   |   |   |   |   |   |
`-----------+---+---+---+---+---|  |---+---+---+---+---+-----------'
            |   |   |   |   |   |  |   |   |   |   |   |
            `-------------------'  `-------------------'
*/
    [_ADJUST] = LAYOUT(
      KC_EXEC, KC_HELP, KC_MENU, KC_SELECT, KC_STOP, KC_AGAIN,                                      KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,
      _______, RGB_TOG, RGB_SAI,   RGB_HUI, RGB_VAI,  RGB_MOD,                                      KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
      _______, _______, RGB_SAD,   RGB_HUD, RGB_VAD, RGB_RMOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______
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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    switch (biton32(layer_state)) {
    case _RAISE:
      if (clockwise) {
	tap_code(KC_PGUP);
      } else {
	tap_code(KC_PGDN);
      }
      break;
    case _QWERTY:
      // Up and down arrows
      if (clockwise) {
	tap_code(KC_UP);
      } else {
	tap_code(KC_DOWN);
      }
      break;
    default:
      // Up and down arrows
      if (clockwise) {
	tap_code(KC_UP);
      } else {
	tap_code(KC_DOWN);
      }
      break;
    }
  } else if (index == 1) {
    switch (biton32(layer_state)) {
    case _LOWER:
      if (clockwise) {
	tap_code16(C(KC_Z));
      } else {
	tap_code16(C(KC_Y));	
      }
      break;
    case _QWERTY:
      if (clockwise) {
	tap_code(KC_BSPC);
     } else {
	tap_code(KC_DEL);
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
