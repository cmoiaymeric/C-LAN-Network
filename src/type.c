#include "type.h"

#include <stdio.h>

char * mac_to_string(Mac adresse_mac, char * mac_string) {

  // Format MAC : xx:xx:xx:xx:xx:xx

  for (uint8_t i = 0; i < 6; i++) {
    sprintf(mac_string, "%s%02hhx", mac_string, adresse_mac.octets[i]); // sprintf utilisé pour formater et concatener la chaine de caractères
    if (i < 5) strcat(mac_string,":");
  }
  return mac_string;
}

char * ip_to_string(IP ip, char * ip_string)
{
    // Format IP : xxx.xxx.xxx.xxx

    for (size_t i = 0; i < 4; i++) {
    sprintf(ip_string, "%s%hhu", ip_string, ip.octets[i]);
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