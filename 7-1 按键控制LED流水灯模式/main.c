#include <REGX52.h>
#include "timer0.h"
#include "Key.h" 
#include <intrins.h>

/*
定时器 属于内部资源

定时器资源
	3个 T0、T1、T2
	
四种工作模式
	模式0 13位定时器/计数器
	模式1 16位定时器/计数器(常用)
	模式2 8位自动重装模式
	模式3 两个8位计数器
	
模式1
	【TH,TL】-> [0,65535] 溢出值标志位TF
	
时钟
	系统时钟 	晶振周期 11.0592MHz  f=1/T  1us 计数一次
	C/T 1-C	0-T(*)
	外部引脚	T0 Pin 外部引脚

中断资源
	外部中断0、定时器0中断、外部中断1、定时器1中断、串口中断、定时器2中断、外部中断2、外部中断3

中断优先级
	4个
	
中断号
	中断查询序号就是中断号
	
定时器和中断系统
	
定时器相关寄存器
	定时器/计数器0和1的相关寄存器
		TCON
		TMOD
		TL0
		TL1
		TH0
		TH1
	中断寄存器
		IE
		IP
*/
/*
定时器 T0
系统频率	11.0592MHz
定时器		定时器0
定时长度  	1毫秒
定时器模式	16位
定时器时钟	12T
*/


void Timer0_Init()
{
	// TMOD 工作模式寄存器
	// TMOD=0x01;  // 0000 0001 
	TMOD=TMOD&0xF0; // 低四位清零 高四位不变
	TMOD=TMOD|0x01;//  最低位置   高四位不变
	
	// TCON 控制寄存器
	TF0=0;  //清除TF0标志
	TR0=1;  //定时器0开始计时

	// 设置定时初值
	TH0=64535/256;
	TL0=64535%256;
	
	ET0=1;
	EA=1;  // 开总中断
	PT0=0;
}


unsigned char KeyNumber=0,LedMode=0;
void main()
{
	// Timer0_Init();
	Timer0Init();
	P1=0xFE;  // 0000 0001
	while (1)
	{
		KeyNumber=Key();
		if(KeyNumber!=0)
		{
			if(KeyNumber==1)
			{
				LedMode++;
				if(LedMode>=2)
				{
					LedMode=0;
				}
			}
		}
	}// while()结束
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count=0; // static静态
	
	TH0=64535/256;
	TL0=64535%256;
	
	T0Count++;
	
	if(T0Count>=1000)
	{
		T0Count=0;
		// P1_0=~P1_0; 
		if(LedMode==0)
		{
			P1=_crol_(P1,1); // 左移
		}
		if(LedMode==1)
		{
			P1=_cror_(P1,1);// 右移
		}
	}	
}