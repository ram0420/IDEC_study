/***** LED test *****/
 
#include "sfr.h"
 
extern unsigned int gTickCount;
 
void led_init()
{
	//clk enable port-a, port-c
	rCC_APB2ENR = rCC_APB2ENR | (0x1<<4)|(0x1<<2);
	 
	// pa5,6,7 output setting
	rGPIOA->CRL = rGPIOA->CRL & ~((0xF << 20)|(0xF << 24)|(0xF << 28));
	rGPIOA->CRL = rGPIOA->CRL | (0x3 << 20)|(0x3 << 24)|(0x3 << 28);
	
	// pa8 output setting
	rGPIOA->CRH = rGPIOA->CRH & ~((0xF << 0));
	rGPIOA->CRH = rGPIOA->CRH | (0x3 << 0);
	 
	// pc8,9,10,11 output setting
	rGPIOC->CRH = rGPIOC->CRH & ~((0xF << 0)|(0xF << 4)|(0xF << 8)|(0xF << 12));
	rGPIOC->CRH = rGPIOC->CRH | ((0x3 << 0)|(0x3 << 4)|(0x3 << 8)|(0x3 << 12));
	
}

void led_display(int value)
{
	// all led off
	rGPIOA->ODR = rGPIOA -> ODR & ~(0x1E<<4);
	rGPIOC->ODR = rGPIOC->ODR & ~(0xF<<8);
	// display
	if (value == 1)
	{
		rGPIOA -> ODR = rGPIOA -> ODR | (0x1<<5);
	}
	else if (value == 2)
	{
		rGPIOA -> ODR = rGPIOA -> ODR | (0x1<<6);
	}
	else if (value == 3)
	{
		rGPIOA -> ODR = rGPIOA -> ODR | (0x1<<7);
	}
	else if (value == 4)
	{
		rGPIOA -> ODR = rGPIOA -> ODR | (0x1<<8);
	}
	else if (value == 5)
	{
		rGPIOC -> ODR = rGPIOC -> ODR | (0x1<<8);
	}
	else if (value == 6)
	{
		rGPIOC -> ODR = rGPIOC -> ODR | (0x1<<9);
	}
	else if (value == 7)
	{
		rGPIOC -> ODR = rGPIOC -> ODR | (0x1<<10);
	}
	else if (value == 8)
	{
		rGPIOC -> ODR = rGPIOC -> ODR | (0x1<<11);
	}
}

void led_toggle(int led_num)
{
	switch(led_num)
		{
			case 1 : rGPIOA -> ODR = rGPIOA -> ODR ^ (0x1<<5); break;
			case 2 : rGPIOA -> ODR = rGPIOA -> ODR ^ (0x1<<6); break;
			case 3 : rGPIOA -> ODR = rGPIOA -> ODR ^ (0x1<<7); break;
			case 4 : rGPIOA -> ODR = rGPIOA -> ODR ^ (0x1<<8); break;
			case 5 : rGPIOC -> ODR = rGPIOC -> ODR ^ (0x1<<8); break;
			case 6 : rGPIOC -> ODR = rGPIOC -> ODR ^ (0x1<<9); break;
			case 7 : rGPIOC -> ODR = rGPIOC -> ODR ^ (0x1<<10); break;
			case 8 : rGPIOC -> ODR = rGPIOC -> ODR ^ (0x1<<11); break;
			default: {rGPIOA->ODR = rGPIOA -> ODR & ~(0x1E<<4);
								rGPIOC->ODR = rGPIOC->ODR & ~(0xF<<8);} break;
		}
}

		