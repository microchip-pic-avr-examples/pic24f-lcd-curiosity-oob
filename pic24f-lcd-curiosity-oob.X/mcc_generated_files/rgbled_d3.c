/**
  RGBLED_D3 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    rgbled_d3.h

  @Summary
    This is the generated header file for the RGBLED_D3 driver using Board Support Library

  @Description
    This header file provides APIs for driver for RGBLED_D3.
    Generation Information :
        Product Revision  :  Board Support Library - CQ1-2020
        Device            :  PIC24FJ128GL306
        Driver Version    :  0.95
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

#include "rgbled_d3.h"
#include "red_led.h"
#include "green_led.h"
#include "blue_led.h"

void RGBLED_D3_On(void)
{
    RED_LED_On();
    GREEN_LED_On();
    BLUE_LED_On();
}

void RGBLED_D3_Off(void)
{
    RED_LED_Off();
    GREEN_LED_Off();
    BLUE_LED_Off();
}

void RGBLED_D3_Toggle(void)
{
    RED_LED_Toggle();
    GREEN_LED_Toggle();
    BLUE_LED_Toggle();
}

void RGBLED_D3_ColorSet(uint16_t red, uint16_t green, uint16_t blue)
{
    RED_LED_IntensitySet(red);
    GREEN_LED_IntensitySet(green);
    BLUE_LED_IntensitySet(blue);
}

/**
 End of File
 */