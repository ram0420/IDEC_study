///***** key control *****/
//#define rCC_APB2ENR (*(int *) 0x40021018)
//#define rGPIOA_CRL (*(int *) 0x40010800)		//LED(PA5, PA6, PA7) & KEY (PA2,3,4)
//#define rGPIOA_CRH (*(int *) 0x40010804)		//PA8
//	
//#define rGPIOB_CRL (*(int *) 0x40010C00)		//KEY (PB0,1)
////#define rGPIOB_CRH (*(int *) 0x)		//

//#define rGPIOC_CRH (*(int *) 0x40011004)		//PC8,PC9,PC10,PC11
//	
//#define rGPIOA_ODR (*(int *) 0x4001080C)
//#define rGPIOC_ODR (*(int *) 0x4001100C)

//#define rGPIOB_IDR (*(int *) 0x40010C08)		//key up,down(PB0,1)
//#define rGPIOA_IDR (*(int *) 0x40010808)		//key C,L,R(PA2,3,4)
//	

//void main()
//{
//	rCC_APB2ENR = rCC_APB2ENR | (0x1<<4)|(0x4) ;	
//	
//	 // 2. pa5,6,7 output setting
//	 rGPIOA_CRL = rGPIOA_CRL & ~((0xF << 20)|(0xF << 24)|(0xF << 28));
//	 rGPIOA_CRL = rGPIOA_CRL | (0x3 << 20)|(0x3 << 24)|(0x3 << 28);
//	 // 2. pa8 output setting
//	 rGPIOA_CRH = rGPIOA_CRH & ~((0xF << 0));
//	 rGPIOA_CRH = rGPIOA_CRH | (0x3 << 0);
//	 //2. pc8,9,10,11 output setting
//	 rGPIOC_CRH = rGPIOC_CRH & ~((0xF << 0)|(0xF << 4)|(0xF << 8)|(0xF << 12));
//	 rGPIOC_CRH = rGPIOC_CRH | ((0x3 << 0)|(0x3 << 4)|(0x3 << 8)|(0x3 << 12));
//	
//	//pb0,1 pa2,3,4 input setting (key UDCLR)
//	rGPIOB_IDR = rGPIOB_IDR & ~()
//	
//	
//	while (1)
//	{
//		if((rGPIOA_IDR & (0x1<<2)) == 0 )		// if GPIOA_IDR[2]
//		{
//			rGPIOA_ODR = rGPIOA_ODR & ~ (0x1 << 5);
//		}
//		else
//		{
//			rGPIOA_ODR = rGPIOA_ODR | (0x1 << 5);
//		}
//	}
//}


///***** system Timer *****/
#define rCC_APB2ENR (*(int *) 0x40021018)
#define rGPIOA_CRL (*(int *) 0x40010800)		//LED(PA5, PA6, PA7) & KEY (PA2,3,4)
#define rGPIOA_CRH (*(int *) 0x40010804)		//PA8
	
#define rGPIOB_CRL (*(int *) 0x40010C00)		//KEY (PB0,1)

#define rGPIOC_CRH (*(int *) 0x40011004)		//PC8,PC9,PC10,PC11
	
#define rGPIOA_ODR (*(int *) 0x4001080C)
#define rGPIOC_ODR (*(int *) 0x4001100C)

#define rGPIOB_IDR (*(int *) 0x40010C08)		//key up,down(PB0,1)
#define rGPIOA_IDR (*(int *) 0x40010808)		//key C,L,R(PA2,3,4)
	
#define rSCSR (*(int*) 0xE000E010)
#define rSRVR (*(int*) 0xE000E014)
#define rSCVR (*(int*) 0xE000E018)
	
unsigned int gTickCount;	
void MySystemTimerIsr()
{
	gTickCount = gTickCount + 1;
}

void MyDelay(unsigned int msec)
{
	unsigned int next_tick = gTickCount + msec;
	while(gTickCount < next_tick)
	{
	}
}

void main()
{
	rSRVR = 72000 - 1;
	rSCSR = (0x1 << 2) | (0x1 << 0) | (0x1 << 1);		//write 5
	
	
	rCC_APB2ENR = rCC_APB2ENR | (0x1<<4)|(0x4) ;	
	
	// 2. pa5,6,7 output setting
	rGPIOA_CRL = rGPIOA_CRL & ~((0xF << 20)|(0xF << 24)|(0xF << 28));
	rGPIOA_CRL = rGPIOA_CRL | (0x3 << 20)|(0x3 << 24)|(0x3 << 28);
	
	// 2. pa8 output setting
	rGPIOA_CRH = rGPIOA_CRH & ~((0xF << 0));
	rGPIOA_CRH = rGPIOA_CRH | (0x3 << 0);
	//2. pc8,9,10,11 output setting
	rGPIOC_CRH = rGPIOC_CRH & ~((0xF << 0)|(0xF << 4)|(0xF << 8)|(0xF << 12));
	rGPIOC_CRH = rGPIOC_CRH | ((0x3 << 0)|(0x3 << 4)|(0x3 << 8)|(0x3 << 12));
	
	//input setting
	
	
	
	
	while (1)
	{
		#if 0
				rGPIOA_ODR = rGPIOA_ODR & ~ (0x1 << 5);
				MyDelay(100);
				
				rGPIOA_ODR = rGPIOA_ODR | (0x1 << 5);
				MyDelay(100);
		#else
				rGPIOA_ODR = rGPIOA_ODR ^ (0x1 <<5);
				MyDelay(100);
		#endif
	}
}
