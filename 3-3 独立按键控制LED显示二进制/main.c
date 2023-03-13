#include <REGX52.H>
#include <intrins.h>

/*
矩阵按键 本开发板低电平按下

开发板
	s2-P30 s3-P31 s4-P32 s5-P33
结果
	按下按键s2 LED按照二进制依次闪烁
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
			
			// 默认上电 1111 1111
			// P1++;

			// P1--;  

			LedNum++;
			P1=~LedNum;
		}
	}  // while()结束
}	