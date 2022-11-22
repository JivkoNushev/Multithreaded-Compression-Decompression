#include <stdio.h>
#include <stdlib.h>

#include "string.h"

size_t strlen_(char *string)
{
    size_t len = 0;
    if(NULL != string)
    {
        for(;'\0' != *string; string++, len++);
    }
    
    return len;
}

char* strcat_(char *dest, char *src)
{
    size_t dest_size = strlen_(dest), src_size = strlen_(src);
    size_t size = dest_size + src_size + 1;
    
    dest = (char *) realloc(dest, size + 2);
    if(NULL == dest)
    {
        return NULL;
    }

    for(int i = 0; i < src_size; i++)
    {
        dest[i + dest_size + 1] = src[i];
    }
    dest[size] = '\0';

    return dest;
}

char *strcpy_(char *dest, char *src)
{
    size_t dest_len = strlen_(dest), src_len = strlen_(src);

    if(src_len > dest_len)
    {
        dest = (char *) realloc(dest, src_len + 1);
        if(NULL == dest)
        {
            return NULL;
        }
    }
    
    for(size_t i = 0; i < src_len; i++)
    {
        dest[i] = src[i];
    }
    dest[src_len] = '\0';

    return dest;
}