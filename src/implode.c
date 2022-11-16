// implode.c

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/ourstring.h"
char* our_implode(char* strings[], char* seperator, int nb_of_strings) {
    efassert("nb_of_strings is negative", nb_of_strings >= 0, return(0));
    char* result = NULL;
    size_t result_size = 0;
    int i = 0;
    for (i = 0; i < nb_of_strings; i++) {
        efassert("nb_of_strings is greater than the number of substrings in strings", strings[i], return(0));
        result_size += strlen(strings[i]);
    }
    result_size++;    
    result_size += strlen(seperator) * (nb_of_strings - 1);
    result = (char*) malloc(result_size);; 
    result[0] = '\0';
    for (i = 0; i < nb_of_strings; i++) {
        efassert("nb_of_strings is greater than the number of substrings in strings", strings[i], return(0));
        strcat(result, strings[i]);
        if (i < (nb_of_strings - 1)) strcat(result, seperator);
    }

    return result;
}

/*void main(){
    char* text[4] = {"Il", "était", "une", "fois"};
    printf("%s\n", implode(text, " ", 6));
}*/