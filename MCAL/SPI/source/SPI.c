/*
 * SPI.c
 *
 * Created: 10/27/2023 2:57:13 PM
 *  Author: Musta
 */ 

#include "SPI.h"

void SPI_Init(SPI_ConfigTypes * options)
{
	switch(options->SpiMode)
	{
		case Master:
		DIO_ConfigChannel(SPI_SSPin,DIO_OUTPUT);
		DIO_ConfigChannel(SPI_MOSIPin,DIO_OUTPUT);
		DIO_ConfigChannel(SPI_MISOPin,DIO_INPUT);
		DIO_ConfigChannel(SPI_SCKPin,DIO_OUTPUT);
		SPI->SPCR_Reg.Bits.MSTR_Bit = 1;
		SPI->SPCR_Reg.Bits.SPE_Bit = 1;
		break;
		case Slave:
		DIO_ConfigChannel(SPI_SSPin,DIO_INPUT);
		DIO_ConfigChannel(SPI_MOSIPin,DIO_INPUT);
		DIO_ConfigChannel(SPI_MISOPin,DIO_OUTPUT);
		DIO_ConfigChannel(SPI_SCKPin,DIO_INPUT);
		SPI->SPCR_Reg.Bits.MSTR_Bit = 0;
		SPI->SPCR_Reg.Bits.SPE_Bit = 1;
		break;
	}
	SPI->SPCR_Reg.AllRegister |= options->SpiDord<<5 | options->SpiClock;
	/*SPI->SPCR_Reg.AllRegister |= options->SpiClock;*/
	SPI->SPSR_Reg.AllRegister |= options->SpioubleSpeedMode;
}
u8 SPI_TxRx(u8 data)
{
	SPI->SPDR_Reg = data;
	while(SPI->SPSR_Reg.Bits.SPIF_Bit == 0);
	return SPI->SPDR_Reg;
}
void SPISlaveEnable(DIO_ChanelTypes channelID)
{
	DIO_ConfigChannel(channelID,DIO_OUTPUT);
	DIO_WriteChannel(channelID,STD_LOW);
}
void SPISlaveDisable(DIO_ChanelTypes channelID)
{
	DIO_ConfigChannel(channelID,DIO_OUTPUT);
	DIO_WriteChannel(channelID,STD_HIGH);
}