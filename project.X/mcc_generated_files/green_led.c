/**
  GREEN_LED Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    green_led.h

  @Summary
    This is the generated header file for the GREEN_LED driver using Board Support Library

  @Description
    This header file provides APIs for driver for GREEN_LED.
    Generation Information :
        Product Revision  :  Board Support Library - CQ1-2020
        Device            :  PIC24FJ128GL306
        Driver Version    :  0.97-b
    The generated drivers are tested against the following:
        Compiler          :  1.41
        MPLAB 	          :  MPLAB X v5.25
*/


/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
/**
  Section: Included Files
*/

#ifndef GREEN_LED_H
#define GREEN_LED_H

#include <xc.h>
#include <stdbool.h>
#include "mccp3_compare.h"
#include "green_led.h"

static bool ismccp3Enabled = false;

void GREEN_LED_Initialize()
{
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS
    RPOR14bits.RP28R = 0x0012;    //RP28->OCM3A;
    __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS
}

void GREEN_LED_On(void)
{
    MCCP3_COMPARE_Start();
    ismccp3Enabled = true;
}

void GREEN_LED_Off(void)
{
    MCCP3_COMPARE_Stop();
    ismccp3Enabled = false;
}

void GREEN_LED_Toggle(void)
{
    if(ismccp3Enabled == true)
    {
        GREEN_LED_Off();
    }
    else 
    {
        GREEN_LED_On();
    }
}

void GREEN_LED_IntensitySet(uint16_t new_intensity)
{  
   //Convert 16-bit to 10-bit to reduce flicker/jitter
    new_intensity >>= 6;
    MCCP3_COMPARE_DualCompareValueSet(0x0,new_intensity);
}
#endif /* GREEN_LED_H */
