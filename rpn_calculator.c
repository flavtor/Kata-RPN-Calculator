#include "rpn_calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

static int stack[MAX_STACK_SIZE];
static int stack_top = -1;

void push(int value) {
    if (stack_top < MAX_STACK_SIZE - 1) {
        stack[++stack_top] = value;
    } else {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

int pop() {
    if (stack_top >= 0) {
        return stack[stack_top--];
    } else {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

void evaluate_rpn(const char* expression) {
    char token[10];
    int i = 0, j = 0;
    while (expression[i] != '\0') {
        if (isspace(expression[i])) {
            i++;
            continue;
        }
        
        if (isdigit(expression[i]) || (expression[i] == '-' && isdigit(expression[i+1]))) {
            j = 0;
            while (!isspace(expression[i]) && expression[i] != '\0') {
                token[j++] = expression[i++];
            }
            token[j] = '\0';
            push(atoi(token));
        } else {
            int b = pop();
            int a = pop();
            switch (expression[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                default:
                    fprintf(stderr, "Unknown operator: %c\n", expression[i]);
                    exit(EXIT_FAILURE);
            }
            i++;
        }
    }
    printf("Result: %d\n", pop());
}
