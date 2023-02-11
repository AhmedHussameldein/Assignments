/*
 * LED_Configuration.h
 *
 * Created: 9/8/2022 1:55:50 PM
 *  Author: Dell
 */ 


#ifndef LED_CONFIGURATION_H_
#define LED_CONFIGURATION_H_
#include "DIO.h"

/*-------------LED0-------------*/
#define LED0_Port DIO_PORTC
#define LED0_Pin  PIN_2

/*-------------LED1-------------*/
#define LED1_Port DIO_PORTC
#define LED1_Pin  PIN_7

/*-------------LED2-------------*/
#define LED2_Port DIO_PORTD
#define LED2_Pin  PIN_3


#endif /* LED_CONFIGURATION_H_ */