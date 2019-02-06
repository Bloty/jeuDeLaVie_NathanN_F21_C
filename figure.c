#include "figure.h"
#include <stdio.h>
#include <stdlib.h>

//Figure---------------------------------------------------
void grenouille(tCellule cTab[MAX][MAX])
{
    cTab[0][3].cEtat=CELLVIVANTE;
    cTab[0][3].etat=vivante;
    cTab[3][2].cEtat=CELLVIVANTE;
    cTab[3][2].etat=vivante;
    cTab[1][2].cEtat=CELLVIVANTE;
    cTab[1][2].etat=vivante;
    cTab[2][2].cEtat=CELLVIVANTE;
    cTab[2][2].etat=vivante;
    cTab[1][3].cEtat=CELLVIVANTE;
    cTab[1][3].etat=vivante;
    cTab[2][3].cEtat=CELLVIVANTE;
    cTab[2][3].etat=vivante;
}

void planeur (tCellule cTab[MAX][MAX])
{
    cTab[1][0].cEtat=CELLVIVANTE;
    cTab[1][0].etat=vivante;
    cTab[2][1].cEtat=CELLVIVANTE;
    cTab[2][1].etat=vivante;
    cTab[0][2].cEtat=CELLVIVANTE;
    cTab[0][2].etat=vivante;
    cTab[1][2].cEtat=CELLVIVANTE;
    cTab[1][2].etat=vivante;
    cTab[2][2].cEtat=CELLVIVANTE;
    cTab[2][2].etat=vivante;
}
