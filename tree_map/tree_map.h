#ifndef TREE_MAP_H
#define TREE_MAP_H

#include <stdbool.h>
#include <string.h>

typedef struct entry_t{
    void* key;
    void* value;
}entry_t;

typedef struct tree_map_t{
    struct tree_map_t* left;
    struct tree_map_t* right;
    entry_t entry;
    int (*cmp)(void*, void*);
}tree_map_t;

tree_map_t* new_tree_map(void* key, void* value, int (*cmp)(void*, void*));
void free_tree_map(tree_map_t* map);
void insert_tree_map(tree_map_t* map, void* key, void* value);
void remove_tree_map(tree_map_t* map, void* key);
bool contains_tree_map(tree_map_t* map, void* key);
void print_tree_map(tree_map_t* map, const char* format);
void print_structure_tree_map(tree_map_t* map, const char* format);
void* get_tree_map(tree_map_t* map, void* key);

#endif