#include "reseau.h"
#include "machine.h"
#include "connexion.h"
#include "trame.h"
#include "type.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Initialise un réseau avec des capacités initiales pour machines et connexions.
 * 
 * @param reseau Pointeur vers la structure Reseau à initialiser
 */
void init_reseau(Reseau* reseau) {

    reseau->nb_machines = 0;    // Pas de machines par défaut

    reseau->machines_capacite = 8;  // Initialisation avec une capacité de 8 machines

    reseau->machines = malloc(sizeof(Machine) * reseau->machines_capacite);     // Initialisation du tableau de machines

    reseau->connexions_capacite = 8; // Capacité initiale pour les connexions

    reseau->connexions = malloc(sizeof(Connexion) * reseau->connexions_capacite);   // Initialisation du tableau des connections entre machines

    reseau->nb_connexions = 0;  // Pas de connections par défaut
}

/**
 * @brief Libère la mémoire allouée pour le réseau et ses machines.
 * 
 * @param reseau Pointeur vers la structure Reseau à désinitialiser
 */
void deinit_reseau(Reseau* reseau) {
    free(reseau->machines);
    free(reseau->connexions);
    
    reseau->machines = NULL;
    reseau->connexions = NULL;
    reseau->nb_machines = 0;
    reseau->nb_connexions = 0;
    reseau->machines_capacite = 0;
    reseau->connexions_capacite = 0;
}
void deinit_reseau_complet(Reseau* reseau) {
    // Libération mémoire des machines internes (chaque case du tableau)
    for(uint16_t i = 0; i < reseau->nb_machines; i++) {
        if (reseau->machines[i].type_machine == TypeStation) {
            free((Station*)reseau->machines[i].machine);
        }
        else if (reseau->machines[i].type_machine == TypeSwitch) {
            // CORRECTION: Libérer d'abord la table de commutation
            Switch* sw = (Switch*)reseau->machines[i].machine;
            free(sw->table_commutation.entrees);
            free(sw);
        }
    }
    //libération du tableau
    free(reseau->machines);
    free(reseau->connexions);
    
    reseau->machines = NULL;
    reseau->connexions = NULL;
    reseau->nb_machines = 0;
    reseau->nb_connexions = 0;
    reseau->machines_capacite = 0;
    reseau->connexions_capacite = 0;
}

/**
 * @brief Renvoie le nombre de machines dans le réseau.
 * 
 * @param reseau Pointeur vers la structure Reseau
 * @return uint16_t Nombre de machines
 */
uint16_t nb_machines(Reseau* reseau) {
    return reseau->nb_machines;
}

/**
 * @brief Renvoie le nombre de connexions dans le réseau.
 * 
 * @param reseau Pointeur vers la structure Reseau
 * @return uint16_t Nombre de connexions
 */
uint16_t nb_connexions(Reseau* reseau) {
    return reseau->nb_connexions;
}

/**
 * @brief Vérifie si l'indice de machine est valide dans le réseau.
 * 
 * @param reseau Pointeur vers la structure Reseau
 * @param machine Indice de la machine à vérifier
 * @return uint16_t Indice valide ou UINT16_MAX si invalide
 */
uint16_t index_machine(Reseau* reseau, machine_t machine) {
    
    if(machine < reseau->nb_machines){ 
        return machine;
    }
    return UINT16_MAX;
}

/**
 * @brief Vérifie si une connexion existe dans le réseau.
 * 
 * @param reseau Pointeur vers la structure Reseau
 * @param connexion Connexion à rechercher
 * @return int 1 si la connexion existe, 0 sinon
 */
int existe_connexion(Reseau* reseau, Connexion connexion) {
    for (int i = 0; i < reseau->nb_connexions; i++){
        if ((reseau->connexions[i].machine_1 == connexion.machine_1 && reseau->connexions[i].machine_2 == connexion.machine_2) || (reseau->connexions[i].machine_1 == connexion.machine_2) && reseau->connexions[i].machine_2 == connexion.machine_1){
            return 1;
        }
    }
    return 0;
}



