#include "numericStack.h"
#include <stdio.h>
#include <stdlib.h>

int npush(NUMERIC_STACK * stack, double value) {
    NUMERIC_STACK_ELEMENT *newElement = malloc(sizeof(NUMERIC_STACK_ELEMENT));

    newElement->value = value;
    if(stack->len == 0) {
        stack->last = newElement;
    } else {
        NUMERIC_STACK_ELEMENT *last = stack->last;
        newElement->next = last;
        stack->last = newElement;
    }
    stack->len++;
}

double npop(NUMERIC_STACK *stack) {
    if(stack->len != 0) {
        double value;
        if(stack->len == 1) {
            NUMERIC_STACK_ELEMENT *only = stack->last;
            stack->last = NULL;
            value = only->value;
            free(only);
        } else {
            NUMERIC_STACK_ELEMENT *last = stack->last;
            NUMERIC_STACK_ELEMENT *newLast = last->next;
            stack->last = newLast;
            value = last->value;
            free(last);
        }
        stack->len--;
        return value;
    } else {
        return 0.0;
    }
}

double ntop(NUMERIC_STACK *stack) {
    if(stack->len != 0) {
        return stack->last->value;
    } else {
        return 0.0;
    }
}
