/***** exti.c *****/
#include <stdio.h>
#include "sfr.h"
#include "main.h"

extern unsigned int gTickCount;
extern unsigned int gTickCount2;

extern unsigned int paused;
extern unsigned int pressed;

unsigned int keyPressed = 0;

extern unsigned int led_toggle_msec;

void exti_0_isr()
{
	rEXTI_PR = (1<<0);
	
	printf("%s \r\n", __func__);
}

void exti_1_isr()
{
	rEXTI_PR = (1<<1);
	gTickCount2 = 500;
	printf("%s \r\n", __func__);
}


/*	center key 
1. pause/restart 
2. push 5sec -> reset 
*/
void exti_2_isr()
{
	rEXTI_PR = (1<<2);
	paused ++; // pause/restart 
	pressed = ~pressed;
	printf("%s \r\n", __func__);
}

void exti_3_isr()
{
	rEXTI_PR = (1<<3);
	led_toggle_msec = 103;
	printf("%s \r\n", __func__);
}
void exti_4_isr()
{
	rEXTI_PR = (1<<4);
	//led_toggle_msec = 200;
	printf("%s \r\n", __func__);
}

void exti_init()
{
	// clk enable afio
	rRCC_APB2ENR = rCC_APB2ENR | (0x1<<0);
	
	// enable irq6 ~ irq10
	*(int*) 0xE000E100 = (0x1F << 6);
	
	//pb0 (ext1), pb1 (ext1), pa2(ext2)...
	rAFIO_EXTICR1 = 0x0011;
	
	//pa4(exti4), mux
	rAFIO_EXTICR2 = rAFIO_EXTICR2 & ~(0x1F << 0);
	
	//falling & rising edge trigger
	rEXTI_FTSR = rEXTI_FTSR |(0x1F<<0);
	rEXTI_RTSR = rEXTI_RTSR | (0x1F << 0);
	
	//enable exti4 ~ exti0
	rEXTI_IMR = rEXTI_IMR | (0x1F <<0);
	
	// priority of irq10 (3)
	*(int*) 0xE000E40A = 0x3<<4;
}
