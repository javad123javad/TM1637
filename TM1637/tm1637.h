/*
 * tm1637.h
 *
 *  Created on: Feb 16, 2019
 *      Author: javad
 */

#ifndef TM1637_H_
#define TM1637_H_
#include <stdint.h>
#include <linux/types.h>

int TM1637_udelay(const uint16_t i_delay);
int TM1637_start(void);
int TM1637_ack(void);
int TM1637_stop(void);
int TM1637_write(unsigned char oneByte);


#endif /* TM1637_H_ */
