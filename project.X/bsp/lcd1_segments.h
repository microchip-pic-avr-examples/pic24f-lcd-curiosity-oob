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

#ifndef LCD1_SEGMENTS_H
#define LCD1_SEGMENTS_H

#include <xc.h>

enum LCD1_SEGMENT_CONTROL
{
    LCD1_SEGMENT_OFF = 0,
    LCD1_SEGMENT_ON = 1
};

#define    LCD1_PeriodIcon1_Set(value) LCDDATA13bits.S18C3 = value
#define    LCD1_PeriodIcon1_On() LCDDATA13bits.S18C3 = 1
#define    LCD1_PeriodIcon1_Off() LCDDATA13bits.S18C3 = 0
#define    LCD1_PeriodIcon1_AltSet(value) LCDSDATA13bits.S18C3 = value
#define    LCD1_PeriodIcon1_AltOn() LCDSDATA13bits.S18C3 = 1
#define    LCD1_PeriodIcon1_AltOff() LCDSDATA13bits.S18C3 = 0

#define    LCD1_PeriodIcon2_Set(value) LCDDATA29bits.S18C7 = value
#define    LCD1_PeriodIcon2_On() LCDDATA29bits.S18C7 = 1
#define    LCD1_PeriodIcon2_Off() LCDDATA29bits.S18C7 = 0
#define    LCD1_PeriodIcon2_AltSet(value) LCDSDATA29bits.S18C7 = value
#define    LCD1_PeriodIcon2_AltOn() LCDSDATA29bits.S18C7 = 1
#define    LCD1_PeriodIcon2_AltOff() LCDSDATA29bits.S18C7 = 0

#define    LCD1_PeriodIcon3_Set(value) LCDDATA13bits.S19C3 = value
#define    LCD1_PeriodIcon3_On() LCDDATA13bits.S19C3 = 1
#define    LCD1_PeriodIcon3_Off() LCDDATA13bits.S19C3 = 0
#define    LCD1_PeriodIcon3_AltSet(value) LCDSDATA13bits.S19C3 = value
#define    LCD1_PeriodIcon3_AltOn() LCDSDATA13bits.S19C3 = 1
#define    LCD1_PeriodIcon3_AltOff() LCDSDATA13bits.S19C3 = 0

#define    LCD1_PeriodIcon4_Set(value) LCDDATA29bits.S26C7 = value
#define    LCD1_PeriodIcon4_On() LCDDATA29bits.S26C7 = 1
#define    LCD1_PeriodIcon4_Off() LCDDATA29bits.S26C7 = 0
#define    LCD1_PeriodIcon4_AltSet(value) LCDSDATA29bits.S26C7 = value
#define    LCD1_PeriodIcon4_AltOn() LCDSDATA29bits.S26C7 = 1
#define    LCD1_PeriodIcon4_AltOff() LCDSDATA29bits.S26C7 = 0

#define    LCD1_PeriodIcon5_Set(value) LCDDATA9bits.S26C2 = value
#define    LCD1_PeriodIcon5_On() LCDDATA9bits.S26C2 = 1
#define    LCD1_PeriodIcon5_Off() LCDDATA9bits.S26C2 = 0
#define    LCD1_PeriodIcon5_AltSet(value) LCDSDATA9bits.S26C2 = value
#define    LCD1_PeriodIcon5_AltOn() LCDSDATA9bits.S26C2 = 1
#define    LCD1_PeriodIcon5_AltOff() LCDSDATA9bits.S26C2 = 0

#define    LCD1_PeriodIcon6_Set(value) LCDDATA29bits.S28C7 = value
#define    LCD1_PeriodIcon6_On() LCDDATA29bits.S28C7 = 1
#define    LCD1_PeriodIcon6_Off() LCDDATA29bits.S28C7 = 0
#define    LCD1_PeriodIcon6_AltSet(value) LCDSDATA29bits.S28C7 = value
#define    LCD1_PeriodIcon6_AltOn() LCDSDATA29bits.S28C7 = 1
#define    LCD1_PeriodIcon6_AltOff() LCDSDATA29bits.S28C7 = 0

