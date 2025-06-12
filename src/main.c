#include "reader.h"
#include "machine.h"
#include "reseau.h"
#include "trame.h"

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

  Mac mac1 = get_mac(reseau->machines[7]);
  Mac mac2 = get_mac(reseau->machines[8]);

  Trame t1;
  init_trame(&t1, &mac1, &mac2, 1, "blabla");

  char* mac_string_source = malloc(18);
  char* mac_string_destination = malloc(18);
  mac_to_string(mac1, mac_string_source);
  mac_to_string(mac2, mac_string_destination);
  printf("MAC 1 : %s\n", mac_string_source);
  printf("MAC 2 : %s\n", mac_string_destination);
  free(mac_string_source);
  free(mac_string_destination);
  mac_string_source = NULL;
  mac_string_destination = NULL;

  envoyer_trame(reseau, t1);

  afficher_table_commutation(&reseau->machines[2]);
  printf("\n");

  Trame t2;
  init_trame(&t2, &mac2, &mac1, 1, "blublubluuuu");
  envoyer_trame(reseau, t2);

  afficher_table_commutation(&reseau->machines[2]);

  deinit_trame(&t1);
  deinit_trame(&t2);

  deinit_reseau(reseau);
  free(reseau);
  reseau = NULL;
  exit(0);
}