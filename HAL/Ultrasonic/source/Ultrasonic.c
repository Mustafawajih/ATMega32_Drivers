/*
 * Ultrasonic.c
 *
 * Created: 10/20/2023 3:35:55 PM
 *  Author: Musta
 */ 

#include "Ultrasonic.h"

volatile u32 Timer1_OVCount = 0;

f64 Ultasonic_Read()
{
	DIO_ConfigChannel(UltrasonicTriggerPin,DIO_OUTPUT);
	DIO_ConfigChannel(UltrasonicEchoPin,DIO_INPUT);
	
	EnableAllInterrupts();
	
	Timer1_InitTypes options ={Normal,Clock_64,COM1A_No_PWM,COM1B_No_PWM,TOVInt_Enable,OC1BInt_Disable,OC1AInt_Disable,ICInt_Disable};
	Timer1_Init(&options);	
	
	Timer1->TCCR1B_Reg.Bits.ICES1_Bit = 1;// ICU Rising Edge
	
	DIO_WriteChannel(UltrasonicTriggerPin,STD_HIGH);
	_delay_ms(10);
	DIO_WriteChannel(UltrasonicTriggerPin,STD_LOW);
	
	while(Timer1->TIFR_Reg.Bits.ICF1_Bit == STD_LOW);//waiting for the Rising Edge
	Timer1->TCNT1_Reg = 0x0000;
	Timer1->ICR1_Reg = 0x0000;
	Timer1_OVCount = 0;
	Timer1->TIFR_Reg.Bits.ICF1_Bit = 1;
	Timer1->TCCR1B_Reg.Bits.ICES1_Bit = 0;//ICU Falling Edge
	
	
	while(Timer1->TIFR_Reg.Bits.ICF1_Bit == STD_LOW);//waiting for the Falling Edge
	u32 Timer1_Value = (Timer1_OVCount*65535) + Timer1->ICR1_Reg;
	f64 distance =(f64)0.0686*Timer1_Value;
	return distance;
	
	
}
void Timer1_TOVHandler(void)
{
	Timer1_OVCount++;
}