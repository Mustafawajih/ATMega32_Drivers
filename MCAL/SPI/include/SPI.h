/*
 * SPI.h
 *
 * Created: 10/27/2023 2:57:02 PM
 *  Author: Musta
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "SPI_Reg.h"


void SPI_Init(SPI_ConfigTypes * options);
u8 SPI_TxRx(u8 data);
void SPISlaveEnable(DIO_ChanelTypes channelID);
void SPISlaveDisable(DIO_ChanelTypes channelID);


#endif /* SPI_H_ */