#ifndef TREE_SET_H
#define TREE_SET_H

#include <stdbool.h>

typedef struct tree_set_t{
    struct tree_set_t* left;
    struct tree_set_t* right;
    void* data;
    int (*cmp)(void*, void*);
}tree_set_t;

tree_set_t* new_tree_set(void* data, int (*cmp)(void*, void*));
void free_tree_set(tree_set_t* set);
void insert_tree_set(tree_set_t* set, void* data);
void remove_tree_set(tree_set_t* set, void* data);
bool contains_tree_set(tree_set_t* set, void* data);
void print_tree_set(tree_set_t* set);


#endif