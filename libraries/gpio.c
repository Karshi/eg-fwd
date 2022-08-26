#include "gpio.h"

//#define BITMASKING

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	uint8_t			pinOffset = ChannelId & 7;
	uint8_t			portIndex = ChannelId >> 3;
	GPIO_Type*	port      = Port_GPIO[portIndex];
	#ifdef BITMASKING
	return BIT_BAND_PERIPH(port->DATA_MAP[1UL<<pinOffset], pinOffset) ? HIGH : LOW;
	#else
	return BIT_BAND_PERIPH(port->DATA, pinOffset) ? HIGH : LOW;
	#endif
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	uint8_t			pinOffset = ChannelId & 7;
	uint8_t			portIndex = ChannelId >> 3;
	GPIO_Type*	port      = Port_GPIO[portIndex];
	
	// port->DATA_MAP[1UL<<pinOffset] = (uint32_t)Level << pinOffset;
	
	/* Bit-Banding write to single channel */	
	#ifdef BITMASKING
	BIT_BAND_PERIPH(port->DATA_MAP[1UL<<pinOffset], pinOffset) = Level;
	#else
	BIT_BAND_PERIPH(port->DATA, pinOffset) = Level;
	#endif
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	return (Dio_PortLevelType) Port_GPIO[PortId]->DATA;
}

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
	Port_GPIO[PortId]->DATA = Level;
}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	uint8_t			pinOffset = ChannelId & 7;
	uint8_t			portIndex = ChannelId >> 3;
	GPIO_Type*	port      = Port_GPIO[portIndex];
	#ifdef BITMASKING
//	port->DATA_MAP[1UL<<pinOffset] ^= 1UL << pinOffset;
	BIT_BAND_PERIPH(port->DATA_MAP[1UL<<pinOffset], pinOffset) ^= 1UL;
	return BIT_BAND_PERIPH(port->DATA_MAP[1UL<<pinOffset], pinOffset) ? HIGH : LOW;
	#else
	BIT_BAND_PERIPH(port->DATA, pinOffset) ^= 1UL;
	return BIT_BAND_PERIPH(port->DATA, pinOffset) ? HIGH : LOW;
	#endif
}
