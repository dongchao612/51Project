#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "timer0.h"
#include "IR.h"
/*
红外遥控
	有红外LED将调制后的信号发出 由专门的接收头进行解调输出
通信方式	
	单工 异步
红外LED波长
	940nm
通信协议
	NEC
基本发送与接收
	空闲状态	红外LED不亮 接收头输出高电平
	发送低电平	红外LED以30KHz频率闪烁发光 接收头输出低电平
	发送高电平	红外LED不亮 接收头输出高电平
NEC编码
	Start 	9ms低+4.5ms高
	DATA	地址码+地址码反码+命令+命令反码(低位在前 高位在后)
			560us低+560us高		0
			560us低+1690us高	1
	Repeat	9ms低+2.25ms高
		110ms
外部中断
	下降沿和低电平触发
*/
unsigned char Num;
unsigned char Address;
unsigned char Command;

void main()
{
	unsigned int Time=0;
	LCD_Init();
	IR_Init();
	
	LCD_ShowString(1,1,"ADDR  CMD  NUM");
	LCD_ShowString(2,1,"00    00   000");
	
	while(1)
	{
		if(IR_GetDataFlag() || IR_GetRepeatFlag())	//如果收到数据帧或者收到连发帧
		{
			Address=IR_GetAddress();		//获取遥控器地址码
			Command=IR_GetCommand();		//获取遥控器命令码
			
			LCD_ShowHexNum(2,1,Address,2);	//显示遥控器地址码
			LCD_ShowHexNum(2,7,Command,2);	//显示遥控器命令码
		}
		if(Command==IR_VOL_MINUS)		//如果遥控器VOL-按键按下
		{
			Num--;						//Num自减
		}
		if(Command==IR_VOL_ADD)			//如果遥控器VOL+按键按下
		{
			Num++;						//Num自增
		}
		LCD_ShowNum(2,12,Num,3);		//显示Num
	}
}