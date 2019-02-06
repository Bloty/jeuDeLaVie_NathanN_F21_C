#ifndef TABLEAU_H_INCLUDED
#define TABLEAU_H_INCLUDED
#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX 25
#define MIN 0
#define CELLVIVANTE 'o'
#define CELLMORTE ' '

typedef enum etatCell{vivante,morte,naissente,mourante}etatCell;

//Enregistrement-------------------------------------------------------
typedef struct tCellule{
    etatCell etat;
    char cEtat;
}tCellule;


//Prototype------------------------------------------------------------
extern void initTab(tCellule cTab[MAX][MAX]);
extern void affichage(tCellule cTab[MAX][MAX]);
extern void scan(tCellule cTab[MAX][MAX]);
extern void changeSigne(tCellule cTab[MAX][MAX]);

#endif // TABLEAU_H_INCLUDED
