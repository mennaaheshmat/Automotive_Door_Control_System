/*
 *  Author: Mennat-Allah Heshmat
 *  Date: 25 May 2023 
 *  MGPIO_Program.c
 */
 
#include "../LIB/LSTD_TYPES.h"
#include "../LIB/LBIT_MATH.h"

#include "MGPIO_Interface.h"
#include "MGPIO_Private.h"
#include "MGPIO_Config.h"


u8 MGPIO_u8SetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode)
{
	u8 Local_u8CopyReturnState = 0;
	if (Copy_u8PinNumber < 16)
	{
		switch (Copy_u8PortName)
		{
			case MGPIOA_PORT: MGPIOA->MODER |=  (u32)(Copy_u8PinMode << (2*Copy_u8PinNumber));	break;
			case MGPIOB_PORT: MGPIOB->MODER |=  (u32)(Copy_u8PinMode << (2*Copy_u8PinNumber));	break;
			case MGPIOC_PORT: MGPIOC->MODER |=  (u32)(Copy_u8PinMode << (2*Copy_u8PinNumber));	break;
			default: Local_u8CopyReturnState = 2;

		}
	}
	else
	{
		/* return error state */
		Local_u8CopyReturnState = 1;
	}
	return Local_u8CopyReturnState;
}
	
u8 MGPIO_u8SetOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8TypeMode)
{
	u8 Local_u8CopyReturnState = 0;
	if (Copy_u8PinNumber < 16)
	{
		switch (Copy_u8PortName)
		{
			case MGPIOA_PORT: MGPIOA->OTYPER |=  (u32)(Copy_u8TypeMode << (2*Copy_u8PinNumber));	break;
			case MGPIOB_PORT: MGPIOB->OTYPER |=  (u32)(Copy_u8TypeMode << (2*Copy_u8PinNumber));	break;
			case MGPIOC_PORT: MGPIOC->OTYPER |=  (u32)(Copy_u8TypeMode << (2*Copy_u8PinNumber));	break;
			default: Local_u8CopyReturnState = 2;

		}
	}
	else
	{
		/* return error state */
		Local_u8CopyReturnState = 1;
	}
	return Local_u8CopyReturnState;
}

u8 MGPIO_u8SetOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8SpeedMode)
{
	u8 Local_u8CopyReturnState = 0;
	if (Copy_u8PinNumber < 16)
	{
		switch (Copy_u8PortName)
		{
			case MGPIOA_PORT: MGPIOA->OSPEEDR |=  (u32)(Copy_u8SpeedMode << (2*Copy_u8PinNumber));	break;
			case MGPIOB_PORT: MGPIOB->OSPEEDR |=  (u32)(Copy_u8SpeedMode << (2*Copy_u8PinNumber));	break;
			case MGPIOC_PORT: MGPIOC->OSPEEDR |=  (u32)(Copy_u8SpeedMode << (2*Copy_u8PinNumber));	break;
			default: Local_u8CopyReturnState = 2;

		}
	}
	else
	{
		/* return error state */
		Local_u8CopyReturnState = 1;
	}
	return Local_u8CopyReturnState;
}
u8 MGPIO_u8SetPullState(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PullMode)
{
	u8 Local_u8CopyReturnState = 0;
	if (Copy_u8PinNumber < 16)
	{
		switch (Copy_u8PortName)
		{
			case MGPIOA_PORT: MGPIOA->PUPDR |=  (u32)(Copy_u8PullMode << (2*Copy_u8PinNumber));	break;
			case MGPIOB_PORT: MGPIOB->PUPDR |=  (u32)(Copy_u8PullMode << (2*Copy_u8PinNumber));	break;
			case MGPIOC_PORT: MGPIOC->PUPDR |=  (u32)(Copy_u8PullMode << (2*Copy_u8PinNumber));	break;
			default: Local_u8CopyReturnState = 2;

		}
	}
	else
	{
		/* return error state */
		Local_u8CopyReturnState = 1;
	}
	return Local_u8CopyReturnState;
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
	u8 Local_u8CopyPinValue = 0;
		switch (Copy_u8PortName)
		{
			case MGPIOA_PORT:Local_u8CopyPinValue =   GET_BIT(MGPIOA->IDR,Copy_u8PinNumber);	break;
			case MGPIOB_PORT:Local_u8CopyPinValue =   GET_BIT(MGPIOB->IDR,Copy_u8PinNumber);	break;
			case MGPIOC_PORT:Local_u8CopyPinValue =   GET_BIT(MGPIOC->IDR,Copy_u8PinNumber);	break;
			default: ;
		}
		return Local_u8CopyPinValue;
}
u8 MGPIO_u8SetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
	u8 Local_u8CopyReturnState = 0;
	if (Copy_u8PinNumber < 16)
	{
		if ( Copy_u8PinValue == MGPIO_HIGH_VALUE)
		switch (Copy_u8PortName)
		{
			case MGPIOA_PORT: SET_BIT(MGPIOA->ODR, Copy_u8PinNumber);	break;
			case MGPIOB_PORT: SET_BIT(MGPIOB->ODR, Copy_u8PinNumber);	break;			
			case MGPIOC_PORT: SET_BIT(MGPIOC->ODR, Copy_u8PinNumber);	break;		
			
			default: Local_u8CopyReturnState = 2;

		}
		else
		{
			switch (Copy_u8PortName)
			{
			case MGPIOA_PORT: CLR_BIT(MGPIOA->ODR, Copy_u8PinNumber);	break;
			case MGPIOB_PORT: CLR_BIT(MGPIOB->ODR, Copy_u8PinNumber);	break;			
			case MGPIOC_PORT: CLR_BIT(MGPIOC->ODR, Copy_u8PinNumber);	break;		
			default: Local_u8CopyReturnState = 2;
			}
		}
	}
	else
	{
		/* return error state */
		Local_u8CopyReturnState = 1;
	}
	return Local_u8CopyReturnState;
}

