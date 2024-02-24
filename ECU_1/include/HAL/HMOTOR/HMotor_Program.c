/*
 * HMotor_Program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Mennat-Allah Heshmat
 */

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MRCC_Inteface.h"
#include "MGPIO_Interface.h"

#include "HMotor_Interface.h"
#include "HMotor_Config.h"





void HMotor_vidStart (HMotor_Direction_t Copy_uddtMotorDirection)
{
	MRCC_voidInitSystemClk () ;
	MRCC_voidEnablePeripheralClock (AHB1,MRCC_GPIOB);

	MGPIO_u8SetPinMode(Motor_Port,MGPIO_PIN1,MGPIO_MODE_OUTPUT);
	MGPIO_u8SetOutputType (Motor_Port,IN_2,MGPIO_OUTPUT_PUSH_PULL);
	MGPIO_u8SetOutputSpeed(Motor_Port,IN_2,MGPIO_SPEED_LOW);

	MGPIO_u8SetPinMode(Motor_Port,IN_1,MGPIO_MODE_OUTPUT);
	MGPIO_u8SetOutputType (Motor_Port,IN_1,MGPIO_OUTPUT_PUSH_PULL);
	MGPIO_u8SetOutputSpeed(Motor_Port,IN_1,MGPIO_SPEED_LOW);

	switch (Copy_uddtMotorDirection)
	{


	case ClockWise :

		MGPIO_u8SetPinValue(Motor_Port,IN_2,MGPIO_HIGH_VALUE) ;
		MGPIO_u8SetPinValue(Motor_Port,IN_1,MGPIO_LOW_VALUE) ;

		break ;

	case AntiClockWise:

		MGPIO_u8SetPinValue(Motor_Port,IN_2,MGPIO_LOW_VALUE) ;
		MGPIO_u8SetPinValue(Motor_Port,IN_1,MGPIO_HIGH_VALUE) ;

		break;
	}//switch

}//Function

void HMotor_vidStop (void)
{
	MGPIO_u8SetPinValue(Motor_Port,IN_1,MGPIO_LOW_VALUE) ;
	MGPIO_u8SetPinValue(Motor_Port,IN_2,MGPIO_LOW_VALUE) ;
}


