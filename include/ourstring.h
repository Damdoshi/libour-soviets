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
char		*our_strcat(char *dest,const char *src);
char		*our_strncat(char *dest,const char *src,int limit);
int		our_strcmp(const char *string1, const char *string2);
int		our_strncmp(const char *string1, const char *string2, size_t n);
char* our_basename(char *path);
char* our_dirname(char *path);


#endif	/*	OURSTRING_H		*/

