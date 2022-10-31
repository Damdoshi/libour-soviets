#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* our_basename(char *path)
{
    if (path == NULL)
    {
        return NULL;
    }
    char *last_slash = strrchr(path, '/');
    if (last_slash == NULL)
        return path;
    if (last_slash == path) {
        return "/";
    }
    if (last_slash[1] == '\0')
    {
        int foundLast = 0;
        for (int current = strlen(path); current >= 0; current--)
        {
            char currentChar = path[current];
            if (currentChar == '/') {
                if (foundLast == 1)
                {
                    char *basename = &path[current + 1];
                    char *newBasename = malloc(strlen(basename));
                    strncpy(newBasename, basename, strlen(basename) - 1);
                    return newBasename;
                }
                foundLast = 1;
            }
        }

    }
    return last_slash + 1;
}
