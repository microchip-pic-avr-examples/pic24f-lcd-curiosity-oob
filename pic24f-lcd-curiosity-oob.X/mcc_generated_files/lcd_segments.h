/**
  LCD Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    lcd_segments.h

  @Summary
    This is the generated header file for the LCD driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides APIs for driver for LCD.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.169.0
        Device            :  PIC24FJ128GL306
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB 	          :  MPLAB X v5.40
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

#ifndef LCD_SEGMENTS_H
#define LCD_SEGMENTS_H

/**
 Section: Included Files
*/
#include <xc.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
     
/**
 Section: Data Type Definitions
*/

/** LCD Segment Control Definition
 
 @Summary 
   Defines the LCD segment control.
 
 @Description
   This routine defines the LCD segment control.
 
 Remarks:
   None
 */
enum LCD_SEGMENT_CONTROL
{
    LCD_SEGMENT_OFF = 0,
    LCD_SEGMENT_ON = 1
};

/**
  Pixel Assignments
*/        
#define LCD_DOT6_Set(value) LCDDATA29bits.S28C7 = value
#define LCD_DOT6_On() LCDDATA29bits.S28C7 = 1
#define LCD_DOT6_Off() LCDDATA29bits.S28C7 = 0
#define LCD_DOT6_AltSet(value) LCDSDATA29bits.S28C7 = value
#define LCD_DOT6_AltOn() LCDSDATA29bits.S28C7 = 1
#define LCD_DOT6_AltOff() LCDSDATA29bits.S28C7 = 0

#define CHAR5_A_Set(value) LCDDATA5bits.S27C1 = value
#define CHAR5_A_On() LCDDATA5bits.S27C1 = 1
#define CHAR5_A_Off() LCDDATA5bits.S27C1 = 0
#define CHAR5_A_AltSet(value) LCDSDATA5bits.S27C1 = value
#define CHAR5_A_AltOn() LCDSDATA5bits.S27C1 = 1
#define CHAR5_A_AltOff() LCDSDATA5bits.S27C1 = 0

#define CHAR5_B_Set(value) LCDDATA9bits.S28C2 = value
#define CHAR5_B_On() LCDDATA9bits.S28C2 = 1
#define CHAR5_B_Off() LCDDATA9bits.S28C2 = 0
#define CHAR5_B_AltSet(value) LCDSDATA9bits.S28C2 = value
#define CHAR5_B_AltOn() LCDSDATA9bits.S28C2 = 1
#define CHAR5_B_AltOff() LCDSDATA9bits.S28C2 = 0

#define CHAR5_C_Set(value) LCDDATA17bits.S28C4 = value
#define CHAR5_C_On() LCDDATA17bits.S28C4 = 1
#define CHAR5_C_Off() LCDDATA17bits.S28C4 = 0
#define CHAR5_C_AltSet(value) LCDSDATA17bits.S28C4 = value
#define CHAR5_C_AltOn() LCDSDATA17bits.S28C4 = 1
#define CHAR5_C_AltOff() LCDSDATA17bits.S28C4 = 0

#define CHAR5_D_Set(value) LCDDATA25bits.S28C6 = value
#define CHAR5_D_On() LCDDATA25bits.S28C6 = 1
#define CHAR5_D_Off() LCDDATA25bits.S28C6 = 0
#define CHAR5_D_AltSet(value) LCDSDATA25bits.S28C6 = value
#define CHAR5_D_AltOn() LCDSDATA25bits.S28C6 = 1
#define CHAR5_D_AltOff() LCDSDATA25bits.S28C6 = 0

#define CHAR5_E_Set(value) LCDDATA29bits.S27C7 = value
#define CHAR5_E_On() LCDDATA29bits.S27C7 = 1
#define CHAR5_E_Off() LCDDATA29bits.S27C7 = 0
#define CHAR5_E_AltSet(value) LCDSDATA29bits.S27C7 = value
#define CHAR5_E_AltOn() LCDSDATA29bits.S27C7 = 1
#define CHAR5_E_AltOff() LCDSDATA29bits.S27C7 = 0

#define CHAR5_F_Set(value) LCDDATA25bits.S26C6 = value
#define CHAR5_F_On() LCDDATA25bits.S26C6 = 1
#define CHAR5_F_Off() LCDDATA25bits.S26C6 = 0
#define CHAR5_F_AltSet(value) LCDSDATA25bits.S26C6 = value
#define CHAR5_F_AltOn() LCDSDATA25bits.S26C6 = 1
#define CHAR5_F_AltOff() LCDSDATA25bits.S26C6 = 0

