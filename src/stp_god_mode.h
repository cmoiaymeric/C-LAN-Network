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

/**
 * @brief Trie les connexions d'un réseau selon leur poids croissant.
 *
 * Cette fonction parcourt toutes les connexion du réseau donné (représenté par la structure `reseau`)
 * et les trie en fonction des poids fournis dans le tableau `poids_arete`. Le résultat trié
 * est stocké dans le tableau `aretes_triees`.
 *
 * @param[out] aretes_triees
 *      Tableau dans lequel seront stockées les connexions triées. Doit être préalloué avec
 *      au moins autant d'éléments que le nombre total de connexions dans le réseau.
 *
 * @param[in] g
 *      Pointeur constant vers la structure `reseau` représentant le réseau. 
 *      Le réseau contient les sommets et les connexions (arêtes) entre eux.
 *
 * @param[in] poids_arete
 *      Tableau contenant les poids associés à chaque connexion du réseau. Chaque poids
 *      est un entier sur 8 bits non signé (`uint8_t`), et il est supposé qu'il correspond
 *      à l'ordre des connexions dans `g`. Ce tableau doit contenir exactement le même nombre
 *      d'éléments que connexion dans le réseau.
 */
void trier_connexions(Connexion *aretes_triees, reseau const *g, uint8_t *poids_arete);
Reseau* dijkstra_arbre_recouvrement(Reseau* reseau_original, machine_t racine);