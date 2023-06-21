#include <avr/interrupt.h>
#include <avr/io.h>

volatile uint16_t agv_ultrasoon_boom_links = 0;
volatile uint16_t agv_ultrasoon_boom_rechts = 0;
volatile uint16_t agv_ultrasoon_voor_links = 0;
volatile uint16_t agv_ultrasoon_voor_midden = 0;
volatile uint16_t agv_ultrasoon_voor_rechts = 0;
volatile uint8_t agv_ultrasoon_current_sensor = 2;

void agv_ultrasoon_init()
{
    cli();
    DDRB = (1<<PB7) | (1<<PB6) | (1<<PB5);
    DDRA = 0b11111111;
    //PORTA = 0b11111111;
    //triger configuratie
    TCCR3A |= (1<<COM3A1) | (1<<WGM31);
    TCCR3B |= (1<<WGM33) | (1<<CS31) | (1<<WGM32);//wgm33 wgm32 wgm31
    ICR3 = 32768;
    OCR3A = 20;//10microsec
    OCR3B = 5000;// (10microsec + 480microsec+ marge) *2
    DDRE |= (1<<PE3);
    TIMSK3 |= (1<<ICIE3) | (1<<OCIE3B);
    //pin change interrupt:
    PCICR |= (1<<PCIE2);//enables pci 16 tot 23
    sei();
}

ISR(TIMER3_COMPB_vect)
{


    PORTB |= (1<<PB6);
    PORTB &= ~(1<<PB6);
    agv_ultrasoon_current_sensor = (agv_ultrasoon_current_sensor<<1);
    if (agv_ultrasoon_current_sensor == (1<<6))//0b00100000
    {
        agv_ultrasoon_current_sensor = 2;

    }
    PCMSK2 = agv_ultrasoon_current_sensor;
    //PORTA = agv_ultrasoon_current_sensor;
    PCIFR |= (1<<PCIF2);
    TIFR3 |= (1<<ICF3);
}

ISR(TIMER3_CAPT_vect)
{
    PORTB |= (1<<PB5);
    PORTB &= ~(1<<PB5);
    //zet max naar sensorwaarde
    PORTA &= ~agv_ultrasoon_current_sensor;
    if(agv_ultrasoon_current_sensor == 0b00000010)
    {
        agv_ultrasoon_boom_rechts = ICR3;
    }
    else if(agv_ultrasoon_current_sensor == 0b00000100)
    {
        agv_ultrasoon_boom_links = ICR3;
    }
    else if(agv_ultrasoon_current_sensor == 0b00001000)
    {
        agv_ultrasoon_voor_rechts = ICR3;
    }
    else if(agv_ultrasoon_current_sensor == 0b00010000)
    {
        agv_ultrasoon_voor_midden = ICR3;
    }
    else if(agv_ultrasoon_current_sensor == 0b00100000)
    {
        agv_ultrasoon_voor_links = ICR3;
    }
    PCIFR &= ~(1<<PCIF2);

}

ISR(PCINT2_vect)
{
    //PINB |= (1<<PB7);
    PORTB |= (1<<PB7);
    PORTB &= ~(1<<PB7);

    if(agv_ultrasoon_current_sensor == 0b00000010)
    {
        agv_ultrasoon_boom_links = (TCNT3 - 4454)/4*0.343;
        PORTA &= ~(0b00000001);
    }
    else if(agv_ultrasoon_current_sensor == 0b00000100)
    {
        agv_ultrasoon_boom_rechts = (TCNT3 - 4454)/4*0.343;
        PORTA &= ~(0b00000010);
    }
    else if(agv_ultrasoon_current_sensor == 0b00001000)
    {
        agv_ultrasoon_voor_links = (TCNT3 - 4454)/4*0.343;
        PORTA &= ~(0b0000100);
    }
    else if(agv_ultrasoon_current_sensor == 0b00010000)
    {
        agv_ultrasoon_voor_midden = (TCNT3 - 4454)/4*0.343;
        PORTA &= ~(0b00001000);
    }
    else if(agv_ultrasoon_current_sensor == 0b00100000)
    {
        agv_ultrasoon_voor_rechts = (TCNT3 - 4454)/4*0.343;
        PORTA &= ~(0b00010000);
    }
    //check welke sensor en schrijf timer3 waarde naar sensorwaarde
    TIFR3 &= ~(1<<ICF3);
    //zet timer3 overflow flag uit
    PCIFR &= ~(1<<PCIF2);
}
