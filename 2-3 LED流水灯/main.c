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

结果
	LED流水灯 时间间隔为500毫秒
*/
void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
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
		P1=0XFE; // 1111 1110
		Delay500ms();
		P1=0XFD; // 1111 1101
		Delay500ms();
		P1=0XFB; // 1111 1011
		Delay500ms();
		P1=0XF7; // 1111 0111
		Delay500ms();
		P1=0XEF; // 1110 1111
		Delay500ms();
		P1=0XDF; // 1101 1111
		Delay500ms();
		P1=0XBF; // 1011 1111
		Delay500ms();
		P1=0X7F; // 0111 1111
		Delay500ms();
	}  // while()结束
}