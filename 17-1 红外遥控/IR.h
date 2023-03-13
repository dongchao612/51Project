#ifndef __IR_H__
#define __IR_H__

#define IR_0			0x16
#define IR_1			0x0C
#define IR_2			0x18
#define IR_3			0x5E
#define IR_4			0x08
#define IR_5			0x1C
#define IR_6			0x5A
#define IR_7			0x42
#define IR_8			0x52
#define IR_9			0x4A

#define IR_VOL_MINUS	0x07
#define IR_VOL_ADD		0x15
#define IR_EQ			0x09

#define IR_PREVIOUS		0x44
#define IR_NEXT			0x40
#define IR_START_STOP	0x43

#define IR_CH_MINUS		0x45
#define IR_CH			0x46
#define IR_CH_ADD		0x47

void IR_Init(void);
unsigned char IR_GetDataFlag(void);
unsigned char IR_GetRepeatFlag(void);

unsigned char IR_GetAddress(void);
unsigned char IR_GetCommand(void);

#endif
