#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "gcl_treeset.h"

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

tree_set_t* new_tree_set(void* data, int (*cmp)(void*, void*)){
    tree_set_t* set = malloc(sizeof(tree_set_t));
    set->left = NULL;
    set->right = NULL;
    set->data = data;
    if(cmp != NULL)
        set->cmp = cmp;
    else
        set->cmp = &default_cmp;

    return set;
}

void free_tree_set(tree_set_t* set){
    if(set->left != NULL)
        free_tree_set(set->left);
    if(set->right != NULL)
        free_tree_set(set->right);
    free(set);
}

void insert_tree_set(tree_set_t* set, void* data){
    if(set->data == NULL){
        set->data = data;
    }else{
        int comp = set->cmp(data, set->data);
        if(comp < 0){
            //smaller
            if(set->left == NULL)
                set->left = new_tree_set(data, set->cmp);
            else
                insert_tree_set(set->left, data);
        } else if(comp > 0){
            //bigger
            if(set->right == NULL)
                set->right = new_tree_set(data, set->cmp);
            else
                insert_tree_set(set->right, data);
        } else {
            //value equal => value already in tree
            return;
        }
    }
}


static void re_add_rec(tree_set_t* add, tree_set_t* orig){
    if(add != NULL){
        insert_tree_set(orig, add->data);
        re_add_rec(add->left, orig);
        re_add_rec(add->right, orig);
    }
}

void remove_tree_set(tree_set_t* set, void* data){
    if(!contains_tree_set(set, data))
        return;

    int comp = set->cmp(data, set->data);
    if(comp < 0){
        if(set->left != NULL){
            if(set->left->data == data){
                //remove
                tree_set_t* node = set->left;
                set->left = NULL;
                re_add_rec(node->left, set);
                re_add_rec(node->right, set);
            } else {
                remove_tree_set(set->left, data);
            }

        }
    } else if(comp > 0){
        if(set->right != NULL){
            if(set->right->data == data){
                //remove
                tree_set_t* node = set->right;
                set->right = NULL;
                re_add_rec(node->left, set);
                re_add_rec(node->right, set);
            } else {
                remove_tree_set(set->right, data);
            }
        }
    } else {
        //Root node needs to be deleted
        tree_set_t* new_root = new_tree_set(NULL, set->cmp);
        re_add_rec(set->left, new_root);
        re_add_rec(set->right, new_root);
        *set = *new_root;
    }
}

bool contains_tree_set(tree_set_t* set, void* data){
    if(set->data == NULL)
        return false;
    
    int comp = set->cmp(data, set->data);
    if(comp < 0){
        if(set->left == NULL)
            return false;
        else
            contains_tree_set(set->left, data);
    } else if(comp > 0){
        if(set->right == NULL)
            return false;
        else
            contains_tree_set(set->right, data);
    } else {
        //value found
        return true;
    }
    assert(0);
}

static void print_structure_rec(tree_set_t* set, int level, const char* format){
    if(set != NULL){
        if(set->data != NULL){
            for(int i = 0; i < level; i++)
                printf("  ");
            printf(format, set->data);
            printf("\n");
            print_structure_rec(set->right, level+1, format);
            print_structure_rec(set->left, level+1, format);
        }
    }
}

void print_structure_tree_set(tree_set_t* set, const char* format){
    print_structure_rec(set, 0, format);
}

static void print_rec(tree_set_t* set, const char* format){
    if(set != NULL){
        if(set->data != NULL){
            printf(format, set->data);
            printf(" ");
            print_rec(set->right, format);
            print_rec(set->left, format);
        }
    }
}

void print_tree_set(tree_set_t* set, const char* format){
    printf("{ ");
    print_rec(set, format);
    printf("}\n");
}