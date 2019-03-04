#ifndef POWER_H
#define	POWER_H

enum POWER_SOURCE
{
    POWER_SOURCE_UNKNOWN = -1,
    POWER_SOURCE_USB = 0,
    POWER_SOURCE_BATTERY
};

enum POWER_SOURCE POWER_GetSource(void);
double POWER_GetVddVoltage(void);

#endif	/* POWER_H */

