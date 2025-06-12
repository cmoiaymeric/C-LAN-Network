#pragma once 

#include "type.h"


/**
 * @enum typeTrame
 * @brief Enumération des types de trames supportés.
 * 
 * Cette énumération permet de classifier les trames selon leur protocole :
 * - ICMP : Internet Control Message Protocol
 * - BPDU : Bridge Protocol Data Unit
 * - ARP  : Address Resolution Protocol
 * - IPv4 : Internet Protocol version 4
 * - IPv6 : Internet Protocol version 6
 * - DHCP : Dynamic Host Configuration Protocol
 */
typedef enum typeTrame{
    ICMP_REQUEST,ICMP_REPLY,BPDU,ARP,IPv4,IPv6,DHCP
}typeTrame;


/**
 * @struct Trame
 * @brief Représente une trame réseau de niveau 2 (Ethernet).
 * 
 * Champs :
 * - SFD               : Start Frame Delimiter, valeur fixe indiquant le début de la trame.
 * - TTL               : Time To Live de la trame
 * - addrDestination   : Adresse MAC de destination.
 * - addrSource        : Adresse MAC source.
 * - type              : Type de protocole contenu dans la trame.
 * - data[1500]        : Données contenues dans la trame (payload), jusqu'à 1500 octets.
 * - FCS               : Frame Check Sequence, utilisé pour la détection d'erreurs (non calculé ici).
 */
typedef struct Trame{
    uint8_t SFD;
    uint8_t TTL;
    Mac addrDestination;
    Mac addrSource;
    typeTrame type;
    char data[1500]; // Taille maximale d'une trame Ethernet
    uint32_t FCS;
}Trame;

/**
 * @brief Initialise une trame avec les paramètres spécifiés.
 * 
 * @param trame      Pointeur vers la trame à initialiser.
 * @param sourceMac  Pointeur vers l'adresse MAC source.
 * @param destMac    Pointeur vers l'adresse MAC de destination.
 * @param type       Type de trame (utiliser une valeur de l'enum typeTrame).
 * @param data       Données (payload) à insérer dans la trame (doit être une chaîne de caractères).
 */
void init_trame(Trame* trame, Mac* sourceMac, Mac* destMac, typeTrame type, char *data);
void deinit_trame(Trame* trame);

void afficher_trame_user(Trame *trame);
void afficher_trame_hexa(Trame *trame);