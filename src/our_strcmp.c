#include <stdio.h>

#include "ourstring.h"

int our_strcmp(const char *string1, const char *string2) {

	efassert("string1 is NULL", string1, return (-2));
	efassert("string2 is NULL", string2, return (-2));

	for(; *string1 == *string2 && *string1 && *string2 ; ++string1, ++string2) {}
    	if(!*string1 && !*string2) return 0;
    	return *string1 < *string2 ? -1 : 1;
}
