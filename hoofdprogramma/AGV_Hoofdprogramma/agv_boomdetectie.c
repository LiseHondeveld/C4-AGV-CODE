#include <avr/io.h>
#include <avr/delay.h>
#include "agv_ultrasoon.h"
#include "agv_motor.h"

void boomdetectie(void)
{
    if (agv_ultrasoon_boom_links <= 10)
    {
        DirectieMotorL = 0;
        DirectieMotorR = 0;// karretje niet rijden

        agv_buzzer_aan();
        _delay_ms(400);
        agv_buzzer_uit();
        _delay_ms(1000);
        // buzzer aan voor 1 sec
    }
    if (agv_ultrasoon_boom_rechts <=10)
    {
        DirectieMotorL = 0;
        DirectieMotorR = 0;// karretje niet rijden

        agv_buzzer_aan(); // buzzer aan voor 1 sec
        _delay_ms(400);
        agv_buzzer_uit();
        _delay_ms(1000);
    }
}

void obstakeldetectie(void)
{
    if ((agv_ultrasoon_voor_midden <= 7) || (agv_ultrasoon_voor_rechts <= 7) || (agv_ultrasoon_voor_links <= 7))
    {
        TIMSK4 &= ~(1<<TOIE4);
        agv_buzzer_aan();
    }
    else
    {
        TIMSK4 |= (1<<TOIE4);
        agv_buzzer_uit();
    }
}
