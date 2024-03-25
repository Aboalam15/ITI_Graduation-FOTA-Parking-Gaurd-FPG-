/*
 * LCD_program.c
 *
 *  Created on: Feb 6, 2024
 *      Author: MICHAEL
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/MGPIO/MGPIO_interface.h"
#include "../../MCAL/MSTK/MSTK_interface.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"


void CLCD_voidSendCommand(u8 copy_u8Command)
{
	/* RS = 0 */
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,MGPIO_u8LOW);
	/* RW = 0 */
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,MGPIO_u8LOW);

	#if (CLCD_MODE == EIGHT_BIT)
		/* Send Command */
		DIO_u8SetPortValue(CLCD_DATA_PORT,copy_u8Command);

		/* Enable */
		MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,MGPIO_u8HIGH);

		/* delay */
		_delay_ms(2);

		/* Disable */
		MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,MGPIO_u8LOW);

	#else

		///*Sending the higher nibble*/
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D4_ID, GET_BIT(copy_u8Command, 4));
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D5_ID, GET_BIT(copy_u8Command, 5));
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D6_ID, GET_BIT(copy_u8Command, 6));
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D7_ID, GET_BIT(copy_u8Command, 7));
		MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,MGPIO_u8HIGH);

		MSTK_voidSetBusyWait(16000);
		//_delay_ms(1);
		/*Sending the lower nibble*/
		MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,MGPIO_u8LOW); /*Falling edge to perform the instruction*/

		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D4_ID, GET_BIT(copy_u8Command, 0));
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D5_ID, GET_BIT(copy_u8Command, 1));
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D6_ID, GET_BIT(copy_u8Command, 2));
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D7_ID, GET_BIT(copy_u8Command, 3));
		MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,MGPIO_u8HIGH);
		MSTK_voidSetBusyWait(32000);
		//_delay_ms(2);

		MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,MGPIO_u8LOW); /*Falling edge to perform the instruction*/

		#endif

}

void CLCD_voidSendCharacter(u8 copy_u8Char)
{
	/* RS = 1 */
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,MGPIO_u8HIGH);
	/* RW = 0 */
	MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,MGPIO_u8LOW);

	#if (CLCD_MODE == EIGHT_BIT)
		/* Send Data */
		DIO_u8SetPortValue(CLCD_DATA_PORT,copy_u8Char);

		/* Enable */
		MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,MGPIO_u8HIGH);
		/* delay */
		_delay_ms(2);

		MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,MGPIO_u8LOW);
	#else
		/*Sending the higher nibble*/
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D4_ID, GET_BIT(copy_u8Char, 4));
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D5_ID, GET_BIT(copy_u8Char, 5));
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D6_ID, GET_BIT(copy_u8Char, 6));
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D7_ID, GET_BIT(copy_u8Char, 7));

		/* Enable */
		MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,MGPIO_u8HIGH);
		/* delay */
		MSTK_voidSetBusyWait(16000);
		//_delay_ms(1);

		MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,MGPIO_u8LOW);

		/*Sending the lower nibble*/
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D4_ID, GET_BIT(copy_u8Char, 0));
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D5_ID, GET_BIT(copy_u8Char, 1));
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D6_ID, GET_BIT(copy_u8Char, 2));
		MGPIO_voidSetPinValue(CLCD_DATA_PORT, D7_ID, GET_BIT(copy_u8Char, 3));
		/* Enable */
		MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,MGPIO_u8HIGH);
		/* delay */
		MSTK_voidSetBusyWait(32000);
		//_delay_ms(2);

		MGPIO_voidSetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,MGPIO_u8LOW);
		#endif


}

