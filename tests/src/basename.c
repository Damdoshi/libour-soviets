#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../../include/ourstring.h"

int main(void) {
    assert(strcmp(our_basename("/usr/lib"), "lib") == 0);
    assert(strcmp(our_basename("/usr/"), "usr") == 0);
    assert(strcmp(our_basename("usr"), "usr") == 0);
    assert(strcmp(our_basename("/"), "/") == 0);
    return (0);
}