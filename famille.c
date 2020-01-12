#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "famille.h"

float dist_min(DISTANCE dist, float mininf){
	float min = 2;

	for(int a = 0; a < 20; a++){
		for(int b = a; b < 20; b++){
			if(a != b){
				if(min > dist.Distance_Finale[a][b]){
					mininf = min; 
					min = dist.Distance_Finale[a][b]; //Nous définissons la distance minimum
				}
				else if(mininf > dist.Distance_Finale[a][b] && dist.Distance_Finale[a][b] != min){
					mininf = dist.Distance_Finale[a][b];
				}
			}
		}
	}

	printf("Le minimum vaut: %.2f\n", min);
	printf("Le deuxième min vaut: %.2f\n", mininf);

	return min;
}

int indice(DISTANCE dist, FAMILLE fam, float min){
	int cpt = 0; int nb_fam = 0; int indice;

	fam.Dmin = min;
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			if(dist.Distance_Finale[i][j] == fam.Dmin){
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

	fam.taille = nb_fam + 1;

	return indice;
}
void construction(DISTANCE dist, FAMILLE fam, int indice){
	
	fam.sequence = (char **) malloc(fam.taille * sizeof(char *));
	for(int i = 0; i < fam.taille; i++){
		fam.sequence[i] = (char *) malloc(24 * sizeof(char));
	}

	fam.sequence[0] = dist.nom[indice];
	int nigga = 1;
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			if(dist.Distance_Finale[i][j] == fam.Dmin){
				fam.sequence[nigga] = dist.nom[j];
				printf("La sequence: %s\n", dist.nom[j]);
				nigga++;
			}
		}
	}

}