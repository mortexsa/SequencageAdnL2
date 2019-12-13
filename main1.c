#include <stdio.h>
#include "sequence.h"

int main(){

	SEQUENCE Lire = lire_fichier("sequences_ADN/seq01.txt");
	SEQUENCE Lire2 = lire_fichier("sequences_ADN/seq02.txt");

	calcul_prov(Lire.sequence,Lire2.sequence,Lire.taille-1,Lire2.taille-1);

	return 0;
}