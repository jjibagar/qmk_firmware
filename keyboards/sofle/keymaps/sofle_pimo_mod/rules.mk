
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
ENCODER_ENABLE = yes
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes 

#Sparkfun Config
CONVERT_TO=promicro_rp2040
BOOTLOADER = rp2040

#Pimoroni config
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pimoroni_trackball

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812  

SRC += features/pimoroni.c



# vamos a por ol unicode
UNICODE_ENABLE = yes

TAP_DANCE_ENABLE = yes
SLEEP_LED_ENABLE = yes


NKRO_ENABLE  = yes #registrar pulsaciones multiples
# activo los combos para lo de i+d
 COMBO_ENABLE = yes
