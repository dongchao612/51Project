#include <REGX52.h>
#include "Delay.h"
#include "LCD1602.h"
#include "XPT2046.h"
/*
AD 模数转换
	通常有多个输入通道 用多路选择开关至AD转换器
	
	AD/DA与单片机数据传输可使用并口、串口
DA 数模转换
运算放大器
	是具有很高放大倍数的放大电路单元
	内部集成了差分放大器 电压放大器 功率放大器
DA
	V0=(D7~D0)/256*Vref
AD
	(D7~D0)=(Vin/Vref)*256
	
分辨率
	对于5V电源系统来说 8位AD可将5V等分为256份 
	模拟量变化位0.01953125V 即电压分辨率
转换速度
	
XPT2046
	内涵12位分辨率 25KHz
XPT2046时序

*/
void main()
{
	unsigned int ADValue=0;
	LCD_Init();
	LCD_ShowString(1,1,"ADJ  NTC  GR");
	while (1)
	{
		ADValue=XPT2046_ReadAD(XPT2046_XP_8);		//读取AIN0，可调电阻
		LCD_ShowNum(2,1,ADValue,3);				//显示AIN0
		ADValue=XPT2046_ReadAD(XPT2046_YP_8);		//读取AIN1，热敏电阻
		LCD_ShowNum(2,6,ADValue,3);				//显示AIN1
		ADValue=XPT2046_ReadAD(XPT2046_VBAT_8);	//读取AIN2，光敏电阻
		LCD_ShowNum(2,11,ADValue,3);			//显示AIN2
	}
}