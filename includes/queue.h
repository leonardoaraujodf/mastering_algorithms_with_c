/* Header for the Queue Abstract Datatype */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include "list.h"

/* Implement queues as linked lists */
typedef List Queue;

/* --------------------- Public Interface ------------------------ */

/*
 * Description: Initializes the queue specified by queue. This
 * operation must be called for a queue before the queue can be used
 * with any other operation. The destroy argument provides a way
 * to free dynamically allocated data when queue_destroy is called.
 * It works in a manner similar to that descrived for stack_destroy.
 * For a queue containing data that should not be freed, destroy
 * should be set to NULL.
 * 
 * Return Value: None.
 * 
 * Complexity: O(1)
 * 
 */
#define queue_init list_init

/*
 * Description: Destroys the queue specified by queue. No other
 * operations are permitted after calling queue_destroy unless
 * queue_init is called again. The queue_destroy operation removes
 * all elements from a queue and calls the function passes as destroy
 * to queue_init once for each element as it is removed, provided
 * destroy was not set to NULL.
 * 
 * Return Value: None.
 * 
 * Complexity: O(n), where n is the number of elements in the queue.
 * 
 */
#define queue_destroy list_destroy

/*
 * Description: Enqueues an element at the tail of the queue specified
 * by queue. The new element contains a pointer to data, so the memory
 * referenced by data should remain valid as long as the element
 * remains in the queue. It is the responsibility of the caller to
 * manage the storage associated with data.
 * 
 * Return Value: 0 if enqueuing the element is succesful, or
 * -1 otherwise.
 * 
 * Complexity: O(1)
 * 
 */
int queue_enqueue(Queue *queue, const void *data);

/*
 * Description: Dequeues an element from the head of the queue 
 * specified by queue. Upon return, data points to the data stored in
 * the element that was dequeued. It is the responsibility of the
 * caller to manage the storage associated with the data.
 * 
 * Return Value: 0 if dequeuing the element is succesful, or
 * -1 otherwise.
 * 
 * Complexity: O(1)
 * 
 */
int queue_dequeue(Queue *queue, void **data);

/*
 * Description: Macro that evaluates to the data stored in the
 * element at the head of the queue specified by queue.
 * 
 * Return Value: Data stored in the element at the head of the queue,
 * or NULL if the queue is empty.
 * 
 * Complexity: O(1)
 * 
 */
#define queue_peek(queue) ((queue)->head == NULL ? NULL : \
    (queue)->head->data)

/*
 * Description: Macro that evaluates to the number of elements in the
 * queue specified by queue.
 * 
 * Return Value: Number of elements in the queue.
 * 
 * Complexity: O(1)
 * 
 */
#define queue_size list_size

#endif