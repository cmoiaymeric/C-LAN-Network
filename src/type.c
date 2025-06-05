#include "type.h"

#include <stdio.h>

char * mac_to_string(Mac mac, char * macString) {

  // Format MAC : xx:xx:xx:xx:xx:xx

  for (uint8_t i = 0; i < 6; i++) {
    sprintf(macString, "%s%02hhx", macString, mac.octets[i]); // sprintf utilisé pour formater et concatener la chaine de caractères
    if (i < 5) strcat(macString,":");
  }
  return macString;
}

char * ip_to_string(IP ip, char * ipString)
{
    // Format IP : xxx.xxx.xxx.xxx

    for (size_t i = 0; i < 4; i++) {
    sprintf(ipString, "%s%hhu", ipString, ip.octets[i]);
    if (i < 3) strcat(ipString, ".");
    }  
    return ipString;
}

Mac* mac_from_string(char * String, Mac* mac) {
  sscanf(String, "%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:", &mac->octets[0],&mac->octets[1],&mac->octets[2],&mac->octets[3],&mac->octets[4],&mac->octets[5]);
  return mac;
}


IP* ip_from_string(char * String, IP* ip) {
  sscanf(String, "%hhu.%hhu.%hhu.%hhu", &ip->octets[0], &ip->octets[1], &ip->octets[2], &ip->octets[3]);
  return ip;
}