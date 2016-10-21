#ifndef NUMERICSTACK_H_INCLUDED
#define NUMERICSTACK_H_INCLUDED
typedef struct stack_element {
    char * value;
    struct stack_element *next;
} STACK_ELEMENT;

typedef struct stack {
    int len;
    STACK_ELEMENT *last;
} STACK;
#endif // NUMERICSTACK_H_INCLUDED
