#ifndef __DS1302__H__
#define __DS1302__H__

void DS1302_Init(void);
void DS1302_WriteByte(unsigned char Command,Data);
unsigned char DS1302_ReadByte(unsigned char Command);
unsigned char Data2BCD(unsigned char Data);
unsigned char BCD2Data(unsigned char Data);
void DS1302_SetTime(unsigned char DS1302_Time[]);
void DS1302_ReadTime(unsigned char DS1302_Time[]);

#endif
