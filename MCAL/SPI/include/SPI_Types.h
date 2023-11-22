/*
 * SPI_Types.h
 *
 * Created: 10/27/2023 2:56:18 PM
 *  Author: Musta
 */ 


#ifndef SPI_TYPES_H_
#define SPI_TYPES_H_

#include "STD.h"

typedef struct{
	u8 SPR_Bit:2;
	u8 CPHA_Bit:1;
	u8 CPOL_Bit:1;
	u8 MSTR_Bit:1;
	u8 DORD_Bit:1;
	u8 SPE_Bit:1;
	u8 SPIE_Bit:1;	
}SPCR_BitsType;

typedef struct{
	u8 SPI2X_Bit:1;
	u8 RESERVED_Bit:5;
	u8 WCOL_Bit:1;
	u8 SPIF_Bit:1;
}SPSR_BitsType;


typedef union{
	u8 AllRegister;
	SPCR_BitsType Bits;
}SPCR_RegisterType;

typedef union{
	u8 AllRegister;
	SPSR_BitsType Bits;
}SPSR_RegisterType;


typedef struct{
	SPCR_RegisterType SPCR_Reg;
	SPSR_RegisterType SPSR_Reg;
	u8 SPDR_Reg;
}SPI_Registers;

typedef enum{
	MSB=0,
	LSB
}SPI_DORDTypes;

typedef enum{
	Slave =0,
	Master
}SPI_ModeTypes;

typedef enum{
	SPI_Clock_4=0,
	SPI_Clock_16,
	SPI_Clock_64,
	SPI_Clock_128
}SPI_ClockTypes;

typedef enum{
	SPI_DoubleSpeedDisable=0,
	SPI_DoubleSpeedEnable
}SPI_DoubleSpeedTypes;

typedef struct{
	
	SPI_ModeTypes	SpiMode;
	SPI_DORDTypes	SpiDord;
	SPI_ClockTypes	SpiClock;
	SPI_DoubleSpeedTypes	SpioubleSpeedMode;
}SPI_ConfigTypes;



#endif /* SPI_TYPES_H_ */