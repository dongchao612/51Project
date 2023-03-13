#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
/*
LCD 
开发板 P0
p07 p06 p05 p04 p03 p02 p01 p00

#define LCD_EN P3_4
#define LCD_RS P3_5
#define LCD_RW P3_6

sbit LCD_EN=P3^4;
sbit LCD_RS=P3^5;
sbit LCD_RW=P3^6;

sbit LCD_EN=0xB4;
sbit LCD_RS=0xB5;
sbit LCD_RW=0xB6;

*/
void main()
{
	int result=0;
	LCD_Init();

	LCD_ShowNum(1,1,result,3);
	while(1)
	{
		result++;
		Delay(1000);
		LCD_ShowNum(1,1,result,3);
	}
}