#include "type.h"

#include <stdio.h>

char * macToString(Mac mac, char * macString) {
  for (uint8_t i = 0; i < 6; i++) {
    sprintf(macString, "%s%02hhx", macString, mac.octets[i]);
    if (i < 5) strcat(macString,":");
  }
  return macString;
}

char * ipToString(IP ip, char * ipString)
{
    // Format IP : xxx.xxx.xxx.xxx

    for (size_t i = 0; i < 4; i++) {
    sprintf(ipString, "%s%hhu", ipString, ip.octets[i]);
    if (i < 3) strcat(ipString, ".");
    }  
    return ipString;
}

Mac* macFromString(char * String, Mac* mac) {
  sscanf(String, "%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:", &mac->octets[0],&mac->octets[1],&mac->octets[2],&mac->octets[3],&mac->octets[4],&mac->octets[5]);
  return mac;
}


IP* ipFromString(char * String, IP* ip) {
  sscanf(String, "%hhu.%hhu.%hhu.%hhu", &ip->octets[0], &ip->octets[1], &ip->octets[2], &ip->octets[3]);
  return ip;
}