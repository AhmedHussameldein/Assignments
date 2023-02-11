/*
 * Timer.c
 *
 * Created: 9/23/2022 8:07:08 PM
 *  Author: AMIT
 */ 

#include "Timer.h"
#include <avr/interrupt.h>

/*Timer0 Variables*/
Uint16 Timer0_No_OVFs = 0;
Uint8 Timer0_Init_val = 0;

/*Timer1 Variables*/
Uint16 Timer1_No_OVFs_A = 0;
Uint16 Timer1_No_OVFs_B = 0;
Uint8 Timer1_Init_val_A = 0;
Uint8 Timer1_Init_val_B = 0;

/*Timer2 Variables*/
Uint16 Timer2_No_OVFs = 0;
Uint8 Timer2_Init_val = 0;

Uint8 Counter_Of_Flag = 60;

Uint8 Flag_1 = 0;
Uint8 Flag_2 = 0;
Uint8 Flag_3 = 0;

void Timer0_Init(void)
{
	/*Global Interrupt Enable/ Disable*/
	SREG |= Global_INT << 7;
	
	/*Timer0 Modes*/
	#if Timer0_Mode == Timer0_OVF
	Clear_Bit(TCCR0, 3);
	Clear_Bit(TCCR0, 6);
	
	/*Peripheral Interrupt Enable/ Disable*/
	TIMSK = (Timer0_OVF_INT) | (TIMSK & 0XFE);
	
	#elif Timer0_Mode == Timer0_P_PWM
	Clear_Bit(TCCR0, 3);
	Set_Bit(TCCR0, 6);
	
	/*Phase Correct PWM Mode*/
	TCCR0 = (P_OC0_Mode << 4) | (TCCR0 & 0XCF);
	
	/*OC0 Pin direction*/
	DIO_SetPin_Dir(DIO_PORTB, PIN_3, PIN_OUT);
		
	#elif Timer0_Mode == Timer0_CTC
	Set_Bit(TCCR0, 3);
	Clear_Bit(TCCR0, 6);
	
	/*Peripheral Interrupt Enable/ Disable*/
	TIMSK = (Timer0_CTC_INT << 1) | (TIMSK & 0XFD);
	
	#elif Timer0_Mode == Timer0_F_PWM
	Set_Bit(TCCR0, 3);
	Set_Bit(TCCR0, 6);
	
	/*Fast PWM Mode*/
	TCCR0 = (F_OC0_Mode << 4) | (TCCR0 & 0XCF);
	
	/*OC0 Pin direction*/
	DIO_SetPin_Dir(DIO_PORTB, PIN_3, PIN_OUT);

#endif
}
void Timer0_SetDelay(Uint32 delay_ms)
{
	Uint8 Tick_time_us = 0;
	Uint32 Tick_num = 0;
	Tick_time_us = Timer0_Freq_Divider / MC_Freq_Mhz;
	Tick_num = (delay_ms * 1000) / Tick_time_us;
	
	#if Timer0_Mode == Timer0_OVF
	if (Tick_num <= 256)
	{
		Timer0_Init_val = 256 - Tick_num;
		TCNT0 = Timer0_Init_val;
		Timer0_No_OVFs = 1;
	}
	else
	{
		Timer0_No_OVFs = !(Tick_num % 256) ? (Tick_num / 256) : (Tick_num / 256) + 1;
		Timer0_Init_val = 256 - (Tick_num % 256);
		TCNT0 = Timer0_Init_val;
	}
	
	#elif Timer0_Mode == Timer0_CTC
	if (Tick_num <= 256)
	{
		Timer0_Init_val = Tick_num-1;
		OCR0 = Timer0_Init_val;
		Timer0_No_OVFs = 1;
	}
	else
	{
		Timer0_No_OVFs = !(Tick_num % 256) ? (Tick_num / 256) : (Tick_num / 256) + 1;
		Timer0_Init_val = (Tick_num % 256) - 1;
		OCR0 = Timer0_Init_val;
	}	

#endif
}

