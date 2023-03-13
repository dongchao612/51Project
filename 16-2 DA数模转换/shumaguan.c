#include <REGX52.H>
#include "Delay.h"
#include "shumaguan.h"
//共阴数码管段选表0-9
unsigned char code tabel[]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void showNum(int pos,int num)
{
	if((pos<1) && (pos>8) && (num<0) && (num>9))
	{
		P2_7=1;
		P0=0XFF; // 1111 1111	清空位选 
		P2_7=0;
		
		P2_6=1;
		P0=0x00;
		P2_6=0;
		return ;
	}
	
	P0=0XFF; // 1111 1111	清空位选 
	P2_7 = 1;
	P0 = ~(0x01<<(pos-1)); 
	P2_7 = 0;

	P0=0x00; // 0000 0000	清空段选 
	P2_6 = 1;
	P0 = tabel[num];
	P2_6 = 0;
	Delay(5);
}