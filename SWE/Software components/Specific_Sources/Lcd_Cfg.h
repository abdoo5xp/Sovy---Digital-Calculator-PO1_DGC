/*
 * Lcd_Cfg.h
 *
 *  Created on: Jan 24, 2021
 *      Author: abdoo
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_u8_4BITS_MODE			4
#define LCD_u8_8BITS_MODE			8
#define LCD_u8MODE				LCD_u8_8BITS_MODE

/*LCD Pin Assignation */

#define LCD_u8RS			DIO_u8PIN_1
#define LCD_u8RW			DIO_u8PIN_2
#define LCD_u8EN			DIO_u8PIN_3

#define LCD_u8D0			DIO_u8PIN_40
#define LCD_u8D1			DIO_u8PIN_39
#define LCD_u8D2			DIO_u8PIN_38
#define LCD_u8D3			DIO_u8PIN_37
#define LCD_u8D4			DIO_u8PIN_36
#define LCD_u8D5			DIO_u8PIN_35
#define LCD_u8D6			DIO_u8PIN_34
#define LCD_u8D7			DIO_u8PIN_33

//#define LCD_u8LEDA			DIO_u8PIN_22
//#define LCD_u8LEDK			DIO_u8PIN_23

#endif /* LCD_CFG_H_ */