#define    LCD1_Colon_Set(value) LCDDATA29bits.S19C7 = value
#define    LCD1_Colon_On() LCDDATA29bits.S19C7 = 1
#define    LCD1_Colon_Off() LCDDATA29bits.S19C7 = 0
#define    LCD1_Colon_AltSet(value) LCDSDATA29bits.S19C7 = value
#define    LCD1_Colon_AltOn() LCDSDATA29bits.S19C7 = 1
#define    LCD1_Colon_AltOff() LCDSDATA29bits.S19C7 = 0

#define    LCD1_Logos_Set(value) LCDDATA5bits.S26C1 = value
#define    LCD1_Logos_On() LCDDATA5bits.S26C1 = 1
#define    LCD1_Logos_Off() LCDDATA5bits.S26C1 = 0
#define    LCD1_Logos_AltSet(value) LCDSDATA5bits.S26C1 = value
#define    LCD1_Logos_AltOn() LCDSDATA5bits.S26C1 = 1
#define    LCD1_Logos_AltOff() LCDSDATA5bits.S26C1 = 0

#define    LCD1_BatteryBarLow_Set(value) LCDDATA1bits.S28C0 = value
#define    LCD1_BatteryBarLow_On() LCDDATA1bits.S28C0 = 1
#define    LCD1_BatteryBarLow_Off() LCDDATA1bits.S28C0 = 0
#define    LCD1_BatteryBarLow_AltSet(value) LCDSDATA1bits.S28C0 = value
#define    LCD1_BatteryBarLow_AltOn() LCDSDATA1bits.S28C0 = 1
#define    LCD1_BatteryBarLow_AltOff() LCDSDATA1bits.S28C0 = 0

#define    LCD1_BatteryBarMiddle_Set(value) LCDDATA1bits.S26C0 = value
#define    LCD1_BatteryBarMiddle_On() LCDDATA1bits.S26C0 = 1
#define    LCD1_BatteryBarMiddle_Off() LCDDATA1bits.S26C0 = 0
#define    LCD1_BatteryBarMiddle_AltSet(value) LCDSDATA1bits.S26C0 = value
#define    LCD1_BatteryBarMiddle_AltOn() LCDSDATA1bits.S26C0 = 1
#define    LCD1_BatteryBarMiddle_AltOff() LCDSDATA1bits.S26C0 = 0

#define    LCD1_BatteryBarHigh_Set(value) LCDDATA1bits.S27C0 = value
#define    LCD1_BatteryBarHigh_On() LCDDATA1bits.S27C0 = 1
#define    LCD1_BatteryBarHigh_Off() LCDDATA1bits.S27C0 = 0
#define    LCD1_BatteryBarHigh_AltSet(value) LCDSDATA1bits.S27C0 = value
#define    LCD1_BatteryBarHigh_AltOn() LCDSDATA1bits.S27C0 = 1
#define    LCD1_BatteryBarHigh_AltOff() LCDSDATA1bits.S27C0 = 0

#define    LCD1_MoonIcon_Set(value) LCDDATA5bits.S28C1 = value
#define    LCD1_MoonIcon_On() LCDDATA5bits.S28C1 = 1
#define    LCD1_MoonIcon_Off() LCDDATA5bits.S28C1 = 0
#define    LCD1_MoonIcon_AltSet(value) LCDSDATA5bits.S28C1 = value
#define    LCD1_MoonIcon_AltOn() LCDSDATA5bits.S28C1 = 1
#define    LCD1_MoonIcon_AltOff() LCDSDATA5bits.S28C1 = 0

#define    LCD1_Char1A_Set(value) LCDDATA0bits.S04C0 = value
#define    LCD1_Char1A_On() LCDDATA0bits.S04C0 = 1
#define    LCD1_Char1A_Off() LCDDATA0bits.S04C0 = 0
#define    LCD1_Char1A_AltSet(value) LCDSDATA0bits.S04C0 = value
#define    LCD1_Char1A_AltOn() LCDSDATA0bits.S04C0 = 1
#define    LCD1_Char1A_AltOff() LCDSDATA0bits.S04C0 = 0

