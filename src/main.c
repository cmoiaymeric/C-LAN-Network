#include "headers/connexion.h"
#include "headers/reader.h"
#include "headers/machine.h"
#include "headers/reseau.h"
#include "headers/stp_god_mode.h"
#include "headers/trame.h"

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

  Reseau* arbre = malloc(sizeof(Reseau));
  init_reseau(arbre);
  prim_arbre_recouvrement(reseau, get_switch_racine(reseau), arbre);

  printf("Reseau de base :\n");
  afficher_reseau(reseau);
  printf("\nReseau après l'algo de Prim :\n");
  afficher_reseau(arbre);
  printf("\n\n");
  

  machine_t machine1 = 7;
  machine_t machine2 = 14;

  Mac mac1 = get_mac(arbre->machines[machine1]);
  Mac mac2 = get_mac(arbre->machines[machine2]);

  printf("ENVOI DE LA TRAME 1 entre %u et %u\n",machine1,machine2);

  Trame t1;
  init_trame(&t1, &mac1, &mac2, IPv4, "Message sent to Station 14 from Station 7");
  afficher_trame_hexa(&t1);
  printf("\n");
  afficher_trame_user(&t1);
  envoyer_trame(arbre, t1);

  printf("Table de commutation de la machine 3 :\n");
  afficher_table_commutation(&arbre->machines[4]);
  printf("\n");


  printf("ENVOI DE LA TRAME 2 entre %u et %u\n",machine2,machine1);

  Trame t2;
  init_trame(&t2, &mac2, &mac1, IPv4, "Par la barbe de Z, ces donnees sont affiches en hexadecimal !");
  afficher_trame_hexa(&t2);
  printf("\n");
  afficher_trame_user(&t2);
  envoyer_trame(arbre, t2);

  printf("Table de commutation de la machine 3 :\n");
  afficher_table_commutation(&arbre->machines[4]);

  envoyer_ping(arbre, mac1, mac2);

  deinit_trame(&t1);
  deinit_trame(&t2);
  
  deinit_reseau(arbre);
  free(arbre);
  arbre = NULL;
  
  deinit_reseau_complet(reseau);
  free(reseau);
  reseau = NULL;
  
  exit(0);
}