#include "type.h"
#include <stddef.h>

#ifndef MACHINE_H
#define MACHINE_H


typedef struct Station {
  Mac adresse_mac;
  IP adresse_ip;
  Mac voisin;
} Station;

typedef struct Commutation {
  uint8_t port;
  Mac destination;
} Commutation;
 
typedef struct Switch
{
  Mac adresse_mac;
  uint8_t nb_ports;
  uint16_t priorite;
  Commutation* commutations;
} Switch;

typedef enum TypeMachine {
  TypeStation = 1,
  TypeSwitch = 2,
} TypeMachine;

typedef struct Machine {
  TypeMachine type_machine;
  void* machine;
} Machine;

void init_station(Machine* machine, Mac adresse_mac, IP adresse_ip);
void init_switch(Machine* machine, Mac adresse_mac, uint8_t nbPorts, uint16_t priorite);

void deinit_machine(Machine* machine);
void afficher_machine(Machine* machine);


void ajouteVoisin(Machine* machine, Mac mac);

#endif