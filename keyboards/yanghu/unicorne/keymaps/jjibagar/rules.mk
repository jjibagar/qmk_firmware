
# activo los combos para lo de i+d
 COMBO_ENABLE = yes

RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes

# no se para que vale muse, lo he puesto por alfred
ifdef AUDIO_ENABLE
	SRC += muse.c
endif


# configuracion cirque
# POINTING_DEVICE_ENABLE = yes
# POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
