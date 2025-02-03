#include "jjibagar.h"
#include "/home/levo/Dropbox/Documentos/QMK_nombres/datos.h"

bool is_alt_tab_active=false;
 

uint16_t alt_tab_timer=0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {

// esto el sofle no se lo traga si lo comento puedo tener activado el oled
//#ifdef OLED_ENABLE
      //  set_keylog(keycode, record);
//#endif
  
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
       // atajas emacs
case MAGIT:
    if (record->event.pressed) {
      // when keycode QMKBEST is pressed
      SEND_STRING(SS_LCTL("x") SS_TAP(X_M));
    } else {
      // when keycode QMKBEST is released
    }
    return false;
case AVY_LINE:
    if (record->event.pressed) {
      // when keycode QMKBEST is pressed 
	    SEND_STRING(SS_LCTL("c") SS_TAP(X_V));
    } else {
      // when keycode QMKBEST is released
    }
    return false;
case COMPLETADO:
    if (record->event.pressed) {
      // when keycode QMKBEST is pressed 
	    SEND_STRING(SS_LCTL("C") SS_TAP(X_D) SS_TAP(X_Y));
    } else {
      // when keycode QMKBEST is released
    }
    return false;

    // prueba de hacer el salto de linea
case SALTO:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("em"));
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
      // SEND_STRING("å"); // debe ser algo asi, no es lo mismo C-x b cambia buffer normal y å lo tengo puesto para counsel con previsualizacion
//SEND_STRING("å");
    }
    return false;
  case RECENT:
    if (record->event.pressed) {
	SEND_STRING(SS_LCTL("X") SS_TAP(X_Y));
    }
    return false;
   /* case TAB:  */
   /*     if (record->event.pressed) { */
   /* 	   register_code(KC_LALT); */
   /* 	   register_code(KC_TAB); */
   /*     } else { */
   /* 	   unregister_code(KC_TAB); */
   /* 	   unregister_code(KC_LALT); */
   /*     } */
   /*     return false; */

case TAB:
          if (record->event.pressed) {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
		register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
/* // continuacion de la funcion tab */
/* if (is_alt_tab_active) { */
/*     if (timer_elapsed(alt_tab_timer) > 200) { */
/*       unregister_code(KC_LALT); */
/*       is_alt_tab_active = false; */
/*     } */
/*   } */

// las V son para dividir ventanas en emacs
  case V1:
    if (record->event.pressed) {
	SEND_STRING(SS_LCTL("X") SS_TAP(X_1));
    }
    return false;
    case V2:
    if (record->event.pressed) {
	SEND_STRING(SS_LCTL("X") SS_TAP(X_2));
    }
    return false;
  case V3:
    if (record->event.pressed) {
	SEND_STRING(SS_LCTL("X") SS_TAP(X_3));
    }
    return false;
  case V0:
    if (record->event.pressed) {
	SEND_STRING(SS_LCTL("X") SS_TAP(X_0));
    }
    return false;
      case ACE_W:
    if (record->event.pressed) {
	SEND_STRING(SS_LCTL("X") SS_TAP(X_S));
    }
    return false;
    //MACROS
    return false;
         case MACRO1:
    if (record->event.pressed) {
      SEND_STRING(nombre);
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
      SEND_STRING(clave);
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

void matrix_scan_user(void) { // The very important timer.

  /* layer_lock_task(); */
  /* caps_word_task(); */

  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }

};

