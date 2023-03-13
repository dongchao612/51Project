#include <REGX52.h>
#include "timer0.h" 
#include "lcd1602.h"
#include "Delay.h"

unsigned char Sec=57,Min=59,Hour=23;

void main()
{
	LCD_Init();
	Timer0Init();
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowString(2,1,"  :  :  ");
	while (1)
	{
		LCD_ShowNum(2,1,Hour,2);	
		LCD_ShowNum(2,4,Min,2);
		LCD_ShowNum(2,7,Sec,2);
		
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count=0; // static静态
	
	TL0=0x66;
	TH0=0xFC;
	
	T0Count++;
	
	if(T0Count>=1000)
	{
		T0Count=0;
		Sec++;
		if(Sec>=60)
		{
			Sec=0;
			Min++;
			if(Min>=60)
			{
				Min=0;
				Hour++;
				if(Hour>=24)
				{
					Hour=0;
				}
			}
		}
	}	
}