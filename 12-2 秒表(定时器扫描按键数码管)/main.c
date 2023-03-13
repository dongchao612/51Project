#include <REGX52.h>
#include "Delay.h"
#include "shumaguan.h"
#include "Key.h"
#include "timer0.h"
#include "Delay.h"
/*

*/

void main()
{
	unsigned char KeyNum=0,tmp;
	Timer0_Init();
	
	while (1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			Set_Buffer(1,KeyNum);
			Set_Buffer(2,KeyNum);
			Set_Buffer(3,KeyNum);
		}
	}
}
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count1=0,T0Count2=1; // static静态
	
	TL0=0x66;
	TH0=0xFC;
	
	T0Count1++;
	if(T0Count1>=20)
	{
		T0Count1=0;
		Key_Loop(); 
	}
	
	T0Count2++;
	if(T0Count2>=2)
	{
		T0Count2=0;
		Shumaguan_Loop();
	}
}