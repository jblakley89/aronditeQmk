#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;
extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _QWERTY 1
#define _LOWER 6
#define _RAISE 7
#define _ADJUST 16

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  RAISE,
  LOWER
};

enum {
  TD_CTRL_ESC = 0
};

#define KC_ KC_TRNS

#define KC_COLMK COLEMAK
#define KC_QWERT QWERTY
#define KC_LOWER LOWER
#define KC_RAISE RAISE

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
#define KC_RGBRST RGBRST
#define KC_RST RESET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_COLEMAK] = LAYOUT_kc(
    //,-----------------------------------.				,-----------------------------------.
        TAB ,  Q  ,  W  ,  F  ,  P  ,  G  ,				   J  ,  L  ,  U  ,  Y  , SCLN, BSPC,
    //|-----+-----+-----+-----+-----+-----|				|-----+-----+-----+-----+-----+-----|
       ESCTL,  A  ,  R  ,  S  ,  T  ,  D  ,				   H  ,  N  ,  E  ,  I  ,  O  , QUOT,
    //|-----+-----+-----+-----+-----+-----|				|-----+-----+-----+-----+-----+-----|
        LSFT,  Z  ,  X  ,  C  ,  V  ,  B  ,				   K  ,  M  , COMM, DOT , SLSH,ENSHF,
    //|-----+-----+-----+-----+-----+-----|				|-----+-----+-----+-----+-----+-----|
        					     NO ,LOWER, SPC ,   LSFT,RAISE,  NO
    						//`-----------------' `-----------------'
	),
	[_QWERTY] = LAYOUT_kc(
    //,-----------------------------------.				,-----------------------------------.
        TAB ,  Q  ,  W  ,  E  ,  R  ,  T  ,				   Y  ,  U  ,  I  ,  O  ,  P  , BSPC,
    //|-----+-----+-----+-----+-----+-----|				|-----+-----+-----+-----+-----+-----|
       ESCTL,  A  ,  S  ,  D  ,  F  ,  G  ,				   H  ,  J  ,  K  ,  L  , SCLN, QUOT,
    //|-----+-----+-----+-----+-----+-----|				|-----+-----+-----+-----+-----+-----|
        LSFT,  Z  ,  X  ,  C  ,  V  ,  B  ,				   N  ,  M  , COMM, DOT , SLSH,ENSHF,
    //|-----+-----+-----+-----+-----+-----|				|-----+-----+-----+-----+-----+-----|
      						        ,     ,     ,       ,     ,      
    						//`-----------------' `-----------------'
	),
	[_LOWER] = LAYOUT_kc(
    //,-----------------------------------.				,-----------------------------------.
            , F1  , F2  , F3  , F4  , F5  ,				  NLCK,  P7 ,  P8 ,  P9 , PAST, PSLS,
    //|-----+-----+-----+-----+-----+-----|				|-----+-----+-----+-----+-----+-----|
            , F6  , F7  , F8  , F9  , F10 ,				      ,  P4 ,  P5 ,  P6 , PPLS, PMNS,
    //|-----+-----+-----+-----+-----+-----|				|-----+-----+-----+-----+-----+-----|
            , F11 , F12 ,     ,     ,     ,				  RALT,  P1 ,  P2 ,  P3 , PEQL, PCMM,
    //|-----+-----+-----+-----+-----+-----|				|-----+-----+-----+-----+-----+-----|
      						        ,     ,     ,    P0 ,     , LGUI 
    						//`-----------------' `-----------------'
	),
	[_RAISE] = LAYOUT_kc(
    //,-----------------------------------.				,-----------------------------------.
            , EXLM,  AT , LPRN, RPRN, AMPR,				  PGUP, HOME,  UP , END ,  NO , DEL ,
    //|-----+-----+-----+-----+-----+-----|				|-----+-----+-----+-----+-----+-----|
            , HASH, DLR , LCBR, RCBR, PIPE,				  PGDN, LEFT, DOWN, RGHT,  NO ,  NO ,
    //|-----+-----+-----+-----+-----+-----|				|-----+-----+-----+-----+-----+-----|
        LSFT, PERC, CIRC, LBRC, RBRC, GRV ,				   NO ,  NO ,  NO ,  NO ,  NO ,     ,
    //|-----+-----+-----+-----+-----+-----|				|-----+-----+-----+-----+-----+-----|
      						    LGUI,     , BSLS,       ,     ,     
    						//`-----------------' `-----------------'
    ),
	[_ADJUST] = LAYOUT_kc(
    //,-----------------------------------.				,-----------------------------------.
       GLOMF,GLOMR,GLOHI,GLOSI,GLOVI,GLOEI,				 COLMK,QWERT,     ,     ,     , RST ,
    //|-----+-----+-----+-----+-----+-----|				|-----+-----+-----+-----+-----+-----|
            ,     ,GLOHD,GLOSD,GLOVD,GLOED,				, PSCR,     ,     ,     ,     ,
    //|-----+-----+-----+-----+-----+-----|				|-----+-----+-----+-----+-----+-----|
            ,     ,     ,     ,     ,     ,				      , APP ,     ,     ,     ,     ,
    //|-----+-----+-----+-----+-----+-----+-----|  |----+-----+-----+-----+-----+-----+-----|
      						        ,     ,     ,       ,     ,     
    						//`-----------------'  `----------------'
    )
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CTRL_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ESC)
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_master) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_180;
    }
}

void render_layer_state(void) {
	oled_write_ln_P(PSTR("LAYER"), false);
	oled_write_ln_P(PSTR("COLMK"), biton32(default_layer_state) == _COLEMAK);
	oled_write_ln_P(PSTR("QWRTY"), biton32(default_layer_state) == _QWERTY);
	oled_write_P(PSTR("EX:"), false);

	if (layer_state_is(_LOWER)){
		oled_write_P(PSTR("-"), false);
	}
	
	if (layer_state_is(_RAISE)){
		oled_write_P(PSTR("+"), false);
	}
	oled_write_ln_P(PSTR("   "), false);
}

void render_mod_status(uint8_t modifiers) {
	oled_write_ln_P(PSTR("Mods:"), false);
	oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
	oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
	oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
	oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
	oled_write_ln_P(PSTR(" "), false);
}

void render_logo(void) {
	static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
	oled_write_P(qmk_logo, false);
}

void oled_task_user(void) {
  if (is_master) {
	render_layer_state();
	render_mod_status(get_mods()|get_oneshot_mods());
  } else {
	render_logo();
  }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
	case QWERTY:
	  if (record->event.pressed) {
		default_layer_set(1UL<<_QWERTY);
	  }
	  return false;
	case COLEMAK:
	  if (record->event.pressed) {
		default_layer_set(1UL<<_COLEMAK);
	  }
	  return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
		update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
		update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
		update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
		update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
	}
  return true;
}

