/*
 * Interrupts_CFG.h
 *
 * Created: 9/21/2022 12:31:43 PM
 *  Author: AMIT
 */ 


#ifndef INTERRUPTS_CFG_H_
#define INTERRUPTS_CFG_H_

/*-------------> Global Interrupt <-------------*/
#define Global_INT			Enable

/*-------------> Ext Interrupts <-------------*/
#define EXT0_INT			Enable
#define EXT1_INT			Disable
#define EXT2_INT			Disable

/*-------------> ADC Interrupts <-------------*/
#define ADC_INT				Enable

/*-------------> Timer0 Interrupts <-------------*/
#define Timer0_OVF_INT				Enable
#define Timer0_CTC_INT				Enable

/*-------------> Timer1 Interrupts <-------------*/
#define Timer1_OVF_INT				Disable
#define Timer1_CTCA_INT				Disable
#define Timer1_CTCB_INT				Disable
#define Timer1_IN_CAPT_INT			Disable

/*-------------> UART Interrupts <-------------*/
#define UART_RX_INT				Enable
#define UART_TX_INT				Disable

#endif /* INTERRUPTS_CFG_H_ */