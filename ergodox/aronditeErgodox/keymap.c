#include QMK_KEYBOARD_H

#include "action_layer.h"
#include "version.h"
#include "eeconfig.h"
#include "eeprom.h"
#include "keymap_colemak.h"

extern keymap_config_t keymap_config;

enum ergodox_layers {
  _COL,
  _QWR,
  _SYM,
  _NAV,
  _GAM
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /******* COLMAK Layer ********************************************************************************************************
   *
   * ,---------------------------------------------------.           ,---------------------------------------------------.
   * |    `    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |    -_   |
   * |---------+------+------+------+------+-------------|           |------+------+------+------+------+------+---------|
   * |   Tab   |   Q  |   W  |   F  |   P  |   G  |  {[  |           |  ]}  |   J  |   L  |   U  |   Y  |   ;  |    \|   |
   * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+---------|
   * |  Caps   |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   Y  |    '"   |
   * |---------+------+------+------+------+------| Home |           | End  |------+------+------+------+------+---------|
   * | LShift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |  /   |  RShift |
   * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+---------'
   *   |  L(S) | LCtl | LAlt | IGUI |L(NAV)|                                       | Left |  Up  | Down | Right| (S)+= |
   *   `-----------------------------------'                                       `-----------------------------------'
   *                                       ,-------------.           ,-------------.
   *                                       |      |      |           |L(QWR)| Menu |
   *                                ,------|------|------|           |------+------+------.
   *                                |      |      |      |           |      |      |      |
   *                                | Spce | Del  |------|           |------| Enter| Bspc |
   *                                |      |      | ESC  |           |      |      |      |
   *                                `--------------------'           `--------------------'
   */
	[_COL] = LAYOUT_ergodox(
		// LEFT
	  KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_NO,
		KC_TAB,		KC_Q,		KC_W,   KC_F,		KC_P,		KC_G,		KC_LBRC,
		KC_CAPS,	KC_A,	  KC_R,		KC_S,		KC_T,		KC_D,
		KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_HOME,
		MO(_SYM), KC_LCTL,KC_LGUI,KC_LALT,MO(_NAV),

                                      KC_NO,	KC_NO,
                                                      KC_NO,
                                      KC_SPC,	KC_DEL,	KC_ESC,

                                                                    // RIGHT
                                                                    KC_NO, KC_6,		KC_7,		KC_8,		KC_9,		KC_0,	  	KC_MINS,
                                                                    KC_RBRC,	KC_J,		KC_L,		KC_U,		KC_Y,		KC_SCLN,	KC_BSLS,
                                                                              KC_H,	  KC_N,		KC_E,		KC_I,		KC_O,		  KC_QUOT,
                                                                    KC_END,	  KC_K,   KC_M,		KC_COMM,KC_DOT,	KC_SLSH,  KC_LSFT,
                                                                                      KC_LEFT,KC_UP,	KC_DOWN,KC_RGHT,  LT(_SYM,KC_EQL),

                                                                    TG(_QWR),	KC_APP,
                                                                    KC_NO,
                                                                    KC_NO,	KC_ENT,		KC_BSPC
		),

  /******* QWERTY Layer ********************************************************************************************************
   *
   * ,---------------------------------------------------.           ,---------------------------------------------------.
   * |    `    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |    -_   |
   * |---------+------+------+------+------+-------------|           |------+------+------+------+------+------+---------|
   * |   Tab   |   Q  |   W  |   E  |   R  |   T  |  {[  |           |  ]}  |   Y  |   U  |   I  |   O  |   P  |    \|   |
   * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+---------|
   * |  Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |    '"   |
   * |---------+------+------+------+------+------| Home |           | End  |------+------+------+------+------+---------|
   * | LShift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   |  RShift |
   * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+---------'
   *   |  L(S) | LCtl | LAlt | IGUI |L(NAV)|                                       | Left |  Up  | Down | Right| (S)+= |
   *   `-----------------------------------'                                       `-----------------------------------'
   *                                       ,-------------.           ,-------------.
   *                                       |      |      |           |L(QWR)| Menu |
   *                                ,------|------|------|           |------+------+------.
   *                                |      |      |      |           |L(GAM)|      |      |
   *                                | Spce | Del  |------|           |------| Enter| Bspc |
   *                                |      |      | ESC  |           |      |      |      |
   *                                `--------------------'           `--------------------'
   */
	[_QWR] = LAYOUT_ergodox(
		// LEFT
		KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_NO,
		KC_TAB,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,		KC_LBRC,
		KC_CAPS,	KC_A,		KC_S,		KC_D,		KC_F,		KC_G,
		KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_HOME,
		MO(_SYM), KC_LCTL,KC_LGUI,KC_LALT,MO(_NAV),

                                      KC_NO,	KC_NO,
                                                      KC_NO,
                                      KC_SPC,	KC_DEL,	KC_ESC,
                                                                    // RIGHT
                                                                    KC_NO, KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_MINS,
                                                                    KC_RBRC,	KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_BSLS,
                                                                              KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,KC_QUOT,
                                                                    KC_END,		KC_N,		KC_M,		KC_COMM,KC_DOT,	KC_SLSH,KC_LSFT,
                                                                                      KC_LEFT,KC_UP,	KC_DOWN,KC_RGHT,LT(_SYM,KC_EQL),

                                                                    TG(_QWR),	KC_APP,
                                                                    TG(_GAM),
                                                                    KC_NO,	KC_ENT,		KC_BSPC
                                                                    ),

