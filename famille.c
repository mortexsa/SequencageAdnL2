#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
//#include "famille.h"
#include "sequence.h"

char nom[20][25];

/*void machin(char *name)
{
    DIR*  D ;
  
     D = opendir(name);  // ouverture d'un dossier
       
   if(D == NULL)  // si le dossier n'a pas pu etre ouvert
         exit(1);
    else
    printf("Le dossier a été ouvert avec succes !\n");
   struct dirent* sd ;//declaration d'un pointeur vers la structure dirent
   sd = readdir(D);  // on lit le premier repertoire du dossier
  int i = 0;
  while(sd  != NULL && i < 20)
  {
    if(strcmp(sd->d_name, ".") != 0 && strcmp(sd->d_name, "..") != 0){
      sprintf(nom[i],"%s/%s", name, sd->d_name);
      i++;
    }
    sd = readdir(D);
  }
  printf("i = %d\n", i);
  closedir(D);
}
*/

int main()
{
  /*machin("sequences_ADN");
  SEQUENCE lire, lire2;
  int a, b;
  float Distance_Finale;

  for(a = 0; a < 20; a++){
    lire = lire_fichier(nom[a]);
    lire.sequence[lire.taille] = '\0';
    printf("%s\n", lire.sequence);

    for(b = 0; b < 20; b++){
      lire2 = lire_fichier(nom[b]);
      lire.sequence[lire.taille] = '\0';
      printf("haha: %s\n", lire2.sequence);
      calcul_distances(lire.t)
      printf("%.2f\n", Distance_Finale);
    }
  }

  return 0;
}*/