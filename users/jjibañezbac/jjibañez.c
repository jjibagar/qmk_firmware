
// esto me da problemas, si no lo quito no compila
// alfred lo tiene en jjibañez.c y en el keymap
#include "jjibañez.h"
#include "muse.h"
#include "keymap_spanish_dvorak.h"
#include "sendstring_spanish_dvorak.h"




// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:
// __attribute__ ((weak))
// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

// finished and reset functions for each tapdance keycode
void alt_lp_finished(tap_dance_state_t *state, void *user_data);
void alt_lp_reset(tap_dance_state_t *state, void *user_data);
void ctrl_lp_finished(tap_dance_state_t *state, void *user_data);
void ctrl_lp_reset(tap_dance_state_t *state, void *user_data);





// __attribute__ ((weak))
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if ( !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above


// clang-format on
layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

    
// Handle the possible states for each tapdance keycode you define:_:?¿?¿
// __attribute__ ((weak))
void alt_lp_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(DV_QUES);
            break;
        case TD_SINGLE_HOLD:
            register_code16(KC_LALT);
            break;	           
        case TD_DOUBLE_SINGLE_TAP:         
            register_code16(DV_IQUE);
            break;
    case TD_UNKNOWN:
	break;

    }
}
// __attribute__ ((weak))
void alt_lp_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(DV_QUES);
            break;
        case TD_SINGLE_HOLD:
            unregister_code16(KC_LALT);
            break;	           
        case TD_DOUBLE_SINGLE_TAP:         
            unregister_code16(DV_IQUE);
            break;
    case TD_UNKNOWN:
	break;
	    }
}
void ctrl_lp_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(DV_AMPR);
            break;
        case TD_SINGLE_HOLD:
            register_code16(KC_LCTL);
            break;	           
        case TD_DOUBLE_SINGLE_TAP:         
            register_code16(DV_BULT);
            break;
    case TD_UNKNOWN:
	break;

    }
}
void ctrl_lp_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(DV_AMPR);
            break;
        case TD_SINGLE_HOLD:
            unregister_code16(KC_LCTL);
            break;	           
        case TD_DOUBLE_SINGLE_TAP:         
            unregister_code16(DV_BULT);
            break;
    case TD_UNKNOWN:
	break;
	    }
}
// Tap Dance definitions 
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for , twice for ; y lo mismo para el . y los : 
  [TD_PTO] = ACTION_TAP_DANCE_DOUBLE(DV_DOT, LSFT(DV_DOT)),
  [TD_PC] = ACTION_TAP_DANCE_DOUBLE(DV_COMM, LSFT(DV_COMM)),
  [TD_GUION]= ACTION_TAP_DANCE_DOUBLE(DV_MINS, LSFT(DV_MINS)),  // se pulsa una vez es un guion. si se pulsa 2 veces guion+shft  
  [TD_COPY]= ACTION_TAP_DANCE_DOUBLE(DV_Q, KC_COPY), //
  [TD_PASTE]= ACTION_TAP_DANCE_DOUBLE(DV_Y, KC_PASTE),
//simbolos lower
  [TD_INTE]=ACTION_TAP_DANCE_DOUBLE(DV_QUES, DV_IQUE),
  [TD_EXCL]=ACTION_TAP_DANCE_DOUBLE(DV_EXLM,DV_IEXL),
  [TD_CORCH]=ACTION_TAP_DANCE_DOUBLE(DV_LBRC,DV_RBRC),
  [TD_LLAVE]=ACTION_TAP_DANCE_DOUBLE(DV_LCBR,DV_RCBR),
  [TD_PAREN]=ACTION_TAP_DANCE_DOUBLE(DV_LPRN,DV_RPRN),
  [TD_MAYOR]=ACTION_TAP_DANCE_DOUBLE(DV_LABK,DV_RABK),
  [TD_BIRG]=ACTION_TAP_DANCE_DOUBLE(DV_TILD,DV_CIRC),
  [ALT_LP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_lp_finished, alt_lp_reset),
  [CTRL_LP]=ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_lp_finished, ctrl_lp_reset)
};

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);


// clang-format on
layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

// Left encoder scrolls the mousewheel. Right encoder adjusts underglow hue.
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_DOWN);
#else
            tap_code(KC_PGDN);
#endif
        } else {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
#else
            tap_code(KC_PGUP);
#endif
        }
    } else {  // index = 1: right encoder
        if (clockwise) {
#ifdef RGB_MATRIX_ENABLE
            rgb_matrix_step();
#else
            rgblight_increase_hue_noeeprom();
#endif
        } else {
#ifdef RGB_MATRIX_ENABLE
            rgb_matrix_step_reverse();
#else
            rgblight_decrease_hue_noeeprom();
#endif
        }
    }
    return false;
}

// Set underglow color to blue.
void keyboard_post_init_user(void) { rgblight_sethsv_noeeprom(RGBLIGHT_DEFAULT_COLOR); }


// prueba RGB
// dessde aqui
