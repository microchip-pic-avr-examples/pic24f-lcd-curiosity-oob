#include <stdbool.h>
#include <stdint.h>
#include <xc.h>

#include "mcc_generated_files/spi1_types.h"
#include "mcc_generated_files/spi1_driver.h"

static bool running = false;

#define DEGREES_PER_BIT 0.0625

#define CHIP_SELECT_PIN     _RB11
#define CHIP_SELECT_TRIS    _TRISB11

#define CHIP_ENABLE 0
#define CHIP_DISABLE 1

#define INPUT 1
#define OUTPUT 0

void TC77_Initialize(void)
{

}

void TC77_Shutdown(void)
{
    while(spi1_open(SPI1_DEFAULT) == false)
    {
    }
    
    CHIP_SELECT_PIN = CHIP_ENABLE;
    (void)spi1_exchangeByte(0x00);
    (void)spi1_exchangeByte(0x00);
    (void)spi1_exchangeByte(0xFF);    
    (void)spi1_exchangeByte(0xFF);    //Shutdown = 0xFF in control byte
    CHIP_SELECT_PIN = CHIP_DISABLE;   
    
    spi1_close();
}

inline static bool isNegative(uint16_t data)
{
    return ((data & 0x8000) == 0x8000);
}

inline static uint16_t twosCompliment(uint16_t data)
{
    return (data ^ 0xFFFF);
}

static double convert(uint16_t data)
{        
    if( isNegative(data) )
    {
        data ^= 0xFFFF;       
        data >>= 3;
        data += 1;
        
        return -1 * (DEGREES_PER_BIT * (double)data);
    }
    else
    {
        data >>= 3;
        
        return (DEGREES_PER_BIT * (double)data);
    }
}

inline static bool IsValid(uint16_t data)
{
    return ((data & 0x04) == 0x04);
}

double TC77_GetTemperatureCelsius(void)
{    
    uint8_t byte1, byte2, byte3, byte4;
    uint16_t data;
    
    if(running == false)
    {
        running = true;
    }
    
    while(spi1_open(SPI1_DEFAULT) == false)
    {
    }
    
    do
    {
        CHIP_SELECT_PIN = CHIP_ENABLE;
        byte1 = spi1_exchangeByte(0x00);
        byte2 = spi1_exchangeByte(0x00);
        byte3 = spi1_exchangeByte(0x00);    
        byte4 = spi1_exchangeByte(0x00);
        CHIP_SELECT_PIN = CHIP_DISABLE;   
        
        data = byte1;
        data <<= 8;
        data |= byte2;

    } while ( IsValid(data) == false );
    
    spi1_close();
    
    return convert(data);
}