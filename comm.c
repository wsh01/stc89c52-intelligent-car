//舵机不同方向测距与判断
#include <AT89x52.H>

#include "chaoshengbo.h"

#include "run.h"


unsigned char pwm_val_left = 0;//变量定义

unsigned char push_val_left =15;//舵机归中

unsigned long S1=0;

unsigned long S2=0;

unsigned long S3=0;

unsigned long S4=0;

unsigned int timer;//延时基准变量

extern unsigned long S;

void COMM( void )

{
	
		push_val_left=5;//舵机右转90度

		timer=0;

		while(timer<=4000); //延时400MS让舵机转到其位置  

		StartModule(); //启动超声波测距

		Conut();//计算距离

		S2=S;



		push_val_left=24; //舵机向左转90度

		timer=0;

		while(timer<=4000); //延时400MS让舵机转到其位置

		StartModule();//启动超声波测距

		 Conut();//计算距离

		S4=S;




		push_val_left=15; //舵机归中

		timer=0;

		while(timer<=4000); //延时400MS让舵机转到其位置

		StartModule();//启动超声波测距

		Conut();//计算距离

		S1=S;


		if((S2<30)||(S4<30)) //只要左右各有距离小于30CM小车后退

		{

			backrun(); //后退

			timer=0;

			while(timer<=3000);

		}
	
		if(S2<S4)
		{

			rightrun(); //车的左边比车的右边距离小  右转

			timer=0;

			while(timer<=3000);

		}

		else

		{

			leftrun();//车的左边比车的右边距离大  左转

			timer=0;

			while(timer<=3000);

	}
}

		