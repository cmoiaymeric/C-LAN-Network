#pragma once
#include <stdio.h>
#include <string.h>

// Calcule la puissance d'un nombre : base^puissance
// @param base : la base entière
// @param puissance : l'exposant (entier >= 0)
// @return le résultat de base élevé à la puissance
int puissance(int base, int puissance);

// Convertit un entier décimal en binaire (chaîne terminée par '\0')
// @param nombre : le nombre décimal à convertir
// @param buffer : le buffer où la chaîne binaire sera stockée
void decimal_to_binaire(unsigned long nombre, char* buffer);

// Convertit une chaîne binaire (ex : "1010") en entier décimal
// @param nombre : chaîne représentant un nombre en binaire
// @return équivalent décimal du binaire
int binaire_to_decimal(char* nombre);

// Convertit un entier décimal en chaîne hexadécimale (ex : 255 → "FF")
// @param nombre : le nombre décimal à convertir
// @param buffer : le buffer où la chaîne hexadécimale sera stockée
void decimal_to_hexa(unsigned long nombre, char* buffer);

// Convertit une chaîne hexadécimale (ex : "1A3F") en entier décimal
// @param nombre : chaîne représentant un nombre en hexadécimal (majuscules ou minuscules)
// @return équivalent décimal de l’hexadécimal
int hexa_to_decimal(char* nombre);