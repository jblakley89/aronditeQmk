#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _COLEMAK 0
#define _QWERTY 1
#define _GAME 2
#define _LOWER 6
#define _RAISE 7
#define _GAMELOWER 8
#define _GAMERAISE 9
#define _ADJUST 16

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  GAME,
  LOWER,
  RAISE,
  GAMELOWER,
  GAMERAISE,
  ADJST,
};

enum {
  TD_CTRL_ESC = 0
};

#define KC_ KC_TRNS

#define KC_COLMK COLEMAK
#define KC_QWERT QWERTY
#define KC_GAME GAME
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_GAMEL GAMELOWER
#define KC_GAMER GAMERAISE
#define KC_LOWGT LT(_LOWER, LSFT(KC_DOT))
#define KC_RAIS0 LT(_RAISE, KC_P0)

#define KC_ESCTL LCTL_T(KC_ESC) 
#define KC_ENSHF KC_SFTENT 
#define KC_GLOMF RGB_MODE_FORWARD
#define KC_GLOMR RGB_MODE_REVERSE
#define KC_GLOHI RGB_HUI
#define KC_GLOHD RGB_HUD
#define KC_GLOSI RGB_SAI
#define KC_GLOSD RGB_SAD
#define KC_GLOVI RGB_VAI
#define KC_GLOVD RGB_VAD
#define KC_GLOEI RGB_SPI
#define KC_GLOED RGB_SPD
#define KC_RST RESET
#define KC_TDCE TD(TD_CTRL_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = LAYOUT_kc(
    //,-----------------------------------.-----------------------------------.
        TAB ,  Q  ,  W  ,  F  ,  P  ,  G  ,  J  ,  L  ,  U  ,  Y  , SCLN, BSPC,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
       ESCTL,  A  ,  R  ,  S  ,  T  ,  D  ,  H  ,  N  ,  E  ,  I  ,  O  , QUOT,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
        LSFT,  Z  ,  X  ,  C  ,  V  ,  B  ,  K  ,  M  , COMM, DOT , SLSH,ENSHF,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
        LCTL, LGUI, LALT,  NO ,LOWER, SPC , LSFT,RAISE, LEFT, DOWN, UP  , RGHT
    //`-----------------------------------'-----------------------------------'
	),
	[_QWERTY] = LAYOUT_kc(
    //,-----------------------------------.-----------------------------------.
        TAB ,  Q  ,  W  ,  E  ,  R  ,  T  ,  Y  ,  U  ,  I  ,  O  ,  P  , BSPC,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
       ESCTL,  A  ,  S  ,  D  ,  F  ,  G  ,  H  ,  J  ,  K  ,  L  , SCLN, QUOT,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
        LSFT,  Z  ,  X  ,  C  ,  V  ,  B  ,  N  ,  M  , COMM, DOT , SLSH,ENSHF,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
        LCTL, LGUI, LALT,  NO ,LOWER, SPC , LSFT,RAISE, LEFT, DOWN, UP  , RGHT
    //`-----------------------------------'-----------------------------------'
	),
	[_GAME] = LAYOUT_kc(
    //,-----------------------------------.-----------------------------------.
        TAB ,  Q  ,  W  ,  E  ,  R  ,  T  ,  Y  ,  U  ,  I  ,  O  ,  P  , BSPC,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
       ESCTL,  A  ,  S  ,  D  ,  F  ,  G  ,  H  ,  J  ,  K  ,  L  , SCLN, QUOT,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
        LSFT,  Z  ,  X  ,  C  ,  V  ,  B  ,  N  ,  M  , COMM, DOT , SLSH,ENSHF,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
        TDCE, LGUI, LALT,  NO ,GAMEL, SPC , RSFT,GAMER,  NO , RALT, RGUI, RCTL 
    //`-----------------------------------'-----------------------------------'
	),
	[_LOWER] = LAYOUT_kc(
    //,-----------------------------------.-----------------------------------.
            , F1  , F2  , F3  , F4  , F5  ,     ,  7  ,  8  ,  9  , ASTR,     ,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
            , F6  , F7  , F8  , F9  , F10 ,     ,  4  ,  5  ,  6  , MINS,     ,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
            , F11 , F12 ,     ,     ,     ,     ,  1  ,  2  ,  3  , EQL ,     ,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
            ,     ,     ,     ,     ,     ,  0  ,     , NO  , DOT , ENT ,     
    //`-----------------------------------'-----------------------------------'
	),
	[_RAISE] = LAYOUT_kc(
    //,-----------------------------------.-----------------------------------.
            , EXLM,  AT , LPRN, RPRN, AMPR, PGUP, HOME,  UP , END ,  NO , DEL ,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
            , HASH, DLR , LCBR, RCBR, PIPE, PGDN, LEFT, DOWN, RGHT,  NO ,  NO ,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
        LSFT, PERC, CIRC, LBRC, RBRC, GRV ,  NO ,  NO ,  NO ,  NO ,  NO ,     ,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
            ,     ,     ,  NO ,     , BSLS,     ,     ,     ,     ,     ,     
    //`-----------------------------------'-----------------------------------'
    ),
	[_GAMELOWER] = LAYOUT_kc(
    //,-----------------------------------.-----------------------------------.
            , F1  , F2  , F3  , F4  , F5  , NLCK,  P7 ,  P8 ,  P9 , PAST, PSLS,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
            , F6  , F7  , F8  , F9  , F10 ,     ,  P4 ,  P5 ,  P6 , PPLS, PMNS,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
            , F11 , F12 ,     ,     ,     ,     ,  P1 ,  P2 ,  P3 , PEQL, PCMM,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
            ,     ,     ,     ,     ,     ,  P0 ,     ,  NO , PDOT, PENT,  NO
    //`-----------------------------------'-----------------------------------'
    ),
	[_GAMERAISE] = LAYOUT_kc(
    //,-----------------------------------.-----------------------------------.
            ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
            ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
            ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
            ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     
    //`-----------------------------------'-----------------------------------'
    ),
	[_ADJUST] = LAYOUT_kc(
    //,-----------------------------------.-----------------------------------.
       GLOMF,GLOMR,GLOHI,GLOSI,GLOVI,GLOEI,COLMK,QWERT, GAME,     ,     , RST ,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
            ,     ,GLOHD,GLOSD,GLOVD,GLOED,     , PSCR,     ,     ,     ,     ,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
            ,     ,     ,     ,     ,     ,     , APP ,     ,     ,     ,     ,
    //|-----+-----+-----+-----+-----+-----|-----+-----+-----+-----+-----+-----|
            ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     ,     
    //`-----------------------------------'-----------------------------------'
    )
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CTRL_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ESC)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        default_layer_set(1UL<<_GAME);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case GAMELOWER:
      if (record->event.pressed) {
        layer_on(_GAMELOWER);
        update_tri_layer(_GAMELOWER, _GAMERAISE, _ADJUST);
      } else {
        layer_off(_GAMELOWER);
        update_tri_layer(_GAMELOWER, _GAMERAISE, _ADJUST);
      }
      return false;
      break;
    case GAMERAISE:
      if (record->event.pressed) {
        layer_on(_GAMERAISE);
        update_tri_layer(_GAMELOWER, _GAMERAISE, _ADJUST);
      } else {
        layer_off(_GAMERAISE);
        update_tri_layer(_GAMELOWER, _GAMERAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
