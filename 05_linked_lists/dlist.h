/* Header for the Doubly-Linked list Abstract Datatype */
#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

/* Define a structure for doubly-linked list elements. */
typedef struct DListElmt_
{
    void *data;
    struct DListElmt_ *prev;
    struct DListElmt_ *next;
} DListElmt;

/* Define a structure for doubly-linked lists */
typedef struct DList_ 
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    DListElmt *head;
    DListElmt *tail;
} DList;

/* --------------------- Public Interface ------------------------ */

/*
 * Description: Initializes the doubly-linked list specified by list.
 * This operation must be called for a doubly-linked list before the
 * list can be used with any other operation. The destroy argument
 * provides a way to free dinamically allocated data when 
 * dlist_destroy is called. It works in a manner similitar to that
 * described for list_destroy. For a doubly-linked list containing
 * data that should not be freed, destroy should be set to NULL.
 * 
 * Return Value: None.
 * 
 * Complexity: O(1)
 * 
 */ 
void dlist_init(DList *list, void (*destroy)(void *data));


/*
 * Description: Destroys the doubly-linked list specified by list. No
 * other operations are permitted after calling dlist_destroy unless
 * dlist_init is called again. The dlist_destroy operation removes
 * all elements from a doubly-linked list and calls the function
 * passed as destroy to dlist_init once for each element as it is
 * removed, provided destroy was not set to NULL.
 * 
 * Return Value: None.
 * 
 * Complexity: O(n), where n is the number of elements in the
 * doubly-linked list.
 * 
 */
void dlist_destroy(DList *list);

/*
 * Description: Inserts an element just after element in the 
 * doubly-linked list specified by list. When inserting into an empty
 * list, element may point anywhere, but should be NULL to avoid
 * confusion. The new element contains a pointer to data, so the
 * memory referenced by data should remain valid as long as the
 * element remains in the list. It is the responsibility of the
 * caller to manage the storage associated with data.
 * 
 * Return Value: 0 if inserting the element is succesful, or -1
 * otherwise.
 * 
 * Complexity: O(1)
 * 
 */
int dlist_ins_next(DList *list, DListElmt *element, const void *data);

/*
 * Description: Inserts an element just before element in the
 * doubly-linked list specified by list. When inserting into an empty
 * list, element may point anywhere, but should be NULL to avoid 
 * confusion. The new element contains a pointer to data, so the
 * memory referenced by data should remain valid as long as the
 * element remains in the list. It is the responsibility of the
 * caller to manage the storage associated with data.
 * 
 * Return Value: 0 if inserting the element is succesful, or -1
 * otherwise.
 * 
 * Complexity: O(1)
 * 
 */
int dlist_ins_prev(DList *list, DListElmt *element, const void *data);

/*
 * Description: Removes the element specified as element from the
 * doubly-linked list specified by list. Upon return, data points to
 * the data stored in the element that was removed. It is the
 * responsibility of the caller to manage the storage associated
 * with the data.
 * 
 * Return Value: 0 if removing the element is succesful, or -1
 * otherwise.
 * 
 * Complexity: O(1)
 * 
 */ 
int dlist_remove(DList *list, DListElmt *element, void **data);

/*
 * Description: Macro that evaluates to the number of elements in the
 * doubly-linked list specified by list.
 * 
 * Return Value: Number of elements in the list.
 * 
 * Complexity: O(1)
 * 
 */
#define dlist_size(list) ((list)->size)

/*
 * Description: Macro that evaluates to the element at the head of
 * the doubly-linked list specified by list.
 * 
 * Return Value: Element at the head of the list.
 * 
 * Complexity: O(1)
 * 
 */
#define dlist_head(list) ((list)->head)

/*
 * Description: Macro that evaluates to the element at the tail of
 * the doubly-linked list specified by list.
 * 
 * Return Value: Element at the tail of the list.
 * 
 * Complexity: O(1)
 * 
 */
#define dlist_tail(list) ((list)->tail)

/*
 * Description: Macro that determines whether the element specified
 * as element is at the head of a doubly-linked list.
 * 
 * Return Value: 1 if the element is at the head of the list, or 0
 * otherwise.
 * 
 * Complexity: O(1)
 * 
 */
#define dlist_is_head(element) ((element)->prev == NULL ? 1 : 0)

/*
 * Description: Macro that determines whether the element specified
 * as element is at the tail of a doubly-linked list.
 * 
 * Return Value: 1 if the element is at the tail of the list, or 0
 * otherwise.
 * 
 * Complexity: O(1)
 * 
 */
#define dlist_is_tail(element) ((element)->next == NULL ? 1 : 0)

/*
 * Description: Macro that evaluates to the data stored in the
 * element of a doubly-linked list specified by element.
 * 
 * Return Value: Data stored in the element.
 * 
 * Complexity: O(1)
 * 
 */
#define dlist_data(element) ((element)->data)

/*
 * Description: Macro that evaluates to the element of a
 * doubly-linked list following the element specified by element.
 * 
 * Return Value: Element following the specified element.
 * 
 * Complexity: O(1)
 * 
 */
#define dlist_next(element) ((element)->next)

/*
 * Description: Macro that evaluates to the element of a
 * doubly-linked list preceding the element specified by element.
 * 
 * Return Value: Element preceding the specified element.
 * 
 * Complexity: O(1)
 * 
 */
#define dlist_prev(element) ((element)->prev)

#endif
