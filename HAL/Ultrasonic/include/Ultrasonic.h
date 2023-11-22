/*
 * Ultrasonic.h
 *
 * Created: 10/20/2023 3:35:39 PM
 *  Author: Musta
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "DIO.h"
#include "Timer1.h"
#include "GNIT.h"
#include "Clock.h"


#define UltrasonicTriggerPin DIO_ChannelA0
#define UltrasonicEchoPin DIO_ChannelD6

f64 Ultasonic_Read();
void Timer1_TOVHandler(void);   


#endif /* ULTRASONIC_H_ */