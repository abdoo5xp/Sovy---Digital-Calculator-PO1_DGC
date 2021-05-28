/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!     \file     Keypad.c
 *      \brief    implementation of keypad functions
 *      \details  defines arrays for keypad keys and implements function Keypad_u8GetKey
 *
 *********************************************************************************************************************/

#include "../lib/Bit_Math.h"
#include "../lib/Std_Types.h"
#include "util/delay.h"
#include "Dio_int.h"
#include "keypad_cfg.h"
#include "keypad_int.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef FCPU
#define FCPU 8000000


/*! \static
 *  \brief     Array that stores keypad configured pins value
 *
 * */
static u8 loc_au8keypadCfgKeys[KEYPAD_u8ROW_NUM][KEYPAD_u8COL_NUM]={
			{KEYPAD_u8row_1_col_1_pin,KEYPAD_u8row_1_col_2_pin,KEYPAD_u8row_1_col_3_pin,KEYPAD_u8row_1_col_4_pin}
		   ,{KEYPAD_u8row_2_col_1_pin,KEYPAD_u8row_2_col_2_pin,KEYPAD_u8row_2_col_3_pin,KEYPAD_u8row_2_col_4_pin}
		   ,{KEYPAD_u8row_3_col_1_pin,KEYPAD_u8row_3_col_2_pin,KEYPAD_u8row_3_col_3_pin,KEYPAD_u8row_3_col_4_pin}
		   ,{KEYPAD_u8row_4_col_1_pin,KEYPAD_u8row_4_col_2_pin,KEYPAD_u8row_4_col_3_pin,KEYPAD_u8row_4_col_4_pin}
	};

/*! \static
 *  \brief     Array that stores keypad actual pins value
 *
 * */
static u8 Keypad_au8KeypadPinsArr[]= {
	KEYPAD_u8row_1_pin,
	KEYPAD_u8row_2_pin,
	KEYPAD_u8row_3_pin,
	KEYPAD_u8row_4_pin,
    KEYPAD_u8col_1_pin,
    KEYPAD_u8col_2_pin,
    KEYPAD_u8col_3_pin,
    KEYPAD_u8col_4_pin
};

/**********************************************************************************************************************
 *  LOCAL FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  ReturnStatus_e Keypad_u8GetKey(u8* pu8keyPressed)
 *********************************************************************************************************************/
/*! \details       determines which key is pressed on the keypad and if no key is pressed
 *  \param[in]     None
 *  \param[in,out] None
 *  \param[out]    u8 * pu8keyPressed
 *  \return        ReturnStatus_e
 *  \pre           None
 *  \context       TASK
 *********************************************************************************************************************/
ReturnStatus_e Keypad_u8GetKey(u8 * pu8keyPressed)
{
	ReturnStatus_e returnStatus = E_OK;
	u8 Loc_keyPressed;

	u8 loc_u8row_idx=0;
	u8 loc_u8col_idx=0;

	*pu8keyPressed=KEYPAD_u8NO_KEY;
	for (loc_u8col_idx=0;loc_u8col_idx < KEYPAD_u8COL_NUM ;loc_u8col_idx++) {
		Dio_vidSetPinVal(Keypad_au8KeypadPinsArr[loc_u8col_idx+4],DIO_u8LOW);

		for (loc_u8row_idx=0;loc_u8row_idx < KEYPAD_u8ROW_NUM ;loc_u8row_idx++)  {
			Loc_keyPressed= Dio_u8GetPinVal(Keypad_au8KeypadPinsArr[loc_u8row_idx]);
			if (!Loc_keyPressed){
				_delay_ms(10);                           /*delay for debouncing*/
				Loc_keyPressed= Dio_u8GetPinVal(Keypad_au8KeypadPinsArr[loc_u8row_idx]); /*read again for debouncing*/
				if (!Loc_keyPressed){
					*pu8keyPressed = loc_au8keypadCfgKeys[loc_u8row_idx][loc_u8col_idx];
				}
			}
		}
		Dio_vidSetPinVal(Keypad_au8KeypadPinsArr[loc_u8col_idx+4],DIO_u8HIGH);
	}
	return returnStatus;
}
