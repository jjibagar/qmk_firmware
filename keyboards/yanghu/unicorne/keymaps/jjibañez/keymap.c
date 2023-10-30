/*
  

 */


// jjibañez.h se usa aqui y en jjibañez.c 

   //#include "keymap_spanish_dvorak.h"
   //#include "sendstring_spanish_dvorak.h"
#include "jjibañez.h"
#include <stdio.h>
#include <ctype.h>
#include "combos.c"


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_4_wrapper(
/*   
    |¿?| ! | "  | · | $ | % |
    |& | ()| {} | <>|[] |"|"| 
    |@ | #  | ~ | ^ |   |
*/  
	_____BASE_I1_____		_____BASE_D1_____
	_____BASE_I2_____		_____BASE_D2_____
	_____BASE_I3_____		_____BASE_D3_____
	_____BASE_I4_____		_____BASE_D4_____
  ),

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
        _____ADJUST_I2_____     	_____ADJUST_D2_____
        _____ADJUST_I3_____     	_____ADJUST_D3_____
        _____ADJUST_I4_____       	_____ADJUST_D4_____
  )
 };



