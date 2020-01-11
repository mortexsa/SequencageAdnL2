#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "famille.h"



void distance_min(DISTANCE dist, FAMILLE *fam){
	float min = dist.Distance_Finale[0][1];
	for(int a = 0; a < 20; a++){
		for(int b = 0; b < 20; b++){
			if(min > dist.Distance_Finale[a][b] && dist.Distance_Finale[a][b] != 0){
				min = dist.Distance_Finale[a][b];
			}
		}
	}
	printf("Le minimum vaut: %.2f\n", min);

	fam->famille = (char **) malloc(20 * sizeof(char *));
	for(int i = 0; i < 20; i++){
		fam->famille[i] = (char *) malloc(25 * sizeof(char));
	}
	
	int cpt = 0; int nb_fam = 0; int numero_seq;
	fam->Dmin = min;

	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			fam->famille[j] = dist.nom[j];

			if(dist.Distance_Finale[i][j] == fam->Dmin){
				cpt++;
				printf("--------------------------------------------> %s\n", dist.nom[i]);
			}
			if(nb_fam < cpt){
				nb_fam = cpt;
				printf("Repetition: %d\n", nb_fam);
				numero_seq = i;
				printf("Indice: %d\n", numero_seq);
			}
		}
		cpt = 0;
	}
	char *seq = dist.nom[numero_seq];
	printf("La sequence S est: %s\n", seq);
	printf("La famille est composée de %d séquences.\n", nb_fam);
}

/*FAMILLE construction(DISTANCE dist, FAMILLE fam){
	fam = (char **) malloc(20 * sizeof(char *));
	for(int i = 0; i < 20; i++){
		fam = (char *) malloc(25 * sizeof(char));
	}
	
	int cpt = 0; int final_cpt = 0; int numero_seq;
	fam.Dmin = min;

	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			if(dist.Distance_Finale[i][j] == fam.Dmin){
				cpt++;
			}

			if(final_cpt < cpt){
				final_cpt = cpt;
				numero_seq = i;
			}
		}
		cpt = 0;
	}
	char *seq = dist.nom[numero_seq];
	printf("%s\n", seq);
	printf("%d\n", final_cpt);

	return fam;
}*/

/*void Seq_S(DISTANCE dist){
	int cpt = 0; int final_cpt = 0; int numero_seq;
	float Dmin = distance_min(dist);

	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			if(dist.Distance_Finale[i][j] == Dmin){
				cpt++;
			}

			if(final_cpt < cpt){
				final_cpt = cpt;
				numero_seq = i;
			}
		}
		cpt = 0;
	}
	char *seq = dist.nom[numero_seq];
	printf("%s\n", seq);
	printf("%d\n", final_cpt);
}

void fam(DISTANCE dist){
	char **tableaurandom;
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			if(dist.Distance_Finale[i][j] == Dmin){
				tableaurandom[i] = dist.nom[j]
			}
		}
	}
}*/