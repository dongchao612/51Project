#ifndef __I2C__H__
#define __I2C__H__

void I2CStart();
void I2CStop();
void I2CSendByte(unsigned char DATA);
unsigned char I2CReceiveByte();
void I2CSendACK(bit AckBit);
bit I2CReceiveACK();
#endif
