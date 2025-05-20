#include "machine.h"

#ifndef RESEAU_H
#define RESEAU_H


typedef struct Reseau {
  Machine * machines;
} Reseau;

void initReseau(Reseau* reseau);
void deinitReseau(Reseau* reseau);

#endif