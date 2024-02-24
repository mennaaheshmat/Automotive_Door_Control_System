/*
 *  Author: Mennat-Allah Heshmat
 *  Date: 25 May 2023 
 *  MRCC_Program.c
 */
 
#include "../LIB/LSTD_TYPES.h"
#include "../LIB/LBIT_MATH.h"

/* Upper Layer Inclusion 			     	*/

/* Dependencies From Same Layer Inclusion   */

#include "MRCC_Inteface.h"
#include "MRCC_Private.h"
#include "MRCC_Config.h"


void MRCC_voidEnablePeripheralClock (MRCC_Bus_t Copy_uddtPeripheralBus, u32 Copy_u32PeripheralNumber)
{
	switch (Copy_uddtPeripheralBus)
	{
		case AHB1:	SET_BIT(MRCC_AHB1ENR, Copy_u32PeripheralNumber);	break;
		case APB1:	SET_BIT(MRCC_APB1ENR, Copy_u32PeripheralNumber);	break;
		case APB2:	SET_BIT(MRCC_APB2ENR, Copy_u32PeripheralNumber);	break;

		default: /* Rerun Erron State */;
	}
}

void MRCC_voidDisablePeripheralClock (MRCC_Bus_t Copy_uddtPeripheralBus, u32 Copy_u32PeripheralNumber)
{
	switch (Copy_uddtPeripheralBus)
	{
		case AHB1:	CLR_BIT(MRCC_AHB1ENR, Copy_u32PeripheralNumber);	break;
		case APB1:	CLR_BIT(MRCC_APB1ENR, Copy_u32PeripheralNumber);	break;
		case APB2:	CLR_BIT(MRCC_APB2ENR, Copy_u32PeripheralNumber);	break;
		default: /* Rerun Erron State */;
	}
} 

void MRCC_voidInitSystemClk (void)
{
	#if MRCC_CLOCK_SRC == MRCC_HSI
	
	/* Enable HSI */
	SET_BIT(MRCC_CR, 0);
	
	/* Select HSI As Clock Source */
	CLR_BIT(MRCC_CCFGR, 0);
	CLR_BIT(MRCC_CCFGR, 1);
	
	#elif MRCC_CLOCK_SRC == MRCC_HSE
		#if MRCC_HSE_SRC == MRCC_HSE_RC
		/* Enable HSE */
		SET_BIT(MRCC_CR, 16);
		
		/* Enable Bypass */
		SET_BIT(MRCC_CR, 18);
		
			/* Select HSE As Clock Source */
		SET_BIT(MRCC_CCFGR, 0);
		CLR_BIT(MRCC_CCFGR, 1);
		
		#elif MRCC_HSE_SRC == MRCC_HSE_CRYSTAL
		/* Enable HSE */
		SET_BIT(MRCC_CR, 16);
		
		/* Disable Bypass */
		CLR_BIT(MRCC_CR, 18);
		
		/* Select HSE As Clock Source */
		SET_BIT(MRCC_CCFGR, 0);
		CLR_BIT(MRCC_CCFGR, 1);
		#endif
}

