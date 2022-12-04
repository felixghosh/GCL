#include "tree_map.h"
#include <stdio.h>

int main(){
    tree_map_t* map = new_tree_map((void*)2, (void*)1, NULL);
    print_tree_map(map, "{%d: %d}\n");
    insert_tree_map(map, (void*)3, (void*)3);
    print_tree_map(map, "{%d: %d}\n");
    printf("map contains 3: %s\n", contains_tree_map(map, (void*)3) ? "True" : "False");
    remove_tree_map(map, (void*)3);
    print_tree_map(map, "{%d: %d}\n");
    printf("map contains 3: %s\n", contains_tree_map(map, (void*)3) ? "True" : "False");
    int value = get_tree_map(map, (void*)2);
    printf("get(2) gives: %d\n", value);

    free_tree_map(map);
    return 0;
}