#include <stdio.h>
#include "stack.h"
#include "stack.c"


int main(void) {
    stack s = stack_create(5);

    if(s == NULL){
        printf("There was an error with the stack creation\n");
        return 1;
    }

    // inserting elements
    for (int i = 1; i <= 5; i++) {
        if (stack_push(s, i * 10) == STACK_SUCCESS) {
            printf("Pushed: %d\n", i * 10);
        } else {
            printf("Error: the stack is full\n");
        }
    }

    // checking the element at the top of the stack
    int top_value;
    if (stack_top(s, &top_value) == STACK_SUCCESS) {
        printf("\nValue at the top: %d\n", top_value);
    }

    // removing all the elements
    while (!stack_is_empty(s)) {
        int popped;
        if (stack_pop(s, &popped) == STACK_SUCCESS) {
            printf("Removed: %d\n", popped);
        } else {
            printf("Removing Error\n");
        }
    }

    // checking if the stack is empty
    if (stack_is_empty(s)) {
        printf("\nStack is empty.\n");
    }

    // destroying the stack
    stack_destroy(&s);
    if (s == NULL) {
        printf("\nStack successfully deallocated.\n");
    }

    return 0;
}

