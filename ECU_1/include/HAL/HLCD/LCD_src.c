/*******************************************************/
/* Author   : Mohamed Fawzi                            */
/* Date     : 20 DEC 2022                              */
/* File     : LCD_src.c                                */
/* Version  : V 0.0                                    */
/*******************************************************/

#include "../LIB/LSTD_TYPES.h"
#include "../LIB/LBIT_MATH.h"

#include "../MCAL/MGPIO/MGPIO_Interface.h"
#include "../MCAL/MRCC/MRCC_Inteface.h"
#include "../MCAL/MSTK/MSTK_Interface.h"

#include "lcd_int.h"
#include "lcd_cfg.h"
#include "lcd_prv.h"

void LCD_enuInit(void){

		MRCC_voidInitSystemClk() ;
		MRCC_voidEnablePeripheralClock(AHB1,LCD_PORT);

		// MGPIO_vSetPinMode(RS_PORT	, RS_PIN , OUTPUT);
		 MGPIO_u8SetPinMode(RS_PORT,RS_PIN,MGPIO_MODE_OUTPUT);
		// MGPIO_vSetPinMode(RW_PORT	, RW_PIN , OUTPUT);
		 MGPIO_u8SetPinMode(RW_PORT,RW_PIN,MGPIO_MODE_OUTPUT);

		// MGPIO_vSetPinMode(EN_PORT	, EN_PIN , OUTPUT);
		 MGPIO_u8SetPinMode(EN_PORT,EN_PIN,MGPIO_MODE_OUTPUT);

		 MGPIO_u8SetPinMode(D7_PORT, D7_PIN, MGPIO_MODE_OUTPUT);

		 MGPIO_u8SetPinMode(D6_PORT, D6_PIN, MGPIO_MODE_OUTPUT);
		 MGPIO_u8SetPinMode(D5_PORT, D5_PIN, MGPIO_MODE_OUTPUT);
		 MGPIO_u8SetPinMode(D4_PORT, D4_PIN, MGPIO_MODE_OUTPUT);

		 for (u8 i =3 ; i <= 10 ; i++)
		 {
			 MGPIO_u8SetOutputType(MGPIOA_PORT,i,MGPIO_OUTPUT_PUSH_PULL) ;
		 }

		for (u8 i = 3 ; i < 15 ; i++)
		{
			MGPIO_u8SetOutputSpeed(MGPIOB_PORT,i,MGPIO_SPEED_LOW);
		}

		 MSTK_voidDelayMs(50);

	#if LCD_MODE == EIGHT_BIT
		 MGPIO_u8SetPinMode(D3_PORT, D3_PIN, MGPIO_MODE_OUTPUT);
		 MGPIO_u8SetPinMode(D2_PORT, D2_PIN, MGPIO_MODE_OUTPUT);
		 MGPIO_u8SetPinMode(D1_PORT, D1_PIN, MGPIO_MODE_OUTPUT);
		 MGPIO_u8SetPinMode(D0_PORT, D0_PIN, MGPIO_MODE_OUTPUT);

		// function set
		 LCD_enuSendCommand(0x38);

	#elif  LCD_MODE ==FOUR_BIT
		// function set
		 LCD_enuSendCommand(0x28);
	#endif

		 MSTK_voidDelayMs(1);
		//Display on off
		 LCD_enuSendCommand(0x0C);
		 MSTK_voidDelayMs(1);
		//clear display
		LCD_enuSendCommand(0x01);
		MSTK_voidDelayMs(2);
		//entry mode
		LCD_enuSendCommand(0x06);

}


void LCD_enuDisplayChar(u8 Copy_u8Data)
{

	//set RS as Data
	MGPIO_u8SetPinValue(RS_PORT ,RS_PIN ,MGPIO_HIGH_VALUE);
	LCD_voidLatch( Copy_u8Data);

}

void LCD_enuSendCommand(u8 Copy_u8Command)
{

	//set RS as command
	MGPIO_u8SetPinValue(RS_PORT ,RS_PIN ,MGPIO_LOW_VALUE);
	LCD_voidLatch( Copy_u8Command);

}

void LCD_voidSendString  ( u8 * Copy_u8ptrString )
{

	u8 LOC_u8Iterator=0;

	while(Copy_u8ptrString[LOC_u8Iterator]!= '\0')
	{
		LCD_enuDisplayChar(Copy_u8ptrString[LOC_u8Iterator]);
		LOC_u8Iterator++;

	}

}


void LCD_voidSetPosition ( u8 Copy_u8Row , u8 Copy_u8Col )
{

	if(Copy_u8Row==LCD_ROW_1)
	{
		LCD_invidSendCommend((0x80) + ( Copy_u8Col - 1 ));
	}

	else if(Copy_u8Row==LCD_ROW_2)
	{
		LCD_invidSendCommend((0x80)+64 + ( Copy_u8Col - 1 ));

	}

}


