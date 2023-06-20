#include <avr/io.h>

void agv_buzzer_init(void) //Functie voor de buzzer
{
    DDRL |= (1<<PL3); //Pin 46 configureren van de arduino
    TCCR5A = (0<<WGM51) | (1<<WGM50) | (1<<COM5A1); //Instellen fast PWM 8-bit
    TCCR5B |= (1<<CS52) | (0<<CS51) | (0<<CS50); //Prescaler 256
    TCCR5B |= (0<<WGM53) | (1<<WGM32); //Instellen fast PWM 8-bit
    OCR5A = 192; //Duty cycle (hier kan je de volume mee aanpassen)
}

void agv_buzzer_aan(void) //Functie buzzer aan
{
     TCCR5A |= (1<<COM5A1); //Buzzer aan
}

void agv_buzzer_uit(void) //Functie buzzer uit
{
    TCCR5A &= ~(1<<COM5A1); //Buzzer uit
}


