/**
  LCD Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    lcd_16seg.c

  @Summary
    This is the generated driver implementation file for the LCD driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for LCD.
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
#include "lcd_segments.h"

/**
 Section: File specific functions and data types
*/

/**********************************
 *  Bit mapping for 16-seg character
 **********************************
 *            A     B
 *          ----- -----
 *         | \   |   / |
 *       H |  K  L  M  | C
 *         |   \ | /   |
 *          --I-- --J--
 *         |   / | \   |
 *       G |  P  O  N  | D
 *         | /   |   \ |
 *          ----- -----
 *            F     E
 **********************************/

struct CHARACTER_DECODER_16_SEGMENT
{
    char character;
    uint16_t code;
};

static struct CHARACTER_DECODER_16_SEGMENT decoder_16_segment[] = 
{
    //        PONMLKJIHGFEDCBA
    { ' ',  0b0000000000000000 }, //0x20
    { '!',  0b0000000000001100 }, //0x21
    { '"',  0b0000100000000100 }, //0x22
    { '#',  0b0100101100111100 }, //0x23
    { '$',  0b0100101110111011 }, //0x24
    { '%',  0b1101101110011001 }, //0x25
    { '&',  0b0010110101110001 }, //0x26
    { '\'', 0b0000100000000000 }, //0x27
    { '(',  0b0011000000000000 }, //0x28
    { ')',  0b1000010000000000 }, //0x29
    { '*',  0b1111111100000000 }, //0x2A
    { '+',  0b0100101100000000 }, //0x2B
    { ',',  0b1000000000000000 }, //0x2C
    { '-',  0b0000001100000000 }, //0x2D
    { '.',  0b0000000000001000 }, //0x2E
    { '/',  0b1001000000000000 }, //0x2F
    
    //        PONMLKJIHGFEDCBA
    { '0',  0b1001000011111111 }, //0x30
    { '1',  0b0001000000001100 }, //0x31
    { '2',  0b0000001101110111 }, //0x32
    { '3',  0b0000001000111111 }, //0x33
    { '4',  0b0000001110001100 }, //0x34
    { '5',  0b0010000110110011 }, //0x35
    { '6',  0b0000001111111011 }, //0x36
    { '7',  0b0000000000001111 }, //0x37
    { '8',  0b0000001111111111 }, //0x38
    { '9',  0b0000001110111111 }, //0x39
    { ':',  0b0100100000000000 }, //0x3A
    { ';',  0b1000100000000000 }, //0x3B
    { '<',  0b0011000100000000 }, //0x3C
    { '=',  0b0000001100110000 }, //0x3D
    { '>',  0b1000011000000000 }, //0x3E
    { '?',  0b0100001000000111 }, //0x3F
     
    //        PONMLKJIHGFEDCBA
    { '@',  0b0000101011110111 }, //0x40
    { 'A',  0b0000001111001111 }, //0x41
    { 'B',  0b0100101000111111 }, //0x42
    { 'C',  0b0000000011110011 }, //0x43
    { 'D',  0b0100100000111111 }, //0x44
    { 'E',  0b0000000111110011 }, //0x45
    { 'F',  0b0000000111000011 }, //0x46
    { 'G',  0b0000001011111011 }, //0x47
    { 'H',  0b0000001111001100 }, //0x48
    { 'I',  0b0100100000110011 }, //0x49
    { 'J',  0b0000000001111100 }, //0x4A
    { 'K',  0b0011000111000000 }, //0x4B
    { 'L',  0b0000000011110000 }, //0x4C
    { 'M',  0b0001010011001100 }, //0x4D
    { 'N',  0b0010010011001100 }, //0x4E
    { 'O',  0b0000000011111111 }, //0x4F
    
    //        PONMLKJIHGFEDCBA
    { 'P',  0b0000001111000111 }, //0x50
    { 'Q',  0b0010000011111111 }, //0x51
    { 'R',  0b0010001111000111 }, //0x52
    { 'S',  0b0000001110111011 }, //0x53
    { 'T',  0b0100100000000011 }, //0x54
    { 'U',  0b0000000011111100 }, //0x55
    { 'V',  0b1001000011000000 }, //0x56
    { 'W',  0b1010000011001100 }, //0x57
    { 'X',  0b1011010000000000 }, //0x58
    { 'Y',  0b0000001110111100 }, //0x59
    { 'Z',  0b1001000000110011 }, //0x5A
    { '[',  0b0100100000010010 }, //0x5B
    { '\\', 0b0010010000000000 }, //0x5C
    { ']',  0b0100100000100001 }, //0x5D
    { '^',  0b1010000000000000 }, //0x5E
    { '_',  0b0000000000110000 }, //0x5F
    
