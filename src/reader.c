#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/reader.h"
#include "headers/connexion.h"
#include "headers/machine.h"
#include "headers/type.h"
#include "headers/reseau.h"


#define MAX_STR_LENGTH 128

/**
 * @brief Lit un fichier de configuration et remplit la structure réseau.
 * 
 * Lit le nombre de machines et connexions, puis initialise chaque machine
 * (station ou switch) en fonction des données, et ajoute les connexions.
 * 
 * @param file_name Nom du fichier de configuration à lire
 * @param reseau Pointeur vers la structure réseau à remplir
 */
void read_config_file(char* file_name, Reseau* reseau) {

    char * file_string = NULL;
    
    FILE* input_file = fopen(file_name, "r");

    Mac* adresse_mac = NULL;
    adresse_mac = malloc(sizeof(Mac)); // Pour stocker temporairement une adresse MAC lue
    IP* adresse_ip = NULL;
    adresse_ip = malloc(sizeof(IP)); // Pour stocker temporairement une adresse IP lue

    uint8_t nb_sommets = 0;   // Nombre de machines à lire
    uint8_t nb_aretes = 0;    // Nombre de connexions à lire
    uint8_t type_machine = 0; // Type de machine (switch ou station)
    uint8_t ports = 0;        // Nombre de ports (pour un switch)
    uint16_t priorite = 0;    // Priorité (pour un switch)
    uint16_t s1 = 0;          // Sommet 1 d'une connexion
    uint16_t s2 = 0;          // Sommet 2 d'une connexion
    uint16_t poids = 0;       // Poids de la connexion

    if(input_file == NULL){
        printf("Impossible d'ouvrir le fichier %s\n", file_name);
        exit(-1);
    }

    file_string = (char*) malloc(MAX_STR_LENGTH);  // Buffer pour lire chaque ligne
    // Lecture de la première ligne contenant nb_sommets et nb_aretes
    fgets(file_string, MAX_STR_LENGTH, input_file);

    //Traitement d'une erreur de lecture
    if (ferror(input_file)) {
        fprintf(stderr,"Erreur de lecture du fichier %d\n", errno);
        exit(-1);
    }
    
    //On lit la première ligne pour connaitre le nombre de machines et de connexions
    sscanf(file_string, "%hhd %hhd", &nb_sommets, &nb_aretes);

    for(uint8_t i = 0; i < nb_sommets; i++) {

        fgets(file_string, MAX_STR_LENGTH, input_file);
        //Traitement d'une erreur de lecture
        if (ferror(input_file)) {
            fprintf(stderr,"Erreur de lecture du fichier %d\n", errno);
            break;
            exit(-1);
        }

        Machine* machine = malloc(sizeof(Machine));

        sscanf(file_string, "%hhd", &type_machine);

        if(type_machine == TypeSwitch){

            //Lit la ligne pour la configuration d'un switch
            // type_machine;MAC;nb_ports;priorite
            sscanf(file_string, "%hhd;%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx;%hhd;%hd", &type_machine, &adresse_mac->octets[0], &adresse_mac->octets[1], &adresse_mac->octets[2], &adresse_mac->octets[3], &adresse_mac->octets[4], &adresse_mac->octets[5], &ports, &priorite);
            
            init_switch(machine, *adresse_mac, ports, priorite);
        }
        else{
            //Lit la ligne pour la configuration d'une station
            // type_machine;MAC;IP
            sscanf(file_string, "%hhd;%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx;%hhu.%hhu.%hhu.%hhu", &type_machine, &adresse_mac->octets[0], &adresse_mac->octets[1], &adresse_mac->octets[2], &adresse_mac->octets[3], &adresse_mac->octets[4], &adresse_mac->octets[5], &adresse_ip->octets[0], &adresse_ip->octets[1], &adresse_ip->octets[2], &adresse_ip->octets[3]);
           
            init_station(machine, *adresse_mac, *adresse_ip);
        }
        ajouter_machine(reseau, *machine);
        free(machine);
    }

 // Lecture des connexions (arêtes)
    for(uint8_t i = 0; i < nb_aretes; i++) {
        fgets(file_string, MAX_STR_LENGTH, input_file);
        
        //Traitement d'une erreur de lecture
        if (ferror(input_file)) {
            fprintf(stderr,"Erreur de lecture du fichier %d\n", errno);
            break;
            exit(-1);
        }
        // Lit les deux sommets et le poids de la connexion
        sscanf(file_string, "%hd;%hd;%hd", &s1, &s2, &poids);

        ajouter_connection(reseau, (Connexion){s1,s2,poids});
        
    }
    // On ferme le fichier
    fclose(input_file);

    // Libération de la mémoire
    free(file_string);
    file_string = NULL;
    free(adresse_mac);
    adresse_mac = NULL;
    free(adresse_ip);
    adresse_ip = NULL;
}

