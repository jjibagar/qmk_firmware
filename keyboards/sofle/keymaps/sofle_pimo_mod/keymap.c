#include QMK_KEYBOARD_H

#include "features/pimoroni.h"
#include "features/enums.h"

#include "features/encoders.h"
#include "keymap_spanish_dvorak.h"
#include "sendstring_spanish_dvorak.h"

enum combos {
  CB_ALTGR_ONE_SHOT,
  CB_DVK_TIL_A,
  CB_DVK_TIL_O,
  CB_DVK_TIL_E,
  CB_DVK_TIL_U,
  CB_DVK_TIL_I,
  COMBO_LENGTH
};


uint16_t COMBO_LEN = COMBO_LENGTH;

// Combo funcionts
const uint16_t PROGMEM altg_oneshot[] = {DV_I, DV_D, COMBO_END};
const uint16_t PROGMEM dvk_a_til_combo[] = {DV_A, RSFT_T(DV_R), COMBO_END};
const uint16_t PROGMEM dvk_o_til_combo[] = {LALT_T(DV_O), RSFT_T(DV_R), COMBO_END};
const uint16_t PROGMEM dvk_e_til_combo[] = {LCTL_T(DV_E), RSFT_T(DV_R), COMBO_END};
const uint16_t PROGMEM dvk_u_til_combo[] = {LSFT_T(DV_U), RSFT_T(DV_R), COMBO_END};
const uint16_t PROGMEM dvk_i_til_combo[] = {DV_I, RSFT_T(DV_R), COMBO_END};


combo_t key_combos[] = {

  [CB_ALTGR_ONE_SHOT] = COMBO(altg_oneshot, ALTGR_ONE_SHOT ),
  [CB_DVK_TIL_A] = COMBO(dvk_a_til_combo, TIL_A ),
  [CB_DVK_TIL_O] = COMBO(dvk_o_til_combo, TIL_O ),
  [CB_DVK_TIL_E] = COMBO(dvk_e_til_combo, TIL_E ),
  [CB_DVK_TIL_U] = COMBO(dvk_u_til_combo, TIL_U),
  [CB_DVK_TIL_I] = COMBO(dvk_i_til_combo, TIL_I ),

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_QWERTY] = LAYOUT(
KC_ESC,      KC_1,    KC_2,   KC_3, KC_4,    KC_5,                           KC_6, KC_7, KC_8,     KC_9,      KC_0,    KC_GRV,
LALT_T(KC_TAB), TD(TD_PTO), TD(TD_PC),KC_E, KC_R,TD(TD_PASTE),               KC_Y, KC_U, DV_C,     DV_H,      DV_L,    KC_MINS,
KC_LCTL,LGUI_T(DV_A),LALT_T(DV_O),LCTL_T(DV_E),LSFT_T(DV_U), DV_I,    DV_D,RSFT_T(DV_R),RCTL_T(DV_T),LALT_T(DV_N),RGUI_T(DV_S), KC_QUOT,
LSFT_T(KC_CAPS),TD(TD_GUION),TD(TD_COPY),DV_J,DV_K,  DV_X,KC_MUTE,   XXXXXXX,DV_B,KC_M,KC_COMM,KC_DOT,KC_SLSH,RSFT_T(KC_CAPS),
                     KC_LGUI,KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,     KC_ENT,KC_BSPC,_RAISE, KC_RALT,KC_RGUI
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAK] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
  KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,      XXXXXXX,KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTL,MO(_LOWER), KC_ENT,        KC_SPC,  _RAISE, KC_RCTL, KC_RALT, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
     KC_F1,   KC_F2,      KC_F3,   KC_F4,   KC_F5,   KC_F6,                        _______, _______, _______,  KC_P7,    KC_P8,    KC_P9,
     KC_F7,   KC_F8,     KC_F9,   KC_F10,  KC_F11,  KC_F12,                         _______,  KC_UP , _______,  KC_P4,    KC_P5,    KC_P6,
  _______,  KC_F14,UC(FLECHA_AR), KC_F15,  KC_F16,  KC_F17,                      KC_LEFT, KC_DOWN, KC_RGHT,  KC_P1,    KC_P2,    KC_P3,
     _______,UC(FLECHA_I),UC(FLECHA_AB), UC(FLECHA_D), UC(L'ツ'), _______, _______,_______, DV_PLUS, DV_MINS,DV_ASTR,DV_SLSH, KC_P0,DV_EQL,
                           DV_LBRC, _______, _______, _______, _______,   _______,  _______, KC_DEL, _______,DV_RBRC
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, MACRO4, MACRO1,
  XXXXXXX, DV_IQUE, DV_QUES, DV_IEXL, DV_EXLM, XXXXXXX,                   XXXXXXX,  KC_PGUP, XXXXXXX, KC_PSCR, MACRO5, MACRO2,
  XXXXXXX, TAURUS,  UPARROW, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME,  KC_PGDN, KC_END, XXXXXXX, XXXXXXX,MACRO3,
  XXXXXXX,LEFTARROW,DOWNARROW,RIGTHARROW,XXXXXXX, XXXXXXX,XXXXXXX ,  XXXXXXX, KC_PLUS, KC_MINS,KC_EQL, KC_LBRC, KC_RBRC, XXXXXXX,
                      DV_LCBR, _______, _______, _______,  KC_INS, _______,  _______, _______, _______,DV_RCBR
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QK_BOOT|    |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      | Quito esto
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------| KC_COLEMAK 
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|CG_TOGG
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  KC_PWR, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                   KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_MSEL, KC_MUTE,
  QK_BOOT, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_TOG,                   XXXXXXX,XXXXXXX,XXXXXXX ,XXXXXXX , XXXXXXX, XXXXXXX,
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KB_VOLUME_UP,
  TAURUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KB_VOLUME_DOWN,
                    _______, _______, _______, _______, _______, _______,  _______, _______, _______,_______
   ),
   [_MOUSE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                       SCROLL, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};


// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for , twice for ; y lo mismo para el . y los : 
  [TD_PC] = ACTION_TAP_DANCE_DOUBLE(DV_COMM, LSFT(DV_COMM)),
  [TD_PTO] = ACTION_TAP_DANCE_DOUBLE(DV_DOT, LSFT(DV_DOT)),
  [TD_GUION]= ACTION_TAP_DANCE_DOUBLE(DV_MINS, LSFT(DV_MINS)),  // se pulsa uuna vez es un guion. si se pulsa 2 veces guion+shft
  [TD_COPY]= ACTION_TAP_DANCE_DOUBLE(DV_Q, KC_COPY), //
  [TD_PASTE]= ACTION_TAP_DANCE_DOUBLE(DV_Y, KC_PASTE)
};


#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        case SCROLL:
            if (record->event.pressed){
                scrolling_mode = true;
                pointing_device_set_cpi(2000);
            } else {
                scrolling_mode = false;
                pointing_device_set_cpi(15000);
            }
            return false;
	     case TAURUS:
    if (record->event.pressed) {
      SEND_STRING("\\Taurus");
    } else {}
    }
    return true;
}



#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void){
  
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

  return true;
}
#endif
