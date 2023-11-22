/*
 * SPI_Reg.h
 *
 * Created: 10/27/2023 2:56:50 PM
 *  Author: Musta
 */ 


#ifndef SPI_REG_H_
#define SPI_REG_H_

#include "DIO.h"
#include "SPI_Types.h"

#define SPI_SSPin DIO_ChannelB4
#define SPI_MOSIPin DIO_ChannelB5
#define SPI_MISOPin DIO_ChannelB6
#define SPI_SCKPin DIO_ChannelB7


#define SPI ((volatile SPI_Registers*)0x2D)


#endif /* SPI_REG_H_ */