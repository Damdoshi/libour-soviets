#include <string.h>
#include <stddef.h>
#include <stdio.h>

char *our_strnstr(const char *str, const char *substring, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *substring++) != '\0') {
		len = strlen(substring);
		do {
			do {
				if ((sc = *str++) == '\0' || slen-- < 1)
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(str, substring, len) != 0);
		str--;
	}
	return ((char *)str);
}

int main() {
    char buffer[64] = "salutles tout les mondes les de l'univers les";
    char *p = our_strnstr(buffer, "les", 8);
    printf("%s", p);
}

