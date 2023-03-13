#include <REGX52.h>
#include "timer0.h"

/**
   * @brief 	定时器1初始化 1毫秒@11.0592MHz
   * @param 	无
   * @retval	无
   */
void Timer1_Init(void)		//1毫秒@11.0592MHz
{
	TMOD&=0x0F;		//设置定时器模式
	TMOD|=0x10;		//设置定时器模式

	TL1 = 0xA4;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	
	TF1=0;			//清除TF0标志
	TR1=1;			//定时器0开始计时
	

	ET1=1;
	EA=1;  			// 开总中断
	
	PT1=0;
}

/**
   * @brief 定时器中断函数模板
   * @param
   * @retval
   */
/*
void Timer1_Routine() interrupt 2
{
	static unsigned int T0Count=0; // static静态
	
	TL1=0x66;
	TH1=0xFC;
	
	T1Count++;
	
	if(T1Count>=1000)
	{
		T1Count=0;
		P1_0=~P1_0; 
	}	
}
*/