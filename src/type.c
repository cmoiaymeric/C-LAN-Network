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
    char *ptr = ipString;

    for (size_t i = 0; i < 4; i++) {
        ptr += sprintf(ptr, "%u", ip[i]);  
        if (i < 3) {
            *ptr++ = '.'; 
        }
    }
    *ptr = '\0';
    return ipString;
}

