#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "famille.h"

float dist_min(DISTANCE dist, float mininf){
	float min = 0;
	int i=0;
	while(i<20){
		printf("valeur de dist : %f\n", dist.Distance_Finale[0][i]);
		printf("valeur de min : %f\n", min);
		if(dist.Distance_Finale[0][i] > mininf){
			printf("eyhoh\n");
			min = dist.Distance_Finale[0][i];
			break;
		}
		i++;
	}
	//printf("valeur de min : %d\n", min);
	for(int a = 0; a < 20; a++){
		for(int b = a; b < 20; b++){
			if(a != b){
				if(min > dist.Distance_Finale[a][b] && dist.Distance_Finale[a][b] > mininf){
					min = dist.Distance_Finale[a][b];
				}
			}
		}
	}

	printf("Le minimum vaut: %.2f\n", min);

	return min;
}

int indice(DISTANCE dist, FAMILLE * fam, float min, int * aUnGroupe){
	int cpt = 0; int nb_fam = 0; int indice;

	fam->Dmin = min;
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			if(dist.Distance_Finale[i][j] == fam->Dmin && aUnGroupe[j] == 0){
				cpt++;
				printf("La séquence est: %s\n", dist.nom[j]);
			}
			if(nb_fam < cpt){
				nb_fam = cpt;
				indice = i;
			}
		}
		cpt = 0;
	}

	fam->taille = nb_fam + 1;

	return indice;
}

void construction(DISTANCE dist, FAMILLE * fam, int indice, int * aUnGroupe){
	fam->sequence = (SEQUENCE *) malloc(fam->taille * sizeof(SEQUENCE));
	fam->sequence[0] = dist.mesSequences[indice];
	aUnGroupe[indice] = 1;
	int nigga = 1;
	for(int j = 0; j < 20; j++){
		if(dist.Distance_Finale[indice][j] == fam->Dmin && aUnGroupe[j] == 0){
			fam->sequence[nigga] = dist.mesSequences[j];
			aUnGroupe[j] = 1;
			printf("La sequence: %s\n", dist.mesSequences[j].sequence);
			nigga++;
		}
		
	}
}