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

#ifndef LED3_GREEN_H
#define LED3_GREEN_H

#include <xc.h>

#define LED3_GREEN_LAT     LATBbits.LATB4
#define LED3_GREEN_TRIS    TRISBbits.TRISB4

#define LED_ON  1
#define LED_OFF 0

#define INPUT  1
#define OUTPUT 0

#define MAXIMUM_INTENSITY 0x03FF
#define DEFAULT_INTENSITY (MAXIMUM_INTENSITY/2)

static uint16_t current_intensity = DEFAULT_INTENSITY;

void LED3_GREEN_On(void)
{
	LED3_GREEN_TRIS = OUTPUT;

    _RP28R = 18; //18 = OCM3A -> RB4[RP28] (green)
    
    //Green - uses CCP3-PWM
    CCP3RAL = 0;
    CCP3RBL = current_intensity;
    CCP3PRL = MAXIMUM_INTENSITY;
    CCP3PRH = 0;
    CCP3TMRL = 0;
    CCP3CON1Lbits.MOD = 0b0100;     //dual-compare
    CCP3CON1Lbits.T32 = 0;          //16-bit mode
    CCP3CON1Lbits.CLKSEL = 0b000;   //System clock
    CCP3CON1Lbits.TMRPS = 0b00;     //1:1 Pre-scaler 
    CCP3CON1Lbits.CCSEL = 0;        //Output compare
    CCP3CON1Lbits.CCPON = 1;        //Enable  
}

void LED3_GREEN_Off(void)
{
	LED3_GREEN_TRIS = OUTPUT;
	LED3_GREEN_LAT = LED_OFF;
    
    CCP3CON1Lbits.CCPON = 0;        //Disable 
}

void LED3_GREEN_Toggle(void)
{
	if(CCP3CON1Lbits.CCPON)
    {
        LED3_GREEN_Off();
    }
    else
    {
        LED3_GREEN_On();
    }
}

void LED3_GREEN_SetIntensity(uint16_t new_intensity)
{    
    //Convert 16-bit to 10-bit to reduce flicker/jitter
    new_intensity >>= 6;
    
    CCP3RBL = new_intensity;
    
    current_intensity = new_intensity;
    
    if(CCP3TMRL > new_intensity)
    {
        CCP3TMRL = 0;
    }
}

#endif
