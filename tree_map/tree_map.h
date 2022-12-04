#ifndef TREE_MAP_H
#define TREE_MAP_H

#include <stdbool.h>

typedef struct entry_t{
    void* key;
    void* value;
}entry_t;

typedef struct tree_map_t{
    struct tree_set_t* left;
    struct tree_set_t* right;
    entry_t entry;
    int (*cmp)(void*, void*);
}tree_map_t;

tree_map_t* new_tree_map(void* key, void* value, int (*cmp)(void*, void*));
void free_tree_map(tree_map_t* map);
void insert_tree_map(tree_map_t* map);
void remove_tree_map(tree_map_t* map);
bool contains_tree_map(tree_map_t* map);
void print_tree_map(tree_map_t* map, const char* format);
void* get_tree_map(tree_map_t* map, void* key);

#endif