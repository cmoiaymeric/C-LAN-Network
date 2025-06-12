#pragma once
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "reseau.h"
#include "machine.h"

// Structure pour stocker les informations de Dijkstra
typedef struct {
    uint32_t distance;      // Distance minimale depuis la racine
    machine_t precedent;    // Machine précédente dans le chemin optimal
    int visite;           // Indique si la machine a été visitée
} InfoDijkstra;

Reseau* dijkstra_arbre_recouvrement(Reseau* reseau_original, machine_t racine);