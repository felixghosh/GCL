#include <string.h>

int compstring(void* d1, void* d2){
    return strcmp((const char*) d1, (const char*) d2);
}