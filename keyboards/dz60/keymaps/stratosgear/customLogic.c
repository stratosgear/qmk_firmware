
#include QMK_KEYBOARD_H
#include "customLogic.h"
#include "keymap.h"

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
        case L_QWERTY:
            // rgblight_mode(9);
            backlight_disable();
            break;
        case L_NAV:
            // rgblight_mode(29);
            backlight_enable();
            break;
        case L_LIGHT:
            rgblight_mode(26);
            break;
        case L_MACROS:
            rgblight_mode(1);
            break;
        case L_MOUSE:
            rgblight_mode(25);
            break;
    }
    return state;
}
