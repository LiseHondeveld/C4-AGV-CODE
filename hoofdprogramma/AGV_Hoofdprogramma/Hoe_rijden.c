#include <avr/io.h>
#define afstandmuur 50
#define margemeer 55
#define margeminder 45

int rijden(int tv, int ta)    //tv = TOFvoorwaarde
{                             //ta = TOFachterwaarde
    if(tv > margemeer && ta > margemeer){
        //motor langzaam rechts
        if (MotorTrackingPositieL <4){
        MotorTrackingPositieL++;
        DirectieMotorL = 1;
        DirectieMotorR = 0;
        }
        else {
            DirectieMotorL = 1;
            DirectieMotorR = 1;
        }
    }
    if (!(tv > margemeer && ta > margemeer)){
        MotorTrackingPositieL = 0;
    }
    else if(tv < margeminder, ta < margeminder){
        //motor langzaam links
        if (MotorTrackingPositieR <4){
        MotorTrackingPositieR++;
        DirectieMotorL = 0;
        DirectieMotorR = 1;
        }
        else {
            DirectieMotorL = 1;
            DirectieMotorR = 1;
        }
    }
    if (!(tv < margeminder, ta < margeminder)){
        MotorTrackingPositieR = 0;
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
}

