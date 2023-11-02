#pragma once
#include "quantum.h"

extern bool scrolling_mode;

void pointing_device_init_user(void);
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report);
bool is_mouse_record_kb(uint16_t keycode, keyrecord_t* record);


