/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  gpio_cfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "port_types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**
 * Create an array of desired port configurations
 * Struct format: { Channel ID, Mode (GPIO|ALT), Output Level (HIGH|LOW), 
 *									Direction (INPUT|OUTPUT), ATTACHEMENT (PULL_DOWN|PULL_UP|OPEN_DRAIN) 
 *									Output current (STRENGTH_2MA|STRENGTH_4MA|STRENGTH_8MA|STRENGTH_8MA_SR)} 
 */
Port_ConfigType portConfig[] =
	{
		{PA0,	GPIO,	LOW,	OUTPUT,	PULL_DOWN,	STRENGTH_2MA},
		{PA1,	GPIO,	LOW,	OUTPUT,	PULL_DOWN,	STRENGTH_2MA},
		{PA2,	GPIO,	LOW,	OUTPUT,	PULL_DOWN,	STRENGTH_2MA},
		{PA3,	GPIO,	LOW,	OUTPUT,	PULL_DOWN,	STRENGTH_2MA},
		{PA6,	GPIO,	LOW,	OUTPUT,	PULL_DOWN,	STRENGTH_2MA},
		{PE2,	GPIO,	LOW,	OUTPUT,	OPEN_DRAIN,	STRENGTH_4MA},
		{PF3,	GPIO,	LOW,	INPUT,	PULL_UP,		STRENGTH_8MA}
	};
		

/* Calculating the size of the array */
uint32_t Port_count = sizeof(portConfig)/sizeof(portConfig[0]);
/**********************************************************************************************************************
 *  END OF FILE: gpio_cfg.c
 *********************************************************************************************************************/
