#ifndef USERSPACE
#define USERSPACE

#pragma once
#include "quantum.h"
#include "layers.h"
#include "process_records.h"
#include "tap_dances.h"

//#include QMK_KEYBOARD_H





// LAYOUT WRAPPERS -> lo siguiente lo he sacado de alfrdmalr.h ,funciona. Lo he sacado de user y de loyut/community/ortho5x12
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_split_3x6_4_wrapper(...)  LAYOUT_split_3x6_4(__VA_ARGS__)


#define em_Z LT(_EMACS,DV_Z)
#define ju_ENT LT(_JUEGOS,DV_ENT)
//#define NUBSemacs LT(_EMACS,KC_NUBS)
//#define MINSemacs LT(_EMACS,KC_SLSH)

// extern keymap_config_t keymap_config;
// defino capa base    
#define _____BASE_I1_____ LALT_T(KC_ESC), TD(TD_PTO) ,TD(TD_PC),KC_E,KC_R,TD(TD_PASTE), 
#define _____BASE_I2_____ LCTL_T(KC_TAB), DV_A, LALT_T(DV_O),LCTL_T(DV_E),LSFT_T(DV_U), DV_I,
#define _____BASE_I3_____ LSFT_T(KC_CAPS),TD(TD_GUION),TD(TD_COPY),KC_C, DV_K,DV_X,
#define _____BASE_I4_____ KC_LGUI, KC_LALT, LOWER,KC_SPC,
#define _____BASE_D1_____ KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_GRV,
#define _____BASE_D2_____ DV_D,  RSFT_T(DV_R),RCTL_T(DV_T),RALT_T(DV_N),KC_SCLN,DV_ACUT,//KC_QUOT ,
#define _____BASE_D3_____ DV_B, DV_M, DV_W, DV_W, em_Z, DV_QUOT, // KC_MINS, 
#define _____BASE_D4_____ LT(_NUM,KC_ENT),KC_BSPC, RAISE, KC_RALT

// tienes que sacar super y Mgr para poder poner los potenciometros mira a ver si puedes tener un archivo layers en users y separas mejor, esto no tendria que ir aqui
// defino lower
#define _____LOWER_I1_____ TD(ALT_LP),  TD(TD_EXCL),  DV_DQUO,  DV_BULT,  DV_DLR, DV_PERC,
#define _____LOWER_I2_____ TD(CTRL_LP),TD(TD_PAREN),TD(TD_LLAVE),TD(TD_MAYOR),TD(TD_CORCH),TD(TD_BIRG),
#define _____LOWER_I3_____ DV_EQL, DV_PLUS, DV_ASTR, TD(TD_BARRA),   DV_HASH,  DV_AT  ,  
#define _____LOWER_I4_____  _______,  _______,  _______,   _______,   
#define _____LOWER_D1_____ TG(_RAISE), _______ ,KC_UP,  _______,_______,_______, 
#define _____LOWER_D2_____   XXXXXXX,KC_LEFT,  KC_DOWN,KC_RGHT,  _______,DV_GRV,
#define _____LOWER_D3_____  KC_PAST,  KC_PSLS, DV_EQL,  _______,_______,_______,
#define _____LOWER_D4_____  KC_PENT,  KC_DEL ,   _______, _______      
   /*
|¿ ?|¡ !| " | & | $ | % |
|~ ·| ()| {}| <>|[] | |^|  ESTO PONERLO EN LOWER 
| = | + | * |/\ | @ | # | DV_SLSH es / en tapdance con KC_BSLS \ → nombre TD(TD_BARRA)
   */
   // hay que sacar el numerico, y poner las flechas bien en todas las capas
   // se puede poner el numerico en capa intro
