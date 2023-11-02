#pragma once
#include "jjibagar.h"
#include "keymap_spanish_dvorak.h"
//#include "sendstring_spanish_dvorak.h"


enum {
     ALT_LP, // Our example key: LALT when held, ( when tapped. Add additional keycodes for each tapdance.
    CTRL_LP,
    LSFT_LP,
    TD_PTO,
    TD_PC,
    TD_COMI,
    TD_SLA,
    TD_CAPLOCK,
    TD_GUION,
    TD_COPY,
    TD_PASTE,
    //tapdance de simbolos lower
    TD_INTE,
    TD_EXCL,
    TD_CORCH,
    TD_LLAVE,
    TD_MAYOR,
    TD_PAREN,
    TD_BIRG,
    TD_BARRA
};

// Define a type containing as many tapdance states as you need¿?¿?¿?
typedef enum {
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;



// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

// finished and reset functions for each tapdance keycode
void alt_lp_finished(tap_dance_state_t *state, void *user_data);
void alt_lp_reset(tap_dance_state_t *state, void *user_data);
void ctrl_lp_finished(tap_dance_state_t *state, void *user_data);
void ctrl_lp_reset(tap_dance_state_t *state, void *user_data);