#define CHAR5_G_Set(value) LCDDATA17bits.S26C4 = value
#define CHAR5_G_On() LCDDATA17bits.S26C4 = 1
#define CHAR5_G_Off() LCDDATA17bits.S26C4 = 0
#define CHAR5_G_AltSet(value) LCDSDATA17bits.S26C4 = value
#define CHAR5_G_AltOn() LCDSDATA17bits.S26C4 = 1
#define CHAR5_G_AltOff() LCDSDATA17bits.S26C4 = 0

#define CHAR5_H_Set(value) LCDDATA13bits.S26C3 = value
#define CHAR5_H_On() LCDDATA13bits.S26C3 = 1
#define CHAR5_H_Off() LCDDATA13bits.S26C3 = 0
#define CHAR5_H_AltSet(value) LCDSDATA13bits.S26C3 = value
#define CHAR5_H_AltOn() LCDSDATA13bits.S26C3 = 1
#define CHAR5_H_AltOff() LCDSDATA13bits.S26C3 = 0

#define CHAR5_I_Set(value) LCDDATA17bits.S27C4 = value
#define CHAR5_I_On() LCDDATA17bits.S27C4 = 1
#define CHAR5_I_Off() LCDDATA17bits.S27C4 = 0
#define CHAR5_I_AltSet(value) LCDSDATA17bits.S27C4 = value
#define CHAR5_I_AltOn() LCDSDATA17bits.S27C4 = 1
#define CHAR5_I_AltOff() LCDSDATA17bits.S27C4 = 0

#define CHAR5_J_Set(value) LCDDATA21bits.S28C5 = value
#define CHAR5_J_On() LCDDATA21bits.S28C5 = 1
#define CHAR5_J_Off() LCDDATA21bits.S28C5 = 0
#define CHAR5_J_AltSet(value) LCDSDATA21bits.S28C5 = value
#define CHAR5_J_AltOn() LCDSDATA21bits.S28C5 = 1
#define CHAR5_J_AltOff() LCDSDATA21bits.S28C5 = 0

#define CHAR5_K_Set(value) LCDDATA9bits.S27C2 = value
#define CHAR5_K_On() LCDDATA9bits.S27C2 = 1
#define CHAR5_K_Off() LCDDATA9bits.S27C2 = 0
#define CHAR5_K_AltSet(value) LCDSDATA9bits.S27C2 = value
#define CHAR5_K_AltOn() LCDSDATA9bits.S27C2 = 1
#define CHAR5_K_AltOff() LCDSDATA9bits.S27C2 = 0

#define CHAR5_L_Set(value) LCDDATA13bits.S27C3 = value
#define CHAR5_L_On() LCDDATA13bits.S27C3 = 1
#define CHAR5_L_Off() LCDDATA13bits.S27C3 = 0
#define CHAR5_L_AltSet(value) LCDSDATA13bits.S27C3 = value
#define CHAR5_L_AltOn() LCDSDATA13bits.S27C3 = 1
#define CHAR5_L_AltOff() LCDSDATA13bits.S27C3 = 0

#define CHAR5_M_Set(value) LCDDATA13bits.S28C3 = value
#define CHAR5_M_On() LCDDATA13bits.S28C3 = 1
#define CHAR5_M_Off() LCDDATA13bits.S28C3 = 0
#define CHAR5_M_AltSet(value) LCDSDATA13bits.S28C3 = value
#define CHAR5_M_AltOn() LCDSDATA13bits.S28C3 = 1
#define CHAR5_M_AltOff() LCDSDATA13bits.S28C3 = 0

#define CHAR5_N_Set(value) LCDDATA25bits.S27C6 = value
#define CHAR5_N_On() LCDDATA25bits.S27C6 = 1
#define CHAR5_N_Off() LCDDATA25bits.S27C6 = 0
#define CHAR5_N_AltSet(value) LCDSDATA25bits.S27C6 = value
#define CHAR5_N_AltOn() LCDSDATA25bits.S27C6 = 1
#define CHAR5_N_AltOff() LCDSDATA25bits.S27C6 = 0

