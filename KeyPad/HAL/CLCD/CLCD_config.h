/*
 * CLCD_config.h
 *
 *  Created on: Mar 4, 2022
 *      Author: INTEL
 */

#ifndef HAL_CLCD_CLCD_CONFIG_H_
#define HAL_CLCD_CLCD_CONFIG_H_
const U8 CLCD_u8SptialChar[]=
       {  0x00, 0x00, 0x07, 0x04, 0x04, 0x1F, 0x00,   0x00,
		  0x00, 0x00, 0x07, 0x05, 0x05, 0x1F, 0x00,   0x00,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08,   0x10,
		  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   0x00,
		  0x00, 0x00, 0x07, 0x05, 0x05, 0x1F, 0x00,   0x00,
		  0x00, 0x00, 0x07, 0x01, 0x01, 0x1F, 0x00,   0x00,
		  0x00, 0x00, 0x07, 0x05, 0x05, 0x1F, 0x00,   0x00,
		  0x00, 0x00, 0x01, 0x01, 0x01, 0x1F, 0x00,   0x00
};

//Data&Control PORT
/*OPTION PORT
 * PORTA
 * PORTB
 * PORTC
 * PORTD*/
#define CLCD_Data_Port DIO_PORTA
#define CLCD_control_Port DIO_PORTB
//CONTROL PINS
/*OPTION
 * PIN0
 * PIN1
 * PIN2
 * PIN3
 * PIN4
 * PIN5
 * PIN6
 * PIN7*/
#define CLCD_RSPIN  DIO_PIN0
#define CLCD_RWPIN  DIO_PIN1
#define CLCD_ENPIN  DIO_PIN2
//FUNCTION SET
/*OPTION
 * SET1-->1LINE&FONT5*7
 * SET2-->2LINE&FONT5*8
 * SET3-->2LINE&FONT5*7
 * SET4-->1LINE&FONT5*8*/
#define CLCD_function_set CLCD_FunctionSet_3
//DISPLAY ON&OFF
/*OPTION
 * CLCD_Display_OFF
 * CLCD_Display_ON&CURSOR OFF
 * CLCD_cursor_ON
 *  CLCD_cursor_Blink*/
#define CLCD_Display  CLCD_Display_ON
//DISPLAY CLR
#define CLCD_Display_Clear 0X1
//DISPLAY ENTRY MODE
/*	OPTION
 * CLCD_Shift_Left
 * CLCD_Shift_Right
 * CLCD_Disable_Shift*/
#define CLCD_Entry_Mode CLCD_Disable_Shift




#endif /* HAL_CLCD_CLCD_CONFIG_H_ */
