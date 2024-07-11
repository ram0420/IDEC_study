///***** FND test2 without delay func. *****/
//#include "sfr.h"


//unsigned int gTickCount = 0;		
//	
//void MySystemTimerIsr()
//{
//	gTickCount = gTickCount + 1;
//}


//void main()
//{
//	rSRVR = 72000 - 1;
//	rSCSR = (0x1 << 2) | (0x1 << 0) | (0x1 << 1);	
//	
//	
//	rCC_APB2ENR = rCC_APB2ENR | (0x1<<4)|(0x1<<2) ;	
//	
//	fnd_init();
//	led_init();
//	
//	unsigned int preMoment = 0;
//	unsigned int ledMoment0 = 0;
//	unsigned int ledMoment1 = 0;
//	unsigned int pos = 0;
//	
//	while (1)
//	{
//		unsigned int a, b, c, d;
//		a = (gTickCount / 10) % 10;
//		b = (gTickCount / 100) % 10;
//		c = (gTickCount / 1000) % 10;
//		d = (gTickCount / 10000) % 10;
//		
//		if((gTickCount - preMoment) >= 5)
//		{
//			switch(pos)
//			{
//				case 0:
//					fnd_display(0,d);
//					break;
//				case 1:
//					fnd_display(1,c);
//					break;
//				case 2:
//					fnd_display(2,b);
//					break;
//				case 3:
//					fnd_display(3,a);
//					break;
//			}
//			pos = (pos + 1)%4;
//			preMoment = gTickCount;
//		}
//		
//		//toggle led_0 every 103 msec
//		if((gTickCount - ledMoment0) >= 103)
//		{
//			rGPIOA->ODR = (rGPIOA->ODR) ^ (0x1 <<5);
//			ledMoment0 = gTickCount;
//		}
//		
//		//toggle led_1 every 303 msec
//		if((gTickCount - ledMoment1) >= 303)
//		{
//			rGPIOA->ODR = (rGPIOA->ODR) ^ (0x1 <<6);
//			ledMoment1 = gTickCount;
//		}
//		//...
//	}
//}

///***** FND test2 without delay func.2 *****/
//#include "sfr.h"


//unsigned int gTickCount = 0;		
//	
//void MySystemTimerIsr()
//{
//	gTickCount = gTickCount + 1;
//}

////void MyDelay(unsigned int msec)
////{
////	unsigned int next_tick = gTickCount + msec;
////	while(gTickCount < next_tick)
////	{
////	}
////}


//void main()
//{
// 	rSRVR = 72000 - 1;
//	rSCSR = (0x1 << 2) | (0x1 << 0) | (0x1 << 1);	
//	
//	
//	rCC_APB2ENR = rCC_APB2ENR | (0x1<<4)|(0x1<<2)|(0x1 << 1)|(0x1 << 3) ;	
//	
//	fnd_init();
//	led_init();
//	
//	unsigned int preMoment = gTickCount;
//	unsigned int ledMoment0 = 0;
//	unsigned int ledMoment1 = 0;
//	unsigned int pos = 0;
//	
//	while (1)
//	{
//		unsigned int a, b, c, d;
//		a = (gTickCount / 10) % 10;
//		b = (gTickCount / 100) % 10;
//		c = (gTickCount / 1000) % 10;
//		d = (gTickCount / 10000) % 10;
//		
//		
//		if(gTickCount > (preMoment+5))
//		{
//			switch(pos)
//			{
//				case 0:
//					fnd_display(0,d);
//					break;
//				case 1:
//					fnd_display(1,c);
//					break;
//				case 2:
//					fnd_display(2,b);
//					break;
//				case 3:
//					fnd_display(3,a);
//					break;
//			}
//			pos = (pos + 1)%4;
//			preMoment = gTickCount;
//		}
//		
//		//toggle led_0 every 103 msec
//		if(gTickCount > (ledMoment0+103))
//		{
//			rGPIOA->ODR = (rGPIOA->ODR) ^ (0x1 <<5);
//			ledMoment0 = gTickCount;
//		}
//		
//		//toggle led_1 every 303 msec
//		if(gTickCount > (ledMoment1+303))
//		{
//			rGPIOA->ODR = (rGPIOA->ODR) ^ (0x1 <<6);
//			ledMoment1 = gTickCount;
//		}
//		//...
//	}
//}



///***** timer stop *****/
//#include <stdio.h>
//#include "sfr.h"


