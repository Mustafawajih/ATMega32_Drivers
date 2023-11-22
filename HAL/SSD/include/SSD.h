/*
 * SSD.h
 *
 * Created: 9/30/2023 4:02:40 PM
 *  Author: Musta
 */ 


#ifndef SSD_H_
#define SSD_H_

#include "Clock.h"
#include "DIO.h"

void SSD_Init();
void SSD_Display(u8 num);
void SSD_Display_With_Delay(u8 num, u32 delay);




#endif /* SSD_H_ */