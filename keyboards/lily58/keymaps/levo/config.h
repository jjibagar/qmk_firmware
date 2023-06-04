
#pragma once

/* Select hand configuration */
#define MASTER_LEFT
// se pone el master left si es el que mas se usa 
// #define MASTER_RIGHT
//#define EE_HANDS //cuidado que lo has cambiado 


// tienes que personalizar le tapping, bajarlo a 180 los que sean el meñique
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

// oneshotex
#define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

//prevent normal rollover
#define IGNORE_MOD_TAP_INTERRUPT

// #define SPLIT_TRANSPORT_MIRROR // cuidado que lo has cambiado 
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE



#define DRIVER_LED_TOTAL 58
#define DRIVER_COUNT 2


 // Enable Caps Lock indicator using backlight (for keyboards without dedicated LED)
/*
#define BACKLIGHT_BREATHING 	// Not defined 	Enable backlight breathing, if supported
#define BREATHING_PERIOD 	6 //	The length of one backlight “breath” in seconds
#define BACKLIGHT_ON_STATE 	1 //	The state of the backlight pin when the backlight is “on” - 1 for high, 0 for low
#define BACKLIGHT_LIMIT_VAL 	255 //	The maximum duty cycle of the backlight – 255 allows for full brightness, any lower will decrease the maximus
#define BACKLIGHT_DEFAULT_LEVEL 	BACKLIGHT_LEVELS //	The default backlight level to use upon clearing the EEPROM
#define BACKLIGHT_DEFAULT_BREATHING
*/




#define UNICODE_SELECTED_MODES UC_LNX
#define UNICODE_KEY_LNX LCTL(LSFT(KC_F))
