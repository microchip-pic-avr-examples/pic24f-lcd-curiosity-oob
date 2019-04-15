/*******************************************************************************
Copyright 2019 Microchip Technology Inc. (www.microchip.com)

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

#include <xc.h>
#include <stdio.h>
#include <string.h>

#include "segmented_lcd.h"

static void SEG_LCD_PrintChar(char c, uint8_t location);
static void SEG_LCD_PrintCharAlternate(char c, uint8_t location);
static void Set7Seg1(uint8_t data);
static void Set7Seg2(uint8_t data);
static void Set7Seg3(uint8_t data);
static void Set7Seg4(uint8_t data);
static void Set16Seg5(uint16_t data);
static void Set7Seg1_Alternate(uint8_t data);
static void Set7Seg2_Alternate(uint8_t data);
static void Set7Seg3_Alternate(uint8_t data);
static void Set7Seg4_Alternate(uint8_t data);
static void Set16Seg5_Alternate(uint16_t data);

/**********************************
 *  Bit mapping for 7-seg character
 **********************************
 *            A
 *          -----
 *         |     |
 *       F |  G  | B
 *          -----
 *         |     | 
 *       E |  D  | C
 *          -----
 **********************************/

#define    CHAR1_A  LCDDATA0bits.S04C0
#define    CHAR1_B  LCDDATA1bits.S18C0
#define    CHAR1_C  LCDDATA9bits.S18C2
#define    CHAR1_D  LCDDATA12bits.S04C3
#define    CHAR1_E  LCDDATA8bits.S04C2
#define    CHAR1_F  LCDDATA4bits.S04C1
#define    CHAR1_G  LCDDATA5bits.S18C1

#define    CHAR1_A_SDATA  LCDSDATA0bits.S04C0
#define    CHAR1_B_SDATA  LCDSDATA1bits.S18C0
#define    CHAR1_C_SDATA  LCDSDATA9bits.S18C2
#define    CHAR1_D_SDATA  LCDSDATA12bits.S04C3
#define    CHAR1_E_SDATA  LCDSDATA8bits.S04C2
#define    CHAR1_F_SDATA  LCDSDATA4bits.S04C1
#define    CHAR1_G_SDATA  LCDSDATA5bits.S18C1

#define    CHAR2_A  LCDDATA16bits.S04C4
#define    CHAR2_B  LCDDATA17bits.S18C4
#define    CHAR2_C  LCDDATA25bits.S18C6
#define    CHAR2_D  LCDDATA28bits.S04C7
#define    CHAR2_E  LCDDATA24bits.S04C6
#define    CHAR2_F  LCDDATA20bits.S04C5
#define    CHAR2_G  LCDDATA21bits.S18C5

#define    CHAR2_A_SDATA  LCDSDATA16bits.S04C4
#define    CHAR2_B_SDATA  LCDSDATA17bits.S18C4
#define    CHAR2_C_SDATA  LCDSDATA25bits.S18C6
#define    CHAR2_D_SDATA  LCDSDATA28bits.S04C7
#define    CHAR2_E_SDATA  LCDSDATA24bits.S04C6
#define    CHAR2_F_SDATA  LCDSDATA20bits.S04C5
#define    CHAR2_G_SDATA  LCDSDATA21bits.S18C5

#define    CHAR3_A  LCDDATA17bits.S19C4
#define    CHAR3_B  LCDDATA17bits.S25C4
#define    CHAR3_C  LCDDATA25bits.S25C6
#define    CHAR3_D  LCDDATA29bits.S25C7
#define    CHAR3_E  LCDDATA25bits.S19C6
#define    CHAR3_F  LCDDATA21bits.S19C5
#define    CHAR3_G  LCDDATA21bits.S25C5

#define    CHAR3_A_SDATA  LCDSDATA17bits.S19C4
#define    CHAR3_B_SDATA  LCDSDATA17bits.S25C4
#define    CHAR3_C_SDATA  LCDSDATA25bits.S25C6
#define    CHAR3_D_SDATA  LCDSDATA29bits.S25C7
#define    CHAR3_E_SDATA  LCDSDATA25bits.S19C6
#define    CHAR3_F_SDATA  LCDSDATA21bits.S19C5
#define    CHAR3_G_SDATA  LCDSDATA21bits.S25C5

