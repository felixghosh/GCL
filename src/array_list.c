#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gcl_arraylist.h"

static int default_cmp(void* d1, void* d2){
    if(d1 < d2)
        return -1;
    else if(d1 == d2)
        return 0;
    else if(d1 > d2)
        return 1; 
    else{
        printf("ERROR IN CMP FUNCTION!\n");
        exit(1);
    }
}

array_list_t* new_array_list(unsigned int elem_size, unsigned int initial_capacity, int (*cmp)(void*, void*), void* data){
    array_list_t* list = malloc(sizeof(array_list_t));
    list->elem_size = elem_size;
    list->capacity = initial_capacity;
    list->list = calloc(initial_capacity, elem_size);
    if(data != NULL){
        list->list[0] = data;
        list->length = 1;
    } else {
        list->length = 0;
    }
    if(cmp != NULL){
        list->cmp = cmp;
    } else {
        list->cmp = &default_cmp;
    }

    return list;
}

void free_array_list(array_list_t* list){
    free(list->list);
    free(list);
}

void* get_array_list(array_list_t* list, int index){
    return list->list[index*list->elem_size];
}

void set_array_list(array_list_t* list, int index, void* data){
    if(list->capacity > index){
        if(list->list[index] == NULL)
            list->length++;
        memcpy(&(list->list[index*list->elem_size]), data, list->elem_size);
    }
    
}

unsigned int length_array_list(array_list_t* list){
    return list->length;
}