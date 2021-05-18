/*
 * Lcd_Int.h
 *
 *  Created on: Jan 24, 2021
 *      Author: abdoo
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

/*Packet Data Types */
#define IS_CMD						0
#define IS_DATA 					1

/* LCD Commands*/
#define	LCD_CMD_CLEAR				BIT_MASK_0
#define LCD_CMD_HOME				BIT_MASK_1

#define LCD_CMD_ENTRY_L				BIT_MASK_2 | BIT_MASK_1
#define LCD_CMD_ENTRY_R				BIT_MASK_2
#define LCD_CMD_SHIFT_EN			BIT_MASK_2 | BIT_MASK_0
#define LCD_CMD_SHIFT_DIS			BIT_MASK_2

#define LCD_CMD_DISP_ON				BIT_MASK_3 | BIT_MASK_2
#define LCD_CMD_DISP_OFF			BIT_MASK_3
#define LCD_CMD_CURSOR_ON			BIT_MASK_3 | BIT_MASK_1
#define LCD_CMD_CURSOR_OFF			BIT_MASK_3
#define LCD_CMD_BLINKING_ON			BIT_MASK_3 | BIT_MASK_0
#define LCD_CMD_BLINKING_OFF		BIT_MASK_3

#define LCD_CMD_SHIFT_CUR_L			BIT_MASK_4
#define LCD_CMD_SHIFT_CUR_R			BIT_MASK_4 | BIT_MASK_2
#define LCD_CMD_SHIFT_DISP_L		BIT_MASK_4 | BIT_MASK_3
#define LCD_CMD_SHIFT_DISP_R		BIT_MASK_4 | BIT_MASK_2 | BIT_MASK_3


#define LCD_CMD_ONE_LINE			BIT_MASK_5
#define LCD_CMD_TWO_LINE			BIT_MASK_5 | BIT_MASK_3
#define LCD_CMD_FONT_5x7			BIT_MASK_5
#define LCD_CMD_FONT_5x10			BIT_MASK_5 | BIT_MASK_2

/* NOTE:One of these cmd must be sent before performing any read operation */
#define LCD_CMD_SET_CGRAM_ADD		BIT_MASK_6
#define LCD_CMD_SET_DDRAM_ADD		BIT_MASK_7

#define LCD_DDRAM_FIRST_ROW_ADD		0x80
#define LCD_DDRAM_SECOND_ROW_ADD	0xC0



ReturnStatus_e Lcd_Init(void);

ReturnStatus_e Lcd_Send_Packet(u8 Copy_u8Data,u8 Copy_DataType);

ReturnStatus_e Lcd_GoTo(u8 Copy_u8Row, u8 Copy_u8Col);

ReturnStatus_e Lcd_WriteString(u8 *Copy_pu8String);


#endif /* LCD_INT_H_ */