#define CHAR5_O_Set(value) LCDDATA21bits.S27C5 = value
#define CHAR5_O_On() LCDDATA21bits.S27C5 = 1
#define CHAR5_O_Off() LCDDATA21bits.S27C5 = 0
#define CHAR5_O_AltSet(value) LCDSDATA21bits.S27C5 = value
#define CHAR5_O_AltOn() LCDSDATA21bits.S27C5 = 1
#define CHAR5_O_AltOff() LCDSDATA21bits.S27C5 = 0

#define CHAR5_P_Set(value) LCDDATA21bits.S26C5 = value
#define CHAR5_P_On() LCDDATA21bits.S26C5 = 1
#define CHAR5_P_Off() LCDDATA21bits.S26C5 = 0
#define CHAR5_P_AltSet(value) LCDSDATA21bits.S26C5 = value
#define CHAR5_P_AltOn() LCDSDATA21bits.S26C5 = 1
#define CHAR5_P_AltOff() LCDSDATA21bits.S26C5 = 0

#define LCD_DOT5_Set(value) LCDDATA9bits.S26C2 = value
#define LCD_DOT5_On() LCDDATA9bits.S26C2 = 1
#define LCD_DOT5_Off() LCDDATA9bits.S26C2 = 0
#define LCD_DOT5_AltSet(value) LCDSDATA9bits.S26C2 = value
#define LCD_DOT5_AltOn() LCDSDATA9bits.S26C2 = 1
#define LCD_DOT5_AltOff() LCDSDATA9bits.S26C2 = 0

#define LCD_DOT4_Set(value) LCDDATA29bits.S26C7 = value
#define LCD_DOT4_On() LCDDATA29bits.S26C7 = 1
#define LCD_DOT4_Off() LCDDATA29bits.S26C7 = 0
#define LCD_DOT4_AltSet(value) LCDSDATA29bits.S26C7 = value
#define LCD_DOT4_AltOn() LCDSDATA29bits.S26C7 = 1
#define LCD_DOT4_AltOff() LCDSDATA29bits.S26C7 = 0

#define CHAR4_A_Set(value) LCDDATA1bits.S19C0 = value
#define CHAR4_A_On() LCDDATA1bits.S19C0 = 1
#define CHAR4_A_Off() LCDDATA1bits.S19C0 = 0
#define CHAR4_A_AltSet(value) LCDSDATA1bits.S19C0 = value
#define CHAR4_A_AltOn() LCDSDATA1bits.S19C0 = 1
#define CHAR4_A_AltOff() LCDSDATA1bits.S19C0 = 0

#define CHAR4_B_Set(value) LCDDATA1bits.S25C0 = value
#define CHAR4_B_On() LCDDATA1bits.S25C0 = 1
#define CHAR4_B_Off() LCDDATA1bits.S25C0 = 0
#define CHAR4_B_AltSet(value) LCDSDATA1bits.S25C0 = value
#define CHAR4_B_AltOn() LCDSDATA1bits.S25C0 = 1
#define CHAR4_B_AltOff() LCDSDATA1bits.S25C0 = 0

#define CHAR4_C_Set(value) LCDDATA9bits.S25C2 = value
#define CHAR4_C_On() LCDDATA9bits.S25C2 = 1
#define CHAR4_C_Off() LCDDATA9bits.S25C2 = 0
#define CHAR4_C_AltSet(value) LCDSDATA9bits.S25C2 = value
#define CHAR4_C_AltOn() LCDSDATA9bits.S25C2 = 1
#define CHAR4_C_AltOff() LCDSDATA9bits.S25C2 = 0

#define CHAR4_D_Set(value) LCDDATA13bits.S25C3 = value
#define CHAR4_D_On() LCDDATA13bits.S25C3 = 1
#define CHAR4_D_Off() LCDDATA13bits.S25C3 = 0
#define CHAR4_D_AltSet(value) LCDSDATA13bits.S25C3 = value
#define CHAR4_D_AltOn() LCDSDATA13bits.S25C3 = 1
#define CHAR4_D_AltOff() LCDSDATA13bits.S25C3 = 0

#define CHAR4_E_Set(value) LCDDATA9bits.S19C2 = value
#define CHAR4_E_On() LCDDATA9bits.S19C2 = 1
#define CHAR4_E_Off() LCDDATA9bits.S19C2 = 0
#define CHAR4_E_AltSet(value) LCDSDATA9bits.S19C2 = value
#define CHAR4_E_AltOn() LCDSDATA9bits.S19C2 = 1
#define CHAR4_E_AltOff() LCDSDATA9bits.S19C2 = 0

