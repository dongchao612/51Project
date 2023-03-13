#include <REGX52.h>
#include <intrins.h>

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