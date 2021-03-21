#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char lireCaractere()
{
    char caractere = 0;
    caractere = getchar();
    caractere = toupper(caractere);
    while(getchar() != '\n');
    return caractere;
}
int rechercheLettre(char caractereEntre, char motCache[], int lettresTrouvees[])
{
    for(int i = 0; motCache[i] != '\0'; i++))
    {
        if(caractereEntre = motCache[i])
        {
            lettresTrouvees[i] = 1;
            return 1;
        }
    }
    return 0;
}
int gagne(int lettresTrouvees[])
{
    int j = 1;
    for(int i = 0; i<6; i++)
    {
        if(lettresTrouvees[i] == 0)
        {
            j = 0;
        }
    }
    return j;
}
int main(int argc, char *argv[])
{
    int coups = 10;
    char motCache[] = "MARRON";
    char caractereEntre = 0;
    int lettresTrouvees[6] = {0};
    int i = 0;
    printf("====================Bienvenue dans le Pendu !====================\n\n");
    printf("Il vous reste %d coups à jouer\n", coups);
    printf("Quel est lemot secret?\n");
    while(coups>0 && !gagner(lettresTrouvees))
    {
        printf("Proposez une lettre : ");
        caractereEntre = lireCaractere();
        if(!rechercheLettre(caractereEntre, motCache, lettresTrouvees))
            coups--;
        for(i =0; i<6; i++)
        {
            if(lettresTrouvees[i])
                printf("%c",&motCache[i]);
            else
                printf("*");
        }

    }
    if(gagne(lettresTrouvees))
        printf("\n\nGagne! le mot secret etait bien : %s", motCache);
    else    
        printf("\\Perdu! Le mot secret etait : %s", motCache);
     return 0;
}