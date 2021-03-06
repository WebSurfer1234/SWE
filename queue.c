/**
 * file: queue.c
 *
 * date: 2016-10-24
 * progtimeest.: 60 min
 * progtimereal: 30 min
 * author: David Seidl
 * email: dseidl.its-b2016@fh-salzburg.ac.at
 *
 * Salzburg University of Applied Sciences
 * Information Technology & Systems Management
 * SWE1-ILV/B, exercise 1
 *
 */
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
int enqueue(QUEUE *queue, char *value) {
    ELEMENT *newElement = malloc(sizeof(ELEMENT));
    newElement->value = value;
    if(queue->len == 0) {
        queue->first = newElement;
        queue->last = newElement;
    } else {
        ELEMENT *last = queue->last;
        last->next = newElement;
        queue->last = newElement;
    }
    queue->len++;
    return 0;
}

char * dequeue(QUEUE *queue) {
    if(queue->len != 0) {
        char *value;
        if(queue->len == 1) {
            ELEMENT *only = queue->first;
            queue->first = NULL;
            queue->last = NULL;
            value = only->value;
            free(only);
        } else {
            ELEMENT *first = queue->first;
            ELEMENT *newFirst = first->next;
            queue->first = newFirst;
            value = first->value;
            free(first);
        }
        queue->len--;
        return value;
    } else {
        return NULL;
    }
}

char * first(QUEUE *queue) {
    if(queue->len != 0) {
        return queue->first->value;
    } else {
        return NULL;
    }
}

int size(QUEUE *queue) {
    return queue->len;
}
