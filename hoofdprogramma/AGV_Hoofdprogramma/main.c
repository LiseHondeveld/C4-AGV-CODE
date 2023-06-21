/*
 */

#include <avr/io.h>
#include "agv_boomdetectie.h"
#include <util/delay.h>
#include "agv_ultrasoon.h"
#include "agv_buzzer.h"
#include "agv_motor.h"


int main(void)
{
   agv_buzzer_init();
   agv_ultrasoon_init();

   //agv_buzzer_aan();
   //_delay_ms(1000);
   //agv_buzzer_uit();
   //_delay_ms(1000);
   agv_motor_init();
   PredefinedBocht();
   //DirectieMotorL = -1;
   //DirectieMotorR = 1;
   while(1){

    //boomdetectie();
    obstakeldetectie();

   }

}
