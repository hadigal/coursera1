//For this function you will need to call a handful of functions and test your
//function outputs. You only need to call each of the following functions once.
//These include test_data1(), test_data2(), test_memmove1(), test_memmove2(),
//test_memmove3(), test_memcopy(), test_memset(), and test_reverse().
#include "data.h"
#include "memory.h"

int8_t course1();

// This function will test to atoi and itoa conversions for you.
int8_t test_data1();

//This function will test to atoi and itoa conversions for you.
int8_t test_data2();

//This function will test non-overlapped memmove.
int8_t test_memmove1();

// This function will test overlapped memmove where there is overlap of the end
// of destination and start of the source regions.
int8_t test_memmove2();

// This function will test overlapped memmove where there is overlap of
// the start of destination and end of the source regions.
int8_t test_memmove3();

// This function will test memcopy.
int8_t test_memcopy();

// This function will test memset and memzero.
int8_t test_memset();

// This function will test reverse.
int8_t test_reverse();
