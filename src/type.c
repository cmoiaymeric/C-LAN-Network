#include "type.h"
#include "machine.h"
#include <stdio.h>
#include <stdlib.h>


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

Mac* mac_from_string(char * mac_string, Mac* adresse_mac) {
  sscanf(mac_string, "%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:", &adresse_mac->octets[0],&adresse_mac->octets[1],&adresse_mac->octets[2],&adresse_mac->octets[3],&adresse_mac->octets[4],&adresse_mac->octets[5]);
  return adresse_mac;
}


IP* ip_from_string(char * ip_string, IP* ip) {
  sscanf(ip_string, "%hhu.%hhu.%hhu.%hhu", &ip->octets[0], &ip->octets[1], &ip->octets[2], &ip->octets[3]);
  return ip;
}

int comparer_adresses_mac( Mac addr1, Mac addr2)
{
  for (int i = 0; i < 6; i++) {
    if (addr1.octets[i] != addr2.octets[i]) {
      return 0; // Les adresses MAC sont différentes
    }
  }
  return 1; // Les adresses MAC sont identiques
}
