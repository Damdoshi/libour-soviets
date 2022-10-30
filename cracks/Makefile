## Jason Brillante "Damdoshi" ---------------------------------------------- ##
## Pentacle Technologie 2008-2023 ------------------------------------------ ##
## EFRITS SAS 2022-2023 ---------------------------------------------------- ##
## Hanged Bunny Studio 2014-2021 ------------------------------------------- ##
## La Caverne aux Lapins Noirs --------------------------------------------- ##
## ------------------------------------------------------------------------- ##
## Our Lib ----------------------------------------------------------------- ##
## ------------------------------------------------------------------------- ##

TEST_LIBRARY	?=	libour.so
TEST_LIBRARY	:=	$(basename $(subst lib,,$(TEST_LIBRARY)))
PRJ_DIR		=	$(shell pwd)/../
INC_DIR		=	../include/
LIB_DIR		=	LD_LIBRARY_PATH=$(PRJ_DIR)

COMPILER	?=	gcc
RM		=	rm -f

LFLAGS		=	-L$(PRJ_DIR) -l$(TEST_LIBRARY)
CFLAGS		=	-Wextra -Wall -fPIC -std=c11 -I$(INC_DIR) -g

SRC		=	$(wildcard src/*.c)
OBJ		=	$(basename $(SRC))

all		:	$(OBJ)
	@echo `ls src/*.trace 2> /dev/null | wc -l` "weakness(es) found(s)"

$(OBJ)		:
	$(COMPILER) $@.c -o $@ $(CFLAGS) $(LFLAGS)
	$(LIB_DIR) valgrind --error-exitcode=42 $@ 2> $@.trace && $(RM) $@.trace || echo -n

clean		:
	$(RM) $(OBJ)

fclean		:	clean
	$(RM) -r $(REPORT)
	find . -name "*.trace" -delete

re		:	fclean all

