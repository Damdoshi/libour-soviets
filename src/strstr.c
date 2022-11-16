#include <string.h>
#include <stddef.h>
#include <stdio.h>


char *our_strstr(const char *str, const char *substring)
{
    int i,j,k;
    //efassert("str is null", str && substring, return (0));

    if (str == NULL) {
        return 0;
    }

    if (substring == NULL) {
        return 0;
    }

    const char *b;

    int len1 = strlen(str);
    int len2 = strlen(substring);

    //efassert("invalide entrie", len1 < len2, return (0));

    if (len1 < len2){
        return 0;
    }

    b = substring;

    if (*b == 0) {
        return (char *) str;
    }

    for (i = 0; i < len1; i++){
        for (j = i, k = 0; k < len2; j++, k++){
            if (str[j] != substring[k]) break;
        }
        if (k == len2){
            return (char *)str + i;
        }
    }
    return NULL;
}

int main(){
    char test[]="yoyoyo danyilll";

    printf("%s",our_strstr("ddd\0f", ""));
}