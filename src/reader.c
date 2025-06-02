#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reader.h"
#include "machine.c"

#define MAX_STR_LENGTH 128

// Fonction pour lire le fichier et afficher les informations
void readFile(char* fileName, char* fileString) {
    
    FILE* inputFile = fopen(fileName, "r");

    Mac* adresseMac = NULL;
    adresseMac = malloc(sizeof(Mac));
    IP* adresseIP = NULL;
    adresseIP = malloc(sizeof(IP));

    int nbSommets = 0;
    int nbAretes = 0;
    int typeMachine = 0;
    int port = 0;
    int priorite = 0;
    int s1 = 0;
    int s2 = 0;
    int poids = 0;

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
    sscanf(fileString, "%d %d", &nbSommets, &nbAretes);

    for(int i = 0; i < nbSommets; i++) {
        fgets(fileString, MAX_STR_LENGTH, inputFile);
        if (ferror(inputFile)) {
            fprintf(stderr,"Erreur de lecture du fichier %d\n", errno);
            break;
            exit(-1);
        }

        Machine* machine = malloc(sizeof(Machine));

        if(fileString[0] == '2'){
            sscanf(fileString, "%d;%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx;%d;%d", &typeMachine, *adresseMac, *(adresseMac+1), *(adresseMac+2), *(adresseMac+3), *(adresseMac+4), *(adresseMac+5), &port, &priorite);
            printf("Type de machine : %d\t", typeMachine);
            printf("Adresse MAC : ");
            for (int h = 0; h < 6; h++)
            {
                printf("%02x", **(adresseMac+h));
                if (h < 5) {
                    printf(":");
                }
            }
            printf("\tPort : %d\t", port);
            printf("Priorité : %d\n", priorite);
            printf("\n");
        }
        else{
            sscanf(fileString, "%d;%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx;%hhu.%hhu.%hhu.%hhu", &typeMachine, *adresseMac, *(adresseMac+1), *(adresseMac+2), *(adresseMac+3), *(adresseMac+4), *(adresseMac+5), *adresseIP, *(adresseIP+1), *(adresseIP+2), *(adresseIP+3));
            printf("Type de machine : %d\t", typeMachine);
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
            }
            initStation(machine, *adresseMac, *adresseIP);
            printf("\n\n");
        }
    }

    for(int i = 0; i < nbAretes; i++) {
        fgets(fileString, MAX_STR_LENGTH, inputFile);
        if (ferror(inputFile)) {
            fprintf(stderr,"Erreur de lecture du fichier %d\n", errno);
            break;
            exit(-1);
        }
        sscanf(fileString, "%d;%d;%d", &s1, &s2, &poids);
        printf("Arete : s1 : %d\t| s2 : %d\t", s1, s2);
        printf("Poids : %d\n", poids);
    }

    fclose(inputFile);
    free(fileString);
    fileString = NULL;
    printf("Le fichier a été traité avec succès\n");
    exit(0);
}

