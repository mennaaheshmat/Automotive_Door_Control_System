/*
 * ASystem_Init.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Mostafa Ashraf
 */


#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MRCC_Inteface.h"
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"

#include "MNVIC_Interface.h"
#include "MEXTI_Interface.h"

#include "MUSART_Interface.h"

#include "HMotor_Interface.h"
#include "LCD_int.h"

#include "ASystem_Init.h"



void ASystem_voidInit (void)
{

	MRCC_voidInitSystemClk () ;
	MRCC_voidEnablePeripheralClock (AHB1,MRCC_GPIOA);
	MRCC_voidEnablePeripheralClock (AHB1,MRCC_GPIOB);
	MRCC_voidEnablePeripheralClock (APB2,MRCC_USART1);

	MSTK_voidInit();

/******************************************************************************/
	//For SysTick LED Check
	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN0,MGPIO_MODE_OUTPUT);
	MGPIO_u8SetOutputType (MGPIOA_PORT,MGPIO_PIN0,MGPIO_OUTPUT_PUSH_PULL);
	MGPIO_u8SetOutputSpeed(MGPIOA_PORT,MGPIO_PIN0,MGPIO_SPEED_LOW);
/******************************************************************************/

	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN7,MGPIO_MODE_OUTPUT);
	MGPIO_u8SetOutputType (MGPIOA_PORT,MGPIO_PIN7,MGPIO_OUTPUT_PUSH_PULL);
	MGPIO_u8SetOutputSpeed(MGPIOA_PORT,MGPIO_PIN7,MGPIO_SPEED_LOW);

	//MNVIC_voidEnableInterrupt( (u8)37 );//UART1
	//MNVIC_voidSetInterruptPriority((u8)7 , MNVIC_GROUPMODE_G0S16 , 1 , 1) ;
	//MNVIC_voidSetInterruptPriority((u8)37 , MNVIC_GROUPMODE_G0S16 , 1 , 2) ;
*/******************************************************************************/

	//UART REC CHECK
	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN0,MGPIO_MODE_OUTPUT);
	MGPIO_u8SetOutputType (MGPIOA_PORT,MGPIO_PIN0,MGPIO_OUTPUT_PUSH_PULL);
	MGPIO_u8SetOutputSpeed(MGPIOA_PORT,MGPIO_PIN0,MGPIO_SPEED_LOW);




	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN5,MGPIO_MODE_OUTPUT);
	MGPIO_u8SetOutputType (MGPIOA_PORT,MGPIO_PIN5,MGPIO_OUTPUT_PUSH_PULL);
	MGPIO_u8SetOutputSpeed(MGPIOA_PORT,MGPIO_PIN5,MGPIO_SPEED_LOW);

	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN1,MGPIO_MODE_INPUT);
	MGPIO_u8SetPullState(MGPIOA_PORT,MGPIO_PIN1,MGPIO_PULL_UP) ;

	//MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN15,MGPIO_MODE_INPUT);
	//MGPIO_u8SetPullState(MGPIOA_PORT,MGPIO_PIN15,MGPIO_PULL_UP) ;



}

void ADoor_voidInit (void)
{
	MNVIC_voidEnableInterrupt( (u8)7 ); //EXT_1
	MEXTI_voidEnableEXTI(MEXTI_LINE_1) ;
	MEXTI_voidSetTriggerSource (MEXTI_LINE_1 ,MEXTI_ON_CHANGE) ;

	/*******************************Lights***********************************/
	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN2,MGPIO_MODE_OUTPUT);
	MGPIO_u8SetOutputType (MGPIOA_PORT,MGPIO_PIN2,MGPIO_OUTPUT_PUSH_PULL);
	MGPIO_u8SetOutputSpeed(MGPIOA_PORT,MGPIO_PIN2,MGPIO_SPEED_LOW);

}

void ALights_voidControl (void)
{
	MEXTI1_VoidCallBack (LED_ON) ;
}

void ASysTick_voidCheck (void)
{

	/***************************************************************************/
		MGPIO_u8SetPinValue(MGPIOA_PORT,MGPIO_PIN0,MGPIO_HIGH_VALUE) ;
		MSTK_voidDelayMs (1000) ;
		MGPIO_u8SetPinValue(MGPIOA_PORT,MGPIO_PIN0,MGPIO_LOW_VALUE) ;
		MSTK_voidDelayMs (1000) ; //100,000 >> 1 sec
	/***************************************************************************/
}


void ASystem_vodiUART (void)
{
	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN9,MGPIO_MODE_ALTF);
	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN10,MGPIO_MODE_ALTF);

	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN9,MGPIO_ALTFN_7);
	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN10,MGPIO_ALTFN_7);


	MUSART_voidInit() ;
	MUSART_voidEnable();
	//u8 dataToSend []  = {1,2,3,4,5} ;
	//	u8 dataLenght = (sizeof (dataToSend) / sizeof (dataToSend[0])) ;

	//	MUSART_voidSendData (dataToSend , dataLenght) ;

}

void ASystem_voidLCD (void)
{
	LCD_enuInit();

	LCD_voidSetPosition(0,1) ;

    u8 hello[] = "Hello";
    LCD_voidSendString(hello);
}

void ASystem_voidMotor (void)
{


	HMotor_vidStart(ClockWise);
}

void LED_ON(void)
{
    ASystem_vodiUART(); // Initialize UART if needed

    static u8 lights_indicator = 0;

    if (lights_indicator == 0)
    {
    	lights_indicator = 1;

        //MUSART_voidSendData(&lights_indicator, 1);

        if (MGPIO_u8GetPinValue(MGPIOA_PORT,MGPIO_PIN1) == 0)
        {
		LCD_enuSendCommand(0x01);
		MSTK_voidDelayMs(1000000);
        u8 hello[] = "DOORs are OPEN";
        LCD_voidSendString(hello);
    	MSTK_voidDelayMs(1000000);

        MGPIO_u8SetPinValue(MGPIOA_PORT, MGPIO_PIN5, MGPIO_HIGH_VALUE);
    	MSTK_voidDelayMs(1000000);
        MGPIO_u8SetPinValue(MGPIOA_PORT, MGPIO_PIN5, MGPIO_LOW_VALUE);
    	MSTK_voidDelayMs(1000000);


        }

    }
    else
    {
        MGPIO_u8SetPinValue(MGPIOA_PORT, MGPIO_PIN5, MGPIO_LOW_VALUE);
        LCD_enuSendCommand(0x01);
        MSTK_voidDelayMs(500);

        lights_indicator = 0;
    }
}

void AAlert_voidSys (void)
{
	u8 LocalData = 0 ;
	if ((MGPIO_u8GetPinValue(MGPIOA_PORT, MGPIO_PIN1) == 0 )&& ( MGPIO_u8GetPinValue(MGPIOB_PORT,MGPIO_PIN1)==1) )
	{

		LocalData = 1 ;
		MUSART_voidSendData(&LocalData, 1);


	}
	else
	{
		LocalData = 0 ;
		MUSART_voidSendData(&LocalData, 1);

	}

}



