#include <REGX52.H>

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
	点亮了第一个LED灯
	点亮了第一、三、五个LED灯
*/

void main(void)
{
	P1=0xFE; 
	// 0xFE->1111 1110
	// 0X55->0101 0101
	
	while(1)
	{
		;
	} // while()结束
}