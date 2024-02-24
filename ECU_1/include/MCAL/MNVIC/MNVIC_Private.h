/*
 *  Author: Mennat-Allah Heshmat
 *  Date: 25 May 2023 
 *  MNVIC_Private.h
 */

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


/************************  Macros Base Address Of NVIC Registers **************************/
#define MNVIC_BASE_ADDRESS    0xE000E100

/*******************************************************************************************************/
/*                                       Register Definitions                                          */
/*     - Developer can't Edit in it                                                                    */
/*     - Register _ Defination		                                                                   */
/*     - Design :                                                                                      */
/*    				- #define	:	NO                                                                 */
/*    				- Union		:	NO                                                                 */
/*    				- Struct	:	YES                                                                */
/*******************************************************************************************************/




/** NVIC register map type */
typedef struct
{
	u32 ISER[8];              /**< Interrupt Set Enable Registers */
	u32 RESERVED0[24];        /**< Reserved */
	u32 ICER[8];              /**< Interrupt Clear Enable Registers */
	u32 RSERVED1[24];         /**< Reserved */
	u32 ISPR[8];              /**< Interrupt Set Pending Registers */
	u32 RESERVED2[24];        /**< Reserved */
	u32 ICPR[8];              /**< Interrupt Clear Pending Registers */
	u32 RESERVED3[24];        /**< Reserved */
	u32 IABR[8];              /**< Interrupt Active bit Registers */
	u32 RESERVED4[56];        /**< Reserved */
	u8  IPR[240];             /**< Interrupt Priority Registers */
	u32 RESERVED5[580];       /**< Reserved */
	u32 STIR;                 /**< Software Trigger Interrupt Registers */
} NVIC_t;


/************************* Struct Macros Base Address Of NVIC **************************/

#define     MNVIC_REG    ((volatile NVIC_t*)(MNVIC_BASE_ADDRESS))

#define     MSCB_AIRCR   (*(volatile u32*) 0xE000ED0C)   //Regiter Definaition

#define     MNVIC_VECTKEY     0x05FA0000

#endif // GPIO_PRIVATE_H
