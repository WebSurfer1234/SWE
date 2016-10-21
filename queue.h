#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
typedef struct stringQueue {
    int len;
    struct element *first;
    struct element *last;
} QUEUE;

typedef struct element {
    char *value;
    struct element *next;
    struct element *previous;
} ELEMENT;


#endif // QUEUE_H_INCLUDED
