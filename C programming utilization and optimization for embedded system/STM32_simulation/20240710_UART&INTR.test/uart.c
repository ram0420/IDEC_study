/***** uart.c *****/

#include "sfr.h"


void uart_init()
{
	// enable port-a, uart
	rRCC_APB2ENR = rRCC_APB2ENR | (0x1<<14) | (0x1<<2);
	// PA9 --> uart-tx
	rGPIOA_CRH = (rGPIOA_CRH & ~ (0xF<<4)) | (0xB<<4);
	// baud rate
	rUSART1_BRR = SYS_CLOCK / 115200;
	// TE, RE, UART Enable
	rUSART1_CR1 = rUSART1_CR1 | (0x1<<13) | (0x1<<3) | (0x1<<2);
}

void uart_sendbyte(unsigned char c)
{
	while ((rUSART1_SR & (0x1<<7))==0);
	rUSART1_DR = c;
}


unsigned char uart_readbyte()
{
	while ((rUSART1_SR & (0x1<<5))==0);
	return rUSART1_DR;
}