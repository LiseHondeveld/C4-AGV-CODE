/*#include "general_i2c.h"
#include "avr/io.h"
uint8_t InitRGB(uint8_t addr, uint8_t data1, uint8_t data2, uint8_t data3)
{
    uint8_t RW = 1;
    TWIStart();
    if (TWIGetStatus() != 0x08)
        return ERROR;
    //select devise and send A2 A1 A0 address bits
    TWIWrite((addr | RW));
    if (TWIGetStatus() != 0x18)
        return ERROR;
    //send screen
    TWIWrite(data1);
    if (TWIGetStatus() != 0x28)
        return ERROR;
    //write byte to eeprom
    TWIWrite(data2);
    if (TWIGetStatus() != 0x28)
        return ERROR;
    TWIWrite(data3);
    if (TWIGetStatus() != 0x28)
        return ERROR;
    TWIStop();
    return SUCCESS;
}

uint8_t SetRGB(uint8_t addr, uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4)
{
    uint8_t RW = 1;
    TWIStart();
    if (TWIGetStatus() != 0x08)
        return ERROR;
    //select devise and send A2 A1 A0 address bits
    TWIWrite((uint8_t)(addr | RW));
    if (TWIGetStatus() != 0x18)
        return ERROR;
    //send screen
    TWIWrite(data1);
    if (TWIGetStatus() != 0x28)
        return ERROR;
    //write byte to eeprom
    TWIWrite(data2);
    if (TWIGetStatus() != 0x28)
        return ERROR;
    TWIWrite(data3);
    if (TWIGetStatus() != 0x28)
        return ERROR;
    TWIWrite(data4);
    if (TWIGetStatus() != 0x28)
        return ERROR;
    TWIStop();
    return SUCCESS;
}
*/