    //        PONMLKJIHGFEDCBA
    { '`',  0b0000010000000000 }, //0x60
    { 'a',  0b0100000101110000 }, //0x61
    { 'b',  0b0100000111100000 }, //0x62
    { 'c',  0b0000000101100000 }, //0x63
    { 'd',  0b0100001000011100 }, //0x64
    { 'e',  0b1000000010110000 }, //0x65
    { 'f',  0b0100101100000010 }, //0x66
    { 'g',  0b0100100110100001 }, //0x67
    { 'h',  0b0100000111000000 }, //0x68
    { 'i',  0b0100000000000000 }, //0x69
    { 'j',  0b0100100001100000 }, //0x6A
    { 'k',  0b0111100000000000 }, //0x6B
    { 'l',  0b0000000011000000 }, //0x6C
    { 'm',  0b0100001101001000 }, //0x6D
    { 'n',  0b0100000101000000 }, //0x6E
    { 'o',  0b0100000101100000 }, //0x6F
    
    //        PONMLKJIHGFEDCBA
    { 'p',  0b0000100111000001 }, //0x70
    { 'q',  0b0100100110000001 }, //0x71
    { 'r',  0b0000000101000000 }, //0x72
    { 's',  0b0100000110100001 }, //0x73
    { 't',  0b0000000111100000 }, //0x74
    { 'u',  0b0100000001100000 }, //0x75
    { 'v',  0b1000000001000000 }, //0x76
    { 'w',  0b1010000001001000 }, //0x77
    { 'x',  0b1011010000000000 }, //0x78
    { 'y',  0b0000101000011100 }, //0x79
    { 'z',  0b1000000100100000 }, //0x7A
    { '{',  0b0100100100010010 }, //0x7B
    { '|',  0b0100100000000000 }, //0x7C
    { '}',  0b0100101000100001 }, //0x7D
    { '~',  0b1001001100000000 }, //0x7E    
};

static uint16_t CharTo16Seg(char inputCharacter);

/**
 Section: Driver Interface Function Definitions
*/

static uint16_t CharTo16Seg(char inputCharacter)
{
    uint8_t i;
    
    for(i=0; i<sizeof(decoder_16_segment)/sizeof(struct CHARACTER_DECODER_16_SEGMENT); i++)
    {
        if(decoder_16_segment[i].character == inputCharacter)
        {
            return decoder_16_segment[i].code;
        }
    }
    
    return decoder_16_segment[0].code;
}

void LCD_CHAR5_Print(char cData) 
{
    uint16_t data = CharTo16Seg(cData);
    
    CHAR5_A_Set(data & 0x01);
    data >>= 1;
    CHAR5_B_Set(data & 0x01);
    data >>= 1;
    CHAR5_C_Set(data & 0x01);
    data >>= 1;
    CHAR5_D_Set(data & 0x01);
    data >>= 1;
    CHAR5_E_Set(data & 0x01);
    data >>= 1;
    CHAR5_F_Set(data & 0x01);
    data >>= 1;
    CHAR5_G_Set(data & 0x01);
    data >>= 1;
    CHAR5_H_Set(data & 0x01);
    data >>= 1;
    CHAR5_I_Set(data & 0x01);
    data >>= 1;
    CHAR5_J_Set(data & 0x01);
    data >>= 1;
    CHAR5_K_Set(data & 0x01);
    data >>= 1;
    CHAR5_L_Set(data & 0x01);
    data >>= 1;
    CHAR5_M_Set(data & 0x01);
    data >>= 1;
    CHAR5_N_Set(data & 0x01);
    data >>= 1;
    CHAR5_O_Set(data & 0x01);
    data >>= 1;
    CHAR5_P_Set(data & 0x01);
}

/* AltPrint is used for blinking and alternate screen modes.  This sets which
 * segments will be active in this alternate functionality. */
void LCD_CHAR5_AltPrint(char character) 
{
    uint16_t data = CharTo16Seg(character);
    
    CHAR5_A_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_B_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_C_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_D_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_E_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_F_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_G_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_H_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_I_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_J_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_K_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_L_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_M_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_N_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_O_AltSet(data & 0x01);
    data >>= 1;
    CHAR5_P_AltSet(data & 0x01);
}