#define    LCD1_Char1B_Set(value) LCDDATA1bits.S18C0 = value
#define    LCD1_Char1B_On() LCDDATA1bits.S18C0 = 1
#define    LCD1_Char1B_Off() LCDDATA1bits.S18C0 = 0
#define    LCD1_Char1B_AltSet(value) LCDSDATA1bits.S18C0 = value
#define    LCD1_Char1B_AltOn() LCDSDATA1bits.S18C0 = 1
#define    LCD1_Char1B_AltOff() LCDSDATA1bits.S18C0 = 0

#define    LCD1_Char1C_Set(value) LCDDATA9bits.S18C2 = value
#define    LCD1_Char1C_On() LCDDATA9bits.S18C2 = 1
#define    LCD1_Char1C_Off() LCDDATA9bits.S18C2 = 0
#define    LCD1_Char1C_AltSet(value) LCDSDATA9bits.S18C2 = value
#define    LCD1_Char1C_AltOn() LCDSDATA9bits.S18C2 = 1
#define    LCD1_Char1C_AltOff() LCDSDATA9bits.S18C2 = 0

#define    LCD1_Char1D_Set(value) LCDDATA12bits.S04C3 = value
#define    LCD1_Char1D_On() LCDDATA12bits.S04C3 = 1
#define    LCD1_Char1D_Off() LCDDATA12bits.S04C3 = 0
#define    LCD1_Char1D_AltSet(value) LCDSDATA12bits.S04C3 = value
#define    LCD1_Char1D_AltOn() LCDSDATA12bits.S04C3 = 1
#define    LCD1_Char1D_AltOff() LCDSDATA12bits.S04C3 = 0

#define    LCD1_Char1E_Set(value) LCDDATA8bits.S04C2 = value
#define    LCD1_Char1E_On() LCDDATA8bits.S04C2 = 1
#define    LCD1_Char1E_Off() LCDDATA8bits.S04C2 = 0
#define    LCD1_Char1E_AltSet(value) LCDSDATA8bits.S04C2 = value
#define    LCD1_Char1E_AltOn() LCDSDATA8bits.S04C2 = 1
#define    LCD1_Char1E_AltOff() LCDSDATA8bits.S04C2 = 0

#define    LCD1_Char1F_Set(value) LCDDATA4bits.S04C1 = value
#define    LCD1_Char1F_On() LCDDATA4bits.S04C1 = 1
#define    LCD1_Char1F_Off() LCDDATA4bits.S04C1 = 0
#define    LCD1_Char1F_AltSet(value) LCDSDATA4bits.S04C1 = value
#define    LCD1_Char1F_AltOn() LCDSDATA4bits.S04C1 = 1
#define    LCD1_Char1F_AltOff() LCDSDATA4bits.S04C1 = 0

#define    LCD1_Char1G_Set(value) LCDDATA5bits.S18C1 = value
#define    LCD1_Char1G_On() LCDDATA5bits.S18C1 = 1
#define    LCD1_Char1G_Off() LCDDATA5bits.S18C1 = 0
#define    LCD1_Char1G_AltSet(value) LCDSDATA5bits.S18C1 = value
#define    LCD1_Char1G_AltOn() LCDSDATA5bits.S18C1 = 1
#define    LCD1_Char1G_AltOff() LCDSDATA5bits.S18C1 = 0

#define    LCD1_Char2A_Set(value) LCDDATA16bits.S04C4 = value
#define    LCD1_Char2A_On() LCDDATA16bits.S04C4 = 1
#define    LCD1_Char2A_Off() LCDDATA16bits.S04C4 = 0
#define    LCD1_Char2A_AltSet(value) LCDSDATA16bits.S04C4 = value
#define    LCD1_Char2A_AltOn() LCDSDATA16bits.S04C4 = 1
#define    LCD1_Char2A_AltOff() LCDSDATA16bits.S04C4 = 0

