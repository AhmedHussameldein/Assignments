// Pre-processor defining and including
#define F_CPU 16000000
#include "LED.h"
#include "Timer.h"
// Extern Flag variables from Timer.c driver
extern Uint8 Flag_1;
extern Uint8 Flag_2;
extern Uint8 Flag_3;

int main(void)
{
	// Timer and led initialization
	Timer0_Init();
    LED0_Init();
	LED1_Init();
	LED2_Init();
	
	// First Toggle out of timer
	LED0_Toggle();
	LED1_Toggle();
	LED2_Toggle();
		
	// Starting the timer to count	
	Timer0_Start();	
	Timer0_SetDelay(500);
	
    while (1) 
    {
		// Flag Conditions
		if(Flag_1 == 1)
		{
			LED0_Toggle();
			Flag_1 = 0;
		}
		
		if(Flag_2 == 1)
		{
			LED1_Toggle();
			Flag_2 = 0;
		}
		
		if(Flag_3 == 1)
		{
			LED2_Toggle();
			Flag_3 = 0;
		}
    }
}

