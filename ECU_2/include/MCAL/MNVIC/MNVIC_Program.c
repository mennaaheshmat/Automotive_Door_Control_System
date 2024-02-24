/*
 *  Author: Mennat-Allah Heshmat
 *  Date: 25 May 2023 
 *  MNVIC_Program.c
 */


/**************************** Standard Types LIB **********************************/
#include "../LIB/LSTD_TYPES.h"
#include "../LIB/LBIT_MATH.h"


/****************************** MCAL Components ***********************************/
#include "MNVIC_Private.h"
#include "MNVIC_Interface.h"
#include "MNVIC_Config.h"


/************************** Functions Implementations *****************************/
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntPos)
{
	//REMINDER: Check your notes app to remember the modules
   MNVIC_REG->ISER[Copy_u8IntPos/32] = (1U << (Copy_u8IntPos % 32 )) ;

}
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntPos)
{

	 MNVIC_REG->ICER[Copy_u8IntPos/32] = (1U << (Copy_u8IntPos % 32 )) ;

}
void MNVIC_voidEnableInterruptPending  (u8 Copy_u8IntPos)
{

	 MNVIC_REG->ISPR[Copy_u8IntPos/32] = (1U << (Copy_u8IntPos % 32 )) ;

}
void MNVIC_voidDisableInterruptPending  (u8 Copy_u8IntPos)
{

	 MNVIC_REG->ICPR[Copy_u8IntPos/32] = (1U << (Copy_u8IntPos % 32 )) ;

}
u8 MNVIC_u8IsInterruptActive (u8 Copy_u8IntPos)
{
     return  GIT_BIT(MNVIC_REG->IABR[Copy_u8IntPos/32],(Copy_u8IntPos % 32 )) ;
}
void MNVIC_voidSetInterruptPriority  (u8 Copy_u8IntPos ,MNVIC_GroupMode_t Copy_uddtGroupMode,u8 Copy_u8GroupNum,u8 Copy_u8SubGroupNum )
{
	/*
	REMINDER: 1- Case1: you have 0 group priorities and 16 sub-priorities so it sets sub-priority to priority value directly
			  2- Case2:	you have 16 group priorities and 0 sub-priorities so it sets group priority to priority value directly
			  3- Case3:	you have 4 group priorities and 4 sub-priorities which means values from 0~3 only for each,
					also the shifting number is 2 because the 4 bits of priority are divided into 2 group and 2 subs
			  4- Case4:	you have 2 group priorities and 8 sub-priorities which means group values 0~1 only and 
			  sub values 0~7, also the shifting number is 3 because the 4 bits of priority are divided into 
			  1 group and 3 subs.
			  5- Case5: same concept as first
	*/

 u8 LOC_u8PrioValue = 0 ;
  switch(Copy_uddtGroupMode)
  {
  case MNVIC_GROUPMODE_G0S16 :  LOC_u8PrioValue = Copy_u8SubGroupNum  ;  break ;
  case MNVIC_GROUPMODE_G16S0 :  LOC_u8PrioValue = Copy_u8GroupNum     ;  break ;
  case MNVIC_GROUPMODE_G4S4 :   LOC_u8PrioValue = (Copy_u8GroupNum<<2) | Copy_u8SubGroupNum    ;  break ;
  case MNVIC_GROUPMODE_G2S8 :   LOC_u8PrioValue = (Copy_u8GroupNum<<3) | Copy_u8SubGroupNum    ;  break ;
  case MNVIC_GROUPMODE_G8S2 :   LOC_u8PrioValue = (Copy_u8GroupNum<<1) | Copy_u8SubGroupNum    ;  break ;
  }


  MNVIC_REG->IPR[Copy_u8IntPos] = (LOC_u8PrioValue<<4) ;
}

void MNVIC_voidSetInterruptGroupMode(MNVIC_GroupMode_t Copy_uddtGroupMode)
{
	MSCB_AIRCR  = MNVIC_VECTKEY  ;   //reset the register first
	MSCB_AIRCR = MNVIC_VECTKEY | (Copy_uddtGroupMode<<8 ) ;
}

