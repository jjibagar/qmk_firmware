#include "jjibagar.h"


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
         case MAGIT:
    if (record->event.pressed) {
      // when keycode QMKBEST is pressed
      SEND_STRING(SS_LCTL("x") SS_TAP(X_M));
    } else {
      // when keycode QMKBEST is released
    }
    return false;
      case KILL:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("x") SS_TAP(X_V));
    }
    return false;
  case ORGPDF:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("ce") SS_TAP(X_P) SS_TAP(X_R));
    }
    return false;
  case OPEN:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("xf"));
    }
    return false;
  case SAVE:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("xs"));
    }
    return false;
  case BUFFER:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("x") SS_TAP(X_N));
    }
    return false;
  case RECENT:
    if (record->event.pressed) {
	SEND_STRING(SS_LCTL("X") SS_TAP(X_Y));
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
