#include "../include/ourstring.h"
#include <stdio.h>

char *our_strncat(char *dest, const char *src, int limit)
{
    efassert("str is null", dest && src, return (0));
    efassert("incorrect limit", limit>0, return (0));

    int i,j;
    for (i = 0; dest[i] != '\0'; i++);
    for (j = 0; src[j] != '\0'; j++)
    {
        if(j != limit){
            dest[i+j] = src[j];
            }
    }
    dest[i+j] = '\0';
    return dest;
}