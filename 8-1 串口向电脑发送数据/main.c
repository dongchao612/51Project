#include <REGX52.h>
#include "Delay.h"
#include "UART.h"
/*
串口通信 互相通信 定时器1

硬件电路
	发送端TXD	接收端RXD	交叉连接
	
电平标准
	TTL		+5v-1		0v-0
	RS323	-3~-15v-1	+3~+15-0
	RS485	+2~+6-1		-2~-6-0
	
常见通信协议
	UART	TXD-RXD				全双工、异步	点对点通信
	IIC		SCL-SDA 			半双工、同步	可挂载多个设备	
	SPI 	SCLK-MOSI-MISO-CS	全双工、同步 	可挂载多个设备	
	1-Wire	DQ					半双工、异步	可挂载多个设备
	CAN
	USB
相关术语
	全双工	通信双方可以在同一时刻互相传输数据
	半双工	通信双方可以互相传输数据。但必须服用一条数据线
	单工	通信只能乙方发送到另一方，不能反向传输
	
	异步	通信双方各自约定通信速率
	同步	通信双方靠一条时钟线约定通信速率
	
	总线	连接各个设备的数据传输线路
	
单片机的UART	1个
工作模式
	模式0	同步移位寄存器
	模式1	8位uart，波特率可变(常用)
	模式2	9位uart，波特率固定
	模式2	9位uart，波特率可变
	
串口参数
	波特率	串口通信的速率
	检验位	用于数据校验
	停止位	用于数据帧间隔
SCON
	SM0 SM1   01
*/

unsigned char Sec=0;

void main()
{
	UART_Init();

	while (1)
	{
		UART_SendByte(Sec);
		Sec++;
	}
}