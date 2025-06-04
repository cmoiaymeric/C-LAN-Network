#include "type.h"
#include <stddef.h>

#ifndef MACHINE_H
#define MACHINE_H


typedef struct Station {
  Mac addrMac;
  IP addrIp;
  Mac voisin;
} Station;

typedef struct commutation {
  uint8_t port;
  Mac destination;
} commutation;
 
typedef struct Switch
{
  Mac addrMac;
  uint8_t nbPort;
  uint16_t priorite;
  commutation* commutations;
} Switch;

typedef enum TypeMachine {
  TypeStation = 1,
  TypeSwitch = 2,
} TypeMachine;

typedef struct Machine {
  TypeMachine typemachine;
  void* machine;
} Machine;

void initStation(Machine* machine, Mac addrMac, IP addrIp);
void initSwitch(Machine* machine, Mac addrMac, uint8_t nbPorts, uint16_t priorite);

void deinitMachine(Machine* machine);
void afficheMachine(Machine* machine);


void ajouteVoisin(Machine* machine, Mac mac);

#endif