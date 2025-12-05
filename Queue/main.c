#include <stdio.h>
#include "queue.h"
#include "queue.c"


int main(void) {

    queue q = queue_create(5);

    if(q == NULL){
        printf("There was an error with the queue creation\n");
        return 1;
    }

    // inserting elements into the queue
    for(int i = 1; i <= 5; i++){
        if(queue_enqueue(q, i * 10) == QUEUE_SUCCESS) printf("Enqueued: %d\n", i * 10);
        else printf("Queue is full\n");
    }

    // trying to add elements when the queue is full
    if(queue_enqueue(q, 60) == QUEUE_ERROR_FULL) printf("\nQueue is full, enqueue failed\n");


    // getting the element at the head of the queue
    int value;
    if(queue_peek(q, &value) == QUEUE_SUCCESS) printf("\nPeek successful: %d\n", value);

    // removing 3 elements
    for(int i = 0; i < 3; i++){
        if(queue_dequeue(q, &value) == QUEUE_SUCCESS) printf("Dequeued: %d\n", value);
    }

    queue_enqueue(q, 70);
    queue_enqueue(q, 80);


    queue_destroy(&q);
    if(q == NULL) printf("\nQueue successfully deallocated\n");

    return 0;
}

