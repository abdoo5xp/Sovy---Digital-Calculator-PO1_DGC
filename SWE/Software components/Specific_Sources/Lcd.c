/*
 * Lcd.c
 *
 *  Created on: Jan 24, 2021
 *      Author: abdoo
 */

#undef F_CPU
#define F_CPU 8000000
#include <util/delay.h>
#include "../../lib/Bit_Math.h"
#include "../../lib/Std_Types.h"
#include "../../lib/ATmega32_Registers.h"
#include "../../lib/Bit_Mask.h"
#include "Dio_Int.h"
#include "Lcd_Int.h"
#include "Lcd_Cfg.h"

#define NULL 						( (void *)0)
#define LCD_CMD_DL_8				BIT_MASK_5 | BIT_MASK_4
#define LCD_CMD_DL_4				BIT_MASK_5 | BIT_MASK_4
#define RT_ERROR					2
#define RT_PARAM					1
#define RT_SUCCESS					0


const u8 LCD_u8arrDataPins[LCD_u8MODE]={
#if LCD_u8MODE == LCD_u8_8BITS_MODE
				LCD_u8D0,
				LCD_u8D1,
				LCD_u8D2,
				LCD_u8D3,
#endif
				LCD_u8D4,
				LCD_u8D5,
				LCD_u8D6,
				LCD_u8D7
};

ReturnStatus_e Lcd_Init(void){
#if LCD_u8MODE == LCD_u8_8BITS_MODE
		//initialize the lcd for the code for 8 bits mode
_delay_ms(30);
LCD_u8Send_Packet(LCD_CMD_DL_8|LCD_CMD_TWO_LINE|LCD_CMD_FONT_5x7,IS_CMD);
_delay_us(40);
LCD_u8Send_Packet(LCD_CMD_DISP_ON |LCD_CMD_CURSOR_OFF|LCD_CMD_BLINKING_OFF,IS_CMD);
_delay_us(40);
LCD_u8Send_Packet(LCD_CMD_CLEAR,IS_CMD);
_delay_ms(1.5);
LCD_u8Send_Packet(LCD_CMD_ENTRY_L|LCD_CMD_SHIFT_DIS,IS_CMD);
_delay_us(40);
#endif

#if LCD_u8MODE == LCD_u8_4BITS_MODE
//initialize the lcd for the code for 4 bits mode
#endif
return RT_SUCCESS;
}

ReturnStatus_e Lcd_Send_Packet(u8 Copy_u8Data,u8 Copy_u8DataType){
	u8 Loc_u8PinsIdx;
	Dio_u8SetPinVal(LCD_u8RS,Copy_u8DataType);
	Dio_u8SetPinVal(LCD_u8RW,DIO_u8LOW);
	Dio_u8SetPinVal(LCD_u8EN,DIO_u8HIGH);

	/*Sending Data*/
	for(Loc_u8PinsIdx = 0;Loc_u8PinsIdx <LCD_u8MODE;Loc_u8PinsIdx++ ){
		Dio_u8SetPinVal(LCD_u8arrDataPins[Loc_u8PinsIdx], GET_BIT(Copy_u8Data,Loc_u8PinsIdx) );
	}
	/*setting the enable pin to low to get the falling edge that will make the lcd mcu read the data in DR*/
	Dio_u8SetPinVal(LCD_u8EN,DIO_u8LOW);

	/*waiting time for the command/data to be executed */
	_delay_ms(1.5);

	return RT_SUCCESS;
}

ReturnStatus_e Lcd_u8WriteString(u8 *Copy_pu8String){
	if(Copy_pu8String == NULL){
		return RT_PARAM;
	}
	u32 Loc_Character_Idx =0;
	while(Copy_pu8String[Loc_Character_Idx] != '\0'){
		LCD_u8Send_Packet(Copy_pu8String[Loc_Character_Idx],IS_DATA);
		Loc_Character_Idx++;
	}
	return RT_SUCCESS;
}

ReturnStatus_e Lcd_GoTo(u8 Copy_u8Row, u8 Copy_u8Col){

	if(	Copy_u8Col > 16 ||
		(Copy_u8Row != LCD_DDRAM_FIRST_ROW_ADD &&
		Copy_u8Row != LCD_DDRAM_SECOND_ROW_ADD)
		)
	{
		return RT_PARAM;
	}

	LCD_u8Send_Packet(LCD_CMD_SET_DDRAM_ADD | Copy_u8Row | Copy_u8Col,IS_CMD);

	return RT_SUCCESS;
}



