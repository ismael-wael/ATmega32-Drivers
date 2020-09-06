/*
 * HServoMotor_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

//main avr libraries
#include "util/delay.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#define F_CPU 8000000UL
//used libraries
#include "../../LIB_STDTypes/LIB_stdTypes.h"
#include "../../LIB_BMNP/LIB_BMNP.h"
#include "../../Platform/ATMega32_Features.h"

//MTWI
#include "../../CSWC_PLTF_MCU_ATMEGA32/SWC_MDIO/MDIO_int.h"

//Servo
#include "HServoMotor_cfg.h"
#include "HServoMotor_init.h"

void HServo_voidInit(void)
{
	#if HSERVO_PWM_MODE == HSERVO_FAST_PWM

	    // PWM waveform (inverted or non-inverted)
		#if HSERVO_PWM_WAVEFORM == HSERVO_NONINVERTED_PWM
			TCCR1A = 0b10000010;
		#elif HSERVO_PWM_WAVEFORM == HSERVO_INVERTED_PWM
			TCCR1A = 0b11000010;
		#endif

    	// clk prescaler
		#if HSERVO_PRESCALLER == HSERVO_STOP
			TCCR1B = 0b00011000;
		#elif HSERVO_PRESCALLER == HSERVO_PS_1
			TCCR1B = 0b00011001;
		#elif HSERVO_PRESCALLER == HSERVO_PS_8
			TCCR1B = 0b00011010;
		#elif HSERVO_PRESCALLER == HSERVO_PS_64
			TCCR1B = 0b00011011;
		#elif HSERVO_PRESCALLER == HSERVO_PS_256
			TCCR1B = 0b00011100;
		#elif HSERVO_PRESCALLER == HSERVO_PS_1024
			TCCR1B = 0b00011101;
		#endif
	#elif HSERVO_PWM_MODE == HSERVO_PH_CORRECT_PWM

		// PWM waveform (inverted or non-inverted)
		#if HSERVO_PWM_WAVEFORM == HSERVO_NONINVERTED_PWM
			TCCR1A = 0b10000010;
		#elif HSERVO_PWM_WAVEFORM == HSERVO_INVERTED_PWM
			TCCR1A = 0b11000010;
		#endif

	    // clk prescaler
		#if HSERVO_PRESCALLER == HSERVO_STOP
			TCCR1B = 0b00010000;
		#elif HSERVO_PRESCALLER == HSERVO_PS_1
			TCCR1B = 0b00010001;
		#elif HSERVO_PRESCALLER == HSERVO_PS_8
			TCCR1B = 0b00010010;
		#elif HSERVO_PRESCALLER == HSERVO_PS_64
			TCCR1B = 0b00010011;
		#elif HSERVO_PRESCALLER == HSERVO_PS_256
			TCCR1B = 0b00010100;
		#elif HSERVO_PRESCALLER == HSERVO_PS_1024
			TCCR1B = 0b00010101;
		#endif
	#elif HSERVO_PWM_MODE == HSERVO_PH_FRQ_CORRECT_PWM

		// PWM waveform (inverted or non-inverted)
		#if HSERVO_PWM_WAVEFORM == HSERVO_NONINVERTED_PWM
			TCCR1A = 0b10000000;
		#elif HSERVO_PWM_WAVEFORM == HSERVO_INVERTED_PWM
			TCCR1A = 0b11000000;
		#endif

	    // clk prescaler
		#if HSERVO_PRESCALLER == HSERVO_STOP
			TCCR1B = 0b00010000;
		#elif HSERVO_PRESCALLER == HSERVO_PS_1
			TCCR1B = 0b00010001;
		#elif HSERVO_PRESCALLER == HSERVO_PS_8
			TCCR1B = 0b00010010;
		#elif HSERVO_PRESCALLER == HSERVO_PS_64
			TCCR1B = 0b00010011;
		#elif HSERVO_PRESCALLER == HSERVO_PS_256
			TCCR1B = 0b00010100;
		#elif HSERVO_PRESCALLER == HSERVO_PS_1024
			TCCR1B = 0b00010101;
		#endif
	#endif

	sei(); // activate global interrupt

	TIMSK |=(1<<4); // Output Compare A Match Interrupt Enable

	DDRD_Register |=(1<<5); // make the OC1A pin as output
}

void HServo_voidSet_ICR1(u16 u16ValCpy)
{
	ICR1H = u16ValCpy >> 8; // add the high byte to ICR1H
	ICR1L = u16ValCpy & 0x00ff; // add the low byte to ICR1L
}

void HServo_voidSet_OCR1A(u16 u16ValCpy)
{
	OCR1AH = u16ValCpy >> 8; // add the high byte to OCR1AH
	OCR1AL = u16ValCpy & 0x00ff; // add the low byte to OCR1AL
}

