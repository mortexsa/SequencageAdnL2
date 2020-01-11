#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "distance.h"

DISTANCE Recherche_fichiers(char *name){
	DISTANCE dist;
	DIR* D;
	D = opendir(name);

	dist.nom = (char **)malloc(20 * sizeof(char *)+1);
	for(int j = 0; j < 20; j++){
		dist.nom[j] = (char *)malloc(25 * sizeof(char)+1);
	}

	if(D == NULL)
		exit(1);
	else
		printf("Le dossier à bien été ouvert.\n");

	struct dirent *sd;
	sd = readdir(D);
	int i = 0;

	while(sd != NULL && i < 20){
		if(strcmp(sd->d_name, ".") != 0 && strcmp(sd->d_name, "..") != 0){
			sprintf(dist.nom[i], "%s/%s", name, sd->d_name);
			i++;
		}
		sd = readdir(D);
	}

	printf("i = %d\n", i);
	closedir(D);

	return dist;
}



void comparaison(DISTANCE *dist, SEQUENCE lire, SEQUENCE lire2){

	float tableau[5][5] = {{0, 2, 1, 2, 1.5}, {2, 0, 2, 1, 1.5}, {1, 2, 0, 2, 1.5}, {2, 1, 2, 0, 1.5}, {1.5, 1.5, 1.5, 1.5, 0}};
	
	float **stick;

	dist->Distance_Finale = (float **) malloc(20 * sizeof(float *));
	for(int i = 0; i < 20; i++){
		dist->Distance_Finale[i] = (float *) malloc(20 * sizeof(float));
	}
	int a, b, compteur = 0;
	for(a = 0; a < 20; a++){

		lire = lire_fichier(dist->nom[a]);

		for(b = a; b < 20; b++){
			lire2 = lire_fichier(dist->nom[b]);
			stick = (float**) malloc(lire.taille * sizeof (float*) + 1);

			for(int i=0; i<lire.taille; i++)
			{
				stick[i] = (float *) malloc(lire2.taille * sizeof (float) + 1); //Allocation du stick
				for(int j=0; j<lire2.taille; j++){
    				stick[i][j] = 0; //Initialisation de toutes les valeures à 0
    			}
			}
			
			dist->Distance_Finale[a][b] = calcul_recursive_dist(lire.numerique, lire2.numerique, lire.taille-1, lire2.taille-1, tableau, stick);
			printf("La distance finale est: %.2f\n", dist->Distance_Finale[a][b]);
			compteur++;
		}
	}

	printf("haha: %d\n", compteur);
}

