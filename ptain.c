#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "famille.h"//
# include "dirent.h"




int main(int argc,char ** argv)
{
  /*void seekdir(DIR *D,long pos) positionner dans un tableau*/
  
  DIR*  D ;
  
     D = opendir(argv[1]);  /* ouverture d'un dossier*/
       
   if(D == NULL)  /* si le dossier n'a pas pu etre ouvert*/
         exit(1);
    else
    printf("le dossier est ouvert avec succes\n");
   struct dirent* sd ;/*declaration d'un pointeur vers la structure dirent*/
   sd = readdir(D);  /* on lit le premier repertoire du dossier*/
  char nomfic[128];
  while(sd  != NULL  )
  {      
   if(strcmp(sd->d_name, ".") != 0 && strcmp(sd->d_name, "..") != 0)
        sprintf(nomfic,"%s/%s",argv[1],sd -> d_name);
         printf("nomfic = %s\n",nomfic);
         
         sd = readdir(D);
   
    }
  exit(0);
}