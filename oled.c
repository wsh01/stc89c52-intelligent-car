#include "oled.h"
/*******************************************************************************
* 函 数 名         : OLED_Init()
* 函数功能		   : OLED初始化函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void OLED_Init()
{
	Write_IIC_Command(0xAE);//display off
	Write_IIC_Command(0x20);//Set Memory Addressing Mode	
	Write_IIC_Command(0x10);//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	Write_IIC_Command(0xb0);//Set Page Start Address for Page Addressing Mode,0-7
	Write_IIC_Command(0xc8);//Set COM Output Scan Direction
	Write_IIC_Command(0x00);//---set low column address
	Write_IIC_Command(0x10);//---set high column address
	Write_IIC_Command(0x40);//--set start line address
	Write_IIC_Command(0x81);//--set contrast control register
	Write_IIC_Command(0xff);//亮度调节 0x00~0xff
	Write_IIC_Command(0xa1);//--set segment re-map 0 to 127
	Write_IIC_Command(0xa6);//--set normal display
	Write_IIC_Command(0xa8);//--set multiplex ratio(1 to 64)
	Write_IIC_Command(0x3F);//
	Write_IIC_Command(0xa4);//0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	Write_IIC_Command(0xd3);//-set display offset
	Write_IIC_Command(0x00);//-not offset
	Write_IIC_Command(0xd5);//--set display clock divide ratio/oscillator frequency
	Write_IIC_Command(0xf0);//--set divide ratio
	Write_IIC_Command(0xd9);//--set pre-charge period
	Write_IIC_Command(0x22);//
	Write_IIC_Command(0xda);//--set com pins hardware configuration
	Write_IIC_Command(0x12);
	Write_IIC_Command(0xdb);//--set vcomh
	Write_IIC_Command(0x20);//0x20,0.77xVcc
	Write_IIC_Command(0x8d);//--set DC-DC enable
	Write_IIC_Command(0x14);//
	Write_IIC_Command(0xaf);//--turn on oled panel 
}
/*******************************************************************************
* 函 数 名         : OLED_SetPos(unsigned char x, unsigned char y)
* 函数功能		   : 设置起始点坐标
* 输    入         : 起始点坐标
* 输    出         : 无
*******************************************************************************/
void OLED_SetPos(unsigned char x, unsigned char y)
{ 
	Write_IIC_Command(0xb0+x);
	Write_IIC_Command((y&0x0f)|0x00);//LOW
	Write_IIC_Command(((y&0xf0)>>4)|0x10);//HIGHT
}
/*******************************************************************************
* 函 数 名         : OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[])
* 函数功能		   : BMP位图函数
* 输    入         : x0,y0 -- 起始点坐标(x0:0~127, y0:0~7); x1,y1 -- 起点对角线(结束点)的坐标(x1:1~128,y1:1~8)
* 输    出         : 无
*******************************************************************************/
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[])
{
	unsigned int j=0;
	unsigned char x,y;
	if(y1%8==0)
		y = y1/8;
	else
		y = y1/8 + 1;
	for(y=y0;y<y1;y++)
	{
		//OLED_SetPos(x0,y);
		OLED_SetPos(y,x0);
		for(x=x0;x<x1;x++)
		{
			Write_IIC_Data(BMP[j++]);
		}
	}
}
