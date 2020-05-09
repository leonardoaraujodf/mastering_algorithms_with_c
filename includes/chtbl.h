/**
 * @file chtbl.h
 * @author Kyle Loudon
 * @date 8 May 2020
 * @brief Header for the Chained Hash Table Abstract Datatype
 */

#ifndef CHTBL_H
#define CHTBL_H

#include <stdlib.h>

#include "list.h"

/**
 * @brief A structure for chained hash tables
 */
typedef struct CHTbl_ {
    int buckets; /*!< Number of buckets in the hash table */
    int (*h)(const void *key); /*!< Pointer that specifies a user-defined function for 
    hashing keys */
    int (*match)(const void *key1, const void *key2); /*!< Pointer that specifies a user-defined
    function to determine whether two keys match */
    void (*destroy)(void *data); /*!< Pointer that specifies a user-defined function to be used
    by #chtbl_destroy */

    int size; /*!<  The number of elements currently in the table */
    List *table; /*!< The array of buckets */
} CHTbl;

/* --------------------- Public Interface ------------------------ */

/**
 * @brief Initializes the chained hash table specified by htbl.
 * 
 * This operation must be called for a chained hash table before the hash table can be used with any 
 * other operation. The number of buckets allocated in the hash table is specified by buckets. The
 * The function pointer h specifies a user-defined hash function for hashing keys. The function
 * pointer match specifies a user-defined function to determine whether two keys match. It should
 * return 1 if key1 is equal to key, and 0 otherwise. The destroy argument provides a way to free
 * dynamically allocated data when #chtbl_destroy is called. For example, if the hash table contains
 * data dynamically allocated using malloc, destroy should be set to free to free the data as the 
 * hash table is destroyed. For structured data containing several dynamically allocated members,
 * #destroy should be set to a user-defined function that calls free for each dynamically allocated
 * member as well as for the structure itself. For a hash table containing data tha should not be
 * freed, #destroy should be set to NULL.
 * 
 * @param[in,out] htbl Chained hash table to be initialized
 * @param[in] buckets Number of buckets allocated in the hash table
 * @param[in] h Pointer that specifies a user-defined function to determine
 * @param[in] match Pointer to the match function
 * @param[in] destroy Pointer to the destroy function
 * @return 0 if initializing the hash table is succesful, or -1 
 *         otherwise
 * 
 */
int chtbl_init(CHTbl *htbl, int buckets, int (*h)(const void *key), 
               int (*match)(const void *key1, const void *key2), 
               void (*destroy)(void *data));

/**
 * @brief Destroys the chained hash table specified by htbl. 
 * 
 * No other operations are permitted after calling #chtbl_destroy unless #chtbl_init is called
 * again. The #chtbl_destroy operation removes all elements from a hash table and calls the function
 * passed as destroy to #chtbl_init once for each element as it is removed, provided destroy was
 * not set to NULL.
 * 
 * @param[in,out] htbl Chained hash table to be initialized
 * @return None.
 * 
 */ 
void chtbl_destroy(CHTbl *htbl);

/**
 * @brief Inserts an element into the chained hash table specified by htbl.
 * 
 * The new element contains a pointer to data, so the memory referenced by data should remain valid
 * as long as the element remains in the hash table. It is the responsibility of the caller to 
 * manage the storage with data.
 * 
 * @param[in,out] htbl Chained hash table to insert the element
 * @param[in] data Data that is to be inserted in htbl
 * @return 0 if insert the element is successful, 1 if the element is already in the hash table,
 * or -1 otherwise.
 * 
 */
int chtbl_insert(CHTbl *htbl, const void *data);

/**
 * @brief Removes the element matching data from the chained hash table specified by htbl.
 * 
 * Upon return, data points to the data stored in the element that was removed. It is the
 * responsibility of the caller to manage the storage associated with the data.
 * 
 * @param[in, out] htbl Chained hash table to remove the element
 * @param[in] data Data that is to be removed from htbl
 * @return 0 if removing the element is succesful, or -1 otherwise
 *  
 */
int chtbl_remove(CHTbl *htbl, void **data);

/**
 * @brief Determines whether an element matches data in the chained hash table specified by htbl.
 * 
 * If a match is found, data points to the matching data in the hash table upon return.
 * 
 * @param[in] htbl Chained hash table to lookup.
 * @param[in, out] data Data that should be found.
 * @return 0 if the element is found in the hash table, or -1 otherwise.
 *  
 */
int chtbl_lookup(const CHTbl *htbl, void **data);

/**
 * @brief Macro that evaluates to the number of elements in the chained hash table specified by 
 * htbl.
 * 
 * @param[in] htbl Chained hash table to find the size
 * @return Number of elements in the hash table
 * 
 */
#define chtbl_size(htbl) ((htbl)->size)

#endif