#include "machine.h"
#include "type.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initStation(Machine* machine, Mac addrMac, IP addrIp) {
  machine->typemachine = TypeStation;

  Station* station = malloc(sizeof(Station));
  for (int i=0; i<4; i++)
    station->addrIp[i] = addrIp[i];
  for (int i=0; i<6; i++)
    station->addrMac[i] = addrMac[i];

  machine->machine = station;
}

void initSwitch(Machine *machine, Mac addrMac, size_t nbPorts, uint8_t priorite) {
  machine->typemachine = TypeSwitch;

  Switch* siwtch = malloc(sizeof(Switch));
  for (int i=0; i<6; i++) {
    siwtch->addrMac[i] = addrMac[i];
  }
  siwtch->nbPort = nbPorts;
  siwtch->priorite = priorite;
  machine->machine = siwtch;
}

void deinitMachine(Machine *machine) {
  if (machine->typemachine == TypeStation) {
    free(((Station*)machine->machine));
    machine->machine = NULL;
  }
  else if (machine->typemachine == TypeSwitch) {
    free(((Switch*)machine->machine));
    machine->machine = NULL;
  }
}


void afficheMachine(Machine *machine) {
  char* macString = malloc(sizeof(char)*18);
  char* ipString = malloc(sizeof(char)*16);
  if (machine->typemachine == TypeStation) 
  {
    printf("Type de machine : Station\t");
    printf("Adresse MAC : %s\t",macToString(((Station*)machine->machine)->addrMac, macString));
    printf("Adresse IP : %s\n",ipToString(((Station*)machine->machine)->addrIp, ipString));
  }
  else if (machine->typemachine == TypeSwitch) 
  {
    printf("Type de machine : Switch\t");
    printf("Adresse MAC : %s\t",macToString(((Switch*)machine->machine)->addrMac, macString));
    printf("Priorité : %zu",((Switch*)machine->machine)->priorite);
  }
  else 
  {
    printf("Erreur d'affichage");
  }
  free(macString);
  free(ipString);
}