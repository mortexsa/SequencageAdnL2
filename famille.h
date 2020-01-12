#ifndef __FAMILLE_H
#define __FAMILLE_H
#include "distance.h"

struct Famille{
	char ** sequence;
	int taille;
	float Dmin;
};
typedef struct Famille FAMILLE;

float dist_min(DISTANCE dist, float mininf);
int indice(DISTANCE dist, FAMILLE fam, float min);

#endif