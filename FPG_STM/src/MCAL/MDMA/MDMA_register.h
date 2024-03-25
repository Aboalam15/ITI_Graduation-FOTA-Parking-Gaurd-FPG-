/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MDMA_register.h -> registers address
peri		: for the developer in MCAL only not for the user
*/
#ifndef MDMA_MDMA_REGISTER_H_
#define MDMA_MDMA_REGISTER_H_

#define 	MDMA1_BASE_ADDRESS		0x40026000
#define     MDMA2_BASE_ADDRESS		0x40026400

typedef struct{
	volatile u32 CR;
	volatile u32 NDTR;
	volatile u32 PAR;
	volatile u32 M0AR;
	volatile u32 M1AR;
	volatile u32 FCR;
}DMA_stream_t;

typedef struct{
	volatile u32 LISR;
	volatile u32 HISR;
	volatile u32 LIFCR;
	volatile u32 HIFCR;
	DMA_stream_t S[8];
}DMA_MEMORY_t;


#define DMA1 	((volatile DMA_MEMORY_t*)(MDMA1_BASE_ADDRESS))
#define DMA2 	((volatile DMA_MEMORY_t*)(MDMA2_BASE_ADDRESS))

#endif /* MDMA_MDMA_REGISTER_H_ */
