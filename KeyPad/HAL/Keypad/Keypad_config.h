/*
 * Keypad_config.h
 *
 *  Created on: Mar 9, 2022
 *      Author: INTEL
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

//BUTTONS ARRAY            /*C0, C1, C2, C3*/
U8 Keypad_u8Buttons[4][4]={{'1','2','3','4'},//RW0
                           {'5','6','7','8'},//RW1
						   {'9','A','B','C'},//RW2
						   {'D','E','F','G'}//RW3
};/*U8 Keypad_u8Buttons[4][4]={{0,1,2,3},//RW0
                           {4,5,6,7},//RW1
						   {8,9}//RW2
						   //{'D','E','F','G'}//RW3
};*/

/*option
 * DIO_PORTA
 * DIO_PORTB
 * DIO_PORTC
 * DIO_PORTD*/
#define Keypad_Port DIO_PORTC
/*RW&COL PINS OPTION
 * DIO_PIN0
 * DIO_PIN1
 * DIO_PIN2
 * DIO_PIN3
 * DIO_PIN4
 * DIO_PIN5
 * DIO_PIN6
 * DIO_PIN7*/
//ROWS PINS
#define Keypad_RW0  DIO_PIN0
#define Keypad_RW1  DIO_PIN1
#define Keypad_RW2  DIO_PIN2
#define Keypad_RW3  DIO_PIN3
//COL PINS
#define Keypad_col0 DIO_PIN4
#define Keypad_col1 DIO_PIN5
#define Keypad_col2 DIO_PIN6
#define Keypad_col3 DIO_PIN7

#define Keypad_RW_INIT DIO_PIN0
#define Keypad_RW_END  DIO_PIN3

#define Keypad_COL_INIT DIO_PIN4
#define Keypad_COL_END  DIO_PIN7



#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
