#include <stdio.h>
#include "sequence.h"

int main(){

	SEQUENCE s2 = lire_fichier("sequences_ADN/seq03.txt");
	printf("%s\n", s2.sequence);

	return 0;
}