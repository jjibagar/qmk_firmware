
#include QMK_KEYBOARD_H
#include "jjibagar.h"
#include "sendstring_spanish_dvorak.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| MUTE  |    |DISCORD|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE |RAISE | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

  [_BASE] = LAYOUT_split_3x6_4_wrapper(
	_____BASE_I1_____			_____BASE_D1_____
      _____BASE_I1_____			_____BASE_D1_____
	_____BASE_I2_____			_____BASE_D2_____
	_____BASE_I3_____ KC_MUTE,   KC_D_MUTE, _____BASE_D3_____
KC_BSPC,_____BASE_I4_____			_____BASE_D4_____,KC_RALT
  ),

/*   Capa de simbolos (lower)
    |¿?| ! | "  | · | $ | % |
    |& | ()| {} | <>|[] |"|"| 
    |@ | #  | ~ | ^ |   |
*/  
  [_LOWER] = LAYOUT_split_3x6_4_wrapper(
	_____LOWER_I1_____			_____LOWER_D1_____
      _____LOWER_I1_____			_____LOWER_D1_____
	_____LOWER_I2_____	 		_____LOWER_D2_____
	_____LOWER_I3_____ KC_MUTE,   KC_D_MUTE,_____LOWER_D3_____       
KC_BSPC,_____LOWER_I4_____			_____LOWER_D4_____,KC_RALT
  ),  

  [_RAISE] = LAYOUT_split_3x6_4_wrapper(
	_____RAISE_I1_____			_____RAISE_D1_____
      _____RAISE_I1_____			_____RAISE_D1_____
	_____RAISE_I2_____			_____RAISE_D2_____
	_____RAISE_I3_____KC_MUTE,   KC_D_MUTE,_____RAISE_D3_____
KC_BSPC,_____RAISE_I4_____			_____RAISE_D4_____,KC_RALT
  ),

  [_ADJUST] = LAYOUT_split_3x6_4_wrapper(
        _____ADJUST_I1_____			_____ADJUST_D1_____
      _____ADJUST_I1_____			_____ADJUST_D1_____
        _____ADJUST_I2_____		     	_____ADJUST_D2_____
        _____ADJUST_I3_____KC_MUTE,   KC_D_MUTE,_____ADJUST_D3_____
KC_BSPC,_____ADJUST_I4_____		      	_____ADJUST_D4_____,KC_RALT
      ),

  [_EMACS] = LAYOUT_split_3x6_4_wrapper(
      _____EMACS_I1_____		 _____EMACS_D1_____
      _____EMACS_I1_____		 _____EMACS_D1_____
      _____EMACS_I2_____	 	 _____EMACS_D2_____
      _____EMACS_I3_____KC_MUTE, KC_MUTE,_____EMACS_D3_____
KC_BSPC,_____EMACS_I4_____     	         _____EMACS_D4_____,KC_RALT
      ),
  [_NUM] = LAYOUT_split_3x6_4_wrapper(
	_____NUM_I1_____		_____NUM_D1_____
      _____NUM_I1_____		_____NUM_D1_____
	_____NUM_I2_____		_____NUM_D2_____    
	_____NUM_I3_____KC_MUTE, KC_MUTE,_____NUM_D3_____    
KC_BSPC,_____NUM_I4_____		 _____NUM_D4_____,KC_RALT
      ),
  [_JUEGOS] = LAYOUT_split_3x6_4_wrapper(
	_____JUEGOS_I1_____		_____JUEGOS_D1_____
      _____JUEGOS_I1_____		_____JUEGOS_D1_____
	_____JUEGOS_I2_____		_____JUEGOS_D2_____
	_____JUEGOS_I3_____KC_MUTE,KC_MUTE,_____JUEGOS_D3_____
KC_BSPC,_____JUEGOS_I4_____		_____JUEGOS_D4_____,KC_RALT
     )
};      
      
