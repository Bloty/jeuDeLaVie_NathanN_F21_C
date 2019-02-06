#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "tableau.h"
#include "figure.h"
#include "fichier.h"

#define VITESSE 100




//Programme principale-------------------------------------------------
int main()
{
    tCellule cTab[MAX][MAX];
    int nI=0, nChoix=0, nIterMax=0;
    FILE* fichier = NULL;

    initTab(cTab);

    printf("--JEU DE LA VIE--\n\n");


    printf("Enter la figure de votre choix\n\n");
    printf("Entrez 1 pour la grenouille\nEntrez 2 pour la planeur\n");

    scanf("%d",&nChoix);
    fflush(stdin);

    printf("Enter le nombre d'iteration\n");
     scanf("%d",&nIterMax);

    switch(nChoix)
    {
    case 1:
        grenouille(cTab);
        break;
    case 2:
        planeur(cTab);
        break;
    }

    for(nI=0;nI<nIterMax;nI++)
    {
        system("cls");
        scan(cTab);
        changeSigne(cTab);
        affichage(cTab);
        printf("\n");
        Sleep(VITESSE);
    }
    ecrire_Fichier(cTab,fichier);
    lire(fichier);
    return 0;
}
