#include QMK_KEYBOARD_H
#include "keymap.h"
#include "customLogic.h"

#define LEADER_TIMEOUT 500 


LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;

        // emails
        SEQ_TWO_KEYS(KC_E, KC_G) { SEND_STRING("stratosgear@gmail.com"); }
        SEQ_TWO_KEYS(KC_E, KC_S) { SEND_STRING("stratos@gerakakis.net"); }

        // development macros
        SEQ_TWO_KEYS(KC_D, KC_T) { SEND_STRING("tmuxp load ."); }

        leader_end();
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [L_QWERTY] = 
        LAYOUT_directional(

        // |--------|----1---|----2---|----3---|---4----|---5----|---6----|---7----|---8----|---9----|---0----|-- - ---|-- = ---|-- ~ ---/--BSPC--|
             KC_GESC,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS,  KC_EQL,  KC_GRV,  KC_LEAD,
        // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------||------//--------|  
        //  
        // |----TAB-----||---Q----|---W----|---E----|---R----|---T----|---Y----|---U----|---I----|---O----|---P----|-- [ ---|-- ] ---|---- \ -----|
               KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS, 
        // |------------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------------|
        //
        // |----CAPS------||---A----|---S----|---D----|---F----|---G----|---H----|---J----|---K----|---L----|---;----|---'----|---- ENTER -------||
              KC_LGUI,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_QUOT,    KC_ENT, 
        // |--------------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------------------||
        //
        // |----- SHIFT -----|---Z----|---X----|---C----|---V----|---B----|---N----|---M----|---,----|---.----|-- / ---|--SHFT--|-- UP --|--DEL--||
                 KC_LSFT,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,  KC_PGDN, 
        // |-----------------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|-------||
        //
        // |---CTRL---|----WIN---||----ALT---||--------SPACE---------||----FN----|------BCKSPC------||---FN---|--CTRL--|--LEFT--|--DOWN--|-RIGHT--|    
              KC_LCTL,    TO_NAV,    KC_LALT,           KC_SPC,           MO(4),         KC_BSPC,       MO(2),   MO(3),  KC_LEFT, KC_DOWN, KC_RGHT),
        // |---1.25---|---1.25---||---1.25---||--------2.25----------||---1.25---|------2.75--------||---1----|---1----|---1----|---1----|----1---|    
                                                              
    [L_NAV] = // Super
        LAYOUT_directional(
        // |--------|----1---|----2---|----3---|---4----|---5----|---6----|---7----|---8----|---9----|---0----|-- - ---|-- = ---|-- ~ ---/--BSPC--|
              KC_NO,   KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,  KC_NO, 
        // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------||------//--------|  
        //  
        // |----TAB-----||---Q----|---W----|---E----|---R----|---T----|---Y----|---U----|---I----|---O----|---P----|-- [ ---|-- ] ---|---- \ -----|
               KC_NO,      KC_P7,   KC_P8,   KC_P9,  KC_PPLS,  KC_NO,   KC_NO,  KC_HOME,  KC_UP,   KC_END, KC_PGUP,  KC_NO,   KC_NO,     KC_NO, 
        // |------------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------------|
        //
        // |----CAPS------||---A----|---S----|---D----|---F----|---G----|---H----|---J----|---K----|---L----|---;----|---'----|---- ENTER -------||
                KC_NO,       KC_P4,   KC_P5,   KC_P6,  KC_PMNS,  KC_NO,   KC_NO,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,  KC_NO,       KC_NO, 
        // |--------------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------------------||
        //
        // |----- SHIFT -----|---Z----|---X----|---C----|---V----|---B----|---N----|---M----|---,----|---.----|-- / ---|--SHFT--|-- UP --|--DEL--||
                  KC_NO,       KC_P1,   KC_P2,   KC_P3,  KC_PAST,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_HOME,  KC_NO,   KC_END, 
        // |-----------------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|-------||
        //
        // |---CTRL---|----WIN---||----ALT---||--------SPACE---------||----FN----|------BCKSPC------||---FN---|--CTRL--|--LEFT--|--DOWN--|-RIGHT--|    
             KC_TRNS,    KC_TRNS,    KC_P0,           KC_PDOT,           KC_NO,         KC_DEL,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO),
        // |---1.25---|---1.25---||---1.25---||--------2.25----------||---1.25---|------2.75--------||---1----|---1----|---1----|---1----|----1---|    

    [L_LIGHT]  = // Right Alt
        LAYOUT_directional(
        // |--------|----1---|----2---|----3---|---4----|---5----|---6----|---7----|---8----|---9----|---0----|-- - ---|-- = ---|-- ~ ---/--BSPC--|
              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
        // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------||------//--------|  
        //  
        // |----TAB-----||---Q----|---W----|---E----|---R----|---T----|---Y----|---U----|---I----|---O----|---P----|-- [ ---|-- ] ---|---- \ -----|
               KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_SPI, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG,   KC_NO, 
        // |------------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------------|
        //
        // |----CAPS------||---A----|---S----|---D----|---F----|---G----|---H----|---J----|---K----|---L----|---;----|---'----|---- ENTER -------||
               KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, RGB_SPD, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD,      KC_NO, 
        // |--------------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------------------||
        //
        // |----- SHIFT -----|---Z----|---X----|---C----|---V----|---B----|---N----|---M----|---,----|---.----|-- / ---|--SHFT--|-- UP --|--DEL--||
                  KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  BL_INC,  BL_TOGG, 
        // |-----------------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|-------||
        //
        // |---CTRL---|----WIN---||----ALT---||--------SPACE---------||----FN----|------BCKSPC------||---FN---|--CTRL--|--LEFT--|--DOWN--|-RIGHT--|    
              KC_NO,      KC_NO,      KC_NO,           KC_NO,             KC_NO,         KC_NO,       KC_TRNS,  KC_NO,   KC_NO,   BL_DEC,  KC_NO),
        // |---1.25---|---1.25---||---1.25---||--------2.25----------||---1.25---|------2.75--------||---1----|---1----|---1----|---1----|----1---|    

    [L_MACROS] = // Right CTRL
        LAYOUT_directional(
        // |--------|----1---|----2---|----3---|---4----|---5----|---6----|---7----|---8----|---9----|---0----|-- - ---|-- = ---|-- ~ ---/--BSPC--|
              KC_NO,   KC_F13,  KC_F14,  KC_F15, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,    RESET, EEP_RST, 
        // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------||------//--------|  
        //  
        // |----TAB-----||---Q----|---W----|---E----|---R----|---T----|---Y----|---U----|---I----|---O----|---P----|-- [ ---|-- ] ---|---- \ -----|
               KC_NO,     DM_REC1, DM_REC2,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_PSCR,  KC_NO,   KC_NO,     KC_NO, 
        // |------------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------------|
        //
        // |----CAPS------||---A----|---S----|---D----|---F----|---G----|---H----|---J----|---K----|---L----|---;----|---'----|---- ENTER -------||
                KC_NO,      DM_PLY1, DM_PLY2,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO, 
        // |--------------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------------------||
        //
        // |----- SHIFT -----|---Z----|---X----|---C----|---V----|---B----|---N----|---M----|---,----|---.----|-- / ---|--SHFT--|-- UP --|--DEL--||
                  KC_NO,      DM_RSTP,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, 
        // |-----------------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|-------||
        //
        // |---CTRL---|----WIN---||----ALT---||--------SPACE---------||----FN----|------BCKSPC------||---FN---|--CTRL--|--LEFT--|--DOWN--|-RIGHT--|    
               KC_NO,    KC_TRNS,     KC_NO,           KC_NO,             KC_NO,         KC_NO,         KC_NO,  KC_TRNS,  KC_NO,  KC_NO,  KC_NO),
        // |---1.25---|---1.25---||---1.25---||--------2.25----------||---1.25---|------2.75--------||---1----|---1----|---1----|---1----|----1---|    

    [L_MOUSE]  = // SPC FN
        LAYOUT_directional(
        // |--------|----1---|----2---|----3---|---4----|---5----|---6----|---7----|---8----|---9----|---0----|-- - ---|-- = ---|-- ~ ---/--BSPC--|
              KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        // |--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------||------//--------|  
        //  
        // |----TAB-----||---Q----|---W----|---E----|---R----|---T----|---Y----|---U----|---I----|---O----|---P----|-- [ ---|-- ] ---|---- \ -----|
               KC_NO,      KC_NO,  KC_MS_U,  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_WH_U, KC_BTN1, KC_BTN2, KC_BTN3,  KC_NO,   KC_NO,     KC_NO, 
        // |------------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------------|
        //
        // |----CAPS------||---A----|---S----|---D----|---F----|---G----|---H----|---J----|---K----|---L----|---;----|---'----|---- ENTER -------||
               KC_NO,       KC_MS_L, KC_MS_D, KC_MS_R,  KC_NO,   KC_NO,   KC_NO,  KC_WH_D,  KC_NO,   KC_NO,   KC_NO,  KC_MUTE,      KC_NO, 
        // |--------------||--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|------------------||
        //
        // |----- SHIFT -----|---Z----|---X----|---C----|---V----|---B----|---N----|---M----|---,----|---.----|-- / ---|--SHFT--|-- UP --|--DEL--||
                  KC_NO,      KC_ACL0, KC_ACL1, KC_ACL2,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_VOLD, KC_VOLU, KC_MPLY,  KC_NO, 
        // |-----------------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|-------||
        //
        // |---CTRL---|----WIN---||----ALT---||--------SPACE---------||----FN----|------BCKSPC------||---FN---|--CTRL--|--LEFT--|--DOWN--|-RIGHT--|    
        // |---1.25---|---1.25---||---1.25---||--------2.25----------||---1.25---|------2.75--------||---1----|---1----|---1----|---1----|----1---|    
              KC_NO,      KC_NO,      KC_NO,           KC_NO,           KC_TRNS,         KC_NO,        KC_NO,   KC_TRNS, KC_MPRV, KC_MSTP, KC_MNXT),
    };
