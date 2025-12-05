#include <stdio.h>
#include "queue.h"

/*
 * Implementation of the queue defined in queue.h
 *
 * The queue is implemented through a dynamically allocated circular array,
 * with explicit management of head and tail indexes, and a variable for the current size.
 * The max capacity of the array is set when it's created.
 * */


struct _queue{
    int* data;
    int capacity;
    int size;
    int head;
    int tail;
};

queue queue_create(int _capacity){
    if(_capacity == 0) return NULL;

    queue q = malloc(sizeof(struct _queue));
    if(q == NULL) return NULL;

    q->data = malloc(sizeof(int) * _capacity);
    if(q->data == NULL){
        free(q);
        return NULL;
    }
    q->capacity = _capacity;
    q->size = 0;
    q->head = q->tail = 0;

    return q;
}

void queue_destroy(queue* _queue){
    if(_queue == NULL || *_queue == NULL) return;

    free((*_queue)->data);
    free(*_queue);
    *_queue = NULL;
}

int queue_enqueue(queue _queue, int value){
    if(_queue == NULL) return QUEUE_ERROR_NULL;
    if(_queue->size == _queue->capacity) return QUEUE_ERROR_FULL;

    _queue->data[_queue->tail] = value; 
    _queue->tail = (_queue->tail + 1) % _queue->capacity;
    _queue->size++; 
    
    return QUEUE_SUCCESS; 
}

int queue_dequeue(queue _queue, int* _value_out){
    if(_queue == NULL) return QUEUE_ERROR_NULL; 
    if(_queue->size == 0) return QUEUE_ERROR_EMPTY;
    
    *_value_out = _queue->data[_queue->head];
    _queue->head = (_queue->head + 1) % _queue->capacity;
    _queue->size--; 
    
    return QUEUE_SUCCESS; 
}

int queue_peek(queue _queue, int* _value_out){
    if(_queue == NULL) QUEUE_ERROR_NULL;
    if(_queue->size == 0) return QUEUE_ERROR_EMPTY;
    
    *_value_out = _queue->data[_queue->head];
    return QUEUE_SUCCESS;
}

bool queue_is_empty(queue _queue){
    return (_queue == NULL || _queue->size == 0);
}

bool queue_is_full(queue _queue){
    if(_queue == NULL) return false;
    return (_queue->size == _queue->capacity); 
}
