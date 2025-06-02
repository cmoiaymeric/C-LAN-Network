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

typedef struct trame{
    Mac addrDestination;
    Mac addrSource;
    typeTrame type;
}trame;

char * macToString(Mac mac, char * macString);
char * ipToString(IP ip, char * ipString);

Mac* macFromString(char * String, Mac* mac);
IP* ipFromString(char * String, IP* ip);

#endif