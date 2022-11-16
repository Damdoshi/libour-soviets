#include	<stdlib.h>
#include	<stdio.h>
#include	<assert.h>
#include	<sys/types.h>
#include	<signal.h>




long our_strtol(const char *theString, char **end, int base){
    long result = 0;
    int sign = 1;
    int i = 0;
    int digit = 0;
    if (theString[i] == '-'){
        sign = -1;
        i++;
    }
    else if (theString[i] == '+'){
        i++;
    }
    if (base == 0){
        if (theString[i] == '0'){
            if (theString[i+1] == 'x' || theString[i+1] == 'X'){
                base = 16;
                i += 2;
            }
            else{
                base = 8;
                i++;
            }
        }
        else{
            base = 10;
        }
    }
    else if (base == 16){
        if (theString[i] == '0' && (theString[i+1] == 'x' || theString[i+1] == 'X')){
            i += 2;
        }
    }
    while (theString[i] != '\0'){
        if (theString[i] >= '0' && theString[i] <= '9'){
            digit = theString[i] - '0';
        }
        else if (theString[i] >= 'a' && theString[i] <= 'z'){
            digit = theString[i] - 'a' + 10;
        }
        else if (theString[i] >= 'A' && theString[i] <= 'Z'){
            digit = theString[i] - 'A' + 10;
        }
        else{
            break;
        }
        if (digit >= base){
            break;
        }
        result = result * base + digit;
        i++;
    }
    if (end != 0){
        *end = (char *) &theString[i];
    }
    return result * sign;

}

void jai_chie(int n)
{
	(void)n;
	puts("SegFault Detected");
}

int main()
{
    //printf("%d\n",our_strtol(NULL, NULL, NULL));
	signal(SIGSEGV, jai_chie);
	our_strtol(NULL, NULL, NULL);
    return (EXIT_SUCCESS);
}


