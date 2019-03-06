#include "operational_mode.h"
#include "power.h"
#include "segmented_lcd.h"
#include "adc.h"

static void Initialize(void);
static void Deinitialize(void);
static void Tasks(void);

const struct OPERATIONAL_MODE battery_operational_mode = {
    &Initialize,
    &Deinitialize,
    &Tasks
};

static void Initialize(void)
{
    //Enable and configure the ADC so it can sample the potentiometer.
    ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT);
    ADC_ChannelEnable(ADC_CHANNEL_POTENTIOMETER);
    
    SEG_LCD_Initialize();
    
    SEG_LCD_LowPowerModeEnable(true);
    SEG_LCD_SetBatteryStatus(BATTERY_STATUS_UNKNOWN);
}

static void Deinitialize(void)
{
    
}

static void Tasks(void)
{
    double vdd = POWER_GetVddVoltage();
    enum BATTERY_STATUS battery_status = BATTERY_STATUS_UNKNOWN;
    
    if(vdd < 2.5)
    {
        battery_status = BATTERY_STATUS_CRITICAL;
    }
    else if(vdd < 2.7)
    {
        battery_status = BATTERY_STATUS_LOW;
    }
    else if(vdd < 2.9)
    {
        battery_status = BATTERY_STATUS_MEDIUM;
    }
    else
    {
        battery_status = BATTERY_STATUS_FULL;
    }
    
    SEG_LCD_SetBatteryStatus(battery_status);
}