u8 MGPIO_u8SetResetDirectValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
		u8 Local_u8CopyReturnState = 0;
	if (Copy_u8PinNumber < 16)
	{
		if ( Copy_u8PinValue == MGPIO_HIGH_VALUE)
		switch (Copy_u8PortName)
		{
			case MGPIOA_PORT: MGPIOA->BSRR = (1<<Copy_u8PinNumber); 	break;
			case MGPIOB_PORT: MGPIOB->BSRR = (1<<Copy_u8PinNumber);		break;
			case MGPIOC_PORT: MGPIOC->BSRR = (1<<Copy_u8PinNumber);		break;
			
			default: Local_u8CopyReturnState = 2;

		}
		else
		{
			Copy_u8PinNumber += 16;
			switch (Copy_u8PortName)
			{
			case MGPIOA_PORT: MGPIOA->BSRR = (1<<Copy_u8PinNumber);		break;
			case MGPIOB_PORT: MGPIOB->BSRR = (1<<Copy_u8PinNumber);		break;
			case MGPIOC_PORT: MGPIOC->BSRR = (1<<Copy_u8PinNumber);		break;
			default: Local_u8CopyReturnState = 2;
			}
		}
	}
	else
	{
		/* return error state */
		Local_u8CopyReturnState = 1;
	}
	return Local_u8CopyReturnState;
}

void MGPIO_voidSetPinAltFun(u8 Copy_u8PortName ,u8 Copy_u8PinNum, u8 Copy_u8AlFun)
{
	if(Copy_u8PinNum <=7U)
	{
		switch(Copy_u8PortName)
		{
		case MGPIOA_PORT:MGPIOA->AFRL  |=(u32)(Copy_u8AlFun << (4U*Copy_u8PinNum)) ; break ;
		case MGPIOB_PORT:MGPIOB->AFRL  |=(u32)(Copy_u8AlFun << (4U*Copy_u8PinNum)) ; break ;
		case MGPIOC_PORT:MGPIOC->AFRL  |=(u32)(Copy_u8AlFun << (4U*Copy_u8PinNum)) ; break ;
		default : break ;
		}
	}
	else
	{
		switch(Copy_u8PortName)
		{
		case MGPIOA_PORT:MGPIOA->AFRH  |=(u32)(Copy_u8AlFun << (4U*(Copy_u8PinNum%8))) ; break ;
		case MGPIOB_PORT:MGPIOB->AFRH  |=(u32)(Copy_u8AlFun << (4U*(Copy_u8PinNum%8))) ; break ;
		case MGPIOC_PORT:MGPIOC->AFRH  |=(u32)(Copy_u8AlFun << (4U*(Copy_u8PinNum%8))) ; break ;
		default : break ;
		}

	}
}

