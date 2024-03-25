/*
 * LCD_config.h
 *
 *  Created on: Feb 6, 2024
 *      Author: MICHAEL
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_


/* Options:
	1- DIO_u8PORTA
	2- DIO_u8PORTB
	3- DIO_u8PORTC
	4- DIO_u8PORTD
*/

#define CLCD_CTRL_PORT	MGPIO_u8PORTB
#define CLCD_RS_PIN		0
#define CLCD_RW_PIN		1
#define CLCD_E_PIN		2


#define CLCD_DATA_PORT	MGPIO_u8PORTB

/*Case of 4bit mode this is used*/
#define D4_ID 4
#define D5_ID 5
#define D6_ID 6
#define D7_ID 7

#define DISPLAY_CURSOR			CURSOR_ON

#define CLCD_MODE FOUR_BIT



#endif /* HAL_LCD_LCD_CONFIG_H_ */
