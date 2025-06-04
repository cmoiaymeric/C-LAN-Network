#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reader.h"
#include "machine.h"
#include "type.h"


#define MAX_STR_LENGTH 128

// Fonction pour lire le fichier et afficher les informations
void readFile(char* fileName, char* fileString) {
    
    FILE* inputFile = fopen(fileName, "r");

    Mac* adresseMac = NULL;
    adresseMac = malloc(sizeof(Mac));
    IP* adresseIP = NULL;
    adresseIP = malloc(sizeof(IP));

    uint8_t nbSommets = 0;
    uint8_t nbAretes = 0;
    uint8_t typeMachine = 0;
    uint8_t ports = 0;
    uint16_t priorite = 0;
    uint16_t s1 = 0;
    uint16_t s2 = 0;
    uint16_t poids = 0;

    if(inputFile == NULL){
        printf("Impossible d'ouvrir le fichier %s\n", fileName);
        exit(-1);
    }

    fileString = (char*) malloc(MAX_STR_LENGTH);
    fgets(fileString, MAX_STR_LENGTH, inputFile);
    if (ferror(inputFile)) {
        fprintf(stderr,"Erreur de lecture du fichier %d\n", errno);
        exit(-1);
    }
    
    //On lit la première ligne
    sscanf(fileString, "%hhd %hhd", &nbSommets, &nbAretes);

    for(uint8_t i = 0; i < nbSommets; i++) {

        fgets(fileString, MAX_STR_LENGTH, inputFile);
        if (ferror(inputFile)) {
            fprintf(stderr,"Erreur de lecture du fichier %d\n", errno);
            break;
            exit(-1);
        }

        Machine* machine = malloc(sizeof(Machine));

        sscanf(fileString, "%hhd", &typeMachine);

        if(typeMachine == TypeSwitch){

            printf("=====================================================================================\n");

            sscanf(fileString, "%hhd;%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx;%hhd;%hd", &typeMachine, &adresseMac->octets[0], &adresseMac->octets[1], &adresseMac->octets[2], 
                   &adresseMac->octets[3], &adresseMac->octets[4], &adresseMac->octets[5], &ports, &priorite);
            //printf("Type de machine : %d\t", typeMachine);
            /*printf("Adresse MAC : ");
            for (int h = 0; h < 6; h++)
            {
                printf("%02x", **(adresseMac+h));
                if (h < 5) {
                    printf(":");
                }
            }
            printf("\tports : %d\t", ports);
            printf("Priorité : %d\n", priorite);*/
            initSwitch(machine, *adresseMac, ports, priorite);
            afficheMachine(machine);
            // On libère la mémoire allouée pour la machine
            printf("\n");
        }
        else{

            printf("=====================================================================================\n");

            sscanf(fileString, "%hhd;%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx;%hhu.%hhu.%hhu.%hhu", &typeMachine, &adresseMac->octets[0], &adresseMac->octets[1], &adresseMac->octets[2], 
                   &adresseMac->octets[3], &adresseMac->octets[4], &adresseMac->octets[5], &adresseIP->octets[0], &adresseIP->octets[1], &adresseIP->octets[2], &adresseIP->octets[3]);
            /*printf("Type de machine : %d\t", typeMachine);
            printf("Adresse MAC : ");
            for (int h = 0; h < 6; h++)
            {
                printf("%02x", **(adresseMac+h));
                if (h < 5) {
                    printf(":");
                }
            }
            printf("\tAdresse IP : ");
            for (int j = 0; j < 4; j++) {
                printf("%d", **(adresseIP+j));
                if (j < 3) {
                    printf(".");
                }
            }*/
           
            initStation(machine, *adresseMac, *adresseIP);
            afficheMachine(machine);
            printf("\n");
        }
    }

    printf("=====================================================================================\n");

    for(uint8_t i = 0; i < nbAretes; i++) {
        fgets(fileString, MAX_STR_LENGTH, inputFile);
        if (ferror(inputFile)) {
            fprintf(stderr,"Erreur de lecture du fichier %d\n", errno);
            break;
            exit(-1);
        }
        sscanf(fileString, "%hd;%hd;%hd", &s1, &s2, &poids);
        printf("Arete : s1 : %d\t| s2 : %d\t", s1, s2);
        printf("Poids : %d\n", poids);
        printf("=========================================\n");
    }
    fclose(inputFile);
    free(fileString);
    fileString = NULL;
    printf("Le fichier a été traité avec succès\n");
    exit(0);
}