#define    CHAR4_A  LCDDATA1bits.S19C0
#define    CHAR4_B  LCDDATA1bits.S25C0
#define    CHAR4_C  LCDDATA9bits.S25C2
#define    CHAR4_D  LCDDATA13bits.S25C3
#define    CHAR4_E  LCDDATA9bits.S19C2
#define    CHAR4_F  LCDDATA5bits.S19C1
#define    CHAR4_G  LCDDATA5bits.S25C1

#define    CHAR4_A_SDATA  LCDSDATA1bits.S19C0
#define    CHAR4_B_SDATA  LCDSDATA1bits.S25C0
#define    CHAR4_C_SDATA  LCDSDATA9bits.S25C2
#define    CHAR4_D_SDATA  LCDSDATA13bits.S25C3
#define    CHAR4_E_SDATA  LCDSDATA9bits.S19C2
#define    CHAR4_F_SDATA  LCDSDATA5bits.S19C1
#define    CHAR4_G_SDATA  LCDSDATA5bits.S25C1

/**********************************
 *  Bit mapping for 7-seg character
 **********************************
 *            0
 *          -----
 *         |     |
 *       5 |  6  | 1
 *          -----
 *         |     | 
 *       4 |  3  | 2
 *          -----
 **********************************/
static const uint8_t ascii_7seg_numbers_convert[10] = {
    0b00111111, //0
    0b00000110, //1
    0b01011011, //2
    0b01001111, //3
    0b01100110, //4
    0b01101101, //5
    0b01111101, //6
    0b00000111, //7
    0b01111111, //8
    0b01100111  //9
};

#define SEG7_BLANK  0b00000000 //
#define SEG7_MINUS  0b01000000 //-
#define SEG7_P      0b01110011 //P
#define SEG7_I      0b00110000 //I
#define SEG7_C      0b00111001 //C
#define SEG7_2      0b01011011 //2
#define SEG7_L      0b00111000 //L
    
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

#define    CHAR5_A  LCDDATA5bits.S27C1
#define    CHAR5_B  LCDDATA9bits.S28C2
#define    CHAR5_C  LCDDATA17bits.S28C4
#define    CHAR5_D  LCDDATA25bits.S28C6
#define    CHAR5_E  LCDDATA29bits.S27C7
#define    CHAR5_F  LCDDATA25bits.S26C6
#define    CHAR5_G  LCDDATA17bits.S26C4
#define    CHAR5_H  LCDDATA13bits.S26C3
#define    CHAR5_I  LCDDATA17bits.S27C4
#define    CHAR5_J  LCDDATA21bits.S28C5
#define    CHAR5_K  LCDDATA9bits.S27C2
#define    CHAR5_L  LCDDATA13bits.S27C3
#define    CHAR5_M  LCDDATA13bits.S28C3
#define    CHAR5_N  LCDDATA25bits.S27C6
#define    CHAR5_O  LCDDATA21bits.S27C5
#define    CHAR5_P  LCDDATA21bits.S26C5

#define    CHAR5_A_SDATA  LCDSDATA5bits.S27C1
#define    CHAR5_B_SDATA  LCDSDATA9bits.S28C2
#define    CHAR5_C_SDATA  LCDSDATA17bits.S28C4
#define    CHAR5_D_SDATA  LCDSDATA25bits.S28C6
#define    CHAR5_E_SDATA  LCDSDATA29bits.S27C7
#define    CHAR5_F_SDATA  LCDSDATA25bits.S26C6
#define    CHAR5_G_SDATA  LCDSDATA17bits.S26C4
#define    CHAR5_H_SDATA  LCDSDATA13bits.S26C3
#define    CHAR5_I_SDATA  LCDSDATA17bits.S27C4
#define    CHAR5_J_SDATA  LCDSDATA21bits.S28C5
#define    CHAR5_K_SDATA  LCDSDATA9bits.S27C2
#define    CHAR5_L_SDATA  LCDSDATA13bits.S27C3
#define    CHAR5_M_SDATA  LCDSDATA13bits.S28C3
#define    CHAR5_N_SDATA  LCDSDATA25bits.S27C6
#define    CHAR5_O_SDATA  LCDSDATA21bits.S27C5
#define    CHAR5_P_SDATA  LCDSDATA21bits.S26C5

