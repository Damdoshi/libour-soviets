#include <stdlib.h>
#include "ourstring.h"

int main(void) {
    assert(our_explode(' ', NULL) == 0);
    assert(strcmp(our_explode(' ', "")[0], "") == 0);
    assert(strcmp(our_explode(' ', "")[0], "") == 0);
    assert(strcmp(our_explode(' ', "arara")[0], "arara") == 0);
    assert(strcmp(our_explode(' ', "ara ara")[0], "ara") == 0);
    return EXIT_SUCCESS;
}