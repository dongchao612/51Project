#include <REGX52.H>
#include "ds18b20.h"
#include "LCD1602.h"
#include "Delay.h"
/*
DS18B20 传感器
测温范围 
	-55~+125
通信接口
	1-wire
64-BIT ROM 
	作为器件地址 用于总线寻址
SCRATCHPAD
	用于总线的数据交换
EEPROM
	用于保存保存温度触发阈值和配置参数
	SCRATCHPAD           	EEPROM
	Byte0	LSB
	Byte1	MSB
	Byte2	TH				TH
	Byte3	TL				TL
	Byte4	Configuration	Configuration
	Byte5
	Byte6
	Byte7
	Byte8	CRC校验
单总线
	一根通信线 DQ
	 异步、半双工
单总线的电路规范
	设备的DQ均要配置成开漏输出模式
	DQ需要上拉电阻 4.7k
	若此总线的踪迹采取寄生供电 则主机还应配备一个强上拉输出电路
时序结构
初始化
	主机将总线拉低至少480us 然后释放总线 等待15-60us后
	存在的从机会拉低总线60-240us响应主机 之后从机释放总线
发送一位
	主机将总线拉低60-120us 然后释放总线 表示发送0
	主机将总线拉低1-15us 然后释放总线 表示发送0
	从机在将总线拉低30us后读取电平 整个时间片应大于60us
接收一位
	主机将总线拉低1-15us 然后释放总线 并在拉低15us后读取电平(尽量贴近15us)
	读取为低电平则为接收0 读取为高电平则为接收1 整个时间片应大于60us
发送一个字节 B0 B1 B2 B3 B4 B5 B6 B7
接收一个字节 B0 B1 B2 B3 B4 B5 B6 B7

DS12820操作流程
	初始化		从机复位 主机判断从机是否响应
	ROM操作		ROM指令+本指令读写操作	
	功能操作	功能指令+本指令读写操作	
	
	ROM指令	指令功能			控制指令	指令功能
	33H		READ ROM			44H			Convert T
	55H		MATCH ROM			BEH			Read Scratchpad
	F0H		SERACH ROM			4EH			Write Scratchpad
	ECH		ALARM SERACH ROM	48H			Copy Scratchpad
	CCH		SKIP ROM			B8H			Recall E2
								B4H			Read Power Supply
数据帧
	温度变化
		初始化+跳过+开始温度变换
		S+SKIP ROM+Convert T
	温度读取
		初始化+跳过+读暂存器+连续的读操作
		S+SKIP ROM+Read Scratchpad+LSB+MSB+...
MSB+LSB
	B15 B14 B13 B12 B11 B10 B9 B8 B7 B6 B5 B4 B3 B2 B1 B0
	B0~B3 		小数位
	B4~B10 		整数位
	B11~B15		符号位
*/



void main(void)
{
	float T=0;
	DS18B20_ConvertT();		//上电先转换一次温度，防止第一次读数据错误
	Delay(1000);
	
	LCD_Init();
	
	LCD_ShowString(1,1,"Temperature:");
	
	while(1)
	{
		DS18B20_ConvertT();
		T=DS18B20_ReadT();
		if(T<0)
		{
			LCD_ShowChar(2,1,'-');
			T=-T;
		}
		else
		{
			LCD_ShowChar(2,1,'+');
		}
		LCD_ShowNum(2,2,T,3);
		LCD_ShowChar(2,5,'.');
		LCD_ShowNum(2,6,(unsigned long)(T*10000)%10000,4);
	} // while()结束
}