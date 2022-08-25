#ifndef __GPIO_H
#define __GPIO_H

#include <stdint.h>

typedef uint32_t Dio_ChannelType;
typedef uint32_t Dio_PortType;
typedef uint32_t Dio_LevelType;
typedef uint32_t Dio_PortLevelType;

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

#endif
