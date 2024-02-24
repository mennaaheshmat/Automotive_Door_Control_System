/*
 *  Author           : Mennat-Allah Heshmat              
 *  Date             : 25 May 2023
 *  MRGPIO_Interface.h --> Function Prototypes    
 *  Module Features  :                                           
 *          01- MRCC_voidEnablePeripheralClock              
 *          02- MRCC_voidDisablePeripheralClock             
 */

#ifndef MGPIO_INTERFACE_H
#define MGPIO_INTERFACE_H

/******************** GPIO PORTS ******************************/
#define MGPIOA_PORT	0UL
#define MGPIOB_PORT	1UL
#define MGPIOC_PORT	2UL
#define MGPIOD_PORT	3UL
#define MGPIOE_PORT	4UL
#define MGPIOF_PORT	5UL
#define MGPIOH_PORT	6UL

/******************** GPIO PINS *******************************/
#define MGPIO_PIN0	0UL
#define MGPIO_PIN1	1UL
#define MGPIO_PIN2	2UL
#define MGPIO_PIN3	3UL
#define MGPIO_PIN4	4UL
#define MGPIO_PIN5	5UL
#define MGPIO_PIN6	6UL
#define MGPIO_PIN7	7UL
#define MGPIO_PIN8	8UL
#define MGPIO_PIN9	9UL
#define MGPIO_PIN10	10UL
#define MGPIO_PIN11	11UL
#define MGPIO_PIN12	12UL
#define MGPIO_PIN13	13UL
#define MGPIO_PIN14	14UL
#define MGPIO_PIN15	15UL

/******************** GPIO MODE *******************************/
#define MGPIO_MODE_INPUT	(0b00)
#define MGPIO_MODE_OUTPUT	(0b01)
#define MGPIO_MODE_ALTF		(0b10)
#define MGPIO_MODE_ANALOG	(0b11)

/******************** GPIO OUTPUT TYPE ************************/
#define MGPIO_OUTPUT_PUSH_PULL	0UL
#define MGPIO_OUTPUT_OPEN_DRAIN	1UL


/******************** GPIO MODE *******************************/
#define MGPIO_SPEED_LOW			(0b00)
#define MGPIO_SPEED_MEDUIM		(0b01)
#define MGPIO_SPEED_HIGH		(0b10)
#define MGPIO_SPEED_VERY_HIGH	(0b11)


/******************** GPIO INTERNAL PULL *************************/
#define MGPIO_NORMAL	(0b00)
#define MGPIO_PULL_UP	(0b01)
#define MGPIO_PULL_DOWN	(0b10)

#define MGPIO_LOW_VALUE		0UL
#define MGPIO_HIGH_VALUE	1UL

/*********************** Macros ALTF ***************************/
 #define MGPIO_ALTFN_0                          (0b0000)
 #define MGPIO_ALTFN_1                          (0b0001)
 #define MGPIO_ALTFN_2                          (0b0010)
 #define MGPIO_ALTFN_3                          (0b0011)
 #define MGPIO_ALTFN_4                          (0b0100)
 #define MGPIO_ALTFN_5                          (0b0101)
 #define MGPIO_ALTFN_6                          (0b0110)
 #define MGPIO_ALTFN_7                          (0b0111)
 #define MGPIO_ALTFN_8                          (0b1000)
 #define MGPIO_ALTFN_9                          (0b1001)
 #define MGPIO_ALTFN_10                         (0b1010)
 #define MGPIO_ALTFN_11                         (0b1011)
 #define MGPIO_ALTFN_12                         (0b1100)
 #define MGPIO_ALTFN_13                         (0b1101)
 #define MGPIO_ALTFN_14                         (0b1110)
 #define MGPIO_ALTFN_15                         (0b1111)


/*********************** Function Prototypes **********************/
u8 MGPIO_u8SetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode);
u8 MGPIO_u8SetOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8TypeMode);
u8 MGPIO_u8SetOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8SpeedMode);
u8 MGPIO_u8SetPullState(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PullMode);
u8 MGPIO_u8SetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);
u8 MGPIO_u8SetResetDirectValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);
void MGPIO_voidSetPinAltFun(u8 Copy_u8PortName ,u8 Copy_u8PinNum, u8 Copy_u8AlFun) ;



#endif
