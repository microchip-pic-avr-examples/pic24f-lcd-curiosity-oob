#include <xc.h>
#include "adc.h"
#include "power.h"

#define BANDGAP_TYPICAL_VOLTAGE     1.2

/* Datasheet of D1 claims 0.240v max. But doesn't specify a typical value.
 * Using typical value measure on a few development boards during development */
#define DIODE_D1_DROP               0.12

enum POWER_SOURCE POWER_GetSource(void){
    ANSELBbits.ANSB2 = 0;   //Digital
    TRISBbits.TRISB2 = 1;   //Input

    if(PORTBbits.RB2 == 1)
    {
        return POWER_SOURCE_USB;
    }
    
    return POWER_SOURCE_BATTERY;
}

double POWER_GetVddVoltage(void)
{
    uint16_t vdd;
    uint16_t band_gap;
    
    while(HLVDCONbits.BGVST == 0)
    {
    }
    
    vdd = ADC_Read12bit(ADC_CHANNEL_VDD);
    band_gap = ADC_Read12bit(ADC_CHANNEL_BAND_GAP); 
    
    return ( (BANDGAP_TYPICAL_VOLTAGE * vdd) / band_gap );
}

double POWER_GetBatteryVoltage(void)
{
    return (POWER_GetVddVoltage() + DIODE_D1_DROP);
}
