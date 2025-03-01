#include "jjibagar.h"

enum custom_keycodes {
    //QWERTY = SAFE_RANGE,
  KC_MAKE = SAFE_RANGE,
  NEW_SAFE_RANGE,  //use "NEW_SAFE_RANGE" for keymap specific codes
  MACRO1,
  MACRO2,
  MACRO3,
  MACRO4,
  MACRO5,
  UNICODE,
  RIGTHARROW,
  LEFTARROW,
  UPARROW,
  DOWNARROW,
  TAURUS,
  ALT_TAB,
  ALTGR_ONE_SHOT,
  TIL_A,
  TIL_O,
  TIL_E,
  TIL_U,
  TIL_I,
  // codigos emacs
  SAVE,
  SAVE_AS,
  MAGIT,
  SALTO,
  COMPLETADO,
  BASE,
  JUEGOS,
  AVY_LINE,
  RECENT,
  TAB,
  OPEN,
  BUFFER,
  KILL,
  ORGPDF,
  V1,
  V2,
  V3,
  V0,
  ACE_W,
  //codigos datos personles
  inicio
};


/* / Tap Dance keycodes
enum td_keycodes {
    ALT_LP, // Our example key: LALT when held, ( when tapped. Add additional keycodes for each tapdance.
    CTRL_LP,
    LSFT_LP
};
*/

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define EMACS MO(_EMACS)
#define JUEGOS DF(_JUEGOS)
#define NUM MO(_NUM)
#define BASE DF(_BASE)
// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
