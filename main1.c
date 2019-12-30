#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "distance.h"

char nom[20][25];
float **stick;

int main(){

	Recherche_fichiers("sequences_ADN");
	
	comparaison();

	return 0;
}