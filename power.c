#include <xc.h>
#include "adc.h"
#include "power.h"

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
    
    /* 1.2v typical band gap reference voltage. */
    return ( ( (1.2 * vdd) / band_gap ) );
}
