#pragma once
#include <stdint.h>

typedef struct rtc_time {
    uint8_t sec;
    uint8_t min;
    uint8_t hour;
    uint8_t day;
    uint8_t mon;
    uint16_t year;
} time_t;

int _time(time_t *buf);