void PWM0_Gen(f32 Duty_cycle)
{
	if (Duty_cycle < 0)
	{
		Duty_cycle = 0;
	}
	else if (Duty_cycle > 100)
	{
		Duty_cycle = 100;
	}
	#if Timer0_Mode == Timer0_F_PWM
	
		#if F_PWM0_Mode == F_PWM0_C_COMP_S_TOP
		OCR0 = !Duty_cycle ? 0 : (Duty_cycle * 256 / 100) - 1; // OCR0
		
		#elif F_PWM0_Mode == F_PWM0_S_COMP_C_TOP
		OCR0 = Duty_cycle == 100 ? 0 : 255 - (Duty_cycle * 256 / 100);
		
		#endif
	
	
	#elif Timer0_Mode == Timer0_P_PWM
	
		#if P_PWM0_Mode == P_PWM0_C_COMPU_S_COMPD
		OCR0 = Duty_cycle * 255 / 100;
		
		#elif P_PWM0_Mode == P_PWM0_S_COMPU_C_COMPD
		OCR0 = 255 - (Duty_cycle * 255 / 100);
		#endif
#endif
}

void Timer0_Start(void)
{
	TCCR0 = (Timer0_CLK) | (TCCR0 & 0XF8);
}
void Timer0_Stop(void)
{
	TCCR0 &= 0XF8; // TCCR0 = TCCR0 & 0XF8
}

ISR(TIMER0_OVF_vect)
{
	static int count = 0;
	count++;
	if(Timer0_No_OVFs == count)
	{
		// Write your code her
		
		// Counter Conditions
		Counter_Of_Flag++;
		
		if((Counter_Of_Flag%4) == 0)
		{
			Flag_1 = 1;
		}
			
		if((Counter_Of_Flag%5) == 0)
		{
			Flag_2 = 1;
		}
		
		if((Counter_Of_Flag%6) == 0)
		{
			Flag_3 = 1;
		}
		
		if(Counter_Of_Flag == 60)
			Counter_Of_Flag = 0;
		
		count = 0;
		TCNT0 = Timer0_Init_val;
	}
}

ISR(TIMER0_COMP_vect)
{
	static int count = 0;
	count++;
	if (Timer0_No_OVFs == 1)
	{
		if(Timer0_No_OVFs == count)
		{
			// Write your code here
			
			
			count = 0;
			OCR0 = Timer0_Init_val;
		}
	}
	else
	{
		if (count == 1)
		{
			OCR0 = 255;
		}
		else if(Timer0_No_OVFs == count)
		{
			//write your code here
			
			
			count = 0;
			OCR0 = Timer0_Init_val;
		}
	}	
}

