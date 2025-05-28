#include "type.h"

#include <stdio.h>

char * macToString(Mac mac, char * macString) {
  for (size_t i = 0; i < 6; i++) {
    sprintf(macString, "%02X", mac[i]);
    if (i < 5) sprintf(macString,":");
  }
  return macString;
}

char * ipToString(IP ip, char * ipString)
{
    // Format IP : xxx.xxx.xxx.xxx

    for (size_t i = 0; i < 4; i++) {
    sprintf(ipString, "%hhu", ip[i]);
    if (i < 3) sprintf(ipString, ".");
    }  
    return ipString;
}

Mac* macFromString(char * String, Mac* mac) {
  sscanf(String, "%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx:", mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
  return mac;
}


IP* ipFromString(char * String, IP* ip) {
 
}