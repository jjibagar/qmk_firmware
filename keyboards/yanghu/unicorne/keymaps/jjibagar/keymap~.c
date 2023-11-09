/* Copyright 2021 Yang Hu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any ccdddd()((cc666622266ññññññ662266ññññ666666ñññ666))
 * This program is distributed in the hope that it will be useful,#~⁺-6d
 * but WITHOUT ANY WARRANTY; without even the implied warranty of   
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See theñ
 *Ç*^¿??.ñ,pyyyp.ggg777131313++++++++ * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.Cambio la T->A
 */




#include QMK_KEYBOARD_H
#include "jjibagar.h"
#include "sendstring_spanish_dvorak.h"
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_4(
/*   
    |¿?| ! | "  | · | $ | % |
    |& | ()| {} | <>|[] |"|"| 
    |@ | #  | ~ | ^ |   |
*/  
LALT_T(KC_ESC), TD(TD_PTO) ,TD(TD_PC),KC_E,KC_R,TD(TD_PASTE),       KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_GRV,                            
LCTL_T(KC_TAB), DV_A, LALT_T(DV_O),LCTL_T(DV_E),LSFT_T(DV_U), DV_I, DV_D,  RSFT_T(DV_R),RCTL_T(DV_T),RALT_T(DV_N),KC_SCLN,DV_ACUT,
LSFT_T(KC_CAPS),TD(TD_GUION),TD(TD_COPY),KC_C, DV_K,DV_X,           DV_B, DV_M, DV_W, DV_V, em_Z, DV_QUOT,                      
KC_LGUI, KC_LALT, LOWER,KC_SPC,					    LT(_NUM,KC_ENT),KC_BSPC, RAISE, KC_MUTE                         
),

[_LOWER] = LAYOUT_split_3x6_4(
TD(ALT_LP),  TD(TD_EXCL),  DV_DQUO,  DV_AMPR,  DV_DLR, DV_PERC,	              TG(_RAISE), _______ ,KC_UP,  _______,_______,_______,   
TD(CTRL_LP),TD(TD_PAREN),TD(TD_LLAVE),TD(TD_MAYOR),TD(TD_CORCH),TD(TD_BIRG),  XXXXXXX,KC_LEFT,  KC_DOWN,KC_RGHT,  _______,DV_GRV,     
DV_EQL, DV_PLUS, DV_ASTR, TD(TD_BARRA),   DV_HASH,  DV_AT  ,  	       	      KC_PAST,  KC_PSLS, DV_EQL,  _______,_______,_______,    
_______, _______,_______,_______,	      				      KC_PENT,  KC_DEL ,   _______, _______                    
  ),  

  [_RAISE] = LAYOUT_split_3x6_4(
 KC_F1,  KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6,              TG(_LOWER), _______,  KC_PGUP, _______, _______,  _______, 
 KC_F7,  KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,             _______,   KC_HOME,  KC_PGDN,  KC_END, _______,  _______, 
_______, _______, _______, _______, _______, _______,      _______,  _______,  _______,  _______,  _______, _______, 
                      _______, _______,  _______, KC_INS,   _______,   _______,   _______,  _______                      
  ),

  [_ADJUST] = LAYOUT_split_3x6_4(
  KC_PWR,   RGB_SAI, RGB_HUI,  RGB_MOD,  RGB_VAI,   RGB_TOG,  TG(_BASE),  XXXXXXX,  XXXXXXX,  XXXXXXX,  MACRO4,  MACRO1,
  XXXXXXX,   RGB_SAD, RGB_HUD,  RGB_RMOD, RGB_VAD,   XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  MACRO5,  MACRO2,
  XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX, QK_BOOT,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, MACRO3,
                           _______,  _______,   _______,   _______, _______,   _______,   _______,  _______                     
      ),
 

  [_EMACS] = LAYOUT_split_3x6_4(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ORGPDF , XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX, 
XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX, XXXXXXX ,XXXXXXX, XXXXXXX, RECENT, XXXXXXX   , XXXXXXX, SAVE , XXXXXXX, 
XXXXXXX, XXXXXXX, OPEN, XXXXXXX, KILL, XXXXXXX ,         BUFFER, MAGIT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX                     
      ),
  [_NUM] = LAYOUT_split_3x6_4(
      XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,   TG(_JUEGOS),KC_P7, KC_P8, KC_P9,  XXXXXXX, XXXXXXX,
XXXXXXX,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,   XXXXXXX,  KC_P4, KC_P5,  KC_P6, XXXXXXX,  XXXXXXX,    
DV_EQL, DV_PLUS, DV_ASTR, TD(TD_BARRA), DV_HASH,  DV_AT,  _______,  KC_P1, KC_P2,  KC_P3,  XXXXXXX,  XXXXXXX,   
_______,   _______,   _______,  _______,          	  KC_ENT,   _______,   _______,   _______          
      ),
  [_JUEGOS] = LAYOUT_split_3x6_4(
      LALT_T(KC_ESC), TD(TD_PTO) ,TD(TD_PC),KC_E,KC_R,TD(TD_PASTE),  TG(_BASE), KC_U, KC_I,    KC_O,   KC_P, KC_GRV, 
LCTL_T(KC_TAB), DV_A, DV_O, DV_E, DV_U , DV_I,                 DV_D,  DV_R,DV_T,DV_N,DV_S,DV_ACUT,//KC_QUOT ,    
LSFT_T(KC_CAPS),TD(TD_GUION),DV_Q, DV_J, DV_K,DV_X,            DV_B, DV_M, DV_W, DV_W, em_Z, DV_QUOT, // KC_MINS,
KC_LGUI, KC_LALT, LOWER,KC_SPC,                                KC_ENT,KC_BSPC, RAISE, KC_RALT                    
      
     )
};      
      
     
