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

void calcul_distances(SEQUENCE lire, SEQUENCE lire2)
{
	
	enum InitSeq {A = 0, C = 1, G = 2, T = 3, Vide = 4};
	enum InitContenu {Z = 0, U = 1, D = 2};

	const float F = 1.5;

	float tableau[5][5] = {{Z, D, U, D, F}, {D, Z, D, U, F}, {U, D, Z, D, F}, {D, U, D, Z, F}, {F, F, F, F, Z}};

	lire.sequence = malloc(lire.taille * sizeof(char));
	lire2.sequence = malloc(lire2.taille * sizeof(char));

	strcmp(lire.sequence, lire2.sequence);

	int max;
	if(lire.taille > lire2.taille)
		max = lire.taille;
	else
		max = lire2.taille;

	for(int cpt = 0; cpt<max; cpt++){

		printf("meow: %f\n", tableau[lire.sequence[cpt]][lire2.sequence[cpt]]);
	}






	//a toi de voir ce que tu veut rajouter ici, ton while est useless mon frere

	//utilise %f pour afficher les float, et pour comparer deux sequence, tu doit strcmp les deuc chaine,
	//donc lire.sequence et lire2.sequence un truc comme ca, j'ai pas regarder ta structure
	


	/*while(strcmp(fichier1, fichier2) == 0){
		printf("C'est: %f\n", tableau[A][A]);
	}*/
}