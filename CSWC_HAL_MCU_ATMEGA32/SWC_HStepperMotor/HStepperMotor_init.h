/*
 * HStepperMotor_init.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

#ifndef HSTEPPERMOTOR_INIT_H_
#define HSTEPPERMOTOR_INIT_H_

void Stepper_RotateCW(void);
void Stepper_RotateCCW(void); // full step
void HStepper_voidInit(void); // full step

/****  How to Use  ****/
	    /* Rotate clock wise for 5 seconds */
/*      for (u8 i=0;i<250;i++)
		{
			Stepper_RotateCCW();
		}*/

		/* Rotate anti clock wise for 5 seconds */
/*      for (u8 i=0;i<250;i++)
		{
			Stepper_RotateCW();
		}*/

#endif /* HSTEPPERMOTOR_INIT_H_ */
