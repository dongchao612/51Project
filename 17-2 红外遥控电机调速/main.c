#include <REGX52.h>
#include "Delay.h"
#include "Key.h"
#include "shumaguan.h"
#include "moto.h"
#include "IR.h"

/*
直流电机
	永磁体	线圈	转换器
其他电机
	步进电机	舵机	无刷电机	空心杯电机
PWM 脉通宽度调制
	频率=1/Ts	占空比Ton/Ts	精度占空比变化步距 1% 2%...
	____--____--____
*/
unsigned char Speed=0,Command;


void main()
{
	Moto_Init();
	IR_Init();
	Moto_Set_Speed(0);
	while (1)
	{
		if(IR_GetDataFlag())
		{
			Command=IR_GetCommand();
			if(Command==IR_0)
			{
				Speed=0;
				Moto_Set_Speed(0);
			}
			if(Command==IR_1)
			{
				Speed=1;
				Moto_Set_Speed(25);
			}
			if(Command==IR_2)
			{
				Moto_Set_Speed(50);
				Speed=2;
			}
			if(Command==IR_3)
			{
				Moto_Set_Speed(75);
				Speed=3;
			}
			if(Command==IR_4)
			{
				Moto_Set_Speed(100);
				Speed=4;
			}	
			
		}
		showNum(1,Speed);
	}
}