#define CHAR4_F_Set(value) LCDDATA5bits.S19C1 = value
#define CHAR4_F_On() LCDDATA5bits.S19C1 = 1
#define CHAR4_F_Off() LCDDATA5bits.S19C1 = 0
#define CHAR4_F_AltSet(value) LCDSDATA5bits.S19C1 = value
#define CHAR4_F_AltOn() LCDSDATA5bits.S19C1 = 1
#define CHAR4_F_AltOff() LCDSDATA5bits.S19C1 = 0

#define CHAR4_G_Set(value) LCDDATA5bits.S25C1 = value
#define CHAR4_G_On() LCDDATA5bits.S25C1 = 1
#define CHAR4_G_Off() LCDDATA5bits.S25C1 = 0
#define CHAR4_G_AltSet(value) LCDSDATA5bits.S25C1 = value
#define CHAR4_G_AltOn() LCDSDATA5bits.S25C1 = 1
#define CHAR4_G_AltOff() LCDSDATA5bits.S25C1 = 0

#define LCD_DOT3_Set(value) LCDDATA13bits.S19C3 = value
#define LCD_DOT3_On() LCDDATA13bits.S19C3 = 1
#define LCD_DOT3_Off() LCDDATA13bits.S19C3 = 0
#define LCD_DOT3_AltSet(value) LCDSDATA13bits.S19C3 = value
#define LCD_DOT3_AltOn() LCDSDATA13bits.S19C3 = 1
#define LCD_DOT3_AltOff() LCDSDATA13bits.S19C3 = 0

#define CHAR1_A_Set(value) LCDDATA0bits.S04C0 = value
#define CHAR1_A_On() LCDDATA0bits.S04C0 = 1
#define CHAR1_A_Off() LCDDATA0bits.S04C0 = 0
#define CHAR1_A_AltSet(value) LCDSDATA0bits.S04C0 = value
#define CHAR1_A_AltOn() LCDSDATA0bits.S04C0 = 1
#define CHAR1_A_AltOff() LCDSDATA0bits.S04C0 = 0

#define CHAR1_B_Set(value) LCDDATA1bits.S18C0 = value
#define CHAR1_B_On() LCDDATA1bits.S18C0 = 1
#define CHAR1_B_Off() LCDDATA1bits.S18C0 = 0
#define CHAR1_B_AltSet(value) LCDSDATA1bits.S18C0 = value
#define CHAR1_B_AltOn() LCDSDATA1bits.S18C0 = 1
#define CHAR1_B_AltOff() LCDSDATA1bits.S18C0 = 0

#define CHAR1_C_Set(value) LCDDATA9bits.S18C2 = value
#define CHAR1_C_On() LCDDATA9bits.S18C2 = 1
#define CHAR1_C_Off() LCDDATA9bits.S18C2 = 0
#define CHAR1_C_AltSet(value) LCDSDATA9bits.S18C2 = value
#define CHAR1_C_AltOn() LCDSDATA9bits.S18C2 = 1
#define CHAR1_C_AltOff() LCDSDATA9bits.S18C2 = 0

#define CHAR1_D_Set(value) LCDDATA12bits.S04C3 = value
#define CHAR1_D_On() LCDDATA12bits.S04C3 = 1
#define CHAR1_D_Off() LCDDATA12bits.S04C3 = 0
#define CHAR1_D_AltSet(value) LCDSDATA12bits.S04C3 = value
#define CHAR1_D_AltOn() LCDSDATA12bits.S04C3 = 1
#define CHAR1_D_AltOff() LCDSDATA12bits.S04C3 = 0

#define CHAR1_E_Set(value) LCDDATA8bits.S04C2 = value
#define CHAR1_E_On() LCDDATA8bits.S04C2 = 1
#define CHAR1_E_Off() LCDDATA8bits.S04C2 = 0
#define CHAR1_E_AltSet(value) LCDSDATA8bits.S04C2 = value
#define CHAR1_E_AltOn() LCDSDATA8bits.S04C2 = 1
#define CHAR1_E_AltOff() LCDSDATA8bits.S04C2 = 0

