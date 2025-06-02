#include "machine.h"
#include "type.h"
#include <stdio.h>
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

void initSwitch(Machine *machine, Mac addrMac, uint8_t priorite) {
  machine->typemachine = TypeSwitch;

  Switch* siwtch = malloc(sizeof(Switch));
  for (int i=0; i<6; i++) {
    siwtch->addrMac[i] = addrMac[i];
  }
  machine->machine = siwtch;
}


void afficheMachine(Machine *machine) {
  if (machine->typemachine == TypeStation) {
    
    char* macString = malloc(sizeof(char)*17);
    char* ipString = malloc(sizeof(char)*15);

    printf("Type de machine : Station\t");
    printf("Adresse MAC : %s\t",macToString(((Station*)machine->machine)->addrMac, macString));
    printf("Adresse IP : %s\n",ipToString(((Station*)machine->machine)->addrIp, ipString));
  }
  else if (machine->typemachine == TypeSwitch) {
    char* macString = malloc(sizeof(char)*17);

    printf("Type de machine : Station\t");
    printf("Adresse MAC : %s\t",macToString(((Switch*)machine->machine)->addrMac, macString));
    printf("Priorité : %zu",((Switch*)machine->machine)->priorite);
  }
}