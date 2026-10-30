/**
* @file   systick.h
*
* @brief  Prototypes for SysTick control functions
*
* @date   20 Oct 2019
*
* @author Benjamin Huang <zemingbh@andrew.cmu.edu>
*/

#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include <unistd.h>

/** @brief  The processor frequency (16MHz) */
#define BASE_FREQ 16000000

/** @brief Documents systick init. */
void systick_init();

/** @brief Documents systick delay. */
void systick_delay();

/** @brief Documents systick get ticks. */
uint32_t systick_get_ticks();

/** @brief Documents systick c handler. */
void systick_c_handler();

#endif /* _SYSTICK_H_ */
