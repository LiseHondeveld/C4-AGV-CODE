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
    DDRA |= 0b10101010;
    DDRC |= 0b01010101;
    TCCR4A = 0;
    TCCR4B = 0;
    TCNT4 = 6;
    TCCR4A |= (1 << WGM41);
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
    motorpositieL = motorpositieL - DirectieMotorL;
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
        PORTC = 0b00000100;
        break;
    case 3:
        PORTC = 0b00010100;
        break;
    case 4:
        PORTC = 0b00010000;
        break;
    case 5:
        PORTC = 0b01010000;
        break;
    case 6:
        PORTC = 0b01000000;
        break;
    case 7:
        PORTC = 0b01000001;
        break;
    case 8:
        PORTC = 0b00000001;
        break;
    }
    switch(motorpositieR)
    {
    case 1:
        PORTA = 0b00001010;
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

void PredefinedBocht(void)
{
    MotorTrackingPositieL = 0;
    MotorTrackingPositieR = 0;
    while(MotorTrackingPositieL < 500*8)
    {
        DirectieMotorL = 1;
        DirectieMotorR = 1;
        obstakeldetectie();
    }
    MotorTrackingPositieL = 0;
    MotorTrackingPositieR = 0;
    while(MotorTrackingPositieL < 300*8)
    {
        DirectieMotorL = 1;
        DirectieMotorR = -1;
        obstakeldetectie();
    }
    MotorTrackingPositieL = 0;
    MotorTrackingPositieR = 0;
    while(MotorTrackingPositieL < 1750*8)
    {
        DirectieMotorL = 1;
        DirectieMotorR = 1;
        obstakeldetectie();
    }
    MotorTrackingPositieL = 0;
    MotorTrackingPositieR = 0;
    while(MotorTrackingPositieL < 300*8)
    {
        DirectieMotorL = 1;
        DirectieMotorR = -1;
        obstakeldetectie();
    }
        while(MotorTrackingPositieL < 500*8)
    {
        DirectieMotorL = 1;
        DirectieMotorR = 1;
        obstakeldetectie();
    }
    MotorTrackingPositieL = 0;
    MotorTrackingPositieR = 0;
    DirectieMotorL = 0;
    DirectieMotorR = 0;
}
/*    #include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRA |= 0b11111111;
    // Insert code
    int i;
    int r = 528;//2 rondjes wiel
    int b = 828;//1 rondje wiel
    int rb = 1356;//1 rondje wiel rechtdoor
    int bb = 1656;//1 rondje wiel bocht
    int rrb = 2181;// 1 rondje wiel rechtdoor
    _delay_ms(1008);
    for(i = 0; i<r; i++) //rechtdoor
    {
        _delay_ms(1);
        PORTA = 0b00110011;
        _delay_ms(1);
        PORTA = 0b00100001;
        _delay_ms(1);
        PORTA = 0b01101001;
        _delay_ms(1);
        PORTA = 0b01001000;
        _delay_ms(1);
        PORTA = 0b11001100;
        _delay_ms(1);
        PORTA = 0b10000100;
        _delay_ms(1);
        PORTA = 0b10010110;
        _delay_ms(1);
        PORTA = 0b00010010;
        _delay_ms(1);

    }
for(i = 528; i<b; i++) //linksom 1e bocht 264 stap
    {
        PORTA = 0b00110011;
        _delay_ms(1);
        PORTA = 0b00100010;
        _delay_ms(1);
        PORTA = 0b01100110;
        _delay_ms(1);
        PORTA = 0b01000100;
        _delay_ms(1);
        PORTA = 0b11001100;
        _delay_ms(1);
        PORTA = 0b10001000;
        _delay_ms(1);
        PORTA = 0b10011001;
        _delay_ms(1);
        PORTA = 0b00010001;
        _delay_ms(1);
    }
 for(i = 828; i<rb; i++) //rechtdoor
    {
        _delay_ms(1);
        PORTA = 0b00110011;
        _delay_ms(1);
        PORTA = 0b00100001;
        _delay_ms(1);
        PORTA = 0b01101001;
        _delay_ms(1);
        PORTA = 0b01001000;
        _delay_ms(1);
        PORTA = 0b11001100;
        _delay_ms(1);
        PORTA = 0b10000100;
        _delay_ms(1);
        PORTA = 0b10010110;
        _delay_ms(1);
        PORTA = 0b00010010;
        _delay_ms(1);
    }
for(i = 1356; i<bb; i++) //linksom 2e bocht 264 bocht
    {
        PORTA = 0b00110011;
        _delay_ms(1);
        PORTA = 0b00100010;
        _delay_ms(1);
        PORTA = 0b01100110;
        _delay_ms(1);
        PORTA = 0b01000100;
        _delay_ms(1);
        PORTA = 0b11001100;
        _delay_ms(1);
        PORTA = 0b10001000;
        _delay_ms(1);
        PORTA = 0b10011001;
        _delay_ms(1);
        PORTA = 0b00010001;
        _delay_ms(1);
    }
 for(i = 828; i<rb; i++) //rechtdoor
    {
        _delay_ms(1);
        PORTA = 0b00110011;
        _delay_ms(1);
        PORTA = 0b00100001;
        _delay_ms(1);
        PORTA = 0b01101001;
        _delay_ms(1);
        PORTA = 0b01001000;
        _delay_ms(1);
        PORTA = 0b11001100;
        _delay_ms(1);
        PORTA = 0b10000100;
        _delay_ms(1);
        PORTA = 0b10010110;
        _delay_ms(1);
        PORTA = 0b00010010;
        _delay_ms(1);
    }
return 0;
}

}
*/
