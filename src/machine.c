#include "machine.h"
#include "type.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_station(Machine* machine, Mac addrMac, IP addrIp) {
  machine->typemachine = TypeStation;

  Station* station = malloc(sizeof(Station));
  station->addrIp = addrIp;
  station->addrMac = addrMac;

  machine->machine = station;
}

void init_switch(Machine *machine, Mac addrMac, uint8_t nbPorts, uint16_t priorite) {
  machine->typemachine = TypeSwitch;

  Switch* siwtch = malloc(sizeof(Switch));

  siwtch->addrMac = addrMac;
  siwtch->nbPort = nbPorts;
  siwtch->priorite = priorite;
  
  machine->machine = siwtch;

}

void deinit_machine(Machine *machine) {
  if (machine->typemachine == TypeStation) {
    free(((Station*)machine->machine));
    machine->machine = NULL;
  }
  else if (machine->typemachine == TypeSwitch) {
    free(((Switch*)machine->machine));
    machine->machine = NULL;
  }
}


void afficher_machine(Machine *machine) {
  char* macString = NULL;
  macString = malloc(sizeof(char)*18);
  char* ipString = NULL;
  ipString = malloc(sizeof(char)*16);

  if (machine->typemachine == TypeStation) 
  {
    printf("Type de machine : Station  ");
    printf("Adresse MAC : %s   ",mac_to_string(((Station*)machine->machine)->addrMac, macString));
    printf("Adresse IP : %s   ",ip_to_string(((Station*)machine->machine)->addrIp, ipString));
  }
  else if (machine->typemachine == TypeSwitch) 
  {
    printf("Type de machine : Switch   ");
    printf("Adresse MAC : %s   ",mac_to_string(((Switch*)machine->machine)->addrMac, macString));
    printf("Priorité : %u   ",((Switch*)machine->machine)->priorite);
  }
  else 
  {
    printf("Erreur d'affichage");
  }
  free(macString);
  macString = NULL;
  free(ipString);
  ipString = NULL;
}


