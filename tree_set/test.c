#include "tree_set.h"
#include <stdio.h>
#include <string.h>

int main(){
    tree_set_t* set = new_tree_set((void*)3, NULL);
    insert_tree_set(set, (void*)2);
    insert_tree_set(set, (void*)5);
    insert_tree_set(set, (void*)1);
    insert_tree_set(set, (void*)0);
    insert_tree_set(set, (void*)6);
    insert_tree_set(set, (void*)4);
    insert_tree_set(set, (void*)3);
    print_structure_tree_set(set, "%d");
    printf("Tree contains 3: %s\n", contains_tree_set(set, (void*)3) ? "True" : "False");
    remove_tree_set(set, (void*)5);
    print_tree_set(set, "%d");
    printf("Tree contains 5: %s\n", contains_tree_set(set, (void*)5) ? "True" : "False");
    remove_tree_set(set, (void*)3);
    print_tree_set(set, "%d");
    printf("Tree contains 3: %s\n", contains_tree_set(set, (void*)3) ? "True" : "False");
    
    tree_set_t* str_set = new_tree_set((void*)"hej", &strcmp);
    print_tree_set(str_set, "%s");
    insert_tree_set(str_set, (void*)"hej");
    print_tree_set(str_set, "%s");
    insert_tree_set(str_set, (void*)"hejdå");
    insert_tree_set(str_set, (void*)"he");
    insert_tree_set(str_set, (void*)"h");
    insert_tree_set(str_set, (void*)"hejdå!");
    print_tree_set(str_set, "%s");
    printf("Tree contains hej: %s\n", contains_tree_set(str_set, (void*)"hej") ? "True" : "False");


    free_tree_set(set);
    free_tree_set(str_set);
    return 0;
}