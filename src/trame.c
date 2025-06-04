#include "trame.h"

void initTrame(Trame *trame, Mac sourceMac, Mac destMac, uint16_t type, char *data)
{
    for (int i = 0; i < 7; i++)
    {
        trame->preambule[i] = 170;
    }
    trame->SFD = 171;
    trame->addrSource = sourceMac;
    trame->addrDestination = destMac;
    trame->type = type;
    for (size_t i = 0; i < strlen(data); i++)
    {
        trame->data[i] = data[i];
    }
    trame->data[strlen(data)] = '\0';
    trame->FCS = 0;
}