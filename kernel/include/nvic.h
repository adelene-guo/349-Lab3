/**
 * @file   nvic.h
 *
 * @brief  NVIC functions
 *
 * @date   August 28 2015
 * @author Kevin DeVincentis
 */
#ifndef _NVIC_H_
#define _NVIC_H_

#include <unistd.h>

/** @brief Documents nvic t. */
struct nvic_t {
  volatile uint32_t reg[3]; /**< Three 32-bit interrupt control registers. */
};

/** @brief Documents NVIC ISER BASE. */
#define NVIC_ISER_BASE (struct nvic_t *) 0xE000E100
/** @brief Documents NVIC ICER BASE. */
#define NVIC_ICER_BASE (struct nvic_t *) 0xE000E180
/** @brief Documents NVIC ICPR BASE. */
#define NVIC_ICPR_BASE (struct nvic_t *) 0xE000E280
/** @brief Documents NVIC REG SIZE. */
#define NVIC_REG_SIZE 32
/** @brief Documents IRQ ENABLE. */
#define IRQ_ENABLE 1
/** @brief Documents IRQ DISABLE. */
#define IRQ_DISABLE 0

/** @brief Documents nvic irq. */
void nvic_irq( uint8_t irq_num, uint8_t status );
/** @brief Documents nvic clear pending. */
void nvic_clear_pending( uint8_t irq_num );

#endif //_NVIC_H
