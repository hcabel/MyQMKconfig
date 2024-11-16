
#include QMK_KEYBOARD_H

// Base Colemak
// + K and J swapped (vim motion)
// + Home row mods Ctrl, Gui, Alt, Shift (mirrored)
// + Vim focused
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
         [0] = LAYOUT_split_3x6_3(
      QK_GESC, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_K, KC_L, KC_U, KC_Y, KC_UNDS, KC_BSPC, KC_TAB, LCTL_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_D, KC_H, RSFT_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), RCTL_T(KC_O), KC_SCLN, KC_BSLS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_J, KC_M, KC_COMM, KC_DOT, KC_QUOT, KC_SLSH, KC_NO, OSL(1), KC_SPC, KC_ENT, OSL(2), KC_NO
      ), [1] = LAYOUT_split_3x6_3(
      QK_GESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_BSPC, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_0, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, MO(3), KC_NO
      ), [2] = LAYOUT_split_3x6_3(
      QK_GESC, KC_NO, KC_LBRC, KC_LCBR, KC_LPRN, KC_CIRC, KC_DLR, KC_RPRN, KC_RCBR, KC_RBRC, KC_NO, KC_BSPC, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_AT, KC_PERC, KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_DEL, KC_NO, KC_EXLM, KC_EQL, KC_PIPE, KC_AMPR, KC_HASH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MO(3), KC_NO, KC_NO, KC_TRNS, KC_NO
      ), [3] = LAYOUT_split_3x6_3(
      QK_GESC, BL_TOGG, BL_STEP, KC_NO, KC_PGUP, KC_HOME, KC_NO, KC_F7, KC_F8, KC_F9, KC_F12, KC_DEL, KC_CAPS, RGB_MOD, RGB_VAI, RGB_SPI, DF(4), KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO, RGB_TOG, RGB_RMOD, RGB_VAD, RGB_SPD, KC_PGDN, KC_END, KC_NO, KC_F1, KC_F2, KC_F3, KC_F10, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO
      ), [4] = LAYOUT_split_3x6_3(
      KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RGUI, KC_NO, MO(5), KC_SPC, KC_ENT, MO(6), KC_NO
      ), [5] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, MO(7), KC_NO
      ), [6] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MO(7), KC_NO, KC_NO, KC_TRNS, KC_NO
      ), [7] = LAYOUT_split_3x6_3(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DF(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO
      )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ESC: // Experimental
            reset_oneshot_layer();
            layer_state_set(default_layer_state);
        default:
            break;
    };
    return true;
}

uint16_t get_tappig_term(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case LCTL_T(KC_A): // Pinky is slower
        case RCTL_T(KC_O):
            return TAPPING_TERM + 50;
    }
    return TAPPING_TERM;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 5:
        case 1:
            rgblight_sethsv(148, 255, 255); // Azure
            break;
        case 6:
        case 2:
            rgblight_sethsv(245, 255, 255); // Red
            break;
        case 7:
        case 3:
            rgblight_sethsv(35, 255, 255); // Gold
            break;
        default:
            rgblight_sethsv(180, 255, 255); // Violet
            break;
    }
    return state;
}