/**********************************
 *  Bit mapping for 16-seg character
 **********************************
 *            0     1
 *          ----- -----
 *         | \   |   / |
 *       7 |  10 11 12 | 2
 *         |   \ | /   |
 *          --8-- --9--
 *         |   / | \   |
 *       6 |  15 14 13 | 3
 *         | /   |   \ |
 *          ----- -----
 *            5     4
 **********************************/
#define SEG16_C     0b0100100000010010
#define SEG16_F     0b0100101000000010
#define SEG16_4     0b0000001110001100
#define SEG16_BLANK 0b0000000000000000
#define SEG16_A     0b0000001111001111
#define SEG16_P     0b0000001111000111
#define SEG16_D     0b0100100000111111
#define SEG16_V     0b1000100011000000


#define    DP1  LCDDATA13bits.S18C3
#define    DP2  LCDDATA29bits.S18C7
#define    DP3  LCDDATA13bits.S19C3
#define    DP4  LCDDATA29bits.S26C7
#define    DP5  LCDDATA9bits.S26C2
#define    DP6  LCDDATA29bits.S28C7

#define    COLON LCDDATA29bits.S19C7

#define    X1   LCDDATA5bits.S26C1
#define    X3   LCDDATA1bits.S28C0
#define    X4   LCDDATA1bits.S26C0
#define    X5   LCDDATA1bits.S27C0
#define    X6   LCDDATA5bits.S28C1

#define    DP1_BLINK  LCDSDATA13bits.S18C3
#define    DP2_BLINK  LCDSDATA29bits.S18C7
#define    DP3_BLINK  LCDSDATA13bits.S19C3
#define    DP4_BLINK  LCDSDATA29bits.S26C7
#define    DP5_BLINK  LCDSDATA9bits.S26C2
#define    DP6_BLINK  LCDSDATA29bits.S28C7

#define    X3_BLINK     LCDSDATA1bits.S28C0
#define    COLON_BLINK  LCDSDATA29bits.S19C7
#define    X1_BLINK     LCDSDATA5bits.S26C1

void SEG_LCD_Initialize(void) {
    // Initialize LCD: no charge pump, 8 common drivers
    LCDPSbits.WFT = 0; // Type A waveform
    LCDPSbits.LP = 2; // LCD Prescaller 1:3
    LCDCONbits.LMUX = 0x07; // 8 commons, 1/3 Bias
    LCDCONbits.CS = 1; // Clock is LPRC
    LCDREFbits.VLCD1PE = 0; // Enable internal bias
    LCDREFbits.VLCD2PE = 0;
    LCDREFbits.VLCD3PE = 0;
    LCDREFbits.LRLAP = 0x03; // ladder in High-Power Interval A (transition)
    LCDREFbits.LRLBP = 0x03; // ladder in High-Power Interval B (steady state, for higher contrast ratio))
    LCDREFbits.LRLAT = 0x03; // Internal LCD reference ladder is in A Power mode for 3 clocks and B Power mode for 13 clocks
    LCDREFbits.LCDIRE = 1; // Internal Reference Enable
    LCDREFbits.LCDCST = 0; // Contrast 
    LCDREFbits.LCDIRE = 1;
    
    LCDREGbits.CLKSEL = 0b01; //LPRC
    LCDREGbits.CPEN = 1;  //enable charge pump

    LCDSE0 = 0b0000000000010000;
    LCDSE1 = 0b0001111000001100;
    LCDSE2 = 0b0000000000000000;
    LCDSE3 = 0b0000000000000000;
    
    _SMEMEN = 1;
    LCDFC1 = 256;
    
    LCDCONbits.LCDEN = 1; // enable LCD module
    
    X1 = 1;
}

