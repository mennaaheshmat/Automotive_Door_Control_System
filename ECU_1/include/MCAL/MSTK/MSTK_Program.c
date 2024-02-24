/*
 *  Author: Mennat-Allah Heshmat
 *  Date: 25 May 2023 
 *  MSTK_Program.h
 */



/*************************** Standard Types LIB ****************************/
#include "../LIB/LSTD_TYPES.h"
#include "../LIB/LBIT_MATH.h"


/****************************** MCAL Components *****************************/
#include "MSTK_Private.h"
#include "MSTK_Interface.h"
#include "MSTK_Config.h"


/************************* Functions Implementations *************************/
/*******************************************************************************************************/
/*                                      01- MSTK_voidInit                                              */
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/



void MSTK_voidInit(void)
{

	/* Disable Systick Interrupt - Stop Systick - CLOCK Source = AHB / 8 */
	MSTK->CTRL = 0x00000000 ;   //Clr_ALL_BITS(MSTK->CTRL) ;


}
/*******************************************************************************************************/
/*                                      02- MSTK_voidStart                                             */
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MSTK_voidStart(u32 Copy_u32PreloadValue)
{

	/*Clock Source -> HSI = 16 MHz -> AHB = 16MHz -> STK Clock Source = AHB / 8 ->  2MHz
	 * 2 MicroSecond For Each Count */

	/*Load Reload Value*/
	MSTK->LOAD = Copy_u32PreloadValue ;

	/*Clear val Register*/
	MSTK->VAL  = 0 ;

	/*Enable Systick*/
	SET_BIT(MSTK->CTRL,MSTK_ENABLE_BIT);

}
/*******************************************************************************************************/
/*                                      03- MSTK_voidDelayMs                                           */
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MSTK_voidDelayMs(u32 Copy_u32DelayMs)
{

	/*Disable Interupt*/
	MSTK_voidInit() ;      //function call
	MSTK_voidCtrlIntState(MSTK_INT_DISABLE) ;
	MSTK_voidStart(Copy_u32DelayMs * 2000) ;
	/*wait flag Polling*/
	while(MSTK_u8ReadFlag() == 0) ;

}
/*******************************************************************************************************/
/*                                      04- MSTK_voidDelayUs                                           */
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MSTK_voidDelayUs(u32 Copy_u32DelayUs)
{
	if(Copy_u32DelayUs >= 2)
	{
		/*Disable Interupt*/
		MSTK_voidInit() ;
		MSTK_voidCtrlIntState(MSTK_INT_DISABLE) ;
		MSTK_voidStart(Copy_u32DelayUs * 2) ;
		/*wait flag Polling*/
		while(MSTK_u8ReadFlag() == 0) ;
	}

}
/*******************************************************************************************************/
/*                                      05- MSTK_u8ReadFlag                                            */
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
u8 MSTK_u8ReadFlag(void)
{
	return (GET_BIT(MSTK->CTRL , 16)) ;
}
/*******************************************************************************************************/
/*                                      06- MSTK_voidCtrlIntState                                      */
/* 1- Function Description ->                                                                          */
/* 2- Function Input                                                                                   */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MSTK_voidCtrlIntState(u8 Copy_u8IntStatus)
{

	//   if(Copy_u8IntStatus == MSTK_INT_ENABLE)
	//   {
	//	   SET_BIT(MSTK->CTRL,1) ;
	//   }
	//   else
	//   {
	//	   CLR_BIT(MSTK->CTRL,1) ;
	//   }

	MSTK->CTRL &= ~(1<<1) ;
	MSTK->CTRL |= (Copy_u8IntStatus << 1 ) ;
}
