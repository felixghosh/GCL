#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>

#define error_exit(message) \
            fprintf(stderr, "ERROR AT LINE:%d in FILE: %s: ", __LINE__, __FILE__);\
            fprintf(stderr, (message));\
            exit(1)

#endif