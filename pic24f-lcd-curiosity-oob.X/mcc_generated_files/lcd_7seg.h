/**
  LCD Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    lcd_7seg.h

  @Summary
    This is the generated header file for the LCD driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides APIs for driver for LCD.
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

#ifndef LCD_7SEG_H
#define LCD_7SEG_H

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
 Section: Interface Routines
*/

/**
  @Summary
    Sets the 7 segment digit CHAR4 with the value.
  
  @Description
    This routine sets the 7 segment digit CHAR4 with the value.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR4_Print(char cData);
    </code>
*/
void LCD_CHAR4_Print(char cData);

/**
  @Summary
    Sets the 7 segment digit CHAR4 with the value in the alternate mode.
  
  @Description
    Sets routine sets the 7 segment digit CHAR4 with the value. This is 
    used in blinking and alternate screen modes.  This sets which segments will 
    be active in this alternate functionality.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR4_AltPrint(char cData);
    </code>
*/
void LCD_CHAR4_AltPrint(char cData);

/**
  @Summary
    Sets the 7 segment digit CHAR1 with the value.
  
  @Description
    This routine sets the 7 segment digit CHAR1 with the value.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR1_Print(char cData);
    </code>
*/
void LCD_CHAR1_Print(char cData);

/**
  @Summary
    Sets the 7 segment digit CHAR1 with the value in the alternate mode.
  
  @Description
    Sets routine sets the 7 segment digit CHAR1 with the value. This is 
    used in blinking and alternate screen modes.  This sets which segments will 
    be active in this alternate functionality.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR1_AltPrint(char cData);
    </code>
*/
void LCD_CHAR1_AltPrint(char cData);

/**
  @Summary
    Sets the 7 segment digit CHAR3 with the value.
  
  @Description
    This routine sets the 7 segment digit CHAR3 with the value.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR3_Print(char cData);
    </code>
*/
void LCD_CHAR3_Print(char cData);

/**
  @Summary
    Sets the 7 segment digit CHAR3 with the value in the alternate mode.
  
  @Description
    Sets routine sets the 7 segment digit CHAR3 with the value. This is 
    used in blinking and alternate screen modes.  This sets which segments will 
    be active in this alternate functionality.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR3_AltPrint(char cData);
    </code>
*/
void LCD_CHAR3_AltPrint(char cData);

/**
  @Summary
    Sets the 7 segment digit CHAR2 with the value.
  
  @Description
    This routine sets the 7 segment digit CHAR2 with the value.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR2_Print(char cData);
    </code>
*/
void LCD_CHAR2_Print(char cData);

/**
  @Summary
    Sets the 7 segment digit CHAR2 with the value in the alternate mode.
  
  @Description
    Sets routine sets the 7 segment digit CHAR2 with the value. This is 
    used in blinking and alternate screen modes.  This sets which segments will 
    be active in this alternate functionality.
  
  @Returns
    None
  
  @Param
    cData - The character data to be printed.
    
  @Example
    <code>
     LCD_CHAR2_AltPrint(char cData);
    </code>
*/
void LCD_CHAR2_AltPrint(char cData);


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif //LCD_7SEG_H



