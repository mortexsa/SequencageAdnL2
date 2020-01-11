#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "distance.h"
#include "famille.h"

int main(){

	SEQUENCE lire, lire2;

	DISTANCE dist = Recherche_fichiers("sequences_ADN");
	comparaison(&dist, lire, lire2);

	//FAMILLE Fam;
	//distance_min(dist, &Fam);

	return 0;
}