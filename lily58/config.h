/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#undef USE_I2C
#define USE_SERIAL_PD2

#define TAPPING_TERM 180

#ifdef OLED_ENABLE
#   define OLED_TIMEOUT 600000
#endif

#undef RGBLED_NUM
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLED_NUM 27
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 5
#define RGBLIGHT_VAL_STEP 5

#undef PRODUCT
#define PRODUCT Arondite Lily58

