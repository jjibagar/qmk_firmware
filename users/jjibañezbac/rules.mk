SRC += jjibañez.c
SRC += combos.c
#A partir de aqui es cosecha propia

BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
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

# no se para que vale muse, lo he puesto por alfred
ifdef AUDIO_ENABLE
	SRC += muse.c
endif

# esto es de la guia, no se si es necesario, es para cancelar macros creo
# ifeq ($(strip $(MACROS_ENABLED)), yes)
#    OPT_DEFS += -DMACROS_ENABLED
# endif
