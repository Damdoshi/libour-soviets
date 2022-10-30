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

#ifndef		EFASSERT_H
# define	EFASSERT_H

// Ensure the stringification of the content of the parameter and not the parameter itself
# define	_TOSTRING(a)			#a
# define	TOSTRING(a)			_TOSTRING(a)

# ifdef		NDEBUG
#  define	efassert(msg, check, code)	do { if (!(check)) { code; } } while (0)
# else
#  include	<assert.h>
// Two steps to ensure the expansion of parameters
#  define	_efassert(msg, check)		assert((msg) && check)
#  define	efassert(msg, check, code)	_efassert(__FILE__ " line " TOSTRING(__LINE__) msg, check)
# endif

#endif	/*	EFASSERT_H			*/
