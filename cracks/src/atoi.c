#include	<stdlib.h>
#include	<assert.h>
#include	<sys/types.h>



int our_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    if (str == 0)
        return 0;
    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] != '\0')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }

    return sign * result;
}



int	main(void)
{
  assert(our_atoi("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA") == 0);
  return (EXIT_SUCCESS);
}


