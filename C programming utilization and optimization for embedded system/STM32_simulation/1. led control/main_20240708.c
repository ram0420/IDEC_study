///***** PA5(LED1) on/off *****/
//#define rCC_APB2ENR (*(int *) 0x40021018)
//#define rGPIO_CRL (*(int *) 0x40010800)
//#define rGPIO_ODR (*(int *) 0x4001080C)

// void main()
// {
//	 //1. clock enable port-a, RCC_APB2ENR[2] <- 1, 0x4002.1018
//	 rCC_APB2ENR = rCC_APB2ENR | 0x4 ;		//(0x1 <<2)
//	 
//	 // 2. pa5 -> output, GPIO_CRL[23:20] <- 0011(3), 0x4001.0800
//	 rGPIO_CRL = rGPIO_CRL & ~(0xF << 20);
//	 rGPIO_CRL = rGPIO_CRL | (0x3 << 20);
//	 

//	 
//	 
//	 while (1)
//		 {
//			 //3. change pa5 voltage, GPIOA_ODR[5] <- 0/1, 0x4001.080c
//			 rGPIO_ODR = rGPIO_ODR | (0x1<<5);		//LED off
//			 
//			 rGPIO_ODR = rGPIO_ODR & ~(0x1<<5);		//LED on
//		 }
// }


///***** PA5(LED1) & PA11(LED8) on/off *****/
//#define rCC_APB2ENR (*(int *) 0x40021018)
//#define rGPIO_CRL (*(int *) 0x40010800)
//#define rGPIO_CRH (*(int *) 0x40011004)
//#define rGPIOA_ODR (*(int *) 0x4001080C)
//#define rGPIOC_ODR (*(int *) 0x4001100C)

// void main()
// {
//	 //1. clock enable port-a, RCC_APB2ENR[2] <- 1, 0x4002.1018
//	 rCC_APB2ENR = rCC_APB2ENR | (0x1<<4)|(0x4) ;	
//	 
//	 // 2. pa5 -> output, GPIO_CRL[23:20] <- 0011(3), 0x4001.0800
//	 rGPIO_CRL = rGPIO_CRL & ~(0xF << 20);
//	 rGPIO_CRL = rGPIO_CRL | (0x3 << 20);
//	 //2. pa11
//	 rGPIO_CRH = rGPIO_CRH & ~(0xF << 12);
//	 rGPIO_CRH = rGPIO_CRH | (0x3 << 12);
//	 	 
//	 
//	 while (1)
//		 {
//			 //3. change pa5 voltage, GPIOA_ODR[5] <- 0/1, 0x4001.080c
//			 rGPIOA_ODR = rGPIOA_ODR | (0x1<<5);		//LED off
//			 rGPIOA_ODR = rGPIOA_ODR & ~(0x1<<5);		//LED on
//			 //3. change pa11
//			 rGPIOC_ODR = rGPIOC_ODR | (0x1<<11);		//LED off
//			 rGPIOC_ODR = rGPIOC_ODR & ~(0x1<<11);		//LED on
//		 }
// }


///***** self study *****/
//#define rCC_APB2ENR (*(int *) 0x40021018)
//#define rGPIOA_CRL (*(int *) 0x40010800)		//PA5, PA6, PA7
//#define rGPIOA_CRH (*(int *) 0x40010804)		//PA8
//#define rGPIOC_CRH (*(int *) 0x40011004)		//PC8,PC9,PC10,PC11
//#define rGPIOA_ODR (*(int *) 0x4001080C)
//#define rGPIOC_ODR (*(int *) 0x4001100C)


//void delay (int a)
//{
//	volatile int i,j;
//	for (i = 0; i<a;i++)
//	{
//		j++;
//	}
//	return;
//}

