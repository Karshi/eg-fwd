#ifndef __GPIO_H
#define __GPIO_H

#include <stdint.h>
#include "register_map.h"

#define __IO volatile
	
typedef struct
{
	__IO	uint32_t	DATA_MAP[255];							/* DATA virtual map	*/
	__IO	uint32_t	DATA;
	__IO	uint32_t	DIR;
	__IO	uint32_t	IS;
	__IO	uint32_t	IBE;
	__IO	uint32_t	IEW;
	__IO	uint32_t	IM;
	__IO	uint32_t	RIS;
	__IO	uint32_t	MIS;
	__IO	uint32_t	ICR;
	__IO	uint32_t	AFSEL;
	__IO	uint32_t	RESERVED2[55];							/*	(0x500 - 0x424)/4	*/
	__IO	uint32_t	DR2R;
	__IO	uint32_t	DR4R;
	__IO	uint32_t	DR8R;
	__IO	uint32_t	ODR;
	__IO	uint32_t	PUR;
	__IO	uint32_t	PDR;
	__IO	uint32_t	SLR;
	__IO	uint32_t	DEN;
	__IO	uint32_t	LOCK;
	__IO	uint32_t	CR;
	__IO	uint32_t	AMSEL;
	__IO	uint32_t	PCTL;
	__IO	uint32_t	ADCCTL;
	__IO	uint32_t	DMACTL;
} GPIO_Type;

typedef struct
{
	__IO	uint32_t	TODO[24];
	__IO	uint32_t	RCC;
	__IO	uint32_t	RESERVED[2];
	__IO	uint32_t	GPIOHBCTL;
	__IO	uint32_t	RCC2;
	__IO	uint32_t	TODO2[357];
	__IO	uint32_t	RCGCGPIO;
	__IO	uint32_t	TODO3[255];
	__IO	uint32_t	PRGPIO;
	__IO	uint32_t	TODO4[20];
} SYSCTL_Type;

#define	GPIOA				((GPIO_Type		*)	GPIOA_BASE)
#define	GPIOB				((GPIO_Type		*)	GPIOB_BASE)
#define	GPIOC				((GPIO_Type		*)	GPIOC_BASE)
#define	GPIOD				((GPIO_Type		*)	GPIOD_BASE)
#define	GPIOE				((GPIO_Type		*)	GPIOE_BASE)
#define	GPIOF				((GPIO_Type		*)	GPIOF_BASE)
#define	GPIOA_AHB		((GPIO_Type		*)	GPIOA_AHB_BASE)
#define	GPIOB_AHB		((GPIO_Type		*)	GPIOB_AHB_BASE)
#define	GPIOC_AHB		((GPIO_Type		*)	GPIOC_AHB_BASE)
#define	GPIOD_AHB		((GPIO_Type		*)	GPIOD_AHB_BASE)
#define	GPIOE_AHB		((GPIO_Type		*)	GPIOE_AHB_BASE)
#define	GPIOF_AHB		((GPIO_Type		*)	GPIOF_AHB_BASE)

#define SYSCTL			((SYSCTL_Type	*)	SYSCTL_BASE)

enum PORT_INDEX
{
	PORTA = 1,
	PORTB = 2,
	PORTC = 4,
	PORTD = 8,
	PORTE = 16,
	PORTF = 32,
};

#define	BIT_BAND_WRITE_PERIPH(BIT_BAND_ADDRESS, BIT)	1UL<<(BIT_BAND_PERIPH_BASE + ((BIT_BAND_ADDRESS - PERIPH_BASE) * 32) + (BIT * 4))


#endif
