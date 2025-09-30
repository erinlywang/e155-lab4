// STM32L432KC_RCC.h
// Header for RCC functions

#ifndef STM32L4_TIMX_H
#define STM32L4_TIMX_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile

// Frequencies


// Base addresses
#define TIM15_BASE (0x40014000UL) // base address of TIM15
#define TIM16_BASE (0x40014400UL) // base address of TIM16

/**
  * @brief Timers 15 and 16
  */

typedef struct
{
  __IO uint32_t CR1;         /*!< TIMX clock control register 1,                                           Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< TIMX clock control register 1,                                           Address offset: 0x04 */
  __IO uint32_t SMCR;        /*!< TIMX slave mode control register,                                        Address offset: 0x08 */
  __IO uint32_t DIER;        /*!< TIMX DMA/interrupt enable register,                                      Address offset: 0x0C */
  __IO uint32_t SR;          /*!< TIMX status register,                                                    Address offset: 0x10 */
  __IO uint32_t EGR;         /*!< TIMX event generation register,                                          Address offset: 0x14 */
  __IO uint32_t CCMR1;       /*!< TIMX capture/compare mode register 1,                                    Address offset: 0x18 */
  uint32_t      RESERVED;    /*!< Reserved, to ccmr1 input                                                                Address offset: 0x1C */
  __IO uint32_t CCER;        /*!< TIMX capture/compare enable register,                                    Address offset: 0x20 */
  __IO uint32_t CNT;         /*!< TIMX counter,                                                            Address offset: 0x24 */
  __IO uint32_t PSC;         /*!< TIMX prescaler,                                                          Address offset: 0x28 */
  __IO uint32_t ARR;         /*!< TIMX auto-reload register,                                               Address offset: 0x2C */
  __IO uint32_t RCR;         /*!< TIMX repetition counter register,                                        Address offset: 0x30 */
  __IO uint32_t CCR1;        /*!< TIMX capture/compare register 1,                                         Address offset: 0x34 */
  __IO uint32_t CCR2;        /*!< TIMX capture/compare register 2,                                         Address offset: 0x38 */
  uint32_t      RESERVED0;   /*!< Reserved,                                                                Address offset: 0x3C */
  uint32_t      RESERVED1;   /*!< Reserved,                                                                Address offset: 0x40 */
  __IO uint32_t BDTR;        /*!< TIMX break and dead-tim register,                                        Address offset: 0x44 */
  __IO uint32_t DCR;         /*!< TIMX DMA control register,                                               Address offset: 0x48 */
  __IO uint32_t DMAR;        /*!< TIMX DMA address for full transfer,                                      Address offset: 0x4C */
  __IO uint32_t OR1;         /*!< TIMX option register 1,                                                  Address offset: 0x50 */
  uint32_t      RESERVED2;   /*!< Reserved,                                                                Address offset: 0x54 */
  uint32_t      RESERVED3;   /*!< Reserved,                                                                Address offset: 0x58 */
  uint32_t      RESERVED4;   /*!< Reserved,                                                                Address offset: 0x5C */
  __IO uint32_t OR2;        /*!< TIMX option register 2,                                                   Address offset: 0x60 */
} TIMX_TypeDef;

#define TIM15 ((TIMX_TypeDef *) TIM15_BASE)
#define TIM16 ((TIMX_TypeDef *) TIM16_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////
void initTIM(TIMX_TypeDef * TIMX);
void delay_millis(TIMX_TypeDef * TIMX, uint32_t ms);
void initTIMPWM(TIMX_TypeDef * TIMX);
void TIM_outPWM(TIMX_TypeDef * TIMX, uint32_t freq);

#endif