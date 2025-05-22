#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reader.h"
#include "machine.h"

#define MAX_STR_LENGTH 256
#define STR_MAC_LENGTH 18
#define STR_IP_LENGTH 16


void readFile(char* fileName, char* fileString) {
    
    FILE* inputFile = fopen(fileName, "r");

    int nbSommets = 0;
    int nbAretes = 0;
    int typeMachine = 0;
    char* adresseMac = NULL;
    int port = 0;
    int priorite = 0;

    char* adresseIP = NULL;

    int s1 = 0;
    int s2 = 0;
    int poids = 0;

    adresseMac = malloc(STR_MAC_LENGTH);
    adresseIP = malloc(STR_IP_LENGTH);

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
        if(fileString[0] == '2'){
            sscanf(fileString, "%d;%17s;%d;%d", &typeMachine, adresseMac, &port, &priorite);
            printf("Type de machine : %d\n", typeMachine);
            printf("Adresse MAC : %s\n", adresseMac);
            printf("Port : %d\n", port);
            printf("Priorité : %d\n", priorite);
        }
        else{
            sscanf(fileString, "%d;%17s;%15s", &typeMachine, adresseMac, adresseIP);
            printf("Type de machine : %d\n", typeMachine);
            printf("Adresse MAC : %s\n", adresseMac);
            printf("Adresse IP : %s\n", adresseIP);
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
        printf("Sommets : s1 : %d | s2 : %d\n", s1, s2);
        printf("Poids : %d\n", poids);
    }

    fclose(inputFile);
    free(fileString);
    fileString = NULL;
    free(adresseMac);
    adresseMac = NULL;
    free(adresseIP);
    adresseIP = NULL;
    printf("Le fichier a été traité avec succès\n");
    exit(0);
}

