/* Copyright 2023 JJIG
 *
 */

#include QMK_KEYBOARD_H
#include "jjibagar.h"
#include "sendstring_spanish_dvorak.h"
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_4_wrapper(
	_____BASE_I1_____		_____BASE_D1_____
	_____BASE_I2_____		_____BASE_D2_____
	_____BASE_I3_____		_____BASE_D3_____
	_____BASE_I4_____		_____BASE_D4_____
  ),

/*   Capa de simbolos (lower)
    |¿?| ! | "  | · | $ | % |
    |& | ()| {} | <>|[] |"|"| 
    |@ | #  | ~ | ^ |   |
*/  
  [_LOWER] = LAYOUT_split_3x6_4_wrapper(
	_____LOWER_I1_____		_____LOWER_D1_____
	_____LOWER_I2_____     		_____LOWER_D2_____
	_____LOWER_I3_____              _____LOWER_D3_____       
	_____LOWER_I4_____ 		_____LOWER_D4_____
  ),  

  [_RAISE] = LAYOUT_split_3x6_4_wrapper(
	_____RAISE_I1_____		_____RAISE_D1_____
	_____RAISE_I2_____		_____RAISE_D2_____
	_____RAISE_I3_____		_____RAISE_D3_____
	_____RAISE_I4_____		_____RAISE_D4_____
  ),

  [_ADJUST] = LAYOUT_split_3x6_4_wrapper(
        _____ADJUST_I1_____		_____ADJUST_D1_____
        _____ADJUST_I2_____	     	_____ADJUST_D2_____
        _____ADJUST_I3_____	    	_____ADJUST_D3_____
        _____ADJUST_I4_____	      	_____ADJUST_D4_____
      ),
 

  [_EMACS] = LAYOUT_split_3x6_4_wrapper(
      _____EMACS_I1_____	_____EMACS_D1_____
      _____EMACS_I2_____	_____EMACS_D2_____
      _____EMACS_I3_____	_____EMACS_D3_____
      _____EMACS_I4_____	_____EMACS_D4_____
      ),
  [_NUM] = LAYOUT_split_3x6_4_wrapper(
	_____NUM_I1_____	_____NUM_D1_____
	_____NUM_I2_____	_____NUM_D2_____    
	_____NUM_I3_____	_____NUM_D3_____    
	_____NUM_I4_____	_____NUM_D4_____
      ),
  [_JUEGOS] = LAYOUT_split_3x6_4_wrapper(
_____JUEGOS_I1_____	_____JUEGOS_D1_____
_____JUEGOS_I2_____	_____JUEGOS_D2_____
_____JUEGOS_I3_____	_____JUEGOS_D3_____
_____JUEGOS_I4_____	_____JUEGOS_D4_____
     )
};      
      
     
