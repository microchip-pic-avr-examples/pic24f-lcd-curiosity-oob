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
    
    //Power monitor pin
    ANSELBbits.ANSB2 = 0;   //Digital
    TRISBbits.TRISB2 = 1;   //Input
    IOCPBbits.IOCPB2 = 1;   //Interrupt on change
    _IOCON = 1;
    _IOCIF = 0;
    _IOCIE = 1;
    
    IO_PINS_HandleUnusedPins();
}

bool IO_PINS_USBPowerSense(void)
{
    return PORTBbits.RB2;
}

void __attribute__ ( ( weak, __interrupt__ , auto_psv ) ) _IOCInterrupt ( void )
{
    _IOCIF = 0;
}
