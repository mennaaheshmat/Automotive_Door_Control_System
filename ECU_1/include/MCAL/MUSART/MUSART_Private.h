/*
 *  Author: Mennat-Allah Heshmat
 *  Date: 30 May 2023 
 *  MUSART_Private.h
 */


#ifndef MUSART_PRIVATE_H_
#define MUSART_PRIVATE_H_




#define MUSART1_BASE_ADRESS     0x40011000UL


typedef struct
{
	u32 SBK        :1 ;
	u32 RWU        :1 ;
	u32 RE         :1 ;
	u32 TE         :1 ;
	u32 IDLEIE     :1 ;
	u32 RXNEIE     :1 ;
	u32 TCIE       :1 ;
	u32 TXEIE      :1 ;
	u32 PEIE       :1 ;
	u32 PS         :1 ;
	u32 PCE        :1 ;
	u32 WAKE       :1 ;
	u32 M          :1 ;
	u32 UE         :1 ;
	u32 RESERVE    :1 ;
	u32 OVER8      :1 ;
	u32 RESERVED2  :16;
}USART_CR1;


typedef struct{

	u32 SR          ;
	u32 DR          ;
	u32 BRR         ;
	USART_CR1  CR1  ;
	u32 CR2         ;
	u32 CR3         ;
	u32 GTPR        ;
}USART_t;

#define MUSART1   ((volatile USART_t*)(MUSART1_BASE_ADRESS))

#endif /* MUSART_PRIVATE_H_ */
