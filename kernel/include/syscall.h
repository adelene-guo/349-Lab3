/**
 * @file syscall.h
 *
 * @brief      
 *
 * @date       
 *
 * @author     
 */

#ifndef _SYSCALLS_H_
#define _SYSCALLS_H_

/** @brief Documents sys sbrk. */
void *sys_sbrk(int incr);

/** @brief Documents sys write. */
int sys_write(int file, char *ptr, int len);

/** @brief Documents sys read. */
int sys_read(int file, char *ptr, int len);

/** @brief Documents sys exit. */
void sys_exit(int status);

/** @brief Documents sys servo enable. */
int sys_servo_enable(uint8_t channel, uint8_t enabled);

/** @brief Documents sys servo set. */
int sys_servo_set(uint8_t channel, uint8_t angle);

#endif /* _SYSCALLS_H_ */
