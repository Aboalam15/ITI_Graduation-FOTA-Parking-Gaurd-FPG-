/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MRCC_register.h -> registers address
peri		: for the developer in MCAL only not for the user
*/


#ifndef MRCC_MRCC_REGISTERS_H_
#define MRCC_MRCC_REGISTERS_H_
/*****************************************************/
/*****************************************************/

/***************	RCC BaseAddress		***************/

	#define 	MRCC_BASE_ADREES	0x40023800


/*****************************************************/
/*****************************************************/

/***************	RCC Registers		***************/

#define 	MRCC_CR 				(*((volatile u32*)(MRCC_BASE_ADREES+0x00)))
#define 	MRCC_PLLCFGR 			(*((volatile u32*)(MRCC_BASE_ADREES+0x04)))
#define 	MRCC_CFGR	 			(*((volatile u32*)(MRCC_BASE_ADREES+0x08)))
#define 	MRCC_CIR 				(*((volatile u32*)(MRCC_BASE_ADREES+0x0C)))
#define 	MRCC_AHB1RSTR 			(*((volatile u32*)(MRCC_BASE_ADREES+0x10)))
#define 	MRCC_AHB2RSTR 			(*((volatile u32*)(MRCC_BASE_ADREES+0x14)))
#define 	MRCC_APB1RSTR	 		(*((volatile u32*)(MRCC_BASE_ADREES+0x20)))
#define 	MRCC_APB2RSTR 			(*((volatile u32*)(MRCC_BASE_ADREES+0x24)))
#define 	MRCC_AHB1ENR 			(*((volatile u32*)(MRCC_BASE_ADREES+0x30)))
#define 	MRCC_AHB2ENR 			(*((volatile u32*)(MRCC_BASE_ADREES+0x34)))
#define 	MRCC_APB1ENR 			(*((volatile u32*)(MRCC_BASE_ADREES+0x40)))
#define 	MRCC_APB2ENR 			(*((volatile u32*)(MRCC_BASE_ADREES+0x44)))
#define 	MRCC_AHB1LPENR 			(*((volatile u32*)(MRCC_BASE_ADREES+0x50)))
#define 	MRCC_AHB2LPENR 			(*((volatile u32*)(MRCC_BASE_ADREES+0x54)))
#define 	MRCC_APB1LPENR 			(*((volatile u32*)(MRCC_BASE_ADREES+0x60)))
#define 	MRCC_APB2LPENR 			(*((volatile u32*)(MRCC_BASE_ADREES+0x64)))
#define 	MRCC_BDCR 				(*((volatile u32*)(MRCC_BASE_ADREES+0x70)))
#define 	MRCC_CSR 				(*((volatile u32*)(MRCC_BASE_ADREES+0x74)))
#define 	MRCC_SSCGR 				(*((volatile u32*)(MRCC_BASE_ADREES+0x80)))
#define 	MRCC_PLLI2SCFGR 		(*((volatile u32*)(MRCC_BASE_ADREES+0x84)))
#define 	MRCC_DCKCFGR	 		(*((volatile u32*)(MRCC_BASE_ADREES+0x8C)))









/*****************************************************/
/*****************************************************/
#endif /* MRCC_MRCC_REGISTERS_H_ */
