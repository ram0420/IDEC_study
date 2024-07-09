///***** FND test *****/
//#include "sfr.h"


//unsigned int gTickCount;	
//void MySystemTimerIsr()
//{
//	gTickCount = gTickCount + 1;
//}

//void MyDelay(unsigned int msec)
//{
//	unsigned int next_tick = gTickCount + msec;
//	while(gTickCount < next_tick)
//	{
//	}
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
//	
//	
//	while (1)
//	{
//		fnd_display(0,5);
//		MyDelay(5);
//		
//		fnd_display(1,6);
//		MyDelay(5);
//		
//		fnd_display(2,7);
//		MyDelay(5);
//		
//		fnd_display(3,8);
//		MyDelay(5);
//	}
//}


///***** FND test2 *****/
//#include "sfr.h"


//unsigned int gTickCount;	
//void MySystemTimerIsr()
//{
//	gTickCount = gTickCount + 1;
//}

//void MyDelay(unsigned int msec)
//{
//	unsigned int next_tick = gTickCount + msec;
//	while(gTickCount < next_tick)
//	{
//	}
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
//	
//	unsigned int d = 10;
//	
//	while (1)
//	{
//		unsigned int a, b, c, d;
//		a = (gTickCount / 10) % 10;
//		b = (gTickCount / 100) % 10;
//		c = (gTickCount / 1000) % 10;
//		d = (gTickCount / 10000) % 10;
//		
//		fnd_display(0,d);
//		MyDelay(5);
//		
//		fnd_display(1,c);
//		MyDelay(5);
//		
//		fnd_display(2,b);
//		MyDelay(5);
//		
//		fnd_display(3,a);
//		MyDelay(5);
//		
//		//toggle led_0 every 103 msec
//		
//		//toggle led_1 every 303 msec
//		
//		//...
//	}
//}



/***** FND test2 without delay func. *****/
#include "sfr.h"


unsigned int gTickCount = 0;	
//unsigned int preMoment = 0;
//unsigned int pos = 0;
	
	
void MySystemTimerIsr()
{
	gTickCount = gTickCount + 1;
}


void main()
{
	rSRVR = 72000 - 1;
	rSCSR = (0x1 << 2) | (0x1 << 0) | (0x1 << 1);	
	
	
	rCC_APB2ENR = rCC_APB2ENR | (0x1<<4)|(0x1<<2) ;	
	
	fnd_init();
	led_init();
	
	unsigned int preMoment = 0;
	unsigned int ledMoment0 = 0;
	unsigned int ledMoment1 = 0;
	unsigned int pos = 0;
	
	while (1)
	{
		unsigned int a, b, c, d;
		a = (gTickCount / 10) % 10;
		b = (gTickCount / 100) % 10;
		c = (gTickCount / 1000) % 10;
		d = (gTickCount / 10000) % 10;
		
		if((gTickCount - preMoment) >= 5)
		{
			switch(pos)
			{
				case 0:
					fnd_display(0,d);
					break;
				case 1:
					fnd_display(1,c);
					break;
				case 2:
					fnd_display(2,b);
					break;
				case 3:
					fnd_display(3,a);
					break;
			}
			pos = (pos + 1)%4;
			preMoment = gTickCount;
		}
		
		//toggle led_0 every 103 msec
		if((gTickCount - ledMoment0) >= 103)
		{
			rGPIOA->ODR = (rGPIOA->ODR) ^ (0x1 <<5);
			ledMoment0 = gTickCount;
		}
		
		//toggle led_1 every 303 msec
		if((gTickCount - ledMoment1) >= 303)
		{
			rGPIOA->ODR = (rGPIOA->ODR) ^ (0x1 <<6);
			ledMoment1 = gTickCount;
		}
		//...
	}
}
