#include "jjibagar.h"
#include "/home/levo/Dropbox/Documentos/QMK_nombres/datos.h"
// #includo "sendstring_spanish_dvorak.h"
#include "send_string_spanish_dvorak.c"
bool is_alt_tab_active = false;

uint16_t alt_tab_timer = 0;

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
        case JUEGOS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_JUEGOS);
            }

            return false;
            break;
        case BASE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE);
            }
            return false;
            break;
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
                //	    SEND_STRING(SS_LCTL("c") SS_TAP(X_V));
                register_code(KC_LCTL);   // Mantener Ctrl presionado
                tap_code(DV_C);           // Enviar C
                unregister_code(KC_LCTL); // Liberar Ctrl
                wait_ms(40);              // Esperar 40 ms si es necesario
                tap_code(DV_K);           // Enviar V
            } else {
                // when keycode QMKBEST is released
            }
            return false;
        case COMPLETADO: // este caso no se para que es
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING(SS_LCTL("C") SS_TAP(X_D) SS_TAP(X_Y));
            } else {
                // when keycode QMKBEST is released
            }
            return false;

            // prueba de hacer el salto de linea
            /* case SALTO: */
            /*     if (record->event.pressed) { */
            /* 	SEND_STRING(SS_LCTL("em")); */
            /*     } */
            /*     return false; */
        case SALTO:
            if (record->event.pressed) {
                register_code(KC_LCTL); // Mantener Ctrl presionado
                tap_code(DV_E);         // Enviar E
                wait_ms(40);
                tap_code(DV_M);           // Enviar M
                unregister_code(KC_LCTL); // Liberar Ctrl
            }
            return false;
        case KILL:
            if (record->event.pressed) {
                //      SEND_STRING(SS_LCTL("x") SS_TAP(X_V));

                register_code(KC_LCTL);   // Mantener Ctrl presionado
                tap_code(DV_X);           // Enviar E
                unregister_code(KC_LCTL); // Liberar Ctrl
                wait_ms(40);
                tap_code(DV_K); // Enviar M
            } else {
            }
            return false;
        case ORGPDF:
            if (record->event.pressed) {
                //      SEND_STRING(SS_LCTL("ce") SS_TAP(X_P) SS_TAP(X_R));
                register_code(KC_LCTL);   // Mantener Ctrl presionado
                tap_code(DV_C);           // Enviar C
                wait_ms(40);              // Esperar 40 milisegundos
                tap_code(DV_E);           // Enviar E
                unregister_code(KC_LCTL); // Liberar Ctrl
                tap_code(KC_P);           // Enviar P fuera de Ctrl
                tap_code(KC_R);           // Enviar R fuera de Ctrl
            }
            return false;
        case OPEN:
            if (record->event.pressed) {
                // SEND_STRING(SS_LCTL("xf"));
                //	tap_code(KC_F15); //para ponerlo en la DV_O

                register_code(KC_LCTL);
                tap_code(DV_X);
                wait_ms(40);
                tap_code(DV_F);
                unregister_code(KC_LCTL);
            }
            return false;
        case SAVE:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(DV_X);
                wait_ms(40);
                tap_code(DV_S);
                unregister_code(KC_LCTL);
                // SEND_STRING(SS_LCTL("xs"));
            }
            return false;
            /*   case BUFFER: */
            /*     if (record->event.pressed) { */
            /* 	SEND_STRING(SS_LCTL("x") SS_TAP(X_N)); */
            /*       // SEND_STRING("å"); // debe ser algo asi, no es lo mismo C-x b cambia buffer normal y å lo tengo puesto para counsel con previsualizacion */
            /* //SEND_STRING("å"); */
            /*     } */
            /*     return false; */
        case IEDIT: // Nombre de tu keycode personalizado
            if (record->event.pressed) {
                //      tap_code(KC_F14);
                register_code(KC_LCTL);
                tap_code(DV_C);
                unregister_code(KC_LCTL);
                SEND_STRING(";");
            }
            return false;
        case BUFFER: // Nombre de tu keycode personalizado
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(DV_X);
                unregister_code(KC_LCTL);
                wait_ms(40);
                tap_code(DV_B);
                //      tap_code(KC_F16);
            }
            return false;
        case EXPAND: // Nombre de tu keycode personalizado
            if (record->event.pressed) {
                register_code(KC_LCTL);
                SEND_STRING("=");
                unregister_code(KC_LCTL);
                //      tap_code(KC_F16);
            }
            return false;

        case RECENT:
            if (record->event.pressed) {
                // SEND_STRING(SS_LCTL("X") SS_TAP(X_Y));
                // tap_code(KC_F19);
                register_code(KC_LCTL);   // Mantener Ctrl presionado
                tap_code(DV_C);           // Enviar E
                unregister_code(KC_LCTL); // Liberar Ctrl
                wait_ms(40);
                tap_code(DV_R); // Enviar M
            }
            return false;

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
                //	SEND_STRING(SS_LCTL("x") SS_TAP(X_1));

                register_code(KC_LCTL);   // Mantener Ctrl presionado
                tap_code(DV_X);           // Enviar E
                unregister_code(KC_LCTL); // Liberar Ctrl
                wait_ms(40);
                tap_code(KC_1); // Enviar M
            }
            return false;
        case V2:
            if (record->event.pressed) {
                //	SEND_STRING(SS_LCTL("x") SS_TAP(X_2));

                register_code(KC_LCTL);   // Mantener Ctrl presionado
                tap_code(DV_X);           // Enviar E
                unregister_code(KC_LCTL); // Liberar Ctrl
                wait_ms(40);
                tap_code(KC_2); // Enviar M
            }
            return false;
        case V3:
            if (record->event.pressed) {
                //	SEND_STRING(SS_LCTL("x") SS_TAP(X_3));

                register_code(KC_LCTL);   // Mantener Ctrl presionado
                tap_code(DV_X);           // Enviar E
                unregister_code(KC_LCTL); // Liberar Ctrl
                wait_ms(40);
                tap_code(KC_3); // Enviar M
            } else {
            }
            return false;
        case V0:
            if (record->event.pressed) {
                //	SEND_STRING(SS_LCTL("x") SS_TAP(X_0));

                register_code(KC_LCTL);   // Mantener Ctrl presionado
                tap_code(DV_X);           // Enviar E
                unregister_code(KC_LCTL); // Liberar Ctrl
                wait_ms(40);
                tap_code(KC_0); // Enviar M
            }
            return false;
        case ACE_W:
            if (record->event.pressed) {
                //	SEND_STRING(SS_LCTL("X") SS_TAP(X_S));
                //   tap_code(KC_F17);
                //   send_unicode_string("×");

                register_code(KC_LCTL);   // Mantener Ctrl presionado
                tap_code(DV_X);           // toque a 'X'
                unregister_code(KC_LCTL); // Liberar Ctrl
		tap_code(DV_O); 	  // toque a 'O'
            }
            return false;
            // MACROS
            return false;
        case MACRO1:
            if (record->event.pressed) {
                //    esta funcion la saque de lo que me pasó pablo adaptada a «send_string_spanish_dvorak.c»
                send_string_spanish_dvorak("¡España! ¿Funciona? áéíóúÁÉÍÓÚñÑçÇüÜªº@€|¬#~[]{};:*/\\·");
            }
            return false;
        case MACRO2:
            if (record->event.pressed) {
                // Dejo esta cadena pero utiliza mejor send_string_spanish de
                // Para utilizar caracteres especiales usaremos register_unicode con su codigo, tampbien se puede usar un string con el simbolo renderizado como→👀 
                SEND_STRING("Jose ");
                wait_ms(40);
                SEND_STRING("Jorge Ib");
                wait_ms(40);
                register_unicode(0x00E1); // á
                wait_ms(40);
                register_unicode(0x00F1); // ñ
                wait_ms(40);
                SEND_STRING("ez Garc");
                wait_ms(40);
                register_unicode(0x00ED); // í
                wait_ms(40);
                SEND_STRING("a");
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
                send_unicode_string("");
            } else {
            }
            return false;
        case MACRO5:
            if (record->event.pressed) {
                send_unicode_string("👀");
            } else {
            }
            return false;
        case UNICODE:
            if (record->event.pressed) {
                register_unicode(0x1F440);
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
            }
            return false;
        // aqui pongo varias formas de mostrar los acentos, con unicode y con pulsacioes, en este ultimo aoeui es asdfg
        case TIL_A:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_A));
            }
            return false;
        case TIL_O:
           if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_S));
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
                SEND_STRING(SS_TAP(X_QUOT) SS_TAP(X_G));
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
