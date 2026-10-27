/**
 * @file syscall.c
 *
 * @brief      
 *
 * @date       
 *
 * @author     
 */

#include <unistd.h>
#include <syscall.h>
#include <uart.h>
#include <printk.h>
#include <nvic.h>
#include <lcd_driver.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

extern char __heap_low[];
extern char __heap_top[];
static char *heap_ptr = (char *)&__heap_low;

#define UNUSED __attribute__((unused))
/**
 * @brief transmits one byte
 */
static void echo_byte(char c) {
  while (uart_put_byte(c) != 0) {}
}

void *sys_sbrk(UNUSED int incr){

  if (heap_ptr + incr > (char *)&__heap_top
      || heap_ptr + incr < (char *)&__heap_low) {
    return (void *)-1; // ran out of memory
  }
  char *old_ptr = heap_ptr;
  heap_ptr += incr;
  return (void *)old_ptr;
}

int sys_write(UNUSED int file, UNUSED char *ptr, UNUSED int len){
  if (file != 1) return -1; // if output is not stdout, return -1
  for (int i = 0; i < len; i++) {
    echo_byte(ptr[i]);
  }
  return len;
}

int sys_read(UNUSED int file, UNUSED char *ptr, UNUSED int len){
  static bool skip_lf = false; //true right after a '\r', so the '\n' of "\r\n" is ignored

  if (file != 0) return -1; // if input is not stdin, return -1

  int count = 0;
  while (count < len) {
    char c;
    while (uart_get_byte(&c) != 0) {} //wait for character

    if (c == '\n' && skip_lf) { //second half of a Windows "\r\n"
      skip_lf = false;
      continue;
    }
    skip_lf = (c == '\r');
    if (c == '\r') c = '\n'; //treat Enter as newline from here on

    if (c == 4) return count;

    else if (c == '\b') {
      if (count > 0) {
        count--;
        echo_byte('\b');
        echo_byte(' ');
        echo_byte('\b');
      }
    }

    else {
      ptr[count++] = c;
      echo_byte(c);
    }
    
    if (c == '\n') return count;
  }
  return len;
}

void sys_exit(UNUSED int status){
  char status_msg[256];
  snprintf(status_msg, sizeof(status_msg), "%s%d", "Exited status: ", status);
  
  //print the exit code
  printk(status_msg);

  //flush the uart buffers and disable interrupts
  uart_flush();

  //display the exit code on the screen
  lcd_print(status_msg);
}