#include "systick.h"

static Callback_function SysTick_callback = NULL;
static SysTick_ClockSrcType clockSrc = SYSTICK_CLOCK_SRC;

void SysTick_Handler(void)
{
	if (SysTick_callback != NULL)
	{
		SysTick_callback();
	}
}

void SysTick_RegisterCallback(void(*Callback)(void))
{
	SysTick_callback = Callback;
}

void SysTick_Init(void)
{
	/* Set STRELOAD */
//	SYSTICK->STRELOAD = MAXIMUM_TICKS-1;
	/* Clear STCURRENT by writing any value to it */
	SYSTICK->STCURRENT = 0UL;
	/* Configure STCTRL */
	SYSTICK->STCTRL |= (uint32_t)clockSrc << SYSTICK_STCTRL_CLK_SRC_OFFSET;
}

void SysTick_StopTimer(void)
{
	/* Clear ENABLE bit in STCTRL register (datasheet p.139) */
	SYSTICK->STCTRL &= ~(1UL << SYSTICK_STCTRL_ENABLE_OFFSET);
}

void SysTick_StartTimer(SysTick_ValueType Value)
{
	if (Value > 0 && Value <= MAXIMUM_TICKS)
	{
		SYSTICK->STRELOAD = Value - 1;
		SYSTICK->STCURRENT = 0UL;
		SYSTICK->STCTRL |= 1UL << SYSTICK_STCTRL_ENABLE_OFFSET;
	}
}

//static uint32_t overflow_counter = 0;
//
//void SysTick_StartTimer(SysTick_ValueType Value)
//{
//	uint32_t ticks;
//	switch(clockSrc)
//	{
//		case PIOSC:
//			ticks = (uint32_t)(Value * PIOSC_FREQUENCY);
//			break;
//		
//		case SYSCLOCK:
//			ticks = (uint32_t)(Value * SYSCLOCK_FREQUENCY);
//			break;
//	}
//	if (ticks >= MAXIMUM_TICKS)
//	{
//		overflow_counter = ticks / MAXIMUM_TICKS;
//		SYSTICK->STRELOAD = MAXIMUM_TICKS - 1;
//	}
//	else
//	{
//		SYSTICK->STRELOAD = ticks - 1;
//	}
//	SYSTICK->STCTRL |= 1UL << SYSTICK_STCTRL_ENABLE_OFFSET;
//}
