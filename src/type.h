#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifndef TYPE_H
#define TYPE_H

typedef size_t sommet;
typedef unsigned char Mac[6];
typedef size_t IP[4];

typedef enum typeTrame{
    ICMP,BPDU,ARP,IPv4,IPv6,DHCP
}typeTrame;

typedef struct trame{
    Mac addrDestination;
    Mac addrSource;
    typeTrame type;
}trame;

char * macToString(Mac mac, char * macString);
char * ipToString(IP ip, char * ipString);

#endif