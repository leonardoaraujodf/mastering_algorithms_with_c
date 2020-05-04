/* Header for Handling Events */

#ifndef EVENT_H
#define EVENT_H

#include "queue.h"

typedef enum Priority_ {
    Low_priority,
    Medium_priority,
    High_priority
} Priority;


typedef struct Event_{
    char event_name[50];
    Priority event_priority;
} Event;

int receive_event(Queue *events, const Event *event);

int process_event(Queue *events, int (*dispatch)(Event *event));

#endif