#include <REGX52.h>
/*
直流电机
	永磁体	线圈	转换器
其他电机
	步进电机	舵机	无刷电机	空心杯电机
PWM 脉通宽度调制
	频率=1/Ts	占空比Ton/Ts	精度占空比变化步距 1% 2%...
	____--____--____
*/
sbit LED=P1^0;
void Delay(unsigned char t)
{
	while(t--);
}
#define PWM 100
void main()
{
	unsigned char Time,i;
	while (1)
	{
		for(Time=0;Time<PWM;Time++)
		{
			for(i=0;i<20;i++)
			{
				
				LED=0;
				Delay(Time);
				LED=1;
				Delay(PWM-Time);
			}
		}
		for(Time=PWM;Time>0;Time--)
		{
			for(i=0;i<20;i++)
			{	
				LED=0;
				Delay(Time);
				LED=1;
				Delay(PWM-Time);
			}
		}
	}
}