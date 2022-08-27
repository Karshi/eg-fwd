#include "port_driver.h"

void Port_Init(const Port_ConfigType* ConfigPtr)
{
	/* TODO check for special ports that require locks and unlock */
	
	for (uint32_t i = 0; i < Port_count; i++)
	{
		uint8_t			pinOffset = ConfigPtr[i].PortChannelID & 7;
		uint8_t			portIndex = ConfigPtr[i].PortChannelID >> 3;
		GPIO_Type*	port      = Port_GPIO[portIndex];
		
		/* Enable clock for GPIO port in RCGCGPIO */
//		SYSCTL->RCGCGPIO |= 1UL << portIndex;
		BIT_BAND_PERIPH_SET(SYSCTL->RCGCGPIO, portIndex);
		
		/* Set the direction for the pin in GPIODIR, 1 OUTPUT, 0 INPUT */
//		port->DIR 		|= (uint32_t)ConfigPtr[i].PortPinDirection << pinOffset;
		BIT_BAND_PERIPH(port->DIR, pinOffset) = (uint32_t)ConfigPtr[i].PortPinDirection;
		
		/* Configure GPIOAFSEL to program as GPIO or alternate pin */
//		port->AFSEL 	|= (uint32_t)ConfigPtr[i].PortPinMode << pinOffset;
		BIT_BAND_PERIPH(port->AFSEL, pinOffset) = (uint32_t)ConfigPtr[i].PortPinMode;
		
		/* Set drive strength through GPIODR2R, GPIODR4R, and GPIODR8R */
		switch(ConfigPtr[i].PortPinOutputCurrent)
		{
			case STRENGTH_2MA:
//				port->DR2R |= 1UL << pinOffset;
				BIT_BAND_PERIPH_SET(port->DR2R, pinOffset);
				break;
			case STRENGTH_4MA:
//				port->DR4R |= 1UL << pinOffset;
				BIT_BAND_PERIPH_SET(port->DR4R, pinOffset);
				break;
			case STRENGTH_8MA:
//				port->DR8R |= 1UL << pinOffset;
				BIT_BAND_PERIPH_SET(port->DR8R, pinOffset);
				break;
			case STRENGTH_8MA_SR:
//				port->DR8R |= 1UL << pinOffset;
//				port->SLR 	|= 1UL << pinOffset;
				BIT_BAND_PERIPH_SET(port->DR8R, pinOffset);
				BIT_BAND_PERIPH_SET(port->SLR, pinOffset);
				break;
		}
		
		/* pull-up, pull-down, or open drain functionality through
		 * the GPIOPUR, GPIOPDR, GPIOODR
		 */
		switch(ConfigPtr[i].PortPinInternalAttach)
		{
			case PULL_UP:
//				port->PUR |= 1UL << pinOffset;
				BIT_BAND_PERIPH_SET(port->PUR, pinOffset);
				break;
			case PULL_DOWN:
//				port->PDR |= 1UL << pinOffset;
				BIT_BAND_PERIPH_SET(port->PDR, pinOffset);
				break;
			case OPEN_DRAIN:
//				port->ODR |= 1UL << pinOffset;
				BIT_BAND_PERIPH_SET(port->ODR, pinOffset);
				break;
		}
		
		/* In case of output GPIO, set the output level */
		if (ConfigPtr[i].PortPinDirection && !ConfigPtr[i].PortPinMode)
		{
			#ifdef BITMASKING
			BIT_BAND_PERIPH(port->DATA_MAP[1UL<<pinOffset], pinOffset) = ConfigPtr[i].PortPinLevelValue;
			#else
			BIT_BAND_PERIPH(port->DATA, pinOffset) = ConfigPtr[i].PortPinLevelValue;
			#endif
		}
	}
}
