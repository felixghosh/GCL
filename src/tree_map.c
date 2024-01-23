#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "gcl_treemap.h"

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

void free_tree_map(tree_map_t* map){
    if(map->left != NULL)
        free_tree_map(map->left);
    if(map->right != NULL)
        free_tree_map(map->right);
    free(map);
}

void insert_tree_map(tree_map_t* map, void* key, void* value){
    if(map->entry.key == NULL){
        map->entry.key = key;
        map->entry.value = value;
    }else{
        int comp = map->cmp(key, map->entry.key);
        if(comp < 0){
            //smaller
            if(map->left == NULL)
                map->left = new_tree_map(key, value, map->cmp);
            else
                insert_tree_map(map->left, key, value);
        } else if(comp > 0){
            //bigger
            if(map->right == NULL)
                map->right = new_tree_map(key, value, map->cmp);
            else
                insert_tree_map(map->right, key, value);
        } else {
            //value equal => value already in tree
            return;
        }
    }
}

static void re_add_rec(tree_map_t* add, tree_map_t* orig){
    if(add != NULL){
        insert_tree_map(orig, add->entry.key, add->entry.value);
        re_add_rec(add->left, orig);
        re_add_rec(add->right, orig);
    }
}

void remove_tree_map(tree_map_t* map, void* key){
    if(!contains_tree_map(map, key))
        return;

    int comp = map->cmp(key, map->entry.key);
    if(comp < 0){
        if(map->left != NULL){
            if(map->left->entry.key == key){
                //remove
                tree_map_t* node = map->left;
                map->left = NULL;
                re_add_rec(node->left, map);
                re_add_rec(node->right, map);
            } else {
                remove_tree_map(map->left, key);
            }

        }
    } else if(comp > 0){
        if(map->right != NULL){
            if(map->right->entry.key == key){
                //remove
                tree_map_t* node = map->right;
                map->right = NULL;
                re_add_rec(node->left, map);
                re_add_rec(node->right, map);
            } else {
                remove_tree_map(map->right, key);
            }
        }
    } else {
        //Root node needs to be deleted
        tree_map_t* new_root = new_tree_map(NULL, NULL, map->cmp);
        re_add_rec(map->left, new_root);
        re_add_rec(map->right, new_root);
        *map = *new_root;
    }
}

bool contains_tree_map(tree_map_t* map, void* key){
    if(map->entry.key == NULL)
        return false;
    
    int comp = map->cmp(key, map->entry.key);
    if(comp < 0){
        if(map->left == NULL)
            return false;
        else
            contains_tree_map(map->left, key);
    } else if(comp > 0){
        if(map->right == NULL)
            return false;
        else
            contains_tree_map(map->right, key);
    } else {
        //key found
        return true;
    }
    assert(0);
}

static void print_structure_rec(tree_map_t* map, int level, const char* format){
    if(map != NULL){
        if(map->entry.key != NULL){
            for(int i = 0; i < level; i++)
                printf("  ");
            printf(format, map->entry.key, map->entry.value);
            printf("\n");
            print_structure_rec(map->right, level+1, format);
            print_structure_rec(map->left, level+1, format);
        }
    }
}

void print_structure_tree_map(tree_map_t* map, const char* format){
    print_structure_rec(map, 0, format);
}

static void print_rec(tree_map_t* map, const char* format){
    if(map != NULL){
        if(map->entry.key != NULL){
            printf(format, map->entry.key, map->entry.value);
            printf(" ");
            print_rec(map->right, format);
            print_rec(map->left, format);
        }
    }
}

void print_tree_map(tree_map_t* map, const char* format){
    printf("{ ");
    print_rec(map, format);
    printf("}\n");
}

void* get_tree_map(tree_map_t* map, void* key){
    if(map->entry.key == NULL)
        return false;
    
    int comp = map->cmp(key, map->entry.key);
    if(comp < 0){
        if(map->left == NULL)
            return NULL;
        else
            get_tree_map(map->left, key);
    } else if(comp > 0){
        if(map->right == NULL)
            return NULL;
        else
            get_tree_map(map->right, key);
    } else {
        //key found
        return map->entry.value;
    }
    assert(0);
}