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
    M_DDQUOT,  // "|"
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

/* enum layers { */
/*     _QWERTY = 0, */
/*     _LOWER, */
/*     _RAISE, */
/*     NAV, */
/*     _ADJUST */
/* }; */

/* enum custom_keycodes { */
/*     KC_CCCV = SAFE_RANGE */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /*
 * Base Layer: _QWERTY

,-----------------------.                    ,-----------------------.
|Esc| Q | W | E | R | T |                    | Y | U | I | O | P |Bsp|
|---+---+---+---+---+---|                    |---+---+---+---+---+---|
|   |   |   |   |   |   |                    |   |   |   |   | ; | " |
|Tab| A | S | D | F | G |                    | H | J | K | L | : | ' |
|---+---+---+---+---+---+-------.    ,---+---+---+---+---+---+---+---|
|   |   |   |   |   |   |   |   |    |   |   |   |   | < | > | ? |   |
|LCl| Z | X | C | V | B |GUI|App|    |Del|Ral| N | M | , | . | / |RCl|
`-----------+---+---+---+---+---|    |---+---+---+---+---+-----------'
            |Lsh|LAl|Ent|LOW|Lsh|    |Rsh|RSE|Spc|Mac|Rsh|
            `-------------------'    `-------------------'
 */
   [_QWERTY] = LAYOUT( 
//,- -----+-----+-----+------+-----+------.                                    ,------+-----+--------+--------+--------+--------.  
    KC_ESC, KC_Q, KC_W,  KC_E, KC_R,  KC_T,                                       KC_Y, KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
//,-------|-----|-----|------|-----|------|                                    |------|-----|--------|--------|--------|--------|  
    KC_TAB, KC_A, KC_S,  KC_D, KC_F,  KC_G,                                       KC_H, KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
//,-------|-----|-----|------|-----|------|--------+-------. ,-------|---------|------|-----|--------|--------|--------|--------|     
   KC_LCTL, KC_Z, KC_X,  KC_C, KC_V,  KC_B, KC_LGUI, KC_APP,   KC_DEL,  KC_RALT,  KC_N, KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,
//,------------------------------------------------|-------| |-------|---------|------|-----|--------|--------+--------+--------,  
                   KC_LSFT,KC_LALT,KC_ENT,MO(_LOWER),KC_LSFT,  KC_RSFT,MO(_RAISE),KC_SPC,MO(_MACROS), KC_RSFT
//                |-------+-------+------+---------+-------, `-------+---------|------|----------|--------|
		    ),

 /* 
  * //////////// Numpad variant //////////////
  * 
  * Layer _LOWER: Function keys, Symbols, Numbers
,-----------------------.                  ,-----------------------.
| ~ | ! | @ | { | } | & |                  | / | 7 | 8 | 9 | - | , |
|---+---+---+---+---+---|                  |---+---+---+---+---+---|
| ` | # | $ | ( | ) | | |                  | * | 4 | 5 | 6 | + | . |
|---+---+---+---+---+---|-------.  ,-------|---+---+---+---+---+---|
| \ | % | ^ | [ | ] | _ |   |   |  |   |   | 0 | 1 | 2 | 3 | = |   |
`-------------------------------|  |---+---+---+---+---+-----------'
            |   |   |   |   |   |  |   |   |   |Ent|   |
            `-------------------'  `-------------------'
 */

[_LOWER] = LAYOUT(
//|-------+-------+-------+-------+-------+-------|                                  |-------+-----+-----+-----+-------+-------|
   KC_TILD,KC_EXLM,  KC_AT,KC_LCBR,KC_RCBR,KC_AMPR,                                   KC_PSLS,KC_P7,KC_P8,KC_P9,KC_PMNS,KC_COMM,
//,-------|-------|-------|-------|-------|-------|                                  |-------+-----+-----+-----+-------+-------|
    KC_GRV,KC_HASH, KC_DLR,KC_LPRN,KC_RPRN,KC_PIPE,                                   KC_PAST,KC_P4,KC_P5,KC_P6,KC_PPLS,KC_PDOT,
//,-------|-------|-------|-------|-------|-------|-------|-------|  |-------|-------|-------+-----+-----+-----+-------+-------|
   KC_BSLS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_UNDS,_______,_______,   _______,_______,  KC_P0,KC_P1,KC_P2,KC_P3, KC_EQL,_______,
//,-------+-------+-------|-------|-------|-------|-------|-------|  |-------|-------|-------|-----------------+-------+-------|
                           _______,_______,_______,_______,_______,   _______,_______,_______,KC_PENT,_______
//                        |-------+-------+-------+-------+-------|  |-------+-------+-------+-------+-------|
		       ),

