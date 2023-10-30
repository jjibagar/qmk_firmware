SRC += oled.c


EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = legacy

#A partir de aqui es cosecha propia

BOOTMAGIC_ENABLE = no       # ENABLE BOOTMAGIC Lite
MOUSEKEY_ENABLE = yes        # Mouse keys
EXTRAKEY_ENABLE = yes        # Audio control and System control
NKRO_ENABLE= yes

TAP_DANCE_ENABLE = yes
SLEEP_LED_ENABLE = yes


#LTO_ENABLE = yes
# significantly reduce the compiled size,but disable the legacy TMK Macros and Functions features
# de momento lo dejo encendido porque no creo que me falte memoria

# vamos a por ol unicode
 UNICODE_ENABLE = yes
# UNICODEMAP_ENABLE = yes // OTRA FORMA DE UNICODE CON MAS SIMBOLOS INCOMPATIBLE CON UNICODE_ENABLE

# activo los combos para lo de i+d
 COMBO_ENABLE = yes

RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes

# configuracion cirque
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
