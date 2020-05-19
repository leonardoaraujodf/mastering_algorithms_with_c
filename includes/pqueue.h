/**
 * @file heap.h
 * @author Kyle Loudon
 * @date 18 May 2020
 * @brief Header for the Priority Queue Abstract Datatype.
 * 
 */

#ifndef PQUEUE_H
#define PQUEUE_H

#include "heap.h"

/**
 * @brief Implement priority queues as heaps.
*/
typedef Heap PQueue;

/* ------------------------------------- Public Interface --------------------------------------- */

/*
 * @brief Initializes the priority queue specified by pqueue.
 * 
 * This operation must be called for a priority queue before it can be used with any other 
 * operation. The compare argument is a function used by various priority queue operations in
 * maintaining the priority queue's heap property. This function should return 1 if key1 > key2, 0
 * if key1 = key2, and -1 if key1 < key2 for a priority queue in which large keys have a higher
 * priority. For a priority queue in which smaller keys have a higher priority, compare should
 * reverse the cases that return 1 and -1. The destroy argument provides a way to free dynamically
 * allocated data when #pqueue_destroy is called. For example, if the priority queue contains data
 * dynamically allocated using malloc, destroy should be set to free to free the data as the
 * priority queue is destroyed. For structured data containing several dynamically allocated
 * members, destroy should be set to a user-defined function that calls free for each dynamically
 * allocated member as well as for the structure itself. For a priority queue containing data that
 * should not be freed, destroy should be set to NULL. The complexity is O(1).
 * 
 * @param[in,out] pqueue The priority queue to be initialized.
 * @param[in] compare The compare function used to compare the elements when fixing the pqueue.
 * @param[in] destroy The destroy function is used to deallocated each user member specified in 
 * data.
 * @return None.
 * 
 */
#define pqueue_init heap_init

/*
 * @brief Destroys the priority queue specified by pqueue.
 * 
 * No other operation are permitted after calling #pqueue_destroy unless #pqueue_init is called 
 * again. The #pqueue_destroy operation extracts all elements from a priority queue and calls the
 * function passed as destroy to #pqueue_init once for each element as it is extracted, provided
 * destroy was not set to NULL. The complexity is O(lg n), where n is the number of elements in the
 * priority queue.
 * 
 * @param[in] pqueue The priority queue to be destroyed.
 * @return None.
 * 
 */
#define pqueue_destroy heap_destroy

/*
 * @brief Inserts an element into the priority queue specified by pqueue.
 * 
 * The new element contains a pointer to data, so the memory referenced by data should remain valid
 * as long as the element remains in the priority queue. It is the responsibility of the caller
 * to manage the storage associated with data. The complexity is O(lg n), where n is the number of
 * elements in the priority queue.
 * 
 * @param[in] pqueue The priority queue to insert the new element.
 * @param[in] data The data to be inserted in the new element.
 * @return 0 if inserting the element is succesful, or -1 otherwise.
 * 
 */
#define pqueue_insert heap_insert

/**
 * @brief Extracts the element at the top of the priority queue specified by pqueue.
 * 
 * Upon return, data points to the data stored in the element that was extracted. It is the
 * responsibility of the caller to manage the storage associated with the data.
 * 
 * @param[in] pqueue The priority queue to extract the element.
 * @param[in] data The data to be extracted. Upon return, data points to the data stored in the
 * element extracted.
 * @return 0 if extracting the element is succesful, or -1 otherwise.
 * 
 */
#define pqueue_extract heap_extract

/**
 * @brief Macro that evaluates to the highest priority element in the priority queue specified by
 * pqueue.
 * 
 * @param[in] pqueue The priority queue to evaluate the highest priority element.
 * @return Highest priority element in the priority queue, or NULL if the priority queue is empty.
 * The complexity is O(1).
 * 
 */
#define pqueue_peek(pqueue) ((pqueue)->tree == NULL ? NULL : (pqueue)->tree[0])

/**
 * @brief Macro that evaluates to the number of elements in the priority queue specified by queue.
 * 
 * @param[in] pqueue The priority queue to evaluate the size.
 * @return Number of elements in the priority queue.
 * 
 */
#define pqueue_size heap_size

#endif