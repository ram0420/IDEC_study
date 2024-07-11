#ifndef __SFR_H__
#define __SFR_H__


#define rCC_APB2ENR (*(int *) 0x40021018)

// GPIO
typedef struct
{
	unsigned int CRL;
	unsigned int CRH;
	unsigned int IDR;
	unsigned int ODR;
} sfr_t;

#define rGPIOA		((sfr_t *)0x40010800)
#define rGPIOB		((sfr_t *)0x40010C00)
#define rGPIOC		((sfr_t *)0x40011000)


// KEY 
#define key_U (rGPIOA->IDR & (0x1<<0))
#define key_D	(rGPIOA->IDR & (0x1<<1))
#define	key_C	(rGPIOA->IDR & (0x1<<2))
#define	key_L	(rGPIOA->IDR & (0x1<<3))
#define	key_R	(rGPIOA->IDR & (0x1<<4))



//  System Timer Tegisters
#define rSCSR (*(int*) 0xE000E010)
#define rSRVR (*(int*) 0xE000E014)
#define rSCVR (*(int*) 0xE000E018)
	


//	
#define SYS_CLOCK (72000000)
#define rRCC_APB2ENR (*(int *)0x40021018)
#define rGPIOA_CRH (*(int *)0x40010804)
#define rUSART1_SR (*(int *)0x40013800)
#define rUSART1_DR (*(int *)0x40013804)
#define rUSART1_BRR (*(int *)0x40013808)
#define rUSART1_CR1 (*(int *)0x4001380C)
	 

#define rAFIO_EXTICR1 (*(int *)0x40010008)
#define rAFIO_EXTICR2 (*(int *)0x4001000C)
	
#define rEXTI_IMR (*(int *)0x40010400)
#define rEXTI_FTSR (*(int *)0x4001040C)
#define rEXTI_RTSR (*(int *)0x40010408)
#define rEXTI_SWIER (*(int *)0x40010410)
#define rEXTI_PR (*(int *)0x40010414)

#endif

