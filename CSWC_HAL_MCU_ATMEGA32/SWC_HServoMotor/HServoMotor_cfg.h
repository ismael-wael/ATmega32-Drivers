/*
 * HServoMotor_cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

#ifndef HSERVOMOTOR_CFG_H_
#define HSERVOMOTOR_CFG_H_

#include "HServoMotor_init.h"

//Type of PWM used (Fast,phase correct, phase & frequency correct)
#define HSERVO_PWM_MODE			HSERVO_FAST_PWM

//Servo PWM waveform shape(inverted/non-inverted)
#define HSERVO_PWM_WAVEFORM  	HSERVO_NONINVERTED_PWM

//Servo Prescaller Selection
#define HSERVO_PRESCALLER     	HSERVO_PS_64

#endif /* HSERVOMOTOR_CFG_H_ */
