/*
 * HServoMotor_init.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

#ifndef HSERVOMOTOR_INIT_H_
#define HSERVOMOTOR_INIT_H_

//inverted or non-inverted PWM
#define HSERVO_INVERTED_PWM  	 0
#define HSERVO_NONINVERTED_PWM   1

//Servo prescaler options
#define HSERVO_STOP    		 	 0
#define HSERVO_PS_1      	 	 1
#define HSERVO_PS_8       	 	 2
#define HSERVO_PS_64      	 	 3
#define HSERVO_PS_256     	 	 4
#define HSERVO_PS_1024    	 	 5

//Type of PWM used (Fast,phase correct, phase & frequency correct)
#define HSERVO_FAST_PWM                 0
#define HSERVO_PH_CORRECT_PWM			1
#define HSERVO_PH_FRQ_CORRECT_PWM		2

void HServo_voidInit(void);
void HServo_voidSet_ICR1(u16 );
void HServo_voidSet_OCR1A(u16 );

/*example :
 ----------
 * int main(void)
{
	HServo_voidInit();
	HServo_voidSet_ICR1(0x09C4);//2500

	MADC_enuInit();
	u16 Val=0;

	while (1)
	{
	    MADC_enuStartConversion(&Val);
	    HServo_voidSet_OCR1A(Val/3);
	    _delay_ms (20);
	}
}*/

/*this is 10-bit ADC so, 1024 possible value
 * but the Servo works in range [0 --> 300]
 * that's why we divide by 3*/

#endif /* HSERVOMOTOR_INIT_H_ */
