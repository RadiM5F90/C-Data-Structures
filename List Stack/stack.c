#include <stdio.h>
#include "stack.h"

/*
 * stack.c
 *
 * Implementation of the stack defined in stack.h
 *
 * The stack is implemented through a linked list, where each node contains
 * an integer value and a pointer to the next node
 *
 * The structure has a reference to the top of the stack, to the max capacity
 * and to the number of current elements
 */

typedef struct _node{
    int value;
    struct _node* next;
} node;

struct _stack {
    node* top;
    int capacity;
    int size;
};

stack stack_create(int _capacity){
    if (_capacity <= 0) return NULL;

    stack s = malloc(sizeof(struct _stack));
    if(s == NULL) return NULL;

    s->top = NULL;
    s->capacity = _capacity;
    s->size = 0;

    return s;
}

void stack_destroy(stack* _stack){
    if(_stack == NULL || *_stack == NULL) return;

    node* current = (*_stack)->top;
    while(current != NULL){
        node* next = current->next;
        free(current);
        current = next;
    }
    free(*_stack);
    *_stack = NULL;
}

int stack_push(stack _stack, int _value){
    if(_stack == NULL) return STACK_ERROR_NULL;
    if(_stack->size == _stack->capacity) return STACK_ERROR_FULL;

    node* new_node = malloc(sizeof(node));
    if(new_node == NULL) return STACK_ERROR_ALLOC;

    new_node->value = _value;
    new_node->next = _stack->top;
    _stack->top = new_node;
    _stack->size++;

    return STACK_SUCCESS;
}

int stack_pop(stack _stack, int* _value_out){
    if(_stack == NULL) return STACK_ERROR_NULL;
    if(_stack->top == NULL) return STACK_ERROR_EMPTY;

    node* to_delete = _stack->top;
    *_value_out = to_delete->value;
    _stack->top = to_delete->next;
    free(to_delete);

    _stack->size--;

    return STACK_SUCCESS;
}

int stack_top(stack _stack, int* _value_out){
    if(_stack == NULL) return STACK_ERROR_NULL;
    if(_stack->top == NULL) return STACK_ERROR_EMPTY;

    *_value_out = _stack->top->value;

    return STACK_SUCCESS;
}

bool stack_is_empty(stack _stack){
    return ((_stack == NULL) || (_stack->size == 0));
}

bool stack_is_full(stack _stack){
    if(_stack == NULL) return false;
    return (_stack->size == _stack->capacity);
}
