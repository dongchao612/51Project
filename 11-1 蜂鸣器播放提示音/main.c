#include <REGX52.h>
#include "Delay.h"
#include "Key.h"
#include "timer0.h"
#include "shumaguan.h"
#include "buzzer.h"
/*
蜂鸣器(有源)  电信号 -> 声信号
分类
	有源蜂鸣器		内部自带震荡源
	无源蜂鸣器		内部不带震荡源 需要控制器提供脉冲才能发生
ULN
乐谱
	钢琴 相差8度 白黑半音 白白全音 # 升半音 b 降半音
		CDEFGAB cdefgab c1d1e1f1g1a1b1	c2d2e2f2g2a2b2
	A 220 a 440 a1 880  中间2^(1/12)分频
*/
unsigned char keyNum;

void main()
{
	while (1)
	{
		keyNum=Key();
		if(keyNum!=0)
		{
			Buzzer_Time(100);
			showNum(1,keyNum);
		}
	}
}