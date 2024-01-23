#include "gcl_mem.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

static long allocation_counter = 0;


void *internal_checked_malloc(size_t size, int line, const char *file){
    void *p = malloc(size);
    if(p == NULL){
        fprintf(stderr, "ERROR! Checked Malloc returned NULL.\nThis function was called on line:%d in file:%s\nerno: %s\n", line, file, strerror(errno));
        exit(1);
    }
    allocation_counter++;

    return p;
}

void *internal_checked_realloc(void *ptr, size_t size, int line, const char *file){
    ptr = realloc(ptr, size);
    if(ptr == NULL) {
        fprintf(stderr, "ERROR! Checked Realloc returned NULL.\nThis function was called on line:%d in file:%s\nerno: %s\n", line, file, strerror(errno));
        exit(1);
    }
    return ptr;
}

void *internal_checked_calloc(size_t nmemb, size_t size, int line, const char *file){
    void *p = calloc(nmemb, size);
    if(p == NULL){
        fprintf(stderr, "ERROR! Checked Calloc returned NULL.\nThis function was called on line:%d in file:%s\nerno: %s\n", line, file, strerror(errno));
        exit(1);
    }
    allocation_counter++;

    return p;
}


void  internal_checked_free  (void **ptr, int line, const char *file){
    if(allocation_counter <= 0){
        fprintf(stderr, "ERROR! Checked free was called with an allocation counter of %ld, meaning that you are freeing more memory than what has been allocated.\nThis function was called on line:%d in file:%s\nerno: %s\n", allocation_counter, line, file, strerror(errno));
        exit(1);
    }
    free(*ptr);
    allocation_counter--;
    *ptr = NULL;
}

void check_allocations(){
    if(allocation_counter > 0){
        fprintf(stderr, "ERROR! Memory leak detected! Allocation counter is %ld. A positive allocation counter means that you have allocated memory that has not been freed.\n", allocation_counter);
        exit(1);
    }
    if(allocation_counter < 0){
        fprintf(stderr, "ERROR! memory corruption detected! Allocation counter is %ld. A negative allocation counter means that you have freed more memory than what has been allocated.\n", allocation_counter);
        exit(1);
    }
}