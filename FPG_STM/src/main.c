#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MSTK/MSTK_interface.h"
#include "HAL/LCD/LCD_interface.h"

int main()
{
	MRCC_voidInitializeSystemClock();
	MRCC_voidEnablePeripheralClock(MRCC_AHB1,MRCC_GPIOB_EN);

	MGPIO_voidSetPinMode(MGPIO_u8PORTB,0,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTB,1,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTB,2,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTB,4,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTB,5,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTB,6,MGPIO_u8OUTPUT);
	MGPIO_voidSetPinMode(MGPIO_u8PORTB,7,MGPIO_u8OUTPUT);

	CLCD_voidInit();
	CLCD_voidSendCharacter('M');
	while(1)
	{

	}

}
