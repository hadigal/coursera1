#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define M1 0x0000000F
#define M2 0x000000F0
#define M3 0x00000F00
#define M4 0x0000F000
#define M5 0x000F0000
#define M6 0x00F00000
#define M7 0x0F000000
#define M8 0xF0000000

void revPtr(uint8_t **str, uint8_t itr);

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif
