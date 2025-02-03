
#include"jjibagar.h"
//#include "keymap_spanish_dvorak.h"
//#include "sendstring_spanish_dvorak.h"


#ifdef COMBO_ENABLE

enum combos {
  CB_ALTGR_ONE_SHOT,
  CB_DVK_TIL_A,
  CB_DVK_TIL_O,
  CB_DVK_TIL_E,
  CB_DVK_TIL_U,
  CB_DVK_TIL_I,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

// Combo funcionts
const uint16_t PROGMEM altg_oneshot[] = {DV_I, DV_D, COMBO_END};
const uint16_t PROGMEM dvk_a_til_combo[] = {LGUI_T(DV_A), RSFT_T(DV_R), COMBO_END};
const uint16_t PROGMEM dvk_o_til_combo[] = {LALT_T(DV_O), RSFT_T(DV_R), COMBO_END};
const uint16_t PROGMEM dvk_e_til_combo[] = {LCTL_T(DV_E), RSFT_T(DV_R), COMBO_END};
const uint16_t PROGMEM dvk_u_til_combo[] = {LSFT_T(DV_U), RSFT_T(DV_R), COMBO_END};
const uint16_t PROGMEM dvk_i_til_combo[] = {DV_I, RSFT_T(DV_R), COMBO_END};


combo_t key_combos[] = {
    

  [CB_ALTGR_ONE_SHOT] = COMBO(altg_oneshot, ALTGR_ONE_SHOT ),
  [CB_DVK_TIL_A] = COMBO(dvk_a_til_combo, TIL_A ),
  [CB_DVK_TIL_O] = COMBO(dvk_o_til_combo, TIL_O ),
  [CB_DVK_TIL_E] = COMBO(dvk_e_til_combo, TIL_E ),
  [CB_DVK_TIL_U] = COMBO(dvk_u_til_combo, TIL_U),
  [CB_DVK_TIL_I] = COMBO(dvk_i_til_combo, TIL_I ),
};
#endif
