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

  Reseau* reseau = malloc(sizeof(Reseau));
  init_reseau(reseau);
  
  read_config_file(file,reseau);
  printf("Le fichier a été traité avec succès\n");

  printf("\n\n---\n\n");
  afficher_reseau(reseau);

  exit(0);
}