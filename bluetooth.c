#include <reg52.h>
#include "run.h"
unsigned char speed=0;
unsigned char bite;
unsigned char type;
void InitTimer1()  //����������
{ 
	TMOD|=0x20;  //����T1Ϊ������ʽ2

  TH1=0xFD;  //װ���ֵ��������Ϊ9600bps

  TL1=0xFD;

  TR1=1;  //����T1

  REN=1;  //��������

  SM0=0;  //��ʽ1

  SM1=1;

  EA=1;  //��ȫ���ж�

  ES=1;  //�������ж�
}



void bluetooth (void)

{ 
	bite=SBUF;//SBUFΪ��Ƭ�����յ������ݣ���Ƭ�����յ������ݶ������SBUF�

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