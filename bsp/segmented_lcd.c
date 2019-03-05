#include "segmented_lcd.h"

#include <xc.h>
#include <stdio.h>
#include <string.h>

static void SEG_LCD_PrintChar(char c, uint8_t location);
static void Set7Seg1(uint8_t data);
static void Set7Seg2(uint8_t data);
static void Set7Seg3(uint8_t data);
static void Set7Seg4(uint8_t data);
static void Set16Seg5(uint16_t data);

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
#define SEG16_C 0b0000000011110011
#define SEG16_F 0b0000001111000011
#define SEG16_4 0b0000001110001100
#define SEG16_BLANK 0b0000000000000000

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

#define    CHAR2_A  LCDDATA16bits.S04C4
#define    CHAR2_B  LCDDATA17bits.S18C4
#define    CHAR2_C  LCDDATA25bits.S18C6
#define    CHAR2_D  LCDDATA28bits.S04C7
#define    CHAR2_E  LCDDATA24bits.S04C6
#define    CHAR2_F  LCDDATA20bits.S04C5
#define    CHAR2_G  LCDDATA21bits.S18C5

#define    CHAR3_A  LCDDATA17bits.S19C4
#define    CHAR3_B  LCDDATA17bits.S25C4
#define    CHAR3_C  LCDDATA25bits.S25C6
#define    CHAR3_D  LCDDATA29bits.S25C7
#define    CHAR3_E  LCDDATA25bits.S19C6
#define    CHAR3_F  LCDDATA21bits.S19C5
#define    CHAR3_G  LCDDATA21bits.S25C5

#define    CHAR4_A  LCDDATA1bits.S19C0
#define    CHAR4_B  LCDDATA1bits.S25C0
#define    CHAR4_C  LCDDATA9bits.S25C2
#define    CHAR4_D  LCDDATA13bits.S25C3
#define    CHAR4_E  LCDDATA9bits.S19C2
#define    CHAR4_F  LCDDATA5bits.S19C1
#define    CHAR4_G  LCDDATA5bits.S25C1

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

#define    X3_2   LCDSDATA1bits.S28C0
#define    COLON_2 LCDSDATA29bits.S19C7

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
    LCDREFbits.LCDCST = 2; // Contrast is 2/7ths of maximum
    LCDCONbits.LCDEN = 1; // enable LCD module

    LCDSE0 = 0b0000000000010000;
    LCDSE1 = 0b0001111000001100;
    LCDSE2 = 0b0000000000000000;
    LCDSE3 = 0b0000000000000000;

    X1 = 1;
}

static char print_buffer[10];

void SEG_LCD_PrintPot(uint16_t value) {
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
    COLON = 1;
    DP1 = 0;
    DP2 = 0;
    DP3 = 0;
    DP4 = 0;
    DP5 = 0;
    DP6 = 0;

    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%02i", hour);

    SEG_LCD_PrintChar(print_buffer[0], 1);
    SEG_LCD_PrintChar(print_buffer[1], 2);

    memset(print_buffer, ' ', sizeof (print_buffer));

    sprintf(print_buffer, "%02i", minute);

    SEG_LCD_PrintChar(print_buffer[0], 3);
    SEG_LCD_PrintChar(print_buffer[1], 4);
    Set16Seg5(SEG16_BLANK);
    
    _DMSEL = 0b10;
    _BLINKFCS = 0b100;
    COLON_2 = 1;
    _BLINKMODE = 0b01;
    _ELCDEN = 1;
}

void SEG_LCD_SetBatteryStatus(enum BATTERY_STATUS status) {
    switch (status) {
        case BATTERY_STATUS_FULL:
            X3 = 1;
            X4 = 1;
            X5 = 1;
            break;

        case BATTERY_STATUS_MEDIUM:
            X3 = 1;
            X4 = 1;
            X5 = 0;
            break;

        case BATTERY_STATUS_LOW:
            X3 = 1;
            X4 = 0;
            X5 = 0;
            break;

        case BATTERY_STATUS_CRITICAL:
            X3 = 1;
            X4 = 0;
            X5 = 0;
            X3_2 = 1;
            _BLINKMODE = 0b01;
            _ELCDEN = 1;
            break;
    }
}

void SEG_LCD_LowPowerModeEnable(bool enabled) {
    X6 = enabled;
}

void SEG_LCD_PrintTemperature(double temp) {
    unsigned int i;
    unsigned int character;

    COLON = 0;
    DP5 = 1;
    DP6 = 0;

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
}

void SEG_LCD_PrintPIC24(void) {
    COLON = 0;
    DP1 = 0;
    DP2 = 0;
    DP3 = 0;
    DP4 = 0;
    DP5 = 0;
    DP6 = 0;

    Set7Seg1(0b01110011);   //P
    Set7Seg2(0b00110000);   //I
    Set7Seg3(0b00111001);   //C
    Set7Seg4(0b01011011);   //2
    Set16Seg5(SEG16_4);     //4
}

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

static void SEG_LCD_PrintChar(char c, uint8_t location) {
    uint8_t data = 0x0;

    if ((c >= 0x30) && (c <= 0x39)) {
        data = ascii_7seg_numbers_convert[c - 0x30];
    }

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
