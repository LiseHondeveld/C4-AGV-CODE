/*
 */

#include <avr/io.h>
#include "agv_boomdetectie.h"
#include <util/delay.h>
#include "agv_ultrasoon.h"
#include "agv_buzzer.h"
#include "agv_motor.h"
//#include "agv_schakelaar.h"


int main(void)
{
    agv_buzzer_init();
    agv_ultrasoon_init();
    agv_motor_init();
    DirectieMotorL = 1;
    DirectieMotorR = 1;
    //PredefinedBocht();

    while(1)
    {
        boomdetectie();
        DirectieMotorL = 1;
        DirectieMotorR = 1;
        obstakeldetectie();
    }

}
