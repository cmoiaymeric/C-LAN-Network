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
  IP addrIp;
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
void deinitStation(Machine* machine);
void afficheStation(Machine* machine);

void initSwitch(Machine* machine, Mac addrMac, IP addrIp);
void deinitSwitch(Machine* machine);
void afficheSwitch(Machine* machine);

void ajouteVoisin(Machine* machine, Mac mac);


#endif