#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sequence.h"

float DF;

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
	else
		return four;
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

	DF = 0;
	for(int cpt = 0; cpt<min; cpt++){
		printf("meow: %d\n", tableau[valeur(lire, cpt)][valeur(lire2, cpt)]); //Distance entre chaque caractères
		DF += tableau[valeur(lire, cpt)][valeur(lire2, cpt)];
	}
	DF += dist_blanc;
	printf("meow blanc: %f\n", dist_blanc);
	printf("meow final: %f\n", DF); //Distance finale première méthode

}

int min(int a, int b, int c){
	if(a==b && a==c)
		return a;
	if(a<b && a<c)
		return a;
	if(b<a && b<c)
		return b;
	else
		return c;
}

/*void calcul_distances2(SEQUENCE lire, SEQUENCE lire2){

	int tableau[4][4] = {{0, 2, 1, 2}, {2, 0, 2, 1}, {1, 2, 0, 2}, {2, 1, 2, 0}};
	printf("meow: %d\n", tableau[valeur(lire, lire.taille)][valeur(lire2, lire2.taille)]);
	float distance_rec;
	float f = 1.5;

	if(distance_rec < DF){
		return distance_rec;
	}
	else
		return min(calcul_distances2(lire, lire2) + tableau[valeur(lire, lire.taille)][valeur(lire2, lire2.taille)],
			calcul_distances2(lire, lire2) + f,
			calcul_distances2(lire, lire2) + f);

}*/

int transforme(char t){ //Fonction pour renvoyer une valeur selon le char trouvé
	if(t == 'A')
		return 0;
	if(t == 'C')
		return 1;
	if(t == 'G')
		return 2;
	if(t == 'T')
		return 3;
	else
		return 4;
}

float calcul_prov(char * v, char * w, int i, int j) {
	float tableau[5][5] = {{0, 2, 1, 2, 1.5}, {2, 0, 2, 1, 1.5}, {1, 2, 0, 2, 1.5}, {2, 1, 2, 0, 1.5}};
	if(i<=0 && j<=0) return 0;
	return min(
			calcul_prov(v,w,i-1,j-1) + tableau[transforme(v[i])][transforme(w[j])],
			calcul_prov(v,w,i,j-1) + tableau[transforme(v[i])][4],
			calcul_prov(v,w,i-1,j) + tableau[4][transforme(w[j])]
			);
}
