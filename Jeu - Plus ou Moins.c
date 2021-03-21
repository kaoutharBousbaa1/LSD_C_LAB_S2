#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int NombreMystere = 0, NombreChoisi = 0, ContinuerPartie = 0, NiveauDifficulte = 0, MAX = 0, coups = 0;
    const int MIN = 1;
do
{
    do 
  {
      printf("**********Choisissez le niveau de difficulté**********\n");
      printf("1. Easy\n");
      printf("2. Medium\n");
      printf("3. Hard\n");
      scanf("%d\n",&NiveauDifficulte);
      
      switch(NiveauDifficulte):
      {
          case 1:
            MAX = 10;
            break;
          case 2:
            MAX = 100;
            break;
          case 3:
            MAX =1000;
            break;
          default:
            printf("Niveau non reconnu. Je choisi pour vous le niveau 2 (entre 1 et 100)\n");
            MAX = 100;
      }

      srand(time(NULL));
      NombreMystere = (rand() % (MAX - MIN +1)) + MIN;
      printf("Quel est le nombre? ");
      scanf("%d\n", &NombreChoisi);
      
      if (NombreMystere > NombreChoisi) 
      {
          printf("C'est plus!\n");
          coups++;
      }
      else if(NombreMystere < NombreChoisi) 
      {
          printf("C'est moins!\n");
          coups++;
      }
      else
      {
          printf("Bravo!! Vous avez trouvez le nombre mystere! avec un nombre des coups %d\n",&coups);
          printf("Voulez-vous continuer?(0/1)");
          scanf("%d\n", &ContinuerPartie);
      }
      
  }while(NombreChoisi != NombreMystere);

} while (ContinuerPartie != 0);
       
  return 0;
}

