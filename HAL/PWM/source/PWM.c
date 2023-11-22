/*
 * PWM.c
 *
 * Created: 10/14/2023 3:32:34 PM
 *  Author: Musta
 */ 

#include "PWM.h"


void PWM_Generate_COM1A(u8 Duty)
{
	DIO_ConfigChannel(DIO_ChannelD5, DIO_OUTPUT);
	u16 ICRValue = 0xFFFF;
	Timer1_SetValue(ICR1_DataReg,ICRValue);
	u16 OCR1AValue = (u16)((((f32)Duty/100)*((u32)ICRValue+1))-1);
	Timer1_SetValue(OCR1A_DataReg,OCR1AValue);
	Timer1_InitTypes options ={PWM_Fast,Clock_8,COM1A_Non_Inverting_PWM,COM1B_No_PWM,TOVInt_Disable,OC1BInt_Disable,OC1AInt_Disable,ICInt_Disable};
	Timer1_Init(&options);
	
}