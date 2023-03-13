#include <REGX52.H>
#include "DS1302.h"

sbit DS1302_SLCK=P1^0;
sbit DS1302_IO=P1^1;
sbit DS1302_CE=P1^2;

#define DS1302_SECOND    0x80      // 都是写入的地址
#define DS1302_MINUTE    0x82
#define DS1302_HOUR      0x84
#define DS1302_DATE      0x86
#define DS1302_MONTH     0x88
#define DS1302_DAY       0x8A
#define DS1302_YEAR      0x8C
#define DS1302_WP        0x8E



void DS1302_Init(void)
{
	DS1302_CE=0;
	DS1302_SLCK=0;
}

void DS1302_WriteByte(unsigned char Command,Data)
{
	unsigned char i;
	DS1302_CE=1;
	
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command & (0x01<<i);    
		DS1302_SLCK=1;
		DS1302_SLCK=0;
	}
	for(i=0;i<8;i++)
	{
		DS1302_IO=Data & (0x01<<i);    
		DS1302_SLCK=1;
		DS1302_SLCK=0;
	}
	
	DS1302_CE=0;
}

unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i,Data=0x00;
	Command |=0x01; 
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command & (0x01<<i);    
		DS1302_SLCK=0;
		DS1302_SLCK=1;
	}
	for(i=0;i<8;i++)
	{
		DS1302_SLCK=1;
		DS1302_SLCK=0;
		if(DS1302_IO) {Data|=(0x01<<i);}
	}
	DS1302_CE=0;
	DS1302_IO=0;
	return Data;
}

//数据转BCD码
unsigned char Data2BCD(unsigned char Data)
{
	unsigned char Data1, Data2;
	Data1 = Data / 10;
	Data2 = Data % 10;
	Data2 = Data2 + Data1 * 16;
	return Data2;
}

//BCD码转换为数据
unsigned char BCD2Data(unsigned char Data)
{
	unsigned char Data1, Data2;
	Data1 = Data / 16;
	Data2 = Data % 16;
	Data2 = Data2 + Data1 * 10;
	return Data2;
}

void DS1302_SetTime(unsigned char DS1302_Time[])
{
	DS1302_WriteByte(DS1302_WP, 0x00);
	DS1302_WriteByte(DS1302_YEAR,   Data2BCD(DS1302_Time[0]));
	DS1302_WriteByte(DS1302_MONTH,  Data2BCD(DS1302_Time[1]));
	DS1302_WriteByte(DS1302_DATE,   Data2BCD(DS1302_Time[2]));
	DS1302_WriteByte(DS1302_HOUR,   Data2BCD(DS1302_Time[3]));
	DS1302_WriteByte(DS1302_MINUTE, Data2BCD(DS1302_Time[4]));
	DS1302_WriteByte(DS1302_SECOND, Data2BCD(DS1302_Time[5]));
	DS1302_WriteByte(DS1302_DAY,    Data2BCD(DS1302_Time[6]));
	DS1302_WriteByte(DS1302_WP, 0x80);
}

void DS1302_ReadTime(unsigned char DS1302_Time[])
{
	unsigned char Temp;
	Temp=DS1302_ReadByte(DS1302_YEAR);
	DS1302_Time[0] = BCD2Data(Temp);  
	Temp=DS1302_ReadByte(DS1302_MONTH);
	DS1302_Time[1] = BCD2Data(Temp);
	Temp=DS1302_ReadByte(DS1302_DATE);
	DS1302_Time[2] = BCD2Data(Temp);	
	Temp=DS1302_ReadByte(DS1302_HOUR);
	DS1302_Time[3] = BCD2Data(Temp);
	Temp=DS1302_ReadByte(DS1302_MINUTE);
	DS1302_Time[4] = BCD2Data(Temp);
	Temp=DS1302_ReadByte(DS1302_SECOND);
	DS1302_Time[5] = BCD2Data(Temp);
	Temp=DS1302_ReadByte(DS1302_DAY);
	DS1302_Time[6] = BCD2Data(Temp);  	
}

