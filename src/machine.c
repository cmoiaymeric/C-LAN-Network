#include "machine.h"
#include "type.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initStation(Machine* machine, Mac addrMac, IP addrIp) {
  machine->typemachine = TypeStation;
  
  printf("test type machine : %d\n", machine->typemachine);

  Station* station = malloc(sizeof(Station));
  printf("test type machine après malloc : %d\n", machine->typemachine);
  station->addrIp = addrIp;
  station->addrMac = addrMac;

  //machine->machine = station;
  printf("test type machine après machine->machine = station : %d\n", machine->typemachine);
}

void initSwitch(Machine *machine, Mac addrMac, uint8_t nbPorts, uint16_t priorite) {
  machine->typemachine = TypeSwitch;
  printf("test type machine : %d\n", machine->typemachine);

  Switch* siwtch = malloc(sizeof(Switch));
  printf("test type machine après malloc : %d\n", machine->typemachine);

  siwtch->addrMac = addrMac;
  siwtch->nbPort = nbPorts;
  siwtch->priorite = priorite;
  
  //machine->machine = siwtch;
  printf("test type machine après machine->machine = siwtch : %d\n", machine->typemachine);

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
  char* macString = NULL;
  macString = malloc(sizeof(char)*18);
  char* ipString = NULL;
  ipString = malloc(sizeof(char)*16);

  printf("Type de machine test : %d\n", machine->typemachine);
  printf("Type de machine test : %d\n", TypeStation);
  printf("Type de machine test : %d\n", TypeSwitch);
  printf("Jusqu'ici ça va\n");

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
    printf("Priorité : %u",((Switch*)machine->machine)->priorite);
  }
  else 
  {
    printf("Erreur d'affichage");
  }
  free(macString);
  free(ipString);
}


