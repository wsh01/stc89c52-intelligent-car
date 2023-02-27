 //超声波测距的启动与计算
#include <reg52.h>

#include <intrins.h>

sbit ECHO=P1^0;  //超声波接口定义

sbit TRIG=P1^1;  //超声波接口定义

unsigned long S=0;

unsigned int time=0;//时间变量
	
void StartModule(void)//启动测距信号

{

	TRIG=1;

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();

	_nop_();
	 
	_nop_();

	TRIG=0;

 }
void Conut(void) //计算距离
 {
	  unsigned char cnt = 0; 
		 while(!ECHO);//当RX为零时等待

		 TR0=1; //开启计数

		 while(ECHO && cnt <= 100)  //超时退出
	 	{
			cnt++;
		 }//当RX为1计数并等待

		 TR0=0;//关闭计数
		
		 if(cnt <= 100)
		 {
				time=TH0*256+TL0;//读取脉宽长度
				S=(time*1.7)/200;//算出来是CM
		 }
		 else
		 {
				S = 85;
		 }

		 TH0=0;
		 TL0=0;

 }