/*

File    : STM32L432KC_FLASH.c
Author  : Erin Wang
Date    : 9/30/2025
Purpose : Source code for FLASH functions

*/

#include "STM32L432KC_FLASH.h"

void configureFlash() {
    FLASH->ACR |= (0b100); // Set to 4 waitstates
    FLASH->ACR |= (1 << 8); // Turn on the ART
}