#define    LCD1_Char2B_Set(value) LCDDATA17bits.S18C4 = value
#define    LCD1_Char2B_On() LCDDATA17bits.S18C4 = 1
#define    LCD1_Char2B_Off() LCDDATA17bits.S18C4 = 0
#define    LCD1_Char2B_AltSet(value) LCDSDATA17bits.S18C4 = value
#define    LCD1_Char2B_AltOn() LCDSDATA17bits.S18C4 = 1
#define    LCD1_Char2B_AltOff() LCDSDATA17bits.S18C4 = 0

#define    LCD1_Char2C_Set(value) LCDDATA25bits.S18C6 = value
#define    LCD1_Char2C_On() LCDDATA25bits.S18C6 = 1
#define    LCD1_Char2C_Off() LCDDATA25bits.S18C6 = 0
#define    LCD1_Char2C_AltSet(value) LCDSDATA25bits.S18C6 = value
#define    LCD1_Char2C_AltOn() LCDSDATA25bits.S18C6 = 1
#define    LCD1_Char2C_AltOff() LCDSDATA25bits.S18C6 = 0

#define    LCD1_Char2D_Set(value) LCDDATA28bits.S04C7 = value
#define    LCD1_Char2D_On() LCDDATA28bits.S04C7 = 1
#define    LCD1_Char2D_Off() LCDDATA28bits.S04C7 = 0
#define    LCD1_Char2D_AltSet(value) LCDSDATA28bits.S04C7 = value
#define    LCD1_Char2D_AltOn() LCDSDATA28bits.S04C7 = 1
#define    LCD1_Char2D_AltOff() LCDSDATA28bits.S04C7 = 0

#define    LCD1_Char2E_Set(value) LCDDATA24bits.S04C6 = value
#define    LCD1_Char2E_On() LCDDATA24bits.S04C6 = 1
#define    LCD1_Char2E_Off() LCDDATA24bits.S04C6 = 0
#define    LCD1_Char2E_AltSet(value) LCDSDATA24bits.S04C6 = value
#define    LCD1_Char2E_AltOn() LCDSDATA24bits.S04C6 = 1
#define    LCD1_Char2E_AltOff() LCDSDATA24bits.S04C6 = 0

#define    LCD1_Char2F_Set(value) LCDDATA20bits.S04C5 = value
#define    LCD1_Char2F_On() LCDDATA20bits.S04C5 = 1
#define    LCD1_Char2F_Off() LCDDATA20bits.S04C5 = 0
#define    LCD1_Char2F_AltSet(value) LCDSDATA20bits.S04C5 = value
#define    LCD1_Char2F_AltOn() LCDSDATA20bits.S04C5 = 1
#define    LCD1_Char2F_AltOff() LCDSDATA20bits.S04C5 = 0

#define    LCD1_Char2G_Set(value) LCDDATA21bits.S18C5 = value
#define    LCD1_Char2G_On() LCDDATA21bits.S18C5 = 1
#define    LCD1_Char2G_Off() LCDDATA21bits.S18C5 = 0
#define    LCD1_Char2G_AltSet(value) LCDSDATA21bits.S18C5 = value
#define    LCD1_Char2G_AltOn() LCDSDATA21bits.S18C5 = 1
#define    LCD1_Char2G_AltOff() LCDSDATA21bits.S18C5 = 0

#define    LCD1_Char3A_Set(value) LCDDATA17bits.S19C4 = value
#define    LCD1_Char3A_On() LCDDATA17bits.S19C4 = 1
#define    LCD1_Char3A_Off() LCDDATA17bits.S19C4 = 0
#define    LCD1_Char3A_AltSet(value) LCDSDATA17bits.S19C4 = value
#define    LCD1_Char3A_AltOn() LCDSDATA17bits.S19C4 = 1
#define    LCD1_Char3A_AltOff() LCDSDATA17bits.S19C4 = 0

