#include "type.h"
#include "machine.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Convertit une adresse MAC en chaîne de caractères (format : xx:xx:xx:xx:xx:xx).
 * 
 * @param adresse_mac L'adresse MAC à convertir.
 * @param mac_string Une chaîne de caractères préallouée (au moins 18 caractères).
 * @return Pointeur vers la chaîne contenant l'adresse formatée.
 */
char * mac_to_string(Mac adresse_mac, char * mac_string) {

  // Format MAC : xx:xx:xx:xx:xx:xx
  mac_string[0] = '\0'; // initialisation

  for (uint8_t i = 0; i < 6; i++) {
    char temp[4]; // variable temporaire 
    sprintf(temp, "%02hhx", adresse_mac.octets[i]); // sprintf utilisé pour formater et concatener la chaine de caractères
    strcat(mac_string, temp);
    
    if (i < 5) strcat(mac_string,":");
  }
  return mac_string;
}



/**
 * @brief Convertit une adresse IP en chaîne de caractères (format : xxx.xxx.xxx.xxx).
 * 
 * @param ip L'adresse IP à convertir.
 * @param ip_string Une chaîne de caractères préallouée (au moins 16 caractères).
 * @return Pointeur vers la chaîne contenant l'adresse formatée.
 */
char * ip_to_string(IP ip, char * ip_string)
{
    // Format IP : xxx.xxx.xxx.xxx
    ip_string[0] = '\0'; // initialisation

    for (size_t i = 0; i < 4; i++) {
      char temp[4]; // variable temporaire
    sprintf(temp, "%hhu",ip.octets[i]);
    strcat(ip_string, temp);

    if (i < 3) strcat(ip_string, ".");
    }  
    return ip_string;
}


/**
 * @brief Parse une chaîne de caractères représentant une MAC et retourne l'adresse MAC correspondante.
 * 
 * @param mac_string Chaîne de caractères (format : xx:xx:xx:xx:xx:xx).
 * @param adresse_mac Pointeur vers une structure MAC à remplir.
 * @return Pointeur vers la structure remplie.
 */
Mac* mac_from_string(char * mac_string, Mac* adresse_mac) {
  sscanf(mac_string, "%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:", &adresse_mac->octets[0],&adresse_mac->octets[1],&adresse_mac->octets[2],&adresse_mac->octets[3],&adresse_mac->octets[4],&adresse_mac->octets[5]);
  return adresse_mac;
}

/**
 * @brief Parse une chaîne de caractères représentant une IP et retourne l'adresse IP correspondante.
 * 
 * @param ip_string Chaîne de caractères (format : xxx.xxx.xxx.xxx).
 * @param ip Pointeur vers une structure IP à remplir.
 * @return Pointeur vers la structure remplie.
 */
IP* ip_from_string(char * ip_string, IP* ip) {
  sscanf(ip_string, "%hhu.%hhu.%hhu.%hhu", &ip->octets[0], &ip->octets[1], &ip->octets[2], &ip->octets[3]);
  return ip;
}

/**
 * @brief Compare deux adresses MAC.
 * 
 * @param addr1 Première adresse MAC.
 * @param addr2 Deuxième adresse MAC.
 * @return 1 si elles sont égales, 0 sinon.
 */
int comparer_adresses_mac( Mac addr1, Mac addr2)
{
  for (int i = 0; i < 6; i++) {
    if (addr1.octets[i] != addr2.octets[i]) {
      return 0; // Les adresses MAC sont différentes
    }
  }
  return 1; // Les adresses MAC sont identiques
}
