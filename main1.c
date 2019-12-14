#include <stdio.h>
#include "sequence.h"

int main(){

	SEQUENCE Lire = lire_fichier("sequences_ADN/seq01.txt");
	SEQUENCE Lire2 = lire_fichier("sequences_ADN/seq02.txt");
	printf("i=%d ; j=%d\n",Lire.taille,Lire2.taille );
	int tab1[13] ={3,1,1,3,0,1,3,3,3,3,1,3,1/*,1,1,3,0*/};
    int tab2[14] ={2,3,3,0,3,1,0,0,0,0,0,3,3,1/*,1,3,3,2*/};
	float tableau[5][5] = {{0, 2, 1, 2, 1.5}, {2, 0, 2, 1, 1.5}, {1, 2, 0, 2, 1.5}, {2, 1, 2, 0, 1.5}, {1.5, 1.5, 1.5, 1.5, 0}};
	int time = 0;   
	float jjj = calcul_prov(Lire.sequence,Lire2.sequence,Lire.taille-1,Lire2.taille-1,tableau);
	printf("resultat : %f\n", jjj);
	time = clock();
    printf("Temps d'execution = %d ms\n", time);
   
	int time2 = 0;   
	jjj = calcul_test(tab1,tab2,Lire.taille-1,Lire2.taille-1,tableau);
	printf("resultat : %f\n", jjj);
	time2 = clock();
    printf("Temps d'execution = %d ms\n", time2-time);
	//printf("transform : %d\n", transforme(Lire.sequence[2]));
	return 0;
}