#define    LCD1_Char3B_Set(value) LCDDATA17bits.S25C4 = value
#define    LCD1_Char3B_On() LCDDATA17bits.S25C4 = 1
#define    LCD1_Char3B_Off() LCDDATA17bits.S25C4 = 0
#define    LCD1_Char3B_AltSet(value) LCDSDATA17bits.S25C4 = value
#define    LCD1_Char3B_AltOn() LCDSDATA17bits.S25C4 = 1
#define    LCD1_Char3B_AltOff() LCDSDATA17bits.S25C4 = 0

#define    LCD1_Char3C_Set(value) LCDDATA25bits.S25C6 = value
#define    LCD1_Char3C_On() LCDDATA25bits.S25C6 = 1
#define    LCD1_Char3C_Off() LCDDATA25bits.S25C6 = 0
#define    LCD1_Char3C_AltSet(value) LCDSDATA25bits.S25C6 = value
#define    LCD1_Char3C_AltOn() LCDSDATA25bits.S25C6 = 1
#define    LCD1_Char3C_AltOff() LCDSDATA25bits.S25C6 = 0

#define    LCD1_Char3D_Set(value) LCDDATA29bits.S25C7 = value
#define    LCD1_Char3D_On() LCDDATA29bits.S25C7 = 1
#define    LCD1_Char3D_Off() LCDDATA29bits.S25C7 = 0
#define    LCD1_Char3D_AltSet(value) LCDSDATA29bits.S25C7 = value
#define    LCD1_Char3D_AltOn() LCDSDATA29bits.S25C7 = 1
#define    LCD1_Char3D_AltOff() LCDSDATA29bits.S25C7 = 0

#define    LCD1_Char3E_Set(value) LCDDATA25bits.S19C6 = value
#define    LCD1_Char3E_On() LCDDATA25bits.S19C6 = 1
#define    LCD1_Char3E_Off() LCDDATA25bits.S19C6 = 0
#define    LCD1_Char3E_AltSet(value) LCDSDATA25bits.S19C6 = value
#define    LCD1_Char3E_AltOn() LCDSDATA25bits.S19C6 = 1
#define    LCD1_Char3E_AltOff() LCDSDATA25bits.S19C6 = 0

#define    LCD1_Char3F_Set(value) LCDDATA21bits.S19C5 = value
#define    LCD1_Char3F_On() LCDDATA21bits.S19C5 = 1
#define    LCD1_Char3F_Off() LCDDATA21bits.S19C5 = 0
#define    LCD1_Char3F_AltSet(value) LCDSDATA21bits.S19C5 = value
#define    LCD1_Char3F_AltOn() LCDSDATA21bits.S19C5 = 1
#define    LCD1_Char3F_AltOff() LCDSDATA21bits.S19C5 = 0

#define    LCD1_Char3G_Set(value) LCDDATA21bits.S25C5 = value
#define    LCD1_Char3G_On() LCDDATA21bits.S25C5 = 1
#define    LCD1_Char3G_Off() LCDDATA21bits.S25C5 = 0
#define    LCD1_Char3G_AltSet(value) LCDSDATA21bits.S25C5 = value
#define    LCD1_Char3G_AltOn() LCDSDATA21bits.S25C5 = 1
#define    LCD1_Char3G_AltOff() LCDSDATA21bits.S25C5 = 0

#define    LCD1_Char4A_Set(value) LCDDATA1bits.S19C0 = value
#define    LCD1_Char4A_On() LCDDATA1bits.S19C0 = 1
#define    LCD1_Char4A_Off() LCDDATA1bits.S19C0 = 0
#define    LCD1_Char4A_AltSet(value) LCDSDATA1bits.S19C0 = value
#define    LCD1_Char4A_AltOn() LCDSDATA1bits.S19C0 = 1
#define    LCD1_Char4A_AltOff() LCDSDATA1bits.S19C0 = 0

