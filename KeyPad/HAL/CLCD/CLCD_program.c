/*
 * CLCD_program.c

 *
 *  Created on: Mar 4, 2022
 *      Author: INTEL
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO_interface.h"
#include"CLCD_config.h"
#include"CLCD_interface.h"
#include"CLCD_privet.h"
#include"util/delay.h"
void CLCD_voidInit(void){
	DIO_enumSetPortDirection(CLCD_Data_Port,255);
	DIO_enumSetPinDirection(CLCD_RSPIN,CLCD_control_Port,DIO_OUTPUT);
	DIO_enumSetPinDirection(CLCD_RWPIN,CLCD_control_Port,DIO_OUTPUT);
	DIO_enumSetPinDirection(CLCD_ENPIN,CLCD_control_Port,DIO_OUTPUT);
	_delay_ms(50);
	CLCD_voidSendCommand(CLCD_function_set);
	_delay_ms(1);
	CLCD_voidSendCommand(CLCD_Display);
	_delay_ms(1);
	CLCD_voidSendCommand(CLCD_Display_Clear);
	_delay_ms(2);
	CLCD_voidSendCommand(CLCD_Entry_Mode);
	_delay_ms(1);
}
void CLCD_voidSendCommand(U8 Copy_u8Command){
	DIO_enumSetPortValue(CLCD_Data_Port,Copy_u8Command);
	DIO_enumSetPinValue(CLCD_RSPIN,CLCD_control_Port,DIO_LOW);
	DIO_enumSetPinValue(CLCD_RWPIN,CLCD_control_Port,DIO_LOW);
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_LOW);
	_delay_ms(1);

}
void CLCD_voidSendData(U8 Copy_u8Data){
	DIO_enumSetPortValue(CLCD_Data_Port,Copy_u8Data);
	DIO_enumSetPinValue(CLCD_RSPIN,CLCD_control_Port,DIO_HIGH);
	DIO_enumSetPinValue(CLCD_RWPIN,CLCD_control_Port,DIO_LOW);
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(CLCD_ENPIN,CLCD_control_Port,DIO_LOW);
	_delay_ms(1);

}
void CLCD_voidSendString(U8 *Copy_u8ptrString){
	U8 LOC_u8iteration=0;
	while(Copy_u8ptrString[LOC_u8iteration]!='\0'){
		CLCD_voidSendData(Copy_u8ptrString[LOC_u8iteration]);
		LOC_u8iteration++;
	}
}
void CLCD_voidSendNumber(U64 Copy_u64Number){
	U64 LOC_u64Revers=1;
	if(Copy_u64Number==0){
		CLCD_voidSendData('0');
	}else{
		while(Copy_u64Number!=0){
			LOC_u64Revers=(LOC_u64Revers*10)+(Copy_u64Number%10);
			Copy_u64Number/=10;
		}
	}
	while(LOC_u64Revers!=1){
		CLCD_voidSendData((LOC_u64Revers%10)+48);
		LOC_u64Revers/=10;
	}
}
void CLCD_voidSetPostion(U8 Copy_u8Raw,U8 Copy_u8Colum){
	if(Copy_u8Raw==CLCD_ROW_1){
		CLCD_voidSendCommand(CLCD_ROW1_Address+(Copy_u8Colum));
	}else if(Copy_u8Raw==CLCD_ROW_2){
		CLCD_voidSendCommand(CLCD_ROW2_Address+(Copy_u8Colum));
	}
}
/*void CLCD_voidDrawCharachter(void){
	CLCD_voidSendCommand(CLCD_Set_CGRAM);
	U8 LOC_u8ITERATION=0;
	for(LOC_u8ITERATION=0;LOC_u8ITERATION<(sizeof(CLCD_u8SptialChar))/(sizeof(CLCD_u8SptialChar[LOC_u8ITERATION]));LOC_u8ITERATION++){
		CLCD_voidSendData(CLCD_u8SptialChar[LOC_u8ITERATION]);
	}
	for(U8 I=0;I<3;I++){
			CLCD_voidSendData(I);
		}
}*/
void CLCD_voidDrawCharachter(void){
	CLCD_voidSendCommand(CLCD_Set_CGRAM);
	U8 LOC_u8ITERATION=0;
	for(LOC_u8ITERATION=0;LOC_u8ITERATION<(sizeof(CLCD_u8SptialChar))/(sizeof(CLCD_u8SptialChar[LOC_u8ITERATION]));LOC_u8ITERATION++){
			CLCD_voidSendData(CLCD_u8SptialChar[LOC_u8ITERATION]);
		}
}
void CLCD_voidClearDisplay(void){
	CLCD_voidSendCommand(0X1);
	_delay_ms(2);
}
void CLCD_voidClearLine(U8 Copy_u8Raw){
	if(Copy_u8Raw==CLCD_ROW_1){
		CLCD_voidSetPostion(CLCD_ROW_1,CLCD_COL_1);
		CLCD_voidSendString((U8*)"                ");
	}else if(Copy_u8Raw==CLCD_ROW_2){
		CLCD_voidSetPostion(CLCD_ROW_2,CLCD_COL_1);
	    CLCD_voidSendString((U8*)"                ");
	}
}
