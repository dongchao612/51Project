#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

/*
矩阵键盘
开发板 P3

*/
void main()
{
	unsigned char KeyNumber=0;
	
	LCD_Init();

	while(1)
	{
		KeyNumber=MatrixKey();
		LCD_ShowNum(1,1,KeyNumber,2);
	}
}