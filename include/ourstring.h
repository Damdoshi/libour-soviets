/*
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
** ----------------------------------------------------------------------------
*/

#ifndef		OURSTRING_H
# define	OURSTRING_H
# include	<sys/types.h>
# include	"efassert.h"

size_t		our_strlen(const char	*str);
char** our_explode(const char delimiter, const char* str);
char* our_implode(char* strings[], char* seperator, int nb_of_strings);

#endif	/*	OURSTRING_H		*/

