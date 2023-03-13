#include <REGX52.H>
#include <intrins.h>

/*
矩阵按键 本开发板低电平按下

开发板
	s2-P30 s3-P31 s4-P32 s5-P33
结果
	按下s2按键后 LED依次左移闪烁
	按下s3按键后 LED依次右移闪烁
*/

void Delay(unsigned int xms)		//@11.0592MHz
{
	while(xms--)
	{
		unsigned char i, j;

		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

void main()
{	
	unsigned char LedNum=0;
	P1=~0x01;
	while(1)
	{
		// 左移
		if(P3_0==0) // 如果s2被按下
		{
			Delay(30); // 按下消抖
			while(P3_0==0) //一直按下的情况
			{
				;
			} // 松手情况
			Delay(30); // 松手消抖
			
			LedNum++;
			if(LedNum>=8)
			{
				LedNum=0;
			}
			P1=~(0x01<<LedNum);
		}
		
		// 右移
		if(P3_1==0) // 如果s2被按下
		{
			Delay(30); // 按下消抖
			while(P3_1==0) //一直按下的情况
			{
				;
			} // 松手情况
			Delay(30); // 松手消抖
			
			if(LedNum==0)
			{
				LedNum=7;
			}
			else
			{
				LedNum--;
			}
	
			P1=~(0x01<<LedNum);
		}
	} // while()结束
}	