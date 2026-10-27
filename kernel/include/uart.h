/**
 * @file
 *
 * @brief
 *
 * @date
 *
 * @author
 */

#ifndef _UART_H_
#define _UART_H_

/** @brief buffer capacity (power of 2) */
#define UART_BUF_SIZE 64

typedef struct {
  char data[UART_BUF_SIZE];
  volatile uint32_t head;
  volatile uint32_t tail;
} buf_t;

extern buf_t uart_tx_buf;
extern buf_t uart_rx_buf;

void uart_init(int baud);

int uart_put_byte(char c);

int uart_get_byte(char *c);

int uart_write( int file, char *ptr, int len );

int uart_read(int file, char *ptr, int len );

void uart_flush();

#endif /* _UART_H_ */
