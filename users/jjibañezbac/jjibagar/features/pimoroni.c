#include "pimoroni.h"

bool scrolling_mode = false;

//pimoroni config

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}


report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling_mode) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool is_mouse_record_kb(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case KC_ENT:
            return true;
        case KC_RIGHT ... KC_UP:
            return true;
        default:
            return false;
    }
    return  is_mouse_record_user(keycode, record);
}


