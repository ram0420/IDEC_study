/***** KEY test *****/
 #include "sfr.h"


void key_init()
{
	//clk enable port-a, port-b
	rCC_APB2ENR = rCC_APB2ENR | (0x1<<3)|(0x1<<2);
	 
	// key UD input setting (pb0, pb1)
	rGPIOB->CRL = rGPIOB->CRL & ~((0xF << 0)|(0xF << 1));
	rGPIOB->CRL = rGPIOB->CRL | (0x3 << 0)|(0x3 << 1);
	
	// key CLR input setting (pa2, pa3, pa4)
	rGPIOA->CRL = rGPIOA->CRL & ~((0xF << 2)|(0xF << 3)|(0xF << 4));
	rGPIOA->CRL = rGPIOA->CRL | (0x3 << 2)|(0x3 << 3)|(0x3 << 4);
}