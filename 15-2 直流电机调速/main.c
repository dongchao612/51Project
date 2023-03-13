#include <REGX52.h>
#include "Delay.h"
#include "Key.h"
#include "shumaguan.h"
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
unsigned char Counter,Compare,KeyNum,Speed=1;

sbit Moto = P2^0;

void main()
{
	Timer0Init();
	Compare=25;
	while (1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			Speed++;
			if(Speed==5)
			{
				Speed=1;
			}
			if(Speed==1)
			{
				Compare=25;
			}
			if(Speed==2)
			{
				Compare=50;
			}
			if(Speed==3)
			{
				Compare=75;
			}
			if(Speed==4)
			{
				Compare=100;
			}
		}
		showNum(1,Speed);
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
		Moto=1;
	}
	else
	{
		Moto=0;
	}
}