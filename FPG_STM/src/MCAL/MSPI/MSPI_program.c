/*
 * MSPI_program.c
 *
 *  Created on: Jan 22, 2024
 *      Author: MICHAEL
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../MSPI/MSPI_interface.h"
#include "../MSPI/MSPI_register.h"
#include "MSPI_config.h"



void MSPI_voidInit()
{
	 /* DFF=0	For data frame format
	  * TO DO --> Config
	  * */
	CLR_BIT(MSPI1->CR1,11);
	 /* LSBFIRST=0	MSB first */
	CLR_BIT(MSPI1->CR1,7);
	 /* MSTR=0	slave*/
	CLR_BIT(MSPI1->CR1,2);
	 /* CPOL=1	Polarity high*/
	SET_BIT(MSPI1->CR1,1);
	/* CPHA=1	write first*/
	SET_BIT(MSPI1->CR1,0);
	/*Enable MSPI */
	SET_BIT(MSPI1->CR1,6);
    /* SSM and SSI bits must be set in Slave program */
	SET_BIT(MSPI1->CR1,8);
	SET_BIT(MSPI1->CR1,9);

}

u8 MSPI_u8Transceive(u8 Copy_u8Data)
{
	MSPI1->DR = Copy_u8Data;

	while(!(GET_BIT(MSPI1->SR, 1)) || !(GET_BIT(MSPI1->SR, 0)));

	return MSPI1->DR;
}


