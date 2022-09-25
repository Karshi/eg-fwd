#include "pseudo_pwm.h"

/* Time to turn ON/OFF in seconds */
float timer_on = 4;
float timer_off = 2;

int main(void)
{
	Port_PinLevelType SW1_lastState = HIGH;
	Port_PinLevelType SW2_lastState = HIGH;
	
	SysTick_Init();
	Port_Init( portConfig );
	IntCtrl_init();
	
	//pseudoPWM_init(T_ON, T_OFF);
	
	while(1)
	{
		Port_PinLevelType SW1_state = Dio_ReadChannel( PF4 );
		Port_PinLevelType SW2_state = Dio_ReadChannel( PF0 );
		
		/* Check for falling edge on SW1 */
		if( SW1_state == LOW && SW1_lastState != LOW )
		{
			SW1_lastState = LOW;
			timer_on = timer_on / 2;
			timer_off = timer_off / 2;
			pseudoPWM_init( timer_on, timer_off );
		}
		else if( SW1_state == HIGH && SW1_lastState != HIGH )
		{
			SW1_lastState = HIGH;
		}

		/* Check for falling edge on SW2 */
		if( SW2_state == LOW && SW2_lastState != LOW )
		{
			SW2_lastState = LOW;
			timer_on = timer_on * 2;
			timer_off = timer_off * 2;
			pseudoPWM_init( timer_on, timer_off );
		}
		else if( SW2_state == HIGH && SW2_lastState != HIGH )
		{
			SW2_lastState = HIGH;
		}
		
	}
}
