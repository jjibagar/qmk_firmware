
// esto me da problemas, si no lo quito no compila
// alfred lo tiene en jjibañez.c y en el keymap
#include "jjibagar.h"
//#include "muse.h"
//#include "keymap_spanish_dvorak.h"
//#include "sendstring_spanish_dvorak.h"
//#include "combos.c"





// Left encoder scrolls the mousewheel. Right encoder adjusts underglow hue.
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_DOWN);
#else
            tap_code(KC_PGDN);
#endif
        } else {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
#else
            tap_code(KC_PGUP);
#endif
        }
    } else {  // index = 1: right encoder
        if (clockwise) {
#ifdef RGB_MATRIX_ENABLE
            rgb_matrix_step();
#else
            rgblight_increase_hue_noeeprom();
#endif
        } else {
#ifdef RGB_MATRIX_ENABLE
            rgb_matrix_step_reverse();
#else
            rgblight_decrease_hue_noeeprom();
#endif
        }
    }
    return false;
}

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


