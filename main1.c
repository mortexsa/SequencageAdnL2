#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "distance.h"
#include "famille.h"

int main(){

	SEQUENCE lire, lire2;

	DISTANCE dist = Recherche_fichiers("sequences_ADN");
	comparaison(&dist, lire, lire2);

	FAMILLE Fam;
	float mininf = 0;

	float min = dist_min(dist, mininf);
	int indicator = indice(dist, Fam, min);
	printf("merde = %d\n", indicator);
	return 0;
}