/*
 *  Author: Mennat-Allah Heshmat
 *  Date: 25 May 2023 
 *  MSTK_Private.h
 */


#ifndef MSTK_REG_H_
#define MSTK_REG_H_


/**************************** Macros Base Address Of MSTK Registers ***************************/
 #define    MSTK_BASE_ADRESS        0xE000E010

/*******************************************************************************************************/
/*                                       Register Definitions                                          */
/*     - Developer can't Edit in it                                                                    */
/*     - Register _ Defination		                                                                   */
/*     - Design :                                                                                      */
/*    				- #define	:	NO                                                                 */
/*    				- Union		:	NO                                                                 */
/*    				- Struct	:	YES                                                                */
/*******************************************************************************************************/


typedef struct{

	volatile u32 CTRL ;
	volatile u32 LOAD ;
	volatile u32 VAL  ;
	volatile u32 CALIB;

}MSTK;

/*********************** Struct Macros Base Address Of MSTK ****************************/


#define MSTK ((volatile MSTK*)MSTK_BASE_ADRESS)


#endif /* MSTK_REG_H_ */
