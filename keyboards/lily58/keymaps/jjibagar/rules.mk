# Bootloader selection, para elegir si hacer boot con el pro-micro o con el elite
BOOTLOADER = atmel-dfu
#BOOTLOADER = caterina


BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes        # Audio control and System control

#BACKLIGHT_ENABLE = yes     # Enable keyboard backlight functionality
#BACKLIGHT_DRIVER = software

AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no     # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
OLED_ENABLE= yes     # OLED display //

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812  
NKRO_ENABLE        = yes #registrar pulsaciones multiples

TAP_DANCE_ENABLE = yes
SLEEP_LED_ENABLE = yes
SPLIT_KEYBOARD = yes

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
       ./lib/keylogger.c \

# ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \

LTO_ENABLE = yes
# significantly reduce the compiled size,but disable the legacy TMK Macros and Functions features

# vamos a por ol unicode
UNICODE_ENABLE = yes
# UNICODEMAP_ENABLE = yes // OTRA FORMA DE UNICODE CON MAS SIMBOLOS INCOMPATIBLE CON UNICODE_ENABLE

# activo los combos para lo de i+d
COMBO_ENABLE = no


#desactivando
CAPS_WORD_ENABLE = no
AUTO_SHIFT_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no
MUSIC_ENABLE = no 
MIDI_ENABLE = no 
BLUETOOTH_ENABLE = no
NKRO_ENABLE = no
BACKLIGHT_ENABLE = no
