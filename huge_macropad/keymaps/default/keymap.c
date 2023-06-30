#include QMK_KEYBOARD_H
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

static uint32_t key_timer = 0;
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
  //┌────────┬────────┐
     KC_F5,      KC_F1,
  //├────────┼────────┤
     KC_F7,      KC_F3,
  //├────────┼────────┤
     KC_F6,      KC_F2,
  //├────────┼────────┤
     KC_F8,      KC_F4
  //└────────┴────────┘
  )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(LCTL(KC_PPLS), LCTL(KC_PMNS)), ENCODER_CCW_CW(KC_VOLU, KC_VOLD)  }
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
if (timer_elapsed32(key_timer) > 120000) {
    key_timer = timer_read32();
    tap_code(KC_MS_UP);
    tap_code(KC_MS_DOWN);
    tap_code(KC_MS_LEFT);
    tap_code(KC_MS_RIGHT);
    }
}

