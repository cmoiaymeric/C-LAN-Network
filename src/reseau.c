#include "reseau.h"
#include "machine.h"
#include "connexion.h"
#include <stdlib.h>

void init_reseau(Reseau* reseau) {

    reseau->nb_machines = 0;    // Pas de machines par défaut

    reseau->machines_capacite = 8;  // Initialisation avec une capacité de 8 machines

    reseau->machines = malloc(sizeof(Machine) * reseau->machines_capacite);     // Initialisation du tableau de machines

    reseau->connexions_capacite = 8; // Capacité initiale pour les connexions

    reseau->connexions = malloc(sizeof(Connexion) * reseau->connexions_capacite);   // Initialisation du tableau des connections entre machines

    reseau->nb_connexions = 0;  // Pas de connections par défaut
}

void deinit_reseau(Reseau* reseau) {
    reseau->nb_machines = 0;

    free(reseau->machines);
    reseau->machines = NULL;

    reseau->nb_connexions = 0;
    free(reseau->connexions);

    reseau->connexions = NULL;

    reseau->connexions_capacite = 0;

    free(reseau);
    reseau = NULL;
}

uint16_t nb_machines(Reseau* reseau) {
    return reseau->nb_machines;
}

uint16_t nb_connexions(Reseau* reseau) {
    return reseau->nb_connexions;
}

uint16_t index_machine(Reseau* reseau, machine_t machine) {
    
    if(machine <= reseau->nb_machines){
        return machine;
    }
    return -1;
}

// Retourne 1 si la connexion existe, 0 sinon
int existe_connexion(Reseau* reseau, Connexion connexion) {
    for (int i = 0; i < reseau->nb_connexions; i++){
        if ((reseau->connexions[i].machine_1 == connexion.machine_1 && reseau->connexions[i].machine_2 == connexion.machine_2) || (reseau->connexions[i].machine_1 == connexion.machine_2) && reseau->connexions[i].machine_2 == connexion.machine_1){
            return 1;
        }
    }
    return 0;
}


void ajouter_machine(Reseau* reseau, Machine machine) {
    reseau->nb_machines++;
    if (reseau->nb_machines >= reseau->machines_capacite ) {    // Si on est arrivé à la capacité max de machines
        reseau->machines_capacite *= 2;     // On double la capacité max de machines
        reseau->machines = realloc(reseau->machines, sizeof(Machine) * (reseau->machines_capacite));    // On réalloue le tableau en plus grand
    }
    reseau->machines[reseau->nb_machines] = machine;
}


void ajouter_connection(Reseau* reseau, Connexion connexion) {
    reseau->nb_connexions++;
    if (reseau->nb_connexions >= reseau->connexions_capacite) {     // Si on est arrivé à la capacité max de connections
        reseau->connexions_capacite *= 2;       // On double la capacité max de connections
        reseau->connexions = realloc(reseau->connexions, sizeof(Connexion) * reseau->connexions_capacite);  // On réalloue le tableau en plus grand
    }
    reseau->connexions[reseau->nb_connexions] = connexion;
}