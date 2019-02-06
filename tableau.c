#include "tableau.h"
#include <stdio.h>
#include <stdlib.h>

//initTab----------------------------------------------------
//But : Initialiser le tableau de stucture
//Entrer : tableau de stucture
//Sortie : tableau de stucture initialiser
//-----------------------------------------------------------
void initTab(tCellule cTab[MAX][MAX])
{
    int nX=0,nY=0;

    for (nX=MIN;nX<MAX;nX++)
    {
        for (nY=MIN;nY<MAX;nY++)
        {
            cTab[nX][nY].cEtat=CELLMORTE;
            cTab[nX][nY].etat=morte;
        }
    }
}


//affichage----------------------------------------------------
//But : afficher le tableau le tableau
//Entrer : tableau de stucture
//Sortie : le tableau afficher
//-----------------------------------------------------------
void affichage(tCellule cTab[MAX][MAX])
{
int nX=0,nY=0;


    for (nX=MIN;nX<MAX;nX++)
    {
        for (nY=MIN;nY<MAX;nY++)
        {
            printf("%c ",cTab[nY][nX].cEtat);
        }
        printf("\n" );
    }
}

//scan----------------------------------------------------
//But : On compte cellule par cellule les nombre de cellule vivant
//      autour d'elle. si elle a 3 cellule vivant autour elle devient naissante,
//      si elle en a + de 3 ou - de 2 elle est mourrante
//Entrer : tableau de stucture
//Sortie : tableau modifier
//-----------------------------------------------------------
void scan(tCellule cTab[MAX][MAX])
{
    int nX=0,nY=0,nZ=0,nI=0,cptVivant=0;

    for (nY=MIN;nY<MAX;nY++)
    {
        for (nX=MIN;nX<MAX;nX++)
        {
            cptVivant=0;
            nI=0;

            for (nZ=0;nZ<3;nZ++)//au nord du point tester
            {
                if (cTab[(nX-1)+nZ][nY-1].cEtat==CELLVIVANTE && ((nX-1)+nZ>=MIN) && ((nX-1)+nZ<=MAX) && (nY-1>=MIN))
                {
                    cptVivant++;
                }
            }

            for (nZ=0;nZ<2;nZ++)//au même niveau du point tester
            {
                if (cTab[(nX-1)+nI][nY].cEtat==CELLVIVANTE && ((nX-1)+nI>=MIN) && ((nX-1)+nI<=MAX))
                {
                    cptVivant++;
                }
                nI+=2;
            }

            for (nZ=0;nZ<3;nZ++)//au sud du point tester
            {
                if (cTab[(nX-1)+nZ][nY+1].cEtat==CELLVIVANTE && ((nX-1)+nZ>=MIN) && ((nX-1)+nZ<=MAX) && (nY+1<=MAX))
                {
                    cptVivant++;
                }
            }

            if((cTab[nX][nY].etat==morte) && (cTab[nX][nY].etat!=vivante) &&(cptVivant==3))
            {
               cTab[nX][nY].etat=naissente;
            }

            if((cTab[nX][nY].etat==vivante) && (cTab[nX][nY].etat!=morte) && (cptVivant<2) || (cptVivant>3))
            {
                cTab[nX][nY].etat=mourante;
            }

        }
   }
}

//changeSigne----------------------------------------------------
//But : changer l'état de la cellule de naissente a vivante et de mourante a morte
//Entrer : tableau de stucture
//Sortie : tableau modifier
//-----------------------------------------------------------
void changeSigne(tCellule cTab[MAX][MAX])
{
    int nX=0,nY=0;

    for (nY=MIN;nY<MAX;nY++)
    {
        for (nX=MIN;nX<MAX;nX++)
        {
            if(cTab[nX][nY].etat==naissente)
            {
                cTab[nX][nY].cEtat=CELLVIVANTE;
                cTab[nX][nY].etat=vivante;
            }
            if (cTab[nX][nY].etat==mourante)
            {
                cTab[nX][nY].cEtat=CELLMORTE;
                cTab[nX][nY].etat=morte;
            }
        }
    }
}
