#ifndef __INTCTRL_H
#define __INTCTRL_H

#include <stdint.h>
#include "intctrl_types.h"
#include "mcu_hw.h"
#include "IntCtrl_Cfg.h"

extern NVIC_ConfigType NVIC_Config[];
extern uint32_t	IRQn_count;

void IntCtrl_init(void);

#endif
