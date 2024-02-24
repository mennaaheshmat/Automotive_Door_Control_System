/*******************************************************/
/* Author   : Mohamed Fawzi                            */
/* Date     : 15 Aug 2023                              */
/* File     : LCD_int.h                                */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef LCD_INT_H_
#define LCD_INT_H_

#define INPUT    0
#define OUTPUT   1

#define FULL_INPUT  0X00
#define FULL_OUTPUT 0XFF

void LCD_enuInit(void);
void LCD_enuDisplayChar(u8 Copy_u8Data);
void LCD_enuSendCommand(u8 Copy_u8Command);

void LCD_voidSendString  ( u8 * Copy_u8ptrString );
void LCD_voidSetPosition ( u8 Copy_u8Row , u8 Copy_u8Col );

void LCD_voidSendINTNum(u32 copy_u32Num);
void LCD_voidSendExtraChar(u8 *copy_u8Parr,u8 copy_u8CharNum,u8 copy_u8position,u8 copy_u8EntryMode);
void LCD_voidSendFloatNumber(f64 Copy_f32Number);

#endif /* LCD_INT_H_ */
