#include <avr/io.h>
#include "agv_motor.h"
#define afstandmuur 40
#define margemeer 45
#define margeminder 35
int firstL = 0;
int firstR = 0;

void rijden(int tv, int ta)    //tv = TOFvoorwaarde
{                             //ta = TOFachterwaarde
    if(ta > 80)
    {
        PredefinedBocht();
    }



    else if((tv > margemeer) && (ta > margemeer)){
        //motor langzaam rechts
        if (firstL == 0){
            MotorTrackingPositieL = 0;
            firstL = 1;
        }
        if (MotorTrackingPositieL <4){
        DirectieMotorL = 1;
        DirectieMotorR = 0;
        }
        else {
            DirectieMotorL = 1;
            DirectieMotorR = 1;
        }
    }

    else if(tv < margeminder && ta < margeminder){
        //motor langzaam links
        if (firstR == 0){
            MotorTrackingPositieR = 0;
            firstR = 1;
        }
        if (MotorTrackingPositieR <4){
        DirectieMotorL = 0;
        DirectieMotorR = 1;
        }
        else {
            DirectieMotorL = 1;
            DirectieMotorR = 1;
        }
    }

    else if(tv == ta){
        //rechtdoorrijden
        DirectieMotorL = 1;
        DirectieMotorR = 1;
    }
    else if(tv > ta){
        if(tv >= afstandmuur){
            //motorheel rechts
            DirectieMotorL = 1;
            DirectieMotorR = 0;
        }
    }
    else if(tv < ta){
        if(tv < afstandmuur){
            //motor veel links
            DirectieMotorL = 0;
            DirectieMotorR = 1;
        }
    }

    if (!(tv > margemeer && ta > margemeer)){
        MotorTrackingPositieL = 0;
        firstL = 0;
    }

    if (!(tv < margeminder && ta < margeminder)){
        MotorTrackingPositieR = 0;
        firstR = 0;
    }
}

void blind_rijden (void){
    DirectieMotorL = 1;
    DirectieMotorR = 1;
}

