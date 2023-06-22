#include <avr/io.h>
#include <avr/delay.h>
#include "agv_ultrasoon.h"
#include "agv_motor.h"

void boomdetectie(void)
{
    if (agv_ultrasoon_boom_links <= 10)
    {
        static unsigned long long int tijdlaatsteboomlinks = 0;

        if (time_current_ms(0)- tijdlaatsteboomlinks > 2000)
        {
            static uint8_t boomteller = 0;
            DirectieMotorL = 0;
            DirectieMotorR = 0;// karretje niet rijden
            agv_buzzer_aan();
            _delay_ms(400);
            agv_buzzer_uit();
            _delay_ms(1000);
            boomteller = boomteller + 1;
            if(boomteller == 5)
            {
                boomteller = 0;
                PredefinedBocht();
            }
            tijdlaatsteboomlinks = time_current_ms(0);
            // buzzer aan voor 1 sec
        }

    }
    if (agv_ultrasoon_boom_rechts <=10)
    {
        static unsigned long long int tijdlaatsteboomrechts = 0;

        if(time_current_ms(0) - tijdlaatsteboomrechts > 2000)
        {

            DirectieMotorL = 0;
            DirectieMotorR = 0;// karretje niet rijden

            agv_buzzer_aan(); // buzzer aan voor 1 sec
            _delay_ms(400);
            agv_buzzer_uit();
            _delay_ms(1000);
            tijdlaatsteboomrechts = time_current_ms(0);
        }

    }
}

void obstakeldetectie(void)
{
    if ((agv_ultrasoon_voor_midden <= 7))
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
