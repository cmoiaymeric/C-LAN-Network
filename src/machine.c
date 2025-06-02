#include "machine.h"
#include <stdlib.h>

void initStation(Machine* machine, Mac addrMac, IP addrIp) {
  machine->typemachine = TypeStation;

  Station* station = malloc(sizeof(Station));
  for (int i=0; i<4; i++)
    station->addrIp[i] = addrIp[i];
  for (int i=0; i<6; i++)
    station->addrMac[i] = addrMac[i];

  machine->machine = station;
}

