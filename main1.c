#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"

int main(){

	SEQUENCE Lire = lire_fichier("sequences_ADN/seq01.txt");
	SEQUENCE Lire2 = lire_fichier("sequences_ADN/seq02.txt");
	printf("i=%d ; j=%d\n",Lire.taille,Lire2.taille );
	/*int tab1[4] ={0,1,2,3};
    int tab2[3] ={0,2,0};*/
	float tableau[5][5] = {{0, 2, 1, 2, 1.5}, {2, 0, 2, 1, 1.5}, {1, 2, 0, 2, 1.5}, {2, 1, 2, 0, 1.5}, {1.5, 1.5, 1.5, 1.5, 0}};
	/*int time = 0;   
	float jjj2 = calcul_prov(Lire.sequence,Lire2.sequence,Lire.taille-1,Lire2.taille-1,tableau);
	printf("resultat : %f\n", jjj2);
	time = clock();
    printf("Temps d'execution = %d ms\n", time);
   */
	int time2 = 0;   
	float ** stick = (float**) malloc(Lire.taille * sizeof (float*) + 1);
	for (int i=0; i<Lire.taille; i++)
	{
		stick[i] = (float*) malloc (Lire2.taille * sizeof (float) + 1);
	}
	for(int i=0; i<Lire.taille; i++){
    	for(int j=0; j<Lire2.taille; j++){
    		stick[i][j] = 0;
    	}
    }
	float jjj = calcul_test(Lire.numerique,Lire2.numerique,Lire.taille-1,Lire2.taille-1,tableau,stick);
	printf("resultat : %.2f\n", jjj);
	time2 = clock();
    printf("Temps d'execution = %d ms\n", time2/*-time*/);
    for(int i=0; i<Lire.taille; i++){
    	for(int j=0; j<Lire2.taille; j++){
    		printf("%.0f ", stick[i][j]);
    	}
    	printf("\n");
    }
	//printf("transform : %d\n", transforme(Lire.sequence[2]));
	return 0;
}