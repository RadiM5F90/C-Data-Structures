
#include <stdbool.h>
#include <stdlib.h>

typedef struct list* list;
typedef struct list_iterator* iterator;

list create_list();

int insert_front(list list, int value);

int insert_back(list list, int value);

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


