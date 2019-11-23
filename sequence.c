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

int valeur(SEQUENCE truc, int cpt){ //Fonction pour renvoyer une valeur selon le char trouvé
	int zero = 0, one = 1, two = 2, three = 3, four = 4;
	if(truc.sequence[cpt] == 'A')
		return zero;
	if(truc.sequence[cpt] == 'C')
		return one;
	if(truc.sequence[cpt] == 'G')
		return two;
	if(truc.sequence[cpt] == 'T')
		return three;
}

void calcul_distances(SEQUENCE lire, SEQUENCE lire2)
{
	int tableau[4][4] = {{0, 2, 1, 2}, {2, 0, 2, 1}, {1, 2, 0, 2}, {2, 1, 2, 0}}; //Tableau stockant les valeurs possibles de distances

	int min, max;
	if(lire.taille < lire2.taille){
		min = lire.taille;
		max = lire2.taille;
	}
	else{
		min = lire2.taille;
		max = lire.taille; //Chaines min et max
	}
	
	float dist_blanc = (max - min)*1.5; //Calcul distance avec blanc

	float DF = 0;
	for(int cpt = 0; cpt<min; cpt++){
		printf("meow: %d\n", tableau[valeur(lire, cpt)][valeur(lire2, cpt)]); //Distance entre chaque caractères
		DF += tableau[valeur(lire, cpt)][valeur(lire2, cpt)];
	}
	DF += dist_blanc;
	printf("meow blanc: %f\n", dist_blanc);
	printf("meow final: %f\n", DF); //Distance finale

}