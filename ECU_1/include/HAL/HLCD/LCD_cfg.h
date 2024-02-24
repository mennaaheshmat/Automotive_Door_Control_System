/*******************************************************/
/* Author   : Mohamed Fawzi                            */
/* Date     : 20 DEC 2022                              */
/* File     : LCD_cfg.h                                */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

/*   enable clock   */
#define  LCD_PORT    MRCC_GPIOB

/*			LCD_MODE		*/
#define LCD_MODE		EIGHT_BIT

/*			Control Pins	*/
#define RS_PORT		MGPIOA_PORT
#define RS_PIN		MGPIO_PIN11

#define RW_PORT		MGPIOB_PORT
#define RW_PIN		MGPIO_PIN4

#define EN_PORT		MGPIOB_PORT
#define EN_PIN		MGPIO_PIN5

/*			Data Pins		*/
#define D7_PORT		MGPIOB_PORT
#define D7_PIN		MGPIO_PIN14

#define D6_PORT		MGPIOB_PORT
#define D6_PIN		MGPIO_PIN13

#define D5_PORT		MGPIOB_PORT
#define D5_PIN		MGPIO_PIN12

#define D4_PORT		MGPIOB_PORT
#define D4_PIN		MGPIO_PIN10

#define D3_PORT		MGPIOB_PORT
#define D3_PIN		MGPIO_PIN9

#define D2_PORT		MGPIOB_PORT
#define D2_PIN		MGPIO_PIN8

#define D1_PORT		MGPIOB_PORT
#define D1_PIN		MGPIO_PIN7

#define D0_PORT		MGPIOB_PORT
#define D0_PIN      MGPIO_PIN6



#endif /* HAL_LCD_LCD_CFG_H_ */
