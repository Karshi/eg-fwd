#include "intctrl.h"
#include "port_driver.h"
#include "gpio.h"

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
		
uint32_t Port_count = sizeof(portConfig)/sizeof(portConfig[0]);

int main(void)
{
	IntCtrl_init();

	Port_Init(portConfig);
	
	while(1)
	{
		Dio_PortLevelType portLevel;
		Dio_LevelType returnLevel;
		Dio_LevelType level;
		
		Dio_WriteChannel(PA1, HIGH);
		
		Dio_WritePort(0, 85);	//0b01010101
		
		level = Dio_ReadChannel(PA6);
		
		portLevel = Dio_ReadPort(0);
		
		returnLevel = Dio_FlipChannel(PA6);
	}
}
