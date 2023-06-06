

#include QMK_KEYBOARD_H
#include "version.h"
// #include "keymap_spanish.h"
#include "keymap_spanish_dvorak.h"
#include "sendstring_spanish_dvorak.h"


// creo que no vale para nada
extern keymap_config_t keymap_config;


//hasta aqui

// compilar con→ qmk compile -kb lily58/light -km levo
enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};



// Custom keycodes for layer keys
// Dual function escape with left command podemos podemos hacer como la cosa se escribe asi jajajajaja que bien


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST, 
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
  ALT_TAB = SAFE_RANGE
};

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

enum unicode_names {
    BANG,
    IRONY,
    SNEK
};

/* PARA DECLARAR LAS VARIABLES DE UNICODE MAP SE USA CON X(BANG)
const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮ 
    [SNEK]  = 0x1F40D, // 🐍
    }; */
// declaraciones unicode, en case essta otraforwa de meterlos 
#define STAR 0x2605 
#define FLECHA_AR 0x21A5
#define FLECHA_I 0x21A4
#define FLECHA_D 0x21A6
#define FLECHA_AB 0x21A7



//#define ALT_TAB LALT(KC_TAB)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |.td(:)|,Td(;)|   Ñ  |   P  |   Y  |                    |   F  |   G  |   C  |   H  |   H  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   R  |   T  |   N  |   S  |  '   |
 * |------+------+------+------+------+------|   <   |    |    >  |------+------+------+------+------+------| 
 * |LShift|   -  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |RShift|
 * |tdcaps|      |      |      |      |      |       |    |       |      |      |      |      |      |tdcaps|LT(_RAISE,KC_BSPC)
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
KC_ESC,      KC_1,    KC_2,   KC_3, KC_4,    KC_5,                           KC_6, KC_7, KC_8,     KC_9,      KC_0,    KC_GRV,
LALT_T(KC_TAB), TD(TD_PTO), TD(TD_PC),KC_E, KC_R,TD(TD_PASTE),               KC_Y, KC_U, DV_C,     DV_H,      DV_L,    KC_MINS,
KC_LCTL,LGUI_T(DV_A),LALT_T(DV_O),LCTL_T(DV_E),LSFT_T(DV_U), DV_I,    DV_D,RSFT_T(DV_R),RCTL_T(DV_T),LALT_T(DV_N),RGUI_T(DV_S), KC_QUOT,
LSFT_T(KC_CAPS),TD(TD_GUION),TD(TD_COPY),  DV_J,DV_K,  DV_X,   DV_LABK,   DV_RABK,DV_B,KC_M,KC_COMM,KC_DOT,KC_SLSH,RSFT_T(KC_CAPS),
                                 KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,     KC_ENT,KC_BSPC, _RAISE, KC_RALT
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   F1 |  F2  |  F3  |  F4  |  F5  |  F6  |                    |      |      |      |  7   |   8  |   9  | 
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   F7 |  F8  |  F9  | F10  | F11  | F12  |                    |      |  Up  |      |  4   |   5  |   6  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F13 | F14  |  ↥   | F15  | F16  | F17  |-------.    ,-------|  Left| Down | Right|  1   |   2  |   3  |  
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | F18  |  ↤   |   ↧  | ↦    |  ツ  |  ★   |-------|    |-------|   +  |  -   |   *  |   /  |   0  |   =  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |DELETE| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 * aqui e puesto las disntintas formas de añadir codigos unicode */
[_LOWER] = LAYOUT(
     KC_F1,   KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,                        _______, _______, _______,  KC_P7,    KC_P8,    KC_P9,
     KC_F7,   KC_F8,     KC_F9,   KC_F10,  KC_F11,  KC_F12,                         _______,  KC_UP , _______,  KC_P4,    KC_P5,    KC_P6,
  _______,  KC_F14,UC(FLECHA_AR), KC_F15,  KC_F16,  KC_F17,                      KC_LEFT, KC_DOWN, KC_RGHT,  KC_P1,    KC_P2,    KC_P3,
 _______,UC(FLECHA_I),UC(FLECHA_AB), UC(FLECHA_D), UC(L'ツ'), UC(STAR), DV_LBRC, DV_RBRC,DV_PLUS, DV_MINS,DV_ASTR,DV_SLSH, KC_P0,DV_EQL,
                             _______, _______, _______, _______, _______,  _______, KC_DEL, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |Macro4|Macro1| 
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ¿  |   ?  |   ¡  |   !  |      |                    |      | Pag↑ |      |Imprim|Macro5|Macro2|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|  Ini | Pag↓ | FIN  |      |Right |Macro3|
 * |------+------+------+------+------+------|   {   |    |    }  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /INSERT /       \Enter \  |RAISE |BackSP| RGUI | 
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, MACRO4, MACRO1,
  XXXXXXX, DV_IQUE, DV_QUES, DV_IEXL, DV_EXLM, XXXXXXX,                  XXXXXXX,  KC_PGUP, XXXXXXX, KC_PSCR, MACRO5, MACRO2,
  XXXXXXX, TAURUS,  UPARROW, XXXXXXX, XXXXXXX, XXXXXXX,                  KC_HOME,  KC_PGDN, KC_END, XXXXXXX, XXXXXXX,MACRO3,
  XXXXXXX,LEFTARROW,DOWNARROW,RIGTHARROW,XXXXXXX, XXXXXXX,DV_LCBR ,   DV_RCBR, KC_PLUS, KC_MINS,KC_EQL, KC_LBRC, KC_RBRC, XXXXXXX,
                             _______, _______, _______,  KC_INS, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | sys↓ |      |      |      |      |      |                    | Prev | Stop | Play | Next |plyer | MUTE |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |brwser|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    | Reset |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  KC_PWR, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                   KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_MSEL, KC_MUTE,
  QK_BOOT, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_TOG,                   XXXXXXX,XXXXXXX,XXXXXXX ,XXXXXXX , XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KB_VOLUME_UP,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  , QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KB_VOLUME_DOWN,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};
