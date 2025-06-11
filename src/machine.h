#include "type.h"
#include <stddef.h>

#ifndef MACHINE_H
#define MACHINE_H

// Représente une entrée de la table de commutation d'un switch
typedef struct Commutation {
  uint8_t port; // Numéro du port associé
  Mac destination; // Adresse MAC destination correspondante
} Commutation;

// Table de commutation contenant plusieurs entrées
typedef struct TableCommutation {
  Commutation* entrees; // Tableau dynamique des entrées  
  uint16_t nombre; // Nombre actuel d’entrées utilisées
  uint16_t capacite;     // Capacité maximale allouée au tableau
} TableCommutation;

// Représente une station réseau avec ses adresses
typedef struct Station {
  Mac adresse_mac; // mac de la station
  IP adresse_ip; // IP
  Mac voisin; // mac du voisin
} Station;
 
// Représente un switch 
typedef struct Switch
{
  Mac adresse_mac; // MAC
  uint8_t nb_ports; //IP
  uint16_t priorite; // priorité pour le stp / dijkstra 
  TableCommutation table_commutation; // table de commutation
} Switch;

// Enumération pour distinguer les types de machine
typedef enum TypeMachine {
  TypeStation = 1, // Station
  TypeSwitch = 2, // switch
} TypeMachine;

// Struct `machine` pointe vers la structure spécifique (Station ou Switch).
typedef struct Machine {
  TypeMachine type_machine; // Type de la machine
  void* machine; // Pointeur vers la structure spécifique
} Machine;

void afficher_table_commutation(Machine* machine);

void init_station(Machine* machine, Mac adresse_mac, IP adresse_ip);
void init_switch(Machine* machine, Mac adresse_mac, uint8_t nbPorts, uint16_t priorite);

void deinit_machine(Machine** machine);

void afficher_machine(Machine machine);
int comparer_mac_machine(Machine machine, Mac adresse_mac);
Mac get_mac(Machine machine);

#endif