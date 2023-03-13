#include <REGX52.h>
#include <intrins.h>

/*
sfr		特殊功能寄存器
	sfr P0      = 0x80;
sbit	特殊位声明
	sbit P1_0 = 0x90;
	sbit P1_0 = P^1;

*/

sbit RCK=P3^5;	//移位寄存器时钟
sbit SCK=P3^6;	//输出锁存器时钟
sbit SER=P3^4; 	//串行数据口

void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	SCK=0; //输出锁存器时钟
	// Byte= 11000110
	for(i=0;i<8;i++)
	{	
		RCK=0; //移位寄存器时钟
		if(Byte & 0x01)//发送1
			SER = 1;
		else		  //发送0
			SER = 0;
		RCK = 1;	//拉高移位寄存器时钟，数据移位
		Byte >>= 1;//数据右移                 // 移进去8位
	}
	SCK=1;
}
/**
  * @brief  LED点阵屏显示一列数据
  * @param  Column 要选择的列，范围：0~7，0在最左边
  * @param  Data 选择列显示的数据，高位在上，1为亮，0为灭
  * @retval 无
  */
void MatrixLED_ShowColumn(unsigned char Column, unsigned char Data)
{
	unsigned char i,LIE,HANG;
	SCK=0; 
	LIE=~(0x01<<Column);
	HANG=Data;
	
	for(i=0;i<8;i++)
	{	
		RCK=0; //移位寄存器时钟
		if(LIE & 0x01)//发送1
			SER = 1;
		else		  //发送0
			SER = 0;
		RCK = 1;	//拉高移位寄存器时钟，数据移位
		LIE >>= 1;//数据右移                 // 移进去8位
	}
	for(i=0;i<8;i++)
	{	
		RCK=0; //移位寄存器时钟
		if(HANG & 0x01)//发送1
			SER = 1;
		else		  //发送0
			SER = 0;
		RCK = 1;	//拉高移位寄存器时钟，数据移位
		HANG >>= 1;//数据右移                 // 移进去8位
	}
	SCK=1;
}
void main()
{
	// _74HC595_WriteByte(0xF0);
	// MatrixLED_ShowColumn(5,0xAA);
	while(1)
	{
		MatrixLED_ShowColumn(0,0x3C);
		MatrixLED_ShowColumn(1,0x42);
		MatrixLED_ShowColumn(2,0xA9);
		MatrixLED_ShowColumn(3,0x85);
		MatrixLED_ShowColumn(4,0x85);
		MatrixLED_ShowColumn(5,0xA9);
		MatrixLED_ShowColumn(6,0x42);
		MatrixLED_ShowColumn(7,0x3C);

	}
}

