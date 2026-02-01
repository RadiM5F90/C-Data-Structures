
/*
 * library.h
 *
 * Interface for a generic linked list, implemented as an ADT with opaque pointers to hide internal details
 *
 * The list has operations for inserting, removing, accessing and searching for an element
 * Can be used in C applications that require flexible data structures
*/

#include <stdbool.h>
#include <stdlib.h>

// abstract type for the linked list
typedef struct list* list;

// abstract type for a list iterator
typedef struct list_iterator* iterator;

// return codes 
#define LINKED_LIST_SUCCESS 0           
#define LINKED_LIST_ERROR_NULL -1       
#define LINKED_LIST_ERROR_ALLOC -2      
#define LINKED_LIST_ERROR_EMPTY -3      
#define LINKED_LIST_ERROR_INDEX -4      
#define LINKED_LIST_ERROR_NOT_FOUND -5 

/*
 * Creates a new empty list
 * @return Pointer to the new list, or NULL if the memory allocation failed
*/
list create_list();


/*
 * Inserts an element at the front of the list
 * @oaram list List to insert into
 * @param value Is the value to insert
 * @return LINKED_LIST_SUCCESS if it succeeded
 *         LINKED_LIST_ERROR_NULL if list is NULL
 *         LINKED_LIST_ERROR_ALLOC if the memory allocation failed
*/
int insert_front(list list, int value);


/*
 * Inserts an element at the tail of the list
 * @oaram list List to insert into
 * @param value Is the value to insert
 * @return LINKED_LIST_SUCCESS if ok, 
 *         LINKED_LIST_ERROR_NULL if list is NULL
 *         LINKED_LIST_ERROR_ALLOC if the memory allocation failed
*/
int insert_back(list list, int value);


/*
 * Inserts an element at index i (0-based)
 * @param list List to insert into
 * @param index Index to insert into
 * @param value Is the value to insert
 * @return LINKED_LIST_SUCCESS if ok
 *         LINKED_LIST_ERROR_NULL if list is NULL
 *         LINKED_LIST_ERROR_INDEX if index is negative or it's too big
 *         LINKED_LIST_ERROR_ALLOC if memory allocation failed
*/
int insert_at(list list, int index, int value);


/*
 * Reads the element in position i (0-based)
 * @param list List from which to read the element from
 * @param index Index to read from
 * @param value_out Pointer to write the value on
 * @return LINKED_LIST_SUCCESS if ok 
 *         LINKED_LIST_ERROR_NULL if list is NULL
 *         LINKED_LIST_ERROR_INDEX if index is out of bounds
 *         LINKED_LIST_ERROR_ALLOC if memory allocation fails
*/
int get_at(list list, int index, int* value_out);


/*
 * Gets the first element of the list
 * @param list List from which to get the element from
 * @param value_out Pointer to write the value on
 * @return LINKED_LIST_SUCCESS if ok
 *         LINKED_LIST_ERROR_NULL if list is NULL
 *         LINKED_LIST_ERROR_EMPTY if the list is empty
*/
int get_front(list list, int* value_out);


/*
 * Gets the last element of the list
 * @param list List from which to get the element from
 * @param value_out Pointer to write the value on
 * @return LINKED_LIST_SUCCESS if found
 *         LINKED_LIST_ERROR_NULL if list is NULL
 *         LINKED_LIST_ERROR_EMPTY if the list is empty
*/
int get_back(list list, int* value_out);

/*
 * Searches the first occurrence of a value
 * @param list List to search in
 * @param value Value to search for
 * @param index_out Pointer to write the index on
 * @return LINKED_LIST_SUCCESS if found
 *         LINKED_LIST_ERROR_NULL if list is NULL
 *         LINKED_LIST_ERROR_NOT_FOUND if the value is not found
*/
int list_find(list list, int value, int* index_out);


/*
 * Removes an element from position i
 * @param list List to remove from 
 * @param index Index of the element to remove
 * @return LINKED_LIST_SUCCESS if found
 *         LINKED_LIST_ERROR_NULL if list is NULL
 *         LINKED_LIST_ERROR_INDEX if the index is not valid
 *         LINKED_LIST_ERROR_EMPTY if the list is empty
*/
int remove_at(list list, int index);


/*
 * Removes the first occurrence of a value
 * @param list List to remove from
 * @param value Value to remove
 * @return LINKED_LIST_SUCCESS if found
 *         LINKED_LIST_ERROR_NULL if list is NULL
 *         LINKED_LIST_ERROR_NOT_FOUND if the value is not found
*/
int remove_value(list list, int value);


/*
 * Returns the number of elements in the list
 * @param list List to get the size of
 * @return number of elements, or LINKED_LIST_ERROR_NULL if list is NULL
*/
int size(list list);


/*
 * Checks if the list is empty
 * @param list List to check
 * @return 1 if empty, 0 if not empty, LINKED_LIST_ERROR_NULL if list is NULL
*/
int is_empty(list list);


/*
 * Deallocates the list and all of its nodes
 * @param list List to deallocate
*/
void destroy_list(list* list);


/*
 * Creates an iterator for the list
 * @param list List to iterate on
 * @return Pointer to the iterator, or NULL if there is an error
*/
iterator iterator_create(list list);


/*
 * Checks if there are still elements to iterate
 * @param _iterator Iterator to check
 * @return true if there are more elements, false otherwise
*/
bool iterator_has_next(iterator _iterator);


/*
 * Returns the current value and moves the iterator forward
 * @param _iterator Iterator to use
 * @return Iteration's current value 
*/
int iterator_next(iterator _iterator);


/*
 * Deallocates the iterator
 * @param _iterator Iterator to destroy
*/
void destroy_iterator(iterator* _iterator);


