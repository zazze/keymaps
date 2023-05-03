// Keymap used with chording

// Compile and flash with
// make ferris/0_2/compact:zazze:flash
// or 
// make ferris/0_2/bling:zazze:flash
// being in the QMK root directory


// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _QWERTY,
  _LMOD,
  _NUM,
  _NUMPAD,
  _FUN,
  _RMOD,
  _NAV
};

enum ferris_tap_dances {
  TD_Q_ESC
};

#define KC_LSHA LSFT_T(KC_A)
#define KC_CTLZ LCTL_T(KC_Z)
#define KC_RSSC RSFT_T(KC_SCLN)
#define KC_CTSB CTL_T(KC_RBRC)


#define KC_SPM2 LT(2, KC_SPC)
#define KC_BSM1 LT(1, KC_BSPC)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGV CTL_T(KC_GRV)

#define KC_ENNAV LT(_NAV, KC_ENT)
#define KC_BSNUM LT(_NUM, KC_BSPC)
#define KC_SPALT ALT_T(KC_SPC)
#define KC_RSHCAPS RSFT_T(KC_CAPS)
#define KC_RCTLBSP RCTL_T(KC_BSPC)
#define KC_LMESC LT(_LMOD, KC_ESC)
#define KC_NUMTAB LT(_NUM, KC_TAB)

#define KC_NAVENT LT(_NAV, KC_ENT)
#define KC_RMSPC LT(_RMOD, KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 
_QWERTY Layer 
,-------------------.             ,-----------------------. 
| Q | W | E | R | T |             | Y | U | I | O |   P   | 
|---+---+---+---+---|             |---+---+---+---+-------| 
| A | S | D | F | G |             | H | J | K | L |  RSH  | 
|---+---+---+---+---|             |---+---+---+---+-------|
| Z | X | C | V | B |             | N | M | ,<| .>|RCL BSP| 
`---+---+---+---+---+----.    ,---+---+---+---+---+-------' 
        |LMOD ESC|NUM TAB|    |NAV ENT|RMOD SPC| 
	`----------------'    `----------------'               
*/
[_QWERTY] = LAYOUT(
    KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,
    KC_A,      KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,  KC_K,    KC_L,    KC_RSFT,
    KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_RCTLBSP,
                              KC_LMESC,  KC_NUMTAB,    KC_NAVENT, KC_RMSPC
  ),

/*
_NAV Layer 
,-------------------.             ,-------------------. 
|TAB| §±|MB1|MB2|SPC|             |HME|PDN|PUP|END| [{| 
|---+---+---+---+---|             |---+---+---+---+---| 
|LSH|LGU|LAL|RAL|ESC|             |LFT|DWN|LFT|RGT| ;:|
|-------+---+---+---|             |---+---+---+---+---| 
|LCL|CAP|DEL|BSP|ENT|             |ML |MDN|MUP|MR | '"| 
`---+---+---+---+---+---.     ,---+---+---+---+---+---' 
                |   |   |     |   |   | 
		`-------'     `-------'		 
*/
  [_NAV] = LAYOUT( 
    KC_TAB,  KC_NUBS, KC_BTN1, KC_BTN2,  KC_SPC,         KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_LBRC,
    KC_LSFT, KC_LGUI, KC_LALT, KC_RALT,  KC_ESC,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN,
    KC_LCTL, KC_CAPS, KC_DEL,  KC_BSPC,  KC_ENT,         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_QUOT,
                                 _______, _______,     _______, _______
		   ),

/* 

_NUM Layer 
,-------------------.             ,-------------------. 
|TAB| `~|   |   |SPC|             | =+| 7&| 8*| 9(| 0)| 
|---+---+---+---+---|             |---+---+---+---+---|
|LSH|LGU|LAL|RAL|ESC|             | -_| 4$| 5%| 6^| ]}|
|-------+---+---+---|             |---+---+---+---+---|
|LCT|   |VOD|VOU|ENT|             | \|| 1!| 2@| 3#| /?| 
`---+---+---+---+---+---.    ,----+---+---+---+---+---' 
                |   |   |    |_FUN|_NUMPAD|
		`-------'    `------------'		 
*/
  [_NUM] = LAYOUT(
    KC_TAB,   KC_GRV, _______, _______, KC_SPC,        KC_EQL,  KC_7, KC_8, KC_9, KC_0,
    KC_LSFT, KC_LGUI, KC_LALT, KC_RALT, KC_ESC,        KC_MINS, KC_4, KC_5, KC_6, KC_RBRC,
    KC_LCTL, _______, KC_VOLD, KC_VOLU, KC_ENT,        KC_BSLS, KC_1, KC_2, KC_3, KC_SLSH, 
                               _______, _______,      MO(_FUN), MO(_NUMPAD)
		  ),

