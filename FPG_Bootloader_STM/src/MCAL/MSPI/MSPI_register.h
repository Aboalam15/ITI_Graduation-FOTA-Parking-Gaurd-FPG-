/*
 * MSPI_register.h
 *
 *  Created on: Jan 22, 2024
 *      Author: MICHAEL
 */

#ifndef MSPI_MSPI_REGISTER_H_
#define MSPI_MSPI_REGISTER_H_



#define MSPI_BASE_ADDRESS	0x40013000

typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}MSPI_t;

#define MSPI1 	((volatile MSPI_t*)(MSPI_BASE_ADDRESS))




#endif /* MSPI_MSPI_REGISTER_H_ */
