#pragma once
#include "reseau.h"

#pragma once
#ifndef STP_GOD_MODE_H
#define STP_GOD_MODE_H


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
 *      Pointeur constant vers la structure `reseau ` représentant le réseau. 
 *      Le réseau contient les sommets et les connexions (arêtes) entre eux.
 */
void trier_connexions(Connexion *aretes_triees, Reseau* const g);

void prim_arbre_recouvrement(Reseau* reseau_original, machine_t racine, Reseau* reseau_arbre);

#endif