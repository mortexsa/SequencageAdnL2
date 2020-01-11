#ifndef __FAMILLE_H
#define __FAMILLE_H
#include "distance.h"

struct Famille{
	char ** famille;
	float Dmin;
};
typedef struct Famille FAMILLE;

void distance_min(DISTANCE dist, FAMILLE *fam);
//FAMILLE construction(DISTANCE dist, FAMILLE fam);

#endif