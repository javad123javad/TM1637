/*
 * tm1637.c
 *
 *  Created on: Feb 16, 2019
 *      Author: javad
 */

#include "tm1637.h"
#include <unistd.h>

int TM1637_delay(const uint16_t i_delay)
{
	return usleep(i_delay);
}


int TM1637_start(void)
{
	/*
	clk = 1;
	dio = 1;
	TM1637_udelay(2);
	dio = 0;
 */
}
