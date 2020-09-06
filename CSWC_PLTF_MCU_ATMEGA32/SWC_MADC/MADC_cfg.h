/*
 * MADC_cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

#ifndef MADC_CFG_H_
#define MADC_CFG_H_

#include "MADC_int.h"

//setup values

//adc reference voltage (MADC_AREF : AREF, Internal Vref turned off ,
//						 MADC_AVCC : AVCC with external capacitor at AREF pin,
//						 MADC_IREF : Internal 2.56V Voltage Reference with external cap at AREF)
#define MADC_REF MADC_AVCC
//adc prescaler (MADC_PS_2,MADC_PS_4, MADC_PS_8, MADC_PS_16, MADC_PS_32, MADC_PS_64, MADC_PS_128)
#define MADC_PRESCALER MADC_PS_64
//adc justify (MADC_8BIT for 8-bit read  or MADC_10BIT for 10-bit read)
#define MADC_JUSTIFY MADC_10BIT
//set ADC channel
#define MADC_CHANNEL MADC_Channel_0


#endif /* MADC_CFG_H_ */
