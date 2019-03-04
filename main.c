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

#include "usb_operational_mode.h"

enum POWER_SOURCE
{
    UNKNOWN = -1,
    USB = 0,
    BATTERY
};

static enum POWER_SOURCE current_source = UNKNOWN;
static const struct OPERATIONAL_MODE *operational_mode = NULL;

//------------------------------------------------------------------------------
//Functions
//------------------------------------------------------------------------------

static enum POWER_SOURCE GetCurrentPowerSource(void){
    if(PORTBbits.RB2 == 1)
    {
        return USB;
    }
    
    return BATTERY;
}

static void SwitchOperatoinalMode(enum POWER_SOURCE new_source)
{
    switch(new_source)
    {
        case USB:
            operational_mode = &usb_operational_mode;
            break;

        case BATTERY:
            break;
            
        default:
            break;
    }
    
    operational_mode->Initialize();
}

int main(void)
{
    enum POWER_SOURCE new_source = GetCurrentPowerSource();
    
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
            new_source = GetCurrentPowerSource();
        } while( current_source == new_source );
    }
    
    return 0;
}