/***** sfr.h *****/

#ifndef __SFR_H__
#define __SFR_H__


#define rCC_APB2ENR (*(int *) 0x40021018)

	
#define rSCSR (*(int*) 0xE000E010)
#define rSRVR (*(int*) 0xE000E014)
#define rSCVR (*(int*) 0xE000E018)
	

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


#endif
