/*
 */

#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
    //int teller = 0;
    DDRL |= (1<<PL3);
    TCCR5A = (0<<WGM31) | (1<<WGM50) | (1<<COM5A1);
    TCCR5B |= (1<<CS52) | (0<<CS51) | (0<<CS50);//prescaler 64  (mischien 64)
    TCCR5B |= (0<<WGM53) | (1<<WGM32);
    OCR5A = 192;

    while(1)
    {
        TCCR5A &= ~(1<<COM5A1);
        _delay_ms(500);
        TCCR5A |= (1<<COM5A1);
        _delay_ms(500);
    }
}


