#include "machine.h"
#include "connexion.h"
#include <stdint.h>

#ifndef RESEAU_H
#define RESEAU_H


typedef struct Reseau {
  uint16_t nb_machines; // Ordre
  uint16_t machines_capacite; // Capacité initiale de machines
  Machine* machines;  // Tableau contenant les machines
  Connexion* connexions; // Arêtes
  uint16_t nb_connexions; // Nombre d'arêtes
  uint16_t connexions_capacite; // Capacité du tableau de connexions
} Reseau;

void init_reseau(Reseau* reseau);
void deinit_reseau(Reseau* reseau);
uint16_t nb_machines(Reseau* reseau);
uint16_t nb_connexions(Reseau* reseau);
uint16_t index_machine(Reseau* reseau, machine_t machine);
void ajouter_machine(Reseau* reseau, Machine machine);
void ajouter_connection(Reseau* reseau, Connexion connexion);
void afficher_reseau(Reseau* reseau);

#endif