#include <REGX52.H>
#include <intrins.h>

/*
矩阵按键 本开发板低电平按下

开发板
	s2-P30 s3-P31 s4-P32 s5-P33
结果
	按下按键s2 LED1点亮 再次按下LED1熄灭
*/

void Delay(unsigned int xms)		//@11.0592MHz
{
	while(xms)
	{
		unsigned char i, j;

		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}

void main()
{
	P1_0=1; // 熄灭
	
	while(1)
	{
		if(P3_0==0) // 如果s2被按下
		{
			Delay(30); // 按下消抖
			while(P3_0==0) //一直按下的情况
			{
				;
			} // 松手情况
			Delay(30); // 松手消抖
			
			// 一个按键周期结束
			P1_0=~P1_0;
		}
	}  // while()结束
}	