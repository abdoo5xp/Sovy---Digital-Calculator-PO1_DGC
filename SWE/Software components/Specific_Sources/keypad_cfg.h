/*
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!     \file     Keypad_cfg.h
 *      \brief    configurations for keypad module
 *
 *********************************************************************************************************************/
#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#define KEYPAD_u8col_1_pin      DIO_u8PIN3         //PA3  output
#define KEYPAD_u8col_2_pin      DIO_u8PIN2         //PA2  output
#define KEYPAD_u8col_3_pin      DIO_u8PIN1         //PA1  output
#define KEYPAD_u8col_4_pin      DIO_u8PIN0         //PA0  output

#define KEYPAD_u8row_1_pin      DIO_u8PIN7         //PA7  input
#define KEYPAD_u8row_2_pin      DIO_u8PIN6         //PA6  input
#define KEYPAD_u8row_3_pin      DIO_u8PIN5         //PA5  input
#define KEYPAD_u8row_4_pin      DIO_u8PIN4         //PA4  input

#define KEYPAD_u8row_1_col_1_pin   '7'
#define KEYPAD_u8row_1_col_2_pin   '8'
#define KEYPAD_u8row_1_col_3_pin   '9'
#define KEYPAD_u8row_1_col_4_pin   '/'

#define KEYPAD_u8row_2_col_1_pin   '4'
#define KEYPAD_u8row_2_col_2_pin   '5'
#define KEYPAD_u8row_2_col_3_pin   '6'
#define KEYPAD_u8row_2_col_4_pin   '*'

#define KEYPAD_u8row_3_col_1_pin   '1'
#define KEYPAD_u8row_3_col_2_pin   '2'
#define KEYPAD_u8row_3_col_3_pin   '3'
#define KEYPAD_u8row_3_col_4_pin   '-'

#define KEYPAD_u8row_4_col_1_pin   'C'
#define KEYPAD_u8row_4_col_2_pin   '0'
#define KEYPAD_u8row_4_col_3_pin   '='
#define KEYPAD_u8row_4_col_4_pin   '+'



#endif /* KEYPAD_CFG_H_ */
