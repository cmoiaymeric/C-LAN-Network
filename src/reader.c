#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 256

void reader(char* fileName, char* fileString) {

    FILE* inputFile = fopen(fileName, "r");

    if(inputFile == NULL){
        printf("Impossible d'ouvrir le fichier %s\n", fileName);
        exit(-1);
    }

    fileString = (char*) malloc(MAX_LENGTH);

    while (!feof(inputFile)) {
        fgets(fileString, MAX_LENGTH, inputFile);
        if (ferror(inputFile)) {
            fprintf(stderr,"Erreur de lecture du fichier %d\n", errno);
            break;
        }
        printf("%s", fileString);
    }
    fclose(inputFile);
    free(fileString);
    exit(0);
}