/*
 * Layer _RAISE: Function keys, navigation
,-----------------------.                   ,-----------------------.
|F1 |F2 |F3 |F4 |F5 |F6 |                   |Hme|PgD|PgU|End|Ins|PSc|
|---+---+---+---+---+---|                   |---+---+---+---+---+---|
|F7 |F8 |F9 |F10|F11|F12|                   |Lft|Dwn|Up |Rgt|ScL|Pse|
|---+---+---+---+---+---+--------.  ,-------+---+---+---+---+---+---|
|Pre|Ply|Nxt|Mut|Vdn|Vup|Caps|   |  |   |   |MLt|Md |MUp|MRt|MB1|MB2|
`-----------+---+---+---+----+---|  |---+---+---+---+---+-----------'
            |   |   |   |    |   |  |   |   |   |   |   |
            `--------------------'  `-------------------'
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
 * Layer _MACROS: macros
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |  {}  |  <>  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |  ()  |  ''  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |  []  |  ""  |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MACROS] = LAYOUT(
      _______, _______, _______, M_LRCBR, M_LRABR, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, M_LRPRN, M_DQUOT, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, M_LRBRC, M_DDQUOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Adjust Layer: Function keys, RGB
 *
 * ,--------------------------------.                      ,-----------------------------.
 * | EXEC |HELP|MENU| SEL|STOP|AGAIN|                      | F13| F14| F15| F16| F17| F18|
 * |------+----+----+----+----+-----|                      |----+----+---------+----+----|
 * |      | TOG| SAI| HUI| VAI| MOD |                      | F19| F20| F21| F22| F23| F24|
 * |------+----+----+----+----+-----+---------.  ,---------+----+----+----+----+----+----|
 * |      |    | SAD| HUD| VAD| RMOD|    |    |  |    |    |    |    |    |    |    |    |
 * `----------------+----+----+-----+----+----|  |----+----+----+----+----+----+----+----'
 *                  |    |    |     |    |    |  |    |    |    |    |    |
 *                  `-------------------------'  `------------------------'
 */
    [_ADJUST] = LAYOUT(
      KC_EXEC, KC_HELP, KC_MENU, KC_SELECT, KC_STOP, KC_AGAIN,                                      KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,
      _______, RGB_TOG, RGB_SAI,   RGB_HUI, RGB_VAI,  RGB_MOD,                                      KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
      _______, _______, RGB_SAD,   RGB_HUD, RGB_VAD, RGB_RMOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______
    ),

};

