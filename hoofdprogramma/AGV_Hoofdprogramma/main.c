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

    //test
    //esmeE WAS HIer niet
    //hallo, ik ben jarig
    //Bassie zit naast me.
    //Sander naast mij...

    while(1)
    {
        boomdetectie();
        DirectieMotorL = 1;
        DirectieMotorR = 1;
        obstakeldetectie();
        if (PORTF && (1<<PF0))
        {
            TIMSK4 &= ~(1<<TOIE4);
        }
        else
        {
            TIMSK4 |= (1<<TOIE4);
        }
    }

}
