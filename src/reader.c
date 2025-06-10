#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reader.h"
#include "connexion.h"
#include "machine.h"
#include "type.h"
#include "reseau.h"


#define MAX_STR_LENGTH 128

// Fonction pour lire le fichier et afficher les informations
void read_config_file(char* file_name, Reseau* reseau) {
    char * file_string = NULL;
    
    FILE* input_file = fopen(file_name, "r");

    Mac* adresse_mac = NULL;
    adresse_mac = malloc(sizeof(Mac));
    IP* adresse_ip = NULL;
    adresse_ip = malloc(sizeof(IP));

    uint8_t nb_sommets = 0;
    uint8_t nb_aretes = 0;
    uint8_t type_machine = 0;
    uint8_t ports = 0;
    uint16_t priorite = 0;
    uint16_t s1 = 0;
    uint16_t s2 = 0;
    uint16_t poids = 0;

    if(input_file == NULL){
        printf("Impossible d'ouvrir le fichier %s\n", file_name);
        exit(-1);
    }

    file_string = (char*) malloc(MAX_STR_LENGTH);
    fgets(file_string, MAX_STR_LENGTH, input_file);
    if (ferror(input_file)) {
        fprintf(stderr,"Erreur de lecture du fichier %d\n", errno);
        exit(-1);
    }
    
    //On lit la première ligne
    sscanf(file_string, "%hhd %hhd", &nb_sommets, &nb_aretes);

    for(uint8_t i = 0; i < nb_sommets; i++) {

        fgets(file_string, MAX_STR_LENGTH, input_file);
        if (ferror(input_file)) {
            fprintf(stderr,"Erreur de lecture du fichier %d\n", errno);
            break;
            exit(-1);
        }

        Machine* machine = malloc(sizeof(Machine));

        sscanf(file_string, "%hhd", &type_machine);

        if(type_machine == TypeSwitch){

            sscanf(file_string, "%hhd;%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx;%hhd;%hd", &type_machine, &adresse_mac->octets[0], &adresse_mac->octets[1], &adresse_mac->octets[2], &adresse_mac->octets[3], &adresse_mac->octets[4], &adresse_mac->octets[5], &ports, &priorite);
            
            init_switch(machine, *adresse_mac, ports, priorite);
        }
        else{

            sscanf(file_string, "%hhd;%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx;%hhu.%hhu.%hhu.%hhu", &type_machine, &adresse_mac->octets[0], &adresse_mac->octets[1], &adresse_mac->octets[2], &adresse_mac->octets[3], &adresse_mac->octets[4], &adresse_mac->octets[5], &adresse_ip->octets[0], &adresse_ip->octets[1], &adresse_ip->octets[2], &adresse_ip->octets[3]);
           
            init_station(machine, *adresse_mac, *adresse_ip);
        }

        ajouter_machine(reseau, *machine);
    }

    for(uint8_t i = 0; i < nb_aretes; i++) {
        fgets(file_string, MAX_STR_LENGTH, input_file);
        if (ferror(input_file)) {
            fprintf(stderr,"Erreur de lecture du fichier %d\n", errno);
            break;
            exit(-1);
        }
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
    free(input_file);
    input_file = NULL;
}

