/**
  MCCP3 Generated Driver File 

  @Company
    Microchip Technology Inc.

  @File Name
    mccp3.c

  @Summary
    This is the generated driver implementation file for the MCCP3 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides implementations for driver APIs for MCCP3. 
    Generation Information : 
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.169.0
        Device            :  PIC24FJ128GL306
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB             :  MPLAB X v5.40
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

#include "mccp3_compare.h"

/** OC Mode.

  @Summary
    Defines the OC Mode.

  @Description
    This data type defines the OC Mode of operation.

*/

static uint16_t         gMCCP3Mode;

/**
  Section: Driver Interface
*/


void MCCP3_COMPARE_Initialize (void)
{
    // CCPON enabled; MOD Dual Edge Compare; CCSEL disabled; CCPSIDL disabled; TMR32 16 Bit; CCPSLP disabled; TMRPS 1:1; CLKSEL FOSC/2; TMRSYNC disabled; 
    CCP3CON1L = (0x8004 & 0x7FFF); //Disabling CCPON bit
    //RTRGEN disabled; ALTSYNC disabled; ONESHOT disabled; TRIGEN disabled; IOPS Each Time Base Period Match; SYNC MCCP3 Timer; OPSRC Timer Interrupt Event; 
    CCP3CON1H = 0x00;
    //ASDGM disabled; SSDG disabled; ASDG 0; PWMRSEN disabled; 
    CCP3CON2L = 0x00;
    //ICGSM Level-Sensitive mode; ICSEL ICM3; AUXOUT Disabled; OCAEN enabled; OCBEN disabled; OENSYNC disabled; 
    CCP3CON2H = 0x100;
    //DT 0; 
    CCP3CON3L = 0x00;
    //OETRIG disabled; OSCNT None; POLACE disabled; POLBDF disabled; PSSBDF Tri-state; OUTM Steerable single output; PSSACE Tri-state; 
    CCP3CON3H = 0x00;
    //ICDIS disabled; SCEVT disabled; TRSET disabled; ICOV disabled; ASEVT disabled; TRIG disabled; ICGARM disabled; TRCLR disabled; 
    CCP3STATL = 0x00;
    //TMR 0; 
    CCP3TMRL = 0x00;
    //TMR 0; 
    CCP3TMRH = 0x00;
    //PR 16383; 
    CCP3PRL = 0x3FFF;
    //PR 0; 
    CCP3PRH = 0x00;
    //CMP 0; 
    CCP3RAL = 0x00;
    //CMP 8191; 
    CCP3RBL = 0x1FFF;
    //BUF 0; 
    CCP3BUFL = 0x00;
    //BUF 0; 
    CCP3BUFH = 0x00;

    CCP3CON1Lbits.CCPON = 0x1; //Enabling CCP

    gMCCP3Mode = CCP3CON1Lbits.MOD;

}

void __attribute__ ((weak)) MCCP3_COMPARE_CallBack(void)
{
    // Add your custom callback code here
}

void MCCP3_COMPARE_Tasks( void )
{
    if(IFS5bits.CCP3IF)
    {
		// MCCP3 COMPARE callback function 
		MCCP3_COMPARE_CallBack();
		
        IFS5bits.CCP3IF = 0;
    }
}

void __attribute__ ((weak)) MCCP3_COMPARE_TimerCallBack(void)
{
    // Add your custom callback code here
}


void MCCP3_COMPARE_TimerTasks( void )
{
    if(IFS2bits.CCT3IF)
    {
		// MCCP3 COMPARE Timer callback function 
		MCCP3_COMPARE_TimerCallBack();
	
        IFS2bits.CCT3IF = 0;
    }
}

void MCCP3_COMPARE_Start( void )
{
    /* Start the Timer */
    CCP3CON1Lbits.CCPON = true;
}

void MCCP3_COMPARE_Stop( void )
{
    /* Start the Timer */
    CCP3CON1Lbits.CCPON = false;
}

void MCCP3_COMPARE_SingleCompare16ValueSet( uint16_t value )
{   
    CCP3RAL = value;
}


void MCCP3_COMPARE_DualCompareValueSet( uint16_t priVal, uint16_t secVal )
{

    CCP3RAL = priVal;

    CCP3RBL = secVal;
}

void MCCP3_COMPARE_DualEdgeBufferedConfig( uint16_t priVal, uint16_t secVal )
{

    CCP3RAL = priVal;

    CCP3RBL = secVal;
}

void MCCP3_COMPARE_CenterAlignedPWMConfig( uint16_t priVal, uint16_t secVal )
{

    CCP3RAL = priVal;

    CCP3RBL = secVal;
}

void MCCP3_COMPARE_EdgeAlignedPWMConfig( uint16_t priVal, uint16_t secVal )
{

    CCP3RAL = priVal;

    CCP3RBL = secVal;
}

void MCCP3_COMPARE_VariableFrequencyPulseConfig( uint16_t priVal )
{
    CCP3RAL = priVal;
}

bool MCCP3_COMPARE_IsCompareCycleComplete( void )
{
    return(IFS5bits.CCP3IF);
}

bool MCCP3_COMPARE_TriggerStatusGet( void )
{
    return( CCP3STATLbits.TRIG );
    
}

void MCCP3_COMPARE_TriggerStatusSet( void )
{
    CCP3STATLbits.TRSET = 1;
}

void MCCP3_COMPARE_TriggerStatusClear( void )
{
    /* Clears the trigger status */
    CCP3STATLbits.TRCLR = 0;
}

bool MCCP3_COMPARE_SingleCompareStatusGet( void )
{
    return( CCP3STATLbits.SCEVT );
}

void MCCP3_COMPARE_SingleCompareStatusClear( void )
{
    /* Clears the trigger status */
    CCP3STATLbits.SCEVT = 0;
    
}
/**
 End of File
*/
