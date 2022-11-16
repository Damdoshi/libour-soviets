#include	<stdlib.h>
#include	"ourstring.h"

int main(void) {
    char* text[4] = {"Il", "était", "une", "fois"};
    assert(strcmp(our_implode(text, " ", 4), "Il était une fois") == 0);
    assert(our_implode(text, " ", 6) == 0);
    assert(our_implode(text, " ", -1) == 0);
    return EXIT_SUCCESS;
}