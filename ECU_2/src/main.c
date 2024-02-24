#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MRCC_Inteface.h"
#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"

#include "MNVIC_Interface.h"
#include "MEXTI_Interface.h"

#include "MUSART_Interface.h"

void LED_ON (void) ;


int main ()
{
	MRCC_voidInitSystemClk () ;
	MRCC_voidEnablePeripheralClock (AHB1,MRCC_GPIOA);
	MRCC_voidEnablePeripheralClock (APB2,MRCC_USART1);
	MSTK_voidInit();

	MNVIC_voidEnableInterrupt( (u8)7 ); //EXT_1
	MNVIC_voidEnableInterrupt( (u8)37 );//UART1
	//MNVIC_voidSetInterruptPriority((u8)7 , MNVIC_GROUPMODE_G0S16 , 1 , 1) ;
	//MNVIC_voidSetInterruptPriority((u8)37 , MNVIC_GROUPMODE_G0S16 , 1 , 2) ;

	MEXTI_voidEnableEXTI(MEXTI_LINE_1) ;
	MEXTI_voidSetTriggerSource (MEXTI_LINE_1 ,MEXTI_FALLING_EDGE) ;

	MEXTI1_VoidCallBack (LED_ON) ;

	/***************************************************************************/
	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN0,MGPIO_MODE_OUTPUT);
	MGPIO_u8SetOutputType (MGPIOA_PORT,MGPIO_PIN0,MGPIO_OUTPUT_PUSH_PULL);
	MGPIO_u8SetOutputSpeed(MGPIOA_PORT,MGPIO_PIN0,MGPIO_SPEED_LOW);

	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN2,MGPIO_MODE_OUTPUT);
	MGPIO_u8SetOutputType (MGPIOA_PORT,MGPIO_PIN2,MGPIO_OUTPUT_PUSH_PULL);
	MGPIO_u8SetOutputSpeed(MGPIOA_PORT,MGPIO_PIN2,MGPIO_SPEED_LOW);

	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN3,MGPIO_MODE_OUTPUT);
	MGPIO_u8SetOutputType (MGPIOA_PORT,MGPIO_PIN3,MGPIO_OUTPUT_PUSH_PULL);
	MGPIO_u8SetOutputSpeed(MGPIOA_PORT,MGPIO_PIN3,MGPIO_SPEED_LOW);
	/***************************************************************************/

	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN5,MGPIO_MODE_OUTPUT);
	MGPIO_u8SetOutputType (MGPIOA_PORT,MGPIO_PIN5,MGPIO_OUTPUT_PUSH_PULL);
	MGPIO_u8SetOutputSpeed(MGPIOA_PORT,MGPIO_PIN5,MGPIO_SPEED_LOW);
	/***************************************************************************/

	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN7,MGPIO_MODE_OUTPUT);
	MGPIO_u8SetOutputType (MGPIOA_PORT,MGPIO_PIN7,MGPIO_OUTPUT_PUSH_PULL);
	MGPIO_u8SetOutputSpeed(MGPIOA_PORT,MGPIO_PIN7,MGPIO_SPEED_LOW);
	/***************************************************************************/
	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN1,MGPIO_MODE_INPUT);
	MGPIO_u8SetPullState(MGPIOA_PORT,MGPIO_PIN1,MGPIO_PULL_UP) ;
	/***************************************************************************/
	/***************************************************************************/
	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN9,MGPIO_MODE_ALTF);
	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN10,MGPIO_MODE_ALTF);

	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN9,MGPIO_ALTFN_7);
	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN10,MGPIO_ALTFN_7);
	/***************************************************************************/
	/***************************************************************************/
	/***************************************************************************/
	/***************************************************************************/
	MGPIO_u8SetPinMode(MGPIOA_PORT,MGPIO_PIN15,MGPIO_MODE_INPUT);




	MUSART_voidInit() ;
	MUSART_voidEnable();

	u8 DataRec ;

	while (1)
	{
		/***************************************************************************/
		MGPIO_u8SetPinValue(MGPIOA_PORT,MGPIO_PIN0,MGPIO_HIGH_VALUE) ;
		MSTK_voidDelayMs (10000) ;
		MGPIO_u8SetPinValue(MGPIOA_PORT,MGPIO_PIN0,MGPIO_LOW_VALUE) ;

		MSTK_voidDelayMs (10000) ; //100,000 >> 1 sec

		DataRec = MUSART_u8ReadData();

		if(DataRec == 1){
			MGPIO_u8SetPinValue(MGPIOA_PORT,MGPIO_PIN7,MGPIO_HIGH_VALUE);
			MSTK_voidDelayMs (10000) ;
		}
		else{
			MGPIO_u8SetPinValue(MGPIOA_PORT,MGPIO_PIN7,MGPIO_LOW_VALUE) ;
			MSTK_voidDelayMs (10000) ;
		}



	}

	return 0 ;

}

void LED_ON (void)
{
	MGPIO_u8SetPinValue(MGPIOA_PORT,MGPIO_PIN5,MGPIO_HIGH_VALUE) ;

}

