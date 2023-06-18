/*
 */

#include <avr/io.h>
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

return 0;
}
