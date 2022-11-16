#include	<stdlib.h>
#include	<stdio.h>
#include	<assert.h>
#include	<sys/types.h>
#include	<signal.h>




char *our_strchrnul(const char *string, int c) {
    while (*string && *string != (char)c) {
        string++;
    }
    return (char *)string;
}

void jai_chie(int n)
{
    (void)n;
    puts("SegFault Detected in our_strcspn");
}

int main()
{
    signal(SIGSEGV, jai_chie);
    our_strchrnul(NULL, NULL);
    return (EXIT_SUCCESS);
}