#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sequence.h"


SEQUENCE lire_fichier(char *fichier)
{
	SEQUENCE seq;
	seq.taille = 0;
	int c;
	FILE *F = fopen(fichier, "r");
	if (F == NULL)
	{
		fprintf(stderr, "Erreur. Impossible d'ouvrir le fichier"); //Message d'erreur
		exit(1);
	}

	while((c = fgetc(F)) != EOF)
	{
		seq.taille += 1; //Compteur de la taille de la chaine de caractère
	}
	
	seq.sequence = malloc(seq.taille * sizeof(char) + 1);
	
	fseek(F,0,SEEK_SET);

	int cpt = 0;
	while((c = fgetc(F)) != EOF)
	{
		if(c != '\n'){
			seq.sequence[cpt] = c;
			cpt++; //Lecture des caractères
		}
	}

	fclose(F);
	return seq;
}

void calcul_distances(char *fichier1, char *fichier2)
{
	SEQUENCE Lire = lire_fichier(fichier1);
	SEQUENCE Lire2 = lire_fichier(fichier2);

	enum InitSeq {A = 0, C = 1, G = 2, T = 3, Vide = 4};
	enum InitContenu {Z = 0, U = 1, D = 2};

	const float F = 1.5;

	float tableau[5][5] = {{Z, D, U, D, F}, {D, Z, D, U, F}, {U, D, Z, D, F}, {D, U, D, Z, F}, {F, F, F, F, Z}};
	float ValDist;
	while(strcmp(fichier1, fichier2) == 0){
		printf("C'est: %f\n", tableau[A][A]);
	}
}