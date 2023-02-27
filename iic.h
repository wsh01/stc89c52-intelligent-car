#ifndef __IIC_H
#define __IIC_H

#include <reg52.h>  //声明特殊功能寄存器

/*************Pin Define***************/
sbit SCL=P1^4;
sbit SDA=P1^3;

void IIC_Start();
void IIC_Stop();
void Write_IIC_Command(unsigned char IIC_Command);
void Write_IIC_Data(unsigned char IIC_Data);
void Write_IIC_Byte(unsigned char IIC_Byte);

#endif
