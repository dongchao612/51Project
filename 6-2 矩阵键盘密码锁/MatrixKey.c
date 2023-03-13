#include <REGX52.H>
#include "MatrixKey.h"
#include "Delay.h"

// 开发板 P3
unsigned char MatrixKey()
{
	unsigned char KeyNumber=0 ;
	
	P3=0xFF;
	
	P3_4=0;
	if(P3_0==0){Delay(20);while(P3_0==0);Delay(20);KeyNumber=1;}
	if(P3_1==0){Delay(20);while(P3_1==0);Delay(20);KeyNumber=4;}
	if(P3_2==0){Delay(20);while(P3_2==0);Delay(20);KeyNumber=7;}
	if(P3_3==0){Delay(20);while(P3_3==0);Delay(20);KeyNumber=11;}
	
	P3_5=0;
	if(P3_0==0){Delay(20);while(P3_0==0);Delay(20);KeyNumber=2;}
	if(P3_1==0){Delay(20);while(P3_1==0);Delay(20);KeyNumber=5;}
	if(P3_2==0){Delay(20);while(P3_2==0);Delay(20);KeyNumber=8;}
	if(P3_3==0){Delay(20);while(P3_3==0);Delay(20);KeyNumber=10;}
	
	P3_6=0;
	if(P3_0==0){Delay(20);while(P3_0==0);Delay(20);KeyNumber=3;}
	if(P3_1==0){Delay(20);while(P3_1==0);Delay(20);KeyNumber=6;}
	if(P3_2==0){Delay(20);while(P3_2==0);Delay(20);KeyNumber=9;}
	if(P3_3==0){Delay(20);while(P3_3==0);Delay(20);KeyNumber=12;}
	
//	P3_7=0;
//	if(P3_0==0){Delay(20);while(P3_0==0);Delay(20);KeyNumber=1;}
//	if(P3_1==0){Delay(20);while(P3_1==0);Delay(20);KeyNumber=4;}
//	if(P3_2==0){Delay(20);while(P3_2==0);Delay(20);KeyNumber=7;}
//	if(P3_3==0){Delay(20);while(P3_3==0);Delay(20);KeyNumber=1;}
	
	return KeyNumber;
}