void CLCD_voidInit(void)
{
	//_delay_ms(35);
	MSTK_voidSetBusyWait(560000);

	#if (CLCD_MODE == EIGHT_BIT)
		/* Function set (8 bits mode ,2 lines , 5*7) */
		CLCD_voidSendCommand(0b00111000);
		/* Display ON/OFF  */
		CLCD_voidSendCommand(DISPLAY_CURSOR);
		/* Clear display  */
		CLCD_voidSendCommand(0b00000001);


	#else
		/* Function set (4 bits mode ,2 lines , 5*7) */
		CLCD_voidSendCommand(0b00000010);
		CLCD_voidSendCommand(0b00101000);
		/* Display ON/OFF  */
		CLCD_voidSendCommand(DISPLAY_CURSOR);

		/* Clear display  */
		CLCD_voidSendCommand(0b0000001);
		MSTK_voidSetBusyWait(16000);
		//_delay_ms(1);


	#endif
}

void CLCD_voidSendString(char *copy_pcString)
{
	u8 Local_u8Iterator=0;
	while ( copy_pcString[Local_u8Iterator] != '\0')
	{
		CLCD_voidSendCharacter(copy_pcString[Local_u8Iterator]);
		Local_u8Iterator++;
	}
}

void CLCD_voidClearDisplay(void)
{
	#if CLCD_MODE == EIGHT_BIT
		CLCD_voidSendCommand(0b00000001);
	#else
		CLCD_voidSendCommand(0b0000001);
		MSTK_voidSetBusyWait(16000);
		//_delay_ms(1);
	#endif
}

void CLCD_voidMoveCursor(u8 copy_u8Row, u8 copy_u8Col)
{
		u8 Local_u8Address = copy_u8Col + copy_u8Row*(0x40);
		SET_BIT(Local_u8Address,7);
		CLCD_voidSendCommand(Local_u8Address);
}

void CLCD_voidSendNum(s32 copy_u8Num)
{
	u8 Local_u8Digits[10],flag=0;
	s8 i=0;

	if(copy_u8Num == 0){
		CLCD_voidSendCharacter('0');
	}
	if(copy_u8Num < 0){
		copy_u8Num = copy_u8Num * -1;
		flag = 1;
	}
	while(copy_u8Num != 0)
	{
		Local_u8Digits[i] = copy_u8Num % 10;
		copy_u8Num = copy_u8Num / 10;
		i++;
	}
	i--;

	if(flag == 1){
		CLCD_voidSendCharacter('-');
	}

	while(i >=0 )
	{
		CLCD_voidSendCharacter(Local_u8Digits[i]+'0');
		i--;
	}

}

void CLCD_Custom_Char(u8 loc, u8 *msg)
{
    u8 i;
    if(loc<8)
    {
     CLCD_voidSendCommand(0x40 + (loc*8));  /* Command 0x40 and onwards forces the device to point CGRAM address */
       for(i=0;i<8;i++)  /* Write 8 byte for generation of 1 character */
           CLCD_voidSendCharacter(msg[i]);
    }
		/* Return cursor to home*/
		CLCD_voidSendCommand(0x80);

}

void CLCD_voidCursorShift(u8 copy_u8CursorDir)
{
	switch(copy_u8CursorDir)
	{
		case 0:	CLCD_voidSendCommand(0b00010000); break;
		case 1:	CLCD_voidSendCommand(0b00010100); break;
		case 2:	CLCD_voidSendCommand(0b00011000); break;
		case 3:	CLCD_voidSendCommand(0b00011100); break;

	}

}



void CLCD_voidSendCharPosition(u8 copy_u8Char,u8 copy_u8Row, u8 copy_u8Col)
{
	/* Set cursor poisiton */
	CLCD_voidMoveCursor(copy_u8Row,copy_u8Col);
	CLCD_voidSendCharacter(copy_u8Char);

}



void CLCD_voidSendNumPosition(s32 copy_u8Num,u8 copy_u8Row, u8 copy_u8Col)
{
	/* Set cursor poisiton */
	CLCD_voidMoveCursor(copy_u8Row,copy_u8Col);
	CLCD_voidSendNum(copy_u8Num);

}

void CLCD_voidSendStringPosition(char *copy_pcString,u8 copy_u8Row, u8 copy_u8Col)
{
	CLCD_voidMoveCursor(copy_u8Row,copy_u8Col);
	CLCD_voidSendString(copy_pcString);
}


