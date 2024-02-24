/*
 * Author            : Mennat-Allah Heshmat               
 * Date              : 25 May 2023  
 * MEXTI_Interface.h --> Function Prototypes 
 * Module  Features  :                       
 *      01- MEXTI_voidEnableEXTI             
 *      02- MEXTI_voidDisableEXTI            
 *      03- MEXTI_voidSoftwareInterrupt      
 *      04- MEXTI_voidSetTriggerSource       
 *      05- MEXTI_voidSetExtiConfig          
 *      06- MEXTI_VoidCallBack               
 */


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* The Line Number*/
typedef enum{
	MEXTI_LINE_0 ,
	MEXTI_LINE_1 ,
	MEXTI_LINE_2 ,
	MEXTI_LINE_3 ,
	MEXTI_LINE_4 ,
	MEXTI_LINE_5 ,
	MEXTI_LINE_6 ,
	MEXTI_LINE_7 ,
	MEXTI_LINE_8 ,
	MEXTI_LINE_9 ,
	MEXTI_LINE_10 ,
	MEXTI_LINE_11 ,
	MEXTI_LINE_12 ,
	MEXTI_LINE_13 ,
	MEXTI_LINE_14 ,
	MEXTI_LINE_15
}MEXTI_LINE_t;

/******************************************Triggering Source Mode **************************/
typedef enum{
	MEXTI_RISING_EDGE  ,
	MEXTI_FALLING_EDGE ,
	MEXTI_ON_CHANGE
}MEXTI_TriggerMode_t;

/***************************************** Selected Port Number  ***************************/
typedef enum{
	MEXTI_PORTA ,
	MEXTI_PORTB ,
	MEXTI_PORTC
}MEXTI_Port_t;
/*******************************************Function  Prototypes ***************************/
void MEXTI_voidEnableEXTI(MEXTI_LINE_t Copy_uddtLineNum)                                                ;
void MEXTI_voidDisableEXTI(MEXTI_LINE_t Copy_uddtLineNum)                                               ;
void MEXTI_voidSoftwareInterrupt(MEXTI_LINE_t Copy_uddtLineNum)                                         ;
void MEXTI_voidSetTriggerSource(MEXTI_LINE_t Copy_uddtLineNum,MEXTI_TriggerMode_t Copy_uddtTriggerMode) ;
void MEXTI_voidSetExtiConfig(MEXTI_LINE_t Copy_uddtLineNum , u8 Copy_u8GpioPortNum)                     ;
void MEXTI0_VoidCallBack(void (*ptr)(void)) ;
void MEXTI1_VoidCallBack(void (*ptr)(void)) ;



#endif  //EXTI_INTERFACE_H
