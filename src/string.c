#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "gcl_mem.h"
#include "gcl_string.h"

char *str_upper(char *s) {
    char *buf = checked_calloc(strlen(s)+1, sizeof (char));
    int i = 0;

    while(*s) {
        if(*s >= 'a' && *s <= 'z')
            *s -= 32;
        buf[i++] = *s++;
    }

    return buf;
} 

char *str_lower(char *s) {
    char *buf = checked_calloc(strlen(s)+1, sizeof (char));
    int i = 0;

    while(*s) {
        if(*s >= 'A' && *s <= 'Z')
            *s += 32;
        buf[i++] = *s++;
    }

    return buf;
}

char *str_caps(char *s) {
    char *buf = checked_calloc(strlen(s)+1, sizeof (char));
    int state = 0, i = 0;

    while(*s){
        if(state == 0){
            if(isalpha(*s)){
                state = 1;
                *s = toupper(*s);
            }
        } else {
            if(!isalpha(*s))
                state = 0;
        }
        buf[i++] = *s++;
    }

    return buf;
}

char *str_rev(char *s) {
    size_t len = strlen(s);
    char *buf = checked_calloc(len, sizeof (char) + 1);
    int j = 0;

    for(int i = len; i > 0; i--)
        buf[j++] = s[i-1];
    
    return buf;
}

char *str_left(char *s, size_t len) {
    char *buf = checked_calloc(len+1, sizeof (char));

    strncpy(buf, s, len);

    return buf;
}

char *str_right(char *s, size_t len) {
    char *buf = checked_calloc(len+1, sizeof (char));

    size_t s_len = strlen(s);
    if(s_len <= len)
        strncpy(buf, s, s_len);
    else
        for(size_t i = 0; i < len; i++)
            buf[i] = s[s_len-len+i];

    return buf;
}

char *str_mid(char *s, size_t len, size_t offset) {
    char *buf = checked_calloc(len+1, sizeof (char));

    strncpy(buf, s+offset, len);

    return buf;
}

char *str_insert(const char *src, const char *ins, size_t offset) {
    size_t src_len = strlen(src);
    size_t ins_len = strlen(ins);

    if(offset > src_len)
        offset = src_len;

    char *buf = checked_calloc(src_len + ins_len + 1, sizeof (char));
    strncpy(buf, src, offset);
    strncat(buf, ins, ins_len);
    strncat(buf, src+offset, src_len-offset);

    return buf;
}

int str_split(char *src, char **s1, char **s2, size_t offset) {
    size_t len = strlen(src);
    
    if(len < offset)
        return -1;
    *s1 = checked_calloc(offset + 1, sizeof (char));
    *s2 = checked_calloc(len - offset + 1, sizeof (char));
    strncpy(*s1, src, offset);
    strncpy(*s2, src+offset, len-offset);

    return 0;
}

int str_wordcount(const char *s) {
    int state = 0, count = 0;

    while(*s){
        if(state == 0){
            if(isalnum(*s)){
                state = 1;
                count++;
            }
        } else {
            if(isspace(*s))
                state = 0;
        }
        s++;
    }

    return count;
}
