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



// Set underglow color to blue.
void keyboard_post_init_user(void) { rgblight_sethsv_noeeprom(RGBLIGHT_DEFAULT_COLOR); }


// prueba RGB
// dessde aqui

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {

   //    set_unicode_input_mode(UC_LNX); 
      
}

bool rgb_matrix_indicators_user(void) {
  #ifdef RGB_MATRIX_ENABLE
  switch (biton32(layer_state)) {
    case _RAISE:
      for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
          rgb_matrix_set_color(i, 255, 0, 0);
      }
      return true;
     case _LOWER:
      for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
	  rgb_matrix_set_color(i, 0, 0, 255);
      }
       return true;
     /* case _ADJUST: */
     /*  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) { */
     /*     rgb_matrix_set_color(i, 20, 0, 0); */
      /* } */
      /* break; */
    default:
        if (host_keyboard_led_state().caps_lock) {
                  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
          rgb_matrix_set_color(i, 0, 255, 0);
		  } 
       } else {
        for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
          rgb_matrix_set_color(i, 0, 0, 0);
       }
	return true;
    } 
  } 
  #endif
  return true;
}

// FIN DE PRUEBA RGB

     
