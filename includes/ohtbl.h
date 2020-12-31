/**
 * @file ohtbl.h
 * @author Kyle Loudon
 * @date 8 May 2020
 * @brief Header for Open-Addressed Hash Table Abstract Datatype
 */

#ifndef OHTBL_H
#define OHTBL_H

#include <stdlib.h>

/** 
 * @brief A structure for open-addressed hash tables.
 */
typedef struct OHTbl_ {
    int positions; /*!< The number of positions allocated in the hash table. */
    void *vacated; /*!< A pointer that will be initialized to a special storage location to indicate
    that a particular position in the table has had an element removed from it. */

    int (*h1)(const void *key); /*!< h1 User-defined auxiliary hash function 1 for double hashing
    used in #ohtbl_init.*/
    int (*h2)(const void *key); /*!< h2 User-defined auxiliary hash function 1 for double hashing
    used in #ohtbl_init.*/
    int (*match)(const void *key1, const void *key2); /*!< User-defined function to determine if two
     keys match in #ohtbl_init.*/
    void (*destroy)(void *data); /*!< User-defined function to provide a way to free dynamically 
    allocated data when #ohtbl_destroy is called.*/

    int size;
    void **table;
} OHTbl;

/* ------------------------------------- Public Interface --------------------------------------- */

/**
 * @brief Initializes the open-addressed hash table specified by htbl. 
 * 
 * This operation must be called for an open-addressed hash table before the hash table can be used
 * with any other operation. The number of positions to be allocated in the hash table is specified
 * by positions. The function pointers h1 and h2 specify user-defined auxiliary hash functions for
 * double hashing. The function pointer match specifies a user-defined function to determine if two
 * keys match. It should perform in a manner similiar to that described for #chtbl_init. The destroy
 * argument provides a way to free dynamically allocated data when #ohtbl_destroy is called. It
 * works in a manner similar to that described for chtbl_destroy. For an open-addressed hash table
 * containing data that should not be freed, destroy should be set to NULL. The complexity is O(m),
 * where m is the number of positions in the hash table.
 * 
 * @param[in,out] htbl The open-addressed hash table to be initialized.
 * @param[in] positions The number of positions to be allocated in the hash table.
 * @param[in] h1 User-defined auxiliary hash function 1 for double hashing.
 * @param[in] h2 User-defined auxiliary hash function 2 for double hashing.
 * @param[in] match User-defined function to determine if two keys match.
 * @param[in] destroy Provides a way to free dynamically allocated data when #ohtbl_destroy is 
 * called.
 * @return 0 if initializing the hash table is succesful, or -1 otherwise.
 */
int ohtbl_init(OHTbl *htbl, int positions, int (*h1)(const void *key), int (*h2)(const void *key), 
               int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));

/**
 * @brief Destroys the open-addressed hash table specified by htbl.
 * 
 * No other operations are permitted after calling #ohtbl_destroy unless #ohtbl_init is called 
 * again. The #ohtbl_destroy unless #ohtbl_init is called again. The #ohtbl_destroy operation
 * removes all elements from a hash table and calls the function passed as destroy to #ohtbl_init
 * once for each element as it is removed, provided destroy was not set to NULL. The complexity is
 * O(m), where m is the number of positions in the hash table.
 * 
 * @param[in] htbl The open-addressed hash table to be destroyed.
 * @return None.
 * 
 */
void ohtbl_destroy(OHTbl *htbl);

/**
 * @brief Inserts an element into the open-addressed hash table specified by htbl.
 * 
 * The new element contains a pointer to data, so the memory referenced by data should remain valid
 * as long as the element remains in the hash table. It is the responsibility of the caller to
 * manage the storage associated with data. The complexity is O(1).
 * 
 * @param[in,out] htbl The open-addressed hash table to insert the element.
 * @param[in] data A pointer to the element(s) to be inserted in htbl.
 * @return 0 if inserting the element is succesful, 1 if the element is already in the hash table,
 * or -1 otherwise.
 * 
 */
int ohtbl_insert(OHTbl *htbl, const void *data);

/**
 * @brief Removes the element matching data from the open-addressed hash table specified by htbl.
 * 
 * Upon return, data points to the data stored in the element that was removed. If is the
 * responsibility of the caller to manage the storage associated with the data. The complexity is
 * O(1).
 * 
 * @param[in,out] htbl The open-addressed hash table to delete the element.
 * @param[in,out] data A pointer to the data to be removed. Upon return, data points to the data
 * stored in the element that was removed.
 * @return 0 if removing the element is succesful, or -1 otherwise.
 * 
 */
int ohtbl_remove(OHTbl *htbl, const void **data);

/**
 * @brief Determines whether an element matches data in the open addressed hash table specified by
 * htbl.
 * 
 * If a match is found, upon return data points to the matching data in the hash table.
 * The complexity is O(1).
 * 
 * @param[in] htbl The open-addressed hash table to lookup the element.
 * @param[in,out] data A pointer to the element to be found. 
 * @return 0 if the element is found in the hash table, or -1 otherwise.
 * 
 */
int ohtbl_lookup(const OHTbl *htbl, void **data);

/**
 * @brief Macro that evaluates to the number of elements in the open-addressed hash table specified
 * by htbl. The complexity is O(1).
 * 
 * @return Number of elements in the hash table.
 * 
 */
#define ohtbl_size(htbl) ((htbl)->size)

#endif
