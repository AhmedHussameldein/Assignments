/*
 * Timer_CFG.h
 *
 * Created: 9/23/2022 8:07:35 PM
 *  Author: AMIT
 */ 


#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

#include "DIO.h"
#include "Interrupts.h"

#define MC_Freq_Mhz				16

/*Timer0 Mode*/
#define Timer0_Mode				Timer0_OVF
#define Timer0_CLK				Timer0_Freq_1024
#define Timer0_Freq_Divider		Timer0_Freq_Div_1024
#define F_OC0_Mode				F_OC0_C_COMP_S_TOP
#define P_OC0_Mode				P_OC0_C_COMPU_S_COMPD

/*Timer1 Mode*/
#define Timer1_Mode				Timer1_CTC
#define Timer1_CLK				Timer1_Freq_1024
#define Timer1_Freq_Divider		Timer1_Freq_Div_1
#define F_OC1A_Mode				F_OC1A_C_COMP_S_TOP
#define F_OC1B_Mode				F_OC1B_C_COMP_S_TOP
#define P_OC1A_Mode				P_OC1A_C_COMPU_S_COMPD
#define P_OC1B_Mode				P_OC1B_C_COMPU_S_COMPD

#endif /* TIMER_CFG_H_ */