/*Timer1 Function prototype*/
void Timer1_Init(void)
{
	/*Global Interrupt Enable/ Disable*/
	SREG |= Global_INT << 7;
	
	/*Timer1 Modes*/
	#if Timer1_Mode == Timer1_OVF
	// TCCR1A Register
	Clear_Bit(TCCR1A, 0);
	Clear_Bit(TCCR1A, 1);
	
	// TCCR1B Register
	Clear_Bit(TCCR1B, 3);
	Clear_Bit(TCCR1B, 4);
	
	/*Peripheral Interrupt Enable/ Disable*/
	TIMSK = (Timer1_OVF_INT << 2) | (TIMSK & 0XFB);
	
	#elif Timer1_Mode == Timer1_P_PWM_TOP_ICR1
	// TCCR1A Register
	Clear_Bit(TCCR1A, 0);
	Set_Bit(TCCR1A, 1);
	
	// TCCR1B Register
	Clear_Bit(TCCR1B, 3);
	Set_Bit(TCCR1B, 4);
	
	/*Phase Correct PWM Mode*/
	TCCR1A = (P_OC1A_Mode << 6) | (P_OC1B_Mode << 4) | (TCCR1A & 0X0F);
	
	/*Peripheral Interrupt Enable/ Disable*/
	TIMSK = (Timer1_OVF_INT << 2) | (Timer1_CTCA_INT << 4) | (Timer1_CTCB_INT << 3) | (TIMSK & 0XE3);
	
	/*OC1 Pins direction*/
	DIO_SetPin_Dir(DIO_PORTD, PIN_5, PIN_OUT); // OC1A
	DIO_SetPin_Dir(DIO_PORTD, PIN_4, PIN_OUT); // OC1B
	
	#elif Timer1_Mode == Timer1_CTC
	// TCCR1A Register
	Clear_Bit(TCCR1A, 0);
	Clear_Bit(TCCR1A, 1);
	
	// TCCR1B Register
	Set_Bit(TCCR1B, 3);
	Clear_Bit(TCCR1B, 4);
	
	/*Peripheral Interrupt Enable/ Disable*/
	TIMSK = (Timer1_CTCA_INT << 4) | (Timer1_CTCB_INT << 3) | (TIMSK & 0XE7);
	
	#elif Timer1_Mode == Timer1_F_PWM_TOP_ICR1
	// TCCR1A Register
	Clear_Bit(TCCR1A, 0);
	Set_Bit(TCCR1A, 1);
	
	// TCCR1B Register
	Set_Bit(TCCR1B, 3);
	Set_Bit(TCCR1B, 4);
	
	/*Fast PWM Mode*/
	TCCR1A = (F_OC1A_Mode << 6) | (F_OC1B_Mode << 4) | (TCCR1A & 0X0F);
	
	/*Peripheral Interrupt Enable/ Disable*/
	TIMSK = (Timer1_OVF_INT << 2) | (Timer1_CTCA_INT << 4) | (Timer1_CTCB_INT << 3) | (TIMSK & 0XE3);
	
	/*OC1 Pins direction*/
	DIO_SetPin_Dir(DIO_PORTD, PIN_5, PIN_OUT); // OC1A
	DIO_SetPin_Dir(DIO_PORTD, PIN_4, PIN_OUT); // OC1B

	#endif	
}
void Timer1_SetDelay(Uint32 delay_ms_A, Uint32 delay_ms_B)
{
	/*Tick Time & Tick nums*/
	Uint8 Tick_time_us = 0;
	Uint32 Tick_num_A = 0;
	Uint32 Tick_num_B = 0;
	Tick_time_us = Timer1_Freq_Divider / MC_Freq_Mhz;
	Tick_num_A = (delay_ms_A * 1000) / Tick_time_us;	
	Tick_num_B = (delay_ms_B * 1000) / Tick_time_us;	
	
	#if Timer1_Mode == Timer1_OVF
	if (Tick_num_A <= 65535)
	{
		Timer1_Init_val_A = 65535 - Tick_num_A;
		TCNT1 = Timer1_Init_val_A;
		Timer1_No_OVFs_A = 1;
	}
	else
	{
		Timer1_No_OVFs_A = !(Tick_num_A % 65535) ? (Tick_num_A / 65535) : (Tick_num_A / 65535) + 1;
		Timer1_Init_val_A = 65535 - (Tick_num_A % 65535);
		TCNT1 = Timer1_Init_val_A;
	}
	
	#elif Timer1_Mode == Timer1_CTC
	if (Tick_num_A <= 65535)
	{
		Timer1_Init_val_A = Tick_num_A-1;
		OCR1A = Timer1_Init_val_A;
		Timer1_No_OVFs_A = 1;
	}
	else
	{
		Timer1_No_OVFs_A = !(Tick_num_A % 65535) ? (Tick_num_A / 65535) : (Tick_num_A / 65535) + 1;
		Timer1_Init_val_A = (Tick_num_A % 65535) - 1;
		OCR1A = Timer1_Init_val_A;
	}
	
	if (Tick_num_B <= 65535)
	{
		Timer1_Init_val_B = Tick_num_B-1;
		OCR1B = Timer1_Init_val_B;
		Timer1_No_OVFs_B = 1;
	}
	else
	{
		Timer1_No_OVFs_B = !(Tick_num_B % 65535) ? (Tick_num_B / 65535) : (Tick_num_B / 65535) + 1;
		Timer1_Init_val_B = (Tick_num_B % 65535) - 1;
		OCR1B = Timer1_Init_val_B;
	}
	#endif
}
void PWM1_Gen(f32 Duty_cycle_A, f32 Duty_cycle_B, f32 F_OC1_AB_Khz)
{
	ICR1 = (MC_Freq_Mhz * 1000) / (Timer1_Freq_Divider * F_OC1_AB_Khz);
	/*Duty_cycle_A limitations*/
	if (Duty_cycle_A < 0)
	{
		Duty_cycle_A = 0;
	}
	else if (Duty_cycle_A > 100)
	{
		Duty_cycle_A = 100;
	}
	/*Duty_cycle_B limitations*/
	if (Duty_cycle_B < 0)
	{
		Duty_cycle_B = 0;
	}
	else if (Duty_cycle_B > 100)
	{
		Duty_cycle_B = 100;
	}
	#if Timer1_Mode == Timer1_F_PWM_TOP_ICR1 // Fast PWM (Mode-14)
	
	/*OC1A: Non-Inverted Mode*/
	#if F_OC1A_Mode == F_OC1A_C_COMP_S_TOP
	OCR1A = !Duty_cycle_A ? 0 : (Duty_cycle_A * (ICR1 + 1) / 100) - 1; // OCR1A
	/*OC1A: Inverted Mode*/
	#elif F_OC1A_Mode == F_OC1A_S_COMP_C_TOP
	OCR1A = Duty_cycle_A == 100 ? 0 : ICR1 - (Duty_cycle_A * (ICR1 + 1) / 100); // OCR1A
	
	#endif
	
	/*OC1B: Non-Inverted Mode*/
	#if F_OC1B_Mode == F_OC1B_C_COMP_S_TOP
	OCR1B = !Duty_cycle_B ? 0 : (Duty_cycle_B * (ICR1 + 1) / 100) - 1; // OCR1B
	/*OC1B: Inverted Mode*/
	#elif F_OC1B_Mode == F_OC1B_S_COMP_C_TOP
	OCR1B = Duty_cycle_B == 100 ? 0 : ICR1 - (Duty_cycle_B * (ICR1 + 1) / 100); // OCR1B
	
	#endif
	

	#elif Timer1_Mode == Timer1_P_PWM_TOP_ICR1
	
	/*OC1A: Non-Inverted Mode*/
	#if P_OC1A_Mode == P_OC1A_C_COMPU_S_COMPD
	OCR1A = Duty_cycle_A * ICR1 / 100; // OCR1A
	/*OC1A: Inverted Mode*/
	#elif P_OC1A_Mode == P_OC1A_S_COMPU_C_COMPD
	OCR1A = ICR1 - (Duty_cycle_A * ICR1 / 100); // OCR1A
	#endif
	
	/*OC1B: Non-Inverted Mode*/
	#if P_OC1B_Mode == P_OC1B_C_COMPU_S_COMPD
	OCR1B = Duty_cycle_B * ICR1 / 100; // OCR1B
	/*OC1B: Inverted Mode*/
	#elif P_OC1B_Mode == P_OC1B_S_COMPU_C_COMPD
	OCR1B = ICR1 - (Duty_cycle_B * ICR1 / 100); // OCR1B
	#endif
	#endif
}
void Timer1_Start(void)
{
	TCCR1B = (Timer1_CLK) | (TCCR1B & 0XF8);
}
void Timer1_Stop(void)
{
	TCCR1B &= 0XF8; // TCCR1B = TCCR1B & 0XF8
}