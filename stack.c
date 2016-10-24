/**
 * file: RectAU.c
 *
 * date: 2016-10-24
 * progtimeest.: 10 min
 * progtimereal: 9 min
 * author: David Seidl
 * email: dseidl.its-b2016@fh-salzburg.ac.at
 *
 * Salzburg University of Applied Sciences
 * Information Technology & Systems Management
 * SWE1-ILV/B, exercise 1
 *
 */
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int push(STACK * stack, char * value) {
    STACK_ELEMENT *newElement = malloc(sizeof(STACK_ELEMENT));

    newElement->value = value;
    if(stack->len == 0) {
        stack->last = newElement;
    } else {
        STACK_ELEMENT *last = stack->last;
        newElement->next = last;
        stack->last = newElement;
    }
    stack->len++;
}

char * pop(STACK *stack) {
    if(stack->len != 0) {
        char * value;
        if(stack->len == 1) {
            STACK_ELEMENT *only = stack->last;
            stack->last = NULL;
            value = only->value;
            free(only);
        } else {
            STACK_ELEMENT *last = stack->last;
            STACK_ELEMENT *newLast = last->next;
            stack->last = newLast;
            value = last->value;
            free(last);
        }
        stack->len--;
        return value;
    } else {
        return NULL;
    }
}

char * top(STACK *stack) {
    if(stack->len != 0) {
        return stack->last->value;
    } else {
        return NULL;
    }
}
