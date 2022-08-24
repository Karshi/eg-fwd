#ifndef __INTCTRL_H
#define __INTCTRL_H

#include <stdint.h>
#include "intctrl_types.h"
#include "mcu_hw.h"

typedef struct
{
	IntCtrl_InterruptType				interrupt;
	IntCtrl_EnableType					enable;
	IntCtrl_PriorityLevelType		priority;
} NVIC_Config;

void IntCtrl_init(void);
void IntCtrl_enable(IntCtrl_InterruptType IRQn);
void IntCtrl_disable(IntCtrl_InterruptType IRQn);
void IntCtrl_setPriorityGrouping(uint32_t priorityGrouping);
void IntCtrl_setPriority(IntCtrl_InterruptType IRQn, uint8_t priority);

#endif
