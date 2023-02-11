/*
 * Timer.h
 *
 * Created: 9/23/2022 8:07:23 PM
 *  Author: AMIT
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "Timer_CFG.h"

/*---------------------> Timer0 <---------------------*/
/*Timer0 Modes*/
#define Timer0_OVF					0
#define Timer0_P_PWM				1
#define Timer0_CTC					2
#define Timer0_F_PWM				3

/*Timer0 Clocks*/
#define Timer0_No_CLK				0
#define Timer0_Freq_1				1
#define Timer0_Freq_8				2
#define Timer0_Freq_64				3
#define Timer0_Freq_256				4
#define Timer0_Freq_1024			5

/*Timer0 Fast PWM Modes*/
#define F_OC0_C_COMP_S_TOP			2
#define F_OC0_S_COMP_C_TOP			3

/*Timer0 Phase Correct PWM Modes*/
#define P_OC0_C_COMPU_S_COMPD		2
#define P_OC0_S_COMPU_C_COMPD		3

/*Timer0 Prescaler Divider*/
#define Timer0_Freq_Div_1			1
#define Timer0_Freq_Div_8			8
#define Timer0_Freq_Div_64			64
#define Timer0_Freq_Div_256			256
#define Timer0_Freq_Div_1024		1024

/*---------------------> Timer1 <---------------------*/
/*Timer1 Modes*/
#define Timer1_OVF					0
#define Timer1_P_PWM_TOP_ICR1		1
#define Timer1_CTC					2
#define Timer1_F_PWM_TOP_ICR1		3

/*Timer1 Clocks*/
#define Timer1_No_CLK				0
#define Timer1_Freq_1				1
#define Timer1_Freq_8				2
#define Timer1_Freq_64				3
#define Timer1_Freq_256				4
#define Timer1_Freq_1024			5

/*Timer1 Fast PWM Modes*/
#define F_OC1A_Disconnected			0
#define Reserved					1
#define F_OC1A_C_COMP_S_TOP			2
#define F_OC1A_S_COMP_C_TOP			3

#define F_OC1B_Disconnected			0
#define Reserved					1
#define F_OC1B_C_COMP_S_TOP			2
#define F_OC1B_S_COMP_C_TOP			3

/*Timer1 Phase Correct PWM Modes*/
#define P_OC1A_Disconnected			0
#define Reserved					1
#define P_OC1A_C_COMPU_S_COMPD		2
#define P_OC1A_S_COMPU_C_COMPD		3

#define P_OC1B_Disconnected			0
#define Reserved					1
#define P_OC1B_C_COMPU_S_COMPD		2
#define P_OC1B_S_COMPU_C_COMPD		3

/*Timer1 Prescaler Divider*/
#define Timer1_Freq_Div_1			1
#define Timer1_Freq_Div_8			8
#define Timer1_Freq_Div_64			64
#define Timer1_Freq_Div_256			256
#define Timer1_Freq_Div_1024		1024

/*Timer0 Function prototype*/
void Timer0_Init(void);
void Timer0_SetDelay(Uint32 delay_ms);
void PWM0_Gen(f32 Duty_cycle);
void Timer0_Start(void);
void Timer0_Stop(void);

/*Timer1 Function prototype*/
void Timer1_Init(void);
void Timer1_SetDelay(Uint32 delay_ms_A, Uint32 delay_ms_B);
void PWM1_Gen(f32 Duty_cycle_A, f32 Duty_cycle_B, f32 F_OC1_AB_Khz);
void Timer1_Start(void);
void Timer1_Stop(void);

#endif /* TIMER_H_ */