/**
 * @brief Ajoute une machine au réseau, en doublant la capacité si nécessaire.
 * 
 * @param reseau Pointeur vers la structure Reseau
 * @param machine Machine à ajouter
 */
void ajouter_machine(Reseau* reseau, Machine machine) {
    if (reseau->nb_machines >= reseau->machines_capacite ) {    // Si on est arrivé à la capacité max de machines
        reseau->machines_capacite *= 2;     // On double la capacité max de machines
        reseau->machines = realloc(reseau->machines, sizeof(Machine) * (reseau->machines_capacite)); // On réalloue le tableau
    }
    reseau->machines[reseau->nb_machines] = machine;
    reseau->nb_machines++;
}

/**
 * @brief Ajoute une connexion au réseau, en doublant la capacité si nécessaire.
 * 
 * @param reseau Pointeur vers la structure Reseau
 * @param connexion Connexion à ajouter
 */
void ajouter_connection(Reseau* reseau, Connexion connexion) {
    if (reseau->nb_connexions >= reseau->connexions_capacite) {     // Si on est arrivé à la capacité max de connections
        reseau->connexions_capacite *= 2;       // On double la capacité max de connections
        reseau->connexions = realloc(reseau->connexions, sizeof(Connexion) * reseau->connexions_capacite); // On réalloue le tableau
    }
    reseau->connexions[reseau->nb_connexions] = connexion;
    reseau->nb_connexions++;
}


/**
 * @brief Affiche les informations sur les machines et connexions du réseau.
 * 
 * @param reseau Pointeur vers la structure Reseau à afficher
 */
void afficher_reseau(Reseau *reseau) {
    printf("*** Affichage du réseau ***\n\nNombre de machines = %u, Nombre de connexions = %u", reseau->nb_machines, reseau->nb_connexions);
    for (uint16_t i=0; i< reseau->nb_machines; i++) {
        printf("\n==================================================================================\n[%u]\t",i);
        afficher_machine(reseau->machines[i]);
        printf("\tDegré : %u",degre_machine(reseau, i));
    }
    printf("\n==================================================================================\n");

    for (uint16_t i=0; i< reseau->nb_connexions; i++) {
        printf("[%u]\t",i);
        afficher_connexion(reseau->connexions[i]);
        printf("==========================================\n");
    }

}

machine_t get_machine_par_mac(Reseau* reseau, Mac mac) {
    for (machine_t m=0; m<reseau->nb_machines; m++) {
        if (comparer_mac_machine(reseau->machines[m], mac)) {
            return m;
        }
    }
    return 0;
}

machine_t degre_machine(Reseau *reseau, machine_t machine) {
    machine_t deg = 0;
    for (uint16_t i=0; i< reseau->nb_connexions; i++) {
        Connexion c = reseau->connexions[i];
        if (c.machine_1 == machine || c.machine_2 == machine) {
            deg++;
        }
    }
    return deg;
}

void machines_connectees(Reseau *reseau, machine_t machine, machine_t* connectees) {
    uint16_t nb=0;
    for (uint16_t i=0; i< reseau->nb_connexions; i++) {
        Connexion c = reseau->connexions[i];
        if (c.machine_1 == machine) {
            connectees[nb] = c.machine_2;
            nb++;
        }
        else if (c.machine_2 == machine) {
            connectees[nb] = c.machine_1;
            nb++;
        }
    }
}

void def_priorite_switch(Reseau *reseau, machine_t machine, uint16_t priorite) {
    if (reseau->machines[machine].type_machine == TypeSwitch)
        ((Switch*)reseau->machines[machine].machine)->priorite = priorite;
}

machine_t get_switch_racine(Reseau *reseau) {
    machine_t racine = -1;
    uint16_t priorite_max = 0;
    Mac mac;

    for (machine_t s = 0; s < reseau->nb_machines; s++) {
        if (reseau->machines[s].type_machine == TypeSwitch) {
            Switch* sw = (Switch*)reseau->machines[s].machine;

            if (sw->priorite > priorite_max) {
                priorite_max = sw->priorite;
                mac = sw->adresse_mac;
                racine = s;

            } else if (sw->priorite == priorite_max) {
                if (mac_est_plus_petite(sw->adresse_mac, mac)) {
                    mac = sw->adresse_mac;
                    racine = s;
                }
            }
        }
    }

    return racine;
}