void LCD_voidSendINTNum(u32 copy_u32Num)
{


	u32 LOC_u32Reversed = 1 ;

	if( copy_u32Num == 0 ){ LCD_enuDisplayChar('0'); }

	else{

		while ( copy_u32Num != 0 ){

			LOC_u32Reversed = ( LOC_u32Reversed * 10 ) + ( copy_u32Num % 10 );
			copy_u32Num /= 10 ;

		}

		while ( LOC_u32Reversed != 1 ){
			MGPIO_u8SetPinValue(RS_PORT,RS_PIN,MGPIO_HIGH_VALUE);
			LCD_voidLatch( ( LOC_u32Reversed % 10 ) + 48 );
			LOC_u32Reversed /= 10 ;

		}

	}




}


void LCD_voidSendExtraChar(u8 *copy_u8Parr,u8 copy_u8CharNum,u8 copy_u8position,u8 copy_u8EntryMode)
{
	u8 LOC_u8Iterator = 0 ;
	//Go To CGRAM
	LCD_invidSendCommend(0b01000000);
	// set RS as data
	MGPIO_u8SetPinValue(RS_PORT, RS_PIN,MGPIO_HIGH_VALUE);
	//Draw Character
	for(LOC_u8Iterator=0;LOC_u8Iterator<(copy_u8CharNum*8);LOC_u8Iterator++)
	{
		LCD_voidLatch(copy_u8Parr[LOC_u8Iterator]);
	}
	if(copy_u8EntryMode==0x04)
	{
		//return to DDRAM
		LCD_invidSendCommend(copy_u8position);
		LCD_invidSendCommend(copy_u8EntryMode);


	}
	//send address
	for(LOC_u8Iterator=0;LOC_u8Iterator<copy_u8CharNum;LOC_u8Iterator++)
	{
		MGPIO_u8SetPinValue(RS_PORT, RS_PIN,MGPIO_HIGH_VALUE);
		LCD_voidLatch(LOC_u8Iterator);


	}

}


void LCD_voidSendFloatNumber(f64 Copy_f64Number)
{


	// send int num
	LCD_voidSendINTNum((u64)Copy_f64Number );
	// Send decimal point
	LCD_enuDisplayChar('.');

	// Multiply the Float Number by 10^6 so the decimal number becomes part number
	u64 Local_u64tempNumber = Copy_f64Number*1000000;

	if( Local_u64tempNumber%10 >=5 )
	{

		LCD_voidSendINTNum((u64)((( Local_u64tempNumber/10)+1) % 100000));
	}
	else
	{

		// Display the number
		LCD_voidSendINTNum((u64)(( Local_u64tempNumber/10) % 100000));

	}


}

void LCD_invidSendCommend(u8 Copy_u8Command)
{
	//set RS as command
	MGPIO_u8SetPinValue(RS_PORT ,RS_PIN ,MGPIO_LOW_VALUE);

	// set RW as  write operation,EN LOW
	MGPIO_u8SetPinValue(RW_PORT, RW_PIN,MGPIO_LOW_VALUE);
	MGPIO_u8SetPinValue(EN_PORT, EN_PIN,MGPIO_LOW_VALUE);

	//write data
	MGPIO_u8SetPinValue(D7_PORT, D7_PIN,GET_BIT(Copy_u8Command,7) );
	MGPIO_u8SetPinValue(D6_PORT, D6_PIN, GET_BIT(Copy_u8Command,6) );
	MGPIO_u8SetPinValue(D5_PORT, D5_PIN, GET_BIT(Copy_u8Command,5)  );
	MGPIO_u8SetPinValue(D4_PORT, D4_PIN, GET_BIT(Copy_u8Command,4)  );

#if LCD_MODE==EIGHT_BIT

	MGPIO_u8SetPinValue(D3_PORT, D3_PIN,GET_BIT(Copy_u8Command,3) );
	MGPIO_u8SetPinValue(D2_PORT, D2_PIN, GET_BIT(Copy_u8Command,2) );
	MGPIO_u8SetPinValue(D1_PORT, D1_PIN, GET_BIT(Copy_u8Command,1) );
	MGPIO_u8SetPinValue(D0_PORT, D0_PIN, GET_BIT(Copy_u8Command,0) );

#elif LCD_MODE == FOUR_BIT
	if(Copy_u8Command=0x28)
	{
		// falling edge
		MGPIO_vWriteData(EN_PORT, EN_PIN,HIGH);
		Delay_vMsIn16MHz(10);
		MGPIO_vWriteData(EN_PORT, EN_PIN,LOW);
		Delay_vMsIn16MHz(10);
		MGPIO_vWriteData(D7_PORT, D7_PIN,GET_BIT(Copy_u8Command,7) );
		MGPIO_vWriteData(D6_PORT, D6_PIN, GET_BIT(Copy_u8Command,6) );
		MGPIO_vWriteData(D5_PORT, D5_PIN, GET_BIT(Copy_u8Command,5)  );
		MGPIO_vWriteData(D4_PORT, D4_PIN, GET_BIT(Copy_u8Command,4)  );
	}


	// falling edge
	MGPIO_vWriteData(EN_PORT, EN_PIN,HIGH);
	Delay_vMsIn16MHz(10);
	MGPIO_vWriteData(EN_PORT, EN_PIN,LOW);
	Delay_vMsIn16MHz(10);

	MGPIO_vWriteData(D3_PORT, D3_PIN,GET_BIT(Copy_u8Command,3) );
	MGPIO_vWriteData(D2_PORT, D2_PIN, GET_BIT(Copy_u8Command,2) );
	MGPIO_vWriteData(D1_PORT, D1_PIN, GET_BIT(Copy_u8Command,1) );
	MGPIO_vWriteData(D0_PORT, D0_PIN, GET_BIT(Copy_u8Command,0) );


#else
#error Wrong Selection


#endif

	// falling edge
	MGPIO_u8SetPinValue(EN_PORT, EN_PIN,MGPIO_HIGH_VALUE);
	MSTK_voidDelayMs(10);
	MGPIO_u8SetPinValue(EN_PORT, EN_PIN,MGPIO_LOW_VALUE);
	MSTK_voidDelayMs(10);

}





