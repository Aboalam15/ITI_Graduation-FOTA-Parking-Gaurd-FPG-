/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MDMA_interface.h -> functions prototypes
peri		: for the developer in MCAL only not for the user
*/
#ifndef MDMA_MDMA_INTERFACE_H_
#define MDMA_MDMA_INTERFACE_H_

/**************************/
#define  MDMA_u8STREM0   	0
#define  MDMA_u8STREM1   	1
#define  MDMA_u8STREM2  	2
#define  MDMA_u8STREM3   	3
#define  MDMA_u8STREM4   	4
#define  MDMA_u8STREM5   	5
#define  MDMA_u8STREM6   	6
#define  MDMA_u8STREM7   	7



/********************************/
void MDMA1_voidInit(void);

void MDMA1_voidSetStream(u8 Copy_u8StreamID, u32* Copy_pu32SrcAddress, u32* Copy_pu32DesAddress,u32 Copy_u32BlockSize);

void MDMA1_voidEnableStream(u8 Copy_u8StreamID);

void MDMA1_voidSetStreamcallBack(u8 Copy_u8StreamID,void (*pv_Function)(void));
/************************************/
void MDMA2_voidInit(void);

void MDMA2_voidSetStream(u8 Copy_u8StreamID, u32* Copy_pu32SrcAddress, u32* Copy_pu32DesAddress,u32 Copy_u32BlockSize);

void MDMA2_voidEnableStream(u8 Copy_u8StreamID);

void MDMA2_voidSetStreamcallBack(u8 Copy_u8StreamID,void (*pv_Function)(void));

#endif /* MDMA_MDMA_INTERFACE_H_ */
