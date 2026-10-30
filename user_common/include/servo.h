/**
 * @file 
 *
 * @brief      
 *
 * @date       
 *
 * @author     
 */

#ifndef _SERVO_H_
#define _SERVO_H_

#include <stdint.h>

/** @brief Documents servo enable. */
int servo_enable(uint8_t channel, uint8_t enabled);

/** @brief Documents servo set. */
int servo_set(uint8_t channel, uint8_t angle);

#endif /* _SERVO_H_ */
