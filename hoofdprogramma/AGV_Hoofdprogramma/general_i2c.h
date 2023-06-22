#ifndef GENERAL_I2C_H_INCLUDED
#define GENERAL_I2C_H_INCLUDED
#include <avr/io.h>
void TWIInit(void);
uint8_t i2c_write_addr8_register8_data8(uint8_t addr8,uint8_t register8, uint8_t data8);
uint8_t i2c_read_addr8_register8_pointer8(uint8_t addr8, uint8_t register8, uint8_t *pointer8);


#endif // GENERAL_I2C_H_INCLUDED
