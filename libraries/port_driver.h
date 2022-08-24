#ifndef __PORT_DRIVER_H
#define __PORT_DRIVER_H

#include <stdint.h>

typedef enum
{
	
} Port_PinModeType;


//typedef uint32_t Port_PinModeType;
typedef uint32_t Port_PinDirectionType;
typedef uint32_t Port_PinInternalAttachType;
typedef uint32_t Port_PinOutputCurrentType;

typedef struct
{
	Port_PinModeType						PortPinMode;
	_Bool												PortPinLevelValue;
	Port_PinDirectionType				PortPinDirection;
	Port_PinInternalAttachType	PortPinInternalAttach;
	Port_PinOutputCurrentType		PortPinOutputCurrent;
} Port_ConfigType;

void Port_Init(const Port_ConfigType* ConfigPtr);

#endif
