#ifndef __GPIO_H
#define __GPIO_H

#include <stdint.h>
#include "port_driver.h"

typedef Port_ChannelType Dio_ChannelType;
typedef uint8_t Dio_PortType;
typedef Port_PinLevelType Dio_LevelType;
typedef uint8_t Dio_PortLevelType;

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

#endif