#define    LCD1_Char4B_Set(value) LCDDATA1bits.S25C0 = value
#define    LCD1_Char4B_On() LCDDATA1bits.S25C0 = 1
#define    LCD1_Char4B_Off() LCDDATA1bits.S25C0 = 0
#define    LCD1_Char4B_AltSet(value) LCDSDATA1bits.S25C0 = value
#define    LCD1_Char4B_AltOn() LCDSDATA1bits.S25C0 = 1
#define    LCD1_Char4B_AltOff() LCDSDATA1bits.S25C0 = 0

#define    LCD1_Char4C_Set(value) LCDDATA9bits.S25C2 = value
#define    LCD1_Char4C_On() LCDDATA9bits.S25C2 = 1
#define    LCD1_Char4C_Off() LCDDATA9bits.S25C2 = 0
#define    LCD1_Char4C_AltSet(value) LCDSDATA9bits.S25C2 = value
#define    LCD1_Char4C_AltOn() LCDSDATA9bits.S25C2 = 1
#define    LCD1_Char4C_AltOff() LCDSDATA9bits.S25C2 = 0

#define    LCD1_Char4D_Set(value) LCDDATA13bits.S25C3 = value
#define    LCD1_Char4D_On() LCDDATA13bits.S25C3 = 1
#define    LCD1_Char4D_Off() LCDDATA13bits.S25C3 = 0
#define    LCD1_Char4D_AltSet(value) LCDSDATA13bits.S25C3 = value
#define    LCD1_Char4D_AltOn() LCDSDATA13bits.S25C3 = 1
#define    LCD1_Char4D_AltOff() LCDSDATA13bits.S25C3 = 0

#define    LCD1_Char4E_Set(value) LCDDATA9bits.S19C2 = value
#define    LCD1_Char4E_On() LCDDATA9bits.S19C2 = 1
#define    LCD1_Char4E_Off() LCDDATA9bits.S19C2 = 0
#define    LCD1_Char4E_AltSet(value) LCDSDATA9bits.S19C2 = value
#define    LCD1_Char4E_AltOn() LCDSDATA9bits.S19C2 = 1
#define    LCD1_Char4E_AltOff() LCDSDATA9bits.S19C2 = 0

#define    LCD1_Char4F_Set(value) LCDDATA5bits.S19C1 = value
#define    LCD1_Char4F_On() LCDDATA5bits.S19C1 = 1
#define    LCD1_Char4F_Off() LCDDATA5bits.S19C1 = 0
#define    LCD1_Char4F_AltSet(value) LCDSDATA5bits.S19C1 = value
#define    LCD1_Char4F_AltOn() LCDSDATA5bits.S19C1 = 1
#define    LCD1_Char4F_AltOff() LCDSDATA5bits.S19C1 = 0

#define    LCD1_Char4G_Set(value) LCDDATA5bits.S25C1 = value
#define    LCD1_Char4G_On() LCDDATA5bits.S25C1 = 1
#define    LCD1_Char4G_Off() LCDDATA5bits.S25C1 = 0
#define    LCD1_Char4G_AltSet(value) LCDSDATA5bits.S25C1 = value
#define    LCD1_Char4G_AltOn() LCDSDATA5bits.S25C1 = 1
#define    LCD1_Char4G_AltOff() LCDSDATA5bits.S25C1 = 0

#define    LCD1_Char5A_Set(value) LCDDATA5bits.S27C1 = value
#define    LCD1_Char5A_On() LCDDATA5bits.S27C1 = 1
#define    LCD1_Char5A_Off() LCDDATA5bits.S27C1 = 0
#define    LCD1_Char5A_AltSet(value) LCDSDATA5bits.S27C1 = value
#define    LCD1_Char5A_AltOn() LCDSDATA5bits.S27C1 = 1
#define    LCD1_Char5A_AltOff() LCDSDATA5bits.S27C1 = 0

#define    LCD1_Char5B_Set(value) LCDDATA9bits.S28C2 = value
#define    LCD1_Char5B_On() LCDDATA9bits.S28C2 = 1
#define    LCD1_Char5B_Off() LCDDATA9bits.S28C2 = 0
#define    LCD1_Char5B_AltSet(value) LCDSDATA9bits.S28C2 = value
#define    LCD1_Char5B_AltOn() LCDSDATA9bits.S28C2 = 1
#define    LCD1_Char5B_AltOff() LCDSDATA9bits.S28C2 = 0

