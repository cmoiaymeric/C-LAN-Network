#include "machine.h"
#include "type.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Mac get_mac(Machine* machine) {
  if (machine->type_machine == TypeStation) {
    return ((Station*)machine->machine)->adresse_mac;
  } else {
    return ((Switch*)machine->machine)->adresse_mac;
  }
}

void init_station(Machine* machine, Mac adresse_mac, IP adresse_ip) {
  machine->type_machine = TypeStation;

  Station* station = malloc(sizeof(Station));
  station->adresse_ip = adresse_ip;
  station->adresse_mac = adresse_mac;
  station->voisin = malloc(sizeof(Machine));

  machine->machine = station;
}

void init_switch(Machine *machine, Mac adresse_mac, uint8_t nb_ports, uint16_t priorite) {
  machine->type_machine = TypeSwitch;

  Switch* siwtch = malloc(sizeof(Switch));

  siwtch->adresse_mac = adresse_mac;
  siwtch->nb_ports = nb_ports;
  siwtch->priorite = priorite;
  siwtch->voisins = malloc(sizeof(Machine*)*nb_ports);
  for (size_t i=0; i<nb_ports; i++) {
    *(siwtch->voisins + i) = NULL;
  }
  
  machine->machine = siwtch;

}

void deinit_machine(Machine **machine) {
  if ((*machine)->type_machine == TypeStation) {
    free(((Station*)(*machine)->machine));
    (*machine)->machine = NULL;
  }
  else if ((*machine)->type_machine == TypeSwitch) {
    free(((Switch*)(*machine)->machine));
    (*machine)->machine = NULL;
  }
  free(*machine);
  *machine = NULL; 
}


void afficher_machine(Machine* machine) {
  char* macString = NULL;
  macString = malloc(sizeof(char)*18);
  char* ipString = NULL;
  ipString = malloc(sizeof(char)*16);

  if (machine->type_machine == TypeStation) 
  {
    printf("Type de machine : Station  ");
    printf("Adresse MAC : %s   ",mac_to_string(((Station*)machine->machine)->adresse_mac, macString));
    printf("Adresse IP : %s   ",ip_to_string(((Station*)machine->machine)->adresse_ip, ipString));
	  printf("Lien : %s  ",mac_to_string(get_mac(((Station*)machine->machine)->voisin), macString));
  }
  else if (machine->type_machine == TypeSwitch) 
  {
    printf("Type de machine : Switch   ");
    printf("Adresse MAC : %s   ",mac_to_string(((Switch*)machine->machine)->adresse_mac, macString));
    printf("Priorité : %u   ",((Switch*)machine->machine)->priorite);
	  printf("Liens :");
	for (uint16_t i=0; i<((Switch*)machine->machine)->nb_voisins; i++) {
		printf("  %s",mac_to_string(get_mac(((Switch*)machine->machine)->voisins[i]), macString));
	}
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


void ajouter_lien(Machine* machine1, Machine* machine2) {
	if (machine1->type_machine == TypeStation) {
		((Station*)machine1->machine)->voisin = machine2;
	}
	else {
		((Switch*)machine1->machine)->voisins[((Switch*)machine1->machine)->nb_voisins] = machine2;
		((Switch*)machine1->machine)->nb_voisins++;
	}
}
