#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/ourstring.h"

char* our_dirname(char *path) 
{
    efassert("path is null", path, return (NULL));
    char *last_slash = strrchr(path, '/');
    if (last_slash == NULL) {
        return ".";
    }    
    if (last_slash == path || last_slash[1] == '\0') {
        return "/";
    }    
    char *newPath = malloc(strlen(path));
    strncpy(newPath, path, strlen(path) - strlen(last_slash));
    return newPath;
}
