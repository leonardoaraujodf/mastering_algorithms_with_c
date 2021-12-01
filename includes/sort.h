/**
 * @file sort.h
 * @author Kyle Loudon
 * @date 28 April 2021
 * @brief Header for Sorting Algorithms.
 */
#include <stdio.h>

#ifndef SORT_H
#define SORT_H

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

/**
 * @brief Uses quicksort to sort the array of elements in data.
 * Complexity: O(n lg n), where n is the number of elements to be sorted.
 *
 * @param[in/out] data The data to be sorted. When qksort returns, data contains the sorted elements.
 * @param[in] size The number of elements in data.
 * @param[in] esize The size of each element.
 * @param[in] i Defines the current partition being sorted. Should be initialized to 0.
 * @param[in] k Defines the current partition being sorted. Should be initialized to size - 1;
 * @param[in] compare Specifies a user-defined function to compare elements. This function should return 1 if
 * key1 > key2, 0 if key1 = key2, and –1 if key1 < key2 for an ascending sort.
 * For a descending sort, compare should reverse the cases returning 1 and –1. When qksort returns, data contains
 * the sorted elements.
 * @return Returns 0 if sorting is successful, or –1 otherwise.
 */
int qksort(void *data, int size, int esize, int i, int k, int (*compare)(const void *key1, const void *key2));

/**
 * @brief Uses merge sort to sort the array of elements in data.
 * Complexity: O(n lg n), where n is the number of elements to be sorted.
 *
 * @param[in] data The data to be sorted. When mgsort returns, data contains the sorted elements.
 * @param[in] size The number of elements in data.
 * @param[in] esize The size of each element.
 * @param[in] i Defines the current division being sorted. Should be initialized to 0.
 * @param[in] k Defines the current division being sorted. Should be initialized to size - 1.
 * @param[in] compare Specifies a user-defined function to compare elements. This function should return 1 if
 * key1 > key2, 0 if key1 = key2, and –1 if key1 < key2 for an ascending sort.
 * For a descending sort, compare should reverse the cases returning 1 and –1. When mgsort returns, data contains
 * the sorted elements.
 *
 * @return Returns 0 if sorting is successful, or –1 otherwise.
 */
int mgsort(void *data, int size, int esize, int i, int k, int (*compare)(const void *key1, const void *key2));

#endif
