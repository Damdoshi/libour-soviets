#include <assert.h>
#include <stdio.h>

#include "../../include/ourstring.h"

int main() {
	assert(our_strncmp("Voiture", "Véhicule", 50) == -84);
	assert(our_strncmp("Voiture", "Véhicule", 7) == -84);
	assert(our_strncmp("Voiture", "Véhicule", 0) == -3);
	assert(our_strncmp("Voiture", "Véhicule", -5) == -84);
	assert(our_strncmp(NULL, "Maison", 4) == -2);
	assert(our_strncmp("Maison", NULL, -50) == -2);
	assert(our_strncmp(NULL, NULL, 150) == -2);
	assert(our_strncmp("Voiture", "Voiture", 5) == 0);
	assert(our_strncmp("Voiture", "Voiture", 50) == 0);
}
