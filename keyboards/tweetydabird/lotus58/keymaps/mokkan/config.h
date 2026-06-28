#pragma once

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define HOLD_ON_OTHER_KEY_PRESS

// using custom logic in keymap to always/only enable oled on right hand
#define OLED_TIMEOUT 0
#undef SPLIT_OLED_ENABLE

#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4

#define SPLIT_ACTIVITY_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE
