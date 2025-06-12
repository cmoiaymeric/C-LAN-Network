#include "stp_god_mode.h"

void trier_aretes(arete *aretes_triees, graphe const *g, double const *poids_arete)
{
    int nb_aretes = g->nb_aretes;
    int indices[nb_aretes];

    // Initialiser les indices
    for (int i = 0; i < nb_aretes; i++) {
        indices[i] = i;
    }

    // Tri 
    for (int i = 0; i < nb_aretes - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < nb_aretes; j++) {
            if (poids_arete[indices[j]] < poids_arete[indices[min_index]]) {
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
        aretes_triees[i] = g->aretes[indices[i]];
    }
}

void dijkstra_arbre_recouvrement(Reseau* reseau_original, machine_t racine, Reseau* reseau_arbre)
{
    
}