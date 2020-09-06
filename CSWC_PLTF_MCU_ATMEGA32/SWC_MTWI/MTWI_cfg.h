/*
 * MTWI_cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Elsa7er
 */

#ifndef MTWI_CFG_H_
#define MTWI_CFG_H_

#define MTWI_MODE			MTWI_SLV_MODE

/*the device 7-bit address when it's slave (put it even if you are master)
 * the address is 7-bit and the 8th bit is (1 for General Call Recognition)*/
#define MTWI_Slave_Add		0b10101111

#define MTWI_CLK			MTWI_clk_200_KHZ


#endif /* MTWI_CFG_H_ */
