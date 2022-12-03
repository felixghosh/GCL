#include "tree_set.h"
#include <stdio.h>

int main(){
    tree_set_t* set = new_tree_set((void*)3);
    insert_tree_set(set, (void*)2);
    insert_tree_set(set, (void*)5);
    insert_tree_set(set, (void*)1);
    insert_tree_set(set, (void*)0);
    insert_tree_set(set, (void*)6);
    insert_tree_set(set, (void*)4);
    insert_tree_set(set, (void*)3);
    print_tree_set(set);
    printf("Tree contains 3: %s\n", contains_tree_set(set, (void*)3) ? "True" : "False");
    remove_tree_set(set, (void*)5);
    print_tree_set(set);
    printf("Tree contains 5: %s\n", contains_tree_set(set, (void*)5) ? "True" : "False");
    remove_tree_set(set, (void*)3);
    print_tree_set(set);
    printf("Tree contains 3: %s\n", contains_tree_set(set, (void*)3) ? "True" : "False");
    

    
    free_tree_set(set);
    return 0;
}