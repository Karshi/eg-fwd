/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  systick.h
 *       Module:  SysTick
 *
 *  Description:  header file for SysTick Module    
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_H
#define SYSTICK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <stdint.h>
#include <stddef.h>
#include "mcu_hw.h"
#include "systick_cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define MAXIMUM_TICKS 0x100000

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32_t SysTick_ValueType;
typedef void (*Callback_function)(void);

typedef enum
{
	PIOSC,
	SYSCLOCK
} SysTick_ClockSrcType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : SysTick_RegisterCallback(Callback_function callback_ptr)
* \Description     : Registers the callback function to the systick ISR                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Value                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_RegisterCallback(Callback_function Callback);

/******************************************************************************
* \Syntax          : void SysTick_StartTimer(SysTick_ValueType Value)
* \Description     : Starts the SysTick counting with the passed target counts                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Value                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_StartTimer(SysTick_ValueType Value);

/******************************************************************************
* \Syntax          : void SysTick_StopTimer(void)
* \Description     : Stops the SysTick counting                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_StopTimer(void);

/******************************************************************************
* \Syntax          : void SysTick_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClockSrc                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SysTick_Init(void);

#endif  /* SYSTICK_H */

/**********************************************************************************************************************
 *  END OF FILE: systick.h
 *********************************************************************************************************************/
