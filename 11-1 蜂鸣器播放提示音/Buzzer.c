#include <REGX52.h>
#include "buzzer.h"
#include <intrins.h>
sbit Buzzer_IO=P2^3;

void Buzzer_Delay500us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}


void Buzzer_Time(unsigned int ms)
{
	unsigned int i=0;
	for(i=0;i<ms*2;i++)
	{
		Buzzer_IO=!Buzzer_IO;
		Buzzer_Delay500us();
	}
}