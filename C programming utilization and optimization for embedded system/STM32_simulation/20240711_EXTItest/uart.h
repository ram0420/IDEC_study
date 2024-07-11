#ifndef __UART_H__
#define __UART_H__

void uart_init(void);
void uart_sendbyte(char c);
unsigned char uart_readbyte(void);

#endif
