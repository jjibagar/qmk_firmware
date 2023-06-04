/* Copyright 2021 Yang Hu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any !"·$%%!!"·$%!"·$!"·%?¿^*Ç!"·$%?¿^*Ç
?¿^*Ç*++++``
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of   
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *Ç*^¿??.ñ,pyyyp.ggg777131313++++++++ * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.Cambio la T->A
 */

#include QMK_KEYBOARD_H
// en layers.h estan los nombres de capa _qwerty se llama _base
#include "layers.h"
#include "keymap_spanish_dvorak.h"
#include "sendstring_spanish_dvorak.h"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

enum {
    TD_PC,
    TD_COMI,
    TD_SLA,
    TD_CAPLOCK,
    TD_PTO,
    TD_GUION,
    TD_COPY,
    TD_PASTE
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE, 
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
  ALTGR_ONE_SHOT
};

enum combos {
  CB_ALTGR_ONE_SHOT,
  COMBO_LENGTH
};


uint16_t COMBO_LEN = COMBO_LENGTH;

// Combo funcionts
const uint16_t PROGMEM altg_oneshot[] = {DV_I, DV_D, COMBO_END};

combo_t key_combos[] = {

  [CB_ALTGR_ONE_SHOT] = COMBO(altg_oneshot, ALTGR_ONE_SHOT ),

};




// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_4(
 LALT_T(KC_TAB), TD(TD_PTO),TD(TD_PC),KC_E,KC_R,TD(TD_PASTE),             KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_GRV,
 LCTL_T(KC_ESC), DV_A, LALT_T(DV_O),LCTL_T(DV_E),LSFT_T(DV_U), DV_I,     DV_D, RSFT_T(DV_R),RCTL_T(DV_T),LALT_T(DV_N),KC_SCLN,KC_QUOT ,
 LSFT_T(KC_CAPS),TD(TD_GUION),TD(TD_COPY),KC_C, KC_V, KC_B,             KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
                 KC_LGUI, KC_LALT, LOWER,KC_SPC,                         KC_ENT,KC_BSPC, RAISE, KC_RALT
  ),

  [_LOWER] = LAYOUT_split_3x6_4(
    _______,  DV_IQUE,  DV_QUES,  DV_IEXL,  DV_EXLM,   DV_PIPE,            KC_CIRC,  KC_UP,  _______,  KC_P7, KC_P8,  KC_P9,
    _______,  DV_LBRC,  DV_LABK,  DV_LCBR,  DV_RCBR,   DV_HASH,            KC_LEFT,  KC_DOWN,KC_RGHT,  KC_P4, KC_P5,  KC_P6,
    _______,  _______, _______,   _______,  DV_PLUS,   DV_MINS,            DV_ASTR,  DV_SLSH, DV_EQL,  KC_P1, KC_P2,  KC_P3,
                    _______,  _______,  _______,   _______,                       _______,  KC_DEL ,   _______,  KC_P0
  ),  

  [_RAISE] = LAYOUT_split_3x6_4(
    _______,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               _______,  KC_PGUP, _______,_______,  _______,  _______,
    _______,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,               KC_HOME,  KC_PGDN, KC_END, _______,  _______,  _______,
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                 KC_F7,  KC_F8,    KC_F9,  KC_F10,   KC_F11,  KC_F12,
                     _______,  _______,   _______,   KC_INS,               _______,   _______,   _______,  _______
  ),

  [_ADJUST] = LAYOUT_split_3x6_4(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MACRO1,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MACRO2,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,          RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MACRO3,
                   _______,  _______,   _______,   _______,              _______,   _______,   _______,  _______
  )
 };

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for , twice for ; y lo mismo para el . y los : 
  [TD_PC] = ACTION_TAP_DANCE_DOUBLE(DV_COMM, LSFT(DV_COMM)),
  [TD_PTO] = ACTION_TAP_DANCE_DOUBLE(DV_DOT, LSFT(DV_DOT)),
  [TD_GUION]= ACTION_TAP_DANCE_DOUBLE(DV_MINS, LSFT(DV_MINS)),  // se pulsa uuna vez es un guion. si se pulsa 2 veces guion+shft  
  [TD_COPY]= ACTION_TAP_DANCE_DOUBLE(DV_Q, KC_COPY), //
  [TD_PASTE]= ACTION_TAP_DANCE_DOUBLE(DV_Y, KC_PASTE)
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

void rgb_matrix_indicators_user(void) {
  #ifdef RGB_MATRIX_ENABLE
  switch (biton32(layer_state)) {
    case _RAISE:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
          rgb_matrix_set_color(i, 255, 0, 0);
      }
      break;

     case _LOWER:
      for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
         rgb_matrix_set_color(i, 0, 0, 255);
      }
      break;
     /* case _ADJUST: */
     /*  for (int i = 0; i < DRIVER_LED_TOTAL; i++) { */
     /*     rgb_matrix_set_color(i, 20, 0, 0); */
      /* } */
      /* break; */
    default:
        if (host_keyboard_led_state().caps_lock) {
                  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
          rgb_matrix_set_color(i, 0, 255, 0);
        } 
       } else {
        for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
          rgb_matrix_set_color(i, 0, 0, 0);
       }       
    } 
  }
  #endif
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
            SEND_STRING("23029594Q");
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
      SEND_STRING("5489133150712709");
        } else {
            
        }
        return false;
	  case MACRO5:
    if (record->event.pressed) {
      SEND_STRING("ES79 0073 0100 5206 5217 6501");
        } else {
            
        }
        return false;
	    case UNICODE:
      if (record->event.pressed) {
        send_unicode_hex_string("1F440");
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


