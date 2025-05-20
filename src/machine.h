#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "type.h"

#ifndef MACHINE_H
#define MACHINE_H


typedef struct Station {
  Mac addrMac;
  IP addrIp;
} Station;

typedef struct Sridge
{
  Mac addrMac;
  IP addrIp;
  size_t nbPort;
  size_t priorite;
  Mac tableCommutation[];
} Switch;




#endif