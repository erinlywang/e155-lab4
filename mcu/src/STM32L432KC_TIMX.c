/*

File    : STM32L432KC_TIMX.c
Author  : Erin Wang
Date    : 9/30/2025
Purpose : Source code for TIMX functions (initTIM is for initializing the delay timer)

*/

#include "STM32L432KC_TIMX.h"

#define PWMFREQ  10000000
#define PWMPSC    7
#define DELAYPSC  7999
#define DELAYTICKPERMS  10
void initTIM(TIMX_TypeDef * TIMX) {
    // Make sure slave mode is off (Set bits 16, 2, 1, 0 to 0)
    TIMX -> SMCR &= ~((1 << 0) | (1 << 1) | (1 << 2) | (1 << 16));

    // Set Prescaler to 7 because we're dividing by PSC + 1 = 8
    TIMX -> PSC = DELAYPSC;

    // Generate an update event to update prescaler
    TIMX -> EGR |= 1;

    // Clear the counter
    TIMX -> CNT = 0;

    // Enable the counter
    TIMX -> CR1 |= 1;
}

void delay_millis(TIMX_TypeDef * TIMX, uint32_t ms) {
    TIMX -> ARR = ms*DELAYTICKPERMS;   // Set timer max count
    TIMX -> SR &= ~(1 << 0);      // Clear the interrupt flag

    while(!((TIMX -> SR) & 1));     // wait for UIF to go high

}


void initTIMPWM(TIMX_TypeDef * TIMX){   
    // Set Prescaler to 7 because we're dividing by PSC + 1 = 8
    TIMX -> PSC = PWMPSC;

    // Enable CC1 (Set bit 0 to 1)
    TIMX -> CCER |= 1;

    // Set as active HIGH (Set bit 1 to 0)
    TIMX -> CCER &= ~(1 << 1);

    // Enable the Main Output Bit to 1 
    TIMX -> BDTR |= (1 << 15);  

    // Enable output compare 1 preload (Set bit 3 to 1)
    TIMX -> CCMR1 |= (1 << 3);

    // Set OCM1 output to PWM mode (Set bit 6:4 to 110)
    TIMX -> CCMR1 |= ((1 << 5) | (1 << 6));
    TIMX -> CCMR1 &= ~(1 << 4);

    //Reinitialize the counter using the UG bit of EGR (Set bit 0 to 1)
    TIMX -> EGR |= 1;

    // Clear the counter
    TIMX -> CNT = 0;

    // Enable the counter
    TIMX -> CR1 |= 1;
}

void TIM_outPWM(TIMX_TypeDef * TIMX, uint32_t note_freq) {
    if (note_freq == 0) {
      // Set the CCR1 to 0
      TIMX -> CCR1 = 0;
    
      // Set the auto-reload register be greater than 0 (1)
      TIMX -> ARR = 1;
    }
        
    else {
      uint32_t counter_freq = PWMFREQ / note_freq;

      // Set the CCR1 channel to half the auto-reload register
      TIMX -> CCR1 = counter_freq / 2;
    
      // Set the auto-reload register to be the necessary number of ticks
      TIMX -> ARR = counter_freq;
    }
}
