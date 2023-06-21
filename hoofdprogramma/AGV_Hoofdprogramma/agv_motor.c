//code voor motoraansturing
#include <avr/io.h>
#include <avr/interrupt.h>

int DirectieMotorL = 0;
int DirectieMotorR = 0;
int MotorTrackingPositieL = 0;
int MotorTrackingPositieR = 0;

void agv_motor_init()
{
    //timer 4 instellen op elke ms
    cli();
    TCCR4A = 0;
    TCCR4B = 0;
    TCNT4 = 6;
    TCCR4A |= (1 << WGM01);
    TCCR4B |= (1 << CS41) | (1 << CS40);//prescaler 64
    TIMSK4 |= (1 << TOIE4);
    sei();
}

int time_current_ms(int update){//0 = return, 1 = time++
    static unsigned long long int time_ms = 0;
    if (update == 1){
        time_ms++;
    }
    return(time_ms);
}

ISR(TIMER4_OVF_vect){
    //1ms timer code:
    TCNT4 = 6;
    time_current_ms(1);
    //1ms motor code:
    static int motorpositieL = 0;//int aangemaakt om de positie van de linker motor te kunnen aansturen.
    motorpositieL = motorpositieL + DirectieMotorL;
    MotorTrackingPositieL = MotorTrackingPositieL + DirectieMotorL;
    static int motorpositieR = 0;//int aangemaakt om de positie van de linker motor te kunnen aansturen.
    motorpositieR = motorpositieR + DirectieMotorR;
    MotorTrackingPositieR = MotorTrackingPositieR + DirectieMotorR;

    if(motorpositieL == -1)
    {
        motorpositieL = 7;
    }
    else if(motorpositieL == 8)
    {
        motorpositieL = 0;
    }
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
}

int PredefinedBocht(int start)
{
    static int BochtState = 0;
    if(start == 1)
    {
        MotorTrackingPositieL = 0;
        MotorTrackingPositieR = 0;
        BochtState = 1;
        return(1);
    }

}
