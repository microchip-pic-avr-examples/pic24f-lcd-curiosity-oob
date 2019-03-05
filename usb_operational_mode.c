#include <stdio.h>

#include "leds.h"
#include "buttons.h"
#include "adc.h"
#include "leds_rgb.h"
#include "timer_1ms.h"
#include "mcc_generated_files/uart1.h"
#include "segmented_lcd.h"
#include "operational_mode.h"
#include "rtcc.h"

//------------------------------------------------------------------------------
//Application related definitions
//------------------------------------------------------------------------------
#define BUTTON_DEBOUCE_TIME_MS      20

typedef enum
{
    BUTTON_COLOR_RED = 0,
    BUTTON_COLOR_GREEN = 1,
    BUTTON_COLOR_BLUE = 2
} BUTTON_COLOR;

enum DISPLAY_MODE
{
    DISPLAY_POT,
    DISPLAY_TEMPERATURE,
    DISPLAY_TIME,
    DISPLAY_PIC24
};

//------------------------------------------------------------------------------
//Private prototypes
//------------------------------------------------------------------------------
static void ButtonDebounce(void);
static void UpdatePrintout(void);
static void Initialize(void);
static void Tasks(void);

//------------------------------------------------------------------------------
//Global variables
//------------------------------------------------------------------------------
static volatile BUTTON_COLOR buttonColor = BUTTON_COLOR_RED;
static volatile bool updatePrintout = true;
static volatile enum DISPLAY_MODE display_mode = DISPLAY_PIC24;

static uint16_t potentiometer;
static uint16_t red = 64;
static uint16_t green = 32;
static uint16_t blue = 16;
static double temperature = 22.3;
static RTCC_DATETIME date_time;

const struct OPERATIONAL_MODE usb_operational_mode = {
    &Initialize,
    &Tasks
};

//------------------------------------------------------------------------------
//Functions
//------------------------------------------------------------------------------
static void Initialize(void)
{
    //Configure the pushbutton pins as digital inputs.
    BUTTON_Enable(BUTTON_S1);
    BUTTON_Enable(BUTTON_S2);

    //Configure and enable the I/O pins controlling the general purpose LEDs, and 
    //the PWM outputs controlling the RGB LED.
    LED_Enable(LED_LED1);
    LED_Enable(LED_LED2);
    LED_RGB_Enable(LED_RGB_LED3);
    
    //Enable and configure the ADC so it can sample the potentiometer.
    ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT);
    ADC_ChannelEnable(ADC_CHANNEL_POTENTIOMETER);
    
    //Turn on a timer, so to generate periodic interrupts.
    TIMER_SetConfiguration(TIMER_CONFIGURATION_1MS);
    
    //Register the ButtonDebounce() callback function, so it gets called periodically
    //when the timer interrupts occur (in this case at 1:1 rate, so ButtonDebounce()
    //executes once per 1ms).
    TIMER_RequestTick(&ButtonDebounce, 1);
    TIMER_RequestTick(&UpdatePrintout, 2);
    
    _RP16R = 3;  //RF3[RP16] = U1TX
    
    UART1_Initialize();
    
    printf("\033[2J");      //Clear screen
    printf("\033[0;0f");    //return cursor to 0,0
    printf("\033[?25l");    //disable cursor
    
    printf("------------------------------------------------------------------\r\n");
    printf("PIC24F LCD Curiosity Development Board Demo\r\n");
    printf("------------------------------------------------------------------\r\n");
    printf("S1 - controls LED1, changes active RGB color\r\n");
    printf("S2 - controls LED2, cycle what is on LCD display\r\n");
    printf("Potentiometer - controls active RGB color intensity\r\n");
    printf("\r\n");
    
    SEG_LCD_Initialize();
    SEG_LCD_LowPowerModeEnable(false);
}