/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/* /\*  */
/*  * Base Layer: _QWERTY */
/*  * */
/*  * ,-------------------------------------------.                              ,-------------------------------------------. */
/*  * | ESC    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   | */
/*  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------| */
/*  * | LSFT   |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   | */
/*  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------| */
/*  * | LCTL   |   Z  |   X  |   C  |   V  |   B  | CCCV |      |  | Del  |Leader|   N  |   M  | ,  < | . >  | /  ? |  - _   | */
/*  * `----------------------+------+------+------+------+      |  |------+------+------+------+------+----------------------' */
/*  *                        | GUI  | Alt  |      | Space| Enter|  | Bspc | Space|      | Tab  | AltGr| */
/*  *                        |      |      | Lower| Shift| Alt  |  |      | Nav  | Raise|      |      | */
/*  *                        `----------------------------------'  `----------------------------------' */
/*  *\/ */
/*     [_QWERTY] = LAYOUT( */
/*       KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE, */
/*       KC_LSFT, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, */
/*       KC_LCTL, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_CCCV,   XXXXXXX, KC_DEL, KC_LEAD,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS, */
/*               KC_LGUI, KC_LALT, MO(_LOWER), MT(MOD_LSFT, KC_SPC), MT(MOD_LALT, KC_ENT), KC_BSPC, LT(NAV, KC_SPC), MO(_RAISE), KC_TAB, KC_RALT */
/*     ), */
/* /\* */
/*  * Lower Layer: Numpad, Media */
/*  * */
/*  * ,-------------------------------------------.                              ,-------------------------------------------. */
/*  * |        |      |      | VolUp|      |      |                              | / ?  | 7 &  | 8 *  | 9 (  | - _  |        | */
/*  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------| */
/*  * |        |      | Prev | Play | Next |      |                              | *    | 4 $  | 5 %  | 6 ^  | , <  | +      | */
/*  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------| */
/*  * |        |      |      | VolDn| Mute |      |      |      |  |      |      | 0 )  | 1 !  | 2 @  | 3 #  | = +  |        | */
/*  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------' */
/*  *                        |      |      |      |      |      |  |      |      |      |      |      | */
/*  *                        |      |      | Lower|      |      |  |      | Nav  | Raise|      |      | */
/*  *                        `----------------------------------'  `----------------------------------' */
/*  *\/ */
/*     [_LOWER] = LAYOUT( */
/*       _______, _______, _______, KC_VOLU, _______, _______,                                     KC_SLSH, KC_7,    KC_8,    KC_9, KC_MINS, _______, */
/*       _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,                                     KC_ASTR, KC_4,    KC_5,    KC_6, KC_COMM, KC_PLUS, */
/*       _______, _______, _______, KC_VOLD, KC_MUTE, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3, KC_EQL,  _______, */
/*                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ */
/*     ), */
/* /\* */
/*  * Raise Layer: Symbols */
/*  * */
/*  * ,-------------------------------------------.                              ,-------------------------------------------. */
/*  * |        |  !   |  @   |  {   |  }   |  |   |                              |      |  _   |  €   |      |      |  \     | */
/*  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------| */
/*  * |        |  #   |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  %   |  ' "   | */
/*  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------| */
/*  * |        |  %   |  ^   |  [   |  ]   |  ~   |      |      |  |      |      |   &  |  =   |  ,   |  .   |  / ? | - _    | */
/*  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------' */
/*  *                        |      |      |      |      |      |  |      |      |      |      |      | */
/*  *                        |      |      | Lower|      |      |  |      | Nav  | Raise|      |      | */
/*  *                        `----------------------------------'  `----------------------------------' */
/*  *\/ */
/*     [_RAISE] = LAYOUT( */
/*       _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                     _______, KC_UNDS, ALGR(KC_5),_______,_______,KC_BSLS, */
/*       _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                      KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT, */
/*       _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS, */
/*                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ */
/*     ), */
/* /\* */
/*  * Navigation Layer */
/*  * */
/*  * ,-------------------------------------------.                              ,-------------------------------------------. */
/*  * |        |      |      |      |      |      |                              | PgUp | Home | Up   | End  |      | ScrlLk | */
/*  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------| */
/*  * |        |      |      |      |      |      |                              | PgDn | Left | Down | Right|      | CapsLk | */
/*  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------| */
/*  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        | */
/*  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------' */
/*  *                        |      |      |      |      |      |  |      |      |      |      |      | */
/*  *                        |      |      | Lower|      |      |  |      | Nav  | Raise|      |      | */
/*  *                        `----------------------------------'  `----------------------------------' */
/*  *\/ */
/*     [NAV] = LAYOUT( */
/*       _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_SLCK, */
/*       _______, _______, _______, _______, _______, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_CAPS, */
/*       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, */
/*                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ */
/*     ), */
/* /\* */
/*  * Adjust Layer */
/*  * */
/*  * ,-------------------------------------------.                              ,-------------------------------------------. */
/*  * |        |      |      |      |      |      |                              |      | F7   | F8   | F9   | F10  |        | */
/*  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------| */
/*  * |        |      | SAI  | HUI  | VAI  |      |                              |      | F4   | F5   | F6   | F11  |        | */
/*  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------| */
/*  * |        |      | SAD  | HUD  | VAD  |      |      |      |  |      |      |      | F1   | F2   | F3   | F12  |        | */
/*  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------' */
/*  *                        |      |      |      |      |      |  |      |      |      |      |      | */
/*  *                        |      |      |      |      |      |  |      |      |      |      |      | */
/*  *                        `----------------------------------'  `----------------------------------' */
/*  *\/ */
/*     [_ADJUST] = LAYOUT( */
/*       _______, _______, _______, _______, _______, _______,                                     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, */
/*       _______, _______, RGB_SAI, RGB_HUI, RGB_VAI, _______,                                     _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, */
/*       _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______, */
/*                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ */
/*     ), */
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
/* }; */

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
        }

    }
    
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case KC_CCCV:  // One key copy/paste */
/*             if (record->event.pressed) { */
/*                 copy_paste_timer = timer_read(); */
/*             } else { */
/*                 if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {  // Hold, copy */
/*                     tap_code16(LCTL(KC_C)); */
/*                 } else { // Tap, paste */
/*                     tap_code16(LCTL(KC_V)); */
/*                 } */
/*             } */
/*             break; */
/*     } */
/*     return true; */
/* } */


