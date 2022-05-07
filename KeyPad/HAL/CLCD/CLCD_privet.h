/*
 * CLCD_privet.h
 *
 *  Created on: Mar 4, 2022
 *      Author: INTEL
 */

#ifndef HAL_CLCD_CLCD_PRIVET_H_
#define HAL_CLCD_CLCD_PRIVET_H_
//function set option
#define CLCD_FunctionSet_1 0X30
#define CLCD_FunctionSet_2 0X3C
#define CLCD_FunctionSet_3 0X38
#define CLCD_FunctionSet_4 0X34
//Display on&off option
#define CLCD_Display_OFF   0X8
#define CLCD_Display_ON    0XC
#define CLCD_cursor_ON     0XE
#define CLCD_cursor_Blink  0XF
//entry mode option
#define CLCD_Shift_Left     0X7
#define CLCD_Shift_Right    0X5
#define CLCD_Disable_Shift  0X6
//DDRAM ADDRESSES
#define CLCD_ROW1_Address 0X80
#define CLCD_ROW2_Address 0X80+64
#define CLCD_Set_CGRAM    0X40



#endif /* HAL_CLCD_CLCD_PRIVET_H_ */
