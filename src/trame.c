#include "trame.h"

void init_trame(Trame *trame, Mac* sourceMac, Mac* destMac, uint16_t type, char *data)
{
    trame->SFD = 171;

    for (uint8_t i = 0; i < 6; i++)
    {
        trame->addrSource.octets[i] = sourceMac->octets[i];
    }

    for (uint8_t i = 0; i < 6; i++)
    {
        trame->addrDestination.octets[i] = destMac->octets[i];
    }

    trame->type = type;

    for (int i = 0; i < strlen(data); i++)
    {
        trame->data[i] = data[i];
    }

    trame->data[strlen(data)] = '\0';
    trame->FCS = 0;
}

void deinit_trame(Trame *trame)
{
    trame->SFD = 0;
    
    free(trame->addrSource.octets);
    for (int i = 0; i < 6; i++) {
        trame->addrSource.octets[i] = 0;
    }

    free(trame->addrDestination.octets);
    for (int i = 0; i < 6; i++) {
        trame->addrDestination.octets[i] = 0;
    }

    trame->type = 0;
    trame->FCS = 0;
}