/* bool is_alt_tab_active = false; */
/* uint16_t alt_tab_timer = 0; */

/* LEADER_EXTERNS(); */

/* void matrix_scan_user(void) { */
/*     if (is_alt_tab_active) { */
/*         if (timer_elapsed(alt_tab_timer) > 1000) { */
/*             unregister_code(KC_LALT); */
/*             is_alt_tab_active = false; */
/*         } */
/*     } */

/*     LEADER_DICTIONARY() { */
/*         leading = false; */
/*         leader_end(); */

/*         SEQ_ONE_KEY(KC_C) { // Inline Code */
/*             SEND_STRING("`` " SS_TAP(X_LEFT) SS_TAP(X_LEFT)); */
/*         } */
/*         SEQ_ONE_KEY(KC_P) { // Invoke Password Manager */
/*             SEND_STRING(SS_LCTRL(SS_LALT("\\"))); */
/*         } */
/*         SEQ_ONE_KEY(KC_S) { // Windows screenshot */
/*             SEND_STRING(SS_LGUI("\nS")); */
/*         } */
/*         SEQ_TWO_KEYS(KC_F, KC_P) { // Fusion Projection prefix */
/*             SEND_STRING("[Projection] "); */
/*         } */
/*         SEQ_TWO_KEYS(KC_B, KC_B) { // Basecone invoice description */
/*             SEND_STRING("[Leveranciersnaam] [Factuurnummer]"); */
/*         } */
/*         SEQ_TWO_KEYS(KC_E, KC_S) { // Support email splitkb */
/*             SEND_STRING("support@splitkb.com"); */
/*         } */
/*         SEQ_TWO_KEYS(KC_E, KC_T) { // Email splitkb */
/*             SEND_STRING("thomas@splitkb.com"); */
/*         } */
/*         SEQ_TWO_KEYS(KC_E, KC_P) { // Email personal */
/*             SEND_STRING("mail@thomasbaart.nl"); */
/*         } */
/*         SEQ_TWO_KEYS(KC_S, KC_D) { // Splitkb documentation */
/*             SEND_STRING("https://docs.splitkb.com/"); */
/*         } */
/*         SEQ_TWO_KEYS(KC_S, KC_V) { // Splitkb VAT number */
/*             SEND_STRING("NL210593349B01"); */
/*         } */
/*         SEQ_TWO_KEYS(KC_B, KC_C) { // Discord bongocat */
/*             SEND_STRING(":bongocat:\n"); */
/*         } */
/*         SEQ_TWO_KEYS(KC_C, KC_B) { // Discord code block */
/*             SEND_STRING("```c" SS_LSFT("\n\n") "``` " SS_TAP(X_UP)); */
/*         } */
/*         SEQ_TWO_KEYS(KC_Y, KC_S) { // Greeting */
/*             SEND_STRING("Yours sincerely,\n\nThomas Baart"); */
/*         } */
/*         SEQ_THREE_KEYS(KC_M, KC_V, KC_G) { // Greeting */
/*             SEND_STRING("Met vriendelijke groet,\n\nThomas Baart"); */
/*         } */
/*     } */
/* } */

