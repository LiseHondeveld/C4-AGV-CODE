#include <avr/io.h>
#include <util/delay.h>
#define DEBOUNCE_PERIOD_MS 15

void init_knoppen (void){
    DDRL &= ~(1<<PL4);
    DDRL &= ~(1<<PL6);

    DDRL |= (1<<PL0); //leds
    DDRB |= (1<<PB2);
    DDRB |= (1<<PB0);
}

int stand1 (void){
    if(PINL &(1<<PL4)){
        _delay_ms(DEBOUNCE_PERIOD_MS);
        if(PINL &(1<<PL4)){
           return 1;
           }
    }
    return 0;
}

int stand2 (void){
    if(PINL &(1<<PL6)){
        _delay_ms(DEBOUNCE_PERIOD_MS);
        if(PINL &(1<<PL6)){
           return 1;
           }
    }
    return 0;
}

void led_auto_aan(void){
    PORTL |= (1<<PL0);
}

void led_auto_uit(void){
    PORTL &= ~(1<<PL0);
}

void led_idle_aan(void){
    PORTB |= (1<<PB2);
}

void led_idle_uit(void){
    PORTB &= ~(1<<PB2);
}

void led_volg_aan(void){
    PORTB |= (1<<PB0);
}

void led_volg_uit(void){
    PORTB &= ~(1<<PB0);
}
