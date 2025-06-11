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
    printf("Connection : %d  -->  %d\t", connexion.machine_1, connexion.machine_2);
    printf("Poids : %d\n", connexion.poids);
}