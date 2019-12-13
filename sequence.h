#ifndef __SEQUENCE_H
#define __SEQUENCE_H

struct Sequence{
	char *sequence;
	int taille;
};
typedef struct Sequence SEQUENCE;

SEQUENCE lire_fichier(char *fichier);
int valeur(SEQUENCE lire, int truc);
void calcul_distances(SEQUENCE lire, SEQUENCE lire2);
int min(int a, int b, int c);
void calcul_distances2(SEQUENCE lire, SEQUENCE lire2);
int transforme(char t);
float calcul_prov(char * v, char * w, int i, int j);

#endif