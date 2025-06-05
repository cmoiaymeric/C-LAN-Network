#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint16_t machine_t;

typedef struct Connexion {
    machine_t machine_1; // Sommet 1
    machine_t machine_2; // Sommet 2
    uint8_t poids; // Poids de la connexion
} Connexion;