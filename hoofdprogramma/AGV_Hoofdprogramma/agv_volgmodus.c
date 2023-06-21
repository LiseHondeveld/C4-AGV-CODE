#include <avr/io.h>
#include <avr/delay.h>
#include "agv_ultrasoon.h"
#include "agv_motor.h"
int volgmodus(void)
{
    if (agv_ultrasoon_voor_links <= 20)
    {
        DirectieMotorL = 0;
        DirectieMotorR = 1;

    }
    else if (agv_ultrasoon_voor_rechts <= 20)
    {
        DirectieMotorL = 1;
        DirectieMotorR = 0;

    }
    else if (agv_ultrasoon_voor_midden <= 20)
    {
        DirectieMotorL = 1;
        DirectieMotorR = 1;
    }
    else
    {
        DirectieMotorL = 0;
        DirectieMotorR = 0;
    }
}
