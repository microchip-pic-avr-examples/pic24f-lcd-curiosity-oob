/**
  MCCP2 Generated Driver File 

  @Company
    Microchip Technology Inc.

  @File Name
    mccp2.c

  @Summary
    This is the generated driver implementation file for the MCCP2 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides implementations for driver APIs for MCCP2. 
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

#include "mccp2_compare.h"

/** OC Mode.

  @Summary
    Defines the OC Mode.

  @Description
    This data type defines the OC Mode of operation.

*/

static uint16_t         gMCCP2Mode;

/**
  Section: Driver Interface
*/


void MCCP2_COMPARE_Initialize (void)
{
    // CCPON enabled; MOD Dual Edge Compare; CCSEL disabled; CCPSIDL disabled; TMR32 16 Bit; CCPSLP disabled; TMRPS 1:1; CLKSEL FOSC/2; TMRSYNC disabled; 
    CCP2CON1L = (0x8004 & 0x7FFF); //Disabling CCPON bit
    //RTRGEN disabled; ALTSYNC disabled; ONESHOT disabled; TRIGEN disabled; IOPS Each Time Base Period Match; SYNC MCCP2 Timer; OPSRC Timer Interrupt Event; 
    CCP2CON1H = 0x00;
    //ASDGM disabled; SSDG disabled; ASDG 0; PWMRSEN disabled; 
    CCP2CON2L = 0x00;
    //ICGSM Level-Sensitive mode; ICSEL ICM2; AUXOUT Disabled; OCAEN enabled; OCBEN disabled; OENSYNC disabled; 
    CCP2CON2H = 0x100;
    //DT 0; 
    CCP2CON3L = 0x00;
    //OETRIG disabled; OSCNT None; POLACE disabled; POLBDF disabled; PSSBDF Tri-state; OUTM Steerable single output; PSSACE Tri-state; 
    CCP2CON3H = 0x00;
    //ICDIS disabled; SCEVT disabled; TRSET disabled; ICOV disabled; ASEVT disabled; TRIG disabled; ICGARM disabled; TRCLR disabled; 
    CCP2STATL = 0x00;
    //TMR 0; 
    CCP2TMRL = 0x00;
    //TMR 0; 
    CCP2TMRH = 0x00;
    //PR 16383; 
    CCP2PRL = 0x3FFF;
    //PR 0; 
    CCP2PRH = 0x00;
    //CMP 0; 
    CCP2RAL = 0x00;
    //CMP 8191; 
    CCP2RBL = 0x1FFF;
    //BUF 0; 
    CCP2BUFL = 0x00;
    //BUF 0; 
    CCP2BUFH = 0x00;

    CCP2CON1Lbits.CCPON = 0x1; //Enabling CCP

    gMCCP2Mode = CCP2CON1Lbits.MOD;

}

void __attribute__ ((weak)) MCCP2_COMPARE_CallBack(void)
{
    // Add your custom callback code here
}

void MCCP2_COMPARE_Tasks( void )
{
    if(IFS4bits.CCP2IF)
    {
		// MCCP2 COMPARE callback function 
		MCCP2_COMPARE_CallBack();
		
        IFS4bits.CCP2IF = 0;
    }
}

void __attribute__ ((weak)) MCCP2_COMPARE_TimerCallBack(void)
{
    // Add your custom callback code here
}


void MCCP2_COMPARE_TimerTasks( void )
{
    if(IFS0bits.CCT2IF)
    {
		// MCCP2 COMPARE Timer callback function 
		MCCP2_COMPARE_TimerCallBack();
	
        IFS0bits.CCT2IF = 0;
    }
}

void MCCP2_COMPARE_Start( void )
{
    /* Start the Timer */
    CCP2CON1Lbits.CCPON = true;
}

void MCCP2_COMPARE_Stop( void )
{
    /* Start the Timer */
    CCP2CON1Lbits.CCPON = false;
}

void MCCP2_COMPARE_SingleCompare16ValueSet( uint16_t value )
{   
    CCP2RAL = value;
}


void MCCP2_COMPARE_DualCompareValueSet( uint16_t priVal, uint16_t secVal )
{

    CCP2RAL = priVal;

    CCP2RBL = secVal;
}

void MCCP2_COMPARE_DualEdgeBufferedConfig( uint16_t priVal, uint16_t secVal )
{

    CCP2RAL = priVal;

    CCP2RBL = secVal;
}

void MCCP2_COMPARE_CenterAlignedPWMConfig( uint16_t priVal, uint16_t secVal )
{

    CCP2RAL = priVal;

    CCP2RBL = secVal;
}

void MCCP2_COMPARE_EdgeAlignedPWMConfig( uint16_t priVal, uint16_t secVal )
{

    CCP2RAL = priVal;

    CCP2RBL = secVal;
}

void MCCP2_COMPARE_VariableFrequencyPulseConfig( uint16_t priVal )
{
    CCP2RAL = priVal;
}

bool MCCP2_COMPARE_IsCompareCycleComplete( void )
{
    return(IFS4bits.CCP2IF);
}

bool MCCP2_COMPARE_TriggerStatusGet( void )
{
    return( CCP2STATLbits.TRIG );
    
}

void MCCP2_COMPARE_TriggerStatusSet( void )
{
    CCP2STATLbits.TRSET = 1;
}

void MCCP2_COMPARE_TriggerStatusClear( void )
{
    /* Clears the trigger status */
    CCP2STATLbits.TRCLR = 0;
}

bool MCCP2_COMPARE_SingleCompareStatusGet( void )
{
    return( CCP2STATLbits.SCEVT );
}

void MCCP2_COMPARE_SingleCompareStatusClear( void )
{
    /* Clears the trigger status */
    CCP2STATLbits.SCEVT = 0;
    
}
/**
 End of File
*/
