#pragma once

#include "quantum.h"

enum sofle_layers {
    
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE
};
enum {
    TD_PC,
    TD_COMI,
    TD_SLA,
    TD_CAPLOCK,
    TD_PTO,
    TD_GUION,
    TD_COPY,
    TD_PASTE,
    TD_BASE,
    TD_JUEGOS
};
enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    SCROLL,
    MACRO1,
    MACRO2,
    MACRO3,
    MACRO4,
    MACRO5,
    UNICODE,
    RIGTHARROW,
    LEFTARROW,
    UPARROW,
    DOWNARROW,
    TAURUS,
    ALTGR_ONE_SHOT,
    TIL_A,
    TIL_O,
    TIL_E,
    TIL_U,
    TIL_I,
    ALT_TAB = SAFE_RANGE
};

// declaraciones unicode, en case essta otraforwa de meterlos 
#define STAR 0x2605 
#define FLECHA_AR 0x21A5
#define FLECHA_I 0x21A4
#define FLECHA_D 0x21A6
#define FLECHA_AB 0x21A7

