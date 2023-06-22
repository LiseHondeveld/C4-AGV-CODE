/*
 */

#include <avr/io.h>
#include "agv_boomdetectie.h"
#include <util/delay.h>
#include "agv_ultrasoon.h"
#include "agv_buzzer.h"
#include "agv_motor.h"
#include "agv_schakelaar.h"


int main(void)
{
   agv_buzzer_init();
   agv_ultrasoon_init();
   agv_motor_init();
   DirectieMotorL = 1;
   DirectieMotorR = 1;
   //PredefinedBocht();

   while(1){

    if ((!stand1()) && (!stand2())){
        led_idle_aan();
        led_auto_uit();
        led_volg_uit();
    }

    if (stand1()){
        led_auto_aan();
        led_idle_uit();
        led_volg_uit();

        boomdetectie();
        DirectieMotorL = 1;
        DirectieMotorR = 1;
        obstakeldetectie();

    }
    if (stand2()){
        led_volg_aan();
        led_idle_uit();
        led_auto_uit();
    }

   }

}
