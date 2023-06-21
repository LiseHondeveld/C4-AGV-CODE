/*
 */

#include <avr/io.h>
#include "agv_boomdetectie.h"
#include "agv_motor.h"
#include <util/delay.h>

int main(void)
{
    agv_buzzer_init();
    agv_ultrasoon_init();
    // Insert code
    agv_buzzer_aan();
    _delay_ms(1000);
    agv_buzzer_uit();
    _delay_ms(1000);
    while(1){
        boomdetectie();
}

    return 0;
}