void SEG_LCD_PrintPIC24(void) {   
    COLON_BLINK = 0;
    COLON = 0;
    DP1 = 0;
    DP2 = 0;
    DP3 = 0;
    DP4 = 0;
    DP5 = 0;
    DP6 = 0;
    DP1_BLINK = 0;
    DP2_BLINK = 0;
    DP3_BLINK = 0;
    DP4_BLINK = 0;
    DP5_BLINK = 0;
    DP6_BLINK = 0;
    X1_BLINK = 1;

    Set7Seg1(SEG7_P);       //P
    Set7Seg2(SEG7_I);       //I
    Set7Seg3(SEG7_C);       //C
    Set7Seg4(SEG7_2);       //2
    Set16Seg5(SEG16_4);     //4
    
    Set7Seg1_Alternate(SEG7_BLANK);   // 
    Set7Seg2_Alternate(SEG7_BLANK);   // 
    Set7Seg3_Alternate(SEG7_L);       //L
    Set7Seg4_Alternate(SEG7_C);       //C
    Set16Seg5_Alternate(SEG16_D);     //D
    
    _ELCDEN = 1;
    _SMEMEN = 1;
    _PMEMDIS = 0;
    _SMFCS = 1;
    _DMSEL = 0b11;
    _BLINKMODE = 0b00;
    LCDFC0=0x3FF;
    LCDACTRLbits.FCCS=00; // LCD clock source
}

static char print_buffer[10];

void SEG_LCD_PrintPot(uint16_t value) {
    _ELCDEN = 0;
    
    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%04i", value);

    COLON = 0;
    DP1 = 0;
    DP2 = 0;
    DP3 = 0;
    DP4 = 0;
    DP5 = 0;
    DP6 = 0;

    SEG_LCD_PrintChar(print_buffer[0], 1);
    SEG_LCD_PrintChar(print_buffer[1], 2);
    SEG_LCD_PrintChar(print_buffer[2], 3);
    SEG_LCD_PrintChar(print_buffer[3], 4);
    Set16Seg5(SEG16_BLANK);
}

void SEG_LCD_PrintTime(uint8_t hour, uint8_t minute) {  
    _BLINKMODE = 0b01;
    _BLINKFCS = 0b001;
    _DMSEL = 0b00;
    //_DMSEL = 0b10;
    _SMEMEN = 1;
    LCDFC0 = 0;
    LCDFC1 = 256;
    _ELCDEN = 1;
    
    COLON = 1;
    DP1 = 0;
    DP2 = 0;
    DP3 = 0;
    DP4 = 0;
    DP5 = 0;
    DP6 = 0;
    X1_BLINK = 0;

    Set7Seg1_Alternate(SEG7_BLANK);   // 
    Set7Seg2_Alternate(SEG7_BLANK);   // 
    Set7Seg3_Alternate(SEG7_BLANK);   // 
    Set7Seg4_Alternate(SEG7_BLANK);   // 
    Set16Seg5_Alternate(SEG16_BLANK); // 
    
    memset(print_buffer, ' ', sizeof (print_buffer));

    if(hour > 12)
    {
        hour -= 12;
        Set16Seg5(SEG16_P);
    }
    else if(hour == 0)
    {
        hour = 12;
        Set16Seg5(SEG16_A);
    }
    else if(hour == 12)
    {
        Set16Seg5(SEG16_P);
    }
    else
    {
        Set16Seg5(SEG16_A);
    }
    sprintf(print_buffer, "%2i", hour);

    SEG_LCD_PrintChar(print_buffer[0], 1);
    SEG_LCD_PrintChar(print_buffer[1], 2);

    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%02i", minute);

    SEG_LCD_PrintChar(print_buffer[0], 3);
    SEG_LCD_PrintChar(print_buffer[1], 4);
    
    COLON_BLINK = 1;
}

