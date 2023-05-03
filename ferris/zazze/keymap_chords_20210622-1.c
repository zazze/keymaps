// Keymap used with chording

// Compile and flash with
// make ferris/0_2/compact:zazze:flash
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  [_QWERTY] = LAYOUT(
    KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,
    KC_A,      KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,  KC_K,    KC_L,    KC_SPC,
    KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_ENT,
    MO(_LMOD), MO(_NUM), MO(_NAV), MO(_RMOD)
  ),

  [_LMOD] = LAYOUT(
    KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_LSFT, KC_LALT, KC_LGUI, KC_RALT, KC_ESC,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_LCTL, KC_TRNS, KC_BSPC, KC_DEL,  KC_RCTL,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   _______, KC_TRNS, KC_TRNS, KC_TRNS  
  ),

  [_NUM] = LAYOUT(
    KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_EQL,  KC_7, KC_8, KC_9,    KC_0,
    KC_LSFT, KC_LALT, KC_LGUI, KC_RALT, KC_ESC,          KC_MINS, KC_4, KC_5, KC_6, KC_BSLS,
    KC_LCTL, KC_TRNS, KC_PCMM, KC_PDOT, KC_PENT,         KC_GRV,  KC_1, KC_2, KC_3, KC_SLSH,
                                  KC_TRNS, _______, MO(_NUMPAD), MO(_FUN)
  ),

  [_NUMPAD] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_PPLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0,
    KC_LSFT, KC_LALT, KC_LGUI, KC_RALT, KC_ESC,          KC_PMNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST,
    KC_LCTL, KC_TRNS, KC_BSPC, KC_DEL,  KC_RCTL,         KC_PEQL, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS,
                                  KC_TRNS, _______, _______, KC_TRNS
  ),
   
  [_FUN] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_APP,  KC_F7, KC_F8, KC_F9, KC_F10,
    KC_LSFT, KC_LALT, KC_LGUI, KC_RALT, KC_ESC,           KC_CAPS, KC_F4, KC_F5, KC_F6, KC_F11,
    KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCTL,          KC_INS,  KC_F1, KC_F2, KC_F3, KC_F12,
                                   KC_TRNS, _______, KC_TRNS, _______
  ),
  
  [_RMOD] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RBRC,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_ESC,  KC_LALT, KC_RGUI, KC_RALT, KC_RSFT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_LCTL, KC_DEL,  KC_LBRC, KC_QUOT, KC_RCTL,
                                   KC_TRNS, KC_TRNS, MO(_NAV), _______
  ),

  [_NAV] = LAYOUT( 
    KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_LBRC,
    KC_LSFT, KC_LALT, KC_LGUI, KC_RALT, KC_ESC,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN, 
    KC_LCTL, KC_TRNS, KC_BTN1, KC_BTN2, KC_RCTL,         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_QUOT,
                                    KC_TRNS, KC_TRNS, _______, KC_TRNS  
  )

};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