  /******* SYMBOL Layer ********************************************************************************************************
   *
   * ,---------------------------------------------------.           ,---------------------------------------------------.
   * |    `    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11   |
   * |---------+------+------+------+------+-------------|           |------+------+------+------+------+------+---------|
   * |         |  #   |   *  |  {   |   }  |   |  |      |           |      |      |   7  |   8  |   9  |   *  |   F12   |
   * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+---------|
   * |         |  !   |   &  |  (   |   )  |   @  |------|           |------|      |   4  |   5  |   6  |   -  |         |
   * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+---------|
   * |         |  %   |   ^  |  [   |   ]  |   $  |      |           |      |      |   1  |   2  |   3  |   +  |         |
   * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+---------'
   *   |       |      |      |  <   |   >  |                                       |   0  |      |   .  |   /  |   =  |
   *   `-----------------------------------'                                       `----------------------------------'
   *                                       ,-------------.           ,-------------.
   *                                       |      |      |           |      |      |
   *                                ,------|------|------|           |------+------+------.
   *                                |      |      |      |           |      |      |      |
   *                                | Spce | Del  |------|           |------| Enter| Bspc |
   *                                |      |      | ESC  |           |      |      |      |
   *                                `--------------------'           `--------------------'
   */
	[_SYM] = LAYOUT_ergodox(
		// LEFT
		KC_NO,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_NO,
		KC_NO,    KC_HASH,  KC_ASTR,  KC_LCBR,	KC_RCBR,	KC_PIPE,	KC_NO,
		KC_NO,  	KC_EXLM,	KC_AMPR,  KC_LPRN,	KC_RPRN,	KC_AT,
		KC_NO,	  KC_PERC,	KC_CIRC,	KC_LBRC,  KC_RBRC,  KC_DLR,	  KC_NO,
		KC_NO,	  KC_NO,	  KC_NO,    KC_LT,	  KC_GT,

														                          KC_TRNS,	  KC_TRNS,
																			                          KC_TRNS,
														                KC_TRNS,	KC_TRNS,	KC_TRNS,

                                                                    // RIGHT
                                                                    KC_NO,	KC_F6,	KC_F7,	KC_F8,	KC_F9,  KC_F10,		KC_F11,
                                                                    KC_NO,	KC_NO,	KC_7,	  KC_8,	  KC_9,	  KC_ASTR,	KC_F12,
                                                                            KC_NO,	KC_4,	  KC_5,	  KC_6,	  KC_MINS,	KC_NO,
                                                                    KC_NO,	KC_NO,	KC_1,	  KC_2,	  KC_3,	  KC_PLUS,	KC_NO,
                                                                                    KC_0,	  KC_NO,  KC_DOT, KC_SLSH,	  KC_EQL,

                                                                    KC_TRNS,	KC_TRNS,
                                                                    KC_TRNS,
                                                                    KC_TRNS,	KC_TRNS,KC_TRNS
		),

