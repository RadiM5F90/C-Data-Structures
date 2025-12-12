
/*
 * stack.h
 *
 * Interface for an ADT for a stack of integers
 * implemented through a fixed size array
 *
 * It has operations such for creating, destroying, inserting (push), removing (pop),
 * check the element at the top and check if the stack is empty or full
 */

#include <stdbool.h>
#include <stdlib.h>

#define STACK_SUCCESS 0
#define STACK_ERROR_NULL -1
#define STACK_ERROR_ALLOC -2
#define STACK_ERROR_EMPTY -3
#define STACK_ERROR_FULL -4

typedef struct _stack* stack;

/*
 * Creates a new stack with a specified capacity
 * @param _capacity Stack's max capacity
 * @return Pointer to the stack, or NULL if there was an allocation error
 */
stack stack_create(int _capacity);

/*
 * Destroys the stack and frees the memory
 * @param _stack Pointer to the stack to destroy, it will be set to NULL
 */
void stack_destroy(stack* _stack);

/*
 * Inserts a value at the top of the stack
 * @param _stack Stack to insert into
 * @param _value Value to insert
 * @return STACK_SUCCESS if the value was successfully inserted,
 *         STACK_ERROR_NULL if the stack is NULL,
 *         STACK_ERROR_FULL if the stack is full
 */
int stack_push(stack _stack, int _value);

/*
 * Removes the element from the top of the stack
 * @param _stack Stack to remove from
 * @param _value_out Pointer that's going to store the value
 * @return STACK_SUCCESS if the value was successfully removed,
 *         STACK_ERROR_NULL if the stack is NULL,
 *         STACK_ERROR_EMPTY if the stack is empty
 */
int stack_pop(stack _stack, int *_value_out);

/*
 * Returns the value from the top of the stack without popping it
 * @param _stack Stack to read from
 * @param _value_out Pointer that's going to store the value
 * @return STACK_SUCCESS if ok,
 *         STACK_ERROR_NULL if the stack is NULL,
 *         STACK_ERROR_EMPTY if the stack is empty
 */
int stack_top(stack _stack, int* _value_out);

/*
 * Checks if the stack is empty
 * @param _stack Stack to check
 * @return true if empty or if _stack is NULL, false otherwise.
 */
bool stack_is_empty(stack _stack);

/*
 * Checks if the stack is full
 * @param _stack Stack to check
 * @return true if full, false otherwise. Returns false if _stack is NULL 
 */
bool stack_is_full(stack _stack);
