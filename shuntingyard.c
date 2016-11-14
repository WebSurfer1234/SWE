/**
 * file: main.c
 *
 * date: 2016-10-24
 * progtimeest.: 180 min
 * progtimereal: 300 min
 * author: David Seidl
 * email: dseidl.its-b2016@fh-salzburg.ac.at
 *
 * Salzburg University of Applied Sciences
 * Information Technology & Systems Management
 * SWE1-ILV/B, exercise 1
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"
#include "stack.h"
#include "stack.c"
#include "numericStack.h"
#include "numericStack.c"
#include <math.h>
#define BUF 255
char* readLine() {
    char *input, buffer[BUF];
    fgets(buffer, BUF, stdin);
    if(!strstr(buffer, "\n")) {
        input = malloc((BUF) * sizeof(char));
        strcpy(input, buffer);
        size_t size = BUF;
        while(1) {
            fgets(buffer, BUF, stdin);
            if(strstr(buffer, "\n") != NULL) {
                int i = strcspn (buffer, "\n");
                size = size + i;
                input = realloc(input, size);
                strncat(input, buffer, i);
                input[size - 1] = '\0';
                break;
            } else {
                size = size + BUF - 1;
                input = realloc(input, size * sizeof(char));
                strcat(input, buffer);
            }
        }
    } else {
        int i = strcspn (buffer, "\n");
        input = malloc((i + 1) * sizeof(char));
        strncpy(input, buffer, i);
        input[i] = '\0';
    }
    return input;
}

bool isNumeric(char * value) {
    int i = 0;
    int size = strlen(value);
    bool hasComma = false;
    for(i; i < size; i++) {
        switch(value[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                break;
            case '.':
                if(hasComma) {
                    //not Numeric ERROR
                    return NULL;
                } else {
                    hasComma = true;
                }
                break;
            case '+':
            case '-':
                if(!(i == 0 && size > 1)) {
                    return false;
                }
                break;
            default:
                return false;
        }
    }
    return true;
}

int getOpportunity(char * operatorElement) {
    if(strcmp(operatorElement, "+") == 0 || strcmp(operatorElement, "-") == 0) {
        return 0;
    } else if(strcmp(operatorElement, "*") == 0 || strcmp(operatorElement, "/") == 0 || strcmp(operatorElement, "sin") == 0 || strcmp(operatorElement, "cos") == 0 ||
              strcmp(operatorElement, "tan") == 0 || strcmp(operatorElement, "asin") == 0 || strcmp(operatorElement, "acos") == 0 || strcmp(operatorElement, "atan") == 0) {
        return 1;
    } else if(strcmp(operatorElement, "^") == 0) {
        return 2;
    } else if(strcmp(operatorElement, "(") == 0) {
        return 10; //sicherheitshalber
    } else {
        //unknown Operator
        return NULL;
    }
}

QUEUE * getInfix(char * calculation) {
    int i = 0;
    bool readNumber = false;
    bool readOperator = false;
    bool nextOperatorCanBelongToNumber = true;
    bool addAfterFor = true;
    char *term = NULL;
    QUEUE *inputQueue = malloc(sizeof(QUEUE));
    inputQueue->len = 0;
    for(i; i < strlen(calculation); i++) {
        switch(calculation[i]) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.':
            addAfterFor = true;
            nextOperatorCanBelongToNumber = false;
            if(!readNumber) {
                if(readOperator) {
                    //operator wurde gelesen
                    enqueue(inputQueue, term);
                    readOperator = false;
                }
                //Achtung bei . als erstes Zeichn nicht sicher ob es funktioniert
                readNumber = true;
                term = malloc(2 * sizeof(char));
                term[0] = calculation[i];
                term[1] = '\0';
            } else {
                int size = strlen(term);
                term = realloc(term, (size + 2) * sizeof(char));
                term[size] = calculation[i];
                term[size + 1] = '\0';
            }
            break;
        case '+':
        case '-':
            if(nextOperatorCanBelongToNumber) {
                addAfterFor = true;
                nextOperatorCanBelongToNumber = false;
                if(readOperator) {
                    //operator wurde gelesen
                    enqueue(inputQueue, term);
                    readOperator = false;
                }
                readNumber = true;
                term = malloc(2 * sizeof(char));
                term[0] = calculation[i];
                term[1] = '\0';
            } else {
            addAfterFor = false;
            if(readOperator || readNumber) {
                enqueue(inputQueue, term);
                readNumber = false;
                readOperator = false;
            }
            term = malloc(2 * sizeof(char));
            term[0] = calculation[i];
            term[1] = '\0';
            enqueue(inputQueue, term);
            }
            break;
        case '(':
        case ')':
        case '*':
        case '/':
        case '^':
            addAfterFor = false;
            if(calculation[i] == ')') {
                nextOperatorCanBelongToNumber = false;
            } else {
                nextOperatorCanBelongToNumber = true;
            }
            if(readOperator || readNumber) {
                enqueue(inputQueue, term);
                readNumber = false;
                readOperator = false;
            }
            term = malloc(2 * sizeof(char));
            term[0] = calculation[i];
            term[1] = '\0';
            enqueue(inputQueue, term);
            break;
        default:
            addAfterFor = true;
            nextOperatorCanBelongToNumber = true;
            if(!readOperator) {
                if(readNumber) {
                    enqueue(inputQueue, term);
                    readNumber = false;
                }
                readOperator = true;
                term = malloc(2 * sizeof(char));
                term[0] = calculation[i];
                term[1] = '\0';
            } else {
                int size = strlen(term);
                term = realloc(term, (size + 2) * sizeof(char));
                term[size] = calculation[i];
                term[size + 1] = '\0';
            }
            break;
        }
    }
    if(addAfterFor) {
        enqueue(inputQueue, term);
    }
    return inputQueue;
}

QUEUE * shuntingYard(QUEUE * infixNotation) {
    QUEUE * postfixNotation = malloc(sizeof(QUEUE));
    postfixNotation->len = 0;
    STACK * operatorStack = malloc(sizeof(STACK));
    operatorStack->len = 0;
    char * currentElement = NULL;
    while(infixNotation->len > 0) {
        currentElement = dequeue(infixNotation);
        if(isNumeric(currentElement)) {
            enqueue(postfixNotation, currentElement);
        } else if(strcmp(currentElement, "pi") == 0) {
            currentElement = realloc(currentElement, 23 * sizeof(char));
            strcpy(currentElement, "3.14159265358979323846");
            enqueue(postfixNotation, currentElement);
        } else if(strcmp(currentElement, ")") == 0) {
            while(strcmp(top(operatorStack), "(") != 0 && operatorStack->len > 0) {
                enqueue(postfixNotation, pop(operatorStack));
            }
            free(pop(operatorStack));
            free(currentElement);
        } else {
            if(operatorStack->len == 0) {
                push(operatorStack, currentElement);
            } else {
                int opportunity = getOpportunity(currentElement);
                int stackTopOpportunity = getOpportunity(top(operatorStack));
                while(opportunity <= stackTopOpportunity && strcasecmp(top(operatorStack), "(") != 0) {
                    enqueue(postfixNotation, pop(operatorStack));
                    if(operatorStack->len == 0) {
                        break;
                    } else {
                        stackTopOpportunity = getOpportunity(top(operatorStack));
                    }
                }
                push(operatorStack, currentElement);
            }
        }
    }
    while(operatorStack->len > 0) {
        enqueue(postfixNotation, pop(operatorStack));
    }
    free(operatorStack);
    return postfixNotation;
}

double solvePostFix(QUEUE * postfixQueue) {
    NUMERIC_STACK * numStack = malloc(sizeof(NUMERIC_STACK));
    numStack->len = 0;
    while(postfixQueue->len > 0) {
        char * currentElement = dequeue(postfixQueue);
        if(isNumeric(currentElement)) {
            npush(numStack, atof(currentElement)); //geht evtln nicht weil wert keinen reservierten Speicher hat
        } else {
            if(strcmp(currentElement, "+") == 0) {
                double val1 = npop(numStack);
                double val2 = npop(numStack);
                double res = val1 + val2;
                npush(numStack, res);
            } else if(strcmp(currentElement, "-") == 0) {
                double val2 = npop(numStack);
                double val1 = npop(numStack);
                double res = val1 - val2;
                npush(numStack, res);
            } else if(strcmp(currentElement, "*") == 0) {
                double val1 = npop(numStack);
                double val2 = npop(numStack);
                double res = val1 * val2;
                npush(numStack, res);
            } else if(strcmp(currentElement, "/") == 0) {
                double val2 = npop(numStack);
                double val1 = npop(numStack);
                double res = val1 / val2;
                npush(numStack, res);
            } else if(strcmp(currentElement, "^") == 0) {
                double val2 = npop(numStack);
                double val1 = npop(numStack);
                double res = pow(val1, val2);
                npush(numStack, res);
            } else if(strcmp(currentElement, "sin") == 0) {
                double val = npop(numStack);
                double res = sin(val);
                npush(numStack, res);
            } else if(strcmp(currentElement, "cos") == 0) {
                double val = npop(numStack);
                double res = cos(val);
                npush(numStack, res);
            } else if(strcmp(currentElement, "tan") == 0) {
                double val = npop(numStack);
                double res = tan(val);
                npush(numStack, res);
            } else if(strcmp(currentElement, "asin") == 0) {
                double val = npop(numStack);
                double res = asin(val);
                npush(numStack, res);
            } else if(strcmp(currentElement, "acos") == 0) {
                double val = npop(numStack);
                double res = acos(val);
                npush(numStack, res);
            } else if(strcmp(currentElement, "atan") == 0) {
                double val = npop(numStack);
                double res = atan(val);
                npush(numStack, res);
            }
        }
        free(currentElement);
    }
    double result = npop(numStack);
    free(numStack);
    return result;
}

int main()
{
    printf("Bitte geben Sie eine Rechnung ein: ");
    char* calculation = readLine();
    QUEUE * inputQueue = getInfix(calculation);
    free(calculation);
    QUEUE * postfixQueue = shuntingYard(inputQueue);
    /*while(postfixQueue->len > 0) {
        printf("%s, ", dequeue(postfixQueue));
    }*/
    free(inputQueue);
    double result = solvePostFix(postfixQueue);
    free(postfixQueue);
    printf("%f", result);
    return 0;
}
