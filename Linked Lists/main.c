#include <stdio.h>
#include "library.h"
#include "library.c"

int main(){
    list list = create_list();

    // inserting in the back and in the front
    insert_back(list, 99);
    insert_back(list, 123);
    insert_back(list, 11);
    insert_back(list, 9);
    insert_front(list, 88);


    // getting the values from the front and the back
    int value;
    get_front(list, &value);
    printf("Element at the front: %d\n", value);

    get_back(list, &value);
    printf("Last element: %d\n", value);

    insert_at(list, 1, 67);


    // printing the elements using the iterator
    printf("List elements:\n");
    iterator _iterator = iterator_create(list);

    while(iterator_has_next(_iterator)){
        int val = iterator_next(_iterator);
        printf("%d\n", val);
    }
    destroy_iterator(_iterator);


    // searching a value
    int index;
    if(list_find(list, 9, &index) == 0) printf("The element was found in index: %d\n", index);
    else printf("Element not found\n");


    remove_value(list, 9);

    remove_at(list, 0);

    destroy_list(&list);
    if(list == NULL) printf("List destroyed\n");

    return 0;
}
