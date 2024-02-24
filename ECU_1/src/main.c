
#include "ASystem_Init.h"


int main ()
{

	ASystem_voidInit () ;

	ADoor_voidInit () ;

	ASystem_vodiUART  () ;

	ALights_voidControl () ;

	ASystem_voidLCD   () ;

	ASystem_voidMotor () ;



	while (1)
	{
		ASysTick_voidCheck() ; //LED ON ~ OFF
		LED_ON () ;
		AAlert_voidSys () ;

	}

	return 0 ;
}



