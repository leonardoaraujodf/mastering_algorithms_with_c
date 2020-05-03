/* Header for the Stack Abstract Datatype */

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "list.h"

/* Implement stacks as linked lists. */
typedef List Stack;

/* --------------------- Public Interface ------------------------ */

/*
 * Description: Initializes the stack specified by stack. This
 * operation must be called for a stack before the stack can be used
 * with any other operation. The destroy argument provides a way to
 * free dynamically allocated data when stack_destroy is called.
 * For example, if the stack contains data dynamically allocated
 * using malloc, destroy should be set to free to free the data as
 * the stack is destroyed. For structured data containing several
 * dynamically allocated members, destroy should be set to a
 * user-defined function that calls free for each dynamically 
 * allocated member as well as for the structure itself. For a stack
 * containing data that should not be freed, destroy should be set
 * to NULL.
 * 
 * Return Value: None.
 * 
 * Complexity: O(1)
 * 
 */
#define stack_init list_init

/*
 * Description: Destroys the stack specified by stack. No other 
 * operations are permitted after calling stack_destroy unless
 * stack_init is called again. The stack_destroy operation removes
 * all elements from a stack and calls the function passed as destroy
 * to stack_init once for each element as it is removed, provided
 * destroy was not set to NULL.
 * 
 * Return Value: None.
 * 
 * Complexity: O(n)
 * 
 */
#define stack_destroy list_destroy

/*
 * Description: Pushes an element onto the stack specified by stack.
 * The new element contains a pointer to data, so the memory 
 * referenced by data should remain valid as long as the element
 * remains in the stack. It is the responsibility of the caller to
 * manage the storage associated with data.
 * 
 * Return Value: 0 if pushing the element is succesful, or -1
 * otherwise.
 * 
 * Complexity: O(1)
 * 
 */
int stack_push(Stack *stack, const void *data);

/*
 * Description: Pops an element off the stack specified by stack.
 * Upon return, data points to the data stored in the element that
 * was popped. It is the responsibility of the caller to manage the
 * storage associated with the data.
 * 
 * Return Value: 0 if pushing the element is succesful, or -1
 * otherwise.
 * 
 * Complexity: O(1)
 * 
 */
int stack_pop(Stack *stack, void **data);

/*
 * Description: Macro that evaluates to the data stored in the
 * element at the top of the stack specified by stack
 * 
 * Return Value: Data stored in the element at the top of the stack,
 * or NULL if the stack is empty
 * 
 * Complexity: O(1)
 * 
 */
#define stack_peek(stack) ((stack)->head == NULL ? \
    NULL : (stack)->head->data)

/*
 * Description: Macro that evaluates to the number of elements in the
 * stack specified by stack.
 * 
 * Return Value: Number of elements in the stack.
 * 
 * Complexity: O(1)
 * 
 */
#define stack_size list_size

#endif
