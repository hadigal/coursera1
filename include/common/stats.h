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
 * @file: stats.h
 * @brief: This file is the header file for all the functions defined in stats.c
 *
 *
 *
 * @author: Hrishikesh Adigal
 * @date: 01/31/2019
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include "platform.h"

/* Add Your Declarations and Function Comments here */
typedef unsigned char uchar;

uchar *temp;

/**
* @brief: Used as a recurrsive function to sort the given array using merge Sort
*
* This function assists in recurrsively sorting the given array
*
* @param arr: The split/given array
* @param lIdx: Left most index the split/given array
* @param rIdx: Right most index in the split/given array
*
* @return
*/
void mergeSort(uchar *arr, int lIdx, int rIdx);

/**
* @brief: Used to copy elements from temp array back to original array
*
* This function uses a temp array elements(sorted) to be copied back to org array
*
* @param arr: The split/given array
* @param arr: The temp array to copy elements from split array in sorted order
* @param lIdx: Left most index the split/given array
* @param rIdx: Right most index in the split/given array
*
* @return
*/
void copyArr(uchar *arr,uchar *temp, int lIdx, int rIdx);

/**
* @brief: Used to copy the elements in sorted order from the split arrays
*
* This function assists in copying the array in sorted order to a temp array and
* merge the split arrays
*
* @param arr: The split/given array
* @param arr: The temp array to copy elements from split array in sorted order
* @param lIdx: Left most index the split/given array
* @param rIdx: Right most index in the split/given array
*
* @return
*/
void mergeArr(uchar *arr, uchar *temp, int lIdx1, int rIdx1, int lIdx2, int rIdx2);

/**
* @brief: Used to copy the elements from sorted array in reverse order
*
* This function assists in copying the sorted array in reverse order
*
* @param arr: The split/given array
* @param temp: The temp array to copy elements from split array in sorted order
* @param size: Size of the org array
*
* @return
*/
void reverseCopy(uchar *arr, uchar *temp, int size);

/**
* @brief: Used to call the sort the given array
*
* This function assists in sorting the given array
*
* @param arr: The split/given array
* @param size: Size of the org array
*
* @return
*/
void sort_array(uchar *arr, int size);

/**
* @brief: Used to find the smallest element of the array
*
* This function assists in finding smallest element of the array
*
* @param arr: The split/given array
* @param size: Size of the org array
*
* @return smallest element (uchar)
*/
uchar find_minimum(uchar *arr, int size);

/**
* @brief: Used to find the largest element of the array
*
* This function assists in finding largest element of the array
*
* @param arr: The split/given array
* @param size: Size of the org array
*
* @return largest element (uchar)
*/
uchar find_maximum(uchar *arr, int size);

/**
* @brief: Used to find the mean of the array
*
* This function assists in finding mean of the array
*
* @param arr: The split/given array
* @param size: Size of the org array
*
* @return mean (uchar)
*/
uchar find_mean(uchar *arr, int size);

/**
* @brief: Used to find the median of the array
*
* This function assists in finding median of the array
*
* @param arr: The split/given array
* @param size: Size of the org array
*
* @return median (uchar)
*/
uchar find_median(uchar *arr, int size);

/**
* @brief: Used to print the given array
*
* This function assists in Printing the given array
*
* @param arr: The split/given array
* @param size: Size of the org array
*
* @return
*/
void print_array(uchar *arr, int size);

/**
* @brief: Used to print the Statistics
*
* This function assists in Printing the input Statistics
*
* @param arr: The split/given array
* @param size: Size of the org array
* @param mean: The mean
* @param median: the median
* @param max: The max element of the array
* @param size: The min element of the array
*
* @return
*/
void print_statistics(uchar mean, uchar median, uchar max, uchar min, uchar *arr, int size);

#endif /* __STATS_H__ */