#define _____RAISE_I1_____  KC_F1,  KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6,   
#define _____RAISE_I2_____  KC_F7,  KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
#define _____RAISE_I3_____ _______, _______, _______, _______, _______, _______,
#define _____RAISE_I4_____			 _______, _______,  _______, KC_INS,
#define _____RAISE_D1_____ TG(_LOWER), _______,  KC_PGUP, _______, _______,  _______,
#define _____RAISE_D2_____ _______,   KC_HOME,  KC_PGDN,  KC_END, _______,  _______,  
#define _____RAISE_D3_____ _______,  _______,  _______,  _______,  _______, _______,    
#define _____RAISE_D4_____  _______,   _______,   _______,  _______

#define _____NUM_I1_____  XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
#define _____NUM_I2_____  XXXXXXX,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
#define _____NUM_I3_____  DV_EQL, DV_PLUS, DV_ASTR, TD(TD_BARRA), DV_HASH,  DV_AT,
#define _____NUM_I4_____		 _______,   _______,   _______,  _______,          		     
#define _____NUM_D1_____ TG(_JUEGOS),KC_P7, KC_P8,  KC_P9,  XXXXXXX,  XXXXXXX, 
#define _____NUM_D2_____ XXXXXXX,  KC_P4, KC_P5,  KC_P6, XXXXXXX,  XXXXXXX,   
#define _____NUM_D3_____ _______,  KC_P1, KC_P2,  KC_P3,  XXXXXXX,  XXXXXXX, 
#define _____NUM_D4_____ KC_ENT,   _______,   _______,   _______	    	


   // poné el sonido y ver que mas se puede tocar
#define _____ADJUST_I1_____ KC_PWR,   RGB_SAI, RGB_HUI,  RGB_MOD,  RGB_VAI,   RGB_TOG,  
#define _____ADJUST_I2_____  XXXXXXX,   RGB_SAD, RGB_HUD,  RGB_RMOD, RGB_VAD,   XXXXXXX,
#define _____ADJUST_I3_____  XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
#define _____ADJUST_I4_____                     _______,  _______,   _______,   _______,    
#define _____ADJUST_D1_____ TG(_BASE),  XXXXXXX,  XXXXXXX,  XXXXXXX,  MACRO4,  MACRO1,	
#define _____ADJUST_D2_____ XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  MACRO5,  MACRO2,	
#define _____ADJUST_D3_____ QK_BOOT,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, MACRO3,
#define _____ADJUST_D4_____ _______,   _______,   _______,  _______			

   //capa emacs
#define _____EMACS_I1_____ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ORGPDF , XXXXXXX,
#define _____EMACS_I2_____ XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX, XXXXXXX ,XXXXXXX  ,
#define _____EMACS_I3_____ XXXXXXX, XXXXXXX, OPEN, XXXXXXX, KILL, XXXXXXX ,
#define _____EMACS_I4_____           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
#define _____EMACS_D1_____  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX,
#define _____EMACS_D2_____  XXXXXXX, RECENT, XXXXXXX   , XXXXXXX, SAVE , XXXXXXX,
#define _____EMACS_D3_____  BUFFER, MAGIT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
#define _____EMACS_D4_____  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define _____JUEGOS_I1_____ LALT_T(KC_ESC), TD(TD_PTO) ,TD(TD_PC),KC_E,KC_R,TD(TD_PASTE),            
#define _____JUEGOS_I2_____ LCTL_T(KC_TAB), DV_A, DV_O, DV_E, DV_U , DV_I,      
#define _____JUEGOS_I3_____ LSFT_T(KC_CAPS),TD(TD_GUION),DV_Q, DV_J, DV_K,DV_X,                
#define _____JUEGOS_I4_____ KC_LGUI, KC_LALT, LOWER,KC_SPC,                                          
#define _____JUEGOS_D1_____ TG(_BASE), KC_U, KC_I,    KC_O,   KC_P,    KC_GRV,                            
#define _____JUEGOS_D2_____ DV_D,  DV_R,DV_T,DV_N,DV_S,DV_ACUT,//KC_QUOT ,
#define _____JUEGOS_D3_____ DV_B, DV_M, DV_W, DV_W, em_Z, DV_QUOT, // KC_MINS,                       
#define _____JUEGOS_D4_____ KC_ENT,KC_BSPC, RAISE, KC_RALT                                           

#endif

