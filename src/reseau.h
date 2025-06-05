#include "machine.h"

#ifndef RESEAU_H
#define RESEAU_H


typedef struct Reseau {
  Machine * machines;
} Reseau;

void init_reseau(Reseau* reseau);
void deinit_reseau(Reseau* reseau);

#endif