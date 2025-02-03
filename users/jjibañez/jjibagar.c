
// esto me da problemas, si no lo quito no compila
// alfred lo tiene en jjibañez.c y en el keymap
#include "jjibagar.h"
//#include "muse.h"
//#include "keymap_spanish_dvorak.h"
//#include "sendstring_spanish_dvorak.h"
//#include "combos.c"



// clang-format on
layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

/********************************************************************************/
/* // Left encoder scrolls the mousewheel. Right encoder adjusts underglow hue. */
/* bool encoder_update_user(uint8_t index, bool clockwise) {		        */
/*     if (index == 0) {						        */
/*         if (clockwise) {						        */
/* #ifdef MOUSEKEY_ENABLE						        */
/*             tap_code(KC_MS_WH_DOWN);					        */
/* #else								        */
/*             tap_code(KC_PGDN);					        */
/* #endif								        */
/*         } else {							        */
/* #ifdef MOUSEKEY_ENABLE						        */
/*             tap_code(KC_MS_WH_UP);					        */
/* #else								        */
/*             tap_code(KC_PGUP);					        */
/* #endif								        */
/*         }								        */
/*     } else {  // index = 1: right encoder				        */
/*         if (clockwise) {						        */
/* #ifdef RGB_MATRIX_ENABLE						        */
/*             rgb_matrix_step();					        */
/* #else								        */
/*             rgblight_increase_hue_noeeprom();			        */
/* #endif								        */
/*         } else {							        */
/* #ifdef RGB_MATRIX_ENABLE						        */
/*             rgb_matrix_step_reverse();				        */
/* #else								        */
/*             rgblight_decrease_hue_noeeprom();			        */
/* #endif								        */
/*         }								        */
/*     }								        */
/*     return false;							        */
/* }									        */
/********************************************************************************/

// Set underglow color to blue. Modificado
#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) { rgblight_sethsv_noeeprom(RGBLIGHT_DEFAULT_COLOR); }
#endif // RGB_MATRIX_ENABLE


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


// Prueba rgb del sofle

#define CUSTOM_FONT

#define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding


#define QUICK_TAP_TERM 0
#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 200
#endif
#define ENCODER_DIRECTION_FLIP


#define RGBLIGHT_SLEEP
//
#define RGBLIGHT_LAYERS

/* ws2812 RGB LED */
#define WS2812_DI_PIN D3


#ifdef RGB_MATRIX_ENABLE
#define RGBLED_NUM 35    // Number of LEDs
#define RGBLED_NUM 35    // Number of LEDs
#define RGB_MATRIX_LED_COUNT RGBLED_NUM
#endif

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM

	//#define RGBLIGHT_EFFECT_BREATHING
	#define RGBLIGHT_EFFECT_RAINBOW_MOOD
	//#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	//#define RGBLIGHT_EFFECT_SNAKE
	//#define RGBLIGHT_EFFECT_KNIGHT
	//#define RGBLIGHT_EFFECT_CHRISTMAS
	//#define RGBLIGHT_EFFECT_STATIC_GRADIENT
	//#define RGBLIGHT_EFFECT_RGB_TEST
	//#define RGBLIGHT_EFFECT_ALTERNATING
	//#define RGBLIGHT_EFFECT_TWINKLE

    #define RGBLED_NUM 70
	//#define RGBLED_SPLIT
	#define RGBLED_SPLIT { 35, 35 } // haven't figured out how to use this yet

	//#define RGBLED_NUM 30
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
#   define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_LEFT_RIGHT

#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10

/* Disable the animations you don't want/need.  You will need to disable a good number of these    *
 * because they take up a lot of space.  Disable until you can successfully compile your firmware. */
 // #   undef ENABLE_RGB_MATRIX_ALPHAS_MODS
 // #   undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
 // #   undef ENABLE_RGB_MATRIX_BREATHING
 // #   undef ENABLE_RGB_MATRIX_CYCLE_ALL
 // #   undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
 // #   undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
 // #   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
 // #   undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
 // #   undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
 // #   undef ENABLE_RGB_MATRIX_DUAL_BEACON
 // #   undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
 // #   undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
 // #   undef ENABLE_RGB_MATRIX_RAINDROPS
 // #   undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
 // #   undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
 // #   undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
 // #   undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
 // #   undef ENABLE_RGB_MATRIX_SPLASH
 // #   undef ENABLE_RGB_MATRIX_MULTISPLASH
 // #   undef ENABLE_RGB_MATRIX_SOLID_SPLASH
 // #   undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
