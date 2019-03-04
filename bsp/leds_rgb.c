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
#include <xc.h>
#include <stdint.h>

#include "leds_rgb.h"

#define LED_RGB_LED3_RED_LAT     LATGbits.LATG9
#define LED_RGB_LED3_GREEN_LAT   LATBbits.LATB4
#define LED_RGB_LED3_BLUE_LAT    LATBbits.LATB7

#define LED_RGB_LED3_RED_TRIS    TRISGbits.TRISG9
#define LED_RGB_LED3_GREEN_TRIS  TRISBbits.TRISB4
#define LED_RGB_LED3_BLUE_TRIS   TRISBbits.TRISB7

#define INPUT  1
#define OUTPUT 0

void LED_RGB_Enable(LED_RGB led)
{
    switch(led)
    {
        case LED_RGB_LED3:
            LED_RGB_LED3_RED_TRIS = OUTPUT ;
            LED_RGB_LED3_GREEN_TRIS = OUTPUT ;
            LED_RGB_LED3_BLUE_TRIS = OUTPUT ;
                   
            _RP27R = 16; //16 = OCM2A -> RG9[RP27] (red)
            _RP28R = 18; //18 = OCM3A -> RB4[RP28] (green)
            _RP7R  = 20; //20 = OCM4A -> RB7[RP7]  (blue)
            
            //Red
            CCP2RAL = 0;
            CCP2RBL = 0;
            CCP2PRL = 0x3FF;
            CCP2PRH = 0;
            CCP2TMRL = 0;
            CCP2CON1Lbits.MOD = 0b0100;     //dual-compare
            CCP2CON1Lbits.T32 = 0;          //16-bit mode
            CCP2CON1Lbits.CLKSEL = 0b000;   //System clock
            CCP2CON1Lbits.TMRPS = 0b00;     //1:1 Pre-scaler 
            CCP2CON1Lbits.CCSEL = 0;        //Output compare
            CCP2CON1Lbits.CCPON = 1;        //Enable      
            
            //Green
            CCP3RAL = 0;
            CCP3RBL = 0;
            CCP3PRL = 0x3FF;
            CCP3PRH = 0;
            CCP3TMRL = 0;
            CCP3CON1Lbits.MOD = 0b0100;     //dual-compare
            CCP3CON1Lbits.T32 = 0;          //16-bit mode
            CCP3CON1Lbits.CLKSEL = 0b000;   //System clock
            CCP3CON1Lbits.TMRPS = 0b00;     //1:1 Pre-scaler 
            CCP3CON1Lbits.CCSEL = 0;        //Output compare
            CCP3CON1Lbits.CCPON = 1;        //Enable   
            
            //Blue
            CCP4RAL = 0;
            CCP4RBL = 0;
            CCP4PRL = 0x3FF;
            CCP4PRH = 0;
            CCP4TMRL = 0;
            CCP4CON1Lbits.MOD = 0b0100;     //dual-compare
            CCP4CON1Lbits.T32 = 0;          //16-bit mode
            CCP4CON1Lbits.CLKSEL = 0b000;   //System clock
            CCP4CON1Lbits.TMRPS = 0b00;     //1:1 Pre-scaler 
            CCP4CON1Lbits.CCSEL = 0;        //Output compare
            CCP4CON1Lbits.CCPON = 1;        //Enable   
            break;
        
        default:
            break;
    }
}

void LED_RGB_SetRed(LED_RGB led, uint16_t red)
{
    CCP2RBL = ((uint16_t)red);
}
    
void LED_RGB_SetGreen(LED_RGB led, uint16_t green)
{
    CCP3RBL = ((uint16_t)green);
}

void LED_RGB_SetBlue(LED_RGB led, uint16_t blue)
{
    CCP4RBL = ((uint16_t)blue);
}

void LED_RGB_Set(LED_RGB led, uint16_t red, uint16_t green, uint16_t blue)
{
    LED_RGB_SetRed(led, red);
    LED_RGB_SetGreen(led, green);
    LED_RGB_SetBlue(led, blue);
}
