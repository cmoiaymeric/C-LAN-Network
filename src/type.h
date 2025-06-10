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

char * mac_to_string(Mac adresse_mac, char * mac_string);
char * ip_to_string(IP adresse_ip, char * ip_string);

Mac* mac_from_string(char * mac_string, Mac* adresse_mac);
IP* ip_from_string(char * ip_string, IP* adresse_ip);

int comparer_adresses_mac( Mac addr1, Mac addr2);
int comparer_mac_machine(Machine machine, Mac adresse_mac);

#endif