/* #ifdef OLED_DRIVER_ENABLE */
/* oled_rotation_t oled_init_user(oled_rotation_t rotation) { */
/* 	return OLED_ROTATION_180; */
/* } */

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

/* static void render_status(void) { */
/*     // QMK Logo and version information */
/*     render_qmk_logo(); */
/*     oled_write_P(PSTR("       Kyria rev1.0\n\n"), false); */

/*     // Host Keyboard Layer Status */
/*     oled_write_P(PSTR("Layer: "), false); */
/*     switch (get_highest_layer(layer_state)) { */
/*         case _QWERTY: */
/*             oled_write_P(PSTR("Default\n"), false); */
/*             break; */
/*         case _LOWER: */
/*             oled_write_P(PSTR("Lower\n"), false); */
/*             break; */
/*         case _RAISE: */
/*             oled_write_P(PSTR("Raise\n"), false); */
/*             break; */
/*         case NAV: */
/*             oled_write_P(PSTR("Navigation\n"), false); */
/*             break; */
/*         case _ADJUST: */
/*             oled_write_P(PSTR("Adjust\n"), false); */
/*             break; */
/*         default: */
/*             oled_write_P(PSTR("Undefined\n"), false); */
/*     } */

/*     // Host Keyboard LED Status */
/*     uint8_t led_usb_state = host_keyboard_leds(); */
/*     oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false); */
/*     oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false); */
/*     oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false); */
/* } */

/* void oled_task_user(void) { */
/*     if (is_keyboard_master()) { */
/*         render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc) */
/*     } else { */
/*         render_kyria_logo(); */
/*     } */
/* } */
/* #endif */

/* #ifdef ENCODER_ENABLE */
/* void encoder_update_user(uint8_t index, bool clockwise) { */
/*     if (index == 0) { */
/*         // Mouse wheel up-down */
/*         if (clockwise) { */
/*             tap_code(KC_MS_WH_UP); */
/*         } else { */
/*             tap_code(KC_MS_WH_DOWN); */
/*         } */
/*     } */
/*     else if (index == 1) { */
/*         // Mouse wheel right-left */
/*         if (clockwise) { */
/*             tap_code(KC_MS_WH_RIGHT); */
/*         } else { */
/*             tap_code(KC_MS_WH_LEFT); */
/*         } */
/*     } */
/* } */
/* #endif */

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    switch (biton32(layer_state)) {
    case _RAISE:
      // Mouse wheel up-down
      if (clockwise) {
	tap_code(KC_MS_WH_DOWN);
      } else {
	tap_code(KC_MS_WH_UP);
      }
      break;
    case _QWERTY:
      // Up and down arrows
      if (clockwise) {
	tap_code(KC_DOWN);
      } else {
	tap_code(KC_UP);
      }
      break;
    default:
      // Up and down arrows
      if (clockwise) {
	tap_code(KC_DOWN);
      } else {
	tap_code(KC_UP);
      }
      break;
    }
  } else if (index == 1) {
    switch (biton32(layer_state)) {
    case _LOWER:
      // Mouse wheel up-down
      if (clockwise) {
	tap_code(KC_MS_WH_DOWN);
      } else {
	tap_code(KC_MS_WH_UP);
      }
      break;
    case _QWERTY:
      // Scrolling with PageUp and PgDn.
      if (clockwise) {
	tap_code(KC_PGDN);
      } else {
	tap_code(KC_PGUP);
      }
      break;
    default:
      // Scrolling with PageUp and PgDn.
      if (clockwise) {
	tap_code(KC_PGDN);
      } else {
	tap_code(KC_PGUP);
      }
      break;
    }
  }
}
#endif
