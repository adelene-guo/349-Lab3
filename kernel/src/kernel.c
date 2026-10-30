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
#include <lcd_driver.h>
#include <gpio.h>
#include <timer.h>
#include <servok.h>

/** @brief USARTDIV value */
#define USART_DIV 0x8B

int kernel_main( void ) {
  init_349(); // DO NOT REMOVE THIS LINE
  uart_init(USART_DIV);
  systick_init();
  lcd_driver_init();
  lcd_clear();
  systick_delay(1000);
  servo_init();
  enter_user_mode();


  // // testing servo
  // servo_init();
  // sys_servo_enable(1, 1);
  // sys_servo_enable(2, 1);

  // while (1) {
  //   sys_servo_set(1, 0);   
  //   sys_servo_set(2, 180);
  //   systick_delay(1500);

  //   sys_servo_set(1, 90);  
  //   sys_servo_set(2, 90);
  //   systick_delay(1500);

  //   sys_servo_set(1, 180); 
  //   sys_servo_set(2, 0);
  //   systick_delay(1500);
  // }


  // //Initialize green LED (testing timer)
  // gpio_port gpio_portGreen = GPIO_A;
  // unsigned int numGreen    = 8;
  // unsigned int modeGreen   = MODE_GP_OUTPUT;
  // unsigned int otypeGreen  = OUTPUT_PUSH_PULL;
  // unsigned int speedGreen  = OUTPUT_SPEED_LOW;
  // unsigned int pupdGreen   = PUPD_NONE;
  // unsigned int altGreen    = ALT0;  
  // gpio_init(gpio_portGreen, numGreen, modeGreen, otypeGreen, speedGreen, pupdGreen, altGreen);
  // timer_init(2, 15999, 999);



  // // checkpoint code
  // uint32_t next = systick_get_ticks() + 1000; // 1000ms = 1s
  // while (1) {
  //   int countdown = systick_get_ticks() - next;
  //   if (countdown >= 0) {
  //     printk("Interrupt!\n");
  //     next += 1000;
  //   }
  // }
  return 0;
}
