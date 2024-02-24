/*******************************************************/
/* Author   : Mohamed Fawzi                            */
/* Date     : 20 DEC 2022                              */
/* File     : LCD_prv.h                                */
/* Version  : V 0.0                                    */
/*******************************************************/

#ifndef HAL_LCD_LCD_PRV_H_
#define HAL_LCD_LCD_PRV_H_


#define LCD_Function_4BIT_2Lines   0x28
#define LCD_Function_8BIT_2Lines   0x38
//===========================LED COmmands==============//
#define LCD_MOVE_DISP_RIGHT           0X1C
#define LCD_MOVE_DISP_LIFT            0X18
#define LCD_MOVE_CURSOR_RIGHT         0X14
#define LCD_MOVE_CURSOR_LIFT          0X10
#define LCD_DISP_OFF_CURSOR_OFF       0X08
#define LCD_DISP_ON_CURSOR_ON         0X0E
#define LCD_DISP_ON_CURSOR_BLINK      0X0F
#define LCD_ENTRY_MODE                0X06
#define LCD_ENTRY_DEC                 0X04
#define LCD_ENTRY_DEC_SHIFT           0X05
#define LCD_ENTRY_INC                 0X06
#define LCD_ENTRY_INC_SHIFT           0X07
#define LCD_BEGIN_AT_FIRST_RAW        0X80
#define LCD_BEGIN_AT_SECOND_RAW       0XC0
#define LCD_CLEAR_SCREEN              0X01
#define LCD_RETURN_HOME               0X02

//=======================================================//
#define   Four_bit    0
#define   Eight_bit   1
#define   High_Nibble 1
#define   Low_Nibble  0

#define EIGHT_BIT	24
#define FOUR_BIT	9


static void LCD_voidLatch(u8 copy_u8Data);

#define LCD_ROW_1     111
#define LCD_ROW_2     222

#define LCD_COL_1      1
#define LCD_COL_2      2
#define LCD_COL_3      3
#define LCD_COL_4      4
#define LCD_COL_5      5
#define LCD_COL_6      6
#define LCD_COL_7      7
#define LCD_COL_8      8
#define LCD_COL_9      9
#define LCD_COL_10     10
#define LCD_COL_11     11
#define LCD_COL_12     12
#define LCD_COL_13     13
#define LCD_COL_14     14
#define LCD_COL_15     15
#define LCD_COL_16     16



#endif /* HAL_LCD_LCD_PRV_H_ */
