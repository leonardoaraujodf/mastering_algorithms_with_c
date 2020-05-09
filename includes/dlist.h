/**
 * @file dlist.h
 * @author Kyle Loudon
 * @date 8 May 2020
 * @brief Header for the Doubly-Linked list Abstract Datatype
 */

#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

/**
 * @brief Define a structure for doubly-linked list elements.
 */
typedef struct DListElmt_
{
    void *data; /*!< A pointer to the data stored in element. */
    struct DListElmt_ *prev; /*!< A pointer to the previous element in the list of the same type. */
    struct DListElmt_ *next; /*!< A pointer to the next element in the list of the same type. */
} DListElmt;

/** 
 * @brief Define a structure for doubly-linked lists.
 */
typedef struct DList_ 
{
    int size; /*!< The actual size of the linked list. */
    int (*match)(const void *key1, const void *key2); /*!< A match function pointer used mostly by 
   other ADT for matching two elements based in a function given by the user. */
    void (*destroy)(void *data); /*!< The destroy function given by the user to be used in 
   #list_destroy*/
    DListElmt *head; /*!< The head element of the list, of the first element. */
    DListElmt *tail; /*!< The final element of the list, the last element or the tail element. */
} DList;

/* --------------------- Public Interface ------------------------ */

/**
 * @brief Initializes the doubly-linked list specified by list.
 * 
 * This operation must be called for a doubly-linked list before the list can be used with any other 
 * operation. The destroy argument provides a way to free dinamically allocated data when 
 * #dlist_destroy is called. It works in a manner similitar to thatdescribed for list_destroy. For a
 * doubly-linked list containing data that should not be freed, destroy should be set to NULL. The
 * complexity is O(1).
 * 
 * @param[in,out] dlist The doubly-linked to be initialized.
 * @param[in] destroy A pointer to the destroy user function to be used by #list_destroy
 * @return None.
 * 
 */ 
void dlist_init(DList *list, void (*destroy)(void *data));


/**
 * @brief: Destroys the doubly-linked list specified by list. 
 * 
 * No other operations are permitted after calling dlist_destroy unless #dlist_init is called again. 
 * The #dlist_destroy operation removes all elements from a doubly-linked list and calls the 
 * function passed as destroy to dlist_init once for each element as it is removed, provided destroy 
 * was not set to NULL. The complexity is O(n), where n is the number of elements in the
 * doubly-linked list.
 * 
 * @param[in] list The doubly-linked list to be destroyed.
 * @return None.
 * 
 */
void dlist_destroy(DList *list);

/**
 * @brief: Inserts an element just after element in the doubly-linked list specified by list. 
 * 
 * When inserting into an empty list, element may point anywhere, but should be NULL to avoid
 * confusion. The new element contains a pointer to data, so the memory referenced by data should 
 * remain valid as long as the element remains in the list. It is the responsibility of the
 * caller to manage the storage associated with data. The complexity is O(1).
 * 
 * @param[in,out] list The doubly-linked list to insert the element.
 * @param[in] element A element used as reference to insert the data next to it.
 * @param[in] data The data to be inserted.
 * @return 0 if inserting the element is succesful, or -1 otherwise.
 * 
 */
int dlist_ins_next(DList *list, DListElmt *element, const void *data);

/**
 * @brief Inserts an element just before element in the doubly-linked list specified by list. 
 * 
 * When inserting into an empty list, element may point anywhere, but should be NULL to avoid 
 * confusion. The new element contains a pointer to data, so the memory referenced by data should 
 * remain valid as long as the element remains in the list. It is the responsibility of the caller 
 * to manage the storage associated with data.
 * 
 * @param[in,out] list The doubly-linked list to insert the element.
 * @param[in] element A element used as reference to insert the data previous to it.
 * @param[in] data The data to be inserted.
 * @return 0 if inserting the element is succesful, or -1 otherwise.
 * 
 * Complexity: O(1)
 * 
 */
int dlist_ins_prev(DList *list, DListElmt *element, const void *data);

/**
 * @brief Removes the element specified as element from the doubly-linked list specified by list. 
 * Upon return, data points to the data stored in the element that was removed. It is the
 * responsibility of the caller to manage the storage associated with the data. The complexity is
 * O(1).
 * 
 * @param[in,out] list The doubly-linked list to remove the element.
 * @param[in] element The element to be removed. The exactly element specified is removed, 
 * be careful!
 * @param[in] data A pointer to pointer to data.
 * @return 0 if removing the element is succesful, or -1 otherwise.
 * 
 */ 
int dlist_remove(DList *list, DListElmt *element, void **data);

/**
 * @brief Macro that evaluates to the number of elements in the doubly-linked list specified by 
 * list. The complexity is O(1).
 * 
 * @return Number of elements in the list.
 * 
 */
#define dlist_size(list) ((list)->size)

/**
 * @brief Macro that evaluates to the element at the head of the doubly-linked list specified by 
 * list. The complexity is O(1).
 * 
 * @return Element at the head of the list.
 * 
 */
#define dlist_head(list) ((list)->head)

/**
 * @brief Macro that evaluates to the element at the tail of the doubly-linked list specified by 
 * list. The complexity is O(1).
 * 
 * @return Element at the tail of the list.
 * 
 */
#define dlist_tail(list) ((list)->tail)

/**
 * @brief Macro that determines whether the element specified as element is at the head of a 
 * doubly-linked list. The complexity is O(1).
 * 
 * @return 1 if the element is at the head of the list, or 0 otherwise.
 * 
 */
#define dlist_is_head(element) ((element)->prev == NULL ? 1 : 0)

/**
 * @brief Macro that determines whether the element specifiedas element is at the tail of a 
 * doubly-linked list. The complexity is O(1).
 * 
 * @return 1 if the element is at the tail of the list, or 0 otherwise.
 *
 */
#define dlist_is_tail(element) ((element)->next == NULL ? 1 : 0)

/**
 * @brief Macro that evaluates to the data stored in the element of a doubly-linked list specified 
 * by element. The complexity is O(1).
 * 
 * @return Data stored in the element.
 *
 */
#define dlist_data(element) ((element)->data)

/**
 * @brief Macro that evaluates to the element of a doubly-linked list following the element 
 * specified by element. The complexity is O(1).
 * 
 * @return Element following the specified element.
 * 
 */
#define dlist_next(element) ((element)->next)

/**
 * @brief Macro that evaluates to the element of a doubly-linked list preceding the element 
 * specified by element. The complexity is O(1).
 * 
 * @return Element preceding the specified element.
 * 
 */
#define dlist_prev(element) ((element)->prev)

#endif
