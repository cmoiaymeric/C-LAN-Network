#include "machine.h"
#include "type.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Affiche la table de commutation d'un switch.
 * 
 * Vérifie que la machine est bien un switch, puis affiche
 * toutes les entrées (adresse MAC et port) de sa table de commutation.
 * 
 * @param machine Pointeur vers la machine (switch)
 */
void afficher_table_commutation(Machine *machine) {
	if (machine->type_machine == TypeSwitch) {
		Switch* sw = ((Switch*)machine->machine);
		char *macString = malloc(sizeof(char)*18);
		printf("Table de commutation du switch %s\n",mac_to_string(sw->adresse_mac,macString));

		for (uint16_t i=0; i< sw->table_commutation.nombre; i++) {
			printf("Mac : %s  -->  Port : %u\n",mac_to_string(sw->table_commutation.entrees[i].destination, macString), sw->table_commutation.entrees[i].port);
		}
	}
}

/**
 * @brief Initialise une machine de type station.
 * 
 * Alloue dynamiquement une structure Station, initialise
 * ses adresses MAC et IP, et l'assigne à la machine.
 * 
 * @param machine Pointeur vers la machine à initialiser
 * @param adresse_mac Adresse MAC de la station
 * @param adresse_ip Adresse IP de la station
 */
void init_station(Machine* machine, Mac adresse_mac, IP adresse_ip) {
  machine->type_machine = TypeStation;

  Station* station = malloc(sizeof(Station));
  station->adresse_ip = adresse_ip;
  station->adresse_mac = adresse_mac;

  machine->machine = station;
}

/**
 * @brief Initialise une machine de type switch.
 * 
 * Alloue dynamiquement une structure Switch, initialise
 * ses adresses MAC, nombre de ports, et priorité, puis
 * l'assigne à la machine.
 * 
 * @param machine Pointeur vers la machine à initialiser
 * @param adresse_mac Adresse MAC du switch
 * @param nb_ports Nombre de ports du switch
 * @param priorite Priorité du switch
 */
void init_switch(Machine *machine, Mac adresse_mac, uint8_t nb_ports, uint16_t priorite) {
  machine->type_machine = TypeSwitch;

  Switch* siwtch = malloc(sizeof(Switch));

  siwtch->adresse_mac = adresse_mac;
  siwtch->nb_ports = nb_ports;
  siwtch->priorite = priorite;
  siwtch->table_commutation.capacite = 8;
  siwtch->table_commutation.nombre = 0;
  siwtch->table_commutation.entrees = malloc(sizeof(Commutation) * siwtch->table_commutation.capacite);
  
  machine->machine = siwtch;
}

/**
 * @brief Libère la mémoire associée à une machine (station ou switch).
 * 
 * @param machine Pointeur vers le pointeur de machine à désinitialiser
 */
void deinit_machine(Machine **machine) {
  if (*machine == NULL) return; 
    
    if ((*machine)->type_machine == TypeStation) {
        free(((Station*)(*machine)->machine));
    }
    else if ((*machine)->type_machine == TypeSwitch) {
        free(((Switch*)(*machine)->machine)->table_commutation.entrees);
        free(((Switch*)(*machine)->machine));
    }
    
    (*machine)->machine = NULL;
}


/**
 * @brief Affiche les informations d'une machine (station ou switch).
 * 
 * Affiche le type, l'adresse MAC, et selon le type,
 * l'adresse IP (station) ou la priorité (switch).
 * 
 * @param machine La machine à afficher
 */
void afficher_machine(Machine machine) {
  char* macString = NULL;
  macString = malloc(sizeof(char)*18);
  char* ipString = NULL;
  ipString = malloc(sizeof(char)*16);

  if (machine.type_machine == TypeStation) 
  {
    printf("Type : Station  ");
    printf("MAC : %s   ",mac_to_string(((Station*)machine.machine)->adresse_mac, macString));
    printf("IP : %s   ",ip_to_string(((Station*)machine.machine)->adresse_ip, ipString));
  }
  else if (machine.type_machine == TypeSwitch) 
  {
    printf("Type : Switch   ");
    printf("MAC : %s   ",mac_to_string(((Switch*)machine.machine)->adresse_mac, macString));
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

/**
 * @brief Compare l'adresse MAC d'une machine avec une adresse MAC donnée.
 * 
 * @param machine La machine à comparer
 * @param adresse_mac L'adresse MAC à comparer
 * @return 0 si égales, une valeur différente sinon (selon comparer_adresses_mac)
 */
int comparer_mac_machine(Machine machine, Mac adresse_mac) {
  return comparer_adresses_mac(get_mac(machine), adresse_mac);
}


Mac get_mac(Machine machine) {
  if (machine.type_machine == TypeStation) {
    return ((Station*)machine.machine)->adresse_mac;
  }
  else {
    return ((Switch*)machine.machine)->adresse_mac;
  }
}

uint16_t get_index_commutation(Machine* machine, Mac mac) {
  if (machine->type_machine == TypeSwitch) {
    Switch* sw = (Switch*)machine->machine;
    for (uint16_t i=0; i<sw->table_commutation.nombre; i++) {
      if (comparer_adresses_mac(sw->table_commutation.entrees[i].destination, mac)) {
        return i;
      }
    }
  }
  return UINT16_MAX;
}

void ajouter_commutation(Machine *machine, Mac mac, machine_t voisin) {
  if (machine->type_machine == TypeSwitch) {
    Switch* sw = (Switch*)machine->machine;

    uint16_t index_table = get_index_commutation(machine, mac);
    if ( index_table != UINT16_MAX) {
      sw->table_commutation.entrees[index_table].port = voisin;
    }
    else {
      if (sw->table_commutation.nombre >= sw->table_commutation.capacite) {
        sw->table_commutation.capacite*=2;
        sw->table_commutation.entrees = realloc(sw->table_commutation.entrees, sizeof(Commutation) * sw->table_commutation.capacite);
      }
      sw->table_commutation.entrees[sw->table_commutation.nombre] = (Commutation){voisin, mac};
      sw->table_commutation.nombre++;
    }
  }
}