#define    LCD1_Char5C_Set(value) LCDDATA17bits.S28C4 = value
#define    LCD1_Char5C_On() LCDDATA17bits.S28C4 = 1
#define    LCD1_Char5C_Off() LCDDATA17bits.S28C4 = 0
#define    LCD1_Char5C_AltSet(value) LCDSDATA17bits.S28C4 = value
#define    LCD1_Char5C_AltOn() LCDSDATA17bits.S28C4 = 1
#define    LCD1_Char5C_AltOff() LCDSDATA17bits.S28C4 = 0

#define    LCD1_Char5D_Set(value) LCDDATA25bits.S28C6 = value
#define    LCD1_Char5D_On() LCDDATA25bits.S28C6 = 1
#define    LCD1_Char5D_Off() LCDDATA25bits.S28C6 = 0
#define    LCD1_Char5D_AltSet(value) LCDSDATA25bits.S28C6 = value
#define    LCD1_Char5D_AltOn() LCDSDATA25bits.S28C6 = 1
#define    LCD1_Char5D_AltOff() LCDSDATA25bits.S28C6 = 0

#define    LCD1_Char5E_Set(value) LCDDATA29bits.S27C7 = value
#define    LCD1_Char5E_On() LCDDATA29bits.S27C7 = 1
#define    LCD1_Char5E_Off() LCDDATA29bits.S27C7 = 0
#define    LCD1_Char5E_AltSet(value) LCDSDATA29bits.S27C7 = value
#define    LCD1_Char5E_AltOn() LCDSDATA29bits.S27C7 = 1
#define    LCD1_Char5E_AltOff() LCDSDATA29bits.S27C7 = 0

#define    LCD1_Char5F_Set(value) LCDDATA25bits.S26C6 = value
#define    LCD1_Char5F_On() LCDDATA25bits.S26C6 = 1
#define    LCD1_Char5F_Off() LCDDATA25bits.S26C6 = 0
#define    LCD1_Char5F_AltSet(value) LCDSDATA25bits.S26C6 = value
#define    LCD1_Char5F_AltOn() LCDSDATA25bits.S26C6 = 1
#define    LCD1_Char5F_AltOff() LCDSDATA25bits.S26C6 = 0

#define    LCD1_Char5G_Set(value) LCDDATA17bits.S26C4 = value
#define    LCD1_Char5G_On() LCDDATA17bits.S26C4 = 1
#define    LCD1_Char5G_Off() LCDDATA17bits.S26C4 = 0
#define    LCD1_Char5G_AltSet(value) LCDSDATA17bits.S26C4 = value
#define    LCD1_Char5G_AltOn() LCDSDATA17bits.S26C4 = 1
#define    LCD1_Char5G_AltOff() LCDSDATA17bits.S26C4 = 0

#define    LCD1_Char5H_Set(value) LCDDATA13bits.S26C3 = value
#define    LCD1_Char5H_On() LCDDATA13bits.S26C3 = 1
#define    LCD1_Char5H_Off() LCDDATA13bits.S26C3 = 0
#define    LCD1_Char5H_AltSet(value) LCDSDATA13bits.S26C3 = value
#define    LCD1_Char5H_AltOn() LCDSDATA13bits.S26C3 = 1
#define    LCD1_Char5H_AltOff() LCDSDATA13bits.S26C3 = 0

#define    LCD1_Char5I_Set(value) LCDDATA17bits.S27C4 = value
#define    LCD1_Char5I_On() LCDDATA17bits.S27C4 = 1
#define    LCD1_Char5I_Off() LCDDATA17bits.S27C4 = 0
#define    LCD1_Char5I_AltSet(value) LCDSDATA17bits.S27C4 = value
#define    LCD1_Char5I_AltOn() LCDSDATA17bits.S27C4 = 1
#define    LCD1_Char5I_AltOff() LCDSDATA17bits.S27C4 = 0

