#include <stdlib.h>
#include <stdio.h>
#include "tree_map.h"

int default_cmp(void* d1, void* d2){
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

tree_map_t* new_tree_map(void* key, void* value, int (*cmp)(void*, void*)){
    tree_map_t* map = malloc(sizeof(tree_map_t));
    map->left = NULL;
    map->right = NULL;
    map->entry.key = key;
    map->entry.value = value;
    if(cmp != NULL)
        map->cmp = cmp;
    else
        map->cmp = &default_cmp;

    return map;
}