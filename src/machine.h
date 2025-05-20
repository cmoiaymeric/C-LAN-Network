#include "type.h"

#ifndef MACHINE_H
#define MACHINE_H


typedef struct Station {
  Mac addrMac;
  IP addrIp;
} Station;

typedef struct Switch
{
  Mac addrMac;
  IP addrIp;
  size_t nbPort;
  size_t priorite;
  Mac tableCommutation[];
} Switch;

typedef union Machine {
  Station station;
  Switch bridge;
} Machine;

void initStation(Station* station, Mac addrMac, IP addrIp);
void deinitStation(Station* station);
void afficheStation(Station* station);

void initSwitch(Switch* bridge, Mac addrMac, IP addrIp);
void deinitSwitch(Switch* bridge);
void afficheSwitch(Switch* bridge);


#endif