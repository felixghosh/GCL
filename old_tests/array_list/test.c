#include <stdio.h>
#include "gcl_arraylist.h"

int main(){
    array_list_t* list = new_array_list(sizeof(int), 10, NULL, (void*)1);
    printf("length: %u\n", length_array_list(list));
    int v = 2;
    set_array_list(list, 1, (void*)&v);
    printf("length: %u\n", length_array_list(list));
    int a = get_array_list(list, 0);
    int b = get_array_list(list, 1);
    printf("a: %d, b: %d\n", a, b);

    free_array_list(list);
    return 0;
}