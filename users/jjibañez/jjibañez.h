#ifndef USERSPACE
#define USERSPACE


#include"layers.h"
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "keymap_spanish_dvorak.h"
#include "sendstring_spanish_dvorak.h"

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
    TD_BIRG
};

enum custom_keycodes {
    //QWERTY = SAFE_RANGE,
  KC_MAKE = SAFE_RANGE,
  NEW_SAFE_RANGE,  //use "NEW_SAFE_RANGE" for keymap specific codes
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
  ALT_TAB,
  ALTGR_ONE_SHOT,
  TIL_A,
  TIL_O,
  TIL_E,
  TIL_U,
  TIL_I
};
enum combos {
  CB_ALTGR_ONE_SHOT,
  CB_DVK_TIL_A,
  CB_DVK_TIL_O,
  CB_DVK_TIL_E,
  CB_DVK_TIL_U,
  CB_DVK_TIL_I,
  COMBO_LENGTH
};




/* / Tap Dance keycodes
enum td_keycodes {
    ALT_LP, // Our example key: LALT when held, ( when tapped. Add additional keycodes for each tapdance.
    CTRL_LP,
    LSFT_LP
};
*/

/******************************/
/* #define LOWER MO(_LOWER)   */
/* #define RAISE MO(_RAISE)   */
/* #define ADJUST MO(_ADJUST) */
/* #define LOWER MO(_LOWER)   */
/* #define RAISE MO(_RAISE)   */
/* #define ADJUST MO(_ADJUST) */
/* #define EMACS MO(_EMACS)   */
/* #define JUEGOS MO(_JUEGOS) */
/* #define NUM MO(_NUM)	      */
/******************************/


// Define a type containing as many tapdance states as you need¿?¿?¿?
typedef enum {
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;



// LAYOUT WRAPPERS -> lo siguiente lo he sacado de alfrdmalr.h ,funciona. Lo he sacado de user y de loyut/community/ortho5x12
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_split_3x6_4_wrapper(...)  LAYOUT_split_3x6_4(__VA_ARGS__)
// lo siguiente es de 333fred
// extern keymap_config_t keymap_config;




// defino capa base    
#define _____BASE_I1_____ LALT_T(KC_ESC), TD(TD_PTO) ,TD(TD_PC),KC_E,KC_R,TD(TD_PASTE), 
#define _____BASE_D1_____ KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_GRV,
#define _____BASE_I2_____ LCTL_T(KC_TAB), DV_A, LALT_T(DV_O),LCTL_T(DV_E),LSFT_T(DV_U), DV_I,
#define _____BASE_D2_____ DV_D, RSFT_T(DV_R),RCTL_T(DV_T),RALT_T(DV_N),KC_SCLN,KC_QUOT ,
#define _____BASE_I3_____ LSFT_T(KC_CAPS),TD(TD_GUION),TD(TD_COPY),KC_C, DV_K,DV_X,
#define _____BASE_D3_____ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
#define _____BASE_I4_____ KC_LGUI, KC_LALT, LOWER,KC_SPC,
#define _____BASE_D4_____ KC_ENT,KC_BSPC, RAISE, KC_RALT

// tienes que sacar super y Mgr para poder poner los potenciometros mira a ver si puedes tener un archivo layers en users y separas mejor, esto no tendria que ir aqui
// defino lower
#define _____LOWER_I1_____ TD(ALT_LP),  TD(TD_EXCL),  DV_DQUO,  DV_BULT,  DV_DLR, DV_PERC,
#define _____LOWER_I2_____ TD(CTRL_LP),TD(TD_PAREN),TD(TD_LLAVE),TD(TD_MAYOR),TD(TD_CORCH),DV_PIPE,
#define _____LOWER_I3_____ _______,DV_PLUS, DV_AT,    DV_HASH,  TD(TD_BIRG)  ,   _______,
#define _____LOWER_I4_____  _______,  _______,  _______,   _______,   
#define _____LOWER_D1_____ TG(_RAISE),KC_UP,  _______, KC_P7, KC_P8,  KC_P9,
#define _____LOWER_D2_____ KC_LEFT,  KC_DOWN,KC_RGHT,  KC_P4, KC_P5,  KC_P6,
#define _____LOWER_D3_____ KC_PAST,  KC_PSLS, DV_EQL,  KC_P1, KC_P2,  KC_P3,
#define _____LOWER_D4_____ KC_PENT,  KC_DEL ,   _______,  KC_P0
   /*
|¿ ?|¡ !| " | & | $ | % |
|~ ·| ()| {}| <>|[] | |^|  ESTO PONERLO EN LOWER 
| = | + | * |/\ | @ | # | 
   */
   // hay que sacar el numerico, y poner las flechas bien en todas las capas
   // se puede poner el numerico en capa intro
#define _____RAISE_I1_____ _______,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
#define _____RAISE_I2_____ _______,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
#define _____RAISE_I3_____ KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
#define _____RAISE_I4_____                  _______,  _______,   _______,   KC_INS,
#define _____RAISE_D1_____ TG(_LOWER),KC_PGUP, _______,_______,  _______,  _______,
#define _____RAISE_D2_____  KC_HOME,  KC_PGDN, KC_END, _______,  _______,  _______,
#define _____RAISE_D3_____    KC_F7,  KC_F8,    KC_F9,  KC_F10,   KC_F11,  KC_F12, 
#define _____RAISE_D4_____  _______,   _______,   _______,  _______

   // poné el sonido y ver que mas se puede tocar
#define _____ADJUST_I1_____ KC_PWR,   RGB_SAI, RGB_HUI,  RGB_MOD,  RGB_VAI,   RGB_TOG,  
#define _____ADJUST_I2_____  XXXXXXX,   RGB_SAD, RGB_HUD,  RGB_RMOD, RGB_VAD,   XXXXXXX,
#define _____ADJUST_I3_____  XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
#define _____ADJUST_I4_____                 _______,  _______,   _______,   _______,    
#define _____ADJUST_D1_____ TG(_BASE),  XXXXXXX,  XXXXXXX,  XXXXXXX,  MACRO4,  MACRO1,	
#define _____ADJUST_D2_____ XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  MACRO5,  MACRO2,	
#define _____ADJUST_D3_____ QK_BOOT,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MACRO3,
#define _____ADJUST_D4_____ _______,   _______,   _______,  _______			

   // poné el sonido y ver que mas se puede tocar

#endif
