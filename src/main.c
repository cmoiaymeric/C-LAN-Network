#include "reader.h"
#include "reseau.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    
  argc--; argv++;
    
  if ( argc == 0 ) {
    printf( "Usage: entrez un nom de fichier\n" );
    exit( 0 );
  }
  char* file = argv[0];
  char* fileString = "";
  readFile(file, fileString);

  printf("%s", fileString);
}