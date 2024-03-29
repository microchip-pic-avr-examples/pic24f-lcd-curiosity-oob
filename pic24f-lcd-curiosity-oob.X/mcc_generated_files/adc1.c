/**
  ADC1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adc1.c

  @Summary
    This is the generated driver implementation file for the ADC1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for ADC1.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  PIC24FJ128GL306      
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB 	          :  MPLAB X v5.50
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
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
#include "adc1.h"

/**
  Section: File Specific Functions
*/

// ADC1 Default Interrupt Handler
static void (*ADC1_DefaultInterruptHandler)(void) = NULL;

/**
  Section: Driver Interface
*/

void ADC1_Initialize (void)
{
    // ASAM disabled; DMABM disabled; ADSIDL disabled; DONE disabled; DMAEN disabled; FORM Absolute decimal result, unsigned, right-justified; SAMP disabled; SSRC Clearing sample bit ends sampling and starts conversion; MODE12 12-bit; ADON enabled; 
    AD1CON1 = 0x8400;
    // CSCNA disabled; NVCFG0 AVSS; PVCFG AVDD; ALTS disabled; BUFM disabled; SMPI Generates interrupt after completion of every sample/conversion operation; BUFREGEN disabled; 
    AD1CON2 = 0x00;
    // SAMC 16; EXTSAM disabled; PUMPEN disabled; ADRC FOSC/2; ADCS 255; 
    AD1CON3 = 0x10FF;
    // CH0SA AN0; CH0SB AN0; CH0NB AVSS; CH0NA AVSS; 
    AD1CHS = 0x00;
    // CSS30 disabled; CSS29 disabled; CSS28 disabled; CSS16 disabled; 
    AD1CSSH = 0x00;
    // CSS9 disabled; CSS8 disabled; CSS7 disabled; CSS6 disabled; CSS5 disabled; CSS4 disabled; CSS3 disabled; CSS2 disabled; CSS15 disabled; CSS1 disabled; CSS14 disabled; CSS0 disabled; CSS13 disabled; CSS12 disabled; CSS11 disabled; CSS10 disabled; 
    AD1CSSL = 0x00;
    // DMABL Allocates 1 word of buffer to each analog input; 
    AD1CON4 = 0x00;
    // ASEN disabled; WM Legacy operation; ASINT No interrupt; CM Less Than mode; BGREQ enabled; LPEN disabled; 
    AD1CON5 = 0x1000;
    // CHH16 disabled; 
    AD1CHITH = 0x00;
    // CHH9 disabled; CHH8 disabled; CHH7 disabled; CHH6 disabled; CHH5 disabled; CHH4 disabled; CHH3 disabled; CHH2 disabled; CHH1 disabled; CHH0 disabled; CHH11 disabled; CHH10 disabled; CHH13 disabled; CHH12 disabled; CHH15 disabled; CHH14 disabled; 
    AD1CHITL = 0x00;
    // AD1RESDMA 0; 
    AD1RESDMA = 0x00;
    // VBGEN3 disabled; VBGEN2 disabled; VBGEN1 disabled; 
    ANCFG = 0x00;
    
    //Assign Default Callbacks
    ADC1_SetInterruptHandler(&ADC1_CallBack);

}

void __attribute__ ((weak)) ADC1_CallBack(void)
{

}

void ADC1_SetInterruptHandler(void* handler)
{
    ADC1_DefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_Tasks ( void )
{
    if(IFS0bits.AD1IF)
    {
        if(ADC1_DefaultInterruptHandler) 
        { 
            ADC1_DefaultInterruptHandler(); 
        }

        // clear the ADC interrupt flag
        IFS0bits.AD1IF = false;
    }
}

/*******************************************************************************

  !!! Deprecated Definitions and APIs !!!
  !!! These functions will not be supported in future releases !!!

*******************************************************************************/
void ADC1_Start(void)
{
   AD1CON1bits.SAMP = 1;
}

void ADC1_Stop(void)
{
   AD1CON1bits.SAMP = 0;
}

uint16_t ADC1_ConversionResultBufferGet(uint16_t *buffer)
{
    int count;
    uint16_t *ADC16Ptr;
    uint16_t sampleCount = AD1CON2bits.SMPI;

    ADC16Ptr = (uint16_t *)&(ADC1BUF0);

    for(count=0;count<=sampleCount;count++)
    {
        buffer[count] = (uint16_t)*ADC16Ptr;
        ADC16Ptr++;
    }
    return count;
}

/**
  End of File
*/
