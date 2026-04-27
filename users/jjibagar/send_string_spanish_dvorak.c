#include "keymap_spanish_dvorak.h"

static uint32_t decode_utf8(const char **str) {
    uint32_t code = 0;
    uint8_t c = **str;

    if ((c & 0x80) == 0) {
        code = c;
        (*str)++;
    } else if ((c & 0xE0) == 0xC0) {  // 2-byte
        code = ((c & 0x1F) << 6) | ((*str)[1] & 0x3F);
        (*str) += 2;
    } else if ((c & 0xF0) == 0xE0) {  // 3-byte
        code = ((c & 0x0F) << 12) | (((*str)[1] & 0x3F) << 6) | ((*str)[2] & 0x3F);
        (*str) += 3;
    }
    return code;
}

void send_string_spanish_dvorak(const char *str) {
    while (*str) {
        uint32_t code = decode_utf8(&str);

        switch (code) {
            // Tildes
            case 0xE1: tap_code16(DV_ACUT); tap_code(DV_A); break;      // á
            case 0xC1: tap_code16(DV_ACUT); tap_code16(S(DV_A)); break; // Á
            case 0xE9: tap_code16(DV_ACUT); tap_code(DV_E); break;      // é
            case 0xC9: tap_code16(DV_ACUT); tap_code16(S(DV_E)); break; // É
            case 0xED: tap_code16(DV_ACUT); tap_code(DV_I); break;      // í
            case 0xCD: tap_code16(DV_ACUT); tap_code16(S(DV_I)); break; // Í
            case 0xF3: tap_code16(DV_ACUT); tap_code(DV_O); break;      // ó
            case 0xD3: tap_code16(DV_ACUT); tap_code16(S(DV_O)); break; // Ó
            case 0xFA: tap_code16(DV_ACUT); tap_code(DV_U); break;      // ú
            case 0xDA: tap_code16(DV_ACUT); tap_code16(S(DV_U)); break; // Ú

            // Diéresis
            case 0xFC: tap_code16(S(DV_ACUT)); tap_code(DV_U); break;       // ü
            case 0xDC: tap_code16(S(DV_ACUT)); tap_code16(S(DV_U)); break;  // Ü

            // Ñ/ñ y Ç/ç
            case 0xF1: tap_code(DV_NTIL); break;        // ñ
            case 0xD1: tap_code16(S(DV_NTIL)); break;   // Ñ
            case 0xE7: tap_code(DV_CCED); break;        // ç
            case 0xC7: tap_code16(S(DV_CCED)); break;   // Ç

            // Símbolos especiales
            case 0xA1: tap_code16(DV_IEXL); break;  // ¡
            case 0xBF: tap_code16(DV_IQUE); break;  // ¿
            case 0xAA: tap_code16(DV_FORD); break;  // ª
            case 0xBA: tap_code(DV_MORD); break;    // º
// Letras minúsculas
	case 'a': tap_code(DV_A); break;      // a
	case 'b': tap_code(DV_B); break;      // b
	case 'c': tap_code(DV_C); break;      // c
	case 'd': tap_code(DV_D); break;      // #define 
	case 'e': tap_code(DV_E); break;      // e
	case 'f': tap_code(DV_F); break;      // f
	case 'g': tap_code(DV_G); break;      // g
	case 'h': tap_code(DV_H); break;      // h
	case 'i': tap_code(DV_I); break;      // i
	case 'j': tap_code(DV_J); break;      // j
	case 'k': tap_code(DV_K); break;      // k
	case 'l': tap_code(DV_L); break;      // l
	case 'm': tap_code(DV_M); break;      // m
	case 'n': tap_code(DV_N); break;      // n
	case 'o': tap_code(DV_O); break;      // o
	case 'p': tap_code(DV_P); break;      // p
	case 'q': tap_code(DV_Q); break;      // q
	case 'r': tap_code(DV_R); break;      // r
	case 's': tap_code(DV_S); break;      // s
	case 't': tap_code(DV_T); break;      // t
	case 'u': tap_code(DV_U); break;      // u
	case 'v': tap_code(DV_V); break;      // v
	case 'w': tap_code(DV_W); break;      // w
	case 'x': tap_code(DV_X); break;      // x
	case 'y': tap_code(DV_Y); break;      // y
	case 'z': tap_code(DV_Z); break;      // z

// Letras mayúsculas
	case 'A': tap_code16(S(DV_A)); break;  // A
	case 'B': tap_code16(S(DV_B)); break;  // B
	case 'C': tap_code16(S(DV_C)); break;  // C
	case 'D': tap_code16(S(DV_D)); break;  // D
	case 'E': tap_code16(S(DV_E)); break;  // E
	case 'F': tap_code16(S(DV_F)); break;  // F
	case 'G': tap_code16(S(DV_G)); break;  // G
	case 'H': tap_code16(S(DV_H)); break;  // H
	case 'I': tap_code16(S(DV_I)); break;  // I
	case 'J': tap_code16(S(DV_J)); break;  // J
	case 'K': tap_code16(S(DV_K)); break;  // K
	case 'L': tap_code16(S(DV_L)); break;  // L
	case 'M': tap_code16(S(DV_M)); break;  // M
	case 'N': tap_code16(S(DV_N)); break;  // N
	case 'O': tap_code16(S(DV_O)); break;  // O
	case 'P': tap_code16(S(DV_P)); break;  // P
	case 'Q': tap_code16(S(DV_Q)); break;  // Q
	case 'R': tap_code16(S(DV_R)); break;  // R
	case 'S': tap_code16(S(DV_S)); break;  // S
	case 'T': tap_code16(S(DV_T)); break;  // T
	case 'U': tap_code16(S(DV_U)); break;  // U
	case 'V': tap_code16(S(DV_V)); break;  // V
	case 'W': tap_code16(S(DV_W)); break;  // W
	case 'X': tap_code16(S(DV_X)); break;  // X
	case 'Y': tap_code16(S(DV_Y)); break;  // Y
	case 'Z': tap_code16(S(DV_Z)); break;  // Z

            // Símbolos que dependen del sistema operativo
		// case 0x20AC: tap_os_dependent_key(EURO); break; // €
//            case 0x7E: tap_os_dependent_key(WAVE); break;   // ~

            // Shift + números
            case 0x21: tap_code16(DV_EXLM); break;  // !
            case 0x22: tap_code16(DV_DQUO); break;  // "
            case 0xB7: tap_code16(DV_BULT); break;  // ·
            case 0x24: tap_code16(DV_DLR);  break;  // $
            case 0x25: tap_code16(DV_PERC); break;  // %
            case 0x26: tap_code16(DV_AMPR); break;  // &
            case 0x2F: tap_code16(DV_SLSH); break;  // /
            case 0x28: tap_code16(DV_LPRN); break;  // (
            case 0x29: tap_code16(DV_RPRN); break;  // )
            case 0x3D: tap_code16(DV_EQL);  break;  // =
            case 0x3F: tap_code16(DV_QUES); break;  // ?

            // AltGr
            case 0x5C: tap_code16(DV_BSLS); break;  // barra invertida
            case 0x7C: tap_code16(DV_PIPE); break;  // |
            case 0x40: tap_code16(DV_AT);   break;  // @
            case 0x23: tap_code16(DV_HASH); break;  // #
            case 0xAC: tap_code16(DV_NOT);  break;  // ¬
            case 0x5B: tap_code16(DV_LBRC); break;  // [
            case 0x5D: tap_code16(DV_RBRC); break;  // ]
            case 0x7B: tap_code16(DV_LCBR); break;  // {
            case 0x7D: tap_code16(DV_RCBR); break;  // }
            case 0x3B: tap_code16(DV_SCLN); break;  // ;
            case 0x3A: tap_code16(DV_COLN); break;  // :
            case 0x5F: tap_code16(DV_UNDS); break;  // _
// el codigo siguiente solo funciona para qwerty, por la posicion de ANSI-ISO para dvorak hay que mapear caracter a caracter 
            default:
                if (code >= 'a' && code <= 'z') tap_code(DV_A + (code - 'a'));
                else if (code >= 'A' && code <= 'Z') tap_code16(S(DV_A + (code - 'A')));
                else if (code >= '0' && code <= '9') tap_code(DV_0 + (code - '0'));
                else send_char(code);
                break;
        }
    }
}
