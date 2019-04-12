/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
  uint8_t *destItr = dst;

  uint8_t * temp = (uint8_t *)calloc(length,sizeof(*temp));
  size_t itr;

  for(itr = 0; itr < length; ++itr)
  {
    *(temp+itr) = *(src+itr);
  }

  for(itr = 0; itr < length; ++itr)
  {
    *(destItr+itr) = *(temp +itr);
  }

  free(temp);
  return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
  if(src == NULL)
  {
    return dst;
  }

  if(dst == NULL)
  {
    dst = (uint8_t *)calloc(length+1,sizeof(*dst));
    if(dst == NULL)
    {
      return ((void *)(0));
    }
  }

  size_t len = 0;
  while((src != NULL) && (len < length))
  {
    *(dst+len) = *(src+len);
    ++len;
  }
  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
  if(src == NULL)
  {
    return src;
  }

  uint8_t itr = 0;
  //uint8_t *srcItr = src;

  while(itr < length)
  {
    *(src+itr) = value;
    //++srcItr;
    ++itr;
  }
  return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
  if(src == NULL)
  {
    return src;
  }

  src = my_memset(src, length, 0);

  return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
  size_t itr = 0;
  size_t mid  = length/2;
  size_t itrBack = length -1;

  if(length == 1)
  {
    return src;
  }

  while(itr < mid)
  {
    uint8_t temp = *(src + itr);
    *(src + itr) = *(src + itrBack);
    *(src + itrBack) = temp;
    ++itr;
    --itrBack;
  }

  return src;
}

int32_t * reserve_words(size_t length)
{
  int32_t *ret;
  ret = (int32_t *)malloc(length*sizeof(*ret));

  return ret;
}

void free_words(int32_t * src)
{
  if(src == NULL)
  {
    return;
  }

  src = realloc(src,0);

  return;
}
