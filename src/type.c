#include "type.h"

char * macToString(Mac mac, char * macString) {
  for (size_t i = 0; i < 6; i++) {
    sprintf(macString, "%02X", mac[i]);
    if (i < 5) sprintf(macString,":");
  }
  return macString;
}