#include "machine.h"
#include "type.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_station(Machine* machine, Mac adresse_mac, IP adresse_ip) {
  machine->type_machine = TypeStation;

  Station* station = malloc(sizeof(Station));
  station->adresse_ip = adresse_ip;
  station->adresse_mac = adresse_mac;

  machine->machine = station;
}

void init_switch(Machine *machine, Mac adresse_mac, uint8_t nb_ports, uint16_t priorite) {
  machine->type_machine = TypeSwitch;

  Switch* siwtch = malloc(sizeof(Switch));

  siwtch->adresse_mac = adresse_mac;
  siwtch->nb_ports = nb_ports;
  siwtch->priorite = priorite;
  
  machine->machine = siwtch;
}

void deinit_machine(Machine **machine) {
  if (*machine == NULL) return; 
    
    if ((*machine)->type_machine == TypeStation) {
        free(((Station*)(*machine)->machine));
    }
    else if ((*machine)->type_machine == TypeSwitch) {
        free(((Switch*)(*machine)->machine));
    }
    
    (*machine)->machine = NULL;
}


void afficher_machine(Machine machine) {
  char* macString = NULL;
  macString = malloc(sizeof(char)*18);
  char* ipString = NULL;
  ipString = malloc(sizeof(char)*16);

  if (machine.type_machine == TypeStation) 
  {
    printf("Type de machine : Station  ");
    printf("Adresse MAC : %s   ",mac_to_string(((Station*)machine.machine)->adresse_mac, macString));
    printf("Adresse IP : %s   ",ip_to_string(((Station*)machine.machine)->adresse_ip, ipString));
  }
  else if (machine.type_machine == TypeSwitch) 
  {
    printf("Type de machine : Switch   ");
    printf("Adresse MAC : %s   ",mac_to_string(((Switch*)machine.machine)->adresse_mac, macString));
    printf("Priorité : %u   ",((Switch*)machine.machine)->priorite);
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
int comparer_mac_machine(Machine machine, Mac adresse_mac) {
  if (machine.type_machine == TypeStation) {
    Station* station = (Station*) machine.machine;
    return comparer_adresses_mac(station->adresse_mac, adresse_mac);
  } else if (machine.type_machine == TypeSwitch) {
    Switch* switch_machine = (Switch*) machine.machine;
    return comparer_adresses_mac(switch_machine->adresse_mac, adresse_mac);
  }
}