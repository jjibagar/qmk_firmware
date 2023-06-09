#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
//Handeness Config
#define MASTER_RIGHT

//USB Detection Config
#define SPLIT_USB_DETECT
#define SPLIT_WATCHDOG_ENABLE

//Pimoroni Config
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define PIMORONI_TRACKBALL_ADDRESS 0x0A

//I2C Config
#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN 16U
#define I2C1_SCL_PIN 17U

//Pimoroni Adjustments
#define MOUSE_EXTENDED_REPORT
#define POINTING_DEVICE_ROTATION_90

//AutoMouseLayer Config
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 5
#define AUTO_MOUSE_TIME 650

#define WS2812_DI_PIN D3

#ifdef RGB_MATRIX_ENABLE

#define RGBLED_NUM 72
#define RGB_MATRIX_LED_COUNT RGBLED_NUM
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_SPLIT {36,36}
#define SPLIT_TRANSPORT_MIRROR

#endif

#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
#define UNICODE_KEY_LNX LCTL(LSFT(KC_F))

// tienes que personalizar le tapping, bajarlo a 180 los que sean el menique
#define TAPPING_FORCE_HOLD
//#define TAPPING_TERM 200 esto esta metido en le rev1


