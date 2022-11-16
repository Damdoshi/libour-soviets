#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../../include/ourstring.h"

int main(void) {
    assert(strcmp(our_dirname("/usr/lib"), "/usr") == 0);
    assert(strcmp(our_dirname("/usr/"), "/") == 0);
    assert(strcmp(our_dirname("usr"), ".") == 0);
    assert(strcmp(our_dirname("/"), "/") == 0);
    return (0);
}