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
 * @file: stats.c
 * @brief: this file contains mains main() and other function definitions for all
 * the functions declared in stats.h
 *
 *
 * @author Hrishikesh Adigal
 * @date 01/30/2019
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

 temp = (unsigned char *)calloc(SIZE,sizeof(*temp));

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  sort_array(test,SIZE);
  print_array(test,SIZE);
  unsigned char max, min, mean, median;
  max = find_maximum(test,SIZE);
  min = find_minimum(test,SIZE);
  mean = find_mean(test,SIZE);
  median = find_median(test,SIZE);

  // printf("\nMAX:%u\nMIN:%u\n",max,min);
  // printf("\nMEAN:%u\nMEDIAN:%u\n",mean,median);
  print_statistics(mean,median,min,max,test,SIZE);
  return;
}

void mergeSort(unsigned char *arr, int lIdx, int rIdx)
{
  int mid;
  if(lIdx < rIdx)
  {
    mid = (rIdx+lIdx)/2;
    mergeSort(arr,lIdx,mid);
    mergeSort(arr,mid+1,rIdx);
    mergeArr(arr,temp,lIdx,mid,mid+1,rIdx);
    copyArr(arr,temp,lIdx,rIdx);
  }
}

/* Add other Implementation File Code Here */
void sort_array(unsigned char *arr, int size)
{
  mergeSort(arr,0,size -1);
  print_array(arr,size);
  reverseCopy(arr,temp,size);
}

void mergeArr(unsigned char *arr, unsigned char *temp, int lIdx1, int rIdx1, int lIdx2, int rIdx2)
{
  int itr1 = lIdx1;
  int itr2 = lIdx2;
  int itr3 = lIdx1;

  while((itr1 <= rIdx1) && (itr2 <= rIdx2))
  {
    if(arr[itr1] <= arr[itr2])
    {
      temp[itr3++] = arr[itr1++];
    }
    else
    {
      temp[itr3++] = arr[itr2++];
    }
  }
  while(itr1 <= rIdx1)
  {
    temp[itr3++] = arr[itr1++];
  }
  while(itr2 <= rIdx2)
  {
    temp[itr3++] = arr[itr2++];
  }
}

void copyArr(unsigned char * arr, unsigned char * temp, int lIdx, int rIdx)
{
  int itr;
  for(itr = 0; itr <= rIdx; ++itr)
  {
    arr[itr] = temp[itr];
  }
}

void reverseCopy(unsigned char *arr, unsigned char *temp, int size)
{
  int itr1 = 0;
  int itr2 = size-1;
  while(itr1 < size)
  {
    arr[itr2--] = temp[itr1++];
  }
}

#ifdef VERBOSE
void print_array(unsigned char *arr, int size)
{
  //printf("\nElements of the given array of size:%d :\n",size);
  PRINTF("\nElements of the given array of size:%d :\n",size);
  for(int itr = 0; itr < size; ++itr)
  {
    //printf("arr[%u]:%u\n",itr,arr[itr]);
    PRINTF("arr[%u]:%u\n",itr,arr[itr]);
  }
}
#else
void print_array(unsigned char *arr, int size)
{

}
#endif

unsigned char find_maximum(unsigned char *arr, int size)
{
  unsigned char max;
  int itr;
  for(itr = 0; itr < size; ++itr)
  {
    if(itr == 0)
    {
      max = arr[itr];
    }
    else
    {
      if(arr[itr] > max)
      {
        max = arr[itr];
      }
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char *arr, int size)
{
  unsigned char min;
  int itr;
  for(itr = 0; itr < size; ++itr)
  {
    if(itr == 0)
    {
      min = arr[itr];
    }
    else
    {
      if(arr[itr] < min)
      {
        min = arr[itr];
      }
    }
  }
  return min;
}

unsigned char find_mean(unsigned char *arr, int size)
{
  int itr = 0;
  unsigned int mean = 0;
  while(itr < size)
  {
    mean += arr[itr++];
  }
  printf("...mean:%u\n",mean);
  mean /= size;
  return mean;
}

unsigned char find_median(unsigned char *arr, int size)
{
  int itr = 0;
  unsigned char median;
  int mid;
  if((size%2) == 0)
  {
    mid = size/2;
    median = (arr[mid] + arr[mid - 1])/2;
  }
  else
  {
    mid = size/2;
    median = arr[mid];
  }
  return median;
}

void print_statistics(uchar mean, uchar median, uchar max, uchar min, uchar *arr, int size)
{
  //printf("\n****************** STATISTICS ******************\n");
  PRINTF("\n****************** STATISTICS ******************\n");
  //printf("MEAN:%u\nMEADIAN:%u\nMIN:%u\nMAX:%u\n",mean,median,min,max);
  PRINTF("MEAN:%u\nMEADIAN:%u\nMIN:%u\nMAX:%u\n",mean,median,min,max);
  print_array(arr,size);
  //printf("\n************************************************\n");
  PRINTF("\n************************************************\n");
}
