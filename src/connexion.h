#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct Connexion {
    uint16_t machine_1; // Sommet 1
    uint16_t machine_2; // Sommet 2
    uint8_t poids; // Poids de la connexion
} Connexion;