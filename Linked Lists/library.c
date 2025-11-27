#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "library.h"

typedef struct _node{
    int value;
    struct _node* next;
} node;

struct list{
    node* head;
    node* tail;
    int size;
};

struct list_iterator{
    list list;
    node* current;
};

list create_list(){
    list list = malloc(sizeof(struct list));

    if(list != NULL){
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return list;
}

int insert_front(list _list, int value){
    if (_list == NULL) return -1;

    node* new_node = malloc(sizeof(node));
    if(new_node == NULL) return -2;

    new_node->value = value;
    new_node->next = _list->head;
    _list->head = new_node;

    if(_list->tail == NULL) _list->tail = new_node;
    _list->size++;

    return 0;
}

int insert_back(list _list, int value){
    if(_list == NULL) return -1;

    node* new_node = malloc(sizeof(node));

    if(new_node == NULL) return -2;

    new_node->value = value;
    new_node->next = NULL;

    if(_list->tail != NULL) _list->tail->next = new_node;
    else _list->head = new_node;

    _list->tail = new_node;
    _list->size++;

    return 0;
}

int insert_at(list _list, int index, int value){
    if(_list == NULL) return -1;
    if(index < 0 || index > _list->size) return -4;
    if(index == 0) return insert_front(_list, value);
    if(index == _list->size) return insert_back(_list, value);

    node* prev = _list->head;

    for(int i = 0; i < index; i++) prev = prev->next;

    node* new_node = malloc(sizeof(node));
    if(new_node == NULL) return -2;

    new_node->value = value;
    new_node->next = prev->next;
    prev->next = new_node;

    _list->size++;
    return 0;
}

int get_at(list _list, int index, int* value_out){
    if(_list == NULL) return -1;
    if(_list->head == NULL) return -3;
    if(index < 0 || index > _list->size) return -4;

    node* current = _list->head;
    for(int i = 0; i < index; i++) current = current->next;

    *value_out = current->value;
    return 0;
}

int get_front(list _list, int* value_out){
    if(_list == NULL) return -1;
    if(_list->head == NULL) return -3;

    *value_out = _list->head->value;
    return 0;
}

int get_back(list _list, int* value_out){
    if(_list == NULL) return -1;
    if(_list->tail == NULL) return -3;

    *value_out = _list->tail->value;
    return 0;
}

int list_find(list _list, int value, int* index_out){
    if(_list == NULL) return -1;

    node* current = _list->head;
    int index = 0;

    while((current != NULL) && (current->value != value)){
        current = current->next;
        index++;
    }
    if(current == NULL) return -5;
    else {
        *index_out = index;
        return 0;
    }
}

int remove_at(list _list, int index){
    if(_list == NULL) return -1;
    if(index < 0 || index > _list->size) return -4;
    if(_list->head == NULL) return -3;

    node* to_delete;
    if(index == 0){
        to_delete = _list->head;
        _list->head = to_delete->next;
        if(_list->head == NULL) _list->tail == NULL;
    }
    else {
        node* prev = _list->head;
        for(int i = 0; i < index - 1; i++) prev = prev->next;
        to_delete = prev->next;
        prev->next = to_delete->next;
        if(to_delete == _list->tail) _list->tail = prev;
    }

    free(to_delete);
    _list->size--;
    return 0;
}

int remove_value(list _list, int value){
    if(_list == NULL) return -1;

    node* current = _list->head;
    node* prev = NULL;

    while((current != NULL) && (current->value != value)){
        prev = current;
        current = current->next;
    }
    if(current == NULL) return -5;
    else{
        if(prev == NULL){
            _list->head = current->next;
            if(_list->head == NULL) _list->tail = NULL;
        }
        else {
            prev->next = current->next;
            if(current == _list->tail) _list->tail = prev;
        }
        free(current);
        _list->size--;
        return 0;
    }
}

int size(list _list){
    if(_list == NULL) return -1;
    return (_list->size);
}

int is_empty(list _list){
    if(_list == NULL) return -1;
    return (_list->size == 0);
}

void destroy_list(list* _list){
    if(_list == NULL || *_list == NULL) return;

    node* current = (*_list)->head;
    while(current != NULL){
        node* next = current->next;
        free(current);
        current = next;
    }
    free (*_list);
    *_list = NULL;
}

iterator iterator_create(list _list){
    if(_list == NULL) return NULL;

    iterator _iterator = malloc(sizeof(struct list_iterator));
    if(_iterator == NULL) return NULL;

    _iterator->current = _list->head;
    return _iterator;
}

bool iterator_has_next(iterator _iterator){
    return (_iterator != NULL && _iterator->current != NULL);
}

int iterator_next(iterator _iterator){
    int value = _iterator->current->value;
    _iterator->current = _iterator->current->next;
    return value;
}

void destroy_iterator(iterator* _iterator){
    if(_iterator == NULL || *_iterator == NULL) return;
    free(*_iterator);
    *_iterator = NULL;
}
