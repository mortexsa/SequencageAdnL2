#include <stdio.h>
#include "sequence.h"

int main(){

	SEQUENCE Lire = lire_fichier("sequences_ADN/seq01.txt");
	SEQUENCE Lire2 = lire_fichier("sequences_ADN/seq02.txt");

	calcul_distances2(Lire,Lire2);

	return 0;
}