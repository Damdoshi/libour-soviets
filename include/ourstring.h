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
char		*our_strcat(char *dest,const char *src);
int		our_strcmp(const char *string1, const char *string2);
char* our_basename(char *path);

#endif	/*	OURSTRING_H		*/

