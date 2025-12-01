#include <stdio.h>
#include "queue.h"

typedef struct _node{
    int value;
    struct _node* next;
} node;

struct _queue{   
    node* head;
    node* tail;
    int size;
    int capacity;
};

queue create_queue(int capacity){
    if(capacity <= 0) return NULL;

    queue q = malloc(sizeof(struct _queue));
    if(q == NULL) return NULL;

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    q->capacity = capacity;

    return q;
}

void destroy_queue(queue* _queue){
    if(_queue == NULL || *_queue == NULL) return;

    node* current = (*_queue)->head;

    while(current != NULL){
        node* next = current->next;
        free(current);
        current = next;
    }
    free(*_queue);
    *_queue = NULL;
}

int enqueue(queue _queue, int value){
    if(_queue == NULL) return QUEUE_ERROR_NULL;
    if(_queue->size == _queue->capacity) return QUEUE_ERROR_FULL;

    node* new_node = malloc(sizeof(node));
    if(new_node = NULL) return QUEUE_ERROR_ALLOC;

    new_node->value = value;
    new_node->next = NULL;

    if(_queue->tail == NULL) _queue->head = new_node;
    else _queue->tail->next = new_node;

    _queue->tail = new_node;
    _queue->size++;

    return QUEUE_SUCCESS;
}

int dequeue(queue _queue, int* value_out){
    if(_queue == NULL) return QUEUE_ERROR_NULL;
    if(_queue->head == NULL) return QUEUE_ERROR_EMPTY;

    node* to_remove = _queue->head;
    *value_out = to_remove->value;
    _queue->head = to_remove->next;

    free(to_remove);
    _queue->size--;

    if(_queue->head == NULL) _queue->tail = NULL;
    return QUEUE_SUCCESS;
}

int peek(queue _queue, int* value_out){
    if(_queue == NULL) return QUEUE_ERROR_NULL;
    if(_queue->head == NULL) return QUEUE_ERROR_EMPTY;

    *value_out = _queue->head->value;
    return QUEUE_SUCCESS;
}

bool is_empty(queue _queue){
    return (_queue == NULL || _queue->size == 0);
}

bool is_full(queue _queue){
    if(_queue == NULL) return false;
    return (_queue->size == _queue->capacity);
}
