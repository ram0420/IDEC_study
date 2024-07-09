/***** led.c *****/

 #include "sfr.h"
 
 void led_init()
 {
	 //	pa5,6,7 output setting
	rGPIOA->CRL = rGPIOA->CRL & ~((0xF << 20)|(0xF << 24)|(0xF << 28));
	rGPIOA->CRL = rGPIOA->CRL | (0x3 << 20)|(0x3 << 24)|(0x3 << 28);
	
	// pa8 output setting
	rGPIOA->CRH = rGPIOA->CRH & ~((0xF << 0));
	rGPIOA->CRH = rGPIOA->CRH | (0x3 << 0);
	 
	// pc8,9,10,11 output setting
	rGPIOC->CRH = rGPIOC->CRH & ~((0xF << 0)|(0xF << 4)|(0xF << 8)|(0xF << 12));
	rGPIOC->CRH = rGPIOC->CRH | ((0x3 << 0)|(0x3 << 4)|(0x3 << 8)|(0x3 << 12));
 }