void SEG_LCD_PrintVoltage(double voltage) {
    _ELCDEN = 0;
    
    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%.3f", voltage);

    COLON = 0;
    DP1 = 0;
    DP2 = 0;
    DP3 = 0;
    DP4 = 0;
    DP5 = 0;
    DP6 = 0;

    SEG_LCD_PrintChar(print_buffer[0], 1);
    DP1 = 1;
    SEG_LCD_PrintChar(print_buffer[2], 2);
    SEG_LCD_PrintChar(print_buffer[3], 3);
    SEG_LCD_PrintChar(print_buffer[4], 4);
    Set16Seg5(SEG16_V);
}

void SEG_LCD_SetBatteryStatus(enum BATTERY_STATUS status) {
    switch (status) {
        case BATTERY_STATUS_UNKNOWN:
            X3 = 0;
            X4 = 0;
            X5 = 0;
            X3_BLINK = 0;
            break;
            
        case BATTERY_STATUS_FULL:
            X3 = 1;
            X4 = 1;
            X5 = 1;
            X3_BLINK = 0;
            break;

        case BATTERY_STATUS_MEDIUM:
            X3 = 1;
            X4 = 1;
            X5 = 0;
            X3_BLINK = 0;
            break;

        case BATTERY_STATUS_LOW:
            X3 = 1;
            X4 = 0;
            X5 = 0;
            X3_BLINK = 0;
            break;

        case BATTERY_STATUS_CRITICAL:
            X3 = 1;
            X4 = 0;
            X5 = 0;
            X3_BLINK = 1;
            break;
    }
}

void SEG_LCD_LowPowerModeEnable(bool low_power_mode_enabled) {
    X6 = low_power_mode_enabled;
    
    if (low_power_mode_enabled == true) {
        LCDREFbits.LRLAP = 0x01; // ladder in Low-Power Interval A (transition)
        LCDREFbits.LRLBP = 0x01; // ladder in low-Power Interval B (steady state, for higher contrast ratio))
    } else {
        LCDREFbits.LRLAP = 0x03; // ladder in High-Power Interval A (transition)
        LCDREFbits.LRLBP = 0x03; // ladder in High-Power Interval B (steady state, for higher contrast ratio))
    }
}

void SEG_LCD_PrintTemperature(double temp) {
    unsigned int i;
    unsigned int character;

    /* Print the Celsius temperature */
    COLON = 0;
    DP5 = 1;
    DP6 = 0;
    X1 = 1;
    
    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%.3f", temp);

    character = 0;
    for (i = 0; i<sizeof (print_buffer); i++) {
        if (print_buffer[i] == '.') {
            switch (character) {
                case 1:
                    DP1 = 1;
                    DP2 = 0;
                    DP3 = 0;
                    DP4 = 0;
                    break;
                case 2:
                    DP1 = 0;
                    DP2 = 1;
                    DP3 = 0;
                    DP4 = 0;
                    break;
                case 3:
                    DP1 = 0;
                    DP2 = 0;
                    DP3 = 1;
                    DP4 = 0;
                    break;
                default:
                    break;
            }
        } else {
            SEG_LCD_PrintChar(print_buffer[i], (character + 1));
            character++;
        }

        if (character >= 4) {
            break;
        }
    }
    
    Set16Seg5(SEG16_C);
    
    /* Print the Fahrenheit temperature */
    COLON_BLINK = 0;
    DP5_BLINK = 1;
    DP6_BLINK = 0;
    X1_BLINK = 1;
    
    /* convert C to F */
    temp = ((temp * 9/5) + 32);
            
    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%.3f", temp);

    character = 0;
    for (i = 0; i<sizeof (print_buffer); i++) {
        if (print_buffer[i] == '.') {
            switch (character) {
                case 1:
                    DP1_BLINK = 1;
                    DP2_BLINK = 0;
                    DP3_BLINK = 0;
                    DP4_BLINK = 0;
                    break;
                case 2:
                    DP1_BLINK = 0;
                    DP2_BLINK = 1;
                    DP3_BLINK = 0;
                    DP4_BLINK = 0;
                    break;
                case 3:
                    DP1_BLINK = 0;
                    DP2_BLINK = 0;
                    DP3_BLINK = 1;
                    DP4_BLINK = 0;
                    break;
                default:
                    break;
            }
        } else {
            SEG_LCD_PrintCharAlternate(print_buffer[i], (character + 1));
            character++;
        }

        if (character >= 4) {
            break;
        }
    }
    
    Set16Seg5_Alternate(SEG16_F);
    
    _SMEMEN = 1;
    _PMEMDIS = 0;
    _SMFCS = 1;
    _DMSEL = 0b11;
    _BLINKMODE = 0b00;
    LCDFC0=0x3FF;
    LCDACTRLbits.FCCS=00; // LCD clock source
    _ELCDEN = 1;
}

