/*
 *  Author: Mennat-Allah Heshmat
 *  Date: 30 May 2023 
 *  MUSART_Program.c
 */



/************************* Includes ************************/

#include"../LIB/LSTD_TYPES.h"
#include"../LIB/LBIT_MATH.h"
#include"MUSART_Private.h"
#include"MUSART_Config.h"
#include"MUSART_Interface.h"


static void(*MUSART_CALLPTR)(void)   = NULL ;


void MUSART_voidInit(void)
{

	/*Set Boaud Rate*/
	MUSART1->BRR = 0x00000683 ;   //baudRate 9600 bps
			//208 ;

	/*OverSampling 16 Sample*/
	MUSART1->CR1.OVER8 = 0 ;   //BitField
	/*8 Bit Word size*/
	MUSART1->CR1.M = 0 ;
	/*Disable Parity*/
	MUSART1->CR1.PCE = 	0 ;
	/*one Stop Bit*/
	CLR_BIT(MUSART1->CR2,12);
	CLR_BIT(MUSART1->CR2,13);
	/*Enable Trasmitter */
	MUSART1->CR1.TE = 1 ;
	/*Enable Receiver*/
	MUSART1->CR1.RE = 1 ;
	/*Receive interrupt  Enable*/
	MUSART1->CR1.RXNEIE = 1 ;
}

void MUSART_voidSendData(u8* copy_u8Data,u8 Copy_u8Len)
{
   for(u8 Copy_u8Iterator = 0 ; Copy_u8Iterator < Copy_u8Len ; Copy_u8Iterator++ )
   {
	   /*Send Byte*/
	   MUSART1->DR = copy_u8Data[Copy_u8Iterator] ;
	   /*wait until data transfer is complete from Transmitter buffer register to shift Transmitter Register*/
	   while(GET_BIT(MUSART1->SR,7) == 0) ;
   }

}

void MUSART_u8ReadData(u8* buffer, u8 length)
{
    for (u8 i = 0; i < length; i++)
    {
        while (!GET_BIT(MUSART1->SR, 5)); // Wait until data ready
        buffer[i] = (u8)MUSART1->DR;      // Read data into the buffer
    }

	/************************************/
	///*wait until data ready*/
	// while(!GET_BIT(MUSART1->SR,5)) ;
	// return (u8) MUSART1->DR  ;
}

void MUSART_voidEnable(void)
{
  /*UART Enable*/
  MUSART1->CR1.UE =  1 ;
}

void MUSART_voidDisable(void)
{
	 /*UART Disable*/
	  MUSART1->CR1.UE =  1 ;
}



void MUSART_voidCallBack(void(*Fptr)(void))
{

	MUSART_CALLPTR = Fptr ;
}




void USART1_IRQHandler(void)
{
	MUSART_CALLPTR() ;
}
