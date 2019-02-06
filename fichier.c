#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

//ecrire_Fichier----------------------------------------------------
//But : Ecrire le nombre de cellule vivant et morte dans un fichier
//Entrer : tableau de stucture+ fichier
//Sortie : fichier modifier
//-----------------------------------------------------------
void ecrire_Fichier(tCellule cTab[MAX][MAX], FILE*fichier)
{
    int nX=0, nY=0, cellViv=0, cellMorte=0;
    char cCellVivante[50],cCellMorte[50];

    for (nY=MIN;nY<MAX;nY++)
    {
        for (nX=MIN;nX<MAX;nX++)
        {
            if(cTab[nX][nY].cEtat==CELLVIVANTE)
            {
                cellViv++;
            }
            else
            {
                cellMorte++;
            }
        }
    }

    sprintf(cCellVivante, "%d", cellViv); //transtypage
    sprintf(cCellMorte, "%d", cellMorte);

    if ((fichier = fopen("nbCell.txt", "w"))==NULL)
    {
        perror("Erreur de creation de fichier");
    }else
    {
        fputs("Cellule vivante : ", fichier);
        fputs(cCellVivante, fichier);
        fputs("\nCellule morte : ", fichier);
        fputs(cCellMorte, fichier);
    }
    fclose(fichier);
}

//lire----------------------------------------------------
//But : lire le ficher
//Entrer : fichier
//Sortie : Ecrire le fichier
//-----------------------------------------------------------
void lire(FILE* fichier)
{
    char chaine[100] = "";

    if ((fichier = fopen("nbCell.txt", "r")) != NULL)
    {
        while (fgets(chaine, 100, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
        }

        fclose(fichier);
    }
}
