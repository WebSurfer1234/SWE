#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
typedef struct numeric_stack_element {
    double value;
    struct numeric_stack_element *next;
} NUMERIC_STACK_ELEMENT;

typedef struct numeric_stack {
    int len;
    NUMERIC_STACK_ELEMENT *last;
} NUMERIC_STACK;
#endif // STACK_H_INCLUDED
