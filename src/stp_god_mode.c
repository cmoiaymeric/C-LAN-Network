#include "stp_god_mode.h"
#include "connexion.h"

void trier_connexions(Connexion *aretes_triees, Reseau* const g)
{
    int nb_aretes = g->nb_connexions;
    int indices[nb_aretes];

    // Initialiser les indices
    for (int i = 0; i < nb_aretes; i++) {
        indices[i] = i;
    }

    // Tri 
    for (int i = 0; i < nb_aretes - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < nb_aretes; j++) {
            if (g->connexions[indices[j]].poids < g->connexions[indices[min_index]].poids) {
                min_index = j;
            }
        }
        // change des indices
        if (min_index != i) {
            int temp = indices[i];
            indices[i] = indices[min_index];
            indices[min_index] = temp;
        }
    }

    // Remplir aretes_triees avec les aretes triees
    for (int i = 0; i < nb_aretes; i++) {
        aretes_triees[i] = g->connexions[indices[i]];
    }
}

void dijkstra_arbre_recouvrement(Reseau* reseau_original, machine_t racine, Reseau* reseau_arbre)
{
    Connexion* connexions_tri = malloc(sizeof(Connexion) * reseau_original->nb_connexions);
    trier_connexions(connexions_tri, reseau_original);

    for (machine_t m=0; m< reseau_original->nb_machines; m++) {
        ajouter_machine(reseau_arbre, reseau_original->machines[m]);
    }

    

    free(connexions_tri);
}