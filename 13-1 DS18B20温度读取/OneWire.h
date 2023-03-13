#ifndef __ONEWIRE__H__
#define __ONEWIRE__H__

void Delay_us(unsigned int us);
unsigned char OneWire_Init(void);
void OneWire_SendBit(unsigned char Bit);
unsigned char OneWire_ReceiveBit(void);
void OneWire_SendByte(unsigned char Byte);
unsigned char OneWire_ReceiveByte(void);


#endif
