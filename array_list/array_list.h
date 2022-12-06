#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdbool.h>


typedef struct array_list_t{
    void** list;
    unsigned int length;
    unsigned int capacity;
    unsigned int elem_size;
    int (*cmp)(void*, void*);
} array_list_t;

array_list_t* new_array_list(unsigned int elem_size, unsigned int initial_capacity, int (*cmp)(void*, void*), void* data);
void  free_array_list(array_list_t* list);
void* get_array_list(array_list_t* list, int index);
void  set_array_list(array_list_t* list, int index, void* data);
void  prepend_array_list(array_list_t* list, void* data);
void  append_array_list(array_list_t* list, void* data);
void* pop_array_list(array_list_t* list, int index);
void  remove_array_list(array_list_t* list, void* data);
unsigned int length_array_list(array_list_t* list);
void* clear_array_list(array_list_t* list);
bool  contains_array_list(array_list_t* list, void* data);
void  print_array_list(array_list_t* list);

#endif