#include "systick.h"
#include "intctrl.h"
#include "port_driver.h"
#include "gpio.h"


void test(void)
{
	uint32_t justatest = 1;
}

int main(void)
{
	SysTick_Init();
	SysTick_RegisterCallback(test);
	
	IntCtrl_init();

	Port_Init(portConfig);
	
	SysTick_StartTimer(MAXIMUM_TICKS);
	
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
