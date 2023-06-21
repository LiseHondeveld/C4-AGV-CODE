#include "general_i2c.h"
#include <avr/io.h>

void TWIInit(void)
{
    //set SCL to 400kHz
    TWSR = 0x00;
    TWBR = 0x0C;
    //enable TWI
    TWCR = (1<<TWEN);
}

void TWIStart(void)
{
    TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while ((TWCR & (1<<TWINT)) == 0);
}

void TWIStop(void)
{
    TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void TWIWrite(uint8_t u8data)
{
    TWDR = u8data;
    TWCR = (1<<TWINT)|(1<<TWEN);
    while ((TWCR & (1<<TWINT)) == 0);
}

uint8_t TWIReadACK(void)
{
    TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
    while ((TWCR & (1<<TWINT)) == 0);
    return TWDR;
}

uint8_t TWIReadNACK(void)
{
    TWCR = (1<<TWINT)|(1<<TWEN);
    while ((TWCR & (1<<TWINT)) == 0);
    return TWDR;
}

uint8_t TWIGetStatus(void)
{
    uint8_t status;
    //mask status
    status = TWSR & 0xF8;
    return status;
}

uint8_t i2c_write_addr8_register8_data8(uint8_t addr8,uint8_t register8, uint8_t data8)
{
    TWIStart();
    if (TWIGetStatus() != 0x08)
        return 1;
    TWIWrite(addr8);
    if (TWIGetStatus() != 0x18)
        return 1;
    TWIWrite(register8);
    if (TWIGetStatus() != 0x28)
        return 1;
    TWIWRITE(data8);
    if (TWIGetStatus() != 0x28)
        return 1;
    TWIStop();
    return 0;
}

uint8_t i2c_read_addr8_register8_pointer8(uint8_t addr8, uint8_t register8, uint8_t *pointer8)
{
    TWIStart();
    if (TWIGetStatus() != 0x08)
        return ERROR;
    TWIWrite(addr8);
    if (TWIGetStatus() != 0x18)
        return 1;
    TWIWrite(register8);
    if (TWIGetStatus() != 0x28)
        return 1;
    TWIStart();
    if (TWIGetStatus() != 0x10)
        return 1;
    TWIWrite(addr8);
    if (TWIGetStatus() != 0x40)
        return 1;

}
