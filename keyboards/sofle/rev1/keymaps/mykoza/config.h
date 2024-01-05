#pragma once

#define EE_HANDS

#undef DEBOUNCE
#define DEBOUNCE 5
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 10

#undef TAPPING_TERM
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

#define AUTO_SHIFT_TIMEOUT 150

#ifdef NKRO_ENABLE
#    define FORCE_NKRO // Force NKRO if enabled.
#endif

#ifdef OLED_ENABLE
#    define OLED_TIMEOUT 20000
#    define OLED_BRIGHTNESS 90
#endif

// Disabled for LTO and save space
#define LAYER_STATE_8BIT
#define NO_ACTION_ONESHOT // Save 244 bytes
//#define NO_RESET //Save 40 bytes