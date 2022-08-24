#ifndef __MCU_HW_H
#define __MCU_HW_H

#include <stdint.h>
#include "register_map.h"

#define __IO volatile

#define	APINT_KEY				0xFA05UL
#define APINT_KEY_POS		16
#define	APINT_KEY_MASK	(APINT_KEY	<<	APINT_KEY_POS)

typedef struct
{
  __IO	uint32_t	STCTRL;
	__IO	uint32_t	STRELOAD;
	__IO	uint32_t	STCURRENT;
} SYSTICK_Type;

#define	SYSTICK_STCTRL_ENABLE		0x00000001
#define	SYSTICK_STCTRL_INTEN		0x00000002
#define	SYSTICK_STCTRL_CLK_SRC	0x00000004

typedef struct
{
  __IO	uint32_t	CPUID;
  __IO	uint32_t	INTCTRL;
  __IO	uint32_t	VTABLE;
  __IO	uint32_t	APINT;
  __IO	uint32_t	SYSCTRL;
  __IO	uint32_t	CFGCTRL;
  __IO	uint32_t	SYSPRI1;
	__IO	uint32_t	SYSPRI2;
	__IO	uint32_t	SYSPRI3;
  __IO	uint32_t	SYSHNDCTRL;
  __IO	uint32_t	FAULTSTAT;
  __IO	uint32_t	HFAULTSTAT;
  __IO	uint32_t	RESERVED0;
  __IO	uint32_t	MMADDR;
  __IO	uint32_t	FAULTADDR;
} SCB_Type;

#define SCB_SYSHNDCTRL_MEM		0x00010000
#define SCB_SYSHNDCTRL_BUS		0x00020000
#define SCB_SYSHNDCTRL_USAGE	0x00040000

typedef struct
{
	__IO	uint32_t	EN[5];
	__IO	uint32_t	RESERVED0[27];
	__IO	uint32_t	DIS[5];
	__IO	uint32_t	RESERVED1[27];
	__IO	uint32_t	PEND[5];
	__IO	uint32_t	RESERVED2[27];
	__IO	uint32_t	UNPEND[5];
	__IO	uint32_t	RESERVED3[27];
	__IO	uint32_t	ACTIVE[5];
	__IO	uint32_t	RESERVED4[59];
	__IO	uint32_t	PRI[35];
	__IO	uint32_t	RESERVED5[669];
	__IO	uint32_t	SWTRIG;
} NVIC_Type;

#define	SYSTICK		((SYSTICK_Type	*)	SYSTICK_BASE)
#define	SCB				((SCB_Type			*)	SCB_BASE)
#define	NVIC			((NVIC_Type			*)	NVIC_BASE)

#endif
