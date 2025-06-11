#include "conversion.h"

// Fonction récursive pour calculer base^exposant (à optimiser si nécessaire)
int puissance(int base, int exposant)
{
    if (exposant == 0) 
    {
        return 1;
    }
    return base * puissance(base, exposant - 1);
}
// Convertit un entier décimal en binaire, stocké sous forme de chaîne dans buffer
void decimal_to_binaire(unsigned long nombre, char* buffer) 
{
    if (nombre == 0) 
    {
        buffer[0] = '0'; 
        buffer[1] = '\0';
        return;
    }
    
    int index = 0;
    while (nombre > 0) 
    {
        buffer[index++] = (nombre % 2) + '0'; // Ajoute le bit le moins significatif
        nombre /= 2;     // Décale à droite
            }
    buffer[index] = '\0';
    
    // Reverse the string pour le bon ordre
    for (int i = 0; i < index / 2; i++) 
    {
        char temp = buffer[i];
        buffer[i] = buffer[index - i - 1];
        buffer[index - i - 1] = temp;
    }
    
}
// Convertit une chaîne binaire (ex: "1010") en entier décimal
int binaire_to_decimal(char* nombre)
{
    int decimal = 0;
    int base = 1;
    int length = strlen(nombre);
    
    for (int i = length - 1; i >= 0; i--) 
    {
        if (nombre[i] == '1') 
        {
            decimal += base;  // Ajoute la puissance de 2 correspondante
        }
        base *= 2; // Passe à la puissance suivante
    }
    
    return decimal;
    
}
// Convertit un entier décimal en chaîne hexadécimale (ex: 255 -> "FF")
void decimal_to_hexa(unsigned long nombre, char* buffer) 
{
    sprintf(buffer, "%lX", nombre);    
}

// Convertit une chaîne hexadécimale (ex: "1A3F") en entier décimal
int hexa_to_decimal(char* nombre)
{
    int decimal = 0;
    int base = 1;
    int length = strlen(nombre);
    
    for (int i = length - 1; i >= 0; i--) 
    {
        if (nombre[i] >= '0' && nombre[i] <= '9') 
        {
            decimal += (nombre[i] - '0') * base; // Chiffre entre 0 et 9
        } 
        else if (nombre[i] >= 'A' && nombre[i] <= 'F') 
        {
            decimal += (nombre[i] - 'A' + 10) * base; // Lettre entre A et F
        } 
        else if (nombre[i] >= 'a' && nombre[i] <= 'f') 
        {
            decimal += (nombre[i] - 'a' + 10) * base; // Lettre entre a et f
        } 
        base *= 16;
    }
    
    return decimal;
    
}