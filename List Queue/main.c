#include <stdio.h>
#include "library.h"
#include "library.c"


int main(){
    // creating the queue
    queue q = create_queue(5);

    if(q == NULL){
        printf("There was an error in creating the queue!\n");
        return 1;
    }

    // inserting elements into the queue
    for(int i = 1; i <= 5; i++){
        if(enqueue(q, i * 10) == QUEUE_SUCCESS) printf("Enqueued: %d\n", i * 10);
        else printf("Queue is full, can't add %d\n", i * 10);
    }

    // trying to enqueue an element when the queue is full
    if(enqueue(q, 60) == QUEUE_ERROR_FULL) printf("Queue is full, enqueue failed\n");


    // peek (return the element at the head of the queue)
    int value;
    if(peek(q, &value) == QUEUE_SUCCESS) printf("Element at the head: %d\n", value);


    // removing 3 elements
    for(int i = 0; i < 3; i++){
        if(dequeue(q, &value) == QUEUE_SUCCESS) printf("Dequeued value: %d\n", value);
    }

    // removing all the remaining elements

    while(!is_empty(q)){
        if(dequeue(q, &value) == QUEUE_SUCCESS) printf("Dequeued: %d\n", value);
    }

    destroy_queue(&q);
    if(q == NULL) printf("Queue destroyed\n");

    return 0;
}
