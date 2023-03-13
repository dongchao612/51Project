#include <REGX52.h>
#include "ds1302.h"
#include "LCD1602.h"

/*
DS1302

VCC2	主电源
VCC1	备用电池
GND		电源地
X1,X2	晶振
CE		芯片使能	
IO		芯片输入输出
SCLK	串行时钟

*/
unsigned char Second=0,Minute=0;
void main()
{
	unsigned char DS1302_Time[]={22,12,25,0,0,0,1};
	LCD_Init();
	LCD_ShowString(0,0,"RCT:");
	DS1302_Init();
	
	// DS1302_WriteByte(0x80,Data2BCD(55));
	
	LCD_ShowString(1,1,"  -  -  ");
	LCD_ShowString(2,1,"  :  :  ");
	DS1302_SetTime(DS1302_Time);
	while (1)
	{
#if 0
		Second=DS1302_ReadByte(0x81);
		Second=BCD2Data(Second);
		LCD_ShowNum(2,1,Second,3);
#endif
#if 0	
		Second=DS1302_ReadByte(0x81);
		Minute=DS1302_ReadByte(0x83);
		LCD_ShowNum(2,1,BCD2Data(Minute),2);	
		LCD_ShowNum(2,3,BCD2Data(Second),2);	
#endif
		DS1302_ReadTime(DS1302_Time);
		LCD_ShowNum(1,1,DS1302_Time[0],2);	
		LCD_ShowNum(1,4,DS1302_Time[1],2);	
		LCD_ShowNum(1,7,DS1302_Time[2],2);	
		LCD_ShowNum(2,1,DS1302_Time[3],2);	
		LCD_ShowNum(2,4,DS1302_Time[4],2);	
		LCD_ShowNum(2,7,DS1302_Time[5],2);	
		LCD_ShowNum(2,10,DS1302_Time[6],1);	
		
	}
}