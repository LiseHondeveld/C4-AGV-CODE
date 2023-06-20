#include <avr/io.h>
#define afstandmuur 50
#define margemeer 55
#define margeminder 45
#define afstandmuurmeer 60
#define afstandmuurminder 40

int rijden(int tv, int ta)    //tv = TOFvoorwaarde
{                             //ta = TOFachterwaarde
    if(tv > margemeer && ta > margemeer){
        //motor langzaam rechts
        DirectieMotorL = 0
        DirectieMotorR = 1

    }
    else if(tv < margeminder, ta < margeminder){
        //motor langzaam links
    }



    else if(tv == ta){
        //motor
    }
    else if(tv > ta){
        if(tv >= afstandmuurmeer){
            //motorheel veel rechts
        }
        else{
            //motor klein beetje rechts
        }
    }
    else if(tv < ta){
        if(tv <= afstandmuurminder){
            //motor veel links
        }
        else {
            //motor beetje links
        }
    }
}

