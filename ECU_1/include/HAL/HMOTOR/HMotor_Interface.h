/*
 * HMotor_Interface.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Mennat-Allah Heshmat
 */

#ifndef  _HMOTOR_INTERFACE_H_
#define  _HMOTOR_INTERFACE_H_ 


typedef enum 
{
	ClockWise = 0 ,
	AntiClockWise
	
}HMotor_Direction_t ;


void HMotor_vidStart (HMotor_Direction_t Copy_uddtMotorDirection) ;

void HMotor_vidStop (void) ;





#endif