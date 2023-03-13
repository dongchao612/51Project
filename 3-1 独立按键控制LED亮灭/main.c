#include <REGX52.H>

/*
矩阵按键 本开发板低电平按下

开发板
	s2-P30 s3-P31 s4-P32 s5-P33
结果
	s2按下LED1点亮 松开LED1熄灭
*/
void main()
{
	P1_0=1; // 熄灭
	
	while(1)
	{
		if(P3_0==0) // 如果s2被按下
		{
			P1_0=0; // 点亮
		}
		else
		{
			P1_0=1; // 熄灭
		}
	}  // while()结束
}	