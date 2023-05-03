// Keymap for tapdancing

// Compile and flash with
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
  _NAV,
  _NUM,
  _NUMPAD,
  _FUN
};

enum ferris_tap_dances {
  TD_Q_ESC
};

#define KC_A_LSH LSFT_T(KC_A)
#define KC_Z_CTL LCTL_T(KC_Z)
#define KC_SC_RSH RSFT_T(KC_SCLN)
//#define KC_CTTA CTL_T(KC_TAB)
#define KC_BSP_CTL CTL_T(KC_BSPC)
// #define KC_GUTA GUI_T(KC_TAB)
#define KC_ESC_GUI GUI_T(KC_ESC)
// #define KC_CLGV CTL_T(KC_GRV)

#define KC_ENT_NAV LT(_NAV, KC_ENT)
#define KC_TAB_NUM LT(_NUM, KC_TAB)
#define KC_SPC_ALT ALT_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* QWERTY */
    KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,
    KC_A_LSH, KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,  KC_K,    KC_L,    KC_SC_RSH,
    KC_Z_CTL, KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_BSP_CTL,
                        KC_ESC_GUI, KC_TAB_NUM,          KC_ENT_NAV, KC_SPC_ALT
  ),

  [_NAV] = LAYOUT( 
    KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_DEL,         KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_LBRC,
    KC_LSFT, KC_LGUI, KC_LALT, KC_RALT,  KC_ESC,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_RBRC, 
    KC_LCTL,    KC_Z, KC_BTN1, KC_BTN2, KC_TRNS,         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_QUOT,
                                 KC_TRNS, KC_TRNS,     _______, KC_TRNS  
  ),

  [_NUM] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_EQL,  KC_7, KC_8, KC_9,    KC_0,
    KC_LSFT, KC_LGUI, KC_LALT, KC_RALT, KC_ESC,          KC_MINS, KC_4, KC_5, KC_6, KC_BSLS,
    KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_GRV,  KC_1, KC_2, KC_3, KC_SLSH,
                                KC_TRNS, _______,      MO(_NUMPAD), MO(_FUN)  
  ),

  [_NUMPAD] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_PPLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0,
    KC_LSFT, KC_LGUI, KC_LALT, KC_RALT, KC_ESC,          KC_PMNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST,
    KC_LCTL, KC_TRNS, KC_PCMM, KC_PDOT, KC_PENT,         KC_PEQL, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS,
                                  KC_TRNS, _______, _______, KC_TRNS
  ),
   
  [_FUN] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_APP,  KC_F7, KC_F8, KC_F9, KC_F10,
    KC_LSFT, KC_LGUI, KC_LALT, KC_RALT, KC_ESC,           KC_CAPS, KC_F4, KC_F5, KC_F6, KC_F11,
    KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_INS,  KC_F1, KC_F2, KC_F3, KC_F12,
                                   KC_TRNS, _______, KC_TRNS, _______
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
