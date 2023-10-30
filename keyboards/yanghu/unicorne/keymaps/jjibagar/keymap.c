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

//#include QMK_KEYBOARD_H
// en layers.h estan los nombres de capa _qwerty se llama _base
//#include "layers.h"
//#include "keymap_spanish_dvorak.h"
//#include "sendstring_spanish_dvorak.h"
#include "combos.c"
//#include "jjibagar.h"


/* / Tap Dance keycodes
enum td_keycodes {
    ALT_LP, // Our example key: LALT when held, ( when tapped. Add additional keycodes for each tapdance.
    CTRL_LP,
    LSFT_LP
};
*/

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

// finished and reset functions for each tapdance keycode
void alt_lp_finished(tap_dance_state_t *state, void *user_data);
void alt_lp_reset(tap_dance_state_t *state, void *user_data);
void ctrl_lp_finished(tap_dance_state_t *state, void *user_data);
void ctrl_lp_reset(tap_dance_state_t *state, void *user_data);




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



td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if ( !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}
// Handle the possible states for each tapdance keycode you define:_:?¿?¿

void alt_lp_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(DV_QUES);
            break;
        case TD_SINGLE_HOLD:
            register_code16(KC_LALT);
            break;	           
        case TD_DOUBLE_SINGLE_TAP:         
            register_code16(DV_IQUE);
            break;
    case TD_UNKNOWN:
	break;

    }
}
void alt_lp_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(DV_QUES);
            break;
        case TD_SINGLE_HOLD:
            unregister_code16(KC_LALT);
            break;	           
        case TD_DOUBLE_SINGLE_TAP:         
            unregister_code16(DV_IQUE);
            break;
    case TD_UNKNOWN:
	break;
	    }
}
void ctrl_lp_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP:
            register_code16(DV_AMPR);
            break;
        case TD_SINGLE_HOLD:
            register_code16(KC_LCTL);
            break;	           
        case TD_DOUBLE_SINGLE_TAP:         
            register_code16(DV_BULT);
            break;
    case TD_UNKNOWN:
	break;

    }
}
void ctrl_lp_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP:
            unregister_code16(DV_AMPR);
            break;
        case TD_SINGLE_HOLD:
            unregister_code16(KC_LCTL);
            break;	           
        case TD_DOUBLE_SINGLE_TAP:         
            unregister_code16(DV_BULT);
            break;
    case TD_UNKNOWN:
	break;
	    }
}
// Tap Dance definitions 
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for , twice for ; y lo mismo para el . y los : 
  [TD_PTO] = ACTION_TAP_DANCE_DOUBLE(DV_DOT, LSFT(DV_DOT)),
  [TD_PC] = ACTION_TAP_DANCE_DOUBLE(DV_COMM, LSFT(DV_COMM)),
  [TD_GUION]= ACTION_TAP_DANCE_DOUBLE(DV_MINS, LSFT(DV_MINS)),  // se pulsa una vez es un guion. si se pulsa 2 veces guion+shft  
  [TD_COPY]= ACTION_TAP_DANCE_DOUBLE(DV_Q, KC_COPY), //
  [TD_PASTE]= ACTION_TAP_DANCE_DOUBLE(DV_Y, KC_PASTE),
//simbolos lower
  [TD_INTE]=ACTION_TAP_DANCE_DOUBLE(DV_QUES, DV_IQUE),
  [TD_EXCL]=ACTION_TAP_DANCE_DOUBLE(DV_EXLM,DV_IEXL),
  [TD_CORCH]=ACTION_TAP_DANCE_DOUBLE(DV_LBRC,DV_RBRC),
  [TD_LLAVE]=ACTION_TAP_DANCE_DOUBLE(DV_LCBR,DV_RCBR),
  [TD_PAREN]=ACTION_TAP_DANCE_DOUBLE(DV_LPRN,DV_RPRN),
  [TD_MAYOR]=ACTION_TAP_DANCE_DOUBLE(DV_LABK,DV_RABK),
  [TD_BIRG]=ACTION_TAP_DANCE_DOUBLE(DV_TILD,DV_CIRC),
  [ALT_LP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_lp_finished, alt_lp_reset),
  [CTRL_LP]=ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctrl_lp_finished, ctrl_lp_reset)
};

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);


// clang-format on
layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

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


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
  
#ifdef OLED_DRIVER_ENABLE
        oled_timer = timer_read32();
#endif
    // set_timelog();
  }
switch (keycode) {
        case ALTGR_ONE_SHOT:
          if (record->event.pressed) {
              set_oneshot_mods(MOD_BIT(KC_RALT));
       } 
       return false;
         case MACRO1:
    if (record->event.pressed) {
      SEND_STRING("Jose Jorge Ibañez Garcia");  
							
        } else {
            
        }
        return false;
         case MACRO2:
    if (record->event.pressed) {
            SEND_STRING("");
        } else {
            
        }
        return false;
	 case MACRO3:
    if (record->event.pressed) {     
      SEND_STRING("<4163aX>\n");
        } else {
            
        }
        return false;
	  case MACRO4:
    if (record->event.pressed) {
      SEND_STRING("");
        } else {
            
        }
        return false;
	  case MACRO5:
    if (record->event.pressed) {
      SEND_STRING("");
        } else {
            
        }
        return false;
	    case UNICODE:
      if (record->event.pressed) {
        send_unicode_string("1F440");
        return false;
      }
              case UPARROW:
    if (record->event.pressed) {
      SEND_STRING("\\uparrow");
        } else {
        }
     return false;
            case DOWNARROW:
    if (record->event.pressed) {
      SEND_STRING("\\downarrow");
        } else {
        }
     return false;
        case RIGTHARROW:
    if (record->event.pressed) {
      SEND_STRING("\\rightarrow");
        } else {
        }
     return false;
            case LEFTARROW:
    if (record->event.pressed) {
      SEND_STRING("\\leftarrow");
        } else {
        }
       return false;
            case TAURUS:
    if (record->event.pressed) {
      SEND_STRING("\\Taurus");
        } else {
        }
    return false;
    // aqui pongo varias formas de mostrar los acentos, con unicode y con pulsacioes, en este ultimo aoeui es asdfg
    case TIL_A:
            if (record->event.pressed) {
                 SEND_STRING(SS_TAP(X_QUOT)SS_TAP(X_A));
            }        
            return false;
    case TIL_O:
            if (record->event.pressed) {
                 SEND_STRING(SS_TAP(X_QUOT)SS_TAP(X_S));
            }        
            return false; 
    case TIL_E:
            if (record->event.pressed) {
                send_unicode_string("\u00e9");
            }        
            return false;
    case TIL_U:
            if (record->event.pressed) {
                 send_unicode_string("ú");
            }        
            return false;
    case TIL_I:
            if (record->event.pressed) {
                 SEND_STRING(SS_TAP(X_QUOT)SS_TAP(X_G));
            }        
            return false;       
      #ifdef RGB_MATRIX_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
          rgb_matrix_enable();
        }
      #endif
      break;
  }
  return true;
}
