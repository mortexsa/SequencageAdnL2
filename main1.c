#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "distance.h"
#include "famille.h"

int main(){


	DISTANCE dist = Recherche_fichiers("sequences_ADN");
	comparaison(&dist);
	for(int i=0;i<20;i++){
		printf("chaine : %d\n", dist.mesSequences[i].taille);
	}
	/*for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			printf("[%0.1f]", dist.Distance_Finale[i][j]);
		}
		printf("\n");
	}*/
	/*FAMILLE Fam;
	float mininf = 0;

	float min = dist_min(dist, mininf);
	printf("mini = %f\n", min);
	int groupe[20] = {0};
	int indicator = indice(dist, &Fam, min, groupe);
	printf("merde = %d\n", indicator);
	printf("Fam.taille : %d\n", Fam.taille);
	construction(dist, &Fam, indicator, groupe);
	for (int i = 0; i < Fam.taille; i++)
	{
		printf("%s\n", Fam.sequence[i].sequence);
	}*/
	LISTFAMILLE lfamille = touteLesSequences(dist);
	printf("lfamille.taille : %d\n", lfamille.taille);
	for(int i = 0; i<lfamille.taille;i++){
		printf("Famille %d :\n", i);
		for(int j=0;j<lfamille.famille[i].taille;j++){
			printf("sequence %d : %s\n",j, lfamille.famille[i].sequence[j].sequence);
		}
		
	}
	return 0;
}