#include "gcl_mem.h"
#include <stdio.h>

int main(){
    int *buffer = checked_calloc(10, sizeof (int));

    printf("[ ");
    for(int i = 0; i < 10; i++){
        printf("%d ", buffer[i]);
    }
    printf("]\n");
    
    printf("[ ");
    for(int i = 0; i < 10; i++){
        buffer[i] = i;
        printf("%d ", buffer[i]);
    }
    printf("]\n");
        
    checked_free(buffer);
    if(buffer == NULL)
        printf("SUCCESS! Buffer is NULL after free\n");


    check_allocations();
    return 0;
}