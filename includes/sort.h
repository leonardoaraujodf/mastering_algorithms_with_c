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


/**
 * @brief Uses couting sort to sort the array of int elements in data.
 * Complexity: O(n + k), where n is the number of integer elements to be sorted and k is the maximum
 * integer in data.
 *
 * @param[in] data The data to be sorted. When ctsort returns, data contains the sorted integers.
 * @param[in] size The number of elements in data.
 * @param[in] k The maximum integer in data, plus 1 (Attention!).
 *
 * @return Returns 0 if sorting is successful, or –1 otherwise.
 */
int ctsort(int * data, int size, int k);


/*
 * @brief Uses radix sort to sort the array of int elements in data.
 * Complexity: O(pn + pk), where n is the number of integers to be sorted, k is the radix, and p is
 * the number of digit positions.
 *
 * @param[in] data The data to be sorted. When rxsort returns, data contains the sorted integers.
 * @param[in] size The number of elements in data.
 * @param[in] p The number of digital positions in each integer.
 * @param[in] k The radix to be used.
 */
int rxsort(int *data, int size, int p, int k);

#endif
