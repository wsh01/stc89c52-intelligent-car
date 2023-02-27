#ifndef __OLED_H
#define __OLED_H

#include "iic.h"

void OLED_Init();
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);


#endif
