#include "intctrl.h"



void IntCtrl_init(void)
{
	
}

void IntCtrl_enable(IntCtrl_InterruptType IRQn)
{
	if (IRQn == MEM_MGMT_IRQn)
	{
		/*	Enable the memory management fault exception (datasheet p.174)	*/
		SCB->SYSHNDCTRL	|=	SCB_SYSHNDCTRL_MEM;
	}
	else if (IRQn == BUS_FAULT_IRQn)
	{
		/*	Enable the bus fault exception (datasheet p.173)	*/
		SCB->SYSHNDCTRL	|=	SCB_SYSHNDCTRL_BUS;
	}
	else if (IRQn == USAGE_FAULT_IRQn)
	{
		/*	Enable the usage fault exception (datasheet p.173)	*/
		SCB->SYSHNDCTRL	|=	SCB_SYSHNDCTRL_USAGE;
	}
	else if (IRQn == SYSTICK_IRQn)
	{
		/*	Enable the SysTick interrupt generation (datasheet p.139)	*/
		SYSTICK->STCTRL	|=	SYSTICK_STCTRL_INTEN;
	}
	/*	Set the ENx register for the interrupt type (datasheet p.142)	*/
	else if (IRQn >= 0)
	{
		NVIC->EN[IRQn/32]	=	1UL	<<	(IRQn	&	31);
	}
}

void IntCtrl_disable(IntCtrl_InterruptType IRQn)
{
	
}

void IntCtrl_setPriorityGrouping(uint32_t priorityGrouping)
{
	/*	Write to APINT to set the priority level (datasheet p.164)	*/
	SCB->APINT	=		APINT_KEY_MASK	|	(priorityGrouping	<<	8U);
}

void IntCtrl_setPriority(IntCtrl_InterruptType IRQn, uint8_t priority)
{
	
}