    /******* NAV Layer ********************************************************************************************************
   *
   * ,---------------------------------------------------.           ,---------------------------------------------------.
   * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |         |
   * |---------+------+------+------+------+-------------|           |------+------+------+------+------+------+---------|
   * |         |      |  Mlc |  Mu  |  Mrc |      |      |           |      | Pgup | Home |   U  |  End |      |         |
   * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+---------|
   * |         |      |  Ml  |  Md  |  Mr  |      |------|           |------| Pgdn |   L  |   D  |   R  |      |         |
   * |---------+------+------+------+------+------| Home |           | End  |------+------+------+------+------+---------|
   * | LShift  |      |      |      |      |      |      |           |      |      |      |      |      |      |         |
   * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+---------'
   *   |       | LCtl | LAlt | IGUI |L(NAV)|                                       |      |      |      |      |      |
   *   `-----------------------------------'                                       `----------------------------------'
   *                                       ,-------------.           ,-------------.
   *                                       |      |      |           | Prnt |      |
   *                                ,------|------|------|           |------+------+------.
   *                                |      |      |      |           |      |      |      |
   *                                | Spce | Del  |------|           |------| Entr | Bspc |
   *                                |      |      | Esc  |           |      |      |      |
   *                                `--------------------'           `--------------------'
   */
	[_NAV] = LAYOUT_ergodox(
		// LEFT
		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
		KC_NO,    KC_NO,    KC_BTN1,  KC_MS_U,  KC_BTN2, 	KC_NO,  	KC_NO,
		KC_NO,  	KC_NO,	  KC_MS_L,	KC_MS_D,  KC_MS_R, 	KC_NO,
		KC_TRNS,	KC_NO,	  KC_NO,  	KC_NO,    KC_NO,    KC_NO,  	KC_TRNS,
		KC_NO,	  KC_TRNS,	KC_TRNS,  KC_TRNS,	KC_TRNS,

														                          KC_TRNS,	KC_TRNS,
																			                          KC_TRNS,
														                KC_TRNS,	KC_TRNS,  KC_TRNS,

                                                                    // RIGHT
                                                                    KC_NO,	KC_NO,	KC_NO,	  KC_NO,  	KC_NO,    KC_NO,		KC_NO,
                                                                    KC_NO,	KC_PGUP,KC_HOME,	KC_UP,	  KC_END,	  KC_NO,	  KC_NO,
                                                                            KC_PGDN,KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_NO,	  KC_NO,
                                                                    KC_TRNS,KC_NO,	KC_NO,	  KC_NO,	  KC_NO,	  KC_NO,	  KC_NO,
                                                                                    KC_TRNS,	KC_TRNS,  KC_TRNS,  KC_TRNS,	KC_NO,

                                                                    KC_PSCR,	KC_TRNS,
                                                                    KC_TRNS,
                                                                    KC_TRNS,	KC_TRNS,	KC_TRNS
		),

	/******* GAMING Layer ********************************************************************************************************
   *
   * ,---------------------------------------------------.           ,---------------------------------------------------.
   * |    `    |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11   |
   * |---------+------+------+------+------+-------------|           |------+------+------+------+------+------+---------|
   * |   Tab   |   Q  |   W  |   E  |   R  |   T  |  {[  |           |  ]}  |   Y  |   U  |   I  |   O  |   P  |   F12   |
   * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+---------|
   * |  Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |    '"   |
   * |---------+------+------+------+------+------| Home |           | End  |------+------+------+------+------+---------|
   * | LShift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   |  RShift |
   * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+---------'
   *   |  L(S) | LCtl | LAlt | IGUI |L(NAV)|                                       | Left |  Up  | Down | Right| (S)+= |
   *   `-----------------------------------'                                       `-----------------------------------'
   *                                       ,-------------.           ,-------------.
   *                                       |      |      |           |      | Menu |
   *                                ,------|------|------|           |------+------+------.
   *                                |      |      |      |           | L(G) |      |      |
   *                                | Spce | Del  |------|           |------| Enter| Bspc |
   *                                |      |      | ESC  |           |      |      |      |
   *                                `--------------------'           `--------------------'
   */
	[_GAM] = LAYOUT_ergodox(
		// LEFT
		KC_GRV,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_NO,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
		KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                KC_TRNS,	KC_TRNS,
                                                          KC_TRNS,
                                      KC_TRNS,	KC_TRNS,	KC_TRNS,
                                                                    // RIGHT
                                                                    KC_NO,    KC_F6,	  KC_F7,	  KC_F8,	  KC_F9,	  KC_F10,	  KC_F11,
                                                                    KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_F12,
                                                                              KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,  KC_TRNS,
                                                                    KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,  KC_TRNS,	KC_TRNS,  KC_TRNS,
                                                                                        KC_TRNS,  KC_TRNS,	KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                                    KC_TRNS,	KC_TRNS,
                                                                    KC_TRNS,
                                                                    KC_TRNS,	KC_TRNS,		KC_TRNS
                                                                    ),
};