#define CHAR1_F_Set(value) LCDDATA4bits.S04C1 = value
#define CHAR1_F_On() LCDDATA4bits.S04C1 = 1
#define CHAR1_F_Off() LCDDATA4bits.S04C1 = 0
#define CHAR1_F_AltSet(value) LCDSDATA4bits.S04C1 = value
#define CHAR1_F_AltOn() LCDSDATA4bits.S04C1 = 1
#define CHAR1_F_AltOff() LCDSDATA4bits.S04C1 = 0

#define CHAR1_G_Set(value) LCDDATA5bits.S18C1 = value
#define CHAR1_G_On() LCDDATA5bits.S18C1 = 1
#define CHAR1_G_Off() LCDDATA5bits.S18C1 = 0
#define CHAR1_G_AltSet(value) LCDSDATA5bits.S18C1 = value
#define CHAR1_G_AltOn() LCDSDATA5bits.S18C1 = 1
#define CHAR1_G_AltOff() LCDSDATA5bits.S18C1 = 0

#define LCD_DOT2_Set(value) LCDDATA29bits.S18C7 = value
#define LCD_DOT2_On() LCDDATA29bits.S18C7 = 1
#define LCD_DOT2_Off() LCDDATA29bits.S18C7 = 0
#define LCD_DOT2_AltSet(value) LCDSDATA29bits.S18C7 = value
#define LCD_DOT2_AltOn() LCDSDATA29bits.S18C7 = 1
#define LCD_DOT2_AltOff() LCDSDATA29bits.S18C7 = 0

#define LCD_DOT1_Set(value) LCDDATA13bits.S18C3 = value
#define LCD_DOT1_On() LCDDATA13bits.S18C3 = 1
#define LCD_DOT1_Off() LCDDATA13bits.S18C3 = 0
#define LCD_DOT1_AltSet(value) LCDSDATA13bits.S18C3 = value
#define LCD_DOT1_AltOn() LCDSDATA13bits.S18C3 = 1
#define LCD_DOT1_AltOff() LCDSDATA13bits.S18C3 = 0

#define LCD_MICROCHIP1_Set(value) LCDDATA5bits.S26C1 = value
#define LCD_MICROCHIP1_On() LCDDATA5bits.S26C1 = 1
#define LCD_MICROCHIP1_Off() LCDDATA5bits.S26C1 = 0
#define LCD_MICROCHIP1_AltSet(value) LCDSDATA5bits.S26C1 = value
#define LCD_MICROCHIP1_AltOn() LCDSDATA5bits.S26C1 = 1
#define LCD_MICROCHIP1_AltOff() LCDSDATA5bits.S26C1 = 0

#define LCD_COLON1_Set(value) LCDDATA29bits.S19C7 = value
#define LCD_COLON1_On() LCDDATA29bits.S19C7 = 1
#define LCD_COLON1_Off() LCDDATA29bits.S19C7 = 0
#define LCD_COLON1_AltSet(value) LCDSDATA29bits.S19C7 = value
#define LCD_COLON1_AltOn() LCDSDATA29bits.S19C7 = 1
#define LCD_COLON1_AltOff() LCDSDATA29bits.S19C7 = 0

#define CHAR3_A_Set(value) LCDDATA17bits.S19C4 = value
#define CHAR3_A_On() LCDDATA17bits.S19C4 = 1
#define CHAR3_A_Off() LCDDATA17bits.S19C4 = 0
#define CHAR3_A_AltSet(value) LCDSDATA17bits.S19C4 = value
#define CHAR3_A_AltOn() LCDSDATA17bits.S19C4 = 1
#define CHAR3_A_AltOff() LCDSDATA17bits.S19C4 = 0

#define CHAR3_B_Set(value) LCDDATA17bits.S25C4 = value
#define CHAR3_B_On() LCDDATA17bits.S25C4 = 1
#define CHAR3_B_Off() LCDDATA17bits.S25C4 = 0
#define CHAR3_B_AltSet(value) LCDSDATA17bits.S25C4 = value
#define CHAR3_B_AltOn() LCDSDATA17bits.S25C4 = 1
#define CHAR3_B_AltOff() LCDSDATA17bits.S25C4 = 0

