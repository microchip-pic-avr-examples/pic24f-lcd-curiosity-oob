/*******************************************************************************
Copyright 2019 Microchip Technology Inc. (www.microchip.com)

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

#ifndef LCD1_H
#define LCD1_H

#include <stdint.h>

#include "lcd1_7seg.h"
#include "lcd1_16seg.h"
#include "lcd1_segments.h"

#include <xc.h>

enum LCD1_MODE
{
    LCD1_MODE_NORMAL,
    LCD1_MODE_BLINK,
    LCD1_MODE_ALTERNATE
};

enum LCD1_POWER_LEVEL
{
    LCD1_POWER_LEVEL_HIGH = 0x03,
    LCD1_POWER_LEVEL_MEDIUM = 0x02,
    LCD1_POWER_LEVEL_LOW = 0x01,
    LCD1_POWER_LEVEL_OFF = 0x00
};
            
void LCD1_Initialize(void);
void LCD1_ModeSet(enum LCD1_MODE mode);
void LCD1_LadderAPowerLevelSet(enum LCD1_POWER_LEVEL power_level);
void LCD1_LadderBPowerLevelSet(enum LCD1_POWER_LEVEL power_level);

#endif

