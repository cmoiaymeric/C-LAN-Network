#include "reader.h"
#include "machine.h"
#include "type.h"
#include "reseau.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    
  argc--; argv++;
    
  if ( argc == 0 ) {
    printf( "Usage: entrez un nom de fichier\n" );
    exit(-1);
  }
  char* file = argv[0];
  char* fileString = NULL;
  read_config_file(file, fileString);
  printf("Le fichier a été traité avec succès\n");
  exit(0);
}