

/***** INTR. Quiz  *****/
#include <stdio.h>
#include "sfr.h"
#include "uart.h"
#include "fnd.h"
#include "exti.h"
#include "main.h"
#include "led.h"


unsigned int gTickCount = 0;
unsigned int gTickCount2 = 0;
unsigned int rstCount = 0;


unsigned int tick;
unsigned int paused = 0;
unsigned int pressed = 0;

unsigned int led_toggle_msec = 0;


int fputc(int c, FILE *fp)
{
	uart_sendbyte(c);
	return c;
}


 
void MySystemTimerIsr()
{
	
//	gTickCount = gTickCount + 1;
//  if (paused%4==0) 
//	{
//			gTickCount2 = gTickCount2 + 1;
//  }
//	if (gTickCount >= (rstCount + 3000))
//	{
//		rstCount = gTickCount;
//		if(pressed == -1)
//		{
//			gTickCount2 = 0;
//			paused = 1;
//		}
//	}
	
		gTickCount = gTickCount + 1;
  if (paused%4==0) 
	{
			gTickCount2 = gTickCount2 + 1;
  }
	if (gTickCount >= (rstCount + 3000))
	{
		rstCount = gTickCount;
		if(pressed == -1)
		{
			gTickCount2 = 0;
			paused = 1;
		}
	}
}



int main()
{
 	rSRVR = 72000 - 1;
	rSCSR = (0x1 << 2) | (0x1 << 1) | (0x1 << 0);	
	
	
	rCC_APB2ENR = rCC_APB2ENR | (0x1<<4)|(0x1<<2)|(0x1 << 1)|(0x1 << 3)|(0x1 << 0) ;	
	
	fnd_init();
	//key_init();
	led_init();
	uart_init();
	exti_init();

	
	for (int k = 0; k<10; k ++)
	{
		uart_sendbyte('a' + k);
	}
	
	unsigned int preMoment = gTickCount;
	unsigned int ledMoment1 = 0;
	unsigned int pos = 0;
	
	
	while (1)
	{
		
		if(gTickCount > (preMoment+5))
		{
			preMoment = gTickCount;
			
			tick = gTickCount2;
			
			unsigned int a[4];
			
			a[3] = (tick / 10) % 10;
	  	a[2] = (tick / 100) % 10;
		  a[1] = (tick / 1000) % 10;
		  a[0] = (tick / 10000) % 10;
			
		  fnd_display(pos, a[pos]);
			pos = (pos + 1)&0x03;
			
		}
		
		//toggle led_1 every 303 msec
		
		if(gTickCount > (ledMoment1+led_toggle_msec))
		{
			led_toggle(1);
			led_toggle(2);
			led_toggle(3);
			led_toggle(4);
			ledMoment1 = gTickCount;
		}
	}
	return 0;
}
