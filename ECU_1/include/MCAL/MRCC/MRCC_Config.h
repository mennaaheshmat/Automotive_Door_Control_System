/*
 *  Author: Mennat-Allah Heshmat
 *  Date: 25 May 2023 
 *  MRCC_Config.h
 */

#ifndef MRCC_CONFIG_H
#define MRCC_CONFIG_H

/************************ RCC CLOCK SOURCE *******************/
/*	1-MRCC_HSI                                               */
/* 	2-MRCC_HSE                                               */
/*	3-MRCC_PLL												 */ 
/*************************************************************/


#define MRCC_CLOCK_SRC	MRCC_HSI

/************************ HSE CLOCK TYPE *******************/

#define MRCC_HSE_SRC	MRCC_HSE_CRYSTAL


/************************ PLL CLOCK TYPE *******************/

#define MRCC_PLL_SRC	MRCC_PLL_HSE

/************************ HSE CRYSTAL VALUE *****************/
#define MRCC_HSE_FREQ	25000000UL

#endif