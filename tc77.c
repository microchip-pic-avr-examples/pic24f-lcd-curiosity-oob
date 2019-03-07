#include <stdbool.h>
#include <stdint.h>

static bool running = false;

#define DEGREES_PER_BIT 0.0625

void TC77_Initialize(void)
{
    
}

void TC77_Shutdown(void)
{
    
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

double TC77_GetTemperatureCelsius(void)
{    
    if(running == false)
    {
        running = true;
    }
    
    return convert(0xE487);
}