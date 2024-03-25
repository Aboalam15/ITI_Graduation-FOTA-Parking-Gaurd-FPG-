/*
Author		: Muhammed Sherif Attia
date		: 10/1/2024
version		: 1.0.0
description : MNVIC_interface.h -> functions prototypes
peri		: for the developer in MCAL only not for the user
*/

#ifndef MNVIC_MNVIC_INTERFACE_H_
#define MNVIC_MNVIC_INTERFACE_H_
/*****************************************************/
/*****************************************************/

/***************	user defined data types		***************/
/* grouping modes */
typedef enum{
	MNVIC_GROUPMODE_G16S0 = 3,
	MNVIC_GROUPMODE_G8S2	,
	MNVIC_GROUPMODE_G4S4	,
	MNVIC_GROUPMODE_G2S8	,
	MNVIC_GROUPMODE_G0S16
}MNVIC_GROUPMODE_t;
/*****************************************************/
/*****************************************************/



#define TIMER2_POS	28
#define TIMER3_POS	29
#define TIMER4_POS	30
#define USART1_POS	37
#define USART2_POS	38



/***************	Function Prototypes		***************/
/*****************************************************************************************/
/* @Name  	  :->		@ MNVIC_voidEnableInterrupt										 */
/* @Brief 	  :->		@ used to Enable the wanted to Active needed interrupt       	 */
/*						@ all vector interrupts are initially disabled					 */
/* @parameters   :-> 	@ Copy_u8IntPOSTION: interrupt line/ number in the NVector table */
/* @PreRequsteis :->	@ RCC peripheral Clock must be Enabled					 		 */
/*****************************************************************************************/
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntPOSTION);
/*****************************************************************************************/
/* @Name  	  :->		@ MNVIC_voidDisableInterrupt									 */
/* @Brief 	  :->		@ used to Disable the Active not needed interrupt       	     */
/*						@ all vector interrupts are initially disabled					 */
/* @parameters   :-> 	@ Copy_u8IntPOSTION: interrupt line/ number in the NVector table */
/* @PreRequsteis :->	@ RCC peripheral Clock must be Enabled					 		 */
/*****************************************************************************************/
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntPOSTION);
/*****************************************************************************************/
/* @Name  	  :->		@ MNVIC_voidSetInterruptGroupMode								 */
/* @Brief 	  :->		@ used to Activate interrupt Priority Grouping 		       	     */
/*						@ all vector interrupts are initially disabled					 */
/* @parameters   :-> 	@ Copy_udtGroupMode: the chosen grouping and subgrouping type	 */
/* @PreRequsteis :->	@ RCC peripheral Clock must be Enabled					 		 */
/*****************************************************************************************/
void MNVIC_voidSetInterruptGroupMode(MNVIC_GROUPMODE_t Copy_udtGroupMode);
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
void MNVIC_voidSetInterruptPeriority(u8 Copy_u8IntPOSTION,u8 Copy_u8Group,u8 Copy_u8SubGroup,MNVIC_GROUPMODE_t Copy_udtGroupMode);
/*****************************************************************************************/
/* @Name  	  :->		@ MNVIC_voidEnableInterruptPending								 */
/* @Brief 	  :->		@ used to Activate interrupt pending							 */
/*						@ all vector interrupts are initially disabled					 */
/* @parameters   :-> 	@ Copy_u8IntPOSTION: interrupt line/ number in the NVector table */
/* @PreRequsteis :->	@ RCC peripheral Clock must be Enabled					 		 */
/*****************************************************************************************/
void MNVIC_voidEnableInterruptPending(u8 Copy_u8IntPOSTION);
/*****************************************************************************************/
/* @Name  	  :->		@ MNVIC_voidDisableInterruptPending								 */
/* @Brief 	  :->		@ used to Disable interrupt pending							 	 */
/*						@ all vector interrupts are initially disabled					 */
/* @parameters   :-> 	@ Copy_u8IntPOSTION: interrupt line/ number in the NVector table */
/* @PreRequsteis :->	@ RCC peripheral Clock must be Enabled					 		 */
/*****************************************************************************************/
void MNVIC_voidDisableInterruptPending(u8 Copy_u8IntPOSTION);
/*****************************************************************************************/
/* @Name  	  :->		@ MNVIC_u8ISInterruptActive										 */
/* @Brief 	  :->		@ used to check on an interrupt being Active/notActive		 	 */
/*						@ all vector interrupts are initially disabled					 */
/*						@ Returns u8 value of the current state of the interrupt		 */
/* @parameters   :-> 	@ Copy_u8IntPOSTION: interrupt line/ number in the NVector table */
/* @PreRequsteis :->	@ RCC peripheral Clock must be Enabled					 		 */
/*****************************************************************************************/
u8 MNVIC_u8ISInterruptActive(u8 Copy_u8IntPOSTION);


#endif /* MNVIC_MNVIC_INTERFACE_H_ */
