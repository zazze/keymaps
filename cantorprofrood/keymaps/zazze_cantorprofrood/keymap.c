// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0
// Compile with
// qmk compile -kb cantorprofrood -km zazze_cantorprofrood -e CONVERT_TO=promicro_rp2040

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

#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)
#define ADJUST   MO(_ADJUST)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define LGUI_ESC  LGUI_T(KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

/* Home row mods left hand */

#define KC_LSHA LSFT_T(KC_A)
#define KC_GUIS LGUI_T(KC_S)
#define KC_LALD LALT_T(KC_D)
#define KC_RALF RALT_T(KC_F)

#define KC_CTLZ LCTL_T(KC_Z)

/* Home row mods right hand */
#define KC_RALJ RALT_T(KC_J)
#define KC_LALK LALT_T(KC_K)
#define KC_GUIL RGUI_T(KC_L)
#define KC_RSHBSL RSFT_T(KC_BSLS)

#define KC_RCTLBSP RCTL_T(KC_BSPC)

/* Thumb keys left */
#define KC_LMESC LT(_LMOD, KC_ESC)
#define KC_NUMTAB LT(_NUM, KC_TAB)

/* Thumb keys right */

#define KC_NAVENT LT(_NAV, KC_ENT)
#define KC_RMSPC LT(_RMOD, KC_SPC)


// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │TAB│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │ [{│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │LSH│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ;:│ '"│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │LCL│ Z │ X │ C │ V │ B │       │ N │ M │ ,<│ .>│BSP│RSH│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *       ┌───┐                               ┌───┐
      *       │LAL├───────┐                   ┌───┤DEL│
      *       └───┤LGU ESC├───────┐   ┌───────┤SPC├───┘
      *           └───────┤NUM TAB│   │NAV ENT├───┘
      *                   └───────┘   └───────┘
      */
/*
 * _QWERTY
EN-WIN
,-----------------------.                  ,-----------------------.
|TAB| Q | W | E | R | T |                  | Y | U | I | O | P | [{|
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|LSH| A | S | D | F | G |                  | H | J | K | L | ;:| '"|
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|LCL| Z | X | C | V | B |                  | N | M | ,<| .>|BSP|RSH|
`-----------+---+---+---+-------.  ,-------+---+---+---+-----------'
            |LAL|LGU ESC|NUM TAB|  |NAV ENT|SPC|RAL|
            `---+-------+-------'  `-------+---+---'

SE-WIN SE-MAC
,-----------------------.                  ,-----------------------.
|TAB| Q | W | E | R | T |                  | Y | U | I | O | P | Å |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|LSH| A | S | D | F | G |                  | H | J | K | L | Ö | Ä |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
|LCL| Z | X | C | V | B |                  | N | M | ,;| .:|BSP|RSH|
`-----------+---+---+---+-------.  ,-------+---+---+---+-----------'
            |LAL|LGU ESC|NUM TAB|  |NAV ENT|SPC|RAL|
            `---+-------+-------'  `-------+---+---'
 */

[_QWERTY] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_BSPC, KC_RSFT,
                                        KC_LALT, LGUI_ESC, KC_NUMTAB,   KC_NAVENT, KC_SPC, KC_RALT
    ),
 /* 
* _NUM: Function keys, Symbols, Numbers
EN-MAC
,-----------------------.           ,-----------------------.
|   | ! | + | `~| } | & |           | =+| 7&| 8*| 9(| 0)| ]}| 
|---+---+---+---+---+---|           |---+---+---+---+---+---|
|   | # | $ |LSh|RAl| | |           | -_| 4$| 5%| 6^| \|| * |
|---+---+---+---+---+---|           |---+---+---+---+---+---|
|   | % | ^ | ~ | ) | _ |           | §±| 1!| 2@| 3#| /?|RCl|
`-----------------------|---.   ,---|---+---+---+---+---+---' 
                |   |   |   |   |   |   |   |
                `-----------'   `-----------'
EN-WIN
,-----------------------.           ,-----------------------.
|   | ! | + | `~| } | & |           | =+| 7&| 8*| 9(| 0)| ]}| 
|---+---+---+---+---+---|           |---+---+---+---+---+---|
|   | # | $ |LSh|RAl| | |           | -_| 4$| 5%| 6^| \|| * |
|---+---+---+---+---+---|           |---+---+---+---+---+---|
|   | % | ^ | ~ | ) | _ |           | §±| 1!| 2@| 3#| /?|RCl|
`-----------------------|---.   ,---|---+---+---+---+---+---' 
                |   |   |   |   |   |   |   |
                `-----------'   `-----------'

,-----------------------.           ,-----------------------.
|   | ! | + | `~| } | & |           | =+| 7&| 8*| 9(| 0)| * |
|---+---+---+---+---+---|           |---+---+---+---+---+---|
|   | # | $ |LSh|RAl| | |           | -_| 4$| 5%| 6^| ]}| \||
|---+---+---+---+---+---|           |---+---+---+---+---+---|
|   | % | ^ | ~ | ] | _ |           | \|| 1!| 2@| 3#| /?|RCl|
`-----------------------|---.   ,---+---+---+---+-----------' 
                |   |   |   |   |   |   |   |
                `-----------'   `-----------'
SE-MAC
,-----------------------.           ,-----------------------.
|   | ! | + | `~| } | & |           | =+| 7&| 8*| 9(| 0)| ]}| 
|---+---+---+---+---+---|           |---+---+---+---+---+---|
|   | # | $ |LSh|RAl| | |           | -_| 4$| 5%| 6^| \|| * |
|---+---+---+---+---+---|           |---+---+---+---+---+---|
|   | % | ^ | ~ | ) | _ |           | §±| 1!| 2@| 3#| /?|RCl|
`-----------------------|---.   ,---|---+---+---+---+---+---' 
                |   |   |   |   |   |   |   |
                `-----------'   `-----------'

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
,-----------------------.           ,-----------------------.
|   | ! | + | `~| } | & |           | =+| 7&| 8*| 9(| 0)| ]}| 
|---+---+---+---+---+---|           |---+---+---+---+---+---|
|   | # | $ |LSh|RAl| | |           | -_| 4$| 5%| 6^| \|| * |
|---+---+---+---+---+---|           |---+---+---+---+---+---|
|   | % | ^ | ~ | ) | _ |           | §±| 1!| 2@| 3#| /?|RCl|
`-----------------------|---.   ,---|---+---+---+---+---+---' 
                |   |   |   |   |   |   |   |
                `-----------'   `-----------'

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


[_NUM] = LAYOUT_split_3x6_3(
 _______,KC_EXLM, KC_PLUS,KC_GRV,KC_RCBR,KC_AMPR,  KC_EQL,  KC_7, KC_8, KC_9, KC_0,    KC_RBRC,
 _______,KC_HASH, KC_DLR,KC_LSFT,KC_RALT,KC_PIPE,  KC_MINS, KC_4, KC_5, KC_6, KC_BSLS, KC_ASTR,
 _______,KC_PERC,KC_CIRC,KC_TILD,KC_RPRN,KC_UNDS,  KC_NUBS, KC_1, KC_2, KC_3, KC_SLSH, KC_RCTL,
                         _______,_______,_______,  _______,_______,KC_DEL
		       )

   
};

