#include "connexion.h"
#include "reader.h"
#include "machine.h"
#include "reseau.h"
#include "stp_god_mode.h"
#include "trame.h"

#include <stdint.h>
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

  afficher_reseau(reseau);

  Mac mac1 = get_mac(reseau->machines[7]);
  Mac mac2 = get_mac(reseau->machines[8]);

  Trame t1;
  init_trame(&t1, &mac1, &mac2, IPv4, "blabla");

  envoyer_trame(reseau, t1);

  afficher_table_commutation(&reseau->machines[3]);
  printf("\n");

  Trame t2;
  init_trame(&t2, &mac2, &mac1, IPv4, "blublubluuuu");
  envoyer_trame(reseau, t2);

  afficher_table_commutation(&reseau->machines[3]);

  envoyer_ping(reseau, mac1, mac2);

  deinit_trame(&t1);
  deinit_trame(&t2);


  printf("Switch racine : %u\n",get_switch_racine(reseau));
  def_priorite_switch(reseau, 2, 1025);
  printf("Switch racine : %u\n",get_switch_racine(reseau));

  deinit_reseau(reseau);
  free(reseau);
  reseau = NULL;
  exit(0);
}