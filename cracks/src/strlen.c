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
#include	<assert.h>
#include	<sys/types.h>

size_t		our_strlen(const char	*str);

int		main(void)
{
  char		buffer[256];

  for (size_t i = 0; i < sizeof(buffer); ++i)
    buffer[i] = 255 - i;
  assert(our_strlen(buffer) == 255);
  assert(our_strlen("") == 0);
  assert(our_strlen(NULL) == 0);
  return (EXIT_SUCCESS);
}

