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

#ifndef LED3_BLUE_H
#define LED3_BLUE_H

#include <xc.h>

#define LED3_BLUE_LAT     LATBbits.LATB7
#define LED3_BLUE_TRIS    TRISBbits.TRISB7

inline static void LED3_BLUE_On(void)
{
	LED3_BLUE_TRIS = 0;
	LED3_BLUE_LAT = 1;
}

inline static void LED3_BLUE_Off(void)
{
	LED3_BLUE_TRIS = 0;
	LED3_BLUE_LAT = 0;
}

inline static void LED3_BLUE_Toggle(void)
{
	LED3_BLUE_TRIS = 0;
	LED3_BLUE_LAT ^= 1;
}

#endif
