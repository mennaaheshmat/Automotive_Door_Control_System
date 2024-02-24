/*
 *  Author: Mennat-Allah Heshmat
 *  Date: 25 May 2023 
 *  MRCC_Private.h
 */

#ifndef MRCC_PRIVATE_H
#define MRCC_PRIVATE_H

/******************** RCC BASE ADDRESS *************************/
#define MRCC_BASE_ADDRESS	0x40023800


/******************** RCC REGISTERS ADDRESS ********************/
#define MRCC_CR					*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x00))
#define MRCC_PLLCFGR			*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x04))
#define MRCC_CCFGR				*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x08))
#define MRCC_CCFGR				*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x08))
#define MRCC_CIR				*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x0C))
#define MRCC_AHB1RSTR			*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x10))
#define MRCC_AHB2RSTR			*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x14))
#define MRCC_APB1RSTR			*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x20))
#define MRCC_APB2RSTR			*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x24))
#define MRCC_AHB1ENR			*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x30))
#define MRCC_AHB2ENR			*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x34))
#define MRCC_APB1ENR			*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x40))
#define MRCC_APB2ENR			*((volatile u32 *)(MRCC_BASE_ADDRESS + 0x44))

/************************ RCC CLOCK TYPES *******************/

#define MRCC_HSI	0UL
#define MRCC_HSE	1UL
#define MRCC_PLLL	2UL

/************************ RCC HSE TYPES ********************/

#define MRCC_HSE_RC			0UL
#define MRCC_HSE_CRYSTAL	1UL


/************************ RCC PLL TYPES ********************/
#define MRCC_PLL_HSI	0UL
#define MRCC_PLL_HSE	1UL

#endif