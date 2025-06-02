#include "type.h"

#ifndef MACHINE_H
#define MACHINE_H


typedef struct Station {
  Mac addrMac;
  IP addrIp;
  Mac voisin;
} Station;

typedef struct Switch
{
  Mac addrMac;
  size_t nbPort;
  size_t priorite;
  Mac tableCommutation[];
} Switch;

typedef enum TypeMachine {
  TypeStation,
  TypeSwitch,
} TypeMachine;

typedef union Machine {
  TypeMachine typemachine;
  void* machine;
} Machine;

void initStation(Machine* machine, Mac addrMac, IP addrIp);
void initSwitch(Machine* machine, Mac addrMac, uint8_t priorite);

void deinitMachine(Machine* machine);
void afficheMachine(Machine* machine);

void ajouteVoisin(Machine* machine, Mac mac);


#endif