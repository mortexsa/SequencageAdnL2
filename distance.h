#ifndef __DISTANCE_H
#define __DISTANCE_H

#include "sequence.h"

struct Distance{
	char **nom;
	float **Distance_Finale;
};
typedef struct Distance DISTANCE;

DISTANCE Recherche_fichiers(char *name);
void comparaison(DISTANCE *dist, SEQUENCE lire, SEQUENCE lire2);

#endif