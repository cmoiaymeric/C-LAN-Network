#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef TYPE_H
#define TYPE_H


// Définition d'un alias pour un octet
typedef uint8_t octet;

/**
 * @brief Représente une adresse MAC.
 * Composée de 6 octets.
 */
typedef struct Mac {
    octet octets[6];
}Mac;


/**
 * @brief Représente une adresse IP.
 * Composée de 4 octets.
 */
typedef struct IP {
    octet octets[4];
}IP;

/**
 * @brief Convertit une adresse MAC en chaîne de caractères (format : xx:xx:xx:xx:xx:xx).
 * 
 * @param adresse_mac Adresse MAC à convertir.
 * @param mac_string Chaîne de caractères préallouée (au moins 18 caractères).
 * @return Pointeur vers la chaîne formatée.
 */
char * mac_to_string(Mac adresse_mac, char * mac_string);
/**
 * @brief Convertit une adresse IP en chaîne de caractères (format : xxx.xxx.xxx.xxx).
 * 
 * @param adresse_ip Adresse IP à convertir.
 * @param ip_string Chaîne de caractères préallouée (au moins 16 caractères).
 * @return Pointeur vers la chaîne formatée.
 */
char * ip_to_string(IP adresse_ip, char * ip_string);

/**
 * @brief Transforme une chaîne de caractères en adresse MAC.
 * 
 * @param mac_string Chaîne au format "xx:xx:xx:xx:xx:xx".
 * @param adresse_mac Pointeur vers la structure MAC à remplir.
 * @return Pointeur vers la structure remplie.
 */
Mac* mac_from_string(char * mac_string, Mac* adresse_mac);

/**
 * @brief Transforme une chaîne de caractères en adresse IP.
 * 
 * @param ip_string Chaîne au format "xxx.xxx.xxx.xxx".
 * @param adresse_ip Pointeur vers la structure IP à remplir.
 * @return Pointeur vers la structure remplie.
 */
IP* ip_from_string(char * ip_string, IP* adresse_ip);

/**
 * @brief Compare deux adresses MAC.
 * 
 * @param addr1 Première adresse MAC.
 * @param addr2 Deuxième adresse MAC.
 * @return 1 si les adresses sont identiques, 0 sinon.
 */
int comparer_adresses_mac( Mac addr1, Mac addr2);


bool mac_est_plus_petite(Mac macP, Mac macG);

#endif