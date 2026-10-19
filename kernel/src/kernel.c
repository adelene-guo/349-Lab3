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
#include <uart.h>

/** @brief USARTDIV value */
#define USART_DIV 0x8B

int kernel_main( void ) {
  init_349(); // DO NOT REMOVE THIS LINE
  uart_init(USART_DIV);

  systick_init();

  uint32_t next = systick_get_ticks() + 1000; // 1000ms = 1s
  while (1) {
    int countdown = systick_get_ticks() - next;
    if (countdown >= 0) {
      printk("Interrupt!\n");
      next += 1000;
    }
  }
  return 0;
}
