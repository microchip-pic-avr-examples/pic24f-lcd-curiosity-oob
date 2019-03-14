#include "operational_mode.h"
#include "power.h"
#include "segmented_lcd.h"
#include "adc.h"
#include "rtcc.h"
#include "timer_1ms.h"
#include "tc77.h"
#include "leds.h"
#include "io_pins.h"

#include <xc.h>

static void Initialize(void);
static void Deinitialize(void);
static void Tasks(void);

static RTCC_DATETIME date_time;

const struct OPERATIONAL_MODE battery_operational_mode = {
    &Initialize,
    &Deinitialize,
    &Tasks
};

static void Initialize(void)
{
    RTCC_DATETIME alarm_time;
    
    SEG_LCD_Initialize();
    SEG_LCD_LowPowerModeEnable(true);
    
    SEG_LCD_SetBatteryStatus(BATTERY_STATUS_UNKNOWN);
    
    /* Enter low powered mode */
    TIMER_SetConfiguration(TIMER_CONFIGURATION_OFF);
    
    TC77_Shutdown();

    LED_Enable(LED_LED1);
    LED_On(LED_LED1);
    
    RTCC_ChimeEnable(true);
    
    RTCC_AlarmFrequency(RTCC_ALARM_FREQUENCY_MINUTE);
    
    alarm_time.bcdFormat = true;
    
    RTCC_TimeGet(&alarm_time);
    RTCC_AlarmSet(&alarm_time, 1);
    
    RTCC_AlarmEnable(true);
    
    LED_Enable(LED_LED1);
    
    date_time.bcdFormat = false;
    
    _VREGS = 0; //fast wakeup disabled (low power)
    _RETEN = 1; //retention mode enabled
    
    PMD1 = 0xFFFF;
    PMD2 = 0xFFFF;
    PMD3 = (0xFFFF & (~_PMD3_RTCCMD_MASK));
    PMD4 = (0xFFFF & (~_PMD4_LVDMD_MASK));
    PMD5 = 0xFFFF;
    PMD6 = (0xFFFF & (~_PMD6_LCDMD_MASK));
    PMD7 = 0xFFFF;
    PMD8 = 0xFFFF;  
    
    IO_PINS_HandleUnusedPins();
}

static void Deinitialize(void)
{
    RTCC_AlarmEnable(false);
    
    /* Re-enable all other modules so they are available for application use. */
    PMD1 = 0x0000;
    PMD2 = 0x0000;
    PMD3 = 0x0000;
    PMD4 = 0x0000;
    PMD5 = 0x0000;
    PMD6 = 0x0000;
    PMD7 = 0x0000;
    PMD8 = 0x0000;
}

static void UpdateBatteryStatusIcon(void)
{
    double battery_voltage = POWER_GetBatteryVoltage();
    enum BATTERY_STATUS battery_status = BATTERY_STATUS_UNKNOWN;
    
    if(battery_voltage < 2.6)
    {
        battery_status = BATTERY_STATUS_CRITICAL;
    }
    else if(battery_voltage < 2.7)
    {
        battery_status = BATTERY_STATUS_LOW;
    }
    else if(battery_voltage < 2.8)
    {
        battery_status = BATTERY_STATUS_MEDIUM;
    }
    else
    {
        battery_status = BATTERY_STATUS_FULL;
    }
    
    SEG_LCD_SetBatteryStatus(battery_status);
}

static void Tasks(void)
{
    LED_On(LED_LED1);
    
    PMD1bits.AD1MD = 0; //Enable ADC peripheral
    PMD4bits.LVDMD = 0; //Enable LVD module
    
    RTCC_TimeGet(&date_time);
    SEG_LCD_PrintTime(date_time.hour, date_time.minute);

    //Enable and configure the ADC so it can sample the battery voltage.
    ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT);
    ADC_ChannelEnable(ADC_CHANNEL_BAND_GAP);
    
    UpdateBatteryStatusIcon();
    
    PMD1bits.AD1MD = 1; //Disable ADC while in sleep
    PMD4bits.LVDMD = 1; //Disable LVD module
    
    LED_Off(LED_LED1);
    
    Sleep();   
}