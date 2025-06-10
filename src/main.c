#include "reader.h"
#include "machine.h"
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

  Reseau* reseau = malloc(sizeof(Reseau));
  init_reseau(reseau);
  
  read_config_file(file,reseau);

  printf("\n\n---\n\n");
  afficher_reseau(reseau);
  deinit_reseau(reseau);
  free(reseau);
  reseau = NULL;
  exit(0);
}