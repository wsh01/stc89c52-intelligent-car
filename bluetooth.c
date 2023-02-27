#include <reg52.h>
#include "run.h"
unsigned char speed=0;
unsigned char bite;
unsigned char type;
void InitTimer1()  //蓝牙比特率
{ 
	TMOD|=0x20;  //设置T1为工作方式2

  TH1=0xFD;  //装入初值，比特率为9600bps

  TL1=0xFD;

  TR1=1;  //开启T1

  REN=1;  //接收允许

  SM0=0;  //方式1

  SM1=1;

  EA=1;  //开全局中断

  ES=1;  //开串口中断
}



void bluetooth (void)

{ 
	bite=SBUF;//SBUF为单片机接收到的数据，单片机接收到的数据都存放在SBUF里；

	RI=0;
	
  switch(bite)
  {
   case'a':
   backrun();
   break;

   case'b':
    run();
   break;

   case'c':
    leftrun();
   break;

   case'd':
    rightrun();
   break;

   case'e':
		 type=0;
    stoprun();
   break;

   case'f':
	  speed=30;
	 break;
	 
	 case'g':
	  speed=50;
	 break;
	 
	 case'h':
		 speed=70;
	 break;
	 
	 case'i':
		 speed=99;
	 break;
	 
	 case'j':
		 type=1;
	 break;
	 
    }
	
}