/* Copyright 2021 Yang Hu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define OLED_FONT_H "keyboards/yanghu/unicorne/glcdfont.c"
#define ENCODER_RESOLUTION 4
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
#define RGBLIGHT_DEFAULT_COLOR HSV_BLUE


// tienes que personalizar le tapping, bajarlo a 180 los que sean el meñique
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200


//prevent normal rollover
//#define IGNORE_MOD_TAP_INTERRUPT


#define UNICODE_SELECTED_MODES UC_LINX
#define UNICODE_KEY_LNX LCTL(LSFT(KC_F))

#define UNICODE_MODE_LINUX
//#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