// BL_TOGG	Turn the backlight on or off
// BL_STEP	Cycle through backlight levels
// BL_ON 	Set the backlight to max brightness
// BL_OFF 	Turn the backlight off
// BL_INC 	Increase the backlight level   uaoetur
// BL_DEC 	Decrease the backlight level
// BL_BRTG

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for , twice for ; y lo mismo para el . y los : 
  [TD_PC] = ACTION_TAP_DANCE_DOUBLE(DV_COMM, LSFT(DV_COMM)),
  [TD_PTO] = ACTION_TAP_DANCE_DOUBLE(DV_DOT, LSFT(DV_DOT)),
  [TD_GUION]= ACTION_TAP_DANCE_DOUBLE(DV_MINS, LSFT(DV_MINS)),  // se pulsa uuna vez es un guion. si se pulsa 2 veces guion+shft
  [TD_COPY]= ACTION_TAP_DANCE_DOUBLE(DV_Q, KC_COPY), //
  [TD_PASTE]= ACTION_TAP_DANCE_DOUBLE(DV_Y, KC_PASTE)
  
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// este bloque lo he descomentado
const char *read_mode_icon(bool swap);
const char *read_host_led_state(void);
void set_timelog(void);
const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE


// prueba RGB

// dessde aquui


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

bool rgb_matrix_indicators_user(void){
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
     /*  for (int i = 0; i < DRIVER_LED_TOTAL; i++) { */
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
       return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
         case MACRO1:
    if (record->event.pressed) {
      SEND_STRING("nombre");  
							
        } else {
            
        }
        return false;
         case MACRO2:
    if (record->event.pressed) {
            SEND_STRING("dni");
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
      SEND_STRING("numero");
        } else {
            
        }
        return false;
	  case MACRO5:
    if (record->event.pressed) {
      SEND_STRING("numero");
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


#ifdef RGB_MATRIX_ENABLE

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   5, NO_LED, NO_LED,   0 },
  { NO_LED, NO_LED, NO_LED, NO_LED },
  {   4, NO_LED, NO_LED,   1 },
  {   3, NO_LED, NO_LED,   2 }
}, {
  // LED Index to Physical Position
	{ 188,  16 }, { 187,  48 }, { 149,  64 }, { 112,  64 }, {  37,  48 }, {  38,  16 }
}, {
  // LED Index to Flag
	1, 4, 4, 4, 4, 1
} };


/* led_config_t g_led_config = { { */
/*     // Key matrix to LED index */
/*     // Left 1-18 */
/*             {17, 12, 11,  6,  5}, */
/*             {16, 13, 10,  7,  4}, */
/*             {15, 14,  9,  8,  3}, */
/*     {NO_LED, NO_LED,  2,  1,  0}, */
/*                                     // Right 1-18 */
/*                                     {23, 24, 29, 30, 35}, */
/*                                     {22, 25, 28, 31, 34}, */
/*                                     {21, 26, 27, 32, 33}, */
/*                                     {18, 19, 20, NO_LED, NO_LED}, */
/* }, { */
/*     // LED index to physical position */
/*     // Left 1-18 */
/*     {122,85},{102,85},{81,85},{102,64},{102,43},{102,21}, */
/*     {81,21},{81,43},{81,64},{61,64},{61,43},{61,21}, */
/*     {41,21},{41,43},{41,64},{20,64},{20,43},{20,21}, */
/*     // Right 1-18 */
/*     {143,85},{163,85},{183,85},{163,64},{163,43},{163,21}, */
/*     {183,21},{183,43},{183,64},{204,64},{204,43},{204,21}, */
/*     {224,21},{224,43},{224,64},{244,64},{244,43},{244,21} */
/* }, { */
/*     // LED index to flag */
/*     // Left 1-18 */
/*     4,4,4,4,4,4, */
/*     4,4,4,4,4,4, */
/*     4,4,4,4,4,4, */   
/*     // Right 1-18 */
/*     4,4,4,4,4,4, */
/*     4,4,4,4,4,4, */
/*     4,4,4,4,4,4 */
/* } }; */
#endif

