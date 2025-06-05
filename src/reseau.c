#include "reseau.h"
#include "machine.h"
#include "connexion.h"

void init_reseau(Reseau* reseau, uint16_t capacite_reseau) {
    reseau->nb_machines = 0;

    reseau->machines = malloc(sizeof(Machine) * 8); // Initialisation avec une capacité de 8 machines

    reseau->connexions_capacite = 8; // Capacité initiale pour les connexions

    reseau->connexions = malloc(sizeof(Connexion) * reseau->connexions_capacite);

    reseau->nb_connexions = 0;
}

void deinit_reseau(Reseau* reseau) {
    reseau->nb_machines = 0;

    free(reseau->machines);
    reseau->machines = NULL;

    reseau->nb_connexions = 0;
    free(reseau->connexions);

    reseau->connexions = NULL;

    reseau->connexions_capacite = 0;
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

// Fonction faites par Copilot, regarder par ici en cas d'erreur
void ajouter_machine(Reseau* reseau, Machine machine) {
    if (reseau->nb_machines >= 8) {
        // Redimensionner le tableau si nécessaire
        reseau->machines = realloc(reseau->machines, sizeof(Machine) * (reseau->nb_machines + 8));
    }
    reseau->machines[reseau->nb_machines++] = machine;
}