static uint8_t CharTo7Seg(char c)
{
    uint8_t data = 0x0;
    
    switch(c)
    {
        case '-':
            data = SEG7_MINUS;
            break;
        default:
            if ((c >= 0x30) && (c <= 0x39)) {
                data = ascii_7seg_numbers_convert[c - 0x30];
            }
            break;
    }
    
    return data;
}

static void SEG_LCD_PrintChar(char c, uint8_t location) 
{
    uint8_t data = CharTo7Seg(c);
    
    switch (location) {
        case 1:
            Set7Seg1(data);
            break;

        case 2:
            Set7Seg2(data);
            break;

        case 3:
            Set7Seg3(data);
            break;

        case 4:
            Set7Seg4(data);
            break;

        default:
            break;
    }
}

static void SEG_LCD_PrintCharAlternate(char c, uint8_t location) 
{
    uint8_t data = CharTo7Seg(c);
    
    switch (location) {
        case 1:
            Set7Seg1_Alternate(data);
            break;

        case 2:
            Set7Seg2_Alternate(data);
            break;

        case 3:
            Set7Seg3_Alternate(data);
            break;

        case 4:
            Set7Seg4_Alternate(data);
            break;

        default:
            break;
    }
}

/**********************************
 *  Bit mapping for 7-seg character
 **********************************
 *            A
 *          -----
 *         |     |
 *       F |  G  | B
 *          -----
 *         |     | 
 *       E |  D  | C
 *          -----
 **********************************/

static void Set7Seg1(uint8_t data) {
    CHAR1_A = data & 0x01;
    data >>= 1;
    CHAR1_B = data & 0x01;
    data >>= 1;
    CHAR1_C = data & 0x01;
    data >>= 1;
    CHAR1_D = data & 0x01;
    data >>= 1;
    CHAR1_E = data & 0x01;
    data >>= 1;
    CHAR1_F = data & 0x01;
    data >>= 1;
    CHAR1_G = data & 0x01;
}

static void Set7Seg2(uint8_t data) {
    CHAR2_A = data & 0x01;
    data >>= 1;
    CHAR2_B = data & 0x01;
    data >>= 1;
    CHAR2_C = data & 0x01;
    data >>= 1;
    CHAR2_D = data & 0x01;
    data >>= 1;
    CHAR2_E = data & 0x01;
    data >>= 1;
    CHAR2_F = data & 0x01;
    data >>= 1;
    CHAR2_G = data & 0x01;
}

static void Set7Seg3(uint8_t data) {
    CHAR3_A = data & 0x01;
    data >>= 1;
    CHAR3_B = data & 0x01;
    data >>= 1;
    CHAR3_C = data & 0x01;
    data >>= 1;
    CHAR3_D = data & 0x01;
    data >>= 1;
    CHAR3_E = data & 0x01;
    data >>= 1;
    CHAR3_F = data & 0x01;
    data >>= 1;
    CHAR3_G = data & 0x01;
}

static void Set7Seg4(uint8_t data) {
    CHAR4_A = data & 0x01;
    data >>= 1;
    CHAR4_B = data & 0x01;
    data >>= 1;
    CHAR4_C = data & 0x01;
    data >>= 1;
    CHAR4_D = data & 0x01;
    data >>= 1;
    CHAR4_E = data & 0x01;
    data >>= 1;
    CHAR4_F = data & 0x01;
    data >>= 1;
    CHAR4_G = data & 0x01;
}

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

