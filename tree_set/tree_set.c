#include <stdlib.h>
#include <stdio.h>
#include "tree_set.h"

tree_set_t* new_tree_set(void* data){
    tree_set_t* set = malloc(sizeof(tree_set_t));
    set->left = NULL;
    set->right = NULL;
    set->data = data;

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
    } else if(data < set->data){
        if(set->left == NULL)
            set->left = new_tree_set(data);
        else
            insert_tree_set(set->left, data);
    } else if( data > set->data){
        if(set->right == NULL)
            set->right = new_tree_set(data);
        else
            insert_tree_set(set->right, data);
    } else {
        //value already in tree
        return;
    }
}


void re_add_rec(tree_set_t* add, tree_set_t* orig){
    if(add != NULL){
        insert_tree_set(orig, add->data);
        re_add_rec(add->left, orig);
        re_add_rec(add->right, orig);
    }
}

void remove_tree_set(tree_set_t* set, void* data){
    if(!contains_tree_set(set, data))
        return;

    if(data < set->data){
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
    } else if(data > set->data){
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
        tree_set_t* new_root = new_tree_set(NULL);
        re_add_rec(set->left, new_root);
        re_add_rec(set->right, new_root);
        *set = *new_root;
    }
}

bool contains_tree_set(tree_set_t* set, void* data){
    if(data < set->data){
        if(set->left == NULL)
            return false;
        else
            contains_tree_set(set->left, data);
    } else if( data > set->data){
        if(set->right == NULL)
            return false;
        else
            contains_tree_set(set->right, data);
    } else {
        //value found
        return true;
    }
}

void print_rec(tree_set_t* set, int level){
    if(set != NULL){
        if(set->data != NULL){
            for(int i = 0; i < level; i++)
                printf("  ");
            printf("%d\n", set->data);
            print_rec(set->right, level+1);
            print_rec(set->left, level+1);
        }
    }
}

void print_tree_set(tree_set_t* set){
    print_rec(set, 0);
}