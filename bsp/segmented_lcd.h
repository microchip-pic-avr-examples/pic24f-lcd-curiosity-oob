#ifndef SEGMENTED_LCD_H
#define SEGMENTED_LCD_H

#include <stdbool.h>
#include <stdint.h>

enum BATTERY_STATUS
{
    BATTERY_STATUS_FULL,
    BATTERY_STATUS_MEDIUM,
    BATTERY_STATUS_LOW,
    BATTERY_STATUS_CRITICAL,
    BATTERY_STATUS_UNKNOWN
};

void SEG_LCD_Initialize(void);
void SEG_LCD_PrintPot(uint16_t value);
void SEG_LCD_PrintTime(uint8_t hour, uint8_t min);
void SEG_LCD_PrintTemperature(double temp);
void SEG_LCD_SetBatteryStatus(enum BATTERY_STATUS status);
void SEG_LCD_LowPowerModeEnable(bool enabled);
void SEG_LCD_PrintPIC24(void);
void SEG_LCD_PrintVoltage(double voltage);

#endif
