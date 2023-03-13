#include <REGX52.H>
#include "At24c02.h"
#include "I2C.h"

#define At24c02ADDR 0XA0   //AT24C02硬件地址

void At24c02_WriteByte(unsigned char WordAddress,unsigned char DATA)
{
	I2CStart();
	I2CSendByte(At24c02ADDR);
	I2CReceiveACK();

	I2CSendByte(WordAddress);
	I2CReceiveACK();

	I2CSendByte(DATA);
	I2CReceiveACK();
	
	I2CStop();
	
}
unsigned char At24c02_ReadByte(unsigned char WordAddress)
{
	unsigned char DATA=0;
	
	I2CStart();
	I2CSendByte(At24c02ADDR);
	I2CReceiveACK();

	I2CSendByte(WordAddress);
	I2CReceiveACK();
	
	I2CStart();
	I2CSendByte(At24c02ADDR|0x01);
	I2CReceiveACK();
	
	DATA = I2CReceiveByte();
	I2CSendACK(1);
	
	I2CStop();
	
	return DATA;
}