#define CHAR3_C_Set(value) LCDDATA25bits.S25C6 = value
#define CHAR3_C_On() LCDDATA25bits.S25C6 = 1
#define CHAR3_C_Off() LCDDATA25bits.S25C6 = 0
#define CHAR3_C_AltSet(value) LCDSDATA25bits.S25C6 = value
#define CHAR3_C_AltOn() LCDSDATA25bits.S25C6 = 1
#define CHAR3_C_AltOff() LCDSDATA25bits.S25C6 = 0

#define CHAR3_D_Set(value) LCDDATA29bits.S25C7 = value
#define CHAR3_D_On() LCDDATA29bits.S25C7 = 1
#define CHAR3_D_Off() LCDDATA29bits.S25C7 = 0
#define CHAR3_D_AltSet(value) LCDSDATA29bits.S25C7 = value
#define CHAR3_D_AltOn() LCDSDATA29bits.S25C7 = 1
#define CHAR3_D_AltOff() LCDSDATA29bits.S25C7 = 0

#define CHAR3_E_Set(value) LCDDATA25bits.S19C6 = value
#define CHAR3_E_On() LCDDATA25bits.S19C6 = 1
#define CHAR3_E_Off() LCDDATA25bits.S19C6 = 0
#define CHAR3_E_AltSet(value) LCDSDATA25bits.S19C6 = value
#define CHAR3_E_AltOn() LCDSDATA25bits.S19C6 = 1
#define CHAR3_E_AltOff() LCDSDATA25bits.S19C6 = 0

#define CHAR3_F_Set(value) LCDDATA21bits.S19C5 = value
#define CHAR3_F_On() LCDDATA21bits.S19C5 = 1
#define CHAR3_F_Off() LCDDATA21bits.S19C5 = 0
#define CHAR3_F_AltSet(value) LCDSDATA21bits.S19C5 = value
#define CHAR3_F_AltOn() LCDSDATA21bits.S19C5 = 1
#define CHAR3_F_AltOff() LCDSDATA21bits.S19C5 = 0

#define CHAR3_G_Set(value) LCDDATA21bits.S25C5 = value
#define CHAR3_G_On() LCDDATA21bits.S25C5 = 1
#define CHAR3_G_Off() LCDDATA21bits.S25C5 = 0
#define CHAR3_G_AltSet(value) LCDSDATA21bits.S25C5 = value
#define CHAR3_G_AltOn() LCDSDATA21bits.S25C5 = 1
#define CHAR3_G_AltOff() LCDSDATA21bits.S25C5 = 0

#define LCD_LOW_POWER_Set(value) LCDDATA5bits.S28C1 = value
#define LCD_LOW_POWER_On() LCDDATA5bits.S28C1 = 1
#define LCD_LOW_POWER_Off() LCDDATA5bits.S28C1 = 0
#define LCD_LOW_POWER_AltSet(value) LCDSDATA5bits.S28C1 = value
#define LCD_LOW_POWER_AltOn() LCDSDATA5bits.S28C1 = 1
#define LCD_LOW_POWER_AltOff() LCDSDATA5bits.S28C1 = 0

#define CHAR2_A_Set(value) LCDDATA16bits.S04C4 = value
#define CHAR2_A_On() LCDDATA16bits.S04C4 = 1
#define CHAR2_A_Off() LCDDATA16bits.S04C4 = 0
#define CHAR2_A_AltSet(value) LCDSDATA16bits.S04C4 = value
#define CHAR2_A_AltOn() LCDSDATA16bits.S04C4 = 1
#define CHAR2_A_AltOff() LCDSDATA16bits.S04C4 = 0

#define CHAR2_B_Set(value) LCDDATA17bits.S18C4 = value
#define CHAR2_B_On() LCDDATA17bits.S18C4 = 1
#define CHAR2_B_Off() LCDDATA17bits.S18C4 = 0
#define CHAR2_B_AltSet(value) LCDSDATA17bits.S18C4 = value
#define CHAR2_B_AltOn() LCDSDATA17bits.S18C4 = 1
#define CHAR2_B_AltOff() LCDSDATA17bits.S18C4 = 0

#define CHAR2_C_Set(value) LCDDATA25bits.S18C6 = value
#define CHAR2_C_On() LCDDATA25bits.S18C6 = 1
#define CHAR2_C_Off() LCDDATA25bits.S18C6 = 0
#define CHAR2_C_AltSet(value) LCDSDATA25bits.S18C6 = value
#define CHAR2_C_AltOn() LCDSDATA25bits.S18C6 = 1
#define CHAR2_C_AltOff() LCDSDATA25bits.S18C6 = 0

