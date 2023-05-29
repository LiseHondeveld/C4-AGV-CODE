/*
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRA |= 0b00001111;
    // Insert code
    int i;
    int n = 264;
    for(i = 0; i<n; i++)
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

return 0;
}
