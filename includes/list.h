/**
 * @file list.h
 * @author Kyle Loudon
 * @date 8 May 2020
 * @brief Header for the Linked List Abstract Datatype
 */

#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>
#include <stdint.h>

/**
 * @brief A structure for linked list elements.
 */
typedef struct ListElmt_
{
   void *data; /*!< A pointer to the data stored in element. */
   struct ListElmt_ *next; /*!< A pointer to the next element of the same type. */
} ListElmt;

/** 
 * @brief A structure for linked lists.
 */
typedef struct List_
{
   int size; /*!< The actual size of the linked list. */

   int (*match)(const void *key1, const void *key2); /*!< A match function pointer used mostly by 
   other ADT for matching two elements based in a function given by the user. */
   void (*destroy)(void *data); /*!< The destroy function given by the user to be used in 
   #list_destroy*/

   ListElmt *head; /*!< The head element of the list, of the first element. */
   ListElmt *tail; /*!< The final element of the list, the last element or the tail element. */
   
} List;

/* Public Interface */

/**
 * @brief Initializes the linked list specified by list. 
 * 
 * This operation must be called for a linked list before the list can be used with any other 
 * operation. The destroy argument provides a way to free dynamically allocated data when 
 * list_destroy is called. For example, if the list contains data dynamically allocated using 
 * malloc, destroy should be set to free to free the data as the linked list is destroyed. For 
 * structured data containing several dynamically allocated members, destroy should be set to a 
 * user-defined function that calls free for each dynamically allocated member as well as for the 
 * structure itself. For a linked list containg data that should not be freed, destroy should be set
 * to NULL.
 *
 * @param[in,out] list The linked list to be initialized
 * @param[in] destroy A pointer to the destroy user function to be used by #list_destroy
 * @return None.
 *
 */
void list_init(List *list, void (*destroy)(void *data));

/**
 * @brief Destroys the linked list specified by list. 
 * 
 * No other operations are permitted after calling list_destroy unless list_init is called again. 
 * The list_destroy operation removes all elements from a linked list and calls the function passed 
 * as destroy to list_init once for each element as it is removed, provided destroy was not set to 
 * NULL.
 *
 * @param[in,out] list The linked list to be destroyed
 * @return None.
 *
 */
void list_destroy(List *list);

/**
 * @brief Inserts an element just after element in the linked list specified by list. 
 * 
 * If element is NULL, the new element is inserted at the head of the list. The new element contains
 * a pointer to data, so the memory referenced by data should remain valid as long as the element 
 * remains in the list. If the responsibility of the caller to manage the storage associated with
 * data. The complexity is O(1).
 * 
 * @param[in,out] list The list to insert the new element.
 * @param[in] element A element used as reference to insert the data next to it.
 * @param[in] data The data to be inserted.
 * @return 0 if the inserting the element is succesful, or -1 otherwise.
 *
 */
int list_ins_next(List *list, ListElmt *element, const void *data);

/**
 * @brief Removes the element just after element from the linked list specified by list. 
 * 
 * If element is NULL, the element at the head of the list is removed. Upon return, data points to 
 * the data stored in the element that was removed. It is the responsibility of the caller to manage
 * the storage associated with data. The complexity is O(1).
 * 
 * @param[in,out] list The list to remove the element.
 * @param[in] element A element used as reference to delete the data next to it.
 * @return 0 if removing the element is succesful, or -1 otherwise.
 *
 */
int list_rem_next(List *list, ListElmt *element, void **data);

/**
 * @brief Macro that evaluates to the number of elements in the linked list specified by list.
 * 
 * The complexity is O(1).
 * 
 * @return Number of elements in the list.
 */
#define list_size(list) ((list)->size)

/**
 * @brief Macro that determines whether the element specified as element is at the head of a linked 
 * list.
 * 
 * The complexity is O(1).
 *
 * @return 1 if the element is at the head of the list, or 0 otherwise.
 *
 */
#define list_head(list) ((list)->head)

/**
 * @brief Macro that determines whether the element specified as element is at the tail of a linked 
 * list.
 * 
 * The complexity is O(1).
 * 
 * @return 1 if the element at the tail of the list, or 0 otherwise.
 *
 */
#define list_tail(list) ((list)->tail)

/**
 * @brief Macro that determines whether the element specified as element is at the head of a linked 
 * list.
 * 
 * The complexity is O(1).
 *
 * @return 1 if the element is at the head of the list, or 0 otherwise.
 *
 */
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)

/**
 * @brief Macro that determines whether the element specified as element is at the tail of a linked 
 * list.
 * 
 * The complexity is O(1).
 *
 * @return 1 if the element is at the tail of the list, or 0 otherwise.
 *
 */
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)

/**
 * @brief Macro that evaluates to the data stored in the element of a linked list specified by 
 * element.
 * 
 * The complexity is O(1).
 * 
 * @return Data stored in the element.
 *
 */
#define list_data(element) ((element)->data)

/**
 * @brief Macro that evaluates to the element of a linked list following the element specified by 
 * element.
 * 
 * The complexity is O(1).
 *
 * @return Element following the specified element.
 *
 */
#define list_next(element) ((element)->next)

#endif
