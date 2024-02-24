/*
 *  Author: Mennat-Allah Heshmat
 *  Date: 25 May 2023 
 *  MEXTI_private.h
 */


#ifndef EXIT_PRIVATE_H
#define EXIT_PRIVATE_H

/************************** Macros Base Address ****************************/

#define    MEXTI_BASE_ADDRESS			      0x40013C00
 
 
#define    MSYSCFG_EXTICR1                  (*(volatile u32*)(0x40013808))

 
#define   EXTI_CONFG_MASK1                0xFFFFFFF0UL
#define   EXTI_CONFG_MASK2                0xFFFFFF0FUL
#define   EXTI_CONFG_MASK3                0xFFFFF0FFUL
#define   EXTI_CONFG_MASK4                0xFFFF0FFFUL

/*******************************************************************************************************/
/*                                       Register Definitions                                          */
/*     - Developer can't Edit in it                                                                    */
/*     - Register _ Defination		                                                                   */
/*     - Design :                                                                                      */
/*    				- #define	:	NO                                                                 */
/*    				- Union		:	NO                                                                 */
/*    				- Struct	:	YES                                                                */
/*******************************************************************************************************/

typedef struct
{
	/*  	Must be arranged like register map		*/

	volatile  u32   IMR		;				// From Here Choice The Line
	volatile  u32   EMR		;				// FOR Event Mask
	volatile  u32   RTSR	;				// For Enable or Disable Raising Trigger For Line
	volatile  u32   FTSR	;				// For Enable or Disable Falling Trigger For Line
	volatile  u32   SWIER   ;				// For The SoftWare Interrput Event
	volatile  u32   PR		;				// For The Pending
}EXTI_t;								    // The New Data Type Of That Struct


/***************************** Struct Macros Base Address Of NVIC ***************************/
#define MEXTI					 (( volatile  EXTI_t * ) MEXTI_BASE_ADDRESS )




#endif //EXIT_PRIVATE_H
