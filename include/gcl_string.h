#ifndef STRING_H
#define STRING_H

#include <stddef.h>

char *str_upper    (char *s);
char *str_lower    (char *s);
char *str_caps     (char *s);
char *str_rev      (char *s);
char *str_left     (char *s, size_t len);
char *str_right    (char *s, size_t len);
char *str_mid      (char *s, size_t len, size_t offset);
char *str_insert   (const char *src, const char *ins, size_t offset);
int   str_split    (char *src, char **s1, char **s2, size_t offset);
int   str_wordcount(const char *s);


#endif