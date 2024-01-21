#include "tree_map.h"
#include <stdio.h>
#include <string.h>

int main(){
    tree_map_t* map = new_tree_map((void*)2, (void*)1, NULL);
    print_tree_map(map, "{%d: %d}");
    insert_tree_map(map, (void*)3, (void*)3);
    print_tree_map(map, "{%d: %d}");
    int value = get_tree_map(map, (void*)3);
    printf("get(3) gives: %d\n", value);
    printf("map contains 3: %s\n", contains_tree_map(map, (void*)3) ? "True" : "False");
    remove_tree_map(map, (void*)3);
    print_tree_map(map, "{%d: %d}");
    printf("map contains 3: %s\n", contains_tree_map(map, (void*)3) ? "True" : "False");
    

    tree_map_t* route = new_tree_map((void*)"/about", "something", &strcmp);
    insert_tree_map(route, (void*)"/help", (void*)"something else");
    printf("/about gives: %s\n", get_tree_map(route, (void*)"/about"));
    printf("/help gives: %s\n", get_tree_map(route, (void*)"/help"));

    free_tree_map(map);
    return 0;
}