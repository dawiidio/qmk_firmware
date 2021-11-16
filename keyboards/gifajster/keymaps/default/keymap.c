// Copyright 2021 Dawid Wojda (@dawiidio)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE
};

enum custom_keycodes {
    PREV = SAFE_RANGE,
    TOGGLE,
    NEXT
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(RAG(KC_8));
        } else {
            tap_code16(RAG(KC_9));
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code16(RAG(KC_AUDIO_VOL_UP));
        } else {
            tap_code16(RAG(KC_AUDIO_VOL_DOWN));
        }
    }

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PREV:
        if (record->event.pressed) {
            tap_code(KC_MEDIA_PREV_TRACK);
        }
        break;
    case TOGGLE:
        if (record->event.pressed) {
            tap_code(KC_MEDIA_PLAY_PAUSE);
        }
        break;
    case NEXT:
        if (record->event.pressed) {
            tap_code(KC_MEDIA_NEXT_TRACK);
        }
        break;
    }

    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        PREV, 
        TOGGLE, 
        NEXT
    )
};
