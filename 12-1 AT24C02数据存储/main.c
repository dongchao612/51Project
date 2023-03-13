#include <REGX52.h>
#include "LCD1602.h"
#include "Delay.h"
#include "At24c02.h"
#include "Key.h"
/*
At24c02 E2PROM
	存储介质 	E2PROM
	通讯接口	I2C
	容量		256字节
	引脚
I2C总线
	两个通信线SCL SDA	同步 半双工 带数据应答
电路规范
	所有I2C设备的SCL连在一起，SDA连在一起
	要配置成开漏输出
起始条件
	SCL高电平期间 SDA从高电平切换到低电平 SCL拉低
终止条件
	SCL高电平期间 SDA从低电平切换到高电平
发送字节
	SCL低电平期间 主机将数据位依次放到SDA线上(高位在前) 然后拉高SCL 
	从机将在SCL高电平期间读取数据位 所以SCL高电平期间SDA不允许有数据变化
接收字节	
	SCL低电平期间 主机将数据位依次放到SDA线上(高位在前) 然后拉高SCL
	主机将在SCL高电平期间读取数据位 所以SCL高电平期间SDA不允许有数据变化	
发送应答
	在接收完一个字节后 主机在下一个时钟发送一位数据 数据0表示应答 数据1表示非应答
接收应答
	在发送完一个字节后 主机在下一个时钟发送一位数据 按断从机是否应答 数据0表示应答 数据1表示非应答
发送一帧数据
	起始条件 从机地址+W(0) 接收应答 发送字节1 接收应答 发送字节2 ... 接收应答 终止条件
	完成任务 向谁发什么
接收一帧数据
	起始条件 从机地址+R(1) 接收应答 接收字节1 发送应答 发送字节2 ... 发送非应答 终止条件
	完成任务 向谁收什么
发送、接收一帧数据
	起始条件 从机地址+W(0) 接收应答 发送字节1 接收应答 发送字节2 ... 接收应答 起始条件 从机地址+R(1) 接收应答 接收字节1 发送应答 发送字节2 ... 发送非应答 终止条件
	完成任务 向谁收什么
*/

void main()
{
//	unsigned char DATA=0;
//	LCD_Init();
//	LCD_ShowString(0,0,"hello");
//	At24c02_WriteByte(0,256);
//	Delay(10);
//	DATA=At24c02_ReadByte(0);
//	LCD_ShowNum(2,1,DATA,3);
	
	unsigned char KeyNum=0,num=0;
	LCD_Init();
	LCD_ShowNum(1,1,num,5);
	while (1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			num++;
			LCD_ShowNum(1,1,num,5);
		}
		if(KeyNum==2)
		{
			num--;
			LCD_ShowNum(1,1,num,5);
		}
		
		if(KeyNum==3)
		{
			At24c02_WriteByte(0,num%256);
			Delay(10);
			At24c02_WriteByte(1,num/256);
			Delay(10);
			LCD_ShowString(2,1,"write ok!");
			Delay(1000);
			LCD_ShowString(2,1,"         ");
		}
		if(KeyNum==4)
		{
			num=At24c02_ReadByte(0);
			num|=At24c02_ReadByte(1);
			LCD_ShowNum(1,1,num,5);
			LCD_ShowString(2,1,"read ok!");
			Delay(1000);
			LCD_ShowString(2,1,"         ");
		}
	}
}