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
#include <string.h>
#include	"ourstring.h"

int		main(void)
{
  assert(strcmp(our_strstr("Hello World", "World"),"World") == 0);
  assert(strcmp(our_strstr("Hello World", "Hello"),"Hello World") == 0);
  assert(strcmp(our_strstr("Hello World", "Hello World"),"Hello World") == 0);
  return (EXIT_SUCCESS);
}

