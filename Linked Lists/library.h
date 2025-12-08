
/*
 * library.h
 *
 * Interface for a generic linked list, implemented as an ADT with opaque pointers to hide internal details
 *
 * The list has operations for inserting, removing, access and search for an element
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
 * @param value Is the value to insert
 * @return LINKED_LIST_SUCCESS if it succeeded
 *         LINKED_LIST_ERROR_NULL if list is NULL
 *         LINKED_LIST_ERROR_ALLOC if the memory allocation failed
*/
int insert_front(list list, int value);


/*
 * Inserts an element at the tail of the list
 * @param value Is the value to insert
 * @return LINKED_LIST_SUCCESS if ok, 
 *         LINKED_LIST_ERROR_NULL if list is null
 *         LINKED_LIST_ERROR_ALLOC if the memory allocation failed
*/
int insert_back(list list, int value);


/*
 * Inserts an element at poistion i (0-based)
 * @param list List to insert into
 * @param value Is the value to insert
 * @return LINKED_LIST_SUCCESS if ok
 *         LINKED_LIST_ERROR_NULL if list is NULL
 *         LINKED_LIST_ERROR_INDEX is index is negative or it's too big
 *         LINKED_LIST_ERROR_ALLOC if memory allocation failed
*/
int insert_at(list list, int index, int value);

int get_at(list list, int index, int* value_out);

int get_front(list list, int* value_out);

int get_back(list list, int* value_out);

int list_find(list list, int value, int* index_out);

int remove_at(list list, int index);

int remove_value(list list, int value);

int size(list list);

int is_empty(list list);

void destroy_list(list* list);

iterator iterator_create(list list);

bool iterator_has_next(iterator _iterator);

int iterator_next(iterator _iterator);

void destroy_iterator(iterator* _iterator);


