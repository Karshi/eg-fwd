#include "intctrl.h"
#include "port_driver.h"
//#include "gpio.h"


Port_ConfigType portConfig[] =
	{
		{PA6, GPIO, LOW, OUTPUT, PULL_DOWN, STRENGTH_2MA}
	};
		
uint32_t Port_count = sizeof(portConfig)/sizeof(portConfig[0]);

int main(void)
{
	IntCtrl_init();

	Port_Init(portConfig);
	
	while(1)
	{
//		for(int i = 0; i < 1000000; i++)
//		{
//			GPIOA->DATA ^= 1UL<<TEST_PIN;
//		}
	}
}
