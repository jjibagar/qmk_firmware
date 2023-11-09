#include "jjibagar.h"


// Create a global instance of the tapdance state type
// esto me da error y no se por que
static td_state_t td_state;

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if ( !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}
// Handle the possible states for each tapdance keycode you define:
// esto nos permite 3 estados en el tapdance, los estas usando en Control, Meta en la capa lower, mira que necesita dos funciones cada una 
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
            register_code16(DV_CIRC);
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
            unregister_code16(DV_CIRC);
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
void lsft_hr_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(DV_LPRN);
            break;
        case TD_SINGLE_HOLD:
            register_code16(KC_LSFT);
            break;	           
        case TD_DOUBLE_SINGLE_TAP:         
            register_code16(DV_RPRN);
            break;
    case TD_UNKNOWN:
	break;

    }
}
void lsft_hr_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(DV_LPRN);
            break;
        case TD_SINGLE_HOLD:
            unregister_code16(KC_LSFT);
            break;	           
        case TD_DOUBLE_SINGLE_TAP:         
            unregister_code16(DV_RPRN);
            break;
    case TD_UNKNOWN:
	break;
	    }
}
void ctrl_hr_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(DV_LBRC);
            break;
        case TD_SINGLE_HOLD:
            register_code16(KC_LCTL);
            break;	           
        case TD_DOUBLE_SINGLE_TAP:         
            register_code16(DV_RBRC);
            break;
    case TD_UNKNOWN:
	break;

    }
}
void ctrl_hr_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(DV_LBRC);
            break;
        case TD_SINGLE_HOLD:
            unregister_code16(KC_LCTL);
            break;	           
        case TD_DOUBLE_SINGLE_TAP:         
            unregister_code16(DV_RBRC);
            break;
    case TD_UNKNOWN:
	break;
	    }
}
void alt_hr_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(DV_LABK);
            break;
        case TD_SINGLE_HOLD:
            register_code16(KC_LALT);
            break;	           
        case TD_DOUBLE_SINGLE_TAP:         
            register_code16(DV_RABK);
            break;
    case TD_UNKNOWN:
	break;

    }
}
void alt_hr_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(DV_LABK);
            break;
        case TD_SINGLE_HOLD:
            unregister_code16(KC_LALT);
            break;	           
        case TD_DOUBLE_SINGLE_TAP:         
            unregister_code16(DV_RABK);
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
//  [TD_CORCH]=ACTION_TAP_DANCE_DOUBLE(DV_LBRC,DV_RBRC),
[TD_LLAVE]=ACTION_TAP_DANCE_DOUBLE(DV_LCBR,DV_RCBR),
// [TD_PAREN]=ACTION_TAP_DANCE_DOUBLE(DV_LPRN,DV_RPRN),
//  [TD_MAYOR]=ACTION_TAP_DANCE_DOUBLE(DV_LABK,DV_RABK),
  [TD_BIRG]=ACTION_TAP_DANCE_DOUBLE(DV_PIPE,DV_TILD),
  [TD_BARRA]=ACTION_TAP_DANCE_DOUBLE(DV_SLSH,DV_BSLS),
  [ALT_LP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_lp_finished, alt_lp_reset),
  [CTRL_LP]=ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_lp_finished, ctrl_lp_reset),
  //Configuramos los hold de homerow en lower
  [LSFT_HR]=ACTION_TAP_DANCE_FN_ADVANCED(NULL, lsft_hr_finished, lsft_hr_reset),
  [CTRL_HR]=ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_hr_finished, ctrl_hr_reset),
  [ALT_HR]=ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_hr_finished, alt_hr_reset)
};



