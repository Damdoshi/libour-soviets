## Jason Brillante "Damdoshi" ---------------------------------------------- ##
## Pentacle Technologie 2008-2023 ------------------------------------------ ##
## EFRITS SAS 2022-2023 ---------------------------------------------------- ##
## Hanged Bunny Studio 2014-2021 ------------------------------------------- ##
## La Caverne aux Lapins Noirs --------------------------------------------- ##
## ------------------------------------------------------------------------- ##
## Our Lib ----------------------------------------------------------------- ##
## ------------------------------------------------------------------------- ##

REPORT		=	$(shell pwd)/report/
PRJ_DIR		=	$(shell pwd)/../
SRC_DIR		=	$(PRJ_DIR)src/
INC_DIR		=	$(PRJ_DIR)include/
LIB_DIR		=	LD_LIBRARY_PATH=$(PRJ_DIR)
TEST_LIBRARY	:=	$(basename $(subst lib,,$(TEST_LIBRARY)))

COMPILER	?=	gcc
RM		=	rm -f

LFLAGS		=	-L$(PRJ_DIR) -lgcov -l$(TEST_LIBRARY)
CFLAGS		=	-Wextra -Wall -fPIC -std=c11 -O0 -Og -g -g3 -ggdb -fprofile-arcs -ftest-coverage --coverage -rdynamic -fno-omit-frame-pointer -fno-align-functions -fno-align-loops -I$(INC_DIR)

SRC		=	$(wildcard src/*.c)
OBJ		=	$(basename $(SRC))

all		:	$(REPORT)

$(REPORT)	:	$(OBJ)
	echo -n $(TEAL)
	lcov --directory . --directory $(SRC_DIR) -c -o coverage_raw.info
	lcov --remove coverage_raw.info '/usr/include/*' '7/*' -o coverage.info
	genhtml -o $(REPORT) -t "LibOur" coverage.info

$(OBJ)		:
	echo -n $(PINK)
	$(COMPILER) $@.c -o $@ $(CFLAGS) $(LFLAGS)
	$(LIB_DIR) $@

clean		:
	$(RM) $(OBJ)
	$(RM) *.info
	$(RM) *.gc*

fclean		:	clean
	$(RM) -r $(REPORT)

re		:	fclean all
