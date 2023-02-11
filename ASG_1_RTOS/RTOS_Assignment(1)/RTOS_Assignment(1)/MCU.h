/*
 * MCU.h
 *
 * Created: 9/6/2022 2:02:30 PM
 *  Author: Dell
 */ 


#ifndef MCU_H_
#define MCU_H_
#include "std.h"

/*---------------------> DIO <---------------------*/
#define PORTA	*((volatile Uint8*)(0x3B))
#define DRRA	*((volatile Uint8*)(0x3A))
#define PINA	*((volatile Uint8*)(0x39))

#define PORTB	*((volatile Uint8*)(0x38))
#define DRRB	*((volatile Uint8*)(0x37))
#define PINB	*((volatile Uint8*)(0x36))

#define PORTC	*((volatile Uint8*)(0x35))
#define DRRC	*((volatile Uint8*)(0x34))
#define PINC	*((volatile Uint8*)(0x33))

#define PORTD	*((volatile Uint8*)(0x32))
#define DRRD	*((volatile Uint8*)(0x31))
#define PIND	*((volatile Uint8*)(0x30))

/*---------------------> External Interrupts <---------------------*/
#define SREG	*((volatile Uint8*)(0x5F))
#define GICR	*((volatile Uint8*)(0x5B))
#define MCUCR	*((volatile Uint8*)(0x55))

/*---------------------> ADC <---------------------*/
#define SFIOR	*((volatile Uint8*)(0x50))
#define ADMUX	*((volatile Uint8*)(0x27))
#define ADCSRA	*((volatile Uint8*)(0x26))
#define ADCH	*((volatile Uint8*)(0x25))
#define ADCL	*((volatile Uint8*)(0x24))
#define ADCR	*((volatile Uint16*)(0x24))

/*---------------------> Timer0 <---------------------*/
#define OCR0	*((volatile Uint8*)(0x5C))
#define TIMSK	*((volatile Uint8*)(0x59))
#define TIFR	*((volatile Uint8*)(0x58))
#define TCCR0	*((volatile Uint8*)(0x53))
#define TCNT0	*((volatile Uint8*)(0x52))

/*---------------------> Timer1 <---------------------*/
#define TCCR1A	*((volatile Uint8*)(0x4F))
#define TCCR1B	*((volatile Uint8*)(0x4E))
#define TCNT1H	*((volatile Uint8*)(0x4D))
#define TCNT1L	*((volatile Uint8*)(0x4C))
#define TCNT1	*((volatile Uint16*)(0x4C))
#define OCR1AH	*((volatile Uint8*)(0x4B))
#define OCR1AL	*((volatile Uint8*)(0x4A))
#define OCR1A	*((volatile Uint16*)(0x4A))
#define OCR1BH	*((volatile Uint8*)(0x49))
#define OCR1BL	*((volatile Uint8*)(0x48))
#define OCR1B	*((volatile Uint16*)(0x48))
#define ICR1H	*((volatile Uint8*)(0x47))
#define ICR1L	*((volatile Uint8*)(0x46))
#define ICR1	*((volatile Uint16*)(0x46))

/*---------------------> UART <---------------------*/
#define UDR		*((volatile Uint8*)(0x2C))
#define UCSRA	*((volatile Uint8*)(0x2B))
#define UCSRB	*((volatile Uint8*)(0x2A))
#define UBRRL	*((volatile Uint8*)(0x29))
#define UBRRH	*((volatile Uint8*)(0x40))
#define UCSRC	*((volatile Uint8*)(0x40))




#endif /* MCU_H_ */