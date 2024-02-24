/*
 *  Author: Mennat-Allah Heshmat
 *  Date: 25 May 2023 
 *  MGPIO_private.h
 */ 

#ifndef MGPIO_PRIVATE_H
#define MGPIO_PRIVATE_H

/******************** GPIO BASE ADDRESS *************************/
#define MGPIOA_BASE_ADDRESS	0x40020000
#define MGPIOB_BASE_ADDRESS	0x40020400
#define MGPIOC_BASE_ADDRESS	0x40020800


/****************** GPIO Registers Struct **********************/
typedef struct 
{
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH   ;
}GPIOx_REG_t;

/******************** GPIOA ADDRESS *************************/
#define MGPIOA  ((GPIOx_REG_t *)(MGPIOA_BASE_ADDRESS))

/******************** GPIOB ADDRESS *************************/
#define MGPIOB  ((GPIOx_REG_t *)(MGPIOB_BASE_ADDRESS))

/******************** GPIOC ADDRESS *************************/
#define MGPIOC  ((GPIOx_REG_t *)(MGPIOC_BASE_ADDRESS))

#endif
