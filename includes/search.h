/**
 * @file sort.h
 * @author Kyle Loudon
 * @date 28 December 2021
 * @brief Header for Searching Algorithms.
 */
#include <stdio.h>

#ifndef SEARCH_H
#define SEARCH_H

/**
 * @brief Uses binary search to locate target in sorted, a sorted array of elements.
 * Complexity: O(lg n), where n is the number of elements to be searched.
 *
 * @param[in] sorted A sorted array of elements to search for target.
 * @param[in] target The target element to search in sorted.
 * @param[in] size The number of elements in sorted
 * @param[in] esize The size of each element.
 * @param[in] compare Specifies a user-defined function to compare elements.
 * This function should return 1 if key1 > key2, 0 if key1 = key2, and –1 if key1 < key2 for
 * an ascending sort.
 * For a descending sort, compare should reverse the cases returning 1 and –1.
 * When issort returns, data contains the sorted elements.
 *
 * @return Returns the index of the target if found, or -1 otherwise.
 */
int bisearch(void *sorted, const void *target, int size, int esize,
             int (*compare)(const void *key1, const void *key2));

#endif
