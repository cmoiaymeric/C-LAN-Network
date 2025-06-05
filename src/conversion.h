#pragma once
#include <stdio.h>
#include <string.h>

int puissance(int base, int puissance);

void decimal_to_binaire(unsigned long nombre, char* buffer);

int binaire_to_decimal(char* nombre);

void decimal_to_hexa(unsigned long nombre, char* buffer);

int hexa_to_decimal(char* nombre);