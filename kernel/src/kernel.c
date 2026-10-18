/**
 * @file kernel.c
 *
 * @brief Kernel entry point
 *
 * @date
 * @author
 */

#include <arm.h>
#include <kernel.h>
#include <printk.h>
#include <systick.h>
#include <uart_polling.h>

/** @brief USARTDIV value */
#define USART_DIV 0x8B

int kernel_main( void ) {
  init_349(); // DO NOT REMOVE THIS LINE
  uart_polling_init(USART_DIV);

  systick_init();

  uint32_t start = systick_get_ticks();

  systick_delay(10000); //1000 ms = 1 second

  uint32_t elapsed = systick_get_ticks() - start;
  printk("Elapsed: %u ms\n", elapsed);

  return 0;
}
