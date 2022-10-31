#include <stdlib.h>
#include <assert.h>
#include "../../src/basename.c"

int main(void) {
    assert(our_basename("/usr/lib") == "lib");
    assert(our_basename("/usr/") == "usr");
    assert(our_basename("usr") == "usr");
    assert(our_basename("/") == "/");
    return (EXIT_SUCCESS);
}