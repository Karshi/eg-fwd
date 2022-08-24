#include "intctrl.h"
//#include "gpio.h"

/* Testing with PA6 */
#define	TEST_PIN	6

int main(void)
{
	IntCtrl_init();
	
	/* Enable clock for GPIO port in RCGCGPIO */
//	SYSCTL->RCGCGPIO |= 1UL<<PORTA;
	
	/* Set the direction for the pin in GPIODIR, 1 OUTPUT, 0 INPUT */
//	GPIOA->DIR |= 1UL<<TEST_PIN;
	
	/* Configure GPIOAFSEL to program as GPIO or alternate pin */
//	GPIOA->AFSEL |= 0UL<<TEST_PIN;
	
	/* Set drive strength through GPIODR2R, GPIODR4R, and GPIODR8R */
//	GPIOA->DR2R |= 1UL<<TEST_PIN;		/* redundant as this is the default value */
	
	/* pull-up, pull-down, or open drain functionality through
the GPIOPUR, GPIOPDR, GPIOODR, and if needed slew rate in GPIOSLR */
	
	/* For digital IO, set the appropriate DEN bit in GPIODEN */
	/* For analog funtion, set GPIOAMSEL */
//	GPIOA->DEN |= 1UL<<TEST_PIN;
	/* For interrupts, program GPIOIS, GPIOIBE, GPIOEV, and GPIOIM (657)*/
	
	while(1)
	{
//		for(int i = 0; i < 1000000; i++)
//		{
//			GPIOA->DATA ^= 1UL<<TEST_PIN;
//		}
	}
}
