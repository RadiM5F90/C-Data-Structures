
/*
 * Interface of an ADT for a queue of integers;
 *
 * The queue follows the FIFO semantic (First In, First Out), where the elements are inserted in the tail of the queue (enqueue),
 * and removed from the head of the queue (dequeue);
 *
 * The functions are for creating the queue, destroying it, inserting and removing elements,
 * read the element at the head of the queue, and check if the queue is empty or full;
 * 
 */

#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_SUCCESS 0
#define QUEUE_ERROR_NULL -1
#define QUEUE_ERROR_ALLOC -2
#define QUEUE_ERROR_EMPTY -3
#define QUEUE_ERROR_FULL -4

typedef struct _queue* queue;


/*
 * Creates a queue with a specified capacity
 * @param _capacity Max number of elements the queue can store
 * @return Pointer to the newly created queue, or NULL if there was an allocation error
 */
queue queue_create(int _capacity);

/*
 * Destroys the queue and frees its associated memory
 * @param _queue Pointer to the queue to destroy, it will be set to NULL
 * */
void queue_destroy(queue* _queue);

/*
 * Inserts an element into the queue
 * @param _queue Queue to insert the element into
 * @param _value Value to insert
 * @return QUEUE_SUCCESS if the insert was successful,
 *         QUEUE_ERROR_NULL if _queue is NULL,
 *         QUEUE_ERROR_FULL if the queue is full
 * */
int queue_enqueue(queue _queue, int _value);

/*
 * Removes the element at the head of the queue
 * @param _queue Queue from which to remove the element
 * @param _value_out Pointer that will store the removed value
 * @return QUEUE_SUCCESS if the value was successfully removed,
 *         QUEUE_ERROR_NULL if _queue is NULL,
 *         QUEUE_ERROR_EMPTY if the queue is empty
 * */
int queue_dequeue(queue _queue, int* _value_out);

/*
 * Returns the element at the head of the queue without removing it
 * @param _queue Queue to read from
 * @param _value_out Pointer that will store the value
 * @return QUEUE_SUCCESS if successful,
 *         QUEUE_ERROR_NULL if _queue is NULL,
 *         QUEUE_ERROR_EMPTY if the queue is empty
 * */
int queue_peek(queue _queue, int* _value_out);

/*
 * Checks if the queue is empty
 * @param _queue Queue to check
 * @return true if it is empty, false otherwise. It returns true even if _queue is NULL
 * */
bool queue_is_empty(queue _queue);

/*
 * Checks if the queue is full
 * @param _queue Queue to check
 * @return true if it is full, fals otherwise. Returns false if _queue is NULL
 * */
bool queue_is_full(queue _queue);
