// Compile and flash with
// make splitkb/kyria/rev1:zazze_allkeys:flash
// being in the QMK root directory

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
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

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
    _NUM,
    _NAV,
    _NUMPAD,
    _MACROS
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK_DH)
#define DVORAK   DF(_DVORAK)

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * _QWERTY
EN-WIN
,-----------------------.                  ,-----------------------.
|Tab| Q | W | E | R | T |                  | Y | U | I | O | P | {[|
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|LSh| A | S | D | F | G |                  | H | J | K | L | ;:| '"|
|---+---+---+---+---+---+-------.  ,---+---+---+---+---+---+---+---|
|LCl| Z | X | C | V | B |CsL|RAl|  |RGU|Del| N | M | ,<| .>|Bsp|RSh|
`-----------+---+---+---+---+---|  |---+---+---+---+---+-----------'
            |Rsh|LAl|LGU|NUM|Esc|  |Ent|NAV|Spc|RAl|Bsp|
            `-------------------'  `-------------------'
SE-WIN SE-MAC
,-----------------------.                  ,-----------------------.
|Tab| Q | W | E | R | T |                  | Y | U | I | O | P | Å |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|LSh| A | S | D | F | G |                  | H | J | K | L | Ö | Ä |
|---+---+---+---+---+---+-------.  ,---+---+---+---+---+---+---+---|
|LCl| Z | X | C | V | B |CsL|RAl|  |RGU|Del| N | M | ,;| .:|Bsp|RSh|
`-----------+---+---+---+---+---|  |---+---+---+---+---+-----------'
            |Rsh|LAl|LGU|NUM|Esc|  |Ent|NAV|Spc|RAl|Bsp|
            `-------------------'  `-------------------'
 */
[_QWERTY] = LAYOUT( 
     KC_TAB, KC_Q, KC_W,  KC_E, KC_R,  KC_T,                                       KC_Y,   KC_U,    KC_I,   KC_O,    KC_P, KC_LBRC,
    KC_LSFT, KC_A, KC_S,  KC_D, KC_F,  KC_G,                                       KC_H,   KC_J,    KC_K,   KC_L, KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z, KC_X,  KC_C, KC_V,  KC_B, KC_CAPS,KC_RALT,  KC_RGUI,  KC_DEL,   KC_N,   KC_M, KC_COMM, KC_DOT, KC_BSPC, KC_RSFT,
                    KC_RSFT,KC_LALT,KC_LGUI,MO(_NUM),KC_ESC,   KC_ENT,MO(_NAV), KC_SPC,KC_RALT, KC_BSPC
		    ),
/* 
* _NUM: Function keys, Symbols, Numbers
EN-MAC
,-----------------------.                  ,-----------------------.
|   | ! | + | `~| } | & |                  | =+| 7&| 8*| 9(| 0)| * |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   | # | $ |LSh|RAl| | |                  | -_| 4$| 5%| 6^| ]}| \||
|---+---+---+---+---+---|-------.  ,-------|---+---+---+---+---+---|
|   | % | ^ | ~ | ] | _ |NUP|   |  |   |Del| §±| 1!| 2@| 3#| /?|RCl|
`-------------------------------|  |---+---+---+---+---+-----------' 
            |   |   |   |   |   |  |PEn|   |   |   |   |
            `-------------------'  `-------------------'
EN-WIN
,-----------------------.                  ,-----------------------.
|   | ! | + | `~| } | & |                  | =+| 7&| 8*| 9(| 0)| * |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   | # | $ |LSh|RAl| | |                  | -_| 4$| 5%| 6^| ]}| \||
|---+---+---+---+---+---|-------.  ,-------|---+---+---+---+---+---|
|   | % | ^ | ~ | ] | _ |NUP|   |  |   |Del| \|| 1!| 2@| 3#| /?|RCl|
`-------------------------------|  |---+---+---+---+---+-----------' 
            |   |   |   |   |   |  |PEn|   |   |   |   |
            `-------------------'  `-------------------'
SE-MAC
,-----------------------.                  ,-----------------------.
|   | ! | ` | <>| ^ | /\|                  | ´`|7/||8([|9)]|0= | ( |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   | # | € |LSh|RAl| * |                  | +?|4€$|5% |6&§|¨^~| '*|
|---+---+---+---+---+---|-------.  ,-------|---+---+---+---+---+---|
|   | % | & | > | = | ? |NUP|   |  |   |Del| §°|1! |2"@|3#£|-_ |RCL|
`-------------------------------|  |---+---+---+---+---+-----------'
            |   |   |   |   |   |  |PEn|   |   |   |   |
            `-------------------'  `-------------------'
SE-WIN
,-----------------------.                  ,-----------------------.
|   | ! | ` | § | ^ | / |                  | ´`|7/{|8([|9)]|0=}| ( |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   | # |sun|LSh|RAl| * |                  | +?|4¤$|5%€|6& |¨^~| '*|
|---+---+---+---+---+---|-------.  ,-------|---+---+---+---+---+---|
|   | % | & |hlf| = | ? |NUP|   |  |   |Del|<>||1! |2"@|3#£| -_|RCL|
`-------------------------------|  |---+---+---+---+---+-----------'
            |   |   |   |   |   |  |Pen|   |   |   |   |
            `-------------------'  `-------------------'
*/


[_NUM] = LAYOUT(
 _______,KC_EXLM, KC_PLUS,KC_GRV,KC_RCBR,KC_AMPR,                                        KC_EQL,  KC_7, KC_8, KC_9, KC_0,    KC_RBRC,
 _______,KC_HASH, KC_DLR,KC_LSFT,KC_RALT,KC_PIPE,                                        KC_MINS, KC_4, KC_5, KC_6, KC_BSLS, KC_ASTR,
 _______,KC_PERC,KC_CIRC,KC_TILD,KC_RPRN,KC_UNDS,MO(_NUMPAD),_______,   _______, KC_DEL, KC_NUBS, KC_1, KC_2, KC_3, KC_SLSH, KC_RCTL,
                         _______,_______,_______,    _______,_______,   KC_PENT,_______, _______,_______,_______
		       ),

/*
* _NAV: Function keys, navigation
,-----------------------.                  ,-----------------------.
|   |F1 |F2 |F3 |F4 |F5 |                  |Hme|PgD|PgU|End|Ins|PSc|
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   |F6 |F7 |F8 |F9 |F10|                  |Lft|Dwn| Up|Rgt|ScL|Pse|
|---+---+---+---+---+---+-------.  ,-------+---+---+---+---+---+---|
|   |F11|F12|Vdn|Vup|App|   |   |  |   |   |MLt|Md |MUp|MRt|MB1|MB2|
`-----------+---+---+---+---+---|  |---+---+---+---+---+-----------'
            |   |   |   |   |   |  |   |   |   |   |   |
            `-------------------'  `-------------------'
*/

[_NAV] = LAYOUT(
_______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                                   KC_HOME,KC_PGDN,KC_PGUP, KC_END,   KC_INS,  KC_PSCR,
_______,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,                                   KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT,  KC_SCRL,  KC_PAUS,
_______, KC_F11, KC_F12,KC_VOLD,KC_VOLU, KC_APP,_______,_______,   _______,_______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,  KC_BTN1,  KC_BTN2,
                        _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
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
            |   |   |   |   |   |  |   |   |   |   |   |
            `-------------------'  `-------------------'
*/
[_NUMPAD] = LAYOUT(
   _______,_______,_______,_______,_______,_______,                                   KC_PEQL,KC_P7,KC_P8,KC_P9,  KC_P0,_______,
   _______,_______,_______,_______,_______,_______,                                   KC_PMNS,KC_P4,KC_P5,KC_P6,KC_PAST,_______,
   _______,_______,KC_PDOT,KC_COMM,KC_PENT,KC_NUM,_______,_______,   _______,_______,KC_PPLS,KC_P1,KC_P2,KC_P3,KC_PSLS,_______,
                           _______,_______,_______,_______,_______,   _______,_______,_______,_______,_______
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
            |   |   |   |   |   |  |   |   |   |   |   |
            `-------------------'  `-------------------'
*/
[_MACROS] = LAYOUT(
_______, _______, _______, M_LRCBR, M_LRABR, _______,                                        KC_EXEC, KC_HELP, KC_MENU, KC_SELECT, KC_STOP, KC_AGAIN,
_______, _______, _______, M_LRPRN, M_DQUOT, M_DPIPE,                                        RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,   RGB_MOD,  _______,
_______, _______, _______, M_LRBRC,M_DDQUOT, _______, _______, _______,    _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD,  RGB_RMOD,  _______,
                              _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    )

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUM, _NAV, _MACROS);
}

