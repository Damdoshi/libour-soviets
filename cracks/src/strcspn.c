#include	<stdlib.h>
#include	<stdio.h>
#include	<assert.h>
#include	<sys/types.h>
#include	<signal.h>





size_t our_strlen(const char	*str)
{
    const char	*tmp;

    for (tmp = str; *tmp; ++tmp);
    return (tmp - str);
}

size_t our_strcspn(const char *string, const char *rejected) {

    const char *copy = string;
    const char *iter = rejected;
    int count = 0;
    int len = our_strlen(string);

    while (len != 0) {
        if (*copy == *iter) {
            return count;
        }
        ++copy;
        count += 1;
        len -= 1;
    }
    return count;
}

void jai_chie(int n)
{
	(void)n;
	puts("SegFault Detected in our_strcspn");
}

int main()
{
	signal(SIGSEGV, jai_chie);
	our_strcspn(NULL, NULL, NULL);
    return (EXIT_SUCCESS);
}


