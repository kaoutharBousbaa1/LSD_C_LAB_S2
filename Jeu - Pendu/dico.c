#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "dico.h"

int piocherMot(char *motPioche)
{
    FILE* dico = NULL;
    int nombreMots = 0, numMotChoisi = 0; i = 0;
    int caractereLu = 0;
    dico = fopen("dico.txt", "r"); //on ouvre le dictionnaire en lecture seule
    // On vérifie si on a réeussi à ouvrir le dictionnaire
    if(dico == NULL)
    {
        printf("\n Impossible de charger le dictionnaire de mots");
        return 0;
    }
    do
    {
        caractereLu = fgetc(dico);
        if(caractereLu == '\n')
            nombreMots++;
    } while (caractereLu != EOF);
    numMotChoisi = nombreAleatoire(nombreMots);
    rewind(dico);
    while(numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if(caractereLu == '\n')
            numMotChoisi--;
    }
    fgets(motPioche, 100, dico);
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);
        return 1;
}

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}