void transfert_trame(Reseau *reseau, Trame trame, machine_t passerelle, machine_t ancien) {
    trame.TTL--;
    bool continuer = true;
    char* macString = malloc(18);

    // Affichage de la machine suivante dans la chaîne de transfert (décommenter pour afficher le test)
    /*
    char* mac_str_passerelle = malloc(18);
    mac_to_string(get_mac(reseau->machines[passerelle]), mac_str_passerelle);
    printf("\n");
    printf("adresse MAC passerelle (prochaine étape) : %s\n", mac_str_passerelle);
    printf("\n");
    free(mac_str_passerelle);
    mac_str_passerelle = NULL;
    */

    if (comparer_mac_machine(reseau->machines[passerelle], trame.addrDestination)) {  
        recevoir_trame(reseau, trame, passerelle, ancien);
        continuer=false;
    }
    else if (trame.TTL <= 0) {
        printf("%s : Le TTL de la trame est de 0, je détruit\n", mac_to_string(get_mac(reseau->machines[passerelle]), macString));
        continuer=false;
    }
    else {
        if (ancien != UINT16_MAX)
            ajouter_commutation(&reseau->machines[passerelle], trame.addrSource, ancien);
    }   
    if (continuer) {

        uint16_t index_commutation = get_index_commutation(&reseau->machines[passerelle], trame.addrDestination);
        if (index_commutation != UINT16_MAX) {
            uint16_t prochain = ((Switch*)reseau->machines[passerelle].machine)->table_commutation.entrees[index_commutation].port;
            printf("%s (%u) : Je fais passer une trame venant de %u, commutation vers %u\n",mac_to_string(get_mac(reseau->machines[passerelle]), macString), passerelle, ancien, prochain);
            transfert_trame(reseau, trame, prochain, passerelle);
        }
        else {
            uint16_t deg = degre_machine(reseau, passerelle);
            machine_t connectees[deg];
            machines_connectees(reseau, passerelle, connectees);
            if (1 != comparer_mac_machine(reseau->machines[passerelle], trame.addrSource))
                printf("%s (%u) : Je fais passer une trame venant de %u, à mes %u voisins en broadcast, \n",mac_to_string(get_mac(reseau->machines[passerelle]), macString), passerelle, ancien, deg-1);
            for (uint16_t i=0; i<deg; i++) {
                if (connectees[i] != ancien)
                    transfert_trame(reseau, trame, connectees[i], passerelle);
            }
        }
    }
    free(macString);
}


void envoyer_trame(Reseau *reseau, Trame trame) {
    char* mac_string_src = malloc(18);
    char* mac_string_dest = malloc(18);
    printf("\n%s : Envoi d'une trame vers %s contenant '%s'\n", mac_to_string(trame.addrSource, mac_string_src), mac_to_string(trame.addrDestination, mac_string_dest),trame.data);
    free(mac_string_src);
    free(mac_string_dest);
    mac_string_src = NULL;
    mac_string_dest = NULL;

    machine_t passerelle = get_machine_par_mac(reseau, trame.addrSource);
    transfert_trame(reseau, trame, passerelle, UINT16_MAX);
}

void recevoir_trame(Reseau *reseau, Trame trame, machine_t destination, machine_t ancien) {
    char* macString = malloc(18);
    printf("%s : J'ai reçu un message venant de %u ! '%s'\n", mac_to_string(get_mac(reseau->machines[destination]),macString), ancien, trame.data);
    if (trame.type == ICMP_REQUEST) {
        Trame reponse;
        init_trame(&reponse, &trame.addrDestination, &trame.addrSource, ICMP_REPLY, "echo reply");
        envoyer_trame(reseau, reponse);
        deinit_trame(&reponse);
    }

    free(macString);
}

void envoyer_ping(Reseau* reseau, Mac source, Mac destination) {
    Trame trame;
    init_trame(&trame, &source, &destination, ICMP_REQUEST, "echo request");
    envoyer_trame(reseau, trame);
    deinit_trame(&trame);
}