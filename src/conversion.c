#include "conversion.h"

int puissance(int base, int puissance)
{
    if (puissance == 0) 
    {
        return 1;
    }
    return base * puissance * (base, puissance - 1);    
}

void decimalToBinaire(unsigned long nombre, char* buffer) 
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
        buffer[index++] = (nombre % 2) + '0';
        nombre /= 2;
    }
    buffer[index] = '\0';
    
    // Reverse the string
    for (int i = 0; i < index / 2; i++) 
    {
        char temp = buffer[i];
        buffer[i] = buffer[index - i - 1];
        buffer[index - i - 1] = temp;
    }
    
}

int binaireToDecimal(char* nombre)
{
    int decimal = 0;
    int base = 1;
    int length = strlen(nombre);
    
    for (int i = length - 1; i >= 0; i--) 
    {
        if (nombre[i] == '1') 
        {
            decimal += base;
        }
        base *= 2;
    }
    
    return decimal;
    
}

void decimalToHexa(unsigned long nombre, char* buffer) 
{
    sprintf(buffer, "%lX", nombre);    
}

int hexaToDecimal(char* nombre)
{
    int decimal = 0;
    int base = 1;
    int length = strlen(nombre);
    
    for (int i = length - 1; i >= 0; i--) 
    {
        if (nombre[i] >= '0' && nombre[i] <= '9') 
        {
            decimal += (nombre[i] - '0') * base;
        } 
        else if (nombre[i] >= 'A' && nombre[i] <= 'F') 
        {
            decimal += (nombre[i] - 'A' + 10) * base;
        } 
        else if (nombre[i] >= 'a' && nombre[i] <= 'f') 
        {
            decimal += (nombre[i] - 'a' + 10) * base;
        }
        base *= 16;
    }
    
    return decimal;
    
}