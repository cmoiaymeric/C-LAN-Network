#include "connexion.h"
#include <stdio.h>

/**
 * @brief Affiche les informations d'une connexion entre deux machines.
 *
 * Cette fonction affiche l'identifiant des deux machines reliées ainsi que le poids de la connexion,
 * qui peut représenter une distance, un coût, ou une autre métrique selon le contexte.
 *
 * @param connexion La structure Connexion contenant les informations sur la connexion,
 *        notamment les identifiants des deux machines et le poids de leur liaison.
 */
void afficher_connexion(Connexion connexion) {
    printf("Connection : %d  <-->  %d\t", connexion.machine_1, connexion.machine_2);
    printf("Poids : %d\n", connexion.poids);
}

Connexion connexion_inverse(Connexion connexion) {

}
bool connexion_egale(Connexion c1, Connexion c2) {
    if ((c1.machine_1 == c2.machine_1 && c1.machine_2 == c2.machine_2) && c1.poids == c2.poids) {
        return true;
    }
    // Pas sur de ça, mais on vérifie aussi l'inverse
    if ((c1.machine_1 == c2.machine_2 && c1.machine_2 == c2.machine_1) && c1.poids == c2.poids) {
        return true;
    }
    return false;
}