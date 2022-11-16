#include	<stdlib.h>
#include	"ourstring.h"
#include <string.h>
int		main(void)
{
  assert(our_strncat(NULL,NULL,4) == 0);
  assert(our_strncat(NULL,"ac",4) == 0);
  assert(our_strncat("ac",NULL,4) == 0);
  char str1[100] = "Hello";
  char str2[100] = "World";
  assert(strcmp(our_strncat(str1, str2,4),"HelloWorl")==0);

  return (EXIT_SUCCESS);
}