#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "distance.h"
#include "sequence.h"
#include <dirent.h>

char nom[20][25];
float **stick;

void Recherche_fichiers(char *name){
	DIR* D;
	D = opendir(name);

	if(D == NULL)
		exit(1);
	else
		printf("Le dossier à bien été ouvert.\n");

	struct dirent *sd;
	sd = readdir(D);
	int i = 0;

	while(sd != NULL && i < 20){
		if(strcmp(sd->d_name, ".") != 0 && strcmp(sd->d_name, "..") != 0){
			sprintf(nom[i], "%s/%s", name, sd->d_name);
			printf("%s\n", nom[i]);
			i++;
		}
		sd = readdir(D);
	}
	printf("i = %d\n", i);
	closedir(D);
}

void comparaison(){

	SEQUENCE lire, lire2;
	int a, b;
	float Distance_Finale;

	float tableau[5][5] = {{0, 2, 1, 2, 1.5}, {2, 0, 2, 1, 1.5}, {1, 2, 0, 2, 1.5}, {2, 1, 2, 0, 1.5}, {1.5, 1.5, 1.5, 1.5, 0}};

	for(a = 0; a < 20; a++){
		lire = lire_fichier(nom[a]);
		lire.sequence[lire.taille] = '\0';
		stick = (float**) malloc(lire.taille * sizeof (float*) + 1);

		for(b = 0; b < 20; b++){
			lire2 = lire_fichier(nom[b]);
			lire2.sequence[lire.taille] = '\0';
			allocation(lire, lire2);
			Distance_Finale = calcul_recursive_dist(lire.numerique, lire2.numerique, lire.taille-1, lire2.taille-1, tableau, stick);
			printf("La distance finale est: %.2f\n", Distance_Finale);
		}
	}

}

