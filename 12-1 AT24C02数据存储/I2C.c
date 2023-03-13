#include <REGX52.H>
#include "I2C.h"

sbit IIC_SCL=P2^1;
sbit IIC_SDA=P2^0;

void I2CStart()
{
	IIC_SDA=1;
	IIC_SCL=1;
	
	IIC_SDA=0;
	IIC_SCL=0;
}
void I2CStop()
{
	IIC_SDA = 0;
	IIC_SCL = 1;
	IIC_SDA = 1;
}
void I2CSendByte(unsigned char DATA)
{
	unsigned char i=0;
	for(i=0;i<8;i++)
	{
		IIC_SDA=DATA&(0X80>>i);
		IIC_SCL=1;
		IIC_SCL=0;
	}
}
unsigned char I2CReceiveByte()
{
	unsigned char Byte=0,i=0;
	
	IIC_SDA=1;
	for(i=0;i<8;i++)
	{
		IIC_SCL=1;
		if(IIC_SDA==1)
		{
			Byte|=(0x80>>i);
		}
		IIC_SCL=0;
	}
	return Byte;
}

void I2CSendACK(bit AckBit)
{
	IIC_SDA=AckBit;
	IIC_SCL=1;
	IIC_SCL=0;
}
bit I2CReceiveACK()
{
	bit AckBit=0;
	IIC_SDA=1;
	IIC_SCL=1;
	AckBit=IIC_SDA;
	IIC_SCL=0;
	return AckBit;
}