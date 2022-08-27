#include "pseudo_pwm.h"

/* Time to turn ON/OFF in seconds */
#define T_ON		(float)1
#define T_OFF		(float)0.5

int main(void)
{

	pseudoPWM_init(T_ON, T_OFF);
	
	while(1)
	{
	}
}
