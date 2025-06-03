#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifndef TYPE_H
#define TYPE_H

typedef uint8_t octet;

typedef struct Mac {
    octet octets[6];
}Mac;

typedef struct IP {
    octet octets[4];
}IP;

typedef enum typeTrame{
    ICMP,BPDU,ARP,IPv4,IPv6,DHCP
}typeTrame;

typedef struct Trame{
    uint8_t preambule[7];
    uint8_t SFD;
    Mac addrDestination;
    Mac addrSource;
    typeTrame type;
    char data[1500];
    uint32_t FCS;
}Trame;

char * macToString(Mac mac, char * macString);
char * ipToString(IP ip, char * ipString);

Mac* macFromString(char * String, Mac* mac);
IP* ipFromString(char * String, IP* ip);

#endif