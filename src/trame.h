#pragma once 

#include "type.h"

typedef enum typeTrame{
    ICMP,BPDU,ARP,IPv4,IPv6,DHCP
}typeTrame;


typedef struct Trame{
    uint8_t SFD;
    Mac addrDestination;
    Mac addrSource;
    typeTrame type;
    char data[1500]; // Taille maximale d'une trame Ethernet
    uint32_t FCS;
}Trame;

void init_trame(Trame *trame, Mac* sourceMac, Mac* destMac, uint16_t type, char *data);