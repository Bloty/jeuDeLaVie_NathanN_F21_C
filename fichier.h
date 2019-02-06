#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"

#define CELLVIVANTE 'o'
#define CELLMORTE ' '

extern void ecrire_Fichier(tCellule cTab[MAX][MAX], FILE*fichier);
extern void lire(FILE* fichier);


#endif // FICHIER_H_INCLUDED
