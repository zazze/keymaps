// Compile with
// make clean;make splitkb/kyria/rev1:zazze_bling:flash
// being in the QMK root directory
// Flash using qmkgui

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
EN-MAC/WIN
,-----------------------.                  ,-----------------------.
|Tab| Q | W | E | R | T |                  | Y | U | I | O | P | {[|
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|LSh| A | S | D | F | G |                  | H | J | K | L | ;:| '"|
|---+---+---+---+---+---+-------.  ,---+---+---+---+---+---+---+---|
|LCl| Z | X | C | V | B |CsL|RAl|  |RAl|Del| N | M | ,<| .>|Bsp|RSh|
`-----------+---+---+---+---+---|  |---+---+---+---+---+-----------'
    (Up|Dwn)|Rsh|LAl|LGU|NUM|Esc|  |Ent|NAV|Spc|RGU|Bsp|(WLft|WRgt)
            `-------------------'  `-------------------'
SE-MAC/WIN
,-----------------------.                  ,-----------------------.
|Tab| Q | W | E | R | T |                  | Y | U | I | O | P | Å |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|LSh| A | S | D | F | G |                  | H | J | K | L | Ö | Ä |
|---+---+---+---+---+---+-------.  ,---+---+---+---+---+---+---+---|
|LCl| Z | X | C | V | B |CsL|RAl|  |RAl|Del| N | M | ,;| .:|Bsp|RSh|
`-----------+---+---+---+---+---|  |---+---+---+---+---+-----------'
    (Up|Dwn)|Rsh|LAl|LGU|NUM|Esc|  |Ent|NAV|Spc|RGU|Bsp|(WLft|WRgt)
            `-------------------'  `-------------------'
 */
[_QWERTY] = LAYOUT( 
    KC_TAB,  KC_Q, KC_W,  KC_E, KC_R,  KC_T,                                       KC_Y,   KC_U,    KC_I,   KC_O,    KC_P, KC_LBRC,
    KC_LSFT, KC_A, KC_S,  KC_D, KC_F,  KC_G,                                       KC_H,   KC_J,    KC_K,   KC_L, KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z, KC_X,  KC_C, KC_V,  KC_B, KC_CAPS,KC_RALT,  KC_RALT,  KC_DEL,   KC_N,   KC_M, KC_COMM, KC_DOT, KC_BSPC, KC_RSFT,
                    KC_RSFT,KC_LALT,KC_LGUI,MO(_NUM),KC_ESC,   KC_ENT,MO(_NAV), KC_SPC,KC_RGUI, KC_BSPC
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
   (MWU|MWD)|Rsh|LAl|LGU|   |Esc|  |PEn|MAC|Spc|RGU|Bsp|(BSP|DEL)
            `-------------------'  `-------------------'
EN-WIN
,-----------------------.                  ,-----------------------.
|   | ! | + | `~| } | & |                  | =+| 7&| 8*| 9(| 0)| * |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   | # | $ |LSh|RAl| | |                  | -_| 4$| 5%| 6^| ]}| \||
|---+---+---+---+---+---|-------.  ,-------|---+---+---+---+---+---|
|   | % | ^ | ~ | ] | _ |NUP|   |  |   |Del| \|| 1!| 2@| 3#| /?|RCl|
`-------------------------------|  |---+---+---+---+---+-----------' 
   (MWU|MWD)|Rsh|LAl|LGU|   |Esc|  |PEn|MAC|Spc|RGU|Bsp|(BSP|DEL)
            `-------------------'  `-------------------'
SE-MAC
,-----------------------.                  ,-----------------------.
|   | ! | ` | <>| ^ | /\|                  | ´`|7/||8([|9)]|0= | ( |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   | # | € |LSh|RAl| * |                  | +?|4€$|5% |6&§|¨^~| '*|
|---+---+---+---+---+---|-------.  ,-------|---+---+---+---+---+---|
|   | % | & | > | = | ? |NUP|   |  |   |Del| §°|1! |2"@|3#£|-_ |RCl|
`-------------------------------|  |---+---+---+---+---+-----------'
   (MWU|MWD)|Rsh|LAl|LGU|   |Esc|  |PEn|MAC|Spc|RGU|Bsp|(BSP|DEL)
            `-------------------'  `-------------------'
SE-WIN
,-----------------------.                  ,-----------------------.
|   | ! | ` | § | ^ | / |                  | ´`|7/{|8([|9)]|0=}| ( |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   | # |sun|LSh|RAl| * |                  | +?|4¤$|5%€|6& |¨^~| '*|
|---+---+---+---+---+---|-------.  ,-------|---+---+---+---+---+---|
|   | % | & |hlf| = | ? |NUP|   |  |   |Del|<>||1! |2"@|3#£| -_|RCl|
`-------------------------------|  |---+---+---+---+---+-----------'
   (MWU|MWD)|Rsh|LAl|LGU|   |Esc|  |PEn|MAC|Spc|RGU|Bsp|(BSP|DEL)
            `-------------------'  `-------------------'
*/


[_NUM] = LAYOUT(
   _______,KC_EXLM, KC_PLUS,KC_GRV,KC_RCBR,KC_AMPR,                                         KC_EQL, KC_7, KC_8, KC_9,   KC_0,  KC_ASTR,
   _______,KC_HASH, KC_DLR,KC_LSFT,KC_RALT,KC_PIPE,                                        KC_MINS, KC_4, KC_5, KC_6,KC_RBRC,KC_BSLS,
   _______,KC_PERC,KC_CIRC,KC_TILD,KC_RPRN,KC_UNDS,MO(_NUMPAD),_______,   _______, KC_DEL, KC_NUBS,KC_1, KC_2, KC_3,KC_SLSH,KC_RCTL,
                           _______,_______,_______,    _______,_______,   KC_PENT,_______, _______,_______,_______
		       ),

/*
* _NAV: Function keys, navigation
,-----------------------.                  ,-----------------------.
|   |F1 |F2 |F3 |F4 |F5 |                  |Hme|PgD|PgU|End|Ins|PSc|
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|   |F6 |F7 |F8 |F9 |F10|                  |Lft|Dwn| Up|Rgt|ScL|Pse|
|---+---+---+---+---+---+-------.  ,-------+---+---+---+---+---+---|
|   |F11|F12|Vdn|Vup|App|   |   |  |   |   |MLt|Md |MUp|MRt|MB1|RSh|
`-----------+---+---+---+---+---|  |---+---+---+---+---+-----------'
   (PgU|PgD)|Rsh|LAl|LGU|NUM|Esc|  |PEn|NAV|Spc|RGU|Bsp|(Bsp|Del)
            `-------------------'  `-------------------'
*/

[_NAV] = LAYOUT(
   _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                                   KC_HOME,KC_PGDN,KC_PGUP, KC_END,  KC_INS,  KC_PSCR,
   _______,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10,                                   KC_LEFT,KC_DOWN,  KC_UP,KC_RGHT, KC_SCRL,  KC_PAUS,
   _______, KC_F11, KC_F12,KC_VOLD,KC_VOLU, KC_APP,_______,_______,   _______,_______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R, KC_BTN1,  KC_RSFT,
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
   (PgU|PgD)|Rsh|LAl|LGU|NUM|Esc|  |PEn|NAV|Spc|RGU|Bsp|(Bsp|Del)
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
 (VolU|VolD)|   |   |   |   |   |  |   |   |   |   |   |(RGBVAI|RGBVAD)
            `-------------------'  `-------------------'
*/
[_MACROS] = LAYOUT(
   _______, _______, _______, M_LRCBR, M_LRABR, _______,                                        KC_EXEC, KC_HELP, KC_MENU, KC_SELECT, KC_STOP, KC_AGAIN,
   _______, _______, _______, M_LRPRN, M_DQUOT, M_DPIPE,                                        RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,   RGB_MOD,  _______,
   _______, _______, _______, M_LRBRC,M_DDQUOT, _______, _______, _______,    _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD,  RGB_RMOD,  _______,
                              _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
    )

};

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
// };

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
    return update_tri_layer_state(state, _NUM, _NAV, _MACROS);
}

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

// DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
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
/*       
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _DVORAK:
                oled_write_P(PSTR("Dvorak\n"), false);
                break;
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
       }
*/
        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
/*
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
    */
  // Left encoder
  if (index == 0) {
    switch (biton32(layer_state)) {
    case _QWERTY:
      // Up and down arrows
      if (clockwise) {
	tap_code(KC_DOWN);
      } else {
	tap_code(KC_UP);
      }
      break;
    case _NAV:
      // Page up and down
      if (clockwise) {
	tap_code(KC_PGDN);
      } else {
	tap_code(KC_PGUP);
      }
      break;
    case _NUM:
      // Mouse wheel up and down
      if (clockwise) {
	tap_code(KC_WH_D);
     } else {
	tap_code(KC_WH_U);
      }
      break;
    case _MACROS:
      // Volume up and down
      if (clockwise) {
	tap_code(KC_VOLU);
     } else {
	tap_code(KC_VOLD);
      }
      break;
    default:
      // Default is up and down
      if (clockwise) {
	tap_code(KC_DOWN);
      } else {
	tap_code(KC_UP);
      }
      break;
    }
    // Right encoder
  } else if (index == 1) {
    switch (biton32(layer_state)) {
    case _QWERTY:
      // Scroll by Word
      if (clockwise) {
	tap_code16(LCTL(KC_RGHT));
      } else {
	tap_code16(LCTL(KC_LEFT));
      }
      break;
    case _NUM:
      // Switch browser tabs
      if (clockwise) {
	tap_code16(KC_DEL);
      } else {
	tap_code16(KC_BSPC);
      }
      break;
    case _NAV:
      // Delete whole Word
      if (clockwise) {
	tap_code16(LCTL(KC_DEL));
      } else {
	tap_code16(LCTL(KC_BSPC));
      }
      break;
    case _MACROS:
      // RGB brightness up/down
      if (clockwise) {
	rgblight_increase_val(); // tap_code(RGB_VAI);
      } else {
	rgblight_decrease_val(); // tap_code(RGB_VAD);
      }
      break;
    default:
      if (clockwise) {
	tap_code(KC_RIGHT);
     } else {
	tap_code(KC_LEFT);
      }
      break;
    }
  }
  return false;
}
    
}
#endif
// DELETE THIS LINE TO UNCOMMENT (2/2)
