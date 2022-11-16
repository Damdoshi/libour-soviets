/*
** Jason Brillante "Damdoshi" -------------------------------------------------
** Pentacle Technologie 2008-2023 ---------------------------------------------
** EFRITS SAS 2022-2023 -------------------------------------------------------
** Hanged Bunny Studio 2014-2021 ----------------------------------------------
** La Caverne aux Lapins Noirs ------------------------------------------------
** ----------------------------------------------------------------------------
** Our Lib --------------------------------------------------------------------
** ----------------------------------------------------------------------------
*/

#include	<stdlib.h>
#include	"ourstring.h"
#include <string.h>
int		main(void)
{
  assert(our_strcat(NULL,NULL) == 0);
  assert(our_strcat(NULL,"ac") == 0);
  assert(our_strcat("ac",NULL) == 0);
  char str1[100] = "Hello";
  char str2[100] = "World";
  assert(strcmp(our_strcat(str1, str2),"HelloWorld")==0);

  return (EXIT_SUCCESS);
}

