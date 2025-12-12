#include <stdio.h>
#include "stack.h"

/*
 * stack.c
 *
 * Implementation of the stack defined in stack.h
 *
 * The stack is implemented through a dynamically allocated array,
 * a variable for its max capacity and a counter for current elements
 *
 * All the functions return error codes, and check NULL pointers
 * The memory is managed in an explicit and safe way
 */

struct _stack {
    int* data;
    int capacity;
    int size;
};

stack stack_create(int _capacity){
    if (_capacity <= 0) return NULL;

    stack s = malloc(sizeof(struct _stack));
    if(s == NULL) return NULL;

    s->data = malloc(sizeof(int) * _capacity);
    if(s->data == NULL){
        free(s);
        return NULL;
    }
    s->capacity = _capacity;
    s->size = 0;
    return s;
}

void stack_destroy(stack* _stack){
    if(_stack == NULL || *_stack == NULL) return;
    free((*_stack)->data);
    free(*_stack);
    *_stack = NULL;
}

int stack_push(stack _stack, int _value){
    if(_stack == NULL) return STACK_ERROR_NULL;
    if(_stack->size == _stack->capacity) return STACK_ERROR_FULL;

    _stack->data[_stack->size++] = _value;
    return STACK_SUCCESS;
}

int stack_pop(stack _stack, int* _value_out){
    if(_stack == NULL) return STACK_ERROR_NULL;
    if(_stack->size == 0) return STACK_ERROR_EMPTY;

    *_value_out = _stack->data[_stack->size - 1];
    _stack->size--;
    return STACK_SUCCESS;
}

int stack_top(stack _stack, int* _value_out){
    if(_stack == NULL) return STACK_ERROR_NULL;
    if(_stack->size == 0) return STACK_ERROR_EMPTY;

    *_value_out = _stack->data[_stack->size - 1];
    return STACK_SUCCESS;
}

bool stack_is_empty(stack _stack){
    return ((_stack == NULL) || (_stack->size == 0));
}

bool stack_is_full(stack _stack){
    if(_stack == NULL) return false;
    return (_stack->size == _stack->capacity);
}