// void main()
// {
//	 //1. clock enable port-a & port-c
//	 rCC_APB2ENR = rCC_APB2ENR | (0x1<<4)|(0x4) ;	
//	 
//	 // 2. pa5,6,7 
//	 rGPIOA_CRL = rGPIOA_CRL & ~((0xF << 20)|(0xF << 24)|(0xF << 28));
//	 rGPIOA_CRL = rGPIOA_CRL | (0x3 << 20)|(0x3 << 24)|(0x3 << 28);
//	 // 2. pa8
//	 rGPIOA_CRH = rGPIOA_CRH & ~((0xF << 0));
//	 rGPIOA_CRH = rGPIOA_CRH | (0x3 << 0);
//	 //2. pc8,9,10,11
//	 rGPIOC_CRH = rGPIOC_CRH & ~((0xF << 0)|(0xF << 4)|(0xF << 8)|(0xF << 12));
//	 rGPIOC_CRH = rGPIOC_CRH | ((0x3 << 0)|(0x3 << 4)|(0x3 << 8)|(0x3 << 12));
//	 	 
//	 
//	 while (1)
//		 {
//			 //LED all on
//			 rGPIOC_ODR = rGPIOC_ODR & ~((0x1<<11)|(0x1<<10)|(0x1<<9)|(0x1<<8));
//			 rGPIOA_ODR = rGPIOA_ODR & ~((0x1<<8)|(0x1<<7)|(0x1<<6)|(0x1<<5));
//			 //3. LED off one by one
//			 rGPIOC_ODR = rGPIOC_ODR | (0x1<<11);
//			 delay(500000);
//			 rGPIOC_ODR = rGPIOC_ODR |(0x1<<10);
//			 delay(500000);
//			 rGPIOC_ODR = rGPIOC_ODR |(0x1<<9);
//			 delay(500000);
//			 rGPIOC_ODR = rGPIOC_ODR |(0x1<<8);
//			 delay(500000);
//			 rGPIOA_ODR = rGPIOA_ODR | (0x1<<8);
//			 delay(500000);
//			 rGPIOA_ODR = rGPIOA_ODR | (0x1<<7);
//			 delay(500000);
//			 rGPIOA_ODR = rGPIOA_ODR | (0x1<<6);
//			 delay(500000);
//			 rGPIOA_ODR = rGPIOA_ODR | (0x1<<5);
//			 delay(500000);
//		 }
// }
 



/***** self study _ make more comfortable *****/
#define rCC_APB2ENR (*(int *) 0x40021018)
#define rGPIOA_CRL (*(int *) 0x40010800)		//PA5, PA6, PA7
#define rGPIOA_CRH (*(int *) 0x40010804)		//PA8
#define rGPIOC_CRH (*(int *) 0x40011004)		//PC8,PC9,PC10,PC11
#define rGPIOA_ODR (*(int *) 0x4001080C)
#define rGPIOC_ODR (*(int *) 0x4001100C)


void delay (int a)
{
	volatile int i,j;
	for (i = 0; i<a;i++)
	{
		j++;
	}
	return;
}



 void main()
 {
	 //1. clock enable port-a & port-c
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
	 
	 
	 while (1)
		 {
			 //LED all on
			 rGPIOC_ODR = rGPIOC_ODR & ~(0xF<<8);
			 rGPIOA_ODR = rGPIOA_ODR & ~((0x1<<8)|(0x1<<7)|(0x1<<6)|(0x1<<5));
			 
			 for (int i = 11 ; i>7 ; i--)
			 {
					//3. LED off one by one
				 rGPIOC_ODR = rGPIOC_ODR | (0x1<<i);
				 delay(500000);
				 rGPIOC_ODR = rGPIOC_ODR & ~(0x1<<i);
			 }
			 
			 for (int i = 8; i>4; i--)
			 {
				 rGPIOA_ODR = rGPIOA_ODR | (0x1<<i);
				 delay(500000);
				 rGPIOA_ODR = rGPIOA_ODR &~(0x1<<i);

			 }
			 //3. LED off one by one
			 rGPIOC_ODR = rGPIOC_ODR | (0x1<<11);
			 delay(500000);
			 rGPIOC_ODR = rGPIOC_ODR & ~(0x1<<11);
			 
			 rGPIOC_ODR = rGPIOC_ODR |(0x1<<10);
			 delay(500000);
			 rGPIOC_ODR = rGPIOC_ODR &~(0x1<<10);
			 

			 rGPIOC_ODR = rGPIOC_ODR |(0x1<<9);
			 delay(500000);
			 rGPIOC_ODR = rGPIOC_ODR &~(0x1<<9);
			 
			 rGPIOC_ODR = rGPIOC_ODR |(0x1<<8);
			 delay(500000);
			 rGPIOC_ODR = rGPIOC_ODR &~(0x1<<8);

			 rGPIOA_ODR = rGPIOA_ODR | (0x1<<8);
			 delay(500000);
			 rGPIOA_ODR = rGPIOA_ODR &~(0x1<<8);

			 rGPIOA_ODR = rGPIOA_ODR | (0x1<<7);
			 delay(500000);
			 rGPIOA_ODR = rGPIOA_ODR &~(0x1<<7);

			 rGPIOA_ODR = rGPIOA_ODR | (0x1<<6);
			 delay(500000);
			 rGPIOA_ODR = rGPIOA_ODR &~(0x1<<6);

			 rGPIOA_ODR = rGPIOA_ODR | (0x1<<5);
			 delay(500000);
			 rGPIOA_ODR = rGPIOA_ODR &~(0x1<<5);
		 }
 }
