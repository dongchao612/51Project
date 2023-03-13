#include <REGX52.H>
#include <intrins.h>

/*
LED 本开发板低电平点亮

区分正负极
	长正短负 
	小负短正
	
TTL 
	5v	+
	0v	-
	
开发板 P1 
		高			低
p17 p16 p15 p14 p13 p12 p11 p10

延时函数 Delay500ms
	频率 		11.0592MHz
	定时长度 	500毫秒
	指令集		STC-Y1
	
结果
	LED1每隔500毫秒闪烁一次
*/

void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_(); // #include <intrins.h>
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main(void)
{
	while(1)
	{
		P1=0XFE;
		Delay500ms();
		P1=0xFF;
		Delay500ms();
	}  // while()结束
}