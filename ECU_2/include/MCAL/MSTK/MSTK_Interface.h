/*
 * Author            : Mennat-Allah Heshmat                 
 * Data              : 25 May 2023             
 * Module  Features  : 1- MSTK_voidInit()        
 *                     2- MSTK_voidStart()       
 *                     3- MSTK_voidDelayMs()     
 *                     4- MSTK_voidDelayUs()     
 *                     5- MSTK_u8ReadFlag()      
 *                     6- MSTK_voidCtrlIntState()
 * Future  Updates   :  interrupt handling       
 */

#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_



#define MSTK_INT_ENABLE         1
#define MSTK_INT_DISABLE        0



#define MSTK_ENABLE_BIT         0


/**************** Function Prototypes ****************/

void MSTK_voidInit(void);
void MSTK_voidStart(u32 Copy_u32PreloadValue);
void MSTK_voidDelayMs(u32 Copy_u32DelayMs);
void MSTK_voidDelayUs(u32 Copy_u32DelayUs);
u8 MSTK_u8ReadFlag(void);
void MSTK_voidCtrlIntState(u8 Copy_u8IntStatus);

#endif /* MSTK_INTERFACE_H_ */
