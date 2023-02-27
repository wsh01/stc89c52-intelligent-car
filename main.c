#include <reg52.h>
#include "delay.h"
#include "run.h"
#include "chaoshengbo.h"
#include "comm.h"
#include "bizhang.h"
#include "bluetooth.h"
#include "iic.h"
#include "oled.h"
#include "oled_main.h"
extern unsigned char push_val_left ;
extern unsigned char pwm;
extern unsigned char type;
void main()
{
	    stoprun();
	
	    OLED_Init();
	
	    Delay_1ms(5);
	     
	    InitTimer1();
				
      InitTimer2();
				
			delay(100);

			push_val_left=15; //¶æ»ú¹éÖÐ
	    
	     oled_main();

	 while(1)
	 {
		  
		 
		  bluetooth();
		 
		 if(type==1)
		 {
	  	bizhang();
		 }
	 }
}