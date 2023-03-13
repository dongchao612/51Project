#include <REGX52.h>
#include "lcd1602.h"
#include "Delay.h"
/*
LCD1602
显示容量 16*2个字符 每个字符为5*7点阵
引脚以及应用电路
	vss		地
	vdd		电源正极
	vo 		对比调节电压
	RS		数据/指令选择 1为数据 0为指令
	RW		读写操作 1为读 0为写
	E		使能 1为数据有效 下降沿执行命令
	D0-D7	数据输入输出
	A		背光灯电源正
	K		背光灯电源负
指令
	0x01	清屏
	0x02	复位
	0x06	数据读写操作后 光标自动加一 画面不动
	0x0c	显示开 光标关 闪烁关
	0x18	画面向左平移一个字符 但光标不变 移屏
	0x1c	画面向右平移一个字符 但光标不变 移屏
	0x38	八位数据接口 两行显示 5*7点阵
	
操作流程
	初始化 
		发送指令	0x38	八位数据接口两行显示 5*7点阵
		发送指令	0x0c	显示开 光标关 闪烁关
		发送指令	0x06	数据读写操作后 光标自动加一 画面不动
		发送指令	0x01	清屏
	显示数据
		发送指令	0x38|AC	设置光标位置
		发送数据
		发送数据
*/
void main()
{
	LCD_Init();
	LCD_ShowChar(1,1,0x41);
	LCD_ShowString(1,3,"hello");
	LCD_ShowNum(1,9,66,2);
	LCD_ShowSignedNum(1,12,-88,2);
	LCD_ShowHexNum(2,1,0xA5,2);
	LCD_ShowBinNum(2,4,0XA5,8);
	LCD_ShowChar(2,13,0xDF);
	LCD_ShowChar(2,14,'C');
	
	LCD_ShowString(1,16,"WELCOME TO CHINA!");
	while (1)
	{
		LCD_WriteCommand(0X18);
		Delay(3000);
	}
}