//�����ͬ���������ж�
#include <AT89x52.H>

#include "chaoshengbo.h"

#include "run.h"


unsigned char pwm_val_left = 0;//��������

unsigned char push_val_left =15;//�������

unsigned long S1=0;

unsigned long S2=0;

unsigned long S3=0;

unsigned long S4=0;

unsigned int timer;//��ʱ��׼����

extern unsigned long S;

void COMM( void )

{
	
		push_val_left=5;//�����ת90��

		timer=0;

		while(timer<=4000); //��ʱ400MS�ö��ת����λ��  

		StartModule(); //�������������

		Conut();//�������

		S2=S;



		push_val_left=24; //�������ת90��

		timer=0;

		while(timer<=4000); //��ʱ400MS�ö��ת����λ��

		StartModule();//�������������

		 Conut();//�������

		S4=S;




		push_val_left=15; //�������

		timer=0;

		while(timer<=4000); //��ʱ400MS�ö��ת����λ��

		StartModule();//�������������

		Conut();//�������

		S1=S;


		if((S2<30)||(S4<30)) //ֻҪ���Ҹ��о���С��30CMС������

		{

			backrun(); //����

			timer=0;

			while(timer<=3000);

		}
	
		if(S2<S4)
		{

			rightrun(); //������߱ȳ����ұ߾���С  ��ת

			timer=0;

			while(timer<=3000);

		}

		else

		{

			leftrun();//������߱ȳ����ұ߾����  ��ת

			timer=0;

			while(timer<=3000);

	}
}

		