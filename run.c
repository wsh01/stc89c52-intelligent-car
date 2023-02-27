//小车的运动
#include <reg52.h>
#include "bizhang.h"
sbit in4=P2^1;
sbit in3=P2^2;
sbit in2=P2^3;
sbit in1=P2^4;

//前进

 void run(void)
{
	 in4=1;in3=0;	  //右前
	
	 in1=0;in2=1;   //左前
}


//后退

void backrun(void)
{
		in4=0;in3=1;  //右后

	  in1=1;in2=0;   //左后
}

//左转

 void leftrun(void)
{
	   in4=1;in3=0;   //右前

		 in1=1;in2=0;   //左后
}


//右转

 void rightrun(void)
{
	  in4=0;in3=1;   //右后

		in1=0;in2=1;   //左前
}

//停

void stoprun(void)
{
	  in4=1;in3=1;   //左停
			
	  in1=1;in2=1;   //右停
}


