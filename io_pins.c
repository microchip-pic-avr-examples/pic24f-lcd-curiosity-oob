
#include <stdbool.h>
#include <stdint.h>
#include <xc.h>

#include "io_pins.h"

void IO_PINS_HandleUnusedPins()
{
    /* mikroBus(tm) slot A */
    _TRISB14 = 0;
    _LATB14 = 0;
    
    _TRISD5 = 0;
    _LATD5 = 0;
    
    _TRISE4 = 0;
    _LATE4 = 0;
    
    _TRISG3 = 0;
    _LATG3 = 0;
    
    _TRISF6 = 0;
    _LATF6 = 0;
    
    _TRISD9 = 0;
    _LATD9 = 0;
    
    _TRISD10 = 0;
    _LATD10 = 0;
    
    /* mikroBus(tm) slot B */
    _TRISB15 = 0;
    _LATB15 = 0;
    
    _TRISG6 = 0;
    _LATG6 = 0;
    
    _TRISD11 = 0;
    _LATD11 = 0;
    
    _TRISB5 = 0;
    _LATB5 = 0;
    
    _TRISD8 = 0;
    _LATD8 = 0;
    
    _TRISF2 = 0;
    _LATF2 = 0;
    
    _TRISF3 = 0;
    _LATF3 = 0;
    
    _TRISF4 = 0;
    _LATF4 = 1;
    
    _TRISF5 = 0;
    _LATF5 = 1;
    
}

void IO_PINS_Initialize()
{
    //UART PPS
    _RP16R = 3;     //RF3[RP16] = U1TX
    
    // TC77 chip select
    _TRISB11 = 0;
    _LATB11 = 0;
    
    //SPI PPS
    _RP22R = 7;     //MOSI
    _RP25R = 8;     //SCK
    _SDI1R = 23;    //MISO
    
    ANSELD &= 0b1111111111101111;
    
    IO_PINS_HandleUnusedPins();
}
