#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "distance.h"
#include "famille.h"
#include "alignement.h"

int main(){


	DISTANCE dist = Recherche_fichiers("sequences_ADN");
	comparaison(&dist);
	
	LISTFAMILLE lfamille = touteLesSequences(dist);
	
	printf("\n\n\n");
	printf("Partie 3 :\n");
	printf("\n\n\n");
	printf("Famille 0 :\n");
	for(int j=0;j<lfamille.famille[0].taille;j++){
			printf("sequence %d : %s\n",j, lfamille.famille[0].sequence[j].sequence);
		}
	SEQUENCE s = seqConsensus(lfamille.famille[0]);
	for (int i = 0; i < s.taille; ++i)
	{
		printf("%d", s.numerique[i]);
	}
	printf("\n");
	printf("Sequence consensus: %s\n", s.sequence);

	return 0;
}