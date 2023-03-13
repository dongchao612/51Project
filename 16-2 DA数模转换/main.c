#include <REGX52.h>
#include "Delay.h"
#include "timer0.h"
/*
直流电机
	永磁体	线圈	转换器
其他电机
	步进电机	舵机	无刷电机	空心杯电机
PWM 脉通宽度调制
	频率=1/Ts	占空比Ton/Ts	精度占空比变化步距 1% 2%...
	____--____--____
*/

sbit DA = P1^1;

unsigned char Counter,Compare;	//计数值和比较值，用于输出PWM

void main()
{
	unsigned char i;
	
	Timer0Init();
	Compare=25;
	while (1)
	{
		for(i=0;i<100;i++)
		{
			Compare=i;			//设置比较值，改变PWM占空比
			Delay(10);
		}
		for(i=100;i>0;i--)
		{
			Compare=i;			//设置比较值，改变PWM占空比
			Delay(10);
		}
		
	}
}
void Timer0_Routine() interrupt 1
{
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	
	
	Counter++;
//	if(Counter==100)
//		Counter=0;
	Counter%=100;
	
	if(Counter<Compare)
	{
		DA=1;
	}
	else
	{
		DA=0;
	}
}