#define CHAR2_D_Set(value) LCDDATA28bits.S04C7 = value
#define CHAR2_D_On() LCDDATA28bits.S04C7 = 1
#define CHAR2_D_Off() LCDDATA28bits.S04C7 = 0
#define CHAR2_D_AltSet(value) LCDSDATA28bits.S04C7 = value
#define CHAR2_D_AltOn() LCDSDATA28bits.S04C7 = 1
#define CHAR2_D_AltOff() LCDSDATA28bits.S04C7 = 0

#define CHAR2_E_Set(value) LCDDATA24bits.S04C6 = value
#define CHAR2_E_On() LCDDATA24bits.S04C6 = 1
#define CHAR2_E_Off() LCDDATA24bits.S04C6 = 0
#define CHAR2_E_AltSet(value) LCDSDATA24bits.S04C6 = value
#define CHAR2_E_AltOn() LCDSDATA24bits.S04C6 = 1
#define CHAR2_E_AltOff() LCDSDATA24bits.S04C6 = 0

#define CHAR2_F_Set(value) LCDDATA20bits.S04C5 = value
#define CHAR2_F_On() LCDDATA20bits.S04C5 = 1
#define CHAR2_F_Off() LCDDATA20bits.S04C5 = 0
#define CHAR2_F_AltSet(value) LCDSDATA20bits.S04C5 = value
#define CHAR2_F_AltOn() LCDSDATA20bits.S04C5 = 1
#define CHAR2_F_AltOff() LCDSDATA20bits.S04C5 = 0

#define CHAR2_G_Set(value) LCDDATA21bits.S18C5 = value
#define CHAR2_G_On() LCDDATA21bits.S18C5 = 1
#define CHAR2_G_Off() LCDDATA21bits.S18C5 = 0
#define CHAR2_G_AltSet(value) LCDSDATA21bits.S18C5 = value
#define CHAR2_G_AltOn() LCDSDATA21bits.S18C5 = 1
#define CHAR2_G_AltOff() LCDSDATA21bits.S18C5 = 0

#define BATTERY1_A_Set(value) LCDDATA15bits.S63C3 = value
#define BATTERY1_A_On() LCDDATA15bits.S63C3 = 1
#define BATTERY1_A_Off() LCDDATA15bits.S63C3 = 0
#define BATTERY1_A_AltSet(value) LCDSDATA15bits.S63C3 = value
#define BATTERY1_A_AltOn() LCDSDATA15bits.S63C3 = 1
#define BATTERY1_A_AltOff() LCDSDATA15bits.S63C3 = 0

#define BATTERY1_B_Set(value) LCDDATA1bits.S28C0 = value
#define BATTERY1_B_On() LCDDATA1bits.S28C0 = 1
#define BATTERY1_B_Off() LCDDATA1bits.S28C0 = 0
#define BATTERY1_B_AltSet(value) LCDSDATA1bits.S28C0 = value
#define BATTERY1_B_AltOn() LCDSDATA1bits.S28C0 = 1
#define BATTERY1_B_AltOff() LCDSDATA1bits.S28C0 = 0

#define BATTERY1_C_Set(value) LCDDATA1bits.S26C0 = value
#define BATTERY1_C_On() LCDDATA1bits.S26C0 = 1
#define BATTERY1_C_Off() LCDDATA1bits.S26C0 = 0
#define BATTERY1_C_AltSet(value) LCDSDATA1bits.S26C0 = value
#define BATTERY1_C_AltOn() LCDSDATA1bits.S26C0 = 1
#define BATTERY1_C_AltOff() LCDSDATA1bits.S26C0 = 0

#define BATTERY1_D_Set(value) LCDDATA1bits.S27C0 = value
#define BATTERY1_D_On() LCDDATA1bits.S27C0 = 1
#define BATTERY1_D_Off() LCDDATA1bits.S27C0 = 0
#define BATTERY1_D_AltSet(value) LCDSDATA1bits.S27C0 = value
#define BATTERY1_D_AltOn() LCDSDATA1bits.S27C0 = 1
#define BATTERY1_D_AltOff() LCDSDATA1bits.S27C0 = 0


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif //LCD_SEGMENTS_H



