## Jason Brillante "Damdoshi" ---------------------------------------------- ##
## Pentacle Technologie 2008-2023 ------------------------------------------ ##
## EFRITS SAS 2022-2023 ---------------------------------------------------- ##
## Hanged Bunny Studio 2014-2021 ------------------------------------------- ##
## La Caverne aux Lapins Noirs --------------------------------------------- ##
## ------------------------------------------------------------------------- ##
## Our Lib ----------------------------------------------------------------- ##
## ------------------------------------------------------------------------- ##

RELEASE		?=	0
PROD_LIBRARY	=	libour.a
export TEST_LIBRARY =	libour.so

export COMPILER	?=	gcc
PROD_LINKER	?=	ar rcs
TEST_LINKER	=	$(COMPILER) -shared $(LFLAGS) -fprofile-arcs -o
RM		=	rm -f

LFLAGS		=
CFLAGS		=	-Wextra -Wall -fPIC -std=c11 -I./include/

export PINK	=	"\033[1;35m"
export TEAL	=	"\033[1;36m"

ifeq ($(RELEASE), 1)
  CFLAGS	+=	-O3 -ffast-match -march=native
  LFLAGS	+=
else
  CFLAGS	+=	-O0 -Og -g -g3 -ggdb -fprofile-arcs -ftest-coverage --coverage -fno-omit-frame-pointer -fno-align-functions -fno-align-loops -DNDEBUG
  LFLAGS	+=
endif

SRC		=	$(wildcard src/*.c)
OBJ		=	$(SRC:.c=.o)

all		:	$(PROD_LIBRARY) check

$(PROD_LIBRARY)	:	$(OBJ)
	echo -n $(TEAL)
	$(PROD_LINKER) $(PROD_LIBRARY) $(OBJ) $(LFLAGS)

$(TEST_LIBRARY)	:	$(OBJ)
	echo -n $(TEAL)
	$(TEST_LINKER) $(TEST_LIBRARY) $(OBJ)

.c.o		:
	echo -n $(PINK)
	$(COMPILER) -c $< -o $@ $(CFLAGS)

clean		:
	$(RM) $(OBJ)
	find . -name "*.info" -delete
	find . -name "*.gc*" -delete
	@(cd tests/ && $(MAKE) clean --no-print-directory)

fclean		:	clean
	$(RM) $(PROD_LIBRARY) $(TEST_LIBRARY)
	@(cd tests/ && $(MAKE) fclean --no-print-directory)

re		:	fclean all

check		:	$(TEST_LIBRARY)
	@(cd tests/ && $(MAKE) --no-print-directory)
