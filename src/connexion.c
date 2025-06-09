#include "connexion.h"
#include <stdio.h>
#include <stdlib.h>

void afficher_connexion(Connexion connexion) {
    printf("Connection : %d  -->  %d\t", connexion.machine_1, connexion.machine_2);
    printf("Poids : %d\n", connexion.poids);
}