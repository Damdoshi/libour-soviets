#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<assert.h>
#include	<sys/types.h>
#include	<signal.h>
#include <string.h>


int our_strrchr(char *string, char *cible) {
    if (string == 0 || cible == 0 )
        return 0;
    int len = 0;
    int result = 0;
    int i = 0;
    int c = cible[0];

    while(string[len] != '\0')
        len++;
    for (i = 0 ; i <= len ; i++)
        if (string[i] == c)
            result = i + 1;
    return result;

}

void jai_chie(int n)
{
    (void)n;
    puts("SegFault Detected in our_strcspn");
    sleep(1);
}

int main()
{
    signal(SIGSEGV, jai_chie);
    char buf[] = "0A";
    assert(our_strrchr(buf, buf) == NULL);
    //printf("%s", strrchr(buf,buf));
    return (EXIT_SUCCESS);
}