static void LCD_voidLatch(u8 copy_u8Data)
{

	// set RW as  write operation,EN LOW
	MGPIO_u8SetPinValue(RW_PORT, RW_PIN,MGPIO_LOW_VALUE);
	MGPIO_u8SetPinValue(EN_PORT, EN_PIN,MGPIO_LOW_VALUE);

	//write data
	MGPIO_u8SetPinValue(D7_PORT, D7_PIN,GET_BIT (copy_u8Data,7) );
	MGPIO_u8SetPinValue(D6_PORT, D6_PIN, GET_BIT(copy_u8Data,6) );
	MGPIO_u8SetPinValue(D5_PORT, D5_PIN, GET_BIT(copy_u8Data,5)  );
	MGPIO_u8SetPinValue(D4_PORT, D4_PIN, GET_BIT(copy_u8Data,4)  );

#if LCD_MODE==EIGHT_BIT

	MGPIO_u8SetPinValue(D3_PORT, D3_PIN,GET_BIT (copy_u8Data,3) );
	MGPIO_u8SetPinValue(D2_PORT, D2_PIN, GET_BIT(copy_u8Data,2) );
	MGPIO_u8SetPinValue(D1_PORT, D1_PIN, GET_BIT(copy_u8Data,1) );
	MGPIO_u8SetPinValue(D0_PORT, D0_PIN, GET_BIT(copy_u8Data,0) );

#elif LCD_MODE == FOUR_BIT
	if(Copy_u8Command=0x28)
	{
		// falling edge
		MGPIO_vWriteData(EN_PORT, EN_PIN,HIGH);
		Delay_vMsIn16MHz(10);
		MGPIO_vWriteData(EN_PORT, EN_PIN,LOW);
		Delay_vMsIn16MHz(10);
		MGPIO_vWriteData(D7_PORT, D7_PIN,GET_BIT( copy_u8Data,7) );
		MGPIO_vWriteData(D6_PORT, D6_PIN, GET_BIT(copy_u8Data,6) );
		MGPIO_vWriteData(D5_PORT, D5_PIN, GET_BIT(copy_u8Data,5)  );
		MGPIO_vWriteData(D4_PORT, D4_PIN, GET_BIT(copy_u8Data,4)  );
	}


	// falling edge
	MGPIO_vWriteData(EN_PORT, EN_PIN,HIGH);
	Delay_vMsIn16MHz(10);
	MGPIO_vWriteData(EN_PORT, EN_PIN,LOW);
	Delay_vMsIn16MHz(10);

	MGPIO_vWriteData(D3_PORT, D3_PIN,GET_BIT (copy_u8Data,3) );
	MGPIO_vWriteData(D2_PORT, D2_PIN, GET_BIT(copy_u8Data,2) );
	MGPIO_vWriteData(D1_PORT, D1_PIN, GET_BIT(copy_u8Data,1) );
	MGPIO_vWriteData(D0_PORT, D0_PIN, GET_BIT(copy_u8Data,0) );


#else
#error "Wrong Selection"


#endif

	// falling edge
	MGPIO_u8SetPinValue(EN_PORT, EN_PIN,MGPIO_HIGH_VALUE);
	MSTK_voidDelayMs(10);
	MGPIO_u8SetPinValue(EN_PORT, EN_PIN,MGPIO_LOW_VALUE);
	MSTK_voidDelayMs(10);



}
