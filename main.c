/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

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

#include <stddef.h>

#include "power.h"
#include "usb_operational_mode.h"
#include "battery_operational_mode.h"
#include "rtcc.h"
#include "io_pins.h"
#include "segmented_lcd.h"

static enum POWER_SOURCE current_source = POWER_SOURCE_UNKNOWN;
static const struct OPERATIONAL_MODE *operational_mode = NULL;

//------------------------------------------------------------------------------
//Functions
//------------------------------------------------------------------------------

static void SwitchOperatoinalMode(enum POWER_SOURCE new_source)
{
    if(operational_mode != NULL)
    {
        operational_mode->Deinitialize();
    }
    
    switch(new_source)
    {
        case POWER_SOURCE_USB:
            operational_mode = &usb_operational_mode;
            break;

        case POWER_SOURCE_BATTERY:
            operational_mode = &battery_operational_mode;
            break;
            
        default:
            break;
    }
    
    operational_mode->Initialize();
}

int main(void)
{
    enum POWER_SOURCE new_source;
    RTCC_DATETIME build_time;
    
    POWER_Initialize();
    IO_PINS_Initialize();
    SEG_LCD_Initialize();
    
    build_time.bcdFormat = false;
    RTCC_BuildTimeGet(&build_time);
    RTCC_Initialize(&build_time);
    
    new_source = POWER_GetSource();
    
    while(1)
    {
        if(new_source != current_source)
        {
            current_source = new_source;
            SwitchOperatoinalMode(new_source);
        }
        
        do
        {
            operational_mode->Tasks();
            new_source = POWER_GetSource();
            
        } while( current_source == new_source );
    }
    
    return 0;
}