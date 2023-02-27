#include <reg52.h>
#include "delay.h"
#include "run.h"
#include "chaoshengbo.h"
#include "comm.h"
#include "bluetooth.h"

sbit ena=P2^0;
sbit enb=P2^5;

sbit  Sevro_moto_pwm=P1^2;  //舵机管脚
extern unsigned char push_val_left ;
extern unsigned int timer;
extern unsigned char pwm_val_left ;
extern unsigned long S;
unsigned char pwm_count;
unsigned char pwm;
extern unsigned char speed;
 
/*调节push_val_left的值改变电机转速,占空比*/

void pwm_Servomoto(void)
{
	if(pwm_val_left<=push_val_left)  //舵机
		Sevro_moto_pwm=1;
	
	else
		Sevro_moto_pwm=0;

	if(pwm_val_left>=200)
		pwm_val_left=0;
	
	if(pwm_count<=speed)
	{
		ena=1;
	  enb=1;
	}
	else
	{
		ena=0;
	  enb=0;
	}
	if(pwm_count>=100)
		pwm_count=0;

}

///*TIMER1中断服务子函数产生PWM信号*/

void Time2()interrupt 5 

{
	  TF2=0;
	
		timer++;  //定时器100US为准。在这个基础上延时

		pwm_val_left++;
	
	  pwm_count++;

		pwm_Servomoto();

}
void InitTimer2()
{
      RCAP2H=(65536-100)/256;
	
			RCAP2L=(65536-100)%256;
		
			//TH2=RCAP2H;
		
			//TL2=RCAP2L;

	    T2CON=0;
	
	    T2MOD=0;
	
			TH0=0;

			TL0=0;

	    IE=0XA0;

			TR2=1;

			ET0= 1;

			EA = 1;
}


void bizhang(void)
{
			
					if(timer>=150) //100MS检测启动检测一次
						
					{
							timer=0;

							StartModule(); //启动检测

							Conut();//计算距离

							if(S<80)//距离小于40CM

						 {

								stoprun(); //小车停止

								COMM(); //方向函数

							}

							 else if(S>=80)//距离大于40CM往前走

								run();
					}

			

}

	