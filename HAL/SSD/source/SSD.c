/*
 * SSD.c
 *
 * Created: 9/30/2023 4:03:00 PM
 *  Author: Musta
 */ 
#include "SSD.h"

void SSD_Init()
{
	// SSD Enable line
	DIO_ConfigChannel(DIO_ChannelB1, DIO_OUTPUT);
	DIO_ConfigChannel(DIO_ChannelB2, DIO_OUTPUT);
	//SSD Data line
	DIO_ConfigChannel(DIO_ChannelA4, DIO_OUTPUT);
	DIO_ConfigChannel(DIO_ChannelA5, DIO_OUTPUT);
	DIO_ConfigChannel(DIO_ChannelA6, DIO_OUTPUT);
	DIO_ConfigChannel(DIO_ChannelA7, DIO_OUTPUT);
	//SSD DP line 
	DIO_ConfigChannel(DIO_ChannelB3, DIO_OUTPUT);
	//turn off Display
	DIO_WriteChannel(DIO_ChannelB1, STD_LOW);
	DIO_WriteChannel(DIO_ChannelB2, STD_LOW);
	
}
//----------------------------------------------------------
void SSD_Display(u8 num)
{
	u8 SSD_First_Digit   = (num%10)<<4;
	u8 SSD_Second_Digit  = (num/10)<<4;
	
	if(num<100)
	{
		//Enable SSD1
		DIO_WriteChannel(DIO_ChannelB1, STD_HIGH);
		//Disable SSD2
		DIO_WriteChannel(DIO_ChannelB2, STD_LOW);
		//Write first Digit
		DIO_WriteChannelGroup(DIO_PortA, SSD_First_Digit, 0xF0);
		
		_delay_ms(1);
		
		//Disable SSD1
		DIO_WriteChannel(DIO_ChannelB1, STD_LOW);
		//Enable SSD2
		DIO_WriteChannel(DIO_ChannelB2, STD_HIGH);
		//Write Second Digit
		DIO_WriteChannelGroup(DIO_PortA, SSD_Second_Digit, 0xF0);
		
		_delay_ms(1);		
	}
	else
	{		
	}
}
//---------------------------------------------------------
void SSD_Display_With_Delay(u8 num, u32 delay)
{
	u32 count = 0;
	for(count=0; count<delay; count+=3)
	{
		SSD_Display(num);
		_delay_ms(1);
	}
}