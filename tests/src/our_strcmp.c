#include <assert.h>
#include <stdio.h>

#include "../../include/ourstring.h"

int main() {
	assert(our_strcmp("Maison", "Manger") == -1);
	assert(our_strcmp("Manger", "Maison") == 1);
	assert(our_strcmp("Maison", "Maison") == 0);
	assert(our_strcmp("Maison", NULL) == -2);
	assert(our_strcmp(NULL, "Maison") == -2);
}
