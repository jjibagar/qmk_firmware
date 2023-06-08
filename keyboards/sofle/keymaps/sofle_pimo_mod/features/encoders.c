#include"encoders.h"

/*
#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
*/

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
    case _RAISE:
	if (index == 0) {
	    if (clockwise) {
		tap_code(KC_VOLD);
	    } else {
		tap_code(KC_VOLU);
	    }
	} else if (index == 1) {
	    if (clockwise) {
		tap_code(KC_PGDN);
	    } else {
		tap_code(KC_PGUP);
	    }
	}
	return true;
    case _LOWER:
	if (index == 0) {
	    if (clockwise) {
		tap_code(KC_VOLD);
	    } else {
		tap_code(KC_VOLU);
	    }
	} else if (index == 1) {
	    if (clockwise) {
		tap_code(KC_PGDN);
               } else {
                 tap_code(KC_PGUP);
               }
             }
        return true;
        case _ADJUST:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                tap_code(KC_VOLD);
              }
           } else if (index == 1) {
                if (clockwise) {
                   tap_code(KC_PGDN);
               } else {
                 tap_code(KC_PGUP);
                }
            }
        return true;
        default:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                tap_code(KC_VOLD);
              }
           } else if (index == 1) {
                if (clockwise) {
                   tap_code(KC_PGDN);
               } else {
                 tap_code(KC_PGUP);
             }
         }
        return true;
    }
}

#endif
