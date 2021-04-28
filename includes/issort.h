/**
 * @file issort.h
 * @author Kyle Loudon
 * @date 28 April 2021
 * @brief Header for the Insertion Sort Algorithm.
 */
#include <stdio.h>

#ifndef ISSORT_H
#define ISSORT_H

/**
 * @brief Uses insertion sort to sort the array of elements in data.
 * Complexity: O(n ** 2), where n is the number of elements to be sorted.
 *
 * @param[in/out] data The data to be sorted. When issort returns, data contains the sorted elements.
 * @param[in] size The number of elements in data.
 * @param[in] esize The size of each element.
 * @param[in] compare Specifies a user-defined function to compare elements. This function should return 1 if
 * key1 > key2, 0 if key1 = key2, and –1 if key1 < key2 for an ascending sort.
 * For a descending sort, compare should reverse the cases returning 1 and –1. When issort returns, data contains
 * the sorted elements.
 * @return Returns 0 if sorting is successful, or –1 otherwise.
 */
int issort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

#endif
