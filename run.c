//С�����˶�
#include <reg52.h>
#include "bizhang.h"
sbit in4=P2^1;
sbit in3=P2^2;
sbit in2=P2^3;
sbit in1=P2^4;

//ǰ��

 void run(void)
{
	 in4=1;in3=0;	  //��ǰ
	
	 in1=0;in2=1;   //��ǰ
}


//����

void backrun(void)
{
		in4=0;in3=1;  //�Һ�

	  in1=1;in2=0;   //���
}

//��ת

 void leftrun(void)
{
	   in4=1;in3=0;   //��ǰ

		 in1=1;in2=0;   //���
}


//��ת

 void rightrun(void)
{
	  in4=0;in3=1;   //�Һ�

		in1=0;in2=1;   //��ǰ
}

//ͣ

void stoprun(void)
{
	  in4=1;in3=1;   //��ͣ
			
	  in1=1;in2=1;   //��ͣ
}


