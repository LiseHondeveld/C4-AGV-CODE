#include <avr/io.h>
#include <avr/delay.h>
#include "agv_ultrasoon.h"

int volgmodus(void)
{
    else if (agv_ultrasoon_voor_links =< 20)
    {
        MotorDirectieL = 0;
        MotorDirectieR = 1;

    }
    else if (agv_ultrasoon_voor_rechts =<20)
    {
        MotorDirectieL = 1;
        MotorDirectieR = 0;

    }
    else if (agv_ultrasoon_voor_midden =<20)
    {
        MotorDirectieL = 1;
        MotorDirectieR = 1;
    }
    else
    {
        MotorDirectieL = 0;
        MotorDirectieR = 0;
    }
}
