#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifndef TYPE_H
#define TYPE_H

typedef size_t sommet;
typedef uint8_t Mac[6];
typedef size_t IP[4];

typedef struct commutation {
    int16_t port;
    Mac destination;
} commutation;


typedef struct equipement {
    Mac addrMac;
    IP addrIP;
    uint16_t nbPort;
    uint16_t priorite;
    commutation* commutations;
    uint8_t type;
}equipement;

typedef enum typeTrame{
    ICMP,BPDU,ARP,IPv4,IPv6,DHCP
}typeTrame;

typedef struct trame{
    Mac addrDestination;
    Mac addrSource;
    typeTrame type;
}trame;

#endif