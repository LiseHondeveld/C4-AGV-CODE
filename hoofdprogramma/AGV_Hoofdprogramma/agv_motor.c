//code voor motoraansturing
#include <avr/io.h>

void Motor(int directie)//programma voor het aangeven van de directie.
{
    static int motorpositieL = 0;//int aangemaakt om de positie van de linker motor te kunnen aansturen.
    motorpositieL = motorpositieL + directie;
    static int motorpositieR = 0;//int aangemaakt om de positie van de linker motor te kunnen aansturen.
    motorpositieR = motorpositieR + directie;

    if(motorpositieL == -1)
    {
        motorpositieL = 7;
    }
    else if(motorpositieL == 8)
    {
        motorpositieL = 0;

    if(motorpositieR == -1)
    {
        motorpositieR = 7;
    }
    else if(motorpositieR == 8)
    {
        motorpositieR = 0;
    }

    switch(motorpositieL)
    {
    case 1:
        PORTC = 0b00000101;
        break;
    case 2:
        PORTA = 0b00000100;
        break;
    case 3:
        PORTA = 0b00010100;
        break;
    case 4:
        PORTA = 0b00010000;
        break;
    case 5:
        PORTA = 0b01010000;
        break;
    case 6:
        PORTA = 0b01000000;
        break;
    case 7:
        PORTA = 0b01000001;
        break;
    case 8:
        PORTA = 0b00000001;
        break;
    }
    switch(motorpositieR)
    {
    case 1:
        PORTC = 0b00001010;
        break;
    case 2:
        PORTA = 0b00000010;
        break;
    case 3:
        PORTA = 0b10000010;
        break;
    case 4:
        PORTA = 0b10000000;
        break;
    case 5:
        PORTA = 0b10100000;
        break;
    case 6:
        PORTA = 0b00100000;
        break;
    case 7:
        PORTA = 0b00101000;
        break;
    case 8:
        PORTA = 0b00001000;
        break;
    }