//unsigned int gTickCount = 0;
//unsigned int gTickCount2 = 0;
//unsigned int gTickCount3 = 0;

//unsigned int tick = 0;

//int fputc(int c, FILE *fp)
//{
//	uart_sendbyte(c);
//	return c;
//}
// 
//void MySystemTimerIsr()
//{
//	gTickCount = gTickCount + 1;
//	gTickCount2 = gTickCount2 + 1;
//	gTickCount3 = gTickCount3 + 1;
//}



//void main()
//{
// 	rSRVR = 72000 - 1;
//	rSCSR = (0x1 << 2) | (0x1 << 0) | (0x1 << 1);	
//	
//	
//	rCC_APB2ENR = rCC_APB2ENR | (0x1<<4)|(0x1<<2)|(0x1 << 1)|(0x1 << 3) ;	
//	
//	fnd_init();
//	led_init();
//	uart_init();
//	
//	printf("hello world \r\n");
//	
//	for (int k = 0; k<10; k ++)
//	{
//		uart_sendbyte('a' + k);
//	}
//	
//	unsigned int preMoment = gTickCount;
//	unsigned int ledMoment0 = 0;
//	unsigned int ledMoment1 = 0;
//	unsigned int pos = 0;
//	unsigned int tick;
//	
//	while (1)
//	{
//		
//		if(gTickCount > (preMoment+5))
//		{
//			preMoment = gTickCount;
//			
//			unsigned int tick = gTickCount2;
//			unsigned int a[4];
//			
//			a[3] = (tick / 10) % 10;
//	  	a[2] = (tick / 100) % 10;
//		  a[1] = (tick / 1000) % 10;
//		  a[0] = (tick / 10000) % 10;
//			
//		  fnd_display(pos, a[pos]);
//			pos = (pos + 1)&0x03;
//			
//		}
//		
//		//if you press the center key, reset the timer
//		if(key_C == 0)
//		{				
//			gTickCount2 = 0;
//			tick = gTickCount2;
//		}

//		//if you press the up key, reset the timer
//		if(key_U == 0)
//		{				
//			tick = gTickCount3;
//		}
//		
//		//toggle led_0 every 103 msec
//		if(gTickCount > (ledMoment0+103))
//		{
//			led_toggle(1);
//			ledMoment0 = gTickCount;
//		}
//		
//		//toggle led_1 every 303 msec
//		if(gTickCount > (ledMoment1+303))
//		{
//			led_toggle(2);
//			ledMoment1 = gTickCount;
//		}
//	}
//}

/***** UART & INTR. test  *****/
#include <stdio.h>
#include "sfr.h"


unsigned int gTickCount = 0;
unsigned int gTickCount2 = 0;
unsigned int gTickCount3 = 0;

unsigned int tick = 0;

int fputc(int c, FILE *fp)
{
	uart_sendbyte(c);
	return c;
}


 
void MySystemTimerIsr()
{
	gTickCount = gTickCount + 1;
	gTickCount2 = gTickCount2 + 1;
	gTickCount3 = gTickCount3 + 1;
}



void main()
{
 	rSRVR = 72000 - 1;
	rSCSR = (0x1 << 2) | (0x1 << 0) | (0x1 << 1);	
	
	
	rCC_APB2ENR = rCC_APB2ENR | (0x1<<4)|(0x1<<2)|(0x1 << 1)|(0x1 << 3)|(0x1 << 0) ;	
	
	fnd_init();
	led_init();
	uart_init();
	exti_init();
	
	printf("hello world \r\n");
	
//	while(1)
//	{
//		char c = uart_readbyte();
//		printf("received data : %c \r\n",c);
//	}
	
	
	for (int k = 0; k<10; k ++)
	{
		uart_sendbyte('a' + k);
	}
	
	unsigned int preMoment = gTickCount;
	unsigned int ledMoment0 = 0;
	unsigned int ledMoment1 = 0;
	unsigned int pos = 0;
	unsigned int tick;
	
	while (1)
	{
		
		if(gTickCount > (preMoment+5))
		{
			preMoment = gTickCount;
			
			unsigned int tick = gTickCount2;
			unsigned int a[4];
			
			a[3] = (tick / 10) % 10;
	  	a[2] = (tick / 100) % 10;
		  a[1] = (tick / 1000) % 10;
		  a[0] = (tick / 10000) % 10;
			
		  fnd_display(pos, a[pos]);
			pos = (pos + 1)&0x03;
			
		}
