#include <avr/io.h>
#include <avr/delay.h>
#include "agv_ultrasoon.h"
int boomdetectie(void)
{
    if (agv_ultrasoon_boom_links =< 20)
    {
        MotorDirectieL = 0;
        MotorDirectieR = 0;// karretje niet rijden

        agv_buzzer_aan
        _delay_ms(1000)
        agv_buzzer_uit
        // buzzer aan voor 1 sec
    }
    if (agv_ultrasoon_boom_rechts =<20)
    {
        MotorDirectieL = 0;
        MotorDirectieR = 0;// karretje niet rijden

        agv_buzzer_aan // buzzer aan voor 1 sec
        _delay_ms(1000)
        agv_buzzer_uit
    }
}

int obstakeldetectie(void)
{
    if (agv_ultrasoon_voor_links =< 20) || (agv_ultrasoon_voor_rechts =< 20) || (agv_ultrasoon_voor_midden =< 20)
    {
        TIMSK4 &= ~(1<<TOIE4);
    }
    else
    {
        TIMSK4 |= (1<<TOIE4);
    }
}
