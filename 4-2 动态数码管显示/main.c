#include <REGX52.H>
#include <intrins.h>

/*
数码管显示 共阴极 高电平有效

开发板 P0
8   7   6   5   4   3   2   1	    0 选中
p07 p06 p05 p04 p03 p02 p01 p00
p   g   f   e   d   c   b   a	    1 选中

位选 P2_7
	1	打开	
	0	锁存
段选 P2_6
	1	打开	
	0	锁存
*/

/*
0x3F,  //"0"
0x06,  //"1"
0x5B,  //"2"
0x4F,  //"3"
0x66,  //"4"
0x6D,  //"5"
0x7D,  //"6"
0x07,  //"7"
0x7F,  //"8"
0x6F,  //"9"
0x77,  //"A"
0x7C,  //"B"
0x39,  //"C"
0x5E,  //"D"
0x79,  //"E"
0x71,  //"F"
0x76,  //"H"
0x38,  //"L"
0x40,  //"-"
0x00,  //熄灭

*/
/*
	P2_7 = 1;//打开位选锁存器
	P0 = 0xFE; //1111 1110 选通第一位数码管
	P2_7 = 0;//锁存位选数据

	P2_6 = 1;//打开段选锁存器
	P0 = 0x3F;//0000 0110 显示“1”
	P2_6 = 0;//锁存段选数据
*/
//共阴数码管段选表0-9
unsigned char code tabel[]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void Delay(unsigned int xms)		//@11.0592MHz
{
	while(xms)
	{
		unsigned char i, j;

		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}

// pos 显示位置
// num 显示数字
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
}

void main()
{
	P0=0x00;
	
	while(1)
	{
		showNum(1,1);
		Delay(5);
		showNum(2,2);
		Delay(5);
		showNum(3,3);
		Delay(5);
	}// while()结束
}