#include "../include/ourstring.h"
#include <stdlib.h>
#include <string.h>

char** our_explode(const char delimiter, const char* str) {
	efassert("str is null", str , return (0));
	char *pointer = strcpy(malloc(strlen(str)),str);
	unsigned int cp_size = sizeof(char*);
	char **result = (char**)malloc(cp_size);
	unsigned long j = 1;
	result[0] = pointer;
	while(*pointer){
		if(*pointer == delimiter){
			result = (char**)realloc(result,(++j)*cp_size);
			result[j-1] = pointer+1;
			*pointer = 0;
		}
		pointer++;
	}
	return result;
}