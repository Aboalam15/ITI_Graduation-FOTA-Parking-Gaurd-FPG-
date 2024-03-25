/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MNVIC_program.c -> Functions impelemntations
peri		: for the developer in MCAL only not for the user
*/

/*********************************************/
/*********************************************/

/***************	NVIC Files include	***************/
/*Standard LIBS*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*NVIC files*/
#include "MNVIC_interface.h"
#include "MNVIC_private.h"
#include "MNVIC_config.h"
#include "MNVIC_register.h"

/*********************************************/
/*********************************************/

/***************	NVIC Functions Implementations	***************/


/*****************************************************************************************/
/* @Name  	  :->		@ MNVIC_voidEnableInterrupt										 */
/* @Brief 	  :->		@ used to Enable the wanted to Active needed interrupt       	 */
/*						@ all vector interrupts are initially disabled					 */
/* @parameters   :-> 	@ Copy_u8IntPOSTION: interrupt line/ number in the NVector table */
/* @PreRequsteis :->	@ RCC peripheral Clock must be Enabled					 		 */
/*****************************************************************************************/
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntPOSTION){
	MNVIC->ISER[Copy_u8IntPOSTION/32] = (1<<(Copy_u8IntPOSTION%32));	/*Enabling the interrupt using ISER register */
}
/*****************************************************************************************/
/* @Name  	  :->		@ MNVIC_voidDisableInterrupt									 */
/* @Brief 	  :->		@ used to Disable the Active not needed interrupt       	     */
/*						@ all vector interrupts are initially disabled					 */
/* @parameters   :-> 	@ Copy_u8IntPOSTION: interrupt line/ number in the NVector table */
/* @PreRequsteis :->	@ RCC peripheral Clock must be Enabled					 		 */
/*****************************************************************************************/
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntPOSTION){
	MNVIC->ICER[Copy_u8IntPOSTION/32]= (1<<(Copy_u8IntPOSTION%32));		/*Disabling the interrupt using ICER register */
}
/*****************************************************************************************/
/* @Name  	  :->		@ MNVIC_voidSetInterruptGroupMode								 */
/* @Brief 	  :->		@ used to Activate interrupt Priority Grouping 		       	     */
/*						@ all vector interrupts are initially disabled					 */
/* @parameters   :-> 	@ Copy_udtGroupMode: the chosen grouping and subgrouping type	 */
/* @PreRequsteis :->	@ RCC peripheral Clock must be Enabled					 		 */
/*****************************************************************************************/
void MNVIC_voidSetInterruptGroupMode(MNVIC_GROUPMODE_t Copy_udtGroupMode){
	MSCB_AICR = MNVIC_VECTKEY;
	MSCB_AICR |= MNVIC_VECTKEY|(Copy_udtGroupMode<<8);
}
/*****************************************************************************************/
/* @Name  	  :->		@ MNVIC_voidSetInterruptPeriority								 */
/* @Brief 	  :->		@ used to set Priority (group/subgroup) for each active interrupt*/
/*						@ all vector interrupts are initially disabled					 */
/* @parameters   :-> 	@ Copy_u8IntPOSTION: interrupt line/ number in the NVector table */
/*						@ Copy_u8Group: which priority Group to set the interrupt in 	 */
/* 						@ Copy_u8SubGroup:which priority SubGroup to set the interrupt in*/
/* 						@ Copy_udtGroupMode: the chosen grouping and subgrouping type	 */
/* @PreRequsteis :->	@ RCC peripheral Clock must be Enabled					 		 */
/*****************************************************************************************/
void MNVIC_voidSetInterruptPeriority(u8 Copy_u8IntPOSTION,u8 Copy_u8Group,u8 Copy_u8SubGroup,MNVIC_GROUPMODE_t Copy_udtGroupMode){
u8 Local_u8PriValue=0;								/*local var to initialize grouping mode for each interrupt before setting it to the interrupt */
switch(Copy_udtGroupMode){
case MNVIC_GROUPMODE_G16S0: Local_u8PriValue= Copy_u8Group; break;							/*setting grouping Mode to 16 main group 0 sub groups*/
case MNVIC_GROUPMODE_G8S2 : Local_u8PriValue= (Copy_u8Group<<1)|(Copy_u8SubGroup);break;	/*setting grouping Mode to 8 main group 2 sub groups*/
case MNVIC_GROUPMODE_G4S4 : Local_u8PriValue= (Copy_u8Group<<2)|(Copy_u8SubGroup);break;	/*setting grouping Mode to 4 main group 4 sub groups*/
case MNVIC_GROUPMODE_G2S8 : Local_u8PriValue= (Copy_u8Group<<3)|(Copy_u8SubGroup);break;	/*setting grouping Mode to 2 main group 8 sub groups*/
case MNVIC_GROUPMODE_G0S16: Local_u8PriValue= Copy_u8SubGroup; break;						/*setting grouping Mode to 0 main group 16 sub groups*/
}
MNVIC->IPR[Copy_u8IntPOSTION] = (Local_u8PriValue<<4);										/*setting the group and sub group to the interrupt*/
}

/*****************************************************************************************/
/* @Name  	  :->		@ MNVIC_voidEnableInterruptPending								 */
/* @Brief 	  :->		@ used to Activate interrupt pending							 */
/*						@ all vector interrupts are initially disabled					 */
/* @parameters   :-> 	@ Copy_u8IntPOSTION: interrupt line/ number in the NVector table */
/* @PreRequsteis :->	@ RCC peripheral Clock must be Enabled					 		 */
/*****************************************************************************************/
void MNVIC_voidEnableInterruptPending(u8 Copy_u8IntPOSTION){
	MNVIC->ISPR[Copy_u8IntPOSTION/32]= (1<<(Copy_u8IntPOSTION%32));	/*setting interrupt pending bits in the ISPR register for the interrupt*/
}
/*****************************************************************************************/
/* @Name  	  :->		@ MNVIC_voidDisableInterruptPending								 */
/* @Brief 	  :->		@ used to Disable interrupt pending							 	 */
/*						@ all vector interrupts are initially disabled					 */
/* @parameters   :-> 	@ Copy_u8IntPOSTION: interrupt line/ number in the NVector table */
/* @PreRequsteis :->	@ RCC peripheral Clock must be Enabled					 		 */
/*****************************************************************************************/
void MNVIC_voidDisableInterruptPending(u8 Copy_u8IntPOSTION){
	MNVIC->ICPR[Copy_u8IntPOSTION/32]= (1<<(Copy_u8IntPOSTION%32));		/*clearing interrupt pending bits in the ICPR register for the interrupt*/
}
/*****************************************************************************************/
/* @Name  	  :->		@ MNVIC_u8ISInterruptActive										 */
/* @Brief 	  :->		@ used to check on an interrupt being Active/notActive		 	 */
/*						@ all vector interrupts are initially disabled					 */
/*						@ Returns u8 value of the current state of the interrupt		 */
/* @parameters   :-> 	@ Copy_u8IntPOSTION: interrupt line/ number in the NVector table */
/* @PreRequsteis :->	@ RCC peripheral Clock must be Enabled					 		 */
/*****************************************************************************************/
u8 MNVIC_u8ISInterruptActive(u8 Copy_u8IntPOSTION){
 return GET_BIT(MNVIC->IABR[Copy_u8IntPOSTION/32],Copy_u8IntPOSTION%32);		/*Returning the value of IABR register corresponding to the interrupt state*/
}
