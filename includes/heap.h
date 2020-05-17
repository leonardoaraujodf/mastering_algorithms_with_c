/**
 * @file heap.h
 * @author Kyle Loudon
 * @date 17 May 2020
 * @brief Header for the Heap Abstract Datatype.
 */

#ifndef HEAP_H
#define HEAP_H

/**
 * @brief Define a structure for heaps.
 * 
 */
typedef struct Heap_ {
    int size;
    int (*compare)(const void *key1, const void *key2);
    int (*destroy)(void *data);

    void **tree;
} Heap;

/* ------------------------------------- Public Interface --------------------------------------- */

/**
 * @brief Initializes the heap specified by heap. 
 * 
 * This operation must be called for a heap before the heap can be used with any other operation.
 * The compare argument is a function used by various heap operations to compare nodes when fixing
 * the heap. This function should return 1 if key1 > key2, 0 if key1 = key2, and -1 if key1 < key2
 * for a top-heavy heap. For a bottom-heavy heap, compare should reverse the cases that return 1
 * and -1. The destroy argument provides a way to free dynamically allocated data when #heap_destroy
 * is called. For example, if the heap contains data dynamically allocated using malloc, destroy
 * should be set to free to free the data as the heap is destroyed. For structured data containing
 * several dynamically allocated members, destroy should be set to a user-defined function that
 * calls free for each dynamically allocated member as wells as for the structure itself. For a heap
 * containing data that should not be freed, destroy should be set to NULL. The complexity is O(1).
 * 
 * @param[in,out] heap The heap to be initialized.
 * @param[in] compare The compare function used to compare the nodes when fixing the heap.
 * @param[in] destroy The destroy function is used to deallocated each user member specified in 
 * data.
 * @return None.
 * 
 */
void heap_init(Heap *heap, int (*compare)(const void *key1, const void *key2), 
               void (*destroy)(void *data));

/**
 * @brief Destroys the heap specified by heap.
 * 
 * No other operations are permitted after calling #heap_destroy unless #heap_init is called again.
 * The #heap_destroy operation removes all nodes from a heap and calls the function passed as 
 * destroy to #heap_init once for each node as it is removed, provided destroy was not set to NULL.
 * The complexity is O(n), where n is the number of nodes in the heap.
 * 
 * @param[in] heap The heap to be destroyed.
 * @return None.
 * 
 */
void heap_destroy(Heap *heap);

/**
 * @brief Inserts a node into the heap specified by heap.
 * 
 * The new node contains a pointer to data, so the memory referenced by data should remain valid as
 * long as the node remains in the heap. It is the responsibility of the caller to manage the 
 * storage associated with data. The complexity is O(log(n)), where n is the number of nodes in the
 * heap.
 * 
 * @param[in] heap The heap to insert the new node.
 * @param[in] data The data to be inserted in the new node.
 * @return 0 if inserting the node is succesful, or -1 otherwise.
 * 
 */
int heap_insert(Heap *heap, const void *data);

/**
 * @brief Extracts the node at the top of the heap specified by heap.
 * 
 * Upon return, data points to the data stored in the node that was extracted. It is the 
 * responsibility of the caller to manage the storage associated with the data. The complexity is
 * O(log(n)), where n is the number of nodes in the heap.
 * 
 * @param[in] heap The heap to extract the node.
 * @param[in] data The data to be extracted. Upon return, data points to the data stored in the node
 * extracted.
 * @return 0 if extracting the node is succesful, or -1 otherwise.
 * 
 */
int heap_extract(Heap *heap, void **data);

/**
 * @brief Macro that evaluates to the number of nodes in the heap specified by heap.
 * 
 * @param[in] heap The heap to evaluate the size.
 * @return Number of nodes in the heap.
 */
#define heap_size(heap) ((heap)->size)

#endif