static void Set16Seg5(uint16_t data) {
    CHAR5_A = data & 0x01;
    data >>= 1;
    CHAR5_B = data & 0x01;
    data >>= 1;
    CHAR5_C = data & 0x01;
    data >>= 1;
    CHAR5_D = data & 0x01;
    data >>= 1;
    CHAR5_E = data & 0x01;
    data >>= 1;
    CHAR5_F = data & 0x01;
    data >>= 1;
    CHAR5_G = data & 0x01;
    data >>= 1;
    CHAR5_H = data & 0x01;
    data >>= 1;
    CHAR5_I = data & 0x01;
    data >>= 1;
    CHAR5_J = data & 0x01;
    data >>= 1;
    CHAR5_K = data & 0x01;
    data >>= 1;
    CHAR5_L = data & 0x01;
    data >>= 1;
    CHAR5_M = data & 0x01;
    data >>= 1;
    CHAR5_N = data & 0x01;
    data >>= 1;
    CHAR5_O = data & 0x01;
    data >>= 1;
    CHAR5_P = data & 0x01;
}

/**********************************
 *  Bit mapping for 7-seg character
 **********************************
 *            A
 *          -----
 *         |     |
 *       F |  G  | B
 *          -----
 *         |     | 
 *       E |  D  | C
 *          -----
 **********************************/
static void Set7Seg1_Alternate(uint8_t data) {
    CHAR1_A_SDATA = data & 0x01;
    data >>= 1;
    CHAR1_B_SDATA = data & 0x01;
    data >>= 1;
    CHAR1_C_SDATA = data & 0x01;
    data >>= 1;
    CHAR1_D_SDATA = data & 0x01;
    data >>= 1;
    CHAR1_E_SDATA = data & 0x01;
    data >>= 1;
    CHAR1_F_SDATA = data & 0x01;
    data >>= 1;
    CHAR1_G_SDATA = data & 0x01;
}

static void Set7Seg2_Alternate(uint8_t data) {
    CHAR2_A_SDATA = data & 0x01;
    data >>= 1;
    CHAR2_B_SDATA = data & 0x01;
    data >>= 1;
    CHAR2_C_SDATA = data & 0x01;
    data >>= 1;
    CHAR2_D_SDATA = data & 0x01;
    data >>= 1;
    CHAR2_E_SDATA = data & 0x01;
    data >>= 1;
    CHAR2_F_SDATA = data & 0x01;
    data >>= 1;
    CHAR2_G_SDATA = data & 0x01;
}

static void Set7Seg3_Alternate(uint8_t data) {
    CHAR3_A_SDATA = data & 0x01;
    data >>= 1;
    CHAR3_B_SDATA = data & 0x01;
    data >>= 1;
    CHAR3_C_SDATA = data & 0x01;
    data >>= 1;
    CHAR3_D_SDATA = data & 0x01;
    data >>= 1;
    CHAR3_E_SDATA = data & 0x01;
    data >>= 1;
    CHAR3_F_SDATA = data & 0x01;
    data >>= 1;
    CHAR3_G_SDATA = data & 0x01;
}

static void Set7Seg4_Alternate(uint8_t data) {
    CHAR4_A_SDATA = data & 0x01;
    data >>= 1;
    CHAR4_B_SDATA = data & 0x01;
    data >>= 1;
    CHAR4_C_SDATA = data & 0x01;
    data >>= 1;
    CHAR4_D_SDATA = data & 0x01;
    data >>= 1;
    CHAR4_E_SDATA = data & 0x01;
    data >>= 1;
    CHAR4_F_SDATA = data & 0x01;
    data >>= 1;
    CHAR4_G_SDATA = data & 0x01;
}

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

static void Set16Seg5_Alternate(uint16_t data) {
    CHAR5_A_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_B_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_C_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_D_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_E_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_F_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_G_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_H_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_I_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_J_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_K_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_L_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_M_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_N_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_O_SDATA = data & 0x01;
    data >>= 1;
    CHAR5_P_SDATA = data & 0x01;
}
