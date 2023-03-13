#include <REGX52.H>
#include "moto.h"
#include "timer1.h"

sbit Moto = P2^0;

unsigned char Counter,Compare;


void Moto_Init()
{
	Timer1_Init();
}
void Moto_Set_Speed(unsigned char Speed)
{
	Compare=Speed;
}
void Timer1_Routine() interrupt 3
{
	TL1 = 0xA4;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值

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