#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

/*
矩阵键盘密码锁
开发板 P3

*/
void main()
{
	unsigned char KeyNumber=0;
	unsigned int PassWord=0;
	unsigned int count=0;
	LCD_Init();
	LCD_ShowString(1,1,"PassWord:");
	LCD_ShowNum(2,1,0,4);
	while(1)
	{
		KeyNumber=MatrixKey();
		if(KeyNumber!=0)
		{
			if((KeyNumber<=9)|| (KeyNumber==10))//如果1-9 或者 10 被按下 输入密码
			{
				if(count<4) //输入次数小于4
				{
					PassWord=PassWord*10;  //密码左移
					PassWord=PassWord+(KeyNumber%10);	// 获取一位密码
					count++;//计次加一
				}
				LCD_ShowNum(2,1,PassWord,4); // 更新显示
			}
			
			if(KeyNumber==11) // 确认键
			{
				if(PassWord==2580)
				{
					LCD_ShowString(1,13,"OK ");
					PassWord=0; // 密码清零
					count=0; // 计次清零
					LCD_ShowNum(2,1,PassWord,4);
				}
				else
				{
					LCD_ShowString(1,13,"ERR");
					PassWord=0; // 密码清零
					count=0; // 计次清零
					LCD_ShowNum(2,1,PassWord,4);
				}
			}
			
			if(KeyNumber==12)// 取消键
			{
				PassWord=0; // 密码清零
				count=0; // 计次清零
			}
		}	
	}
}