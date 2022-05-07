/*
 * main.c

 *
 *  Created on: Mar 4, 2022
 *      Author: INTEL
 */
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../HAL/CLCD/CLCD_interface.h"
#include"util/delay.h"
#include "../HAL/Keypad/Keypad_interface.h"
#include"../HAL/SSD/SSD_interface.h"
#include"../MCAL/DIO_interface.h"
int main(void){
SSD_STATE ssd={SSD_COMMON_ANODE,DIO_PORTD,DIO_PIN3,DIO_PORTB,SSD_Disable_Dot};
	CLCD_voidInit();
	SSD_voidInit();
	SSD_voidEnable(ssd);
	Keypad_voidInit();
	S8 value=-1;


	while(1){
		//KEYPAD+LCD
		/*value=Keypad_U8GetPressed();
		if(value!=0){
			CLCD_voidSendData(value);
		}*/
		//KEYPAD+SSD
		value=Keypad_U8GetPressed();
		if(value!=-1){
			//SSD_voidSedndNumber(ssd,value);
             CLCD_voidSendData(value);
		}


	}

	return 0;
}