/* 
_LMOD Layer 
,-------------------.             ,-------------------. 
|TAB|   |   |   |SPC|             |   |   |   |   |   |
|---+---+---+---+---|             |---+---+---+---+---| 
|LSH|LGU|LAL|RAL|ESC|             |   |   |   |   |   |
|-------+---+---+---|             |---+---+---+---+---| 
|LCL|   |   |   |ENT|             |   |   |   |   |   | 
`---+---+---+---+---+---.     ,---+---+---+---+---+---' 
                |   |   |     |   |   | 
		`-------'     `-------'	               
*/	 

[_LMOD] = LAYOUT(
    KC_TAB,  _______, _______, _______,  KC_SPC,         _______, _______, _______, _______, _______,
    KC_LSFT, KC_LGUI, KC_LALT, KC_RALT,  KC_ESC,         _______, _______, _______, _______, _______,
    KC_LCTL, _______, _______, _______,  KC_ENT,         _______, _______, _______, _______, _______,
                               _______, _______,         _______, _______  
  ),

/* 
_RMOD Layer 
,-------------------.              ,-------------------. 
|   |   |   |   |   |              |SPC|   |   |   |TAB|
|---+---+---+---+---|              |---+---+---+---+---|
|   |   |   |   |   |              |ESC|RAL|LAL|RGU|RSH| 
|-------+---+---+---|              |---+---+---+---+---|
|   |   |   |   |   |              |ENT|   |   |   |RCL|
`---+---+---+---+---+---.  ,---+---+---+---+---+---+---' 
                |   |   |  |   |   | 
		`-------'  `-------'                    
*/
[_RMOD] = LAYOUT(
    _______, _______, _______, _______, _______,         KC_SPC, _______, _______, _______, KC_TAB,
    _______, _______, _______, _______, _______,         KC_ESC, KC_RALT, KC_LALT, KC_RGUI, KC_RSFT,
    _______, _______, _______, _______, _______,         KC_ENT, _______, _______, _______, KC_RCTL,
                               _______, _______,         _______, _______
		 ),

/* 
_NUMPAD Layer 
,-------------------.             ,-------------------. 
|   |   |   |   |   |             | + | 7 | 8 | 9 | 0 | 
|---+---+---+---+---|             |---+---+---+---+---|
|   |   |   |   |   |             | - | 4 | 5 | 6 | * | 
|-------+---+---+---|             |---+---+---+---+---|
|   |   |PCM|PDT|PEN|             | = | 1 | 2 | 3 | / | 
`---+---+---+---+---+---.  ,---+--+---+---+---+---+---' 
                |   |   |  |   |  | 
		`-------'  `------' 		       
*/
[_NUMPAD] = LAYOUT(
    _______, _______, _______, _______, _______,      KC_PPLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0,
    _______, _______, _______, _______, _______,      KC_PMNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST,
    _______, _______, KC_PCMM, KC_PDOT, KC_PENT,      KC_PEQL, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS,
                               _______, _______,         _______, _______
  ),   
/* 
_FUN Layer 
,-------------------.             ,-------------------. 
|   |   |   |   |   |             |APP| F7| F8| F9|F10| 
|---+---+---+---+---|             |---+---+---+---+---|
|   |   |   |   |   |             |CPL| F4| F5| F6|F11| 
|-------+---+---+---|             |---+---+---+---+---|
|   |   |   |   |   |             |INS| F1| F2| F3|F12| 
`---+---+---+---+---+---.  ,---+--+---+---+---+---+---' 
                |   |   |  |   |  | 
		`-------'  `------'                    
*/
[_FUN] = LAYOUT(
    _______, _______, _______, _______, _______,           KC_APP,  KC_F7, KC_F8, KC_F9, KC_F10,
    _______, _______, _______, _______, _______,           KC_CAPS, KC_F4, KC_F5, KC_F6, KC_F11,
    _______, _______, _______, _______, _______,           KC_INS,  KC_F1, KC_F2, KC_F3, KC_F12,
                               _______, _______,           _______, _______
  ),

};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
