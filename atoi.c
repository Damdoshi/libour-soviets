
// Program to implement atoi() in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
// A simple atoi() function
int our_atoi(char* str)
{
    // Initialize result
    int res = 0;
    int i = 0;
    int temp = strlen(str);

    if (str == NULL){
        return -1;
        /* code */
    }


    //if str is empty
    if (*str == '\0'){
        return -2;
    }


    for (int i = 0;  str[i] != '\0'; ++i){
        // if str[i] is not present in ascii table
        if (str[i] < 0 || str[i] > 128){
            return -3;
        }

    }


    // if str is longer than 10 characters return -3
    if (strlen(str) > 10){
        return -3;
    }

    if (strlen(str)  >10 && str[0] == '+'){
        return -3;
    }

    if (strlen(str)  >10 && str[0] == '-'){
        return -3;
    }


    


    // if str[0] is + print only positive numbers
    if (str[0] == '+'){
        str++;

        for (int i = 0;  str[i] != '\0'; ++i){
            if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9'){
                return res;
            }
            res = res * 10 + str[i] - '0';

            
        }

        
        return res;
    }

    if (str[0] == '-'){
        str++;

        // return str with "-" sign

        for (int i = 0;  str[i] != '\0'; ++i){
            if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9'){
                res = res - res*2;
                return res;
            }
            res = res * 10 + str[i] - '0';

            
        }

        res = res - res*2;
        return res;
    }


    for (int i = 0; str[i] != '\0'; ++i){

        //if str[i] is not a number return -4
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9'){
            return res;
        }

        res = res * 10 + str[i] - '0';
    

        
    }
 
    // return result.
    return res;
}
 
// Driver Code