void Tasks(void)
{
    //Fetch an ADC sample from the potentiometer
    potentiometer = ADC_Read12bit(ADC_CHANNEL_POTENTIOMETER);

    //Use the potentiometer ADC value to set the brightness of the currently
    //selected color channel on the RGB LED.  The "currently selected channel"
    //is manually selected by the user at runtime by pressing the pushbuttons.
    switch(buttonColor)
    {
        case BUTTON_COLOR_RED:
            red = (potentiometer>>2);
            break;

        case BUTTON_COLOR_GREEN:
            green = (potentiometer>>2);
            break;

        case BUTTON_COLOR_BLUE:
            blue = (potentiometer>>2);
            break;

        default:
            break;
    }

    //Update the PWM values controlling the intensity of the RGB LED channels.
    LED_RGB_Set(LED_RGB_LED3, red, green, blue);

    if(updatePrintout == true)
    {
        date_time.bcdFormat = false;
        RTCC_TimeGet(&date_time);
        
        updatePrintout = false;
        printf("\033[8;0f");    //move cursor to row 8, column 0
        printf("Potentiometer: %i/4095    \r\n", potentiometer);
        printf("Current color (r,g,b): %i, %i, %i           \r\n", red, green, blue);
        printf("Active color: ");

        switch(buttonColor)
        {
            case BUTTON_COLOR_RED:
                printf("red      \r\n");
                break;

            case BUTTON_COLOR_GREEN:
                printf("green    \r\n");
                break;

            case BUTTON_COLOR_BLUE:
                printf("blue     \r\n");
                break;

            default:
                break;
        }

        printf("Temperature: %.1f C     \r\n", temperature);
        printf("Date/Time: %04i/%02i/%02i %02i:%02i:%02i", 2000+date_time.year, date_time.month, date_time.day, date_time.hour, date_time.minute, date_time.second);
        
        switch(display_mode)
        {
            case DISPLAY_PIC24:
                SEG_LCD_PrintPIC24();
                break;

            case DISPLAY_POT:
                SEG_LCD_PrintPot(potentiometer);
                break;

            case DISPLAY_TIME:
                SEG_LCD_PrintTime(date_time.hour, date_time.minute);
                break;

            case DISPLAY_TEMPERATURE:
                SEG_LCD_PrintTemperature(temperature);
                break;

            default:
                SEG_LCD_PrintPIC24();
                break;
        }
    
        SEG_LCD_SetBatteryStatus(BATTERY_STATUS_FULL);
    }
}


//Helper function that advances the currently selected RGB color channel that
//is to be adjusted next.  This function is called in response to user pushbutton
//press events.
static void ChangeColor(void)
{         
    switch(buttonColor)
    {
        case BUTTON_COLOR_RED:
            buttonColor = BUTTON_COLOR_GREEN;
            break;

        case BUTTON_COLOR_GREEN:
            buttonColor = BUTTON_COLOR_BLUE;
            break;

        case BUTTON_COLOR_BLUE:
            buttonColor = BUTTON_COLOR_RED;
            break;

        default:
            buttonColor = BUTTON_COLOR_RED;
            break;
    }
}

static void ChangeDisplayMode(void)
{
    switch(display_mode)
    {
        case DISPLAY_PIC24:
            display_mode = DISPLAY_POT;
            break;

        case DISPLAY_POT:
            display_mode = DISPLAY_TIME;
            break;

        case DISPLAY_TIME:
            display_mode = DISPLAY_TEMPERATURE;
            break;
            
        case DISPLAY_TEMPERATURE:
            display_mode = DISPLAY_PIC24;
            break;

        default:
            display_mode = DISPLAY_PIC24;
            break;
    }
}


//This callback function gets called periodically (1/1ms) by the timer interrupt event
//handler.  This function is used to periodically sample the pushbuttons and implement
//a debounce algorithm to reject spurious chatter that can occur during press events.
static void ButtonDebounce(void)
{
    static uint16_t debounceCounterS1 = 0;
    static uint16_t debounceCounterS2 = 0;
    
    //Sample the button S1 to see if it is currently pressed or not.
    if(BUTTON_IsPressed(BUTTON_S1))
    {
        //The button is currently pressed.  Turn on the general purpose LED.
        LED_On(LED_LED1);
        
        //Check if the debounce blanking interval has been satisfied.  If so,
        //advance the RGB color channel user control selector.
        if(debounceCounterS1 == 0)
        {
            ChangeColor();   
        }
        
        //Reset the debounce countdown timer, so a new color change operation
        //won't occur until the button is released and remains continuously released 
        //for at least BUTTON_DEBOUCE_TIME_MS.
        debounceCounterS1 = BUTTON_DEBOUCE_TIME_MS;
    }
    else
    {
        //The button is not currently pressed.  Turn off the LED.
        LED_Off(LED_LED1);  
        
        //Allow the debounce interval timer to count down, until it reaches 0.
        //Once it reaches 0, the button is effectively "re-armed".
        if(debounceCounterS1 != 0)
        {
            debounceCounterS1--;
        }
    }

    //Sample the button S2 to see if it is currently pressed or not.
    if(BUTTON_IsPressed(BUTTON_S2))
    {
        //The button is currently pressed.  Turn on the general purpose LED.
        LED_On(LED_LED2);
        
        //Check if the debounce blanking interval has been satisfied.  If so,
        //advance the RGB color channel user control selector.
        if(debounceCounterS2 == 0)
        {
            ChangeDisplayMode();   
        }
        
        //Reset the debounce countdown timer, so a new color change operation
        //won't occur until the button is released and remains continuously released 
        //for at least BUTTON_DEBOUCE_TIME_MS.
        debounceCounterS2 = BUTTON_DEBOUCE_TIME_MS;
    }
    else
    {
        //The button is not currently pressed.  Turn off the LED.
        LED_Off(LED_LED2); 
        
        //Allow the debounce interval timer to count down, until it reaches 0.
        //Once it reaches 0, the button is effectively "re-armed".
        if(debounceCounterS2 != 0)
        {
            debounceCounterS2--;
        }
    }    
}

static void UpdatePrintout(void)
{
    updatePrintout = true;
}