 //�������������������
#include <reg52.h>

#include <intrins.h>

sbit ECHO=P1^0;  //�������ӿڶ���

sbit TRIG=P1^1;  //�������ӿڶ���

unsigned long S=0;

unsigned int time=0;//ʱ�����
	
void StartModule(void)//��������ź�

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
void Conut(void) //�������
 {
	  unsigned char cnt = 0; 
		 while(!ECHO);//��RXΪ��ʱ�ȴ�

		 TR0=1; //��������

		 while(ECHO && cnt <= 100)  //��ʱ�˳�
	 	{
			cnt++;
		 }//��RXΪ1�������ȴ�

		 TR0=0;//�رռ���
		
		 if(cnt <= 100)
		 {
				time=TH0*256+TL0;//��ȡ������
				S=(time*1.7)/200;//�������CM
		 }
		 else
		 {
				S = 85;
		 }

		 TH0=0;
		 TL0=0;

 }