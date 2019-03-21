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

#define LED_LED3_GREEN_LAT     LATBbits.LATB4
#define LED_LED3_GREEN_TRIS    TRISBbits.TRISB4

#define LED_ON  1
#define LED_OFF 0

#define INPUT  1
#define OUTPUT 0

inline static void LED3_GREEN_On(void)
{
	LED_LED3_GREEN_TRIS = OUTPUT;
	LED_LED3_GREEN_LAT = LED_ON;
}

inline static void LED3_GREEN_Off(void)
{
	LED_LED3_GREEN_TRIS = OUTPUT;
	LED_LED3_GREEN_LAT = LED_OFF;
}

inline static void LED3_GREEN_Toggle(void)
{
	LED_LED3_GREEN_TRIS = OUTPUT;
	LED_LED3_GREEN_LAT ^= 1;
}

#endif
