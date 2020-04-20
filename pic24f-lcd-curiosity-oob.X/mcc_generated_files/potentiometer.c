/**
  POTENTIOMETER Generated Driver API Source File

  @Company
    Microchip Technology Inc.

  @File Name
    potentiometer.c

  @Summary
    This is the generated source file for the POTENTIOMETER driver using Board Support Library

  @Description
    This source file provides APIs for driver for POTENTIOMETER.
    Generation Information :
        Product Revision  :  Board Support Library - CQ1-2020
        Device            :  PIC24FJ128GL306
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

#include <xc.h>
#include "potentiometer.h"
#include "adc1.h"

#define POT_ADC_REF_VOLTAGE          (double)3.3     
#define POT_VIN        3.3
#define POT_ADC_RESOLUTION           (double)1024
#define POTENTIOMETER_ADC_CHANNEL   16
uint16_t POTENTIOMETER_Get(void){
    
    volatile uint16_t i=0;
    uint16_t value = 0;
    //Enable the ADC Conversion 
    ADC1_Enable();
    //Select the ADC channel connected to Potentiometer 
    ADC1_ChannelSelect(channel_AN16);
    //Enable Software Trigger
    ADC1_SoftwareTriggerEnable();
    //ADC sampling delay
    for(i=0;i<65535;i++)
    {
        //Do Nothing
    }
    //Disable software trigger
    ADC1_SoftwareTriggerDisable();
    while(!ADC1_IsConversionComplete(channel_AN16))
    {
        //Do Nothing
    }
    value = ADC1_ConversionResultGet(channel_AN16);
    ADC1_Disable();
    return value;
}


double POTENTIOMETER_VoltageGet(void)
{
    double voltage=0;
    uint16_t adcValue = 0;
    // Get the ADC value
    adcValue = POTENTIOMETER_Get();
    /*
    voltage Value = (Actual ADC Value / ADC Resolution) * ADC Ref Voltage  
    */
    voltage = ((adcValue /POT_ADC_RESOLUTION)* POT_ADC_REF_VOLTAGE);
    return voltage;
}

/**
 End of File
 */