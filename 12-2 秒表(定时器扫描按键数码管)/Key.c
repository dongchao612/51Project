#include <REGX52.h>
#include "Key.h"
#include "Delay.h"
unsigned char KeyNum=0;

unsigned char Key()
{
	unsigned char tmp;
	tmp=KeyNum;
	KeyNum=0;
	return tmp;
}
unsigned char Key_GetSatte()
{
	unsigned char KeyNumber=0;

	if(P3_0==0)
	{
		KeyNumber=1;
	}
	
	if(P3_1==0)
	{
		KeyNumber=2;
	}
	if(P3_2==0)
	{
		KeyNumber=3;
	}
	if(P3_3==0)
	{
		KeyNumber=4;
	}
	
	return KeyNumber;
	
}

void Key_Loop(void)
{

	static unsigned char NowState,LastState;
	LastState=NowState;
	NowState=Key_GetSatte();
	
	if(LastState==1 && NowState==0)
	{
		KeyNum=1;
	}
	if(LastState==2 && NowState==0)
	{
		KeyNum=2;
	}
	if(LastState==3 && NowState==0)
	{
		KeyNum=3;
	}
	if(LastState==4 && NowState==0)
	{
		KeyNum=4;
	}
}