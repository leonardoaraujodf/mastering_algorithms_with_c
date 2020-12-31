/* Header for the Circular List Abstract Datatype */

#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>

/* Define a structure for circular list elements. */
typedef struct CListElmt_
{
    void *data;
    struct CListElmt_ *next;
} CListElmt;

/* Define a structure for circular lists */
typedef struct CList_
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    CListElmt *head;
} CList;

/* --------------------- Public Interface ------------------------ */

/*
 * Description: Initializes the circular list specified by list. This
 * operation must be called for a circular list before the list can
 * be used with any other operation. The destroy argument provides a 
 * way to free dynamically allocated data when clist_destroy is 
 * called. It works in a manner similar to that described for
 * list_destroy. For a circular list containing data that should not
 * be freed, destroy should be set to NULL.
 * 
 * Return Value: None.
 * 
 * Complexity: O(1)
 * 
 */
void clist_init(CList *list, void (*destroy)(void *data));

/*
 * Description: Destroys the circular list specified by list. No
 * other operations are permitted after calling clist_destroy unless
 * clist_init is called again. The clist_destroy operation removes all
 * elements from a circular list and calls the function passed as
 * destroy to clist_init once for each element as it is removed,
 * provided destroy was not set to NULL.
 * 
 * Return Value: None.
 * 
 * Complexity: O(n), where n is the number of elements in the circular
 * list.
 * 
 */
void clist_destroy(CList *list);

/*
 * Description: Inserts an element just after element in the circular
 * list specified by list. When inserting into an empty list, element
 * may point anywhere but should be NULL to avoid confusion. The new
 * element contains a pointer to data, so the memory refereced by 
 * data should remain valid as long as the element remains in the 
 * list. It is the responsibility of the caller to manage the storage
 * associated with data.
 * 
 * Return Value: 0 if inserting the element is succesful, or -1
 * otherwise.
 * 
 * Complexity: O(1)
 * 
 */
int clist_ins_next(CList *list, CListElmt *element, const void *data);

/*
 * Description: Removes the element just after element from the 
 * circular list specified by list. Upon return, data points to the
 * data stored in the element that was removed. It is the 
 * responsibility of the caller to manage the storage associated with
 * the data.
 * 
 * Return Value: 0 if removing the element is succesful, or -1
 * otherwise.
 * 
 * Complexity: O(1)
 * 
 */
int clist_rem_next(CList *list, CListElmt *element, void **data);

/*
 * Description: Macro that evaluates to the number of elements in the
 * circular list specified by list.
 * 
 * Return Value: Number of elements in the list.
 * 
 * Complexity: O(1)
 * 
 */
#define clist_size(list) ((list)->size)

/*
 * Description: Macro that evaluates at the head of the circular list
 * specified by list.
 * 
 * Return Value: Element at the head of the list.
 * 
 * Complexity: O(1)
 * 
 */
#define clist_head(list) ((list)->head)

/*
 * Description: Macro that evaluates to the data stored in the element
 * of a circular list specified by element.
 * 
 * Return Value: Data stored in the element.
 * 
 * Complexity: O(1)
 * 
 */
#define clist_data(list) ((element)->data)

/*
 * Description: Macro that evaluates to the element of a circular
 * list following the element specified by element.
 * 
 * Return Value: Element following the specified element.
 * 
 * Complexity: O(1)
 * 
 */
#define clist_next(element) ((element)->next)

#endif
