/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

#include <stdint.h>
#include <stdbool.h>

#ifndef _RTCC_H
#define _RTCC_H

typedef struct
{
    bool bcdFormat;
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t weekday;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} RTCC_DATETIME;

enum RTCC_ALARM_FREQUENCY
{
    RTCC_ALARM_FREQUENCY_HALF_SECOND    = 0b0000,
    RTCC_ALARM_FREQUENCY_SECOND         = 0b0001,
    RTCC_ALARM_FREQUENCY_10_SECONDS     = 0b0010,
    RTCC_ALARM_FREQUENCY_MINUTE         = 0b0011,
    RTCC_ALARM_FREQUENCY_10_MINUTES     = 0b0100,
    RTCC_ALARM_FREQUENCY_HOUR           = 0b0101,
    RTCC_ALARM_FREQUENCY_DAY            = 0b0110,
    RTCC_ALARM_FREQUENCY_WEEK           = 0b0111,
    RTCC_ALARM_FREQUENCY_MONTH          = 0b1000,
    RTCC_ALARM_FREQUENCY_YEAR           = 0b1001
};

void RTCC_Initialize (RTCC_DATETIME * value);
void RTCC_TimeGet (RTCC_DATETIME * value);
void RTCC_BuildTimeGet( RTCC_DATETIME *dateTime);
void RTCC_AlarmEnable(bool enable);
void RTCC_ChimeEnable(bool enable);
void RTCC_AlarmSet(RTCC_DATETIME * alarm, uint8_t count);
void RTCC_AlarmFrequency(enum RTCC_ALARM_FREQUENCY frequency);

#endif
