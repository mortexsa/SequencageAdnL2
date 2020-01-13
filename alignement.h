#ifndef __ALIGNEMENT_H
#define __ALIGNEMENT_H
#include "famille.h"


struct Alignement{
	FAMILLE famille;
	SEQUENCE consensus;
};
typedef struct Alignement ALIGNEMENT;

char transformeInverse(int t);
SEQUENCE seqConsensus(FAMILLE fam);

#endif