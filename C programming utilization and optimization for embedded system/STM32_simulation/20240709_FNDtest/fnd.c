/***** fnd.c *****/
#include "sfr.h"


void fnd_init()
{
	// clk enable port -b, port-c (RCC_APB2ENR)
	rCC_APB2ENR = rCC_APB2ENR | (0x1<<4)|(0x1<<2)|(0x1 << 1)|(0x1 << 3);
	
	// pc0 ... pc7 -> output
	rGPIOC->CRL = 0x33333333;
	

	
	// pb12 ... pb15 -> output
	rGPIOB->CRH = (rGPIOB->CRH & ~(0xFFFF<<16))|(0x3333<<16);
}



void fnd_display(int pos, int value)
{
	// 1. all led off
	rGPIOC->ODR = rGPIOC->ODR & ~(0xFF);
	
	
	// 2. all transistor off
	rGPIOB->ODR = rGPIOB->ODR & ~(0xFF<<12);
	
	// 3.
	if (value == 0)
	{
		rGPIOC->ODR = rGPIOC->ODR | (0x1 <<5)
															| (0x1 <<4)
															| (0x1 <<3)
															| (0x1 <<2)
															| (0x1 <<1)
															| (0x1 <<0);
	}
	else if (value == 1)
	{
		rGPIOC->ODR = rGPIOC->ODR | (0x1 <<2)
															| (0x1 <<1);
	}
	else if (value == 2)
	{
		rGPIOC->ODR = rGPIOC->ODR | (0x1 <<0)
															| (0x1 <<1)
															| (0x1 <<6)
															| (0x1 <<4)
															| (0x1 <<3);
	}
	else if (value == 3)
	{
		rGPIOC->ODR = rGPIOC->ODR | (0x1 <<0)
															| (0x1 <<1)
															| (0x1 <<6)
															| (0x1 <<2)
															| (0x1 <<3);
	}
	else if (value == 4)
	{
		rGPIOC->ODR = rGPIOC->ODR | (0x1 <<5)
															| (0x1 <<6)
															| (0x1 <<1)
															| (0x1 <<2);
	}
	else if (value == 5)
	{
		rGPIOC->ODR = rGPIOC->ODR | (0x1 <<0)
															| (0x1 <<5)
															| (0x1 <<6)
															| (0x1 <<2)
															| (0x1 <<3);
	}
	else if (value == 6)
	{
		rGPIOC->ODR = rGPIOC->ODR | (0x1 <<0)
															| (0x1 <<5)
															| (0x1 <<4)
															| (0x1 <<3)
															| (0x1 <<2)
															| (0x1 <<6);
	}
	else if (value == 7)
	{
		rGPIOC->ODR = rGPIOC->ODR | (0x1 <<5)
															| (0x1 <<0)
															| (0x1 <<1)
															| (0x1 <<2);
	}
	else if (value == 8)
	{
		rGPIOC->ODR = rGPIOC->ODR | (0x1 <<6)
															| (0x1 <<5)
															| (0x1 <<4)
															| (0x1 <<3)
															| (0x1 <<2)
															| (0x1 <<1)
															| (0x1 <<0);
	}
	else if (value == 9)
	{
		rGPIOC->ODR = rGPIOC->ODR | (0x1 <<0)
															| (0x1 <<5)
															| (0x1 <<6)
															| (0x1 <<1)
															| (0x1 <<2)
															| (0x1 <<3);
	}
	
	// 4. 
	if(pos == 0)
	{
		// turn on the 1st transistor
		rGPIOB-> ODR = rGPIOB-> ODR | (0x1<<12);
	}
	else if (pos == 1)
	{
		// turn on the 2nd transistor
		rGPIOB-> ODR = rGPIOB-> ODR | (0x1<<13);
	}
	else if (pos == 2)
	{
		// turn on the 3rd transistor
		rGPIOB-> ODR = rGPIOB-> ODR | (0x1<<14);
	}
	else if (pos == 3)
	{
		// turn on the 4th transistor
		rGPIOB-> ODR = rGPIOB-> ODR | (0x1<<15);
	}

}
