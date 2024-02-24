/*
 *Auther           : Mennat-Allah Heshmat              
 *Data             : 25 May 2023                 
 *Module Features  :                             
 *        01- MRCC_voidEnablePeripheralClock     
 *        02- MRCC_voidDisablePeripheralClock    
 *        03- MRCC_voidInitSystemClk             
 */

typedef enum
{
	AHB1 = 0 ,
	AHB2     ,
	APB1     ,
	APB2
}MRCC_Bus_t;

/*******************************************************************************************************/
/*                                      01- MRCC_voidEnablePeripheralClock                             */
/* 1- Function Description ->                                                                          */
/* 2- Function Input -> Bus Peripheral, Peripheral Number                                              */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MRCC_voidEnablePeripheralClock (MRCC_Bus_t Copy_uddtPeripheralBus, u32 Copy_u32PeripheralNumber);


/*******************************************************************************************************/
/*                                      01- MRCC_voidDisablePeripheralClock                            */
/* 1- Function Description ->                                                                          */
/* 2- Function Input -> Bus Peripheral, Peripheral Number                                              */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MRCC_voidDisablePeripheralClock (MRCC_Bus_t Copy_uddtPeripheralBus, u32 Copy_u32PeripheralNumber);

/*******************************************************************************************************/
/*                                      01- MRCC_voidInitSystemClk                                     */
/* 1- Function Description ->                                                                          */
/* 2- Function Input -> 				                                                               */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MRCC_voidInitSystemClk (void);


/********************* Peripherals Numbers In AHB1 ***********/
/*************************************************************/

#define MRCC_GPIOA	0UL
#define MRCC_GPIOB	1UL
#define MRCC_GPIOC	2UL
#define MRCC_GPIOD	3UL
#define MRCC_GPIOE	4UL
#define MRCC_GPIOH	7UL
#define MRCC_CRC	12UL
#define MRCC_DMA1	21UL
#define MRCC_DMA2	22UL
#define MRCC_SYS_CFG 14UL

#define MRCC_PERIPHERAL_EN_SPI1 12UL


#define MRCC_USART1 4UL



