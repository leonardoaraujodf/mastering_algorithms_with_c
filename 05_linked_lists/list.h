/* Header for the Linked List Abstract Datatype */

#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>
#include <stdint.h>

/* Define a structure for linked list elements */

typedef struct ListElmt_
{
   void *data;
   struct ListElmt_ *next;
} ListElmt;

/* Define a structure for linked lists. */

typedef struct List_
{
   uint32_t size;

   int8_t (*match)(const void *key1, const void *key2);
   void (*destroy)(void *data);

   ListElmt *head;
   ListElmt *tail;
   
} List;

/* Public Interface */

/*
 * Description: Initializes the linked list specified by list. This
 * operation must be called for a linked list before the list can be
 * used with any other operation. The destroy argument provides a way
 * to free dynamically allocated data when list_destroy is called.
 * For example, if the list contains data dynamically allocated using
 * malloc, destroy should be set to free to free the data as the
 * linked list is destroyed. For structured data containing several
 * dynamically allocated members, destroy should be set to a
 * user-defined function that calls free for each dynamically
 * allocated member as well as for the structure itself. For a linked
 * list containg data that should not be freed, destroy should be set
 * to NULL.
 *
 * Return Value: None.
 *
 * Complexity: O(1)
 *
 */
void list_init(List *list, void (*destroy)(void *data));

/*
 * Description: Destroys the linked list specified by list. No other
 * operations are permitted after calling list_destroy unless 
 * list_init is called again. The list_destroy operation removes all
 * elements from a linked list and calls the function passed as
 * destroy to list_init once for each element as it is removed,
 * provided destroy was not set to NULL
 *
 * Return Value: None.
 *
 * Complexity: O(n), where n is the number of elements in the linked 
 * list.
 *
 */
void list_destroy(List *list);

/*
 * Description: Inserts an element just after element in the linked
 * list specified by list. If element is NULL, the new element is
 * inserted at the head of the list. The new element contains a
 * pointer to data, so the memory referenced by data should remain
 * valid as long as the element remains in the list. If the
 * responsibility of the caller to manage the storage associated with
 * data.
 *
 * Return Value: 0 if the inserting the element is succesful, or
 * -1 otherwise.
 *
 * Complexity: O(1)
 *
 */
int8_t list_ins_next(List *list, ListElmt *element, const void *data);

/*
 * Description: Removes the element just after element from the
 * linked list specified by list. If element is NULL, the element at
 * the head of the list is removed. Upon return, data points to the 
 * data stored in the element that was removed. It is the
 * responsibility of the caller to manage the storage associated with
 * data.
 *
 * Return Value: 0 if removing the element is succesful, or
 * -1 otherwise.
 *
 * Complexity: O(1)
 *
 */
int8_t list_rem_next(List *list, ListElmt *element, void **data);

/*
 * Description: Macro that evaluates to the number of elements in the
 * linked list specified by list.
 *
 * Return Value: Number of elements in the list.
 *
 * Complexity: O(1)
 *
 */
#define list_size(list) ((list)->size)

/*
 * Description: Macro that determines whether the element specified
 * as element is at the head of a linked list.
 *
 * Return Value: 1 if the element is at the head of the list, or 0
 * otherwise.
 *
 * Complexity: O(1)
 *
 */
#define list_head(list) ((list)->head)

/*
 * Description: Macro that determines whether the element specified
 * as element is at the tail of a linked list.
 *
 * Return Value: 1 if the element at the tail of the list, or 0
 * otherwise.
 *
 * Complexity: O(1)
 *
 */
#define list_tail(list) ((list)->tail)

/*
 * Description: Macro that determines whether the element specified
 * as element is at the head of a linked list.
 *
 * Return Value: 1 if the element is at the head of the list, or 0
 * otherwise.
 *
 * Complexity: O(1)
 *
 */
#define list_is_head(list, element) ((element) == \
   (list)->head ? 1 : 0)

/*
 * Description: Macro that determines whether the element specified
 * as element is at the tail of a linked list.
 *
 * Return Value: 1 if the element is at the tail of the list, or 0
 * otherwise.
 *
 * Complexity: O(1)
 *
 */
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)

/*
 * Description: Macro that evaluates to the data stored in the
 * element of a linked list specified by element.
 *
 * Return Value: Data stored in the element.
 *
 * Complexity: O(1)
 *
 */
#define list_data(element) ((element)->data)

/*
 * Description: Macro that evaluates to the element of a linked list
 * following the element specified by element.
 *
 * Return Value: Element following the specified element.
 *
 * Complexity: O(1)
 *
 */
#define list_next(element) ((element)->next)

#endif
