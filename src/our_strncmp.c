#include <stdio.h>
#include <string.h>

#include "ourstring.h"

int our_strncmp(const char *string1, const char *string2, size_t n) {

	efassert("string1 is NULL", string1, return(-2));
	efassert("string2 is NULL", string2, return(-2));

	if (n == 0) {
		efassert("Bad value for n, need to be greater than 0", n, return(-3));
	}

	else if (n > strlen(string1)) {
		efassert("n is greater than the length of string1", n, return(-4));
	}

	else if (n > strlen(string2)) {
		efassert("n is greater than the length of string2", n, return(-4));
	}

	do {
		if (*string1 != *string2++) {
			return *(unsigned char *)string1 - *(unsigned char *)--string2;
		}

		if (*string1++ == 0) {
			break;
		}

	} while (--n != 0);

	return 0;
}
