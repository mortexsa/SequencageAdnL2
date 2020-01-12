#ifndef __FAMILLE_H
#define __FAMILLE_H
#include "distance.h"
#include "sequence.h"

struct Famille{
	SEQUENCE * sequence;
	int taille;
	float Dmin;
};
typedef struct Famille FAMILLE;

float dist_min(DISTANCE dist, float mininf);
int indice(DISTANCE dist, FAMILLE * fam, float min, int * aUnGroupe);
void construction(DISTANCE dist, FAMILLE * fam, int indice, int * aUnGroupe);

#endif