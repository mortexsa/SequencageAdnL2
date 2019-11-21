#ifndef __SEQUENCE_H
#define __SEQUENCE_H

struct Sequence{
	char *sequence;
	int taille;
};
typedef struct Sequence SEQUENCE;

SEQUENCE lire_fichier(char *fichier);
void calcul_distances(SEQUENCE lire, SEQUENCE lire2);

#endif