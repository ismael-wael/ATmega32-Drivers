/*
 * MWDT_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

#ifndef MWDT_INT_H_
#define MWDT_INT_H_

//clk prescaler
#define MWDT_16_ms     	 ((u8)0)
#define MWDT_32_ms       ((u8)1)
#define MWDT_65_ms       ((u8)2)
#define MWDT_130_ms      ((u8)3)
#define MWDT_260_ms      ((u8)4)
#define MWDT_520_ms      ((u8)5)
#define MWDT_1000_ms     ((u8)6)
#define MWDT_2100_ms     ((u8)7) // 1500 ms actually

void MWDT_voidInit(u8 u8Val);
void MWDT_voidDisableWDT(void );

// WDT timeout max is 1500 ms (it should be 2100 ms, but...)

/*int main(void)
{
	DDRB_Register |=(1<<0);
	PORTB_Register |=(1<<0);
	_delay_ms(500);
	PORTB_Register &=~(1<<0);
	MWDT_voidInit(MWDT_2100_ms);
	_delay_ms(1000);
	MWDT_voidDisableWDT();
	while (1)
	{
	}
}
 * */

#endif /* MWDT_INT_H_ */