#define    LCD1_Char5J_Set(value) LCDDATA21bits.S28C5 = value
#define    LCD1_Char5J_On() LCDDATA21bits.S28C5 = 1
#define    LCD1_Char5J_Off() LCDDATA21bits.S28C5 = 0
#define    LCD1_Char5J_AltSet(value) LCDSDATA21bits.S28C5 = value
#define    LCD1_Char5J_AltOn() LCDSDATA21bits.S28C5 = 1
#define    LCD1_Char5J_AltOff() LCDSDATA21bits.S28C5 = 0

#define    LCD1_Char5K_Set(value) LCDDATA9bits.S27C2 = value
#define    LCD1_Char5K_On() LCDDATA9bits.S27C2 = 1
#define    LCD1_Char5K_Off() LCDDATA9bits.S27C2 = 0
#define    LCD1_Char5K_AltSet(value) LCDSDATA9bits.S27C2 = value
#define    LCD1_Char5K_AltOn() LCDSDATA9bits.S27C2 = 1
#define    LCD1_Char5K_AltOff() LCDSDATA9bits.S27C2 = 0

#define    LCD1_Char5L_Set(value) LCDDATA13bits.S27C3 = value
#define    LCD1_Char5L_On() LCDDATA13bits.S27C3 = 1
#define    LCD1_Char5L_Off() LCDDATA13bits.S27C3 = 0
#define    LCD1_Char5L_AltSet(value) LCDSDATA13bits.S27C3 = value
#define    LCD1_Char5L_AltOn() LCDSDATA13bits.S27C3 = 1
#define    LCD1_Char5L_AltOff() LCDSDATA13bits.S27C3 = 0

#define    LCD1_Char5M_Set(value) LCDDATA13bits.S28C3 = value
#define    LCD1_Char5M_On() LCDDATA13bits.S28C3 = 1
#define    LCD1_Char5M_Off() LCDDATA13bits.S28C3 = 0
#define    LCD1_Char5M_AltSet(value) LCDSDATA13bits.S28C3 = value
#define    LCD1_Char5M_AltOn() LCDSDATA13bits.S28C3 = 1
#define    LCD1_Char5M_AltOff() LCDSDATA13bits.S28C3 = 0

#define    LCD1_Char5N_Set(value) LCDDATA25bits.S27C6 = value
#define    LCD1_Char5N_On() LCDDATA25bits.S27C6 = 1
#define    LCD1_Char5N_Off() LCDDATA25bits.S27C6 = 0
#define    LCD1_Char5N_AltSet(value) LCDSDATA25bits.S27C6 = value
#define    LCD1_Char5N_AltOn() LCDSDATA25bits.S27C6 = 1
#define    LCD1_Char5N_AltOff() LCDSDATA25bits.S27C6 = 0

#define    LCD1_Char5O_Set(value) LCDDATA21bits.S27C5 = value
#define    LCD1_Char5O_On() LCDDATA21bits.S27C5 = 1
#define    LCD1_Char5O_Off() LCDDATA21bits.S27C5 = 0
#define    LCD1_Char5O_AltSet(value) LCDSDATA21bits.S27C5 = value
#define    LCD1_Char5O_AltOn() LCDSDATA21bits.S27C5 = 1
#define    LCD1_Char5O_AltOff() LCDSDATA21bits.S27C5 = 0

#define    LCD1_Char5P_Set(value) LCDDATA21bits.S26C5 = value
#define    LCD1_Char5P_On() LCDDATA21bits.S26C5 = 1
#define    LCD1_Char5P_Off() LCDDATA21bits.S26C5 = 0
#define    LCD1_Char5P_AltSet(value) LCDSDATA21bits.S26C5 = value
#define    LCD1_Char5P_AltOn() LCDSDATA21bits.S26C5 = 1
#define    LCD1_Char5P_AltOff() LCDSDATA21bits.S